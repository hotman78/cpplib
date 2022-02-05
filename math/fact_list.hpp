#pragma once
#include"prime_factor.hpp"

vector<lint>factor_list(const std::map<int,int>& p){
    vector<pair<lint,lint>>v;
    for(auto [s,t]:p)v.emplace_back(s,t);
    vector<lint>res;
    auto dfs=[&](auto dfs,lint idx,lint now)->void{
        if(idx==(int)v.size()){
            res.push_back(now);
            return;   
        }
        for(int i=0;i<=v[idx].second;++i){
            dfs(dfs,idx+1,now);
            now*=v[idx].first;
        }
    };
    dfs(dfs,0,1);
    sort(res.begin(),res.end());
    return res;
}

vector<lint>factor_list(std::map<long long,long long> p){
    vector<pair<lint,lint>>v;
    for(auto [s,t]:p)v.emplace_back(s,t);
    vector<lint>res;
    auto dfs=[&](auto dfs,lint idx,lint now)->void{
        if(idx==(int)v.size()){
            res.push_back(now);
            return;   
        }
        for(int i=0;i<=v[idx].second;++i){
            dfs(dfs,idx+1,now);
            now*=v[idx].first;
        }
    };
    dfs(dfs,0,1);
    sort(res.begin(),res.end());
    return res;
}

vector<lint>factor_list(lint x){
    auto p=prime_factor(x);
    vector<pair<lint,lint>>v;
    for(auto [s,t]:p)v.emplace_back(s,t);
    vector<lint>res;
    auto dfs=[&](auto dfs,lint idx,lint now)->void{
        if(idx==(int)v.size()){
            res.push_back(now);
            return;   
        }
        for(int i=0;i<=v[idx].second;++i){
            dfs(dfs,idx+1,now);
            now*=v[idx].first;
        }
    };
    dfs(dfs,0,1);
    sort(res.begin(),res.end());
    return res;
}