#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../disjoint_sparse_table.hpp"
#include "../../util/template.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	vec a(n);
	rep(i,n)cin>>a[i];
	disjoint_sparse_table<lint>dst(a);
	while(q--){
		lint s,t;
		cin>>s>>t;
		cout<<dst.get(s,t)<<endl;
	}
}