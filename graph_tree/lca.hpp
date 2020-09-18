#pragma once
#include<vector>
#include<cmath>
#include<tuple>
#include"graph_template.hpp"
#include"../data_structure/RMQ.hpp"

/**
 * @brief LCA &amp;lt;O(N),O(1)&amp;gt;
 */

class LCA{
    std::vector<std::pair<int,int>>data;
    std::vector<int>start;
    RMQ<std::pair<int,int>>*st;
    std::vector<int>dep;
    std::vector<int> __dist;
    public:
    LCA(){}
    LCA(std::vector<std::vector<int>>v,int s){
        data.resize(v.size()*2-1);
        start.resize(v.size());
        int i=0;
        dep=depth(s,v);
        __dist=__distance(s,v);
        auto f=[&](auto f,int n,int p)->void{
            start[n]=i;
            data[i++]=std::make_pair(dep[n],n);
            for(int t:v[n]){
                if(t==p)continue;
                f(f,t,n);
                data[i++]=std::make_pair(dep[n],n);
            }
        };
        f(f,s,-1);
        st=new RMQ<std::pair<int,int>>(data);
    }
    int lca(int p,int q){
        return st->query(std::min(start[p],start[q]),std::max(start[p],start[q])+1).second;
    }
    int distance(int p,int q){
        return __dist[p]+__dist[q]-2*__dist[lca(p,q)];
    }
    std::vector<int> __distance(int start,std::vector<std::vector<int>>G){
		std::vector<int>memo(G.size());
		auto f=[&](auto f,int v,int p,int i)->void{
			for(auto t:G[v]){
				if(t==p)continue;
				f(f,t,v,i+1);
			}
			return memo[v]=i;
		};
		f(f,start,-1,0);
		return memo;
    }
    std::vector<int> depth(int start,std::vector<std::vector<int>>G){
        std::vector<int>memo(G.size());
        auto f=[&](auto f,int v,int p)->int{
            int mx=0;
            for(int t:G[v]){
                if(t==p)continue;
                mx=std::max(mx,f(f,t,v));
            }
            return memo[v]=mx+1;
        };
        f(f,start,-1);
        return memo;
    }
};