---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/prime_factor.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: math/test/AOJ_prime_factor.test.cpp
    title: math/test/AOJ_prime_factor.test.cpp
  - icon: ':x:'
    path: math/test/LC_prime_factor.test.cpp
    title: math/test/LC_prime_factor.test.cpp
  - icon: ':x:'
    path: math/test/AOJ_is_prime.test.cpp
    title: math/test/AOJ_is_prime.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
    links: []
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n#include <initializer_list>\n/**\n\
    \ * @brief \u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)\n */\nbool is_prime(long long\
    \ n){\n    if(n<=1)return 0;\n    if(n==2)return 1;\n    if(n%2==0)return 0;\n\
    \    long long s=0,d=n-1;\n    while(d%2)d/=2,s++;\n    auto mod_pow=[](__int128_t\
    \ a,__int128_t b,__int128_t n){\n        long long res=1;\n        while(b){\n\
    \            if(b%2)res=res*a%n;\n            a=a*a%n;\n            b/=2;\n  \
    \      }\n        return (long long)(res);\n    };\n    for(long long e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \        if(n<=e)break;\n        if(mod_pow(e,d,n)==1)continue;\n        bool\
    \ b=1;\n        for(int i=0;i<s;i++){\n            if(mod_pow(e,d<<i,n)==n-1)b=0;\n\
    \        }\n        if(b)return 0;\n    }\n    return 1;\n}\n"
  code: "#pragma once\n#include <initializer_list>\n/**\n * @brief \u7D20\u6570\u5224\
    \u5B9A(\u9AD8\u901F)\n */\nbool is_prime(long long n){\n    if(n<=1)return 0;\n\
    \    if(n==2)return 1;\n    if(n%2==0)return 0;\n    long long s=0,d=n-1;\n  \
    \  while(d%2)d/=2,s++;\n    auto mod_pow=[](__int128_t a,__int128_t b,__int128_t\
    \ n){\n        long long res=1;\n        while(b){\n            if(b%2)res=res*a%n;\n\
    \            a=a*a%n;\n            b/=2;\n        }\n        return (long long)(res);\n\
    \    };\n    for(long long e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n        if(n<=e)break;\n\
    \        if(mod_pow(e,d,n)==1)continue;\n        bool b=1;\n        for(int i=0;i<s;i++){\n\
    \            if(mod_pow(e,d<<i,n)==n-1)b=0;\n        }\n        if(b)return 0;\n\
    \    }\n    return 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math/prime_factor.hpp
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - math/test/AOJ_prime_factor.test.cpp
  - math/test/LC_prime_factor.test.cpp
  - math/test/AOJ_is_prime.test.cpp
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
---
