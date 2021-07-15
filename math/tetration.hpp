#pragma once
#include<vector>
#include<algorithm>
#include<cmath>
#include"mod_pow.hpp"
#include"euler_phi.hpp"

/**
 * @brief テトレーション
 */

long long tetration(long long a,long long b,long long m){
    std::vector<long long> v;
    long long d=m;
    while(d!=1){
        v.push_back(d);
        d=euler_phi(d);
    }
    v.push_back(1);
    if(a==0)return (b+1)%2%m;
    if(m==1)return 0;
    if(a==1||b==0){
        return 1;
    }
    if((long long)(v.size())>=b)v.resize(b-1,1);
    std::reverse(v.begin(),v.end());
    long long ans=a;
    for(auto e:v){
        long long ad=(ans<=32&&a<e&&std::pow((double)a,ans)<e?0:e);
        ans=mod_pow(a%e,ans,e)+ad;
    }
    return ans%m;
}