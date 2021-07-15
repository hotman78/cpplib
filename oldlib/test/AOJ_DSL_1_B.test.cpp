#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../union-find/waighted_union_find.cpp"

int main(){
	int n,q;
	cin>>n>>q;
	WUF uf(n);
	rep(i,q){
		lint x,s,t,u;
		cin>>x;
		if(x){
            cin>>s>>t;
			if(uf.same(s,t))cout<<uf.diff(s,t)<<endl;
			else cout<<"?"<<endl;
		}else{
            cin>>s>>t>>u;
			uf.unite(s,t,u);
		}
	}
}