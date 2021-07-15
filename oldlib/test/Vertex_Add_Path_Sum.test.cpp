#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../graph_tree/HLD_seg.cpp"

int main(){
	lint n,q;
	cin>>n>>q;
	vec a(n);
	mat v(n);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n-1){
		lint s,t;
		cin>>s>>t;
		v[s].push_back(t);
		v[t].push_back(s);
	}
	HLD_seg<lint>hld(v,a);
	rep(i,q){
		lint p;
		cin>>p;
		if(p){
			lint s,t;
			cin>>s>>t;
			cout<<hld.get(s,t)<<endl;
		}else{
			lint s,t;
			cin>>s>>t;
			hld.update(s,t);
		}
	}
}