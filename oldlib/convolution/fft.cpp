template<typename T>
class FFT{
    using u64 = std::uint_fast64_t;
    using real=long double;
	using C=complex<real>;
	int n=1;
    public:
	vector<T> mul(const vector<T>& a,const vector<T>& b){
		const int size=a.size()+b.size()-1;
        int h=0;
		while(n<size)n<<=1,++h;
		auto c=itoc(b,a,n);
		auto ic=fft(c,h,false);
		vector<C> ires(n);
		for(int i=0;i<n;++i){
            int j=i==0?0:n-i;
            ires[i]=(ic[i]+conj(ic[j]))*(ic[i]-conj(ic[j]))*C(0,-.25);
        }
		auto res=ctoi(fft(ires,h,true),size);
		return res;
	}
	private:
	vector<C> itoc(const vector<T>& s,const vector<T>& t,const int& n){
		vector<C> res(n);
		for(int i=0;i<n;++i)res[i]=C(i<(int)s.size()?cast(s[i]):0.,i<(int)t.size()?cast(t[i]):0);
		return res;
	}
	vector<T> ctoi(const vector<C>& v,const int& size){
		vector<T> res(size);
		for(int i=0;i<min<int>(size,v.size());i++)res[i]=recast(v[i].real());
		return res;
	}
	vector<C> fft(vector<C> v,const int& h,const bool& inv){
		int n=v.size(),mask=n-1;
		assert((n&(n-1))==0);
		vector<C> tmp(n);
        C table[n];
        real theta =2*M_PI*(inv?-1:1)/n;
        for(int i=0;i<n;++i)table[i]=C(cos(i*theta),sin(i*theta));
        for(int j=n>>1,t=h-1;j>=1;j>>=1,--t){
            for(int k=0;k<n;++k){
                int s=k&(j-1); // T は 下 t 桁
                int i=k>>t; // i は 上 h - t 桁
                tmp[k]=v[((i<<(t+1))|s)&mask]+table[i*j]*v[((i<<(t+1))|j|s)&mask];
                // ζ_(2^(h - t))^i
            }
            swap(v,tmp);
        }
        if(inv)for(int i=0;i<n;++i)v[i]/=n;
        return v;
	}
    inline real cast(const T& t){
        return t.a;
    }
    inline T recast(const real& t){
        return round(t-floor(t/MOD)*MOD);
    }
};


// template<typename T>
// class FFT{
// 	using C=complex<double>;
// 	lint n=1;
//     public:
// 	vector<lint> mul(const vector<lint>& a,const vector<lint>& b){
// 		const int size=a.size()+b.size()-1;
// 		while(n<size)n<<=1;
// 		auto c=itoc(b,a,n);
// 		auto ic=fft(c,false);
// 		vector<C> ires(n);
// 		for(int i=0;i<n;++i){
//             int j=i==0?0:n-i;
//             ires[i]=(ic[i]+conj(ic[j]))*(ic[i]-conj(ic[j]))*C(0, -.25);
//         }
// 		auto res=ctoi(fft(ires,true),size);
// 		return res;
// 	}
// 	private:
// 	vector<C> itoc(const vector<T>& s,const vector<T>& t,const int& n){
// 		vector<C> res(n);
// 		for(int i=0;i<n;++i)res[i]=C(i<(int)s.size()?s[i]:0,i<(int)t.size()?t[i]:0);
// 		return res;
// 	}
// 	vector<T> ctoi(const vector<C>& v,const int& size){
// 		vector<T> res(size);
// 		for(int i=0;i<min<int>(size,v.size());i++)res[i]=round(v[i].real()/n);
// 		return res;
// 	}
// 	vector<C> fft(const vector<C>& v,const bool& inv){
// 		int n=v.size();
// 		assert((n&(n-1))==0);
// 		if(n==1)return v;
// 		vector<C> v1(n/2);
// 		vector<C> v2(n/2);
// 		for(int i=0;i<n/2;i++)v1[i]=v[i*2];
// 		for(int i=0;i<n/2;i++)v2[i]=v[i*2+1];
// 		auto iv1=fft(v1,inv);
// 		auto iv2=fft(v2,inv);
// 		vector<C> res(n);
// 		C zeta;
// 		for(int i=0;i<n;i++){
// 			if(inv)zeta=C(cos(2*M_PI*i/n),-sin(2*M_PI*i/n));
// 			else zeta=C(cos(2*M_PI*i/n),sin(2*M_PI*i/n));
// 			res[i]=iv1[i%(n/2)]+zeta*iv2[i%(n/2)];
// 		}
// 		return res;
// 	}
// };

// struct FFT{
// 	FFT(){}
// 	using lint=long long;
// 	using C=complex<double>;
// 	lint n=1;
// 	vector<lint> mul(vector<lint> a,vector<lint> b){
// 		int size=a.size()+b.size()-1;
// 		while(n<size)n<<=1;
// 		auto ac=itoc(a,n);
// 		auto bc=itoc(b,n);
// 		auto ia=fft(ac,false);
// 		auto ib=fft(bc,false);
// 		vector<C> ires(n);
// 		for(int i=0;i<n;i++)ires[i]=ia[i]*ib[i];
// 		auto res=ctoi(fft(ires,true),size);
// 		return res;
// 	}
// 	private:
// 	vector<C> itoc(vector<lint> v,int size){
// 		vector<C> res(size);
// 		for(int i=0;i<min<int>(size,v.size());i++)res[i]=v[i];
// 		return res;
// 	}
// 	vector<lint> ctoi(vector<C> v,int size){
// 		vector<lint> res(size);
// 		for(int i=0;i<min<int>(size,v.size());i++)res[i]=round(v[i].real()/n);
// 		return res;
// 	}
// 	vector<C> fft(vector<C> v,bool inv){
// 		int n=v.size();
// 		assert((n&(n-1))==0);
// 		if(n==1)return v;
// 		vector<C> v1(n/2);
// 		vector<C> v2(n/2);
// 		for(int i=0;i<n/2;i++)v1[i]=v[i*2];
// 		for(int i=0;i<n/2;i++)v2[i]=v[i*2+1];
// 		auto iv1=fft(v1,inv);
// 		auto iv2=fft(v2,inv);
// 		vector<C> res(n);
// 		C zeta;
// 		for(int i=0;i<n;i++){
// 			if(inv)zeta=C(cos(2*M_PI*i/n),-sin(2*M_PI*i/n));
// 			else zeta=C(cos(2*M_PI*i/n),sin(2*M_PI*i/n));
// 			res[i]=iv1[i%(n/2)]+zeta*iv2[i%(n/2)];
// 		}
// 		return res;
// 	}
// };