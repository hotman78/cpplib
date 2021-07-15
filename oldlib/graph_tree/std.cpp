vector<lint> depth(lint start,vector<vector<lint>>G){
	auto Y=[&](auto f){return[&](auto... args){return f(f, args...);};};
	vector<lint>memo(G.size());
	auto f=Y([&](auto f,lint v,lint p)->lint{
		lint mx=0;
		for(auto t:G[v]){
			if(t==p)continue;
			mx=max(mx,f(f,t,v));
		}
		return memo[v]=mx+1;
	});
	f(start,-1);
	return memo;
}

vector<lint> child_size(lint start,vector<vector<lint>>G){
	auto Y=[&](auto f){return[&](auto... args){return f(f, args...);};};
	vector<lint>memo(G.size());
	auto f=Y([&](auto f,lint v,lint p)->lint{
		lint res=0;
		for(auto t:G[v]){
			if(t==p)continue;
			res+=f(f,t,v);
		}
		return memo[v]=res+1;
	});
	f(start,-1);
	return memo;
}

vector<lint>tsort(vector<vector<lint>>G){
	auto Y=[&](auto f){return[&](auto... args){return f(f, args...);};};
	vector<bool> visited(G.size(),0);
	vector<bool> start(G.size(),1);
	for(lint i=0;i<(lint)G.size();i++)for(lint j=0;j<(lint)G[i].size();j++){
		start[G[i][j]]=0;
	}
	vector<lint>res(G.size());
    int idx=0;
	auto f=Y([&](auto f,lint v)->void{
		if(visited[v])return;
		for(auto t:G[v])f(f,t);
		res[idx++]=v;
		visited[v]=1;
	});
	for(lint i=0;i<(lint)G.size();i++)if(start[i])f(i);
	reverse(res.begin(),res.end());
	return res;
}