//comp(a,b) means a<b
template<typename Weight,typename Diff,typename Add,typename Comp,typename Int>
vector<Weight> dij(const vector<vector<pair<Int,Diff>>>&v,const Int& s,const Weight& zero,const Weight& inf,const Comp& comp,const Add& add){
    Int n=v.size();
    vector<Weight> ans(vector<Weight>(n,inf));
    ans[s]=zero;
    using pq_t=__gnu_pbds::priority_queue<pair<Weight,Int>,function<bool(pair<Weight,Int>,pair<Weight,Int>)>,__gnu_pbds::pairing_heap_tag>;
    pq_t que([&comp](auto s,auto t){return comp(t.first,s.first);});
    typename pq_t::point_iterator node[n];
    for(Int i=0;i<n;i++)node[i]=que.push(make_pair(inf,i));
    que.modify(node[s],make_pair(zero,s));
    while(!que.empty()){
        Weight p;
        Int now;
        tie(p,now)=que.top();
        que.pop();
        for(auto d:v[now]){
            auto next=add(p,d.second);
            if(comp(next,ans[d.first])){
				ans[d.first]=next;
				que.modify(node[d.first],make_pair(next,d.first));
			}
        }
    }
	return ans;
}

template<typename E=lint,typename T=double>
vector<T> dij(vector<vector<pair<E,T>>> list,lint s,T inf){
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