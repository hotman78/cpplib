---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: ModSqrt
  - icon: ':heavy_check_mark:'
    path: math/FPS_long.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(Integer)"
  - icon: ':heavy_check_mark:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570(ModLog)"
  - icon: ':heavy_check_mark:'
    path: math/FPS_mint.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  - icon: ':heavy_check_mark:'
    path: math/garner.hpp
    title: "\u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/LC_mod_sqrt.test.cpp
    title: math/test/LC_mod_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_1000000007.test.cpp
    title: math/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_mod_log.test.cpp
    title: math/test/LC_mod_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_998244353.test.cpp
    title: math/test/LC_convolution_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_tetration.test.cpp
    title: math/test/LC_tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: (x^y)%mod
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\n/**\n * @brief (x^y)%mod\n */\n\nlong\
    \ long mod_pow(long long x,long long y,long long mod){\n    long long ret=1;\n\
    \    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n        (x*=x)%=mod;\n     \
    \   y>>=1;\n    }\n    return ret;\n}\n"
  code: "/**\n * @brief (x^y)%mod\n */\n\nlong long mod_pow(long long x,long long\
    \ y,long long mod){\n    long long ret=1;\n    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n\
    \        (x*=x)%=mod;\n        y>>=1;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy:
  - math/tetration.hpp
  - math/mod_sqrt.hpp
  - math/FPS_long.hpp
  - math/mod_log.hpp
  - math/FPS_mint.hpp
  - math/garner.hpp
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/LC_mod_sqrt.test.cpp
  - math/test/LC_convolution_1000000007.test.cpp
  - math/test/LC_mod_log.test.cpp
  - math/test/LC_convolution_998244353.test.cpp
  - math/test/LC_tetration.test.cpp
  - graph_tree/test/LC_centroid_decomposition.test.cpp
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: (x^y)%mod
---
