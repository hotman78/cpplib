#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "../is_prime.hpp"
#include "../../util/template.hpp"

int main(){
    lint t;
    cin>>t;
    lint ans=0;
    while(t--){
        lint n;
        cin>>n;
        ans+=is_prime(n);
    }
    cout<<ans<<endl;
}