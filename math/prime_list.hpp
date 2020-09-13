#pragma once
#include<vector>
#include<bitset>
#include<set>

template<int n=10'000'000>
std::vector<long long> primeList() {
    std::bitset<n+1> p;
    p.set();
    p[0]=0;
    for(int i=2;i<std::sqrt(n)+10;++i){
        if(!p[i])continue;
        for(int j=2*i;j<n;j+=i)p[j]=0;
    }
    std::vector<long long>list;
    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);
    return list;
}