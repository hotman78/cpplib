#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"
#include"../../util/template.hpp"
#include"../dominator_tree.hpp"
#include"../graph_template.hpp"

int main(){
    lint n,m,s;
    cin>>n>>m>>s;
    auto g=load_digraph0(n,m);
    output(dominator_tree(g,s));
}