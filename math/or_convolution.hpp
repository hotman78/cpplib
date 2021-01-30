template<typename T>
vector<T> or_conv(vector<T>s,vector<T>t,int n){
	auto zeta=[](vector<T>& f,int n){
		for(int i=0;i<n;++i){
			for(int j=0;j<(1<<n);++j){
				if((j&(1<<i))==0)f[j^(1<<i)]+=f[j];
			}
		}
	};
	auto mebius=[](vector<T>& f,int n){
		for(int i=0;i<n;++i){
			for(int j=0;j<(1<<n);++j){
				if((j&(1<<i))==0)f[j^(1<<i)]-=f[j];
			}
		}
	};
	zeta(s,n);
	zeta(t,n);
	for(int i=0;i<(1<<n);++i)s[i]*=t[i];
	mebius(s,n);
	return s;
}