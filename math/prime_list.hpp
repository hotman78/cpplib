#pragma once
#include<vector>
#include<bitset>
#include<cmath>
#include<set>

/**
 * @brief 素数列挙
 */

std::bitset<500'000'001> p;
std::vector<long long> prime_list(int n) {
    p.set();
    p[0]=0;
    for(int i=2;i*i<=n;++i){
        if(!p[i])continue;
        for(int j=2*i;j<=n;j+=i)p[j]=0;
    }
    std::vector<long long>list;
    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);
    return list;
}

