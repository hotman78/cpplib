#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "../prime_list.hpp"
#include "../../util/template.hpp"

int main(){
    lint n;
    cin>>n;
    vec a(n);
    rep(i,n)cin>>a[i];
    auto v=prime_list(100'000'000);
    bitset<100'000'001>b;
    for(auto e:v){
        b[e]=1;
    }
    lint ans=0;
    for(auto e:a){
        if(b[e])ans++;
    }
    cout<<ans<<endl;
}