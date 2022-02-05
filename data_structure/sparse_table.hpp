#pragma once
#include<vector>
#include<functional>
#include<cmath>
#include<algorithm>
#include"../alga/maybe.hpp"
/**
 * @brief SparseTable
 */

template<typename T,typename F>
class sparse_table{
    F f;
    std::vector<std::vector<T>>data;
    public:
    sparse_table(std::vector<T> v,F f=F()):f(f){
        int n=v.size(),log=log2(n)+1;
        data.resize(n,std::vector<T>(log));
        for(int i=0;i<n;i++)data[i][0]=v[i];
        for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){
            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);
        }
    }
    maybe<T> get(int l,int r){
        if(l==r)return maybe<T>();
        if(r<l)std::swap(l,r);
        int k=std::log2(r-l);
        return maybe<T>(f(data[l][k],data[r-(1<<k)][k]));
    }
};