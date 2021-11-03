
class mint {
    using u64 = std::uint_fast64_t;
    static u64 &mod() {
        static u64 mod_ = 0;
        return mod_;
    }
    public:
    u64 a;
     mint(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
     u64 &value()noexcept{return a;}
     const u64 &value() const noexcept {return a;}
     mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}
     mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}
     mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}
     mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}
     mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
     mint &operator-=(const mint rhs) noexcept {
        if (a<rhs.a)a += get_mod();
        a -= rhs.a;
        return *this;
    }
     mint &operator*=(const mint rhs) noexcept {
        a = a * rhs.a % get_mod();
        return *this;
    }
     mint operator++(int n) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
     mint operator--(int n) noexcept {
        if (a<1)a += get_mod();
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
     bool operator==(mint x) noexcept {
        return a==x.a;
    }
     bool operator!=(mint x) noexcept {
        return a!=x.a;
    }
     static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1).a==1)root++;
        return root.a;
    }
     mint pow(long long n){
        long long x=a;
        mint ret = 1;
        while(n>0) {
            if(n&1)(ret*=x);
            (x*=x)%=get_mod();
            n>>=1;
        }
        return ret;
    }
     mint inv(){
        return pow(get_mod()-2);
    }
    mint comb(lint b){
        using lint=long long;
        static bool init=1;
        static lint fac[3000001],ifac[3000001];
        if(init){
            init=0;
            fac[0]=1;
            ifac[0]=1;
            auto mod_pow=[&](lint x,lint n){
                lint ans = 1;
                while(n != 0){
                    if(n&1)ans=ans*x%get_mod();
                    x=x*x%get_mod();
                    n=n>>1;
                }
                return ans;
            };
            for(int i=0;i<3000000;i++){
                fac[i+1]=fac[i]*(i+1)%get_mod();
                ifac[i+1]=ifac[i]*mod_pow(i+1, get_mod()-2)%get_mod();
            }
        }
        if(a==0&&b==0)return 1;
        if((lint)a<b||a<0)return 0;
        lint tmp=ifac[a-b]*ifac[b]%get_mod();
        return tmp*fac[a]%get_mod();
    }
    mint fact(){
        using lint=long long;
        static bool init=1;
        static lint fac[3000001];
        if(init){
            init=0;
            fac[0]=1;
            for(int i=0;i<3000000;i++){
                fac[i+1]=fac[i]*(i+1)%get_mod();
            }
        }
        return fac[a];
    }
    friend ostream& operator<<(ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend istream& operator>>(istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    static void set_mod(const u64 x) { mod() = x; }
    static u64 get_mod() { return mod(); }
};
