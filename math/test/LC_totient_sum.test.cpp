#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "../totient_sum.hpp"
#include "../mod_int998244353.hpp"
#include "../../util/ACL/util.hpp"
#include "../../util/template.hpp"

int main(){
    lint n;
    cin>>n;
    cout<<totient_sum<mint>(n)<<endl;
}