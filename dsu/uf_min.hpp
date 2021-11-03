#pragma once
#include<vector>
#include<numeric>
#include<limits>

/**
 * @brief 根とのPathの中での最小値を返すUnionFind
 */

template<typename T>
struct uf_min{
    constexpr static int inf=std::numeric_limits<T>::max();
    std::vector<int>par,mnid;
    std::vector<T>mn;
    uf_min(int v){
        par.resize(v);
        mn.resize(v,inf);
        mnid.resize(v);
        std::iota(par.begin(),par.end(),0);
        std::iota(mnid.begin(),mnid.end(),0);
    }
    int find(int v){
        if(par[v]==v)return v;
        int r=find(par[v]);
        if(mn[v]>mn[par[v]]){
            mnid[v]=mnid[par[v]];
            mn[v]=mn[par[v]];
        }
        par[v]=r;
        return r;
    }
    void set(int v,T x){
        mn[v]=x;
    }
    T eval(int v){
        find(v);
        return mnid[v];
    }
    //xをyの親にする
    void link(int x,int y){
        par[y]=x;
    }
};