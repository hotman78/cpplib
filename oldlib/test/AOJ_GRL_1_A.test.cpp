#define IGNORE
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../graph_tree/dij.cpp"

int main(){
    lint v,e,r;
    cin>>v>>e>>r;
    vector<vector<pair<lint,lint>>>g(v);
    rep(i,e){
        lint s,t,d;
        cin>>s>>t>>d;
        g[s].emplace_back(t,d);
        g[t].emplace_back(s,d);
    }
    auto d=dij(g,r,0LL,INF,less<lint>(),plus<lint>());
    rep(i,v){
        cout<<d[i]<<endl;
    }
}