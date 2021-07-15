#pragma once
#include<vector>
#include<cmath>
#include<tuple>
#include"depth.hpp"
#include"distance.hpp"
#include"graph_template.hpp"
#include"../data_structure/arg_rmq.hpp"

/**
 * @brief LCA &amp;lt;O(N),O(1)&amp;gt;(HL分解と同等の速さ)
 */

class lca{
    std::vector<int>data;
    std::vector<int>comp_data;
    std::vector<int>start;
    arg_rmq<int>*st;
    std::vector<int> __dist;
    public:
    lca(){}
    lca(std::vector<std::vector<int>>v,int s){
        data.resize(v.size()*2-1);
        comp_data.resize(v.size()*2-1);
        start.resize(v.size());
        int i=0;
        __dist=distance(v,s);
        auto f=[&](auto f,int n,int p)->void{
            start[n]=i;
            data[i]=n;
            comp_data[i++]=__dist[n];
            for(int t:v[n]){
                if(t==p)continue;
                f(f,t,n);
                data[i]=n;
                comp_data[i++]=__dist[n];
            }
        };
        f(f,s,-1);
        st=new arg_rmq<int>(comp_data);
    }
    int query(int p,int q){
        return data[st->query(std::min(start[p],start[q]),std::max(start[p],start[q])+1).unwrap().first];
    }
    int dist(int p,int q){
        return __dist[p]+__dist[q]-2*__dist[query(p,q)];
    }
};