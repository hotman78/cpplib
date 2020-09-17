#pragma once
#include<assert.h>
#include<vector>
#include<numeric>
#include<cmath>

template<typename T>
class RMQ{
    class small_rmq{
        using u64=unsigned long long;
        std::vector<u64>table;
        std::vector<T> v;
        public:
        small_rmq(std::vector<T> v):v(v){
            assert(v.size()<=64);
            vector<int>tmp(v.size());
            table.resize(v.size(),0);
            stack<T>stk;
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
            if(l==r)return numeric_limits<T>::max();
            const u64 tmp=table[r-1]&~((1ULL<<l)-1);
            if(tmp==0)return v[r-1];
            else return v[__builtin_ctzll(tmp)];
        }
    };
    class sparse_table{
        std::vector<std::vector<T>>data;
        public:
        sparse_table(std::vector<T> v){
            int n=v.size(),log=log2(n)+1;
            data.resize(n,vector<T>(log));
            for(int i=0;i<n;i++)data[i][0]=v[i];
            for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){
                data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);
            }
        }
        T get(int l,int r){
            if(l==r)return std::numeric_limits<T>::max();
            if(r<l)swap(l,r);
            int k=log2(r-l);
            return f(data[l][k],data[r-(1<<k)][k]);
        }
        constexpr static T e=std::numeric_limits<T>::max();
        T f(T s,T t){
            return std::min(s,t);
        }
    };
    constexpr static int b=64;
    std::vector<T>v;
    std::vector<small_rmq*>backet;
    sparse_table* st=0;
    public:
    RMQ(std::vector<T>v):v(v){
        std::vector<T>tmp2;
        for(int i=0;i<(int)v.size();i+=b){
            std::vector<T>tmp;
            T mn=std::numeric_limits<T>::max();
            for(int j=0;i+j<(int)v.size()&&j<b;j++){
                tmp.push_back(v[i+j]);
                if(mn>v[i+j])mn=v[i+j];
            }
            tmp2.push_back(mn);
            backet.push_back(new small_rmq(tmp));
        }
        st=new sparse_table(tmp2);
    }
    T query(int s,int t){
        if(s/b==t/b)return backet[s/b]->query(s%b,t%b);
        return std::min({backet[s/b]->query(s%b,b),st->get(s/b+1,t/b),backet[t/b]->query(0,t%b)});
    }
};