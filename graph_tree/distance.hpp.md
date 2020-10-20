---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph_tree/distance.hpp\"\nstd::vector<int> distance(const\
    \ graph& G,int start){\n    std::vector<int>memo(G.size());\n    auto f=[&](auto\
    \ f,int v,int p,int i)->void{\n        for(auto t:G[v]){\n            if(t==p)continue;\n\
    \            f(f,t,v,i+1);\n        }\n        memo[v]=i;\n    };\n    f(f,start,-1,0);\n\
    \    return memo;\n}\n"
  code: "std::vector<int> distance(const graph& G,int start){\n    std::vector<int>memo(G.size());\n\
    \    auto f=[&](auto f,int v,int p,int i)->void{\n        for(auto t:G[v]){\n\
    \            if(t==p)continue;\n            f(f,t,v,i+1);\n        }\n       \
    \ memo[v]=i;\n    };\n    f(f,start,-1,0);\n    return memo;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/distance.hpp
  requiredBy:
  - graph_tree/lca.hpp
  timestamp: '2020-09-19 09:30:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_lca.test.cpp
documentation_of: graph_tree/distance.hpp
layout: document
redirect_from:
- /library/graph_tree/distance.hpp
- /library/graph_tree/distance.hpp.html
title: graph_tree/distance.hpp
---
