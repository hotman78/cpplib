#pragma once
#include<vector>

// \sum_{i=0}^{\infty} r^i f(i) (deg f <= d)
template<typename T>
T sum_power_poly_limit(T r,int d,std::vector<T>fs){
    vector<T>rr(d+1);
    rr[0]=1;
    for(int i=1;i<d+1;++i)rr[i]=rr[i-1]*r;
    T ans=0,sumRF=0;
    for(int i=0;i<d+1;++i){
        sumRF+=rr[i]*fs[i];
        ans += T(d-i).fact_inv()*T(i+1).fact_inv()*(((d - i)&1)?-1:1)*rr[d - i]*sumRF;
    }
    ans *= T(1-r).pow(MOD-(d+1))*T(d+1).fact();
    return ans;
}