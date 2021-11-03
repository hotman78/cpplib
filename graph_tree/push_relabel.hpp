#pragma once
#include<vector>
#include<cmath>
#include<queue>
#include<tuple>

/**
 * @brief 最大流(push_relabel法O(V^2√E))
 */
template<typename T>
class push_relabel{
    int n;
    T f=0;
    using i64=long long;
    struct edge{
        int from,to,rev;
        T flow,cap;
    };
    std::vector<i64>h,d;
    std::vector<std::vector<edge*>>g;
    std::vector<size_t>seen;
    std::priority_queue<std::pair<i64,int>,std::vector<std::pair<i64,int>>,std::greater<std::pair<i64,int>>>que;
    public:
    push_relabel(int n):n(n){
        h.resize(n,0);
        d.resize(n,0);
        g.resize(n);
        seen.resize(n,0);
    }
    void add_edge(int u,int v,T cap){
        g[u].emplace_back(new edge{u,v,(int)g[v].size(),0,cap});
        g[v].emplace_back(new edge{v,u,(int)g[u].size()-1,0,0});
    }
    void push(edge* e){
        int u=e->from,v=e->to;
        i64 df=std::min(d[u],e->cap-e->flow);
        e->flow+=df;
        g[v][e->rev]->flow-=df;
        d[u]-=df;
        d[v]+=df;
        if(d[v]>0)que.emplace(h[v],v);
        if(d[u]>0)que.emplace(h[u],u);
    }
    void relabel(int u){
        i64 mn=n*2;
        for(edge* e:g[u]){
            if(e->cap-e->flow>0){
                mn=std::min(mn,h[e->to]);
            }
        }
        h[u]=1+mn;
        que.emplace(h[u],u);
    }
    void discharge(int u){
        while(d[u]>0){
            if(seen[u]<g[u].size()){
                edge* e=g[u][seen[u]];
                if(e->cap-e->flow>0 && h[u]==h[e->to]+1){
                    push(e);
                }else{
                    seen[u]+=1;
                }
            }else{
                relabel(u);
                seen[u]=0;
            }
        }
    }
    T run(int s,int t){
        h[s]=n;
        for(auto e:g[s]){
            d[s]+=e->cap;
            push(e);
        }
        while(!que.empty()){
            int u=que.top().second;
            que.pop();
            if(u==s||u==t)continue;
            discharge(u);
        }
        for(auto e:g[s])f+=e->flow;
        return f;
    }
};