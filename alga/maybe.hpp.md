---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: Segment Tree
  - icon: ':warning:'
    path: alga/monoid.hpp
    title: alga/monoid.hpp
  - icon: ':warning:'
    path: graph_tree/min_cost_flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  - icon: ':heavy_check_mark:'
    path: data_structure/swag.hpp
    title: SWAG(Queue)
  - icon: ':heavy_check_mark:'
    path: data_structure/RMQ.hpp
    title: RMQ&amp;lt;O(N),O(1)&amp;gt;
  - icon: ':heavy_check_mark:'
    path: data_structure/arg_rmq.hpp
    title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
  - icon: ':question:'
    path: data_structure/sparse_table.hpp
    title: SparseTable
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree.test.cpp
    title: segment_tree/test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  - icon: ':x:'
    path: data_structure/test/LC_sparse_table.test.cpp
    title: data_structure/test/LC_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_swag.test.cpp
    title: data_structure/test/LC_swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_RMQ.test.cpp
    title: data_structure/test/LC_RMQ.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Maybe
    links:
    - https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89
  bundledCode: "#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n\
    \ * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [op](const maybe<T>& s,const maybe<T>&\
    \ t){\n        if(s.is_none())return t;\n        if(t.is_none())return s;\n  \
    \      return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n"
  code: "#pragma once\n#include<cassert>\n\n/**\n * @brief Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [op](const maybe<T>& s,const maybe<T>&\
    \ t){\n        if(s.is_none())return t;\n        if(t.is_none())return s;\n  \
    \      return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: alga/maybe.hpp
  requiredBy:
  - segment_tree/segment_tree.hpp
  - alga/monoid.hpp
  - graph_tree/min_cost_flow.hpp
  - graph_tree/lca.hpp
  - data_structure/swag.hpp
  - data_structure/RMQ.hpp
  - data_structure/arg_rmq.hpp
  - data_structure/sparse_table.hpp
  timestamp: '2020-09-18 14:44:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - segment_tree/test/segment_tree.test.cpp
  - graph_tree/test/LC_lca.test.cpp
  - data_structure/test/LC_sparse_table.test.cpp
  - data_structure/test/LC_swag.test.cpp
  - data_structure/test/LC_RMQ.test.cpp
documentation_of: alga/maybe.hpp
layout: document
redirect_from:
- /library/alga/maybe.hpp
- /library/alga/maybe.hpp.html
title: Maybe
---
