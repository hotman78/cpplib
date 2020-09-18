---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6839\u304B\u3089\u306E\u6DF1\u3055"
    links: []
  bundledCode: "#line 2 \"graph_tree/depth.hpp\"\n#include<vector>\n#include<cmath>\n\
    #line 3 \"graph_tree/graph_template.hpp\"\n#include<iostream>\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\n\
    template<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>;\n\
    \ngraph load_graph(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n\
    \        int s,t;\n        std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n}\ngraph load_digraph(int n,int m){\n    graph\
    \ g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n    }\n}\ngraph load_graph0(int\
    \ n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n  \
    \      std::cin>>s>>t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n\
    \    }\n}\ngraph load_digraph0(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n\
    \        int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n    }\n\
    }\ngraph load_tree(int n){\n    graph g(n);\n    for(int i=0;i<n-1;++i){\n   \
    \     int s,t;\n        std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n}\ngraph load_tree1(int n){\n    graph g(n);\n\
    \    for(int i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n    \
    \    --s;--t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n    }\n\
    }\ngraph load_treep(int n){\n    graph g(n);\n    for(int i=0;i<n-1;++i){\n  \
    \      int t;\n        std::cin>>t;\n        g[i+1].push_back(t);\n        g[t].push_back(i+1);\n\
    \    }\n}\n\ntemplate<typename T>\ngraph_w<T> load_graph_weight(int n,int m){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T\
    \ u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n}\ntemplate<typename T>\ngraph_w<T> load_digraph_weight(int\
    \ n,int m){\n    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n\
    \        T u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \    }\n}\ntemplate<typename T>\ngraph_w<T> load_graph0_weight(int n,int m){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T\
    \ u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n        g[t].emplace_back(s,u);\n\
    \    }\n}\ntemplate<typename T>\ngraph_w<T> load_digraph0_weight(int n,int m){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T\
    \ u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n    }\n}\n\
    template<typename T>\ngraph_w<T> load_tree_weight(int n){\n    graph_w<T> g(n);\n\
    \    for(int i=0;i<n-1;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        --s;--t;\n        g[s].emplace_back(t,u);\n        g[t].emplace_back(s,u);\n\
    \    }\n}\ntemplate<typename T>\ngraph_w<T> load_tree1_weight(int n){\n    graph_w<T>\
    \ g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n        T u;\n       \
    \ std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n    \
    \    g[t].emplace_back(s,u);\n    }\n}\ntemplate<typename T>\ngraph_w<T> load_treep_weight(int\
    \ n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n        int t;\n   \
    \     T u;\n        std::cin>>t>>u;\n        g[i+1].emplace_back(t,u);\n     \
    \   g[t].emplace_back(i+1,u);\n    }\n}\n#line 5 \"graph_tree/depth.hpp\"\n\n\
    /**\n * @brief \u6839\u304B\u3089\u306E\u6DF1\u3055\n */\n\nstd::vector<int> depth(int\
    \ start,const graph& g){\n\tstd::vector<int>memo(g.size());\n\tauto f=[&](auto\
    \ f,int v,int p)->int{\n\t\tT mx=0;\n\t\tfor(auto t:g[v]){\n\t\t\tif(t==p)continue;\n\
    \t\t\tmx=std::max(mx,f(f,t,v));\n\t\t}\n\t\treturn memo[v]=mx+1;\n\t};\n\tf(f,start,-1);\n\
    \treturn memo;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<cmath>\n#include\"graph_template.hpp\"\
    \n\n/**\n * @brief \u6839\u304B\u3089\u306E\u6DF1\u3055\n */\n\nstd::vector<int>\
    \ depth(int start,const graph& g){\n\tstd::vector<int>memo(g.size());\n\tauto\
    \ f=[&](auto f,int v,int p)->int{\n\t\tT mx=0;\n\t\tfor(auto t:g[v]){\n\t\t\t\
    if(t==p)continue;\n\t\t\tmx=std::max(mx,f(f,t,v));\n\t\t}\n\t\treturn memo[v]=mx+1;\n\
    \t};\n\tf(f,start,-1);\n\treturn memo;\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/depth.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/depth.hpp
layout: document
redirect_from:
- /library/graph_tree/depth.hpp
- /library/graph_tree/depth.hpp.html
title: "\u6839\u304B\u3089\u306E\u6DF1\u3055"
---
