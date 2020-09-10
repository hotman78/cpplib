#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<bits/stdc++.h>
using namespace std;
#include "union_find.hpp"

int main(){
    int n,q;
    cin>>n>>q;
    UF uf(n);
    for(int i=0;i<q;++i){
        int c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            uf.unite(s,t);
        }else{
            cout<<uf.same(s,t)<<endl;
        }
    }
}