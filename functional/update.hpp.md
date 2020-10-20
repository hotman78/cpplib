---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: segment_tree/test/AOJ_dual_segment_tree.test.cpp
    title: segment_tree/test/AOJ_dual_segment_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u66F4\u65B0"
    links: []
  bundledCode: "#line 2 \"functional/update.hpp\"\n\n/**\n * @brief \u66F4\u65B0\n\
    \ */\n\ntemplate<typename T>\nstruct update{\n    T operator()(const T& s,const\
    \ T& t){\n        return t;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u66F4\u65B0\n */\n\ntemplate<typename T>\n\
    struct update{\n    T operator()(const T& s,const T& t){\n        return t;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: functional/update.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:18:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - segment_tree/test/AOJ_dual_segment_tree.test.cpp
documentation_of: functional/update.hpp
layout: document
redirect_from:
- /library/functional/update.hpp
- /library/functional/update.hpp.html
title: "\u66F4\u65B0"
---
