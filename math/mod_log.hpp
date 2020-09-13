#pragma once
#include"mod_pow.hpp"
#include"euler_phi.hpp"
#include<map>
#include<numeric>
#include<cmath>

/**
 * @brief 離散対数(ModLog)
 */

long long mod_log(long long x,long long y,long long m){
    if(1==y||(x==0&&y==0&&m==1))return 0;
    if(x==0){
        if(y==1)return 0;
        if(y==0)return 1;
        else return -1;
    }
    long long _x=x,_y=y;
    long long g=m;
    long long cnt=0;
    while(std::gcd(x,m)!=1)m/=std::gcd(x,m),cnt++;
    g/=m;
    x%=m;
    y%=m;
    std::map<long long,long long>b;
    long long B=std::sqrt(m*g)+1;
    long long phi=euler_phi(m);
    long long a=mod_pow(x,B-1,m);
    long long inv_x=mod_pow(x,phi-1,m);
    for(long long i=B-1;i>=cnt;--i){
        b[a]=i;
        a=a*inv_x%m;
    }
    long long A=mod_pow(x,B*(phi-1),m);
    long long A2=y;
    for(long long i=0;i<B;++i){
        for(long long j=0;j<cnt;++j)if(mod_pow(_x,i*B+j,m*g)==_y)return i*B+j;
        if(b.count(A2)){
            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return i*B+b[A2];
        }
        A2=A2*A%m;
    }
    return -1;
}