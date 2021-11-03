#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
typedef vector<lint> vec;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../dataStructure/disjoint_sparse_table.cpp"

int main(){
	lint n,q;
	cin>>n>>q;
	vec a(n);
	rep(i,n)cin>>a[i];
	disjoint_sparse_table<lint> dst(a);
	rep(i,q){
		lint l,r;
		cin>>l>>r;
		cout<<dst.get(l,r)<<endl;
	}
}
