---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ \"alga/monoid.hpp\"\n\ntemplate<typename T,typename F>\nstruct monoid{\n   \
    \ using M=monoid<T,F>;\n    maybe<T> val;\n    F op;\n    monoid(F op):val(maybe<T>()),op(op){}\n\
    \    monoid(T val,F op):val(maybe<T>(val)),op(op){}\n    maybe<T> get(){return\
    \ val;}\n    void set(T x){return val=maybe<T>(x);}\n    M operator+(const M&\
    \ rhs){\n        if(val.is_none())return rhs;\n        if(rhs.val.is_none())return\
    \ *this;\n        return monoid(op(get().unwrap(),rhs.get().unwrap()),op);\n \
    \   }\n};\n"
  code: "#pragma once\n#include\"maybe.hpp\"\n\ntemplate<typename T,typename F>\n\
    struct monoid{\n    using M=monoid<T,F>;\n    maybe<T> val;\n    F op;\n    monoid(F\
    \ op):val(maybe<T>()),op(op){}\n    monoid(T val,F op):val(maybe<T>(val)),op(op){}\n\
    \    maybe<T> get(){return val;}\n    void set(T x){return val=maybe<T>(x);}\n\
    \    M operator+(const M& rhs){\n        if(val.is_none())return rhs;\n      \
    \  if(rhs.val.is_none())return *this;\n        return monoid(op(get().unwrap(),rhs.get().unwrap()),op);\n\
    \    }\n};"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: alga/monoid.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:18:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alga/monoid.hpp
layout: document
redirect_from:
- /library/alga/monoid.hpp
- /library/alga/monoid.hpp.html
title: alga/monoid.hpp
---
