#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../util/template.hpp"
#include "../sparse_table.hpp"
#include "../../functional/MIN.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	vec a(n);
	rep(i,n)cin>>a[i];
	sparse_table<lint,MIN<lint>>s(a);
	while(q--){
		lint l,r;
		cin>>l>>r;
		cout<<s.get(l,r).unwrap()<<endl;
	}
}