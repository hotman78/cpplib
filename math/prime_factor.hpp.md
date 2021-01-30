---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/fact_list.hpp
    title: math/fact_list.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/AOJ_prime_factor.test.cpp
    title: math/test/AOJ_prime_factor.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_prime_factor.test.cpp
    title: math/test/LC_prime_factor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)"
    links: []
  bundledCode: "#line 2 \"math/prime_factor.hpp\"\n#include<vector>\n#include<numeric>\n\
    #include<cmath>\n#include<algorithm>\n#include<map>\n#line 2 \"math/is_prime.hpp\"\
    \n#include <initializer_list>\n/**\n * @brief \u7D20\u6570\u5224\u5B9A(\u9AD8\u901F\
    )\n */\nbool is_prime(long long n){\n    if(n<=1)return 0;\n    if(n==2)return\
    \ 1;\n    if(n%2==0)return 0;\n    long long s=0,d=n-1;\n    while(d%2)d/=2,s++;\n\
    \    auto mod_pow=[](__int128_t a,__int128_t b,__int128_t n){\n        long long\
    \ res=1;\n        while(b){\n            if(b%2)res=res*a%n;\n            a=a*a%n;\n\
    \            b/=2;\n        }\n        return (long long)(res);\n    };\n    for(long\
    \ long e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n        if(n<=e)break;\n       \
    \ if(mod_pow(e,d,n)==1)continue;\n        bool b=1;\n        for(int i=0;i<s;i++){\n\
    \            if(mod_pow(e,d<<i,n)==n-1)b=0;\n        }\n        if(b)return 0;\n\
    \    }\n    return 1;\n}\n#line 8 \"math/prime_factor.hpp\"\n\n/**\n * @brief\
    \ \u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)\n */\n\nvoid __prime_factor(long\
    \ long n,long long& c,std::vector<long long>& v){\n    if(n==1)return;\n    if(n%2==0){\n\
    \        v.emplace_back(2);\n        __prime_factor(n/2,c,v);\n        return;\n\
    \    }\n    if(is_prime(n)){\n        v.emplace_back(n);\n        return;\n  \
    \  }\n    while(1){\n        long long x=2,y=2,d=1;\n        while(d==1){\n  \
    \          x=((__int128_t)x*x+c)%n;\n            y=((__int128_t)y*y%n+c)%n;\n\
    \            y=((__int128_t)y*y%n+c)%n;\n            d=std::gcd(std::abs(x-y),n);\n\
    \        }\n        if(d==n){\n            c++;\n            continue;\n     \
    \   }\n        __prime_factor(d,c,v);\n        __prime_factor(n/d,c,v);\n    \
    \    return;\n    }\n}\n\nstd::map<long long,long long> prime_factor(long long\
    \ n){\n    std::vector<long long>v;\n    long long c=1;\n    __prime_factor(n,c,v);\n\
    \    std::map<long long,long long>m;\n    for(auto e:v){\n        m[e]++;\n  \
    \  }\n    return m;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<numeric>\n#include<cmath>\n#include<algorithm>\n\
    #include<map>\n#include\"is_prime.hpp\"\n\n/**\n * @brief \u7D20\u56E0\u6570\u5206\
    \u89E3(\u9AD8\u901F)\n */\n\nvoid __prime_factor(long long n,long long& c,std::vector<long\
    \ long>& v){\n    if(n==1)return;\n    if(n%2==0){\n        v.emplace_back(2);\n\
    \        __prime_factor(n/2,c,v);\n        return;\n    }\n    if(is_prime(n)){\n\
    \        v.emplace_back(n);\n        return;\n    }\n    while(1){\n        long\
    \ long x=2,y=2,d=1;\n        while(d==1){\n            x=((__int128_t)x*x+c)%n;\n\
    \            y=((__int128_t)y*y%n+c)%n;\n            y=((__int128_t)y*y%n+c)%n;\n\
    \            d=std::gcd(std::abs(x-y),n);\n        }\n        if(d==n){\n    \
    \        c++;\n            continue;\n        }\n        __prime_factor(d,c,v);\n\
    \        __prime_factor(n/d,c,v);\n        return;\n    }\n}\n\nstd::map<long\
    \ long,long long> prime_factor(long long n){\n    std::vector<long long>v;\n \
    \   long long c=1;\n    __prime_factor(n,c,v);\n    std::map<long long,long long>m;\n\
    \    for(auto e:v){\n        m[e]++;\n    }\n    return m;\n}"
  dependsOn:
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/prime_factor.hpp
  requiredBy:
  - math/fact_list.hpp
  timestamp: '2021-01-30 11:27:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/LC_prime_factor.test.cpp
  - math/test/AOJ_prime_factor.test.cpp
documentation_of: math/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime_factor.hpp
- /library/math/prime_factor.hpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)"
---
