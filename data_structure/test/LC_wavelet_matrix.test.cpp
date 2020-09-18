#include "../wavelet_matrix.hpp"
#include "../../template.hpp"

int main(){
	lint n,q;
	cin>>n>>q;
	vec a(n);
	rep(i,n)cin>>a[i];
	wavelet_matrix wm(a);
	while(q--){
		lint l,r,k;
		cin>>l>>r>>k;
		cout<<wm.kth_element(l,r,k)<<endl;
	}
}