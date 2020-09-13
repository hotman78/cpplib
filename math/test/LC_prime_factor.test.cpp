#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../prime_factor.hpp"
#include "../../util/template.hpp"

int main(){
    lint q;
    cin>>q;
    rep(i,q){
        lint n;
        cin>>n;
        vec d=prime_factor(n);
        sort(all(d));
        cout<<d.size()<<" "; 
        output(d);
    }
}