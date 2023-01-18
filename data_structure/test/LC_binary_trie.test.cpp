#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../util/template.hpp"
#include "../binary_trie.hpp"

int main(){
	lint n;
	cin>>n;
	binary_trie b;
	while(n--){
		lint c,x;
		cin>>c>>x;
		if(c==0&&!b.count(x))b.insert(x);
		if(c==1)b.erase(x);
		if(c==2)cout<<b.xor_min(x)<<endl;
	}
}