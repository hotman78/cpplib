struct MOD_FFT{
	MOD_FFT(){}
	using lint=mint;
	using C=complex<double>;
	int n=1;
	vector<lint> mul(vector<lint> a,vector<lint> b){
		int size=a.size()+b.size()-1;
		while(n<size)n<<=1;
		auto ac=itoc(a,n);
		auto bc=itoc(b,n);
		auto ia=fft(ac,false);
		auto ib=fft(bc,false);
		vector<C> ires(n);
		for(int i=0;i<n;i++)ires[i]=ia[i]*ib[i];
		auto res=ctoi(fft(ires,true),size);
		return res;
	}
	private:
	vector<C> itoc(vector<lint> v,int size){
		vector<C> res(size);
		for(int i=0;i<min<int>(size,v.size());i++)res[i]=v[i].a;
		return res;
	}
	vector<lint> ctoi(vector<C> v,int size){
		vector<lint> res(size);
		for(int i=0;i<min<int>(size,v.size());i++)res[i]=(lint)round(v[i].real()/n);
		return res;
	}
	vector<C> fft(const vector<C>& v,bool inv){
		int n=v.size();
		assert((n&(n-1))==0);
		if(n==1)return v;
		vector<C> v1(n/2);
		vector<C> v2(n/2);
		for(int i=0;i<n/2;i++)v1[i]=v[i*2];
		for(int i=0;i<n/2;i++)v2[i]=v[i*2+1];
		auto iv1=fft(v1,inv);
		auto iv2=fft(v2,inv);
		vector<C> res(n);
		C zeta;
		for(int i=0;i<n;i++){
			if(inv)zeta=C(cos(2*M_PI*i/n),-sin(2*M_PI*i/n));
			else zeta=C(cos(2*M_PI*i/n),sin(2*M_PI*i/n));
			res[i]=iv1[i%(n/2)]+zeta*iv2[i%(n/2)];
		}
		return res;
	}
};