---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"graph_tree/topological_sort.hpp\"\n#include<vector>\n#include<algorithm>\n\
    \n/**\n * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n */\n\
    \nstd::vector<int>tsort(std::vector<std::vector<int>>G){\n\tstd::vector<int> visited(G.size(),0);\n\
    \tstd::vector<int> start(G.size(),1);\n\tfor(int i=0;i<(int)G.size();i++)for(int\
    \ j=0;j<(int)G[i].size();j++){\n\t\tstart[G[i][j]]=0;\n\t}\n\tstd::vector<int>res(G.size());\n\
    \    int idx=0;\n\tauto f=[&](auto f,int v)->void{\n\t\tif(visited[v])return;\n\
    \t\tfor(auto t:G[v])f(f,t);\n\t\tres[idx++]=v;\n\t\tvisited[v]=1;\n\t};\n\tfor(int\
    \ i=0;i<(int)G.size();i++)if(start[i])f(f,i);\n\tstd::reverse(res.begin(),res.end());\n\
    \treturn res;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\n\n/**\n * @brief \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n */\n\nstd::vector<int>tsort(std::vector<std::vector<int>>G){\n\
    \tstd::vector<int> visited(G.size(),0);\n\tstd::vector<int> start(G.size(),1);\n\
    \tfor(int i=0;i<(int)G.size();i++)for(int j=0;j<(int)G[i].size();j++){\n\t\tstart[G[i][j]]=0;\n\
    \t}\n\tstd::vector<int>res(G.size());\n    int idx=0;\n\tauto f=[&](auto f,int\
    \ v)->void{\n\t\tif(visited[v])return;\n\t\tfor(auto t:G[v])f(f,t);\n\t\tres[idx++]=v;\n\
    \t\tvisited[v]=1;\n\t};\n\tfor(int i=0;i<(int)G.size();i++)if(start[i])f(f,i);\n\
    \tstd::reverse(res.begin(),res.end());\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/topological_sort.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/topological_sort.hpp
layout: document
redirect_from:
- /library/graph_tree/topological_sort.hpp
- /library/graph_tree/topological_sort.hpp.html
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
