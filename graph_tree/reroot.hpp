#pragma once
#include<vector>

/**
 * @brief 全方位木DP
 */

template<typename T,typename F,typename Fix>
struct reroot{
    std::vector<std::vector<long long>>g;
    std::vector<int>p_list;
    std::vector<T>p_table;
    std::vector<bool>p_checked;
    std::vector<map<int,T>>table;
    std::vector<T>ans;
    F f;
    Fix fix;
    reroot(const std::vector<std::vector<long long>>& g,F f=F(),Fix fix=Fix()):g(g),f(f),fix(fix){
        int n=g.size();
        p_list.resize(n,-1);
        p_checked.resize(n,0);
        table.resize(n);
        p_table.resize(n,e);
        ans.resize(n,e);
        dfs1(0,-1);
        for(int i=0;i<n;++i)ans[i]=dfs2(i,-1);
    }
    T dfs1(int n,int p){
        p_list[n]=p;
        T tmp1=e,tmp2=e;
        std::vector<T>tmp(g[n].size());
        rep(i,g[n].size()){
            int t=g[n][i];
            if(t==p)continue;
            table[n][t]=tmp1;
            tmp1=f(tmp1,tmp[i]=dfs1(t,n));
        }
        for(int i=g[n].size()-1;i>=0;--i){
            int t=g[n][i];
            if(t==p)continue;
            table[n][t]=f(table[n][t],tmp2);
            tmp2=f(tmp[i],tmp2);
        }
        return fix(table[n][p]=tmp1,n,p);
    }
    T dfs2(int n,int p){
        if(n==-1)return e;
        if(!p_checked[n]){
            p_checked[n]=1;
            p_table[n]=dfs2(p_list[n],n);
        }
        if(p==-1){
            return f(table[n][p_list[n]],p_table[n]);
        }else{
            if(p_list[n]==-1)return fix(table[n][p],n,p);
            else return fix(f(table[n][p],p_table[n]),n,p);
        }
    }
    vector<T>query(){
        return ans;
    }
};