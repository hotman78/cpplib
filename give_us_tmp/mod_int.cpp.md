---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"give_us_tmp/mod_int.cpp\"\n/**\n * modint\n * \n * \u5272\
    \u308A\u7B97\u3084pow\u306B\u95A2\u3059\u308B\u7269\u306FO(log(mod))\n * \u305D\
    \u308C\u4EE5\u5916\u306FO(1)\n * \u5165\u51FA\u529B\u53EF\u80FD\n * \n */\n\n\
    template<uint mod>\nstruct modint{\n    using M=modint;\n    uint a;\n    modint(ll\
    \ x=0){set(x%mod+mod);}\n    M& set(uint x){\n        a = x<mod ? x : x-mod;\n\
    \        return *this;\n    }\n    M operator-()const{return M()-*this;}\n   \
    \ M operator+(const M& x)const{return M().set(a+x.a);}\n    M operator-(const\
    \ M& x)const{return M().set(a-x.a+mod);}\n    M operator*(const M& x)const{return\
    \ M().set(ull(a)*x.a%mod);}\n    M operator/(const M& x)const{return *this*x.inv();}\n\
    \    M& operator+=(const M& x){return *this=*this+x;}\n    M& operator-=(const\
    \ M& x){return *this=*this-x;}\n    M& operator*=(const M& x){return *this=*this*x;}\n\
    \    M& operator/=(const M& x){return *this=*this/x;}\n    bool operator==(const\
    \ M& x)const{return a==x.a;}\n    bool operator<(const M& x)const{return a<x.a;}\n\
    \    M pow(ll n)const{\n        M x=*this,r=1;\n        while(n){\n          \
    \  if(n&1)r*=x;\n            x*=x;\n            n>>=1;\n        }\n        return\
    \ r;\n    }\n    M inv()const{return pow(mod-2);}\n    friend ostream& operator<<(ostream&\
    \ os, const M& x){os<<x.a;return os;}\n    friend istream& operator>>(istream&\
    \ is,M& x){is>>x.a;return is;}\n};\n\n/**\n * combination\n * \n * \u524D\u8A08\
    \u7B97 :O(mx+log(mod))\n * \u5B9F\u884C   :O(1)\n * Comb(n,k)        :n\u500B\u304B\
    \u3089k\u500B\u9078\u3076\n * Comb::perm(n,k)  :n\u500B\u304B\u3089\u9078\u3076\
    \u9806\u756A\u3092\u533A\u5225\u3057\u3066k\u500B\u9078\u3076\n * Comb::fact(n)\
    \    :n!\n * Comb::ifact(n)   :1/n!\n * Comb::homo(n,k)  :n\u500B\u304B\u3089\u91CD\
    \u8907\u3042\u308A\u3067k\u500B\u9078\u3076\n * \n */\n\ntemplate<typename M>\n\
    struct Comb{\n    static constexpr int mx=1'000'000;\n    M fac[mx],ifac[mx];\n\
    \    Comb(){\n        fac[0]=1;\n        for(int i=1;i<mx;++i){\n            fac[i]=fac[i-1]*i;\n\
    \        }\n        ifac[mx-1]=fac[mx-1].inv();\n        for(int i=mx-1;i>0;--i){\n\
    \            ifac[i-1]=ifac[i]*i;\n        }\n    }\n    M operator()(int n,int\
    \ k){\n        return fac[n]*ifac[k]*ifac[n-k];\n    }\n    M fact(int n){\n \
    \       return fac[n];\n    }\n    M ifact(int n){\n        return ifac[n];\n\
    \    }\n    M perm(int n,int k){\n        return fac[n]*ifac[n-k];\n    }\n  \
    \  M homo(int n,int k){\n        return (*this)(n+k-1,k);\n    }\n};\nusing mint=modint<1000000007>;\n\
    Comb<mint>comb;\n"
  code: "/**\n * modint\n * \n * \u5272\u308A\u7B97\u3084pow\u306B\u95A2\u3059\u308B\
    \u7269\u306FO(log(mod))\n * \u305D\u308C\u4EE5\u5916\u306FO(1)\n * \u5165\u51FA\
    \u529B\u53EF\u80FD\n * \n */\n\ntemplate<uint mod>\nstruct modint{\n    using\
    \ M=modint;\n    uint a;\n    modint(ll x=0){set(x%mod+mod);}\n    M& set(uint\
    \ x){\n        a = x<mod ? x : x-mod;\n        return *this;\n    }\n    M operator-()const{return\
    \ M()-*this;}\n    M operator+(const M& x)const{return M().set(a+x.a);}\n    M\
    \ operator-(const M& x)const{return M().set(a-x.a+mod);}\n    M operator*(const\
    \ M& x)const{return M().set(ull(a)*x.a%mod);}\n    M operator/(const M& x)const{return\
    \ *this*x.inv();}\n    M& operator+=(const M& x){return *this=*this+x;}\n    M&\
    \ operator-=(const M& x){return *this=*this-x;}\n    M& operator*=(const M& x){return\
    \ *this=*this*x;}\n    M& operator/=(const M& x){return *this=*this/x;}\n    bool\
    \ operator==(const M& x)const{return a==x.a;}\n    bool operator<(const M& x)const{return\
    \ a<x.a;}\n    M pow(ll n)const{\n        M x=*this,r=1;\n        while(n){\n\
    \            if(n&1)r*=x;\n            x*=x;\n            n>>=1;\n        }\n\
    \        return r;\n    }\n    M inv()const{return pow(mod-2);}\n    friend ostream&\
    \ operator<<(ostream& os, const M& x){os<<x.a;return os;}\n    friend istream&\
    \ operator>>(istream& is,M& x){is>>x.a;return is;}\n};\n\n/**\n * combination\n\
    \ * \n * \u524D\u8A08\u7B97 :O(mx+log(mod))\n * \u5B9F\u884C   :O(1)\n * Comb(n,k)\
    \        :n\u500B\u304B\u3089k\u500B\u9078\u3076\n * Comb::perm(n,k)  :n\u500B\
    \u304B\u3089\u9078\u3076\u9806\u756A\u3092\u533A\u5225\u3057\u3066k\u500B\u9078\
    \u3076\n * Comb::fact(n)    :n!\n * Comb::ifact(n)   :1/n!\n * Comb::homo(n,k)\
    \  :n\u500B\u304B\u3089\u91CD\u8907\u3042\u308A\u3067k\u500B\u9078\u3076\n * \n\
    \ */\n\ntemplate<typename M>\nstruct Comb{\n    static constexpr int mx=1'000'000;\n\
    \    M fac[mx],ifac[mx];\n    Comb(){\n        fac[0]=1;\n        for(int i=1;i<mx;++i){\n\
    \            fac[i]=fac[i-1]*i;\n        }\n        ifac[mx-1]=fac[mx-1].inv();\n\
    \        for(int i=mx-1;i>0;--i){\n            ifac[i-1]=ifac[i]*i;\n        }\n\
    \    }\n    M operator()(int n,int k){\n        return fac[n]*ifac[k]*ifac[n-k];\n\
    \    }\n    M fact(int n){\n        return fac[n];\n    }\n    M ifact(int n){\n\
    \        return ifac[n];\n    }\n    M perm(int n,int k){\n        return fac[n]*ifac[n-k];\n\
    \    }\n    M homo(int n,int k){\n        return (*this)(n+k-1,k);\n    }\n};\n\
    using mint=modint<1000000007>;\nComb<mint>comb;"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/mod_int.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/mod_int.cpp
layout: document
redirect_from:
- /library/give_us_tmp/mod_int.cpp
- /library/give_us_tmp/mod_int.cpp.html
title: give_us_tmp/mod_int.cpp
---
