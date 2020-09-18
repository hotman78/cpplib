#pragma once
#include<vector>
#include<algorithm>

/**
 * @brief トポロジカルソート
 */

std::vector<int>tsort(std::vector<std::vector<int>>G){
	std::vector<int> visited(G.size(),0);
	std::vector<int> start(G.size(),1);
	for(int i=0;i<(int)G.size();i++)for(int j=0;j<(int)G[i].size();j++){
		start[G[i][j]]=0;
	}
	std::vector<int>res(G.size());
    int idx=0;
	auto f=[&](auto f,int v)->void{
		if(visited[v])return;
		for(auto t:G[v])f(f,t);
		res[idx++]=v;
		visited[v]=1;
	};
	for(int i=0;i<(int)G.size();i++)if(start[i])f(f,i);
	std::reverse(res.begin(),res.end());
	return res;
}