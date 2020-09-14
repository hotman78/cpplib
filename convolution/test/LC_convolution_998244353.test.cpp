#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../util/template.hpp"
#include "../../math/mod_int998244353.hpp"
#include "../convolution/FPS.hpp"
#include "../../util/ACL/util.hpp"

int main(){
    lint n,m;
    cin>>n>>m;
    fps<mint> a(n),b(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    output(a*b);
}