---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  - icon: ':heavy_check_mark:'
    path: data_structure/RMQ.hpp
    title: RMQ&amp;lt;O(N),O(1)&amp;gt;
  - icon: ':heavy_check_mark:'
    path: data_structure/arg_rmq.hpp
    title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  - icon: ':x:'
    path: data_structure/test/LC_sparse_table.test.cpp
    title: data_structure/test/LC_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_RMQ.test.cpp
    title: data_structure/test/LC_RMQ.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: SparseTable
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n#include<vector>\n#include<functional>\n\
    #include<cmath>\n#include<algorithm>\n#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\
    \n/**\n * @brief Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [op](const maybe<T>& s,const maybe<T>&\
    \ t){\n        if(s.is_none())return t;\n        if(t.is_none())return s;\n  \
    \      return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 7 \"data_structure/sparse_table.hpp\"\
    \n/**\n * @brief SparseTable\n */\n\ntemplate<typename T,typename F>\nclass sparse_table{\n\
    \    F f;\n    std::vector<std::vector<T>>data;\n    public:\n    sparse_table(std::vector<T>\
    \ v,F f=F()):f(f){\n        int n=v.size(),log=log2(n)+1;\n        data.resize(n,std::vector<T>(log));\n\
    \        for(int i=0;i<n;i++)data[i][0]=v[i];\n        for(int j=1;j<log;j++)for(int\
    \ i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    maybe<T> get(int l,int r){\n        if(l==r)return maybe<T>();\n\
    \        if(r<l)std::swap(l,r);\n        int k=std::log2(r-l);\n        return\
    \ maybe<T>(f(data[l][k],data[r-(1<<k)][k]));\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<functional>\n#include<cmath>\n#include<algorithm>\n\
    #include\"../alga/maybe.hpp\"\n/**\n * @brief SparseTable\n */\n\ntemplate<typename\
    \ T,typename F>\nclass sparse_table{\n    F f;\n    std::vector<std::vector<T>>data;\n\
    \    public:\n    sparse_table(std::vector<T> v,F f=F()):f(f){\n        int n=v.size(),log=log2(n)+1;\n\
    \        data.resize(n,std::vector<T>(log));\n        for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \        for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    maybe<T> get(int l,int r){\n        if(l==r)return maybe<T>();\n\
    \        if(r<l)std::swap(l,r);\n        int k=std::log2(r-l);\n        return\
    \ maybe<T>(f(data[l][k],data[r-(1<<k)][k]));\n    }\n};"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy:
  - graph_tree/lca.hpp
  - data_structure/RMQ.hpp
  - data_structure/arg_rmq.hpp
  timestamp: '2020-09-19 10:39:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - graph_tree/test/LC_lca.test.cpp
  - data_structure/test/LC_sparse_table.test.cpp
  - data_structure/test/LC_RMQ.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: SparseTable
---
