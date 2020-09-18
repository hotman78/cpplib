#pragma once
#include<vector>

/**
 * @brief ダイクストラ O((E+V)logE)
 */
template<typename E,typename T>
std::vector<T> __dijkstra(vector<vector<pair<E,T>>> list,lint s,T inf){
    std::priority_queue<pair<T,E>,vector<pair<T,E>>,greater<pair<T,E>>>que;
    vector<T>diff(list.size(),inf);
    diff[s]=0;
    que.push(make_pair(T(),s));
    while(!que.empty()){
        auto d=que.top();
        que.pop();
        T x;E now;
        tie(x,now)=d;
        for(auto d2:list[now]){
            T sa;E to;
            tie(to,sa)=d2;
            if(chmin(diff[to],diff[now]+sa))que.emplace(diff[to],to);
        }
    }
    return diff;
}

