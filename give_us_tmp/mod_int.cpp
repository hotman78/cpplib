/**
 * modint
 * 
 * 割り算やpowに関する物はO(log(mod))
 * それ以外はO(1)
 * 入出力可能
 * 
 */

template<uint mod>
struct modint{
    using M=modint;
    uint a;
    modint(ll x=0){set(x%mod+mod);}
    M& set(uint x){
        a = x<mod ? x : x-mod;
        return *this;
    }
    M operator-()const{return M()-*this;}
    M operator+(const M& x)const{return M().set(a+x.a);}
    M operator-(const M& x)const{return M().set(a-x.a+mod);}
    M operator*(const M& x)const{return M().set(ull(a)*x.a%mod);}
    M operator/(const M& x)const{return *this*x.inv();}
    M& operator+=(const M& x){return *this=*this+x;}
    M& operator-=(const M& x){return *this=*this-x;}
    M& operator*=(const M& x){return *this=*this*x;}
    M& operator/=(const M& x){return *this=*this/x;}
    bool operator==(const M& x)const{return a==x.a;}
    bool operator<(const M& x)const{return a<x.a;}
    M pow(ll n)const{
        M x=*this,r=1;
        while(n){
            if(n&1)r*=x;
            x*=x;
            n>>=1;
        }
        return r;
    }
    M inv()const{return pow(mod-2);}
    friend ostream& operator<<(ostream& os, const M& x){os<<x.a;return os;}
    friend istream& operator>>(istream& is,M& x){is>>x.a;return is;}
};

/**
 * combination
 * 
 * 前計算 :O(mx+log(mod))
 * 実行   :O(1)
 * Comb(n,k)        :n個からk個選ぶ
 * Comb::perm(n,k)  :n個から選ぶ順番を区別してk個選ぶ
 * Comb::fact(n)    :n!
 * Comb::ifact(n)   :1/n!
 * Comb::homo(n,k)  :n個から重複ありでk個選ぶ
 * 
 */

template<typename M>
struct Comb{
    static constexpr int mx=1'000'000;
    M fac[mx],ifac[mx];
    Comb(){
        fac[0]=1;
        for(int i=1;i<mx;++i){
            fac[i]=fac[i-1]*i;
        }
        ifac[mx-1]=fac[mx-1].inv();
        for(int i=mx-1;i>0;--i){
            ifac[i-1]=ifac[i]*i;
        }
    }
    M operator()(int n,int k){
        return fac[n]*ifac[k]*ifac[n-k];
    }
    M fact(int n){
        return fac[n];
    }
    M ifact(int n){
        return ifac[n];
    }
    M perm(int n,int k){
        return fac[n]*ifac[n-k];
    }
    M homo(int n,int k){
        return (*this)(n+k-1,k);
    }
};
using mint=modint<1000000007>;
Comb<mint>comb;