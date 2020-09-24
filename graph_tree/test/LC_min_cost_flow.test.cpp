#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"
#include"../../util/template.hpp"
#include"../min_cost_flow.hpp"
#include"../../util/int128.hpp"

int main(){
    lint n,m;
    cin>>n>>m;
    vector<lint>b(n);
    rep(i,n){
        lint x;
        cin>>x;
        b[i]=x;
    }
    min_cost_flow<lint,__int128_t> mf(n);
    loop(m){
        lint from,to,l,r,cost;
        cin>>from>>to>>l>>r>>cost;
        mf.add_edge(from,to,l,r,cost);
    }
    if(mf.ok(b)){
        cout<<mf.run(b)<<endl;
        auto f=mf.flow_result();
        auto p=mf.potential(f);
        rep(i,n){
            cout<<p[i]<<endl;
        }
        rep(i,m){
            cout<<f[i]<<endl;
        }
    }
    else cout<<"infeasible"<<endl;
}