#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../segment/segment_tree_beats.cpp"

int main(){
    lint n,q;
    cin>>n>>q;
    segment_tree_beats<lint>seg(n);
    rep(i,n){
        lint x;
        cin>>x;
        seg.add(i,i+1,x);
    }
    rep(i,q){
        lint x;
        cin>>x;
        if(x==0){
            lint l,r,b;
            cin>>l>>r>>b;
            seg.chmin(l,r,b);
        }
        if(x==1){
            lint l,r,b;
            cin>>l>>r>>b;
            seg.chmax(l,r,b);
        }
        if(x==2){
            lint l,r,b;
            cin>>l>>r>>b;
            seg.add(l,r,b);
        }
        if(x==3){
            lint l,r;
            cin>>l>>r;
            cout<<lint(seg.get_sum(l,r))<<endl;
        }
    }
}