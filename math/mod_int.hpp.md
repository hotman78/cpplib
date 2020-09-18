---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/mod_int998244353.hpp
    title: ModInt(998'244'353)
  - icon: ':heavy_check_mark:'
    path: math/mod_int1000000007.hpp
    title: ModInt(1'000'000'007)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/LC_convolution_1000000007.test.cpp
    title: convolution/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/LC_convolution_998244353.test.cpp
    title: convolution/test/LC_convolution_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_totient_sum.test.cpp
    title: math/test/LC_totient_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_swag.test.cpp
    title: data_structure/test/LC_swag.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: ModInt
    links: []
  bundledCode: "#line 2 \"math/mod_int.hpp\"\n#include<cstdint>\n#include<iostream>\n\
    #include<vector>\n\n/**\n * @brief ModInt\n */\n\ntemplate<int MOD>\nstruct mod_int\
    \ {\n    using mint=mod_int<MOD>;\n    using u64 = std::uint_fast64_t;\n    u64\
    \ a;\n    constexpr mod_int(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n\
    \    constexpr u64 &value()noexcept{return a;}\n    constexpr const u64 &value()\
    \ const noexcept {return a;}\n    constexpr mint operator+(const mint rhs)const\
    \ noexcept{return mint(*this) += rhs;}\n    constexpr mint operator-(const mint\
    \ rhs)const noexcept{return mint(*this)-=rhs;}\n    constexpr mint operator*(const\
    \ mint rhs) const noexcept {return mint(*this) *= rhs;}\n    constexpr mint operator/(const\
    \ mint rhs) const noexcept {return mint(*this) /= rhs;}\n    constexpr mint &operator+=(const\
    \ mint rhs) noexcept {\n        a += rhs.a;\n        if (a >= get_mod())a -= get_mod();\n\
    \        return *this;\n    }\n    constexpr mint &operator-=(const mint rhs)\
    \ noexcept {\n        if (a<rhs.a)a += get_mod();\n        a -= rhs.a;\n     \
    \   return *this;\n    }\n    constexpr mint &operator*=(const mint rhs) noexcept\
    \ {\n        a = a * rhs.a % get_mod();\n        return *this;\n    }\n    constexpr\
    \ mint operator++(int) noexcept {\n        a += 1;\n        if (a >= get_mod())a\
    \ -= get_mod();\n        return *this;\n    }\n    constexpr mint operator--(int)\
    \ noexcept {\n        if (a<1)a += get_mod();\n        a -= 1;\n        return\
    \ *this;\n    }\n    constexpr mint &operator/=(mint rhs) noexcept {\n       \
    \ u64 exp=get_mod()-2;\n        while (exp) {\n            if (exp % 2) {\n  \
    \              *this *= rhs;\n            }\n            rhs *= rhs;\n       \
    \     exp /= 2;\n        }\n        return *this;\n    }\n    constexpr bool operator==(mint\
    \ x) noexcept {\n        return a==x.a;\n    }\n    constexpr bool operator!=(mint\
    \ x) noexcept {\n        return a!=x.a;\n    }\n    constexpr bool operator<(mint\
    \ x) noexcept {\n        return a<x.a;\n    }\n    constexpr bool operator>(mint\
    \ x) noexcept {\n        return a>x.a;\n    }\n    constexpr bool operator<=(mint\
    \ x) noexcept {\n        return a<=x.a;\n    }\n    constexpr bool operator>=(mint\
    \ x) noexcept {\n        return a>=x.a;\n    }\n    constexpr static int root(){\n\
    \        mint root = 2;\n        while(root.pow((get_mod()-1)>>1).a==1)root++;\n\
    \        return root.a;\n    }\n    constexpr mint pow(long long n){\n       \
    \ long long x=a;\n        mint ret = 1;\n        while(n>0) {\n            if(n&1)(ret*=x);\n\
    \            (x*=x)%=get_mod();\n            n>>=1;\n        }\n        return\
    \ ret;\n    }\n    constexpr mint inv(){\n        return pow(get_mod()-2);\n \
    \   }\n    static std::vector<mint> fac;\n    static std::vector<mint> ifac;\n\
    \    static bool init;\n    constexpr static int mx=10000001;\n    void build(){\n\
    \        init=0;\n        fac.resize(mx);\n        ifac.resize(mx);\n        fac[0]=1,ifac[0]=1;\n\
    \        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;\n        ifac[mx-1]=fac[mx-1].inv();\n\
    \        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);\n    }\n    mint comb(long\
    \ long b){\n        if(init)build();\n        if(a==0&&b==0)return 1;\n      \
    \  if((long long)a<b)return 0;\n        return fac[a]*ifac[a-b]*ifac[b];\n   \
    \ }\n    mint fact(){\n        if(init)build();\n        return fac[a];\n    }\n\
    \    mint fact_inv(){\n        if(init)build();\n        return ifac[a];\n   \
    \ }\n    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept\
    \ {\n        lhs << rhs.a;\n        return lhs;\n    }\n    friend std::istream&\
    \ operator>>(std::istream& lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n\
    \        return lhs;\n    }\n    constexpr static u64 get_mod(){\n        return\
    \ MOD;\n    }\n};\ntemplate<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;\n\
    template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;\ntemplate<int MOD>bool\
    \ mod_int<MOD>::init=1;\n"
  code: "#pragma once\n#include<cstdint>\n#include<iostream>\n#include<vector>\n\n\
    /**\n * @brief ModInt\n */\n\ntemplate<int MOD>\nstruct mod_int {\n    using mint=mod_int<MOD>;\n\
    \    using u64 = std::uint_fast64_t;\n    u64 a;\n    constexpr mod_int(const\
    \ long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n  \
    \  constexpr u64 &value()noexcept{return a;}\n    constexpr const u64 &value()\
    \ const noexcept {return a;}\n    constexpr mint operator+(const mint rhs)const\
    \ noexcept{return mint(*this) += rhs;}\n    constexpr mint operator-(const mint\
    \ rhs)const noexcept{return mint(*this)-=rhs;}\n    constexpr mint operator*(const\
    \ mint rhs) const noexcept {return mint(*this) *= rhs;}\n    constexpr mint operator/(const\
    \ mint rhs) const noexcept {return mint(*this) /= rhs;}\n    constexpr mint &operator+=(const\
    \ mint rhs) noexcept {\n        a += rhs.a;\n        if (a >= get_mod())a -= get_mod();\n\
    \        return *this;\n    }\n    constexpr mint &operator-=(const mint rhs)\
    \ noexcept {\n        if (a<rhs.a)a += get_mod();\n        a -= rhs.a;\n     \
    \   return *this;\n    }\n    constexpr mint &operator*=(const mint rhs) noexcept\
    \ {\n        a = a * rhs.a % get_mod();\n        return *this;\n    }\n    constexpr\
    \ mint operator++(int) noexcept {\n        a += 1;\n        if (a >= get_mod())a\
    \ -= get_mod();\n        return *this;\n    }\n    constexpr mint operator--(int)\
    \ noexcept {\n        if (a<1)a += get_mod();\n        a -= 1;\n        return\
    \ *this;\n    }\n    constexpr mint &operator/=(mint rhs) noexcept {\n       \
    \ u64 exp=get_mod()-2;\n        while (exp) {\n            if (exp % 2) {\n  \
    \              *this *= rhs;\n            }\n            rhs *= rhs;\n       \
    \     exp /= 2;\n        }\n        return *this;\n    }\n    constexpr bool operator==(mint\
    \ x) noexcept {\n        return a==x.a;\n    }\n    constexpr bool operator!=(mint\
    \ x) noexcept {\n        return a!=x.a;\n    }\n    constexpr bool operator<(mint\
    \ x) noexcept {\n        return a<x.a;\n    }\n    constexpr bool operator>(mint\
    \ x) noexcept {\n        return a>x.a;\n    }\n    constexpr bool operator<=(mint\
    \ x) noexcept {\n        return a<=x.a;\n    }\n    constexpr bool operator>=(mint\
    \ x) noexcept {\n        return a>=x.a;\n    }\n    constexpr static int root(){\n\
    \        mint root = 2;\n        while(root.pow((get_mod()-1)>>1).a==1)root++;\n\
    \        return root.a;\n    }\n    constexpr mint pow(long long n){\n       \
    \ long long x=a;\n        mint ret = 1;\n        while(n>0) {\n            if(n&1)(ret*=x);\n\
    \            (x*=x)%=get_mod();\n            n>>=1;\n        }\n        return\
    \ ret;\n    }\n    constexpr mint inv(){\n        return pow(get_mod()-2);\n \
    \   }\n    static std::vector<mint> fac;\n    static std::vector<mint> ifac;\n\
    \    static bool init;\n    constexpr static int mx=10000001;\n    void build(){\n\
    \        init=0;\n        fac.resize(mx);\n        ifac.resize(mx);\n        fac[0]=1,ifac[0]=1;\n\
    \        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;\n        ifac[mx-1]=fac[mx-1].inv();\n\
    \        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);\n    }\n    mint comb(long\
    \ long b){\n        if(init)build();\n        if(a==0&&b==0)return 1;\n      \
    \  if((long long)a<b)return 0;\n        return fac[a]*ifac[a-b]*ifac[b];\n   \
    \ }\n    mint fact(){\n        if(init)build();\n        return fac[a];\n    }\n\
    \    mint fact_inv(){\n        if(init)build();\n        return ifac[a];\n   \
    \ }\n    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept\
    \ {\n        lhs << rhs.a;\n        return lhs;\n    }\n    friend std::istream&\
    \ operator>>(std::istream& lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n\
    \        return lhs;\n    }\n    constexpr static u64 get_mod(){\n        return\
    \ MOD;\n    }\n};\ntemplate<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;\n\
    template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;\ntemplate<int MOD>bool\
    \ mod_int<MOD>::init=1;"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_int.hpp
  requiredBy:
  - math/mod_int998244353.hpp
  - math/mod_int1000000007.hpp
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/LC_convolution_1000000007.test.cpp
  - convolution/test/LC_convolution_998244353.test.cpp
  - math/test/LC_totient_sum.test.cpp
  - data_structure/test/LC_swag.test.cpp
documentation_of: math/mod_int.hpp
layout: document
redirect_from:
- /library/math/mod_int.hpp
- /library/math/mod_int.hpp.html
title: ModInt
---
