#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#include "../tetration.hpp"
#include "../../util/template.hpp"

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,m;
        cin>>a>>b>>m;
        cout<<tetration(a,b,m)<<endl;
    }
}