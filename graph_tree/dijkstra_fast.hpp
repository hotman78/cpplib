#pragma once
#include<vector>
#include<tuple>
#include<functional>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include"graph_template.hpp"

/**
 * @brief ダイクストラ O(E+VlogE)
 */


template<typename T,typename F=std::less<T>,typename Add=std::plus<T>>
struct dijkstra{
    int s;
    std::vector<T> diff;
    std::vector<int> par;
    dijkstra(const graph_w<T>& list,int s,T zero=T(),T inf=std::numeric_limits<T>::max(),F f=F(),Add add=Add()):s(s){
        int n=list.size();
        diff.resize(n,inf);
        par.resize(n,-1);
        diff[s]=zero;
        auto cmp=[f](auto s,auto t){return f(t.first,s.first);};
        using pq_t=__gnu_pbds::priority_queue<std::pair<T,int>,decltype(cmp),__gnu_pbds::pairing_heap_tag>;
        pq_t que(cmp);
        typename pq_t::point_iterator node[n];
        for(int i=0;i<n;i++)node[i]=que.push(std::make_pair(inf,i));
        que.modify(node[s],std::make_pair(zero,s));
        while(!que.empty()){
            T p;
            int now;
            std::tie(p,now)=que.top();
            if(p==inf)break;
            que.pop();
            for(auto d:list[now]){
                auto next=add(p,d.second);
                if(f(next,diff[d.first])){
                    diff[d.first]=next;
                    par[d.first]=now;
                    que.modify(node[d.first],std::make_pair(next,d.first));
                }
            }
        }
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