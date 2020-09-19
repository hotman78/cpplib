---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
    title: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u533A\u9593\u52A0\u7B97"
    links: []
  bundledCode: "#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n\
    \ * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 3\
    \ \"functional/range_add_and_range_sum.hpp\"\n\n/**\n * @brief \u533A\u9593\u52A0\
    \u7B97\n */\n\ntemplate<typename T,typename E>\nstruct range_add_and_range_sum{\n\
    \    T operator()(const maybe<T>& s,const E& t,int l,int r){\n        return s.unwrap_or(T())+t*(r-l);\n\
    \    }\n};\n"
  code: "#pragma once\n#include\"../alga/maybe.hpp\"\n\n/**\n * @brief \u533A\u9593\
    \u52A0\u7B97\n */\n\ntemplate<typename T,typename E>\nstruct range_add_and_range_sum{\n\
    \    T operator()(const maybe<T>& s,const E& t,int l,int r){\n        return s.unwrap_or(T())+t*(r-l);\n\
    \    }\n};"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: functional/range_add_and_range_sum.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:47:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/AOJ_lazy_segment_tree.test.cpp
documentation_of: functional/range_add_and_range_sum.hpp
layout: document
redirect_from:
- /library/functional/range_add_and_range_sum.hpp
- /library/functional/range_add_and_range_sum.hpp.html
title: "\u533A\u9593\u52A0\u7B97"
---
