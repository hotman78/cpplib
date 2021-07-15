class bint{
    using u64 = uint_fast64_t;
    public:
    int num=3;
    const vector<u64> mod={1000000007LL,998244353LL,999999937LL};
    vector<u64> a;
    bint(const long long x = 0) noexcept{
        a.resize(3);
        for(int i=0;i<num;i++)a[i]=x<0?mod[i]-abs(x)%mod[i]:x%mod[i];
    }
    u64 value() noexcept {
        return garner(a,mod,9223372036854775807LL);
    }
    bint operator+(const bint rhs) const noexcept {
        return bint(*this) += rhs;
    }
    bint operator-(const bint rhs) const noexcept {
        return bint(*this) -= rhs;
    }
    bint operator*(const bint rhs) const noexcept {
        return bint(*this) *= rhs;
    }
    bint operator/(const bint rhs) const noexcept {
        return bint(*this) /= rhs;
    }
    bint &operator+=(const bint rhs) noexcept {
        for(int i=0;i<num;i++){
            a[i]+=rhs.a[i];
            if (a[i]>=mod[i]){
                a[i]-=mod[i];
            }
        }
        return *this;
    }
    bint &operator-=(const bint rhs) noexcept {
        for(int i=0;i<num;i++){
            if (a[i]<rhs.a[i]) {
                a[i]+=mod[i];
            }
            a[i]-=rhs.a[i];
        }
        return *this;
    }
    bint &operator*=(const bint rhs) noexcept {
        for(int i=0;i<num;i++){
            a[i]=a[i]*rhs.a[i]%mod[i];
        }
        return *this;
    }
    bint &operator/=(bint rhs) noexcept {
        for(int i=0;i<num;i++){
            u64 exp=mod[i]-2;
            while(exp){
                if (exp%2) {
                    (a[i]*=rhs.a[i])%=mod[i];
                }
                (rhs.a[i]*=rhs.a[i])%=mod[i];
                exp/=2;
            }
        }
        return *this;
    }
    bint operator++(int n) const noexcept {
        return bint(*this) +=1;
    }
    bint operator--(int n) const noexcept {
        return bint(*this) -=1;
    }
    u64 garner(const vector<u64>& x, vector<u64> mods, u64 mod){
        using u64 = long long;
        mods.emplace_back(mod);
        vector<u64> coeffs(x.size()+1,1); // coeffs[i]v_i
        vector<u64> constants(x.size()+1,0);
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
        for(int i=0;i<(int)x.size();i++) {
            u64 v=(mods[i]+x[i]-constants[i])%mods[i]*modinv(coeffs[i],mods[i])%mods[i];
            for(int j=i+1;j<(int)x.size()+1;j++) {
                constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
                coeffs[j]=(coeffs[j]*mods[i])%mods[j];
            }
        }
        return constants.back();
    }
};

// class bint{
//     public:
//     constexpr static int mx=36;
//     constexpr static int base=10;
//     int v[mx]={};
//     bint(string s){
//         for(int i=0;i<(int)s.size();i++)v[i]=s[s.size()-i-1]-'0';
//     }
//     bint(long long x=0){
//         int idx=0;
//         while(x){
//             v[idx++]=x%10;
//             x/=10;
//         }
//     }
//     string to_string(){
//         string t;
//         const bint tmp=(v[mx-1]==9)?inv():bint(*this);
//         if(v[mx-1]==9)t="-";
//         bool f=0;
//         for(int i=mx-2;i>=0;i--){
//             if(tmp.v[i])f=1;
//             if(f)t+=(tmp.v[i]+'0');
//         }
//         if(t==""||t=="-")return "0";
//         else return t;
//     }
//     bint operator+(const bint& rhs) const noexcept {
//         return bint(*this) += rhs;
//     }
//     bint operator-(const bint& rhs) const noexcept {
//         return bint(*this) -= rhs;
//     }
//     bint operator-() const noexcept {
//         return bint(*this).inv();
//     }
//     bint operator*(const bint& rhs) const noexcept {
//         return bint(*this) *= rhs;
//     }
//     bint operator/(const bint& rhs) const noexcept {
//         return bint(*this) /= rhs;
//     }
//     bint &operator+=(const bint& t) noexcept {
//         plus(t);
//         return *this;
//     }
//     bint &operator-=(const bint& t) noexcept {
//         plus(t.inv());
//         return *this;
//     }
//     bint &operator*=(const bint& t) noexcept {
//         bint ret;
//         for(int i=0;i<mx;i++)for(int j=0;j<mx-i;j++){
//             ret.v[i+j]+=v[i]*t.v[j];
//         }
//         for(int i=0;i<mx-1;i++){
//             v[i+1]+=v[i]%10;
//             v[i]/=10;
//         }
//         return *this=ret;
//     }
//     bint &operator/=(bint rhs) noexcept {
//         return *this;
//     }
//     bint &operator=(bint rhs) noexcept {
//         memcpy(v,rhs.v,mx*sizeof(int));
//         return *this;
//     }
//     void plus(const bint& t){
//         for(int i=0;i<mx;i++){
//             v[i]+=t.v[i];
//             if(i!=mx-1)v[i+1]+=(v[i]>=10);
//             if(v[i]>=10)v[i]-=10;
//         }
//     }
//     bint inv()const{
//         bint res;
//         bool b=0;
//         for(int i=0;i<mx;i++){
//             if(b){
//                 res.v[i]=9-v[i];
//             }else{
//                 if(v[i]){
//                     b=1;
//                     res.v[i]=10-v[i];
//                 }else{
//                     res.v[i]=0;
//                 }
//             }
//         }
//         return res;
//     }
// };