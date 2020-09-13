#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../prime_list.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,a,b;
    cin>>n>>a>>b;
    auto v=prime_list(n);
    vec ans;
    for(int i=b;i<(int)v.size();i+=a){
        ans.push_back(v[i]);
    }
    cout<<upper_bound(all(v),n)-v.begin()<<" "<<ans.size()<<endl;
    output(ans);
    cout<<endl;
}