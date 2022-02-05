#pragma once
#include<vector>
#include"graph_template.hpp"

std::vector<int> euler_tour(graph v,int s){
    std::vector<int> ret;
    auto f=[](auto f,int n,int p)->void{
        ret.push_back(n);
        for(auto e:v){
            if(e==p)continue;
            f(f,e,n);
        }
        ret.push_back(n);
    };
    f(f,s,-1);
    return ret;
}