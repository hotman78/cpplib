---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/LC_totient_sum.test.cpp
    title: math/test/LC_totient_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C"
    links: []
  bundledCode: "#line 2 \"math/totient_sum.hpp\"\n#include<map>\n\n/**\n * @brief\
    \ \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C\n */\n\ntemplate<typename\
    \ T>\nT totient_sum(long long n){\n    static std::map<long long,T> m2;\n    static\
    \ bool init=1;\n    static long long* m=new long long[10000000]();\n    if(init){\n\
    \        init=0;\n        long long k=1e7;\n        for(long long i=1;i<=k;i++)m[i]=i;\n\
    \        for(long long i=1;i<=k;i++)for(long long j=i*2;j<=k;j+=i)m[j]-=m[i];\n\
    \        for(long long i=1;i<k;i++)m[i+1]+=m[i];\n    }\n    if(n<1e7)return m[n];\n\
    \    else if(m2.count(n))return m2[n];\n    T ans=T(n)*(n+1)/2;\n    long long\
    \ mx=0;\n    for(long long i=1;i*i<n;i++){\n        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);\n\
    \        mx=n/(i+1)+1;\n    }\n    for(long long i=2;i<mx;i++){\n        ans-=totient_sum<T>(n/i);\n\
    \    }\n    return m2[n]=ans;\n}\n"
  code: "#pragma once\n#include<map>\n\n/**\n * @brief \u30C8\u30FC\u30B7\u30A7\u30F3\
    \u30C8\u95A2\u6570\u306E\u548C\n */\n\ntemplate<typename T>\nT totient_sum(long\
    \ long n){\n    static std::map<long long,T> m2;\n    static bool init=1;\n  \
    \  static long long* m=new long long[10000000]();\n    if(init){\n        init=0;\n\
    \        long long k=1e7;\n        for(long long i=1;i<=k;i++)m[i]=i;\n      \
    \  for(long long i=1;i<=k;i++)for(long long j=i*2;j<=k;j+=i)m[j]-=m[i];\n    \
    \    for(long long i=1;i<k;i++)m[i+1]+=m[i];\n    }\n    if(n<1e7)return m[n];\n\
    \    else if(m2.count(n))return m2[n];\n    T ans=T(n)*(n+1)/2;\n    long long\
    \ mx=0;\n    for(long long i=1;i*i<n;i++){\n        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);\n\
    \        mx=n/(i+1)+1;\n    }\n    for(long long i=2;i<mx;i++){\n        ans-=totient_sum<T>(n/i);\n\
    \    }\n    return m2[n]=ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/totient_sum.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/LC_totient_sum.test.cpp
documentation_of: math/totient_sum.hpp
layout: document
redirect_from:
- /library/math/totient_sum.hpp
- /library/math/totient_sum.hpp.html
title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C"
---
