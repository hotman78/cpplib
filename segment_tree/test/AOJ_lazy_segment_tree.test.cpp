#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "../lazy_segment_tree.hpp"
#include "../../functional/range_add_and_range_sum.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    lazy_segment_tree<lint,lint,plus<lint>,plus<lint>,range_add_and_range_sum<lint,lint>>seg(n);
    while(q--){
        lint c;
        cin>>c;
        if(c==0){
            lint s,t,u;
            cin>>s>>t>>u;
            seg.update(s-1,t,u);
        }else{
            lint s,t;
            cin>>s>>t;
            cout<<seg.get(s-1,t).unwrap_or(0)<<endl;
        }
    }
}