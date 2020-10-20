---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u90E8\u5206\u6728\u306E\u5927\u304D\u3055"
    links: []
  bundledCode: "#line 2 \"graph_tree/child_size.hpp\"\n#include<vector>\n#include<cmath>\n\
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
    \ g;}\n#line 5 \"graph_tree/child_size.hpp\"\n\n/**\n * @brief \u90E8\u5206\u6728\
    \u306E\u5927\u304D\u3055\n */\n\nstd::vector<int> child_size(int start,const graph&\
    \ g){\n\tstd::vector<int>memo(g.size());\n\tauto f=[&](auto f,int v,int p)->int{\n\
    \t\tT res=0;\n\t\tfor(auto t:g[v]){\n\t\t\tif(t==p)continue;\n\t\t\tres+=f(f,t,v);\n\
    \t\t}\n\t\treturn memo[v]=res+1;\n\t};\n\tf(f,start,-1);\n\treturn memo;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<cmath>\n#include\"graph_template.hpp\"\
    \n\n/**\n * @brief \u90E8\u5206\u6728\u306E\u5927\u304D\u3055\n */\n\nstd::vector<int>\
    \ child_size(int start,const graph& g){\n\tstd::vector<int>memo(g.size());\n\t\
    auto f=[&](auto f,int v,int p)->int{\n\t\tT res=0;\n\t\tfor(auto t:g[v]){\n\t\t\
    \tif(t==p)continue;\n\t\t\tres+=f(f,t,v);\n\t\t}\n\t\treturn memo[v]=res+1;\n\t\
    };\n\tf(f,start,-1);\n\treturn memo;\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/child_size.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/child_size.hpp
layout: document
redirect_from:
- /library/graph_tree/child_size.hpp
- /library/graph_tree/child_size.hpp.html
title: "\u90E8\u5206\u6728\u306E\u5927\u304D\u3055"
---
