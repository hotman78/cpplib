#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "../../util/template.hpp"
#include "../cartesian_tree.hpp"

int main(){
	lint n;
	cin>>n;
	vec a(n);
	rep(i,n)cin>>a[i];
	cartesian_tree<lint>ct(a);
	output(ct.get());
}