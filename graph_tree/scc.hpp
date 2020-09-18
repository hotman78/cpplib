#pragma once
#include<vector>
#include<tuple>
#include<algorithm>
#include"graph_template.hpp"

/**
 * @brief 強連結成分分解
 */

std::pair<std::vector<int>,graph> scc(const graph& g){
    int n=g.size();
    std::vector<std::vector<int>>rev(n);
    for(int i=0;i<n;i++)for(auto e:g[i]){
        rev[e].emplace_back(i);
    }
    int idx=0;
    std::vector<int>v(n,-1);
    std::vector<bool>visited(n,0);
    auto dfs=[&](auto dfs,int now)->void{
        visited[now]=1;
        for(auto e:g[now]){
            if(!visited[e])dfs(dfs,e);
        }
        v[idx++]=now;
    };
    for(int i=0;i<n;i++){
        if(!visited[i])dfs(dfs,i);
    }
    idx=-1;
    std::vector<int>res(n,-1);
    auto rdfs=[&](auto rdfs,int now)->void{
        for(auto e:rev[now]){
            if(res[e]==-1)res[e]=idx,rdfs(rdfs,e);
        }
    };
    for(int i=n-1;i>=0;--i){
        if(res[v[i]]==-1){
            res[v[i]]=++idx;
            rdfs(rdfs,v[i]);
        }
    }
    idx++;
    std::vector<std::vector<int>>res2(idx);
    for(int i=0;i<n;i++)for(auto e:g[i]){
        if(res[i]==res[e])continue;
        res2[res[i]].push_back(res[e]);
    }
    for(int i=0;i<idx;i++){
        std::sort(res2[i].begin(),res2[i].end());
        res2[i].erase(std::unique(res2[i].begin(),res2[i].end()),res2[i].end());
    }
    return {res,res2};
}