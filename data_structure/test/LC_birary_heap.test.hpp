#include "../binary_heap.hpp"
#include "../../util/template.hpp"

int main(){
	lint n,m,s,t;
	cin>>n>>m>>s>>t;
	vector<vector<pair<lint,lint>>>g(n);
	rep(i,m){
		lint a,b,c;
		cin>>a>>b>>c;
		g[a].emplace_back(b,c);
	}
	binary_heap<pair<lint,lint>>que;
	vector<binary_heap<pair<lint,lint>>::np>v(n);
	rep(i,n)v[i]=que.insert(make_pair(INF,i));
	que.modify(v[s],make_pair(0,s));
	vector<lint>from(n,-1);
	vector<lint>dif(n,INF);
	dif[s]=0;
	while(!que.empty()){
		auto [cost,now]=que.top();
		que.pop();
		for(auto [e,c]:g[now]){
			if(chmin(dif[e],dif[now]+c)){
				from[e]=now;
				que.modify(v[e],make_pair(dif[e],e));
			}
		}
	}
	if(dif[t]==INF){
		cout<<-1<<endl;
		return 0;
	}
	lint now=t;
	vector<pair<lint,lint>>ans;
	while(1){
		if(now==s)break;
		ans.emplace_back(from[now],now);
		now=from[now];
	}
	cout<<dif[t]<<" "<<ans.size()<<endl;
	reverse(all(ans));
	for(auto e:ans){
		cout<<e.first<<" "<<e.second<<endl;
	}
}