#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "../dual_segment_tree.hpp"
#include "../../functional/update.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    dual_segment_tree<lint,update<lint>>seg(n);
    while(q--){
        lint c;
        cin>>c;
        if(c==0){
            lint s,t,u;
            cin>>s>>t>>u;
            seg.set(s,t+1,u);
        }else{
            lint x;
            cin>>x;
            cout<<seg.get(x).unwrap_or((1LL<<31)-1)<<endl;
        }
    }
}