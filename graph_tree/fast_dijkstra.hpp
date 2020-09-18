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

template<typename T,typename Add=std::plus<T>,typename F=std::less<T>>
std::vector<T> dijkstra(const graph_w<T>&v,int s,const T& zero,const T& inf,F f=F(),Add add=Add()){
    int n=v.size();
    std::vector<T> ans(std::vector<T>(n,inf));
    ans[s]=zero;
    auto cmp=[&f](auto s,auto t){return f(t.first,s.first);};
    using pq_t=__gnu_pbds::priority_queue<std::pair<T,int>,decltype(cmp),__gnu_pbds::pairing_heap_tag>;
    pq_t que(cmp);
    typename pq_t::point_iterator node[n];
    for(int i=0;i<n;i++)node[i]=que.push(make_pair(inf,i));
    que.modify(node[s],make_pair(zero,s));
    while(!que.empty()){
        T p;
        int now;
        tie(p,now)=que.top();
        que.pop();
        for(auto d:v[now]){
            auto next=add(p,d.second);
            if(f(next,ans[d.first])){
				ans[d.first]=next;
				que.modify(node[d.first],make_pair(next,d.first));
			}
        }
    }
	return ans;
}