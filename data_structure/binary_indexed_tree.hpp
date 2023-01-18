#pragma once
#include<vector>
#include<functional>

/**
 * @brief BinaryIndexedTree
 */

template<typename T=long long,typename F=std::plus<T>,typename Inv=std::minus<T>>
struct BIT{
    std::vector<T> bit;
    int n;
    F f;
    Inv inv;
    BIT(int n,T zero=T(),F f=F(),Inv inv=Inv()):n(n),f(f),inv(inv){
        bit.resize(n+1,zero);
    }
    //0-indexed [0,x)-sum
    T sum(T x){
        T res=0;
        for(int i=x;i;i-=i&-i)res=f(res,bit[i]);
        return res;
    }
    //0-indexed [x,y)-sum
    T sum(int x,int y){
        return inv(sum(y),sum(x));
    }
    //0-indexed
    void add(int x,T val){
        if(x>=n)return;
        for(int i=x+1;i<=n;i+=i&-i)bit[i]=f(bit[i],val);
    }
};