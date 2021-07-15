template<typename Mint>
struct fps1:FPS_BASE<Mint,fps1<Mint>>{
    class mint_fps;
    using FPS_BASE<Mint,fps1<Mint>>::FPS_BASE;
    using P=fps1<Mint>;
    P mul(P s,P t)override{
        lint n=s.size()+t.size()-1;
        lint h=1;
        while((1<<h)<n)h++;
        vector<mint_fps>a(1<<h,mint_fps(0)),b(1<<h,mint_fps(0));
        for(int i=0;i<(int)s.size();i++){
            a[i]=s[i].value();
        }
        for(int i=0;i<(int)t.size();i++){
            b[i]=t[i].value();
        }
        auto c=ntt(a,h,0);
        auto d=ntt(b,h,0);
        for(int i=0;i<(1<<h);i++){
            c[i]*=d[i];
        }
        auto tmp=ntt(c,h,1);
        P res(n);
        for(int i=0;i<n;i++)res[i]=tmp[i].value();
        return res.pre(n);
    }
    vector<mint_fps> ntt(vector<mint_fps> v,const int& h,const bool& inv){
		int n=v.size(),mask=n-1;
		vector<mint_fps> tmp(n);
        vector<mint_fps> table(n,1);
        mint_fps theta=mint_fps(3).base(h);
        if(inv)theta=theta.inv();
        for(int i=1;i<n;++i)table[i]=table[i-1]*theta;
        for(int j=n>>1,t=h-1;j>=1;j>>=1,--t){
            for(int k=0;k<n;++k){
                int s=k&(j-1);
                int i=k>>t;
                tmp[k]=v[((i<<(t+1))|s)&mask]+table[i*j]*v[((i<<(t+1))|j|s)&mask];
            }
            swap(v,tmp);
        }
        if(inv)for(int i=0;i<n;++i)v[i]/=n;
        return v;
	}
    class mint_fps{
        using u64 = std::uint_fast64_t;
        u64 mods[3]={1224736769,1045430273,1007681537};
        public:
        u64 a[3];
        constexpr mint_fps(const long long x = 0){
            for(int i=0;i<3;i++){
                a[i]=x>=0?x%get_mod():get_mod()-(-x)%get_mod();
            }
        }
        constexpr u64 value() noexcept {
            return garner();
        }
        constexpr mint_fps operator+(const mint_fps rhs)const noexcept{return mint_fps(*this) += rhs;}
        constexpr mint_fps operator-(const mint_fps rhs)const noexcept{return mint_fps(*this)-=rhs;}
        constexpr mint_fps operator*(const mint_fps rhs) const noexcept {return mint_fps(*this) *= rhs;}
        constexpr mint_fps operator/(const mint_fps rhs) const noexcept {return mint_fps(*this) /= rhs;}
        constexpr mint_fps &operator+=(const mint_fps rhs) noexcept {
            for(int i=0;i<3;++i){
                a[i]+=rhs.a[i];
                if (a[i]>=mods[i])a[i]-=mods[i];
            }
            return *this;
        }
        constexpr bool operator==(mint_fps x) noexcept {
            return a==x.a;
        }
        constexpr bool operator!=(mint_fps x) noexcept {
            return a!=x.a;
        }
        constexpr mint_fps &operator-=(const mint_fps rhs) noexcept {
            for(int i=0;i<3;++i){
                a[i]-=rhs.a[i];
                if (a[i]>=mods[i])a[i]-=mods[i];
            }
            return *this;
        }
        constexpr mint_fps &operator*=(const mint_fps rhs) noexcept {
            for(int i=0;i<3;++i){
                a[i]=a[i]*rhs.a[i]%mods[i];
            }
            return *this;
        }
        constexpr mint_fps &operator/=(mint_fps rhs)noexcept{
            for(int i=0;i<3;i++){
                u64 ret =rhs.a[i];
                u64 exp=mods[i]-2;
                while (exp) {
                    if (exp %2) {
                        (a[i]*=ret)%=mods[i];
                    }
                    (ret *= ret)%=mods[i];
                    exp /= 2;
                }
            }
            return *this;
        }
        constexpr mint_fps operator++(int n) noexcept {
            return *this+=1;
        }
        constexpr mint_fps operator--(int n) noexcept {
            return *this-=1;
        }
        constexpr mint_fps base(int h)noexcept{
            for(int i=0;i<3;i++){
                u64 ret =3;
                a[i]=1;
                u64 exp=((mods[i]-1)>>h);
                while (exp) {
                    if (exp %2) {
                        (a[i]*=ret)%=mods[i];
                    }
                    (ret *= ret)%=mods[i];
                    exp /= 2;
                }
            }
            return *this;
        }
        constexpr mint_fps inv(){
            return mint_fps(1)/(*this);
        }
        constexpr static u64 get_mod(){return MOD;}
        constexpr u64 garner(){
            const int sz=3;
            using u64 = long long;
            const u64 mods[4]={1224736769,1045430273,1007681537,get_mod()};
            u64 coeffs[sz+1]={1,1,1,1};
            u64 constants[sz+1]={};
            auto modinv=[](u64 x,u64 mod){
                u64 y=mod-2;
                u64 ret=1;
                while(y>0) {
                    if(y&1)(ret*=x)%=mod;
                    (x*=x)%=mod;
                    y>>=1;
                }
                return ret;
            };
            for(int i=0;i<sz;i++) {
                u64 v=(mods[i]+a[i]-constants[i])%mods[i]*modinv(coeffs[i],mods[i])%mods[i];
                for(int j=i+1;j<sz+1;j++) {
                    constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
                    coeffs[j]=(coeffs[j]*mods[i])%mods[j];
                }
            }
            return constants[3];
        }
    };
};