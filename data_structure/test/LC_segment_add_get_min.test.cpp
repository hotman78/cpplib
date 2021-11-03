#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../li_chao_tree.hpp"
#include "../../util/template.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	LHT<lint>lht;
	while(n--){
		lint l,r,s,t;
		cin>>l>>r>>s>>t;
		lht.add_segment(l,r,s,t);
	}
	while(q--){
		lint c;
		cin>>c;
		if(c==0){
			lint l,r,s,t;
			cin>>l>>r>>s>>t;
			lht.add_segment(l,r,s,t);
		}else{
			lint x;
			cin>>x;
			lint t=lht.get(x);
			if(t==std::numeric_limits<lint>::max())cout<<"INFINITY"<<endl;
			else cout<<t<<endl;
		}
	}
}