#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "../../util/template.hpp"
#include "../mod_sqrt.hpp"

int main(){
    lint t;
    cin>>t;
    while(t--){
        lint y,p;
        cin>>y>>p;
        cout<<mod_sqrt(y,p)<<endl;
    }
}