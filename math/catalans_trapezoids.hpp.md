---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30AB\u30BF\u30E9\u30F3\u53F0\u5F62"
    links: []
  bundledCode: "#line 1 \"math/catalans_trapezoids.hpp\"\n/**\n * @brief \u30AB\u30BF\
    \u30E9\u30F3\u53F0\u5F62\n */\ntemplate<typename T>\nT catalans_trapezoids(long\
    \ long n,long long k,long long m=1){\n    if(m<=0)return T();\n    else if(0<=k&&k<m)return\
    \ T(n+k).comb(k);\n    else if(m<=k&&k<n+m)return T(n+k).comb(k)-T(n+k).comb(k-m);\n\
    \    else return T(0);\n}\n"
  code: "/**\n * @brief \u30AB\u30BF\u30E9\u30F3\u53F0\u5F62\n */\ntemplate<typename\
    \ T>\nT catalans_trapezoids(long long n,long long k,long long m=1){\n    if(m<=0)return\
    \ T();\n    else if(0<=k&&k<m)return T(n+k).comb(k);\n    else if(m<=k&&k<n+m)return\
    \ T(n+k).comb(k)-T(n+k).comb(k-m);\n    else return T(0);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/catalans_trapezoids.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/catalans_trapezoids.hpp
layout: document
redirect_from:
- /library/math/catalans_trapezoids.hpp
- /library/math/catalans_trapezoids.hpp.html
title: "\u30AB\u30BF\u30E9\u30F3\u53F0\u5F62"
---
