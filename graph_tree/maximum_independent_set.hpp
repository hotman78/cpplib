#pragma once
#include<tuple>
#include<vector>
#include<bitset>
#include"graph_template.hpp"

/**
 * @brief 最大独立集合(V<=50)
 */

std::pair<int,std::bitset<50>> __maximum_independent_set(std::vector<std::bitset<50>>v,std::bitset<50>b=std::bitset<50>()){
	int n=v.size();
	auto del=[&](int k){
		for(int i=0;i<n;++i){
			v[k][i]=0;
			v[i][k]=0;
		}
		b[k]=1;
	};
	int t=-1;
	for(int i=0;i<n;++i)if(b[i]==0)t=i;
	if(t==-1)return std::make_pair(0,std::bitset<50>());
	if(v[t].count()<=1){
		for(int i=0;i<n;++i)if(v[t][i])del(i);
		del(t);
		auto p=__maximum_independent_set(v,b);
		p.first++;
		p.second[t]=1;
		return p;
	}else{
		std::vector<int>tmp;
		for(int i=0;i<n;++i)if(v[t][i])tmp.push_back(i);
		del(t);
		auto p=__maximum_independent_set(v,b);
		for(auto e:tmp)del(e);
		auto q=__maximum_independent_set(v,b);
		q.first++;
		q.second[t]=1;
		return p.first>q.first?p:q;
	}
}

std::vector<int> maximum_independent_set(const graph& g){
	std::vector<std::bitset<50>>v(g.size());
	for(size_t i=0;i<g.size();++i){
		for(auto e:g[i]){
			v[i][e]=1;
		}
	}
	auto res=__maximum_independent_set(v);
	std::vector<int>ret;
	for(size_t i=0;i<res.second.size();++i){
		if(res.second[i])ret.push_back(i);
	}
	return ret;
}