#pragma once
#include<vector>
#include<stack>
#include"../dsu/uf_min.hpp"

/**
 * @brief 支配木
 */

// rootからvに向かう際に絶対通らないといけない頂点を
// vの祖先とするように木を構築する
std::vector<int> dominator_tree(std::vector<std::vector<int>>g,int s){
	int n=g.size();
	std::vector<std::vector<int>> rev_g(n);
	for(int i=0;i<n;++i){
		for(auto e:g[i]){
			rev_g[e].push_back(i);
		}
	}
	std::stack<int>stk;
    std::vector<bool>used(n,0);
    std::vector<int>id(n+1,n);
    std::vector<int>id2(n+1,n);
    std::vector<int>sdom(n,n);
    std::vector<int>idom(n,n);
    std::vector<std::vector<int>>ch(n);
    sdom[s]=s;
    int idx=0;
    stk.emplace(s);
    while(!stk.empty()){
        auto v=stk.top();
        stk.pop();
        id2[v]=idx;
        id[idx++]=v;
        for(auto e:g[v]){
            if(!used[e]){
                ch[v].push_back(e);
                stk.emplace(e);
                used[e]=1;
            }
        }
    }
    for(int i=0;i<n;++i){
        int v=id[i];
        if(v==n)continue;
        if(v==s)continue;
        for(auto e:rev_g[v]){
            if(id2[e]<i){
                if(id2[sdom[v]]>id2[e]){
                    sdom[v]=e;
                }
            }
        }
    }
    uf_min uf(n);
    std::vector<std::vector<int>>sdom_list(n+1);
    std::vector<int>u(n,-1);
    for(int i=n-1;i>=0;--i){
        int v=id[i];
        if(v==n)continue;
        for(auto e:sdom_list[v]){
            u[e]=uf.eval(e);
        }
        if(v==s)continue;
        for(auto e:rev_g[v]){
            if(id2[e]<i)continue;
            auto d=uf.eval(e);
            if(id2[sdom[v]]>id2[sdom[d]])sdom[v]=sdom[d];
        }
        sdom_list[sdom[v]].push_back(v);
        uf.set(v,id2[sdom[v]]);
        for(auto e:ch[v]){
            uf.link(v,e);
        }
    }
    for(int i=0;i<n;++i){
        auto v=id[i];
        if(v==n)continue;
        if(v==s){
            idom[v]=v;
            continue;
        }
        if(sdom[v]==sdom[u[v]])idom[v]=sdom[v];
        else idom[v]=idom[u[v]];
    }
    for(int i=0;i<n;++i)if(idom[i]==n)idom[i]=-1;
	return idom;
}