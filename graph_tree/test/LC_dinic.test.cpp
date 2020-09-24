#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313"
#include"../dinic.hpp"
#include"../../util/template.hpp"

int main(){
    int n,e,q;
    cin>>n>>e>>q;
    dinic<lint>mf(n,0,n-1);
    while(e--){
        int s,t;
        cin>>s>>t;
        s--;t--;
        mf.update_edge(s,t,1);
        mf.update_edge(t,s,1);
    }
    while(q--){
        int c,s,t;
        cin>>c>>s>>t;
        s--;t--;
        mf.update_edge(s,t,c==1?1:-1);
        mf.update_edge(t,s,c==1?1:-1);
        cout<<mf.run()<<endl;
    }
}