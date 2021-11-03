#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../segment/segment2d.cpp"

int main(){
    segment2d<lint,lint> seg;
    lint n,q;
    cin>>n>>q;
    rep(i,n){
        lint x,y,v;
        cin>>x>>y>>v;
        seg.update(x,y,v);
    }
    rep(i,q){
        lint a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<seg.get(a,c,b,d)<<endl;
    }
}