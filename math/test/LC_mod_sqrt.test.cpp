#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "../mod_sqrt.hpp"
#include "../../util/template.hpp"

int main(){
    lint t;
    cin>>t;
    while(t--){
        lint y,p;
        cin>>y>>p;
        cout<<mod_sqrt(y,p)<<endl;
    }
}