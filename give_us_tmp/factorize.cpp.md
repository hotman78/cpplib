---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)"
    links:
    - https://judge.yosupo.jp/problem/factorize
    - https://judge.yosupo.jp/submission/28308
  bundledCode: "#line 1 \"give_us_tmp/factorize.cpp\"\n/**\n * @brief \u7D20\u56E0\
    \u6570\u5206\u89E3(\u9AD8\u901F)\n * \n * verified with    :https://judge.yosupo.jp/problem/factorize\n\
    \ * submission       :https://judge.yosupo.jp/submission/28308\n */\n\nvoid __factorize(ll\
    \ n,ll& c,V<ll>& v){\n    if(n==1)return;\n    if(n%2==0){\n        v.emplace_back(2);\n\
    \        __factorize(n/2,c,v);\n        return;\n    }\n    if(is_prime(n)){\n\
    \        v.emplace_back(n);\n        return;\n    }\n    while(1){\n        long\
    \ long x=2,y=2,d=1;\n        while(d==1){\n            x=((__int128_t)x*x+c)%n;\n\
    \            y=((__int128_t)y*y%n+c)%n;\n            y=((__int128_t)y*y%n+c)%n;\n\
    \            d=std::gcd(std::abs(x-y),n);\n        }\n        if(d==n){\n    \
    \        c++;\n            continue;\n        }\n        __factorize(d,c,v);\n\
    \        __factorize(n/d,c,v);\n        return;\n    }\n}\n\nmap<ll,ll> factorize(ll\
    \ n){\n    V<ll>v;\n    ll c=1;\n    __factorize(n,c,v);\n    map<ll,ll>m;\n \
    \   for(auto e:v){\n        m[e]++;\n    }\n    return m;\n}\n"
  code: "/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)\n * \n * verified\
    \ with    :https://judge.yosupo.jp/problem/factorize\n * submission       :https://judge.yosupo.jp/submission/28308\n\
    \ */\n\nvoid __factorize(ll n,ll& c,V<ll>& v){\n    if(n==1)return;\n    if(n%2==0){\n\
    \        v.emplace_back(2);\n        __factorize(n/2,c,v);\n        return;\n\
    \    }\n    if(is_prime(n)){\n        v.emplace_back(n);\n        return;\n  \
    \  }\n    while(1){\n        long long x=2,y=2,d=1;\n        while(d==1){\n  \
    \          x=((__int128_t)x*x+c)%n;\n            y=((__int128_t)y*y%n+c)%n;\n\
    \            y=((__int128_t)y*y%n+c)%n;\n            d=std::gcd(std::abs(x-y),n);\n\
    \        }\n        if(d==n){\n            c++;\n            continue;\n     \
    \   }\n        __factorize(d,c,v);\n        __factorize(n/d,c,v);\n        return;\n\
    \    }\n}\n\nmap<ll,ll> factorize(ll n){\n    V<ll>v;\n    ll c=1;\n    __factorize(n,c,v);\n\
    \    map<ll,ll>m;\n    for(auto e:v){\n        m[e]++;\n    }\n    return m;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/factorize.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/factorize.cpp
layout: document
redirect_from:
- /library/give_us_tmp/factorize.cpp
- /library/give_us_tmp/factorize.cpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)"
---
