class mint {
    using u64 = std::uint_fast64_t;
    public:
    u64 a;
    static constexpr u64 h=30;
    static constexpr u64 t=((1LL<<h)-1);
    static constexpr u64 get_mod(){return MOD;}
    static constexpr u64 f(u64 x,u64 y){
        u64 res=1;
        while(y){
            if(y&1)res=(res*x)&t;
            x=(x*x)&t;
            y>>=1;
        }
        return res;
    }
    static constexpr u64 get_base(){
        return f(t+1-get_mod(),t>>1);
    }
    constexpr static u64 MR(u64 a){
        constexpr u64 base=get_base();
        u64 c=(a+((a*base)&t)*get_mod())>>h;
        return c>=get_mod()?c-get_mod():c;
    }
    constexpr static u64 rMR(u64 a){
        constexpr u64 R2=(1LL<<(2*h))%get_mod();
        return MR(a*R2);
    }
    
    constexpr mint(const long long x = 0)noexcept:a(x>=0?rMR(x):rMR(get_mod()-(-x))){}
    constexpr u64 &value()noexcept{return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}
    constexpr mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}
    constexpr mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}
    constexpr mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}
    constexpr mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
        if (a<rhs.a)a += get_mod();
        a -= rhs.a;
        return *this;
    }
    constexpr mint &operator*=(const mint rhs) noexcept {
        a = MR(a*rhs.a);
        return *this;
    }
    constexpr mint operator++(int n) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint operator--(int n) noexcept {
        if (a<1)a += get_mod();
        a -= 1;
        return *this;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
        return (*this)*=rhs.pow(get_mod()-2);
    }
    constexpr bool operator==(mint x) noexcept {
        return a==x.a;
    }
    constexpr bool operator!=(mint x) noexcept {
        return a!=x.a;
    }
    static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1)==1)root++;
        return root.a;
    }
    constexpr mint pow(u64 n)noexcept{
        u64 x=(*this).a;
        u64 ret=1;
        while(n){
            if(n&1)ret=MR(ret*x);
            x=MR(x*x);
            n>>=1;
        }
        return mint(ret);
    }
    constexpr mint inv(){
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
        lhs << MR(rhs.a);
        return lhs;
    }
    friend istream& operator>>(istream& lhs,mint& rhs) noexcept {
        u64 x;
        lhs>>x;
        rhs=x;
        return lhs;
    }
};
vector<mint> mint::fac;
vector<mint> mint::ifac;
bool mint::init=1;