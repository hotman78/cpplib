#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../util/template.hpp"
#include "../RMQ.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	vector<lint>a(n);
	rep(i,n)cin>>a[i];
	RMQ<lint> rmq(a);
	while(q--){
		lint s,t;
		cin>>s>>t;
		cout<<rmq.query(s,t)<<endl;
	}
}