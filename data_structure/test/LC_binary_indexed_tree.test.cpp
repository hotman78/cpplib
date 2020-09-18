#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../binary_indexed_tree.hpp"
#include "../../template.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	BIT bit(n);
	rep(i,n){
		lint x;
		cin>>x;
		bit.add(i,x);
	}
	while(q--){
		lint c,s,t;
		cin>>c>>s>>t;
		if(c==0){
			bit.add(s,t);
		}else{
			cout<<bit.sum(s,t)<<endl;
		}
	}
}