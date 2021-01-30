---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
    links:
    - https://judge.yosupo.jp/problem/factorize
    - https://judge.yosupo.jp/submission/28308
  bundledCode: "#line 1 \"give_us_tmp/is_prime.cpp\"\n/**\n * @brief \u7D20\u6570\u5224\
    \u5B9A(\u9AD8\u901F)\n * \n * verified with    :https://judge.yosupo.jp/problem/factorize\n\
    \ * submission       :https://judge.yosupo.jp/submission/28308\n */\nbool is_prime(ll\
    \ n){\n    if(n<=1)return 0;\n    if(n==2)return 1;\n    if(n%2==0)return 0;\n\
    \    ll s=0,d=n-1;\n    while(d%2)d/=2,s++;\n    auto mod_pow=[](__int128_t a,__int128_t\
    \ b,__int128_t n){\n        ll res=1;\n        while(b){\n            if(b%2)res=res*a%n;\n\
    \            a=a*a%n;\n            b/=2;\n        }\n        return (ll)(res);\n\
    \    };\n    for(ll e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n        if(n<=e)break;\n\
    \        if(mod_pow(e,d,n)==1)continue;\n        bool b=1;\n        for(int i=0;i<s;i++){\n\
    \            if(mod_pow(e,d<<i,n)==n-1)b=0;\n        }\n        if(b)return 0;\n\
    \    }\n    return 1;\n}\n"
  code: "/**\n * @brief \u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)\n * \n * verified with\
    \    :https://judge.yosupo.jp/problem/factorize\n * submission       :https://judge.yosupo.jp/submission/28308\n\
    \ */\nbool is_prime(ll n){\n    if(n<=1)return 0;\n    if(n==2)return 1;\n   \
    \ if(n%2==0)return 0;\n    ll s=0,d=n-1;\n    while(d%2)d/=2,s++;\n    auto mod_pow=[](__int128_t\
    \ a,__int128_t b,__int128_t n){\n        ll res=1;\n        while(b){\n      \
    \      if(b%2)res=res*a%n;\n            a=a*a%n;\n            b/=2;\n        }\n\
    \        return (ll)(res);\n    };\n    for(ll e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \        if(n<=e)break;\n        if(mod_pow(e,d,n)==1)continue;\n        bool\
    \ b=1;\n        for(int i=0;i<s;i++){\n            if(mod_pow(e,d<<i,n)==n-1)b=0;\n\
    \        }\n        if(b)return 0;\n    }\n    return 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/is_prime.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/is_prime.cpp
layout: document
redirect_from:
- /library/give_us_tmp/is_prime.cpp
- /library/give_us_tmp/is_prime.cpp.html
title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
---
