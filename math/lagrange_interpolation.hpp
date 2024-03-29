#pragma once
#include<vector>
/**
 * @brief ラグランジュ補完(連続点->一点)
 */

template<typename T>
T lagrange_interpolation(std::vector<T>v,long long n){
    long long k=v.size();
    if(n<k)return v[n];
    std::vector<T> tmp1(k+1,1),tmp2(k+1,1);
    T ans=0;
    for(int i=0;i<k;++i)tmp1[i]=(i?tmp1[i-1]:T(1))*(n-i);
    for(int i=k-1;i>=0;--i)tmp2[i]=(i<k-1?tmp2[i+1]:T(1))*(n-i);
    for(int i=0;i<k;++i){
        ans+=v[i]*(i<k-1?tmp2[i+1]:1)*(i?tmp1[i-1]:T(1))/(T(k-1-i).fact()*T(i).fact()*T((k-1-i)%2?-1:1));
    }
    return ans;
}