#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include"../dijkstra_fast.hpp"
#include"../graph_template.hpp"
#include"../../util/template.hpp"

int main(){
    lint n,m,s,t;
    cin>>n>>m>>s>>t;
    auto g=load_digraph0_weight<lint>(n,m);
    dijkstra<lint> d(g,s);
    if(d.reachable(t)){
        auto p=d.get_path(t);
        cout<<d[t]<<" "<<p.size()-1<<endl;
        rep(i,p.size()-1){
            cout<<p[i]<<" "<<p[i+1]<<endl;
        }
    }else{
        cout<<-1<<endl;
    }
}