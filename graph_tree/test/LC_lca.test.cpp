#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../lca.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    auto g=load_treep(n);
    lca lca(g,0);
    while(q--){
        lint s,t;
        cin>>s>>t;
        cout<<lca.query(s,t)<<endl;
    }
}