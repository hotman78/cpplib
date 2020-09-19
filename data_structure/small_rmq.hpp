#pragma once
#include<vector>

/**
 * RMQ(small) &amp;lt;O(N),O(1)&amp;gt;(N<=64)
 */

template<typename T>
class small_rmq{
    using u64=unsigned long long;
    std::vector<u64>table;
    std::vector<T> v;
    public:
    small_rmq(std::vector<T> v):v(v){
        assert(v.size()<=64);
        std::vector<int>tmp(v.size());
        table.resize(v.size(),0);
        std::stack<T>stk;
        for(int i=0;i<(int)v.size();++i){
            tmp.resize(v.size());
            while(!stk.empty()&&v[stk.top()]>=v[i]){
                stk.pop();
            }
            tmp[i]=stk.empty()?-1:stk.top();
            stk.emplace(i);
        }
        for(int i=0;i<(int)v.size();++i){
            if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));
        }
    }
    T query(int l,int r){
        assert(l!=r);
        const u64 tmp=table[r-1]&~((1ULL<<l)-1);
        if(tmp==0)return r-1;
        else return __builtin_ctzll(tmp);
    }
};