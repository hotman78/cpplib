#pragma once
#include<vector>
#include"mod_pow.hpp"

/**
 * 
 * @brief ガーナーのアルゴリズム
 *
 */

long long garner(const std::vector<long long>&a,const std::vector<long long>&mods){
    const int sz=a.size();
    long long coeffs[sz+1]={1,1,1,1};
    long long constants[sz+1]={};
    for(int i=0;i<sz;i++){
        long long v=(mods[i]+a[i]-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];
        for(int j=i+1;j<sz+1;j++) {
            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
            coeffs[j]=(coeffs[j]*mods[i])%mods[j];
        }
    }
    return constants[sz];
}