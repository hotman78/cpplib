#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../li_chao_tree.hpp"
#include "../../util/template.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	LHT<lint>lht;
	while(n--){
		lint s,t;
		cin>>s>>t;
		lht.add_line(s,t);
	}
	while(q--){
		lint c;
		cin>>c;
		if(c==0){
			lint s,t;
			cin>>s>>t;
			lht.add_line(s,t);
		}else{
			lint x;
			cin>>x;
			cout<<lht.get(x)<<endl;
		}
	}
}