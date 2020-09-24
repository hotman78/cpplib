#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include"../FPS_mint.hpp"
#include"../mod_int998244353.hpp"
#include"../../util/template.hpp"

int main(){
    int n;
    cin>>n;
    vector<mint> x(n),y(n);
    rep(i,n)cin>>x[i];
    rep(i,n)cin>>y[i];
    output(fps<mint>::interpolation(x,y));
}