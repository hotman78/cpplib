#pragma once
#include<vector>
#include<cmath>
#include"graph_template.hpp"

/**
 * @brief 根からの深さ
 */

std::vector<int> depth(int start,const graph& g){
	std::vector<int>memo(g.size());
	auto f=[&](auto f,int v,int p)->int{
		T mx=0;
		for(auto t:g[v]){
			if(t==p)continue;
			mx=std::max(mx,f(f,t,v));
		}
		return memo[v]=mx+1;
	};
	f(f,start,-1);
	return memo;
}