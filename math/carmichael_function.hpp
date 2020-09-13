#pragma once
#include<map>

template<typename T>
auto carmichael_function(T n){
    map<T,long long>ret;
    for(auto i=2;i*i<=n;i++){
        while(n%i==0){
            ret[i]++;
            n/=i;
        }
    }
    if(n!=1)ret[n]=1;
    long long res=1;
    for(auto d:ret){
        if(d.first==2){
            if(d.second<3)res=pow(d.first,d.second-1);
            else res=pow(d.first,d.second-2);
        }
        else res=lcm(res,(long long)pow(d.first,d.second-1)*(d.first-1));
    }
    return res;
}