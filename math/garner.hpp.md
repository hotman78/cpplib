---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/FPS_long.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(Integer)"
  - icon: ':heavy_check_mark:'
    path: math/FPS_mint.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_1000000007.test.cpp
    title: math/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_998244353.test.cpp
    title: math/test/LC_convolution_998244353.test.cpp
  - icon: ':x:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links: []
  bundledCode: "#line 2 \"math/garner.hpp\"\n#include<vector>\n#line 1 \"math/mod_pow.hpp\"\
    \n/**\n * @brief (x^y)%mod\n */\n\nlong long mod_pow(long long x,long long y,long\
    \ long mod){\n    long long ret=1;\n    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n\
    \        (x*=x)%=mod;\n        y>>=1;\n    }\n    return ret;\n}\n#line 4 \"math/garner.hpp\"\
    \n\n/**\n * \n * @brief \u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\n *\n */\n\nlong long garner(std::vector<long long>a,std::vector<long\
    \ long>mods){\n    const int sz=3;\n    long long coeffs[sz+1]={1,1,1,1};\n  \
    \  long long constants[sz+1]={};\n    for(int i=0;i<sz;i++){\n        long long\
    \ v=(mods[i]+a[i]-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];\n\
    \        for(int j=i+1;j<sz+1;j++) {\n            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];\n\
    \            coeffs[j]=(coeffs[j]*mods[i])%mods[j];\n        }\n    }\n    return\
    \ constants[3];\n}\n"
  code: "#pragma once\n#include<vector>\n#include\"mod_pow.hpp\"\n\n/**\n * \n * @brief\
    \ \u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *\n */\n\
    \nlong long garner(std::vector<long long>a,std::vector<long long>mods){\n    const\
    \ int sz=3;\n    long long coeffs[sz+1]={1,1,1,1};\n    long long constants[sz+1]={};\n\
    \    for(int i=0;i<sz;i++){\n        long long v=(mods[i]+a[i]-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];\n\
    \        for(int j=i+1;j<sz+1;j++) {\n            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];\n\
    \            coeffs[j]=(coeffs[j]*mods[i])%mods[j];\n        }\n    }\n    return\
    \ constants[3];\n}"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/garner.hpp
  requiredBy:
  - math/FPS_long.hpp
  - math/FPS_mint.hpp
  timestamp: '2020-09-14 19:36:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - math/test/LC_convolution_1000000007.test.cpp
  - math/test/LC_convolution_998244353.test.cpp
  - graph_tree/test/LC_centroid_decomposition.test.cpp
documentation_of: math/garner.hpp
layout: document
redirect_from:
- /library/math/garner.hpp
- /library/math/garner.hpp.html
title: "\u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---
