#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "../prime_list.hpp"
#include "../../util/template.hpp"

int main(){
    lint n;
    cin>>n;
    auto v=prime_list(n);
    cout<<v.size()<<endl;
    for(auto e:v){
        cout<<e<<endl;
    }
}