#pragma once
#include<vector>
#include<cmath>
#include<tuple>
#include"depth.hpp"
#include"graph_template.hpp"
#include"../data_structure/RMQ.hpp"

/**
 * @brief LCA &amp;lt;O(N),O(1)&amp;gt;(WIP)
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
        dep=depth(v,s);
        __dist=distance(v,s);
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
    int query(int p,int q){
        return st->query(std::min(start[p],start[q]),std::max(start[p],start[q])+1).second;
    }
    int dist(int p,int q){
        return __dist[p]+__dist[q]-2*__dist[lca(p,q)];
    }
};