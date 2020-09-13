#pragma once
#include<cstdint>
#include<iostream>
#include<vector>

template<int MOD>
struct mod_int {
    using mint=mod_int<MOD>;
    using u64 = std::uint_fast64_t;
    u64 a;
    constexpr mod_int(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
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
        a = a * rhs.a % get_mod();
        return *this;
    }
    constexpr mint operator++(int) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint operator--(int) noexcept {
        if (a<1)a += get_mod();
        a -= 1;
        return *this;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
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
    constexpr static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1).a==1)root++;
        return root.a;
    }
    constexpr mint pow(long long n){
        long long x=a;
        mint ret = 1;
        while(n>0) {
            if(n&1)(ret*=x);
            (x*=x)%=get_mod();
            n>>=1;
        }
        return ret;
    }
    constexpr mint inv(){
        return pow(get_mod()-2);
    }
    static std::vector<mint> fac;
    static std::vector<mint> ifac;
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
    mint comb(long long b){
        if(init)build();
        if(a==0&&b==0)return 1;
        if((long long)a<b)return 0;
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
    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend std::istream& operator>>(std::istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    constexpr static u64 get_mod(){
        return MOD;
    }
};
template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;
template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;
template<int MOD>bool mod_int<MOD>::init=1;