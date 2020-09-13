#pragma once
#include<map>

template<typename Int>
std::map<int,int> osa_k(Int n){
    constexpr int mx=10'000'000;
    assert(n<mx);
    static init=false;
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