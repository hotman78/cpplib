---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/FPS_long.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(Integer)"
  - icon: ':question:'
    path: math/FPS_mint.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_1000000007.test.cpp
    title: math/test/LC_convolution_1000000007.test.cpp
  - icon: ':x:'
    path: math/test/LC_interpolation.test.cpp
    title: math/test/LC_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_998244353.test.cpp
    title: math/test/LC_convolution_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/ceil_pow2.hpp\"\nint ceil_pow2(int n) {\n    int x\
    \ = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n"
  code: "int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned\
    \ int)(n)) x++;\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ceil_pow2.hpp
  requiredBy:
  - math/FPS_long.hpp
  - math/FPS_mint.hpp
  timestamp: '2020-09-14 19:36:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - math/test/LC_convolution_1000000007.test.cpp
  - math/test/LC_interpolation.test.cpp
  - math/test/LC_convolution_998244353.test.cpp
  - graph_tree/test/LC_centroid_decomposition.test.cpp
documentation_of: math/ceil_pow2.hpp
layout: document
redirect_from:
- /library/math/ceil_pow2.hpp
- /library/math/ceil_pow2.hpp.html
title: math/ceil_pow2.hpp
---
