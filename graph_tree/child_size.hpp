#pragma once
#include<vector>
#include<cmath>
#include"graph_template.hpp"

/**
 * @brief 部分木の大きさ
 */

std::vector<int> child_size(int start,const graph& g){
	std::vector<int>memo(g.size());
	auto f=[&](auto f,int v,int p)->int{
		T res=0;
		for(auto t:g[v]){
			if(t==p)continue;
			res+=f(f,t,v);
		}
		return memo[v]=res+1;
	};
	f(f,start,-1);
	return memo;
}