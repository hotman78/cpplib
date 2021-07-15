class NTT{
	using lint=long long;
	class mint {
		using u64 = std::uint_fast64_t;
		static u64 &mod() {
			static u64 mod_ = 0;
			return mod_;
		}
		public:
		u64 a;
		mint(const u64 x = 0) : a(x % get_mod()) {}
		u64 &value() noexcept { return a; }
		const u64 &value() const noexcept { return a; }
		mint operator+(const mint rhs) const {
			return mint(*this) += rhs;
		}
		mint operator-(const mint rhs) const {
			return mint(*this) -= rhs;
		}
		mint operator*(const mint rhs) const {
			return mint(*this) *= rhs;
		}
		mint operator/(const mint rhs) const {
			return mint(*this) /= rhs;
		}
		mint &operator+=(const mint rhs) {
			a += rhs.a;
			if (a >= get_mod()) {
				a -= get_mod();
			}
			return *this;
		}
		mint &operator-=(const mint rhs) {
			if (a < rhs.a) {
				a += get_mod();
			}
			a -= rhs.a;
			return *this;
		}
		mint &operator*=(const mint rhs) {
			a = a * rhs.a % get_mod();
			return *this;
		}
		mint &operator/=(mint rhs) {
			u64 exp = get_mod() - 2;
			while (exp) {
				if (exp % 2) {
					*this *= rhs;
				}
				rhs *= rhs;
				exp /= 2;
			}
			return *this;
		}

		static void set_mod(const u64 x) { mod() = x; }
		static u64 get_mod() { return mod(); }
	};
	mint pow(const mint& m,const lint& n){
		if(n==0)return 1;
		else if(n%2==0){
			mint x=pow(m,n/2);
			return x*x;
		}else{
			return m*pow(m,n-1);
		}
	}
	inline mint rev(const mint& m){return pow(m,m.get_mod()-2);}
	const lint NTT_PRIMES[18][2] = {
		{1224736769, 3}, // 2^24 * 73 + 1,
		{1053818881, 7}, // 2^20 * 3 * 5 * 67 + 1
		{1051721729, 6}, // 2^20 * 17 * 59 + 1
		{1045430273, 3}, // 2^20 * 997 + 1
		{1012924417, 5}, // 2^21 * 3 * 7 * 23 + 1
		{1007681537, 3}, // 2^20 * 31^2 + 1
		{1004535809, 3}, // 2^21 * 479 + 1
		{998244353, 3},  // 2^23 * 7 * 17 + 1
		{985661441, 3},  // 2^22 * 5 * 47 + 1
		{976224257, 3},  // 2^20 * 7^2 * 19 + 1
		{975175681, 17}, // 2^21 * 3 * 5 * 31 + 1
		{962592769, 7},  // 2^21 * 3^3 * 17 + 1
		{950009857, 7},  // 2^21 * 4 * 151 + 1
		{943718401, 7},  // 2^22 * 3^2 * 5^2 + 1
		{935329793, 3},  // 2^22 * 223 + 1
		{924844033, 5},  // 2^21 * 3^2 * 7^2 + 1
		{469762049, 3},  // 2^26 * 7 + 1
		{167772161, 3},  // 2^25 * 5 + 1
	};
	public:
	NTT(){}
	vector<mint> zeta,inv_zeta;
	vector<lint> mul(vector<lint> a,vector<lint> b,int idx){
		mint::set_mod(NTT_PRIMES[idx][0]);
		int size=a.size()+b.size()-1;
		lint n=1,log=0;
		while(n<size)n<<=1,log++;
		zeta.resize(log);
		inv_zeta.resize(log);
		zeta[0]=pow(mint(NTT_PRIMES[idx][1]),(NTT_PRIMES[idx][0]-1)/n);
		inv_zeta[0]=rev(zeta[0]);
		for(int i=1;i<log;i++)zeta[i]=zeta[i-1]*zeta[i-1];
		for(int i=1;i<log;i++)inv_zeta[i]=inv_zeta[i-1]*inv_zeta[i-1];
		vector<mint>ac(n),bc(n);
		for(int i=0;i<(int)a.size();i++)ac[i]=a[i];
		for(int i=0;i<(int)b.size();i++)bc[i]=b[i];
		auto ia=ntt(ac,false,idx,0);
		auto ib=ntt(bc,false,idx,0);
		vector<mint> ires(n);
		for(int i=0;i<n;i++)ires[i]=ia[i]*ib[i];
		auto res_m=ntt(ires,true,idx,0);
		vector<lint> res(size);
		for(int i=0;i<size;i++)res[i]=(res_m[i]/n).a;
		return res;
	}
	private:
	vector<mint> ntt(const vector<mint>& v,const bool& inv,const int& idx,const int& dep){
		int n=v.size();
		assert((n&(n-1))==0);
		if(n==1)return v;
		vector<mint> v1(n/2);
		vector<mint> v2(n/2);
		for(int i=0;i<n/2;i++)v1[i]=v[i*2];
		for(int i=0;i<n/2;i++)v2[i]=v[i*2+1];
		auto iv1=ntt(v1,inv,idx,dep+1);
		auto iv2=ntt(v2,inv,idx,dep+1);
		vector<mint> res(n);
		mint pow_zeta=1;
		mint _zeta=inv?inv_zeta[dep]:zeta[dep];
		for(int i=0;i<n;i++){
			res[i]=iv1[i%(n/2)]+pow_zeta*iv2[i%(n/2)];
			pow_zeta*=_zeta;
		}
		return res;
	}
};