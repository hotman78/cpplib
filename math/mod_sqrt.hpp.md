---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  - icon: ':x:'
    path: util/random_gen.hpp
    title: util/random_gen.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: math/test/LC_mod_sqrt.test.cpp
    title: math/test/LC_mod_sqrt.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: ModSqrt
    links: []
  bundledCode: "#line 1 \"math/mod_sqrt.hpp\"\n#include<tuple>\n#line 1 \"math/mod_pow.hpp\"\
    \n/**\n * @brief (x^y)%mod\n */\n\nlong long mod_pow(long long x,long long y,long\
    \ long mod){\n    long long ret=1;\n    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n\
    \        (x*=x)%=mod;\n        y>>=1;\n    }\n    return ret;\n}\n#line 2 \"util/random_gen.hpp\"\
    \n#include<random>\n#include<chrono>\n\nstruct RandomNumberGenerator {\n    std::mt19937\
    \ mt;\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    int operator()(int a, int b) { // [a, b)\n        std::uniform_int_distribution<\
    \ int > dist(a, b - 1);\n        return dist(mt);\n    }\n\n    int operator()(int\
    \ b) { // [0, b)\n        return (*this)(0, b);\n    }\n};\n#line 4 \"math/mod_sqrt.hpp\"\
    \n\n/**\n * @brief ModSqrt\n */\n\nlong long mod_sqrt(long long a,long long mod){\n\
    \    if(mod==2||a==0)return a;\n    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;\n\
    \    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);\n    long long q=(mod-1),s=0;\n\
    \    while(q%2==0)q/=2,s++;\n    long long z=1;\n    RandomNumberGenerator rnd;\n\
    \    while(mod_pow(z=rnd(0,mod),(mod-1)/2,mod)!=mod-1);\n    long long c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;\n\
    \    while(m>1){\n        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;\n   \
    \     else std::tie(c,t,r,m)=std::make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);\n\
    \    }\n    return r%mod;\n}\n"
  code: "#include<tuple>\n#include\"mod_pow.hpp\"\n#include\"../util/random_gen.hpp\"\
    \n\n/**\n * @brief ModSqrt\n */\n\nlong long mod_sqrt(long long a,long long mod){\n\
    \    if(mod==2||a==0)return a;\n    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;\n\
    \    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);\n    long long q=(mod-1),s=0;\n\
    \    while(q%2==0)q/=2,s++;\n    long long z=1;\n    RandomNumberGenerator rnd;\n\
    \    while(mod_pow(z=rnd(0,mod),(mod-1)/2,mod)!=mod-1);\n    long long c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;\n\
    \    while(m>1){\n        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;\n   \
    \     else std::tie(c,t,r,m)=std::make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);\n\
    \    }\n    return r%mod;\n}"
  dependsOn:
  - math/mod_pow.hpp
  - util/random_gen.hpp
  isVerificationFile: false
  path: math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:33:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - math/test/LC_mod_sqrt.test.cpp
documentation_of: math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/math/mod_sqrt.hpp
- /library/math/mod_sqrt.hpp.html
title: ModSqrt
---
