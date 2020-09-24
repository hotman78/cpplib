---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6839\u304B\u3089\u306E\u6DF1\u3055"
    links: []
  bundledCode: "#line 2 \"graph_tree/depth.hpp\"\n#include<vector>\n#include<cmath>\n\
    #line 3 \"graph_tree/graph_template.hpp\"\n#include<tuple>\n#include<iostream>\n\
    /**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n\
    using graph=std::vector<std::vector<int>>;\ntemplate<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
    \ngraph load_graph(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_digraph(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);}return\
    \ g;}\ngraph load_graph0(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_digraph0(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;g[s].push_back(t);}return\
    \ g;}\ngraph load_tree(int n){graph g(n);for(int i=0;i<n-1;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_tree0(int n){graph g(n);for(int i=0;i<n-1;++i){int s,t;std::cin>>s>>t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_treep(int n){graph g(n);for(int i=0;i<n-1;++i){int t;std::cin>>t;g[i+1].push_back(t);g[t].push_back(i+1);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_graph_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;--s;--t;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_digraph_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;--s;--t;g[s].emplace_back(t,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_graph0_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_digraph0_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;g[s].emplace_back(t,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_tree_weight(int n){graph_w<T> g(n);for(int\
    \ i=0;i<n-1;++i){int s,t;T u;std::cin>>s>>t>>u;--s;--t;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_tree0_weight(int n){graph_w<T> g(n);for(int\
    \ i=0;i<n-1;++i){int s,t;T u;std::cin>>s>>t>>u;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_treep_weight(int n){graph_w<T> g(n);for(int\
    \ i=0;i<n-1;++i){int t;T u;std::cin>>t>>u;g[i+1].emplace_back(t,u);g[t].emplace_back(i+1,u);}return\
    \ g;}\n#line 5 \"graph_tree/depth.hpp\"\n\n/**\n * @brief \u6839\u304B\u3089\u306E\
    \u6DF1\u3055\n */\n\nstd::vector<int> depth(const graph& g,int start){\n\tstd::vector<int>memo(g.size());\n\
    \tauto f=[&](auto f,int v,int p)->int{\n\t\tint mx=0;\n\t\tfor(auto t:g[v]){\n\
    \t\t\tif(t==p)continue;\n\t\t\tmx=std::max(mx,f(f,t,v));\n\t\t}\n\t\treturn memo[v]=mx+1;\n\
    \t};\n\tf(f,start,-1);\n\treturn memo;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<cmath>\n#include\"graph_template.hpp\"\
    \n\n/**\n * @brief \u6839\u304B\u3089\u306E\u6DF1\u3055\n */\n\nstd::vector<int>\
    \ depth(const graph& g,int start){\n\tstd::vector<int>memo(g.size());\n\tauto\
    \ f=[&](auto f,int v,int p)->int{\n\t\tint mx=0;\n\t\tfor(auto t:g[v]){\n\t\t\t\
    if(t==p)continue;\n\t\t\tmx=std::max(mx,f(f,t,v));\n\t\t}\n\t\treturn memo[v]=mx+1;\n\
    \t};\n\tf(f,start,-1);\n\treturn memo;\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/depth.hpp
  requiredBy:
  - graph_tree/lca.hpp
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_lca.test.cpp
documentation_of: graph_tree/depth.hpp
layout: document
redirect_from:
- /library/graph_tree/depth.hpp
- /library/graph_tree/depth.hpp.html
title: "\u6839\u304B\u3089\u306E\u6DF1\u3055"
---
