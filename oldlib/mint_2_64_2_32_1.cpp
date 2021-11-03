class mint {
  using u64 = std::uint_fast64_t;
    public:
    u64 a;
    constexpr mint(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
    constexpr u64 &value()noexcept{return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}
    constexpr mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}
    mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}
    mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}
    constexpr mint &operator+=(const mint rhs) noexcept {
		__uint128_t x=__uint128_t(a)+rhs.a;
        if (x >= get_mod())x -= get_mod();
		a=x;
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
		__uint128_t x=a;
        if (x<rhs.a)x += get_mod();
        x -= rhs.a;
		a=x;
        return *this;
    }
    mint &operator*=(const mint rhs) noexcept {
    	a=__uint128_t(a)*rhs.a%get_mod();
        return *this;
    }
    constexpr mint operator++(int n) noexcept {
        a += 1;
        return *this;
    }
    constexpr mint operator--(int n) noexcept {
        a -= 1;
        return *this;
    }
    mint &operator/=(mint rhs) noexcept {
        u64 exp=get_mod()-2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr bool operator==(mint x) noexcept {
        return a==x.a;
    }
    constexpr bool operator!=(mint x) noexcept {
        return a!=x.a;
    }
	constexpr bool operator<(mint x) noexcept {
        return a<x.a;
    }
	constexpr bool operator>(mint x) noexcept {
        return a>x.a;
    }
	constexpr bool operator<=(mint x) noexcept {
        return a<=x.a;
    }
	constexpr bool operator>=(mint x) noexcept {
        return a>=x.a;
    }
    static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1).a==1)root++;
        return root.a;
    }
    mint pow(u64 n){
        mint x=a;
        mint ret = 1;
        while(n>0) {
            if(n&1)ret*=x;
            x*=x;
            n>>=1;
        }
        return ret;
    }
    mint inv(){
        return pow(get_mod()-2);
    }
    static vector<mint> fac,ifac;
    static bool init;
    constexpr static int mx=10000001;
    void build(){
        init=0;
        fac.resize(mx);
        ifac.resize(mx);
        fac[0]=1,ifac[0]=1;
        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;
        ifac[mx-1]=fac[mx-1].inv();
        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);
    }
    mint comb(lint b){
        if(init)build();
        if(a==0&&b==0)return 1;
        if((lint)a<b||a<0)return 0;
        return fac[a]*ifac[a-b]*ifac[b];
    }
    mint fact(){
        if(init)build();
        return fac[a];
    }
    mint fact_inv(){
        if(init)build();
        return ifac[a];
    }
    friend ostream& operator<<(ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend istream& operator>>(istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    constexpr static u64 get_mod(){return -(1ULL<<32)+1;}
};
vector<mint> mint::fac;
vector<mint> mint::ifac;
bool mint::init=1;