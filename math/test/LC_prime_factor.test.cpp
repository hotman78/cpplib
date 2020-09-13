#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../prime_factor.hpp"
#include "../../util/template.hpp"

int main(){
    lint q;
    cin>>q;
    while(q--){
        lint n;
        cin>>n;
        vec d=prime_factor(n);
        cout<<d.size()<<" "; 
        output(d);
    }
}