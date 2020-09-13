#pragma once
#include<vector>
#include<bitset>
#include<set>

template<typename T>
std::set<T> primeSet(T n) {
    std::vector<bool> p(n+1,1);
    std::set<T> set;
    p[0]=0;
    for(int i=2;i<=std::sqrt(n);i++) {
        if(p[i])for(int j=2;j<n/i+1;j++)p[i*j]=0;
    }
    for(int i=2;i<=n;i++)if(p[i])set.insert(i);
    return set;
}