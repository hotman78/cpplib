#pragma once
#include<vector>
#include<algorithm>

/**
 * @brief トポロジカルソート
 */

std::vector<int>tsort(std::vector<std::vector<int>>G){
	std::vector<int> in(G.size(),0);
	std::vector<int> vis(G.size(),0);
	std::vector<int> res;
	for(int i=0;i<(int)G.size();i++)for(int j=0;j<(int)G[i].size();j++){
		in[G[i][j]]++;
	}
	for(int i=0;i<(int)G.size();++i){
		auto dfs=[&](auto dfs,int v)->void{
			vis[v]=1;
			res.push_back(v);
			for(auto e:G[v]){
				in[e]--;
				if(in[e]==0)dfs(dfs,e);
			}
		};
		if(vis[i]==0&&in[i]==0)dfs(dfs,i);
	}
	return res;
}