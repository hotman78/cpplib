#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../push_relabel.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,m;
    cin>>n>>m;
    push_relabel<lint>mf(n);
    while(m--){
        lint u,v,c;
        cin>>u>>v>>c;
        mf.add_edge(u,v,c);
    }
    cout<<mf.run(0,n-1)<<endl;
}