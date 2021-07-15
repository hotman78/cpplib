#pragma once
#include<vector>
#include<queue>
#include<cmath>
#include<limits>
#include<cassert>
#include<iostream>
#include<map>
#include<list>

/**
 * @brief 最大流(Dinic法)
 */

template<typename T>
struct dinic {
    struct edge {
        int to;
        typename std::list<edge>::iterator rev;
        T cap,flow;
        edge(int to,T cap):to(to),cap(cap),flow(T()){}
    };
    int n,src,dst;
    T ret=T();
    std::vector<std::list<edge>> g;
    std::vector<typename std::list<edge>::iterator>itr;
    std::vector<int>level,seen;
    std::map<std::pair<int,int>,bool>exist;
    std::map<std::pair<int,int>,typename std::list<edge>::iterator>m;
    dinic(){}
    dinic(int n,int s,int t):n(n),src(s),dst(t){g.assign(n,std::list<edge>());itr.resize(n);}

    void add_edge(int from, int to, T cap) {
        g[from].push_back(edge(to,cap));
        g[to].push_back(edge(from,0));
        m[std::make_pair(from,to)]=prev(g[from].end());
        m[std::make_pair(to,from)]=prev(g[to].end());
        g[from].back().rev=prev(g[to].end());
        g[to].back().rev=prev(g[from].end());
        exist[std::make_pair(from,to)]=1;
        exist[std::make_pair(to,from)]=1;
    }
    bool update_edge(int from, int to, T cap){
        if(cap>0){
            if(exist[std::make_pair(from,to)]){
                auto e=m[std::make_pair(from,to)];
                e->cap+=cap;
            }else{
                add_edge(from,to,cap);
            }
            return 1;
        }else{
            cap*=-1;
            if(exist[std::make_pair(from,to)]){
                auto e=m[std::make_pair(from,to)];
                if(e->cap-e->flow>=cap){
                    e->cap-=cap;
                }else{
                    e->cap-=cap;
                    T req=e->flow-e->cap;
                    e->flow-=req;
                    e->rev->flow+=req;
                    ret-=req;
                    assert(cancel(dst,to,req));
                    assert(cancel(from,src,req));
                    if(e->cap==0&&e->rev->cap==0){
                        g[from].erase(e);
                        g[to].erase(e->rev);
                        exist[std::make_pair(from,to)]=0;
                        exist[std::make_pair(to,from)]=0;
                    }
                }
                return 1;
            }else{
                return 0;
            }
        }
    }

    void bfs(int s) {
        level.assign(n,-1);
        std::queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(edge e: g[v]){
                if (e.cap-e.flow > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs(int v, int t,T f) {
        if (v == t) return f;
        for(auto &e=itr[v];e!=g[v].end();++e){
            if (e->cap-e->flow > 0 and level[v] < level[e->to]) {
                T d = dfs(e->to, t, std::min(f, e->cap-e->flow));
                if (d > 0) {
                    e->flow+=d;
                    e->rev->flow -= d;
                    return d;
                }
            }
        }
        return 0;
    }

    T __cancel(int v,int t,T f){
        if (v == t) return f;
        seen[v]=1;
        for (edge& e: g[v]){
            if (e.rev->flow > 0&&!seen[e.to]) {
                T d = __cancel(e.to, t, std::min(f,e.rev->flow));
                if (d > 0) {
                    e.flow+=d;
                    e.rev->flow-=d;
                    return d;
                }
            }
        }
        return 0;
    }
    T run() {
        T f;
        while (bfs(src), level[dst] >= 0) {
            for(int i=0;i<n;++i)itr[i]=g[i].begin();
            while ((f = dfs(src, dst, std::numeric_limits<T>::max())) > 0) {
                ret += f;
            }
        }
        return ret;
    }
    T cancel(int s,int t,T mx){
        T f;
        while(seen.assign(n,0),seen[s]=1,(f=__cancel(s, t, mx))>0)mx-=f;
        return mx==0;
    }
    T cap(int s,int t){
        if(exist[std::make_pair(s,t)]){
            return m[std::make_pair(s,t)]->cap;
        }else{
            return 0;
        }
    }
    T flow(int s,int t){
        if(exist[std::make_pair(s,t)]){
            return m[std::make_pair(s,t)]->flow;
        }else{
            return 0;
        }
    }
    void debug(){
        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            if(i==j)continue;
            if(flow(i,j)>0)std::cerr<<"("<<i<<","<<j<<")";
        }
        std::cerr<<'\n';
    }
};