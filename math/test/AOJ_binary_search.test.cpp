#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B"
#include "../binary_search.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,q;
    cin>>n;
    vec a(n);
    rep(i,n)cin>>a[i];
    cin>>q;
    lint ans=0;
    rep(i,q){
        lint x;
        cin>>x;
        lint t=bs(0,n-1,[&](lint i){return a[i]<=x;});
        if(t!=-1&&a[t]==x){
            ans++;
        }
    }
    cout<<ans<<endl;
}