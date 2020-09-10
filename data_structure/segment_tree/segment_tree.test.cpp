#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../../util/template.hpp"
#include "segment_tree.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    vec v(n);
    rep(i,n){
        cin>>v[i];
    }
    auto seg=make_segment_tree(v,plus<lint>());
    rep(i,q){
        lint c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            seg.apply(s,t);
        }else{
            cout<<seg.get(s,t).unwrap()<<endl;
        }
    }
}