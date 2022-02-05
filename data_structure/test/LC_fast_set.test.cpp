#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../fast_set.hpp"
#include "../../util/template.hpp"

int main(){
    lint q;
    cin>>q;
    fast_set<lint>v;
    while(q--){
        lint c;
        cin>>c;
        if(c==0){
            lint s,t;
            cin>>s>>t;
            v[s]=t;
        }else{
            lint s;
            cin>>s;
            cout<<v[s]<<endl;
        }
    }
}