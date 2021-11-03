#pragma once
#include"./graph_template.hpp"

vector<int>parent_list(const graph& g,int s=0){
    vector<int>v(g.size());
    auto dfs=[&](auto dfs,int now,int p){
        v[now]=p;
        for(auto e:g[now]){
            if(e==p)continue;
            dfs(dfs,e,now);
        }
    };
    dfs(dfs,s,-1);
    return v;
}