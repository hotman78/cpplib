---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/RMQ.hpp
    title: RMQ&amp;lt;O(N),O(1)&amp;gt;
  - icon: ':heavy_check_mark:'
    path: data_structure/arg_rmq.hpp
    title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_RMQ.test.cpp
    title: data_structure/test/LC_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/small_rmq.hpp\"\n#include<vector>\n\n/**\n\
    \ * RMQ(small) &amp;lt;O(N),O(1)&amp;gt;(N<=64)\n */\n\ntemplate<typename T>\n\
    class small_rmq{\n    using u64=unsigned long long;\n    std::vector<u64>table;\n\
    \    std::vector<T> v;\n    public:\n    small_rmq(std::vector<T> v):v(v){\n \
    \       assert(v.size()<=64);\n        std::vector<int>tmp(v.size());\n      \
    \  table.resize(v.size(),0);\n        std::stack<T>stk;\n        for(int i=0;i<(int)v.size();++i){\n\
    \            tmp.resize(v.size());\n            while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                stk.pop();\n            }\n            tmp[i]=stk.empty()?-1:stk.top();\n\
    \            stk.emplace(i);\n        }\n        for(int i=0;i<(int)v.size();++i){\n\
    \            if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n        }\n\
    \    }\n    T query(int l,int r){\n        assert(l!=r);\n        const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \        if(tmp==0)return r-1;\n        else return __builtin_ctzll(tmp);\n  \
    \  }\n};\n"
  code: "#pragma once\n#include<vector>\n\n/**\n * RMQ(small) &amp;lt;O(N),O(1)&amp;gt;(N<=64)\n\
    \ */\n\ntemplate<typename T>\nclass small_rmq{\n    using u64=unsigned long long;\n\
    \    std::vector<u64>table;\n    std::vector<T> v;\n    public:\n    small_rmq(std::vector<T>\
    \ v):v(v){\n        assert(v.size()<=64);\n        std::vector<int>tmp(v.size());\n\
    \        table.resize(v.size(),0);\n        std::stack<T>stk;\n        for(int\
    \ i=0;i<(int)v.size();++i){\n            tmp.resize(v.size());\n            while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                stk.pop();\n            }\n            tmp[i]=stk.empty()?-1:stk.top();\n\
    \            stk.emplace(i);\n        }\n        for(int i=0;i<(int)v.size();++i){\n\
    \            if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n        }\n\
    \    }\n    T query(int l,int r){\n        assert(l!=r);\n        const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \        if(tmp==0)return r-1;\n        else return __builtin_ctzll(tmp);\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/small_rmq.hpp
  requiredBy:
  - data_structure/RMQ.hpp
  - data_structure/arg_rmq.hpp
  - graph_tree/lca.hpp
  timestamp: '2020-09-19 10:39:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_RMQ.test.cpp
  - graph_tree/test/LC_lca.test.cpp
documentation_of: data_structure/small_rmq.hpp
layout: document
redirect_from:
- /library/data_structure/small_rmq.hpp
- /library/data_structure/small_rmq.hpp.html
title: data_structure/small_rmq.hpp
---
