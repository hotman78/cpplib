#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../union-find/UnionFind.cpp"

int main(){
	int n,q;
	cin>>n>>q;
	UF uf(n);
	rep(i,q){
		lint x,s,t;
		cin>>x>>s>>t;
		if(x){
			cout<<uf.same(s,t)<<endl;
		}else{
			uf.unite(s,t);
		}
	}
}