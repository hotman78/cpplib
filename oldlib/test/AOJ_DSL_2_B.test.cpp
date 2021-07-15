#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../segment/segment.cpp"

int main(){
    int n,q;
	cin>>n>>q;
	segment<int> seg(n);
	rep(i,q){
		lint x,s,t;
		cin>>x>>s>>t;
		if(x){
			cout<<seg.get(s-1,t)<<endl;
		}else{
			seg.update(s-1,t);
		}
	}
}