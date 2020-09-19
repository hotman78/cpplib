---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
  requiredBy: []
  timestamp: '2020-09-19 09:30:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/distance.hpp
layout: document
redirect_from:
- /library/graph_tree/distance.hpp
- /library/graph_tree/distance.hpp.html
title: graph_tree/distance.hpp
---
