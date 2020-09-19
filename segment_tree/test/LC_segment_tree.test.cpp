#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../segment_tree.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    vec v(n);
    rep(i,n){
        cin>>v[i];
    }
    segment_tree<lint,plus<lint>> seg(v);
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