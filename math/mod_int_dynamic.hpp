#pragma once
#include<cstdint>
#include<iostream>
#include<vector>

/**
 * @brief ModInt
 */

struct mod_int_dynamic{
    using mint=mod_int_dynamic;
    using u64 = std::uint_fast64_t;
    u64 a;
    mod_int_dynamic(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
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
    mint operator++(int) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    mint operator--(int) noexcept {
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
    bool operator<(mint x) noexcept {
        return a<x.a;
    }
    bool operator>(mint x) noexcept {
        return a>x.a;
    }
    bool operator<=(mint x) noexcept {
        return a<=x.a;
    }
    bool operator>=(mint x) noexcept {
        return a>=x.a;
    }
    static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1).a==1)root++;
        return root.a;
    }
    mint pow(long long n)const{
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
    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend std::istream& operator>>(std::istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    constexpr static bool is_static=false;
    static int MOD;
    static u64 get_mod(){
        return MOD;
    }
    static void set_mod(int mod){
        MOD=mod;
    }
};
int mod_int_dynamic::MOD=-1;