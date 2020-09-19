---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  - icon: ':heavy_check_mark:'
    path: data_structure/arg_rmq.hpp
    title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E"
    links: []
  bundledCode: "#line 2 \"functional/argmin.hpp\"\n#include<tuple>\n\n/**\n * @brief\
    \ \u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E\n */\n\ntemplate<typename T,typename\
    \ E>\nstruct argmin{\n    std::pair<T,E> operator()(const std::pair<T,E>& s,const\
    \ std::pair<T,E>& t){\n        return s.second<=t.second?s:t;\n    }\n};\n"
  code: "#pragma once\n#include<tuple>\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E\n */\n\ntemplate<typename T,typename E>\nstruct argmin{\n \
    \   std::pair<T,E> operator()(const std::pair<T,E>& s,const std::pair<T,E>& t){\n\
    \        return s.second<=t.second?s:t;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: functional/argmin.hpp
  requiredBy:
  - graph_tree/lca.hpp
  - data_structure/arg_rmq.hpp
  timestamp: '2020-09-18 14:44:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_lca.test.cpp
documentation_of: functional/argmin.hpp
layout: document
redirect_from:
- /library/functional/argmin.hpp
- /library/functional/argmin.hpp.html
title: "\u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E"
---
