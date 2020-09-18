#pragma once
#include<vector>
#include<queue>
#include<functional>
#include<tuple>
#include<limits>
#include"graph_template.hpp"

/**
 * @brief ダイクストラ O((E+V)logE)
 */

template<typename T,typename F=std::less<T>>
std::vector<T> dijkstra(const graph_w<T>& list,int s,T zero=0,T inf=std::numeric_limits<T>::max(),F f=F()){
    std::priority_queue<std::pair<T,int>,std::vector<pair<T,int>>,std::greater<std::pair<T,int>>>que;
    std::vector<T>diff(list.size(),inf);
    diff[s]=zero;
    que.push(make_pair(T(),s));
    while(!que.empty()){
        auto d=que.top();
        que.pop();
        T x;
        int now;
        tie(x,now)=d;
        for(auto d2:list[now]){
            T sa;
            int to;
            tie(to,sa)=d2;
            if(f(diff[now]+sa,diff[to])){
                diff[to]=diff[now]+sa;
                que.emplace(diff[to],to);
            }
        }
    }
    return diff;
}

