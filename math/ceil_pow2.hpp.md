---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/FPS_long.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(Integer)"
  - icon: ':heavy_check_mark:'
    path: math/FPS_mint.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  - icon: ':warning:'
    path: math/kth_root.hpp
    title: math/kth_root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_1000000007.test.cpp
    title: math/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_998244353.test.cpp
    title: math/test/LC_convolution_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_interpolation.test.cpp
    title: math/test/LC_interpolation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ceil_pow2.hpp\"\nint ceil_pow2(int n) {\n    int x\
    \ = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n"
  code: "int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned\
    \ int)(n)) x++;\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ceil_pow2.hpp
  requiredBy:
  - math/FPS_mint.hpp
  - math/kth_root.hpp
  - math/FPS_long.hpp
  timestamp: '2020-09-14 19:36:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_centroid_decomposition.test.cpp
  - math/test/LC_convolution_998244353.test.cpp
  - math/test/LC_convolution_1000000007.test.cpp
  - math/test/LC_interpolation.test.cpp
documentation_of: math/ceil_pow2.hpp
layout: document
redirect_from:
- /library/math/ceil_pow2.hpp
- /library/math/ceil_pow2.hpp.html
title: math/ceil_pow2.hpp
---
