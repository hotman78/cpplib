---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u91CD\u5FC3\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph_tree/centroid_decomposition.hpp\"\n#include<vector>\n\
    \n/**\n * @brief \u91CD\u5FC3\u5206\u89E3\n */\n\ntemplate<typename T>\nstruct\
    \ centroid_decomposition{\n    std::vector<std::vector<T>>g;\n    std::vector<int>used;\n\
    \    std::vector<int>v;\n    std::vector<vector<int>>ch;\n    int s;\n    centroid_decomposition(const\
    \ vector<vector<T>>&g):g(g){\n        int n=g.size();\n        used.resize(n);\n\
    \        v.resize(n);\n        ch.resize(n);\n        dfs(0,-1,n,-1);\n    }\n\
    \    int dfs(int n,int p,int sz,int root){\n        if(used[n])return 0;\n   \
    \     bool b=1;\n        int res=1;\n        for(auto e:g[n]){\n            if(p==e)continue;\n\
    \            auto t=dfs(e,n,sz,root);\n            res+=t;\n            if(t>sz/2)b=0;\n\
    \        }\n        if(!b||sz-res>sz/2)return res;\n        if(root!=-1)ch[root].push_back(n);\n\
    \        else s=n;\n        v.push_back(n);\n        used[n]=1;\n        for(auto\
    \ e:g[n]){\n            dfs(e,n,dfs(e,n,g.size()*2,n),n);\n        }\n       \
    \ return g.size()*2;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n\n/**\n * @brief \u91CD\u5FC3\u5206\u89E3\
    \n */\n\ntemplate<typename T>\nstruct centroid_decomposition{\n    std::vector<std::vector<T>>g;\n\
    \    std::vector<int>used;\n    std::vector<int>v;\n    std::vector<vector<int>>ch;\n\
    \    int s;\n    centroid_decomposition(const vector<vector<T>>&g):g(g){\n   \
    \     int n=g.size();\n        used.resize(n);\n        v.resize(n);\n       \
    \ ch.resize(n);\n        dfs(0,-1,n,-1);\n    }\n    int dfs(int n,int p,int sz,int\
    \ root){\n        if(used[n])return 0;\n        bool b=1;\n        int res=1;\n\
    \        for(auto e:g[n]){\n            if(p==e)continue;\n            auto t=dfs(e,n,sz,root);\n\
    \            res+=t;\n            if(t>sz/2)b=0;\n        }\n        if(!b||sz-res>sz/2)return\
    \ res;\n        if(root!=-1)ch[root].push_back(n);\n        else s=n;\n      \
    \  v.push_back(n);\n        used[n]=1;\n        for(auto e:g[n]){\n          \
    \  dfs(e,n,dfs(e,n,g.size()*2,n),n);\n        }\n        return g.size()*2;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph_tree/centroid_decomposition.hpp
- /library/graph_tree/centroid_decomposition.hpp.html
title: "\u91CD\u5FC3\u5206\u89E3"
---
