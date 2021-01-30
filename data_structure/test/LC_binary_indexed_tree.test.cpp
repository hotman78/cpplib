#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../binary_indexed_tree.hpp"
#include "../../util/template.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	BIT b(n);
	rep(i,n){
		lint x;
		cin>>x;
		b.add(i,x);
	}
	while(q--){
		lint c,s,t;
		cin>>c>>s>>t;
		if(c==0){
			b.add(s,t);
		}else{
			cout<<b.sum(s,t)<<endl;
		}
	}
}