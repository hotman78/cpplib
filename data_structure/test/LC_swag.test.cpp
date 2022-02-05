#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../math/mod_int998244353.hpp"
#include "../swag.hpp"
#include "../../functional/composite.hpp"
#include "../../util/template.hpp"

int main(){
	lint n;
	cin>>n;
	swag<pair<mint,mint>,composite<mint>>sw;
	while(n--){
		lint c;
		cin>>c;
		if(c==0){
			lint s,t;
			cin>>s>>t;
			sw.push(make_pair(s,t));
		}
		if(c==1){
			sw.pop();
		}
		if(c==2){
			lint x;
			cin>>x;
			cout<<composite<mint>()(make_pair(0,x),sw.fold().unwrap_or(make_pair(1,0))).second<<endl;
		}
	}
}