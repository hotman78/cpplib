---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph_tree/child_size.hpp
    title: "\u90E8\u5206\u6728\u306E\u5927\u304D\u3055"
  - icon: ':heavy_check_mark:'
    path: graph_tree/depth.hpp
    title: "\u6839\u304B\u3089\u306E\u6DF1\u3055"
  - icon: ':heavy_check_mark:'
    path: graph_tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca_short.hpp
    title: "LCA(HL\u5206\u89E3)&amp;lt;O(N),O(logN)&amp;gt;"
  - icon: ':warning:'
    path: graph_tree/two_edge_connectivity.hpp
    title: "\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':warning:'
    path: graph_tree/euler_tour.hpp
    title: graph_tree/euler_tour.hpp
  - icon: ':warning:'
    path: graph_tree/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':warning:'
    path: graph_tree/two_sat.hpp
    title: 2-SAT
  - icon: ':heavy_check_mark:'
    path: graph_tree/dijkstra_fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)"
  - icon: ':heavy_check_mark:'
    path: graph_tree/dijkstra.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5 O((E+V)logE)"
  - icon: ':warning:'
    path: graph_tree/shortest_path_tree_dijkstra.hpp
    title: "\u6700\u77ED\u7D4C\u8DEF\u6728 O((E+V)logE)"
  - icon: ':heavy_check_mark:'
    path: graph_tree/maximum_independent_set.hpp
    title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca_short.test.cpp
    title: graph_tree/test/LC_lca_short.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_dijkstra.test.cpp
    title: graph_tree/test/LC_dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_maximum_independent_set.test.cpp
    title: graph_tree/test/LC_maximum_independent_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_dijkstra_fast.test.cpp
    title: graph_tree/test/LC_dijkstra_fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_dominator_tree.test.cpp
    title: graph_tree/test/LC_dominator_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 2 \"graph_tree/graph_template.hpp\"\n#include<vector>\n#include<tuple>\n\
    #include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\ntemplate<typename T>\n\
    using graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\ngraph load_graph(int\
    \ n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);g[t].push_back(s);}return\
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
    \ g;}\n"
  code: "#pragma once\n#include<vector>\n#include<tuple>\n#include<iostream>\n/**\n\
    \ * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing\
    \ graph=std::vector<std::vector<int>>;\ntemplate<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
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
    \ g;}"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/graph_template.hpp
  requiredBy:
  - graph_tree/child_size.hpp
  - graph_tree/depth.hpp
  - graph_tree/centroid_decomposition.hpp
  - graph_tree/lca.hpp
  - graph_tree/lca_short.hpp
  - graph_tree/two_edge_connectivity.hpp
  - graph_tree/euler_tour.hpp
  - graph_tree/scc.hpp
  - graph_tree/two_sat.hpp
  - graph_tree/dijkstra_fast.hpp
  - graph_tree/dijkstra.hpp
  - graph_tree/shortest_path_tree_dijkstra.hpp
  - graph_tree/maximum_independent_set.hpp
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_lca_short.test.cpp
  - graph_tree/test/LC_dijkstra.test.cpp
  - graph_tree/test/LC_maximum_independent_set.test.cpp
  - graph_tree/test/LC_lca.test.cpp
  - graph_tree/test/LC_dijkstra_fast.test.cpp
  - graph_tree/test/LC_centroid_decomposition.test.cpp
  - graph_tree/test/LC_dominator_tree.test.cpp
documentation_of: graph_tree/graph_template.hpp
layout: document
redirect_from:
- /library/graph_tree/graph_template.hpp
- /library/graph_tree/graph_template.hpp.html
title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---