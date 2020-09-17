#pragma once
#include<vector>

struct BIT{
    std::vector<long long> bit;
    int n;
    BIT(long long n):n(n){
        //bit.resize(n+1,0);
    }
    //0-indexed [0,x)-sum
    long long sum(long long x){
        long long res=0;
        for(int i=x;i;i-=i&-i)res+=bit[i];
        return res;
    }
    //0-indexed [x,y)-sum
    long long sum(long long x,long long y){
        return sum(y)-sum(x);
    }
    //0-indexed
    void add(long long x,long long val){
        ++x;
        if(x>=n)return;
        for(long long i=x;i<=n;i+=i&-i)bit[i]+=val;
    }
};