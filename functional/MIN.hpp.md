---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/RMQ.hpp
    title: RMQ&amp;lt;O(N),O(1)&amp;gt;
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_sparse_table.test.cpp
    title: data_structure/test/LC_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_RMQ.test.cpp
    title: data_structure/test/LC_RMQ.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5C0F\u5024"
    links: []
  bundledCode: "#line 2 \"functional/MIN.hpp\"\n#include<algorithm>\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\n */\n\ntemplate<typename T>\nstruct MIN{\n    T operator()(const\
    \ T& s,const T& t){\n        return std::min(s,t);\n    }\n};\n"
  code: "#pragma once\n#include<algorithm>\n\n/**\n * @brief \u6700\u5C0F\u5024\n\
    \ */\n\ntemplate<typename T>\nstruct MIN{\n    T operator()(const T& s,const T&\
    \ t){\n        return std::min(s,t);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: functional/MIN.hpp
  requiredBy:
  - data_structure/RMQ.hpp
  timestamp: '2020-09-18 14:44:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_sparse_table.test.cpp
  - data_structure/test/LC_RMQ.test.cpp
documentation_of: functional/MIN.hpp
layout: document
redirect_from:
- /library/functional/MIN.hpp
- /library/functional/MIN.hpp.html
title: "\u6700\u5C0F\u5024"
---
