---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"graph_tree/topological_sort.hpp\"\n#include<vector>\n#include<algorithm>\n\
    \n/**\n * @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n */\n\
    \nstd::vector<int>tsort(std::vector<std::vector<int>>G){\n\tstd::vector<int> in(G.size(),0);\n\
    \tstd::vector<int> vis(G.size(),0);\n\tstd::vector<int> res;\n\tfor(int i=0;i<(int)G.size();i++)for(int\
    \ j=0;j<(int)G[i].size();j++){\n\t\tin[G[i][j]]++;\n\t}\n\tfor(int i=0;i<(int)G.size();++i){\n\
    \t\tauto dfs=[&](auto dfs,int v)->void{\n\t\t\tvis[v]=1;\n\t\t\tres.push_back(v);\n\
    \t\t\tfor(auto e:G[v]){\n\t\t\t\tin[e]--;\n\t\t\t\tif(in[e]==0)dfs(dfs,e);\n\t\
    \t\t}\n\t\t};\n\t\tif(vis[i]==0&&in[i]==0)dfs(dfs,i);\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\n\n/**\n * @brief \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n */\n\nstd::vector<int>tsort(std::vector<std::vector<int>>G){\n\
    \tstd::vector<int> in(G.size(),0);\n\tstd::vector<int> vis(G.size(),0);\n\tstd::vector<int>\
    \ res;\n\tfor(int i=0;i<(int)G.size();i++)for(int j=0;j<(int)G[i].size();j++){\n\
    \t\tin[G[i][j]]++;\n\t}\n\tfor(int i=0;i<(int)G.size();++i){\n\t\tauto dfs=[&](auto\
    \ dfs,int v)->void{\n\t\t\tvis[v]=1;\n\t\t\tres.push_back(v);\n\t\t\tfor(auto\
    \ e:G[v]){\n\t\t\t\tin[e]--;\n\t\t\t\tif(in[e]==0)dfs(dfs,e);\n\t\t\t}\n\t\t};\n\
    \t\tif(vis[i]==0&&in[i]==0)dfs(dfs,i);\n\t}\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/topological_sort.hpp
layout: document
redirect_from:
- /library/graph_tree/topological_sort.hpp
- /library/graph_tree/topological_sort.hpp.html
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
