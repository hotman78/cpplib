#pragma once
#include<string>
#include<vector>
#include<set>
#include<tuple>

/**
 * @brief 部分列DP(WIP)
 */

struct subsequence{
    struct node;
    using np=node*;
    struct node{
        np ch[26]={};
        int idx;
        char c;
        node(int idx,char c):idx(idx),c(c){}
    };
    std::string s;int n;
    std::vector<std::vector<int>>m;
    std::vector<np>v;
    np root=0;
    subsequence(std::string s):s(s),n(s.size()),m(n+1,std::vector<int>(26,-1)),v(n+1){
        for(int i=n-1;i>=0;--i){
            m[i]=m[i+1];
            m[i][s[i]-'a']=i;
        }
        for(int i=0;i<n+1;++i)v[i]=new node(i,(i?s[i-1]:'#'));
        for(int i=0;i<n;++i){
            for(int j=0;j<26;++j){
                if(~m[i][j])v[i]->ch[j]=v[m[i][j]+1];
            }
        }
        root=v[0];
    }
    //ここから問題ごとに書く
    std::vector<long long>dp;
    void dp2(){
        dp.resize(n+1);
        for(int i=n;i>=0;--i){
            np t=v[i];
            dp[i]=;
            for(int j=0;j<26;++j){
                if(!t->ch[j])dp[i]=1;
                else dp[i]=min(dp[i],dp[t->ch[j]->idx]+1);
            }
        }
    }
    string ans;
    void dfs(np t){
        for(int i=0;i<26;i++){
            if(!t->ch[i]){
                if(t!=root)ans+=t->c;
                ans+=char(i+'a');
                return;
            }
            if(dp[t->ch[i]->idx]==dp[t->idx]-1){
                if(t!=root)ans+=t->c;
                dfs(t->ch[i]);
                return;
            }
        }
    }
    string solve(){
        dp2();
        dfs(root);
        return ans;
    }
};