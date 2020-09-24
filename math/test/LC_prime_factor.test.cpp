#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../prime_factor.hpp"
#include "../../util/template.hpp"

int main(){
    lint q;
    cin>>q;
    while(q--){
        lint n;
        cin>>n;
        auto d=prime_factor(n);
        vec ans; 
        for(auto [s,t]:d)rep(i,t)ans.push_back(s);
        cout<<ans.size()<<" ";
        output(ans);
    }
}