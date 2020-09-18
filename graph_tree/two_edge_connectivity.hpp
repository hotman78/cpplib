#include<vector>
#include<stack>
#include<algorithm>
#include"graph_template.hpp"

/**
 * @brief 二辺連結成分分解
 */

struct two_edge_connectivity{
	std::vector<int>order,cmp;
	std::stack<int> s,roots;
	std::vector<bool> ins;
	std::vector<std::vector<int>>each_bcc;
	std::vector<std::pair<int,int>>brige;
	two_edge_connectivity(graph g){
		int n=g.size();
		order.resize(n,0);
		ins.resize(n,0);
		cmp.resize(n);
		for(int i=0;i<n;i++){
			if(!order[i])dfs(g,i,-1);
		}
	}
	void dfs(const graph& g,int v,int p){
		order[v]=(p==-1?0:order[p])+1;
		s.emplace(v);
		ins[v]=1;
		roots.emplace(v);
		bool f=1;
		for(auto e:g[v]){
			if(e==p&&f){f=0;continue;}
			if(!order[e])dfs(g,e,v);
			else if(e!=v&&ins[e])while(order[roots.top()]>order[e])roots.pop();
		}
		if(v==roots.top()){
			if(p!=-1)brige.push_back(std::minmax(p,v));
			std::vector<int>bcc;
			while(1){
				int e=s.top();s.pop();ins[e]=0;
				bcc.push_back(e);
				cmp[v]=each_bcc.size();
				if(e==v)break;
			}
			each_bcc.push_back(bcc);
			roots.pop();
		}
	}
	auto get_bcc(){return each_bcc;}
	auto get_v(){return cmp;}
	auto get_brige(){return brige;}
};