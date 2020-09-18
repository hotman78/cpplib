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
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O((E+V)logE)"
    links: []
  bundledCode: "#line 2 \"graph_tree/dijkstra.hpp\"\n#include<vector>\n#include<queue>\n\
    #include<functional>\n#include<tuple>\n#include<limits>\n#line 4 \"graph_tree/graph_template.hpp\"\
    \n#include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\ntemplate<typename\
    \ T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\ngraph load_graph(int\
    \ n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n  \
    \      std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n       \
    \ g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_digraph(int n,int m){\n\
    \    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 8 \"graph_tree/dijkstra.hpp\"\
    \n\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O((E+V)logE)\n */\n\n\
    template<typename T,typename F=std::less<T>>\nstd::vector<T> dijkstra(const graph_w<T>&\
    \ list,int s,T zero=0,T inf=std::numeric_limits<T>::max(),F f=F()){\n    std::priority_queue<std::pair<T,int>,std::vector<pair<T,int>>,std::greater<std::pair<T,int>>>que;\n\
    \    std::vector<T>diff(list.size(),inf);\n    diff[s]=zero;\n    que.push(make_pair(T(),s));\n\
    \    while(!que.empty()){\n        auto d=que.top();\n        que.pop();\n   \
    \     T x;\n        int now;\n        tie(x,now)=d;\n        for(auto d2:list[now]){\n\
    \            T sa;\n            int to;\n            tie(to,sa)=d2;\n        \
    \    if(f(diff[now]+sa,diff[to])){\n                diff[to]=diff[now]+sa;\n \
    \               que.emplace(diff[to],to);\n            }\n        }\n    }\n \
    \   return diff;\n}\n\n"
  code: "#pragma once\n#include<vector>\n#include<queue>\n#include<functional>\n#include<tuple>\n\
    #include<limits>\n#include\"graph_template.hpp\"\n\n/**\n * @brief \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9 O((E+V)logE)\n */\n\ntemplate<typename T,typename F=std::less<T>>\n\
    std::vector<T> dijkstra(const graph_w<T>& list,int s,T zero=0,T inf=std::numeric_limits<T>::max(),F\
    \ f=F()){\n    std::priority_queue<std::pair<T,int>,std::vector<pair<T,int>>,std::greater<std::pair<T,int>>>que;\n\
    \    std::vector<T>diff(list.size(),inf);\n    diff[s]=zero;\n    que.push(make_pair(T(),s));\n\
    \    while(!que.empty()){\n        auto d=que.top();\n        que.pop();\n   \
    \     T x;\n        int now;\n        tie(x,now)=d;\n        for(auto d2:list[now]){\n\
    \            T sa;\n            int to;\n            tie(to,sa)=d2;\n        \
    \    if(f(diff[now]+sa,diff[to])){\n                diff[to]=diff[now]+sa;\n \
    \               que.emplace(diff[to],to);\n            }\n        }\n    }\n \
    \   return diff;\n}\n\n"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-09-18 20:41:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/dijkstra.hpp
layout: document
redirect_from:
- /library/graph_tree/dijkstra.hpp
- /library/graph_tree/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O((E+V)logE)"
---
