---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/FPS.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/LC_convolution_1000000007.test.cpp
    title: convolution/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/LC_convolution_998244353.test.cpp
    title: convolution/test/LC_convolution_998244353.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - convolution/FPS.hpp
  timestamp: '2020-09-14 19:36:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/LC_convolution_1000000007.test.cpp
  - convolution/test/LC_convolution_998244353.test.cpp
documentation_of: math/ceil_pow2.hpp
layout: document
redirect_from:
- /library/math/ceil_pow2.hpp
- /library/math/ceil_pow2.hpp.html
title: math/ceil_pow2.hpp
---
