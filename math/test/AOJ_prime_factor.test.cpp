#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "../prime_factor.hpp"
#include "../../util/template.hpp"

int main(){
    lint n;
    cin>>n;
    auto v=prime_factor(n);
    cout<<n<<": ";
    vec ans;
    for(auto [s,t]:v)rep(i,t)ans.push_back(s);
    output(ans);
}