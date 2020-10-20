---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/test/LC_sum_power_poly_limit.cpp
    title: math/test/LC_sum_power_poly_limit.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/LC_floor_sum.test.cpp
    title: math/test/LC_floor_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: \sum_{i=0}^{n-1}\floor(a*i+b/c)
    links: []
  bundledCode: "#line 2 \"math/floor_sum.hpp\"\n/**\n * @brief \\sum_{i=0}^{n-1}\\\
    floor(a*i+b/c)\n */\nlong long floor_sum(long long a,long long b,long long c,long\
    \ long n){\n    long long tmp=b/c*n+a/c*n*(n-1)/2;\n    if(a%c==0){\n        return\
    \ tmp;\n    }\n    long long next=(c-b%c+a%c-1)/(a%c);\n    if(next>=n){\n   \
    \     return tmp;\n    }\n    a%=c;\n    b=b%c+a*next;\n    n-=next;\n    return\
    \ tmp+floor_sum(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);\n}\n"
  code: "#pragma once\n/**\n * @brief \\sum_{i=0}^{n-1}\\floor(a*i+b/c)\n */\nlong\
    \ long floor_sum(long long a,long long b,long long c,long long n){\n    long long\
    \ tmp=b/c*n+a/c*n*(n-1)/2;\n    if(a%c==0){\n        return tmp;\n    }\n    long\
    \ long next=(c-b%c+a%c-1)/(a%c);\n    if(next>=n){\n        return tmp;\n    }\n\
    \    a%=c;\n    b=b%c+a*next;\n    n-=next;\n    return tmp+floor_sum(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy:
  - math/test/LC_sum_power_poly_limit.cpp
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/LC_floor_sum.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
redirect_from:
- /library/math/floor_sum.hpp
- /library/math/floor_sum.hpp.html
title: \sum_{i=0}^{n-1}\floor(a*i+b/c)
---
