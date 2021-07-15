#pragma once
#include<vector>
#include<queue>
#include<functional>
#include<tuple>
#include<limits>
#include<algorithm>
#include"graph_template.hpp"
#include"../util/template.hpp"
/**
 * @brief ダイクストラ法 O((E+V)logE)
 */

template<typename T,typename F=std::less<T>,typename Add=std::plus<T>>
struct dijkstra{
    int s;
    std::vector<T> diff;
    std::vector<int> par;
    std::vector<int>used;
    dijkstra(const graph_w<T>& list,int s,T zero=T(),T inf=std::numeric_limits<T>::max(),F f=F(),Add add=Add()):s(s){
        int n=list.size();
        diff.resize(n,inf);
        par.resize(n,-1);
        used.resize(n,0);
        std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<std::pair<T,int>>>que;
        diff[s]=zero;
        que.push(std::make_pair(T(),s));
        while(!que.empty()){
            auto d=que.top();
            que.pop();
            T x;
            int now;
            std::tie(x,now)=d;
            if(used[now])continue;
            used[now]=1;
            for(auto d2:list[now]){
                T sa;
                int to;
                std::tie(to,sa)=d2;
                T tmp=add(diff[now],sa);
                if(f(tmp,diff[to])){
                    diff[to]=tmp;
                    par[to]=now;
                    que.emplace(diff[to],to);
                }
            }
        }
    }
    vector<T> get(){
        return diff;
    }
    T operator[](int idx){
        return diff[idx];
    }
    bool reachable(int t){
        return par[t]!=-1;
    }
    std::vector<int> get_path(int t){
        std::vector<int>res;
        while(t!=s){
            res.push_back(t);
            t=par[t];
        }
        res.push_back(s);
        std::reverse(res.begin(),res.end());
        return res;
    }
};