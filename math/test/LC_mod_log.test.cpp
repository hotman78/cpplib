#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../mod_log.hpp"
#include "../../util/template.hpp"

int main(){
    lint t;
    cin>>t;
    while(t--){
        lint x,y,p;
        cin>>x>>y>>p;
        cout<<mod_log(x,y,p)<<endl;
    }
}