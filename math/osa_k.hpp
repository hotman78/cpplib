#pragma once
#include<map>

/**
 * @brief osa_k法
 */

std::map<int,int> osa_k(int n){
    constexpr int mx=20'000'001;
    assert(n<mx);
    static bool init=false;
    static int v[mx];
    static vector<int>pr;
    if(!init){
        init=true;
        for(int i=2;i<mx;++i){
            if(v[i]==0){
                v[i]=i;
                pr.push_back(i);
            }
            for(int j=0;j<(int)pr.size() && pr[j]<=v[i] && i*pr[j]<mx;++j){
                v[i*pr[j]]=pr[j];
            }
        }
    }
    map<int,int>ret;
    while(n!=1){
        ret[v[n]]++;
        n/=v[n];
    }
    return ret;
}