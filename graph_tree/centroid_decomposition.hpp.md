---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u91CD\u5FC3\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph_tree/centroid_decomposition.hpp\"\n#include<vector>\n\
    #line 3 \"graph_tree/graph_template.hpp\"\n#include<tuple>\n#include<iostream>\n\
    /**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n\
    using graph=std::vector<std::vector<int>>;\ntemplate<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
    \ngraph load_graph(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n\
    \        int s,t;\n        std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_digraph(int n,int\
    \ m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n    }\n    return g;\n}\ngraph\
    \ load_graph0(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n    \
    \    int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n\
    \    }\n    return g;\n}\ngraph load_digraph0(int n,int m){\n    graph g(n);\n\
    \    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n      \
    \  g[s].push_back(t);\n    }\n    return g;\n}\ngraph load_tree(int n){\n    graph\
    \ g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n  \
    \  }\n    return g;\n}\ngraph load_tree0(int n){\n    graph g(n);\n    for(int\
    \ i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_treep(int n){\n\
    \    graph g(n);\n    for(int i=0;i<n-1;++i){\n        int t;\n        std::cin>>t;\n\
    \        g[i+1].push_back(t);\n        g[t].push_back(i+1);\n    }\n    return\
    \ g;\n}\n\ntemplate<typename T>\ngraph_w<T> load_graph_weight(int n,int m){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T\
    \ u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_digraph_weight(int n,int m){\n    graph_w<T> g(n);\n    for(int\
    \ i=0;i<m;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        --s;--t;\n        g[s].emplace_back(t,u);\n    }\n    return g;\n}\n\
    template<typename T>\ngraph_w<T> load_graph0_weight(int n,int m){\n    graph_w<T>\
    \ g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        g[s].emplace_back(t,u);\n        g[t].emplace_back(s,u);\n    }\n   \
    \ return g;\n}\ntemplate<typename T>\ngraph_w<T> load_digraph0_weight(int n,int\
    \ m){\n    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n   \
    \     T u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n    }\n\
    \    return g;\n}\ntemplate<typename T>\ngraph_w<T> load_tree_weight(int n){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n       \
    \ T u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_tree0_weight(int n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n\
    \        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_treep_weight(int n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n\
    \        int t;\n        T u;\n        std::cin>>t>>u;\n        g[i+1].emplace_back(t,u);\n\
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 4 \"graph_tree/centroid_decomposition.hpp\"\
    \n\n/**\n * @brief \u91CD\u5FC3\u5206\u89E3\n */\n\nclass centroid_decomposition{\n\
    \    graph g;\n    std::vector<int>used;\n    std::vector<int>v;\n    graph ch;\n\
    \    int s;\n    int dfs(int n,int p,int sz,int root){\n        if(used[n])return\
    \ 0;\n        bool b=1;\n        int res=1;\n        for(auto e:g[n]){\n     \
    \       if(p==e)continue;\n            auto t=dfs(e,n,sz,root);\n            res+=t;\n\
    \            if(t>sz/2)b=0;\n        }\n        if(!b||sz-res>sz/2)return res;\n\
    \        if(root!=-1)ch[root].push_back(n);\n        else s=n;\n        v.push_back(n);\n\
    \        used[n]=1;\n        for(auto e:g[n]){\n            dfs(e,n,dfs(e,n,g.size()*2,n),n);\n\
    \        }\n        return g.size()*2;\n    }\n    public:\n    centroid_decomposition(const\
    \ graph&g):g(g){\n        int n=g.size();\n        used.resize(n);\n        ch.resize(n);\n\
    \        dfs(0,-1,n,-1);\n    }\n\n    int get_root(){return s;}\n    std::vector<int>\
    \ operator[](int i){return ch[i];}\n    std::vector<int> get_euler_tour(){return\
    \ v;}\n};\n"
  code: "#pragma once\n#include<vector>\n#include\"graph_template.hpp\"\n\n/**\n *\
    \ @brief \u91CD\u5FC3\u5206\u89E3\n */\n\nclass centroid_decomposition{\n    graph\
    \ g;\n    std::vector<int>used;\n    std::vector<int>v;\n    graph ch;\n    int\
    \ s;\n    int dfs(int n,int p,int sz,int root){\n        if(used[n])return 0;\n\
    \        bool b=1;\n        int res=1;\n        for(auto e:g[n]){\n          \
    \  if(p==e)continue;\n            auto t=dfs(e,n,sz,root);\n            res+=t;\n\
    \            if(t>sz/2)b=0;\n        }\n        if(!b||sz-res>sz/2)return res;\n\
    \        if(root!=-1)ch[root].push_back(n);\n        else s=n;\n        v.push_back(n);\n\
    \        used[n]=1;\n        for(auto e:g[n]){\n            dfs(e,n,dfs(e,n,g.size()*2,n),n);\n\
    \        }\n        return g.size()*2;\n    }\n    public:\n    centroid_decomposition(const\
    \ graph&g):g(g){\n        int n=g.size();\n        used.resize(n);\n        ch.resize(n);\n\
    \        dfs(0,-1,n,-1);\n    }\n\n    int get_root(){return s;}\n    std::vector<int>\
    \ operator[](int i){return ch[i];}\n    std::vector<int> get_euler_tour(){return\
    \ v;}\n};"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2020-09-18 20:41:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_centroid_decomposition.test.cpp
documentation_of: graph_tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph_tree/centroid_decomposition.hpp
- /library/graph_tree/centroid_decomposition.hpp.html
title: "\u91CD\u5FC3\u5206\u89E3"
---
