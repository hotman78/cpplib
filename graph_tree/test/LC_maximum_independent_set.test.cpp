#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "../maximum_independent_set.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,m;
    cin>>n>>m;
    auto g=load_graph0(n,m);
    auto e=maximum_independent_set(g);
    cout<<e.size()<<endl;
    output(e);
}