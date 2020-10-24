---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/mod_sqrt.hpp
    title: ModSqrt
  _extendedVerifiedWith:
  - icon: ':x:'
    path: math/test/LC_mod_sqrt.test.cpp
    title: math/test/LC_mod_sqrt.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/random_gen.hpp\"\n#include<random>\n#include<chrono>\n\
    \nstruct RandomNumberGenerator {\n    std::mt19937 mt;\n    RandomNumberGenerator()\
    \ : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n    int\
    \ operator()(int a, int b) { // [a, b)\n        std::uniform_int_distribution<\
    \ int > dist(a, b - 1);\n        return dist(mt);\n    }\n\n    int operator()(int\
    \ b) { // [0, b)\n        return (*this)(0, b);\n    }\n};\n"
  code: "#pragma once\n#include<random>\n#include<chrono>\n\nstruct RandomNumberGenerator\
    \ {\n    std::mt19937 mt;\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    int operator()(int a, int b) { // [a, b)\n        std::uniform_int_distribution<\
    \ int > dist(a, b - 1);\n        return dist(mt);\n    }\n\n    int operator()(int\
    \ b) { // [0, b)\n        return (*this)(0, b);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: util/random_gen.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  timestamp: '2020-09-14 10:33:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - math/test/LC_mod_sqrt.test.cpp
documentation_of: util/random_gen.hpp
layout: document
redirect_from:
- /library/util/random_gen.hpp
- /library/util/random_gen.hpp.html
title: util/random_gen.hpp
---
