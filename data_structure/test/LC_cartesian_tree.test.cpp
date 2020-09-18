#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "../cartesian_tree.hpp"
#include "../../template.hpp"

int main(){
	lint n;
	cin>>n;
	vec a(n);
	rep(i,n)cin>>a[i];
	cartesian_tree<lint>ct(a);
	output(ct.get());
}