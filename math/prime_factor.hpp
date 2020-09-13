#pragma once
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
#include"is_prime.hpp"

/**
 * @brief 素因数分解(高速)
 */

void __prime_factor(long long n,long long& c,std::vector<long long>& v){
    if(n==1)return;
    if(n%2==0){
        v.emplace_back(2);
        __prime_factor(n/2,c,v);
        return;
    }
    if(is_prime(n)){
        v.emplace_back(n);
        return;
    }
    while(1){
        long long x=2,y=2,d=1;
        while(d==1){
            x=((__int128_t)x*x+c)%n;
            y=((__int128_t)y*y%n+c)%n;
            y=((__int128_t)y*y%n+c)%n;
            d=std::gcd(std::abs(x-y),n);
        }
        if(d==n){
            c++;
            continue;
        }
        __prime_factor(d,c,v);
        __prime_factor(n/d,c,v);
        return;
    }
}

std::vector<long long>prime_factor(long long n){
    std::vector<long long>v;
    long long c=1;
    __prime_factor(n,c,v);
    std::sort(v.begin(),v.end());
    return v;
}