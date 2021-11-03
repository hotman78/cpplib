#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../util/template.hpp"
#include "../../math/mod_int1000000007.hpp"
#include "../FPS_mint.hpp"

int main(){
    lint n,m;
    cin>>n>>m;
    fps<mint> a(n),b(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    output(a*b);
}