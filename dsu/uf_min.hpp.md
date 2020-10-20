---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph_tree/dominator_tree.hpp
    title: "\u652F\u914D\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_dominator_tree.test.cpp
    title: graph_tree/test/LC_dominator_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6839\u3068\u306EPath\u306E\u4E2D\u3067\u306E\u6700\u5C0F\u5024\
      \u3092\u8FD4\u3059UnionFind"
    links: []
  bundledCode: "#line 2 \"dsu/uf_min.hpp\"\n#include<vector>\n#include<numeric>\n\
    #include<limits>\n\n/**\n * @brief \u6839\u3068\u306EPath\u306E\u4E2D\u3067\u306E\
    \u6700\u5C0F\u5024\u3092\u8FD4\u3059UnionFind\n */\n\ntemplate<typename T>\nstruct\
    \ uf_min{\n    constexpr static int inf=std::numeric_limits<T>::max();\n    std::vector<int>par,mnid;\n\
    \    std::vector<T>mn;\n    uf_min(int v){\n        par.resize(v);\n        mn.resize(v,inf);\n\
    \        mnid.resize(v);\n        std::iota(par.begin(),par.end(),0);\n      \
    \  std::iota(mnid.begin(),mnid.end(),0);\n    }\n    int find(int v){\n      \
    \  if(par[v]==v)return v;\n        int r=find(par[v]);\n        if(mn[v]>mn[par[v]]){\n\
    \            mnid[v]=mnid[par[v]];\n            mn[v]=mn[par[v]];\n        }\n\
    \        par[v]=r;\n        return r;\n    }\n    void set(int v,T x){\n     \
    \   mn[v]=x;\n    }\n    T eval(int v){\n        find(v);\n        return mnid[v];\n\
    \    }\n    //x\u3092y\u306E\u89AA\u306B\u3059\u308B\n    void link(int x,int\
    \ y){\n        par[y]=x;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<numeric>\n#include<limits>\n\n/**\n\
    \ * @brief \u6839\u3068\u306EPath\u306E\u4E2D\u3067\u306E\u6700\u5C0F\u5024\u3092\
    \u8FD4\u3059UnionFind\n */\n\ntemplate<typename T>\nstruct uf_min{\n    constexpr\
    \ static int inf=std::numeric_limits<T>::max();\n    std::vector<int>par,mnid;\n\
    \    std::vector<T>mn;\n    uf_min(int v){\n        par.resize(v);\n        mn.resize(v,inf);\n\
    \        mnid.resize(v);\n        std::iota(par.begin(),par.end(),0);\n      \
    \  std::iota(mnid.begin(),mnid.end(),0);\n    }\n    int find(int v){\n      \
    \  if(par[v]==v)return v;\n        int r=find(par[v]);\n        if(mn[v]>mn[par[v]]){\n\
    \            mnid[v]=mnid[par[v]];\n            mn[v]=mn[par[v]];\n        }\n\
    \        par[v]=r;\n        return r;\n    }\n    void set(int v,T x){\n     \
    \   mn[v]=x;\n    }\n    T eval(int v){\n        find(v);\n        return mnid[v];\n\
    \    }\n    //x\u3092y\u306E\u89AA\u306B\u3059\u308B\n    void link(int x,int\
    \ y){\n        par[y]=x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu/uf_min.hpp
  requiredBy:
  - graph_tree/dominator_tree.hpp
  timestamp: '2020-09-18 22:09:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_dominator_tree.test.cpp
documentation_of: dsu/uf_min.hpp
layout: document
redirect_from:
- /library/dsu/uf_min.hpp
- /library/dsu/uf_min.hpp.html
title: "\u6839\u3068\u306EPath\u306E\u4E2D\u3067\u306E\u6700\u5C0F\u5024\u3092\u8FD4\
  \u3059UnionFind"
---
