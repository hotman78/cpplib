#pragma once
#include<vector>
#include<algorithm>
#include"scc.hpp"
#include"graph_template.hpp"

/**
 * @brief 2-SAT
 */
struct two_sat{
    int n;
    graph v;
    std::vector<int>list;
    graph g;
    two_sat(int n):n(n){
        v.resize(n*2);
        list.resize(n*2,-1);
    }
    //add s==p&&t==q
    void add_edge(int s,int t,bool p,bool q){
        v[s+p*n].push_back(t+(1-q)*n);
        v[t+q*n].push_back(s+(1-p)*n);
    }
    bool solve(){
        static int scced=0;
        static bool ans=1;
        if(!scced){
            scced=1;
            tie(list,v)=scc(v);
            for(int i=0;i<n;i++){
                if(list[i]==list[i+n])ans=0;
            }
        }
        return ans;
    }
    bool operator[](int i){
        return list[i]>list[i+n];
    }
};