---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/LC_mod_log.test.cpp
    title: math/test/LC_mod_log.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u96E2\u6563\u5BFE\u6570(ModLog)"
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\n/**\n * @brief (x^y)%mod\n */\n\nlong\
    \ long mod_pow(long long x,long long y,long long mod){\n    long long ret=1;\n\
    \    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n        (x*=x)%=mod;\n     \
    \   y>>=1;\n    }\n    return ret;\n}\n#line 1 \"math/euler_phi.hpp\"\n/**\n *\
    \ @brief \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\n */\n\n\
    long long euler_phi(long long n) {\n    long long ret = n;\n    for(long long\
    \ i=2;i*i<=n;i++) {\n        if(n%i==0) {\n            ret-=ret/i;\n         \
    \   while(n%i==0)n/=i;\n        }\n    }\n    if(n>1)ret-=ret/n;\n    return ret;\n\
    }\n#line 4 \"math/mod_log.hpp\"\n#include<map>\n#include<numeric>\n#include<cmath>\n\
    \n/**\n * @brief \u96E2\u6563\u5BFE\u6570(ModLog)\n */\n\nlong long mod_log(long\
    \ long x,long long y,long long m){\n    if(1==y||(x==0&&y==0&&m==1))return 0;\n\
    \    if(x==0){\n        if(y==1)return 0;\n        if(y==0)return 1;\n       \
    \ else return -1;\n    }\n    long long _x=x,_y=y;\n    long long g=m;\n    long\
    \ long cnt=0;\n    while(std::gcd(x,m)!=1)m/=std::gcd(x,m),cnt++;\n    g/=m;\n\
    \    x%=m;\n    y%=m;\n    std::map<long long,long long>b;\n    long long B=std::sqrt(m*g)+1;\n\
    \    long long phi=euler_phi(m);\n    long long a=mod_pow(x,B-1,m);\n    long\
    \ long inv_x=mod_pow(x,phi-1,m);\n    for(long long i=B-1;i>=cnt;--i){\n     \
    \   b[a]=i;\n        a=a*inv_x%m;\n    }\n    long long A=mod_pow(x,B*(phi-1),m);\n\
    \    long long A2=y;\n    for(long long i=0;i<B;++i){\n        for(long long j=0;j<cnt;++j)if(mod_pow(_x,i*B+j,m*g)==_y)return\
    \ i*B+j;\n        if(b.count(A2)){\n            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return\
    \ i*B+b[A2];\n        }\n        A2=A2*A%m;\n    }\n    return -1;\n}\n"
  code: "#pragma once\n#include\"mod_pow.hpp\"\n#include\"euler_phi.hpp\"\n#include<map>\n\
    #include<numeric>\n#include<cmath>\n\n/**\n * @brief \u96E2\u6563\u5BFE\u6570\
    (ModLog)\n */\n\nlong long mod_log(long long x,long long y,long long m){\n   \
    \ if(1==y||(x==0&&y==0&&m==1))return 0;\n    if(x==0){\n        if(y==1)return\
    \ 0;\n        if(y==0)return 1;\n        else return -1;\n    }\n    long long\
    \ _x=x,_y=y;\n    long long g=m;\n    long long cnt=0;\n    while(std::gcd(x,m)!=1)m/=std::gcd(x,m),cnt++;\n\
    \    g/=m;\n    x%=m;\n    y%=m;\n    std::map<long long,long long>b;\n    long\
    \ long B=std::sqrt(m*g)+1;\n    long long phi=euler_phi(m);\n    long long a=mod_pow(x,B-1,m);\n\
    \    long long inv_x=mod_pow(x,phi-1,m);\n    for(long long i=B-1;i>=cnt;--i){\n\
    \        b[a]=i;\n        a=a*inv_x%m;\n    }\n    long long A=mod_pow(x,B*(phi-1),m);\n\
    \    long long A2=y;\n    for(long long i=0;i<B;++i){\n        for(long long j=0;j<cnt;++j)if(mod_pow(_x,i*B+j,m*g)==_y)return\
    \ i*B+j;\n        if(b.count(A2)){\n            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return\
    \ i*B+b[A2];\n        }\n        A2=A2*A%m;\n    }\n    return -1;\n}"
  dependsOn:
  - math/mod_pow.hpp
  - math/euler_phi.hpp
  isVerificationFile: false
  path: math/mod_log.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/LC_mod_log.test.cpp
documentation_of: math/mod_log.hpp
layout: document
redirect_from:
- /library/math/mod_log.hpp
- /library/math/mod_log.hpp.html
title: "\u96E2\u6563\u5BFE\u6570(ModLog)"
---
