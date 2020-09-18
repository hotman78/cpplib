---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph_tree/dominator_tree.hpp
    title: "\u652F\u914D\u6728"
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"dsu/uf_min.hpp\"\n#include<vector>\n\nstruct uf_min{\n \
    \   constexpr static int inf=1<<30;\n    std::vector<int>par,mn,mnid;\n    uf_min(int\
    \ v){\n        par.resize(v);\n        mn.resize(v,inf);\n        mnid.resize(v);\n\
    \        iota(par.begin(),par.end(),0);\n        iota(mnid.begin(),mnid.end(),0);\n\
    \    }\n    int find(int v){\n        if(par[v]==v)return v;\n        int r=find(par[v]);\n\
    \        if(mn[v]>mn[par[v]]){\n            mnid[v]=mnid[par[v]];\n          \
    \  mn[v]=mn[par[v]];\n        }\n        par[v]=r;\n        return r;\n    }\n\
    \    void set(int v,int x){\n        mn[v]=x;\n    }\n    int eval(int v){\n \
    \       find(v);\n        return mnid[v];\n    }\n    //x\u3092y\u306E\u89AA\u306B\
    \u3059\u308B\n    void link(int x,int y){\n        par[y]=x;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n\nstruct uf_min{\n    constexpr static int\
    \ inf=1<<30;\n    std::vector<int>par,mn,mnid;\n    uf_min(int v){\n        par.resize(v);\n\
    \        mn.resize(v,inf);\n        mnid.resize(v);\n        iota(par.begin(),par.end(),0);\n\
    \        iota(mnid.begin(),mnid.end(),0);\n    }\n    int find(int v){\n     \
    \   if(par[v]==v)return v;\n        int r=find(par[v]);\n        if(mn[v]>mn[par[v]]){\n\
    \            mnid[v]=mnid[par[v]];\n            mn[v]=mn[par[v]];\n        }\n\
    \        par[v]=r;\n        return r;\n    }\n    void set(int v,int x){\n   \
    \     mn[v]=x;\n    }\n    int eval(int v){\n        find(v);\n        return\
    \ mnid[v];\n    }\n    //x\u3092y\u306E\u89AA\u306B\u3059\u308B\n    void link(int\
    \ x,int y){\n        par[y]=x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu/uf_min.hpp
  requiredBy:
  - graph_tree/dominator_tree.hpp
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/uf_min.hpp
layout: document
redirect_from:
- /library/dsu/uf_min.hpp
- /library/dsu/uf_min.hpp.html
title: dsu/uf_min.hpp
---
