---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/kth_root.hpp
    title: math/kth_root.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ModInt
    links: []
  bundledCode: "#line 2 \"math/mod_int_dynamic.hpp\"\n#include<cstdint>\n#include<iostream>\n\
    #include<vector>\n\n/**\n * @brief ModInt\n */\n\nstruct mod_int_dynamic{\n  \
    \  using mint=mod_int_dynamic;\n    using u64 = std::uint_fast64_t;\n    u64 a;\n\
    \    mod_int_dynamic(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n\
    \    u64 &value()noexcept{return a;}\n    const u64 &value() const noexcept {return\
    \ a;}\n    mint operator+(const mint rhs)const noexcept{return mint(*this) +=\
    \ rhs;}\n    mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}\n\
    \    mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}\n\
    \    mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}\n\
    \    mint &operator+=(const mint rhs) noexcept {\n        a += rhs.a;\n      \
    \  if (a >= get_mod())a -= get_mod();\n        return *this;\n    }\n    mint\
    \ &operator-=(const mint rhs) noexcept {\n        if (a<rhs.a)a += get_mod();\n\
    \        a -= rhs.a;\n        return *this;\n    }\n    mint &operator*=(const\
    \ mint rhs) noexcept {\n        a = a * rhs.a % get_mod();\n        return *this;\n\
    \    }\n    mint operator++(int) noexcept {\n        a += 1;\n        if (a >=\
    \ get_mod())a -= get_mod();\n        return *this;\n    }\n    mint operator--(int)\
    \ noexcept {\n        if (a<1)a += get_mod();\n        a -= 1;\n        return\
    \ *this;\n    }\n    mint &operator/=(mint rhs) noexcept {\n        u64 exp=get_mod()-2;\n\
    \        while (exp) {\n            if (exp % 2) {\n                *this *= rhs;\n\
    \            }\n            rhs *= rhs;\n            exp /= 2;\n        }\n  \
    \      return *this;\n    }\n    bool operator==(mint x) noexcept {\n        return\
    \ a==x.a;\n    }\n    bool operator!=(mint x) noexcept {\n        return a!=x.a;\n\
    \    }\n    bool operator<(mint x) noexcept {\n        return a<x.a;\n    }\n\
    \    bool operator>(mint x) noexcept {\n        return a>x.a;\n    }\n    bool\
    \ operator<=(mint x) noexcept {\n        return a<=x.a;\n    }\n    bool operator>=(mint\
    \ x) noexcept {\n        return a>=x.a;\n    }\n    static int root(){\n     \
    \   mint root = 2;\n        while(root.pow((get_mod()-1)>>1).a==1)root++;\n  \
    \      return root.a;\n    }\n    mint pow(long long n)const{\n        long long\
    \ x=a;\n        mint ret = 1;\n        while(n>0) {\n            if(n&1)(ret*=x);\n\
    \            (x*=x)%=get_mod();\n            n>>=1;\n        }\n        return\
    \ ret;\n    }\n    mint inv(){\n        return pow(get_mod()-2);\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {\n  \
    \      lhs << rhs.a;\n        return lhs;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n        return lhs;\n    }\n\
    \    constexpr static bool is_static=false;\n    static int MOD;\n    static u64\
    \ get_mod(){\n        return MOD;\n    }\n    static void set_mod(int mod){\n\
    \        MOD=mod;\n    }\n};\nint mod_int_dynamic::MOD=-1;\n"
  code: "#pragma once\n#include<cstdint>\n#include<iostream>\n#include<vector>\n\n\
    /**\n * @brief ModInt\n */\n\nstruct mod_int_dynamic{\n    using mint=mod_int_dynamic;\n\
    \    using u64 = std::uint_fast64_t;\n    u64 a;\n    mod_int_dynamic(const long\
    \ long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n    u64\
    \ &value()noexcept{return a;}\n    const u64 &value() const noexcept {return a;}\n\
    \    mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}\n\
    \    mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}\n\
    \    mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}\n\
    \    mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}\n\
    \    mint &operator+=(const mint rhs) noexcept {\n        a += rhs.a;\n      \
    \  if (a >= get_mod())a -= get_mod();\n        return *this;\n    }\n    mint\
    \ &operator-=(const mint rhs) noexcept {\n        if (a<rhs.a)a += get_mod();\n\
    \        a -= rhs.a;\n        return *this;\n    }\n    mint &operator*=(const\
    \ mint rhs) noexcept {\n        a = a * rhs.a % get_mod();\n        return *this;\n\
    \    }\n    mint operator++(int) noexcept {\n        a += 1;\n        if (a >=\
    \ get_mod())a -= get_mod();\n        return *this;\n    }\n    mint operator--(int)\
    \ noexcept {\n        if (a<1)a += get_mod();\n        a -= 1;\n        return\
    \ *this;\n    }\n    mint &operator/=(mint rhs) noexcept {\n        u64 exp=get_mod()-2;\n\
    \        while (exp) {\n            if (exp % 2) {\n                *this *= rhs;\n\
    \            }\n            rhs *= rhs;\n            exp /= 2;\n        }\n  \
    \      return *this;\n    }\n    bool operator==(mint x) noexcept {\n        return\
    \ a==x.a;\n    }\n    bool operator!=(mint x) noexcept {\n        return a!=x.a;\n\
    \    }\n    bool operator<(mint x) noexcept {\n        return a<x.a;\n    }\n\
    \    bool operator>(mint x) noexcept {\n        return a>x.a;\n    }\n    bool\
    \ operator<=(mint x) noexcept {\n        return a<=x.a;\n    }\n    bool operator>=(mint\
    \ x) noexcept {\n        return a>=x.a;\n    }\n    static int root(){\n     \
    \   mint root = 2;\n        while(root.pow((get_mod()-1)>>1).a==1)root++;\n  \
    \      return root.a;\n    }\n    mint pow(long long n)const{\n        long long\
    \ x=a;\n        mint ret = 1;\n        while(n>0) {\n            if(n&1)(ret*=x);\n\
    \            (x*=x)%=get_mod();\n            n>>=1;\n        }\n        return\
    \ ret;\n    }\n    mint inv(){\n        return pow(get_mod()-2);\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {\n  \
    \      lhs << rhs.a;\n        return lhs;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n        return lhs;\n    }\n\
    \    constexpr static bool is_static=false;\n    static int MOD;\n    static u64\
    \ get_mod(){\n        return MOD;\n    }\n    static void set_mod(int mod){\n\
    \        MOD=mod;\n    }\n};\nint mod_int_dynamic::MOD=-1;"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_int_dynamic.hpp
  requiredBy:
  - math/kth_root.hpp
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_int_dynamic.hpp
layout: document
redirect_from:
- /library/math/mod_int_dynamic.hpp
- /library/math/mod_int_dynamic.hpp.html
title: ModInt
---
