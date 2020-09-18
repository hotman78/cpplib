---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)"
    links: []
  bundledCode: "#line 2 \"graph_tree/fast_dijkstra.hpp\"\n#include<vector>\n#include<tuple>\n\
    #include<functional>\n#include<ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/priority_queue.hpp>\n\
    #line 4 \"graph_tree/graph_template.hpp\"\n#include<iostream>\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\n\
    template<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 8 \"graph_tree/fast_dijkstra.hpp\"\
    \n\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)\n */\n\ntemplate<typename\
    \ T,typename Add=std::plus<T>,typename F=std::less<T>>\nstd::vector<T> dijkstra(const\
    \ graph_w<T>&v,int s,const T& zero,const T& inf,F f=F(),Add add=Add()){\n    int\
    \ n=v.size();\n    std::vector<T> ans(std::vector<T>(n,inf));\n    ans[s]=zero;\n\
    \    auto cmp=[&f](auto s,auto t){return f(t.first,s.first);};\n    using pq_t=__gnu_pbds::priority_queue<std::pair<T,int>,decltype(cmp),__gnu_pbds::pairing_heap_tag>;\n\
    \    pq_t que(cmp);\n    typename pq_t::point_iterator node[n];\n    for(int i=0;i<n;i++)node[i]=que.push(make_pair(inf,i));\n\
    \    que.modify(node[s],make_pair(zero,s));\n    while(!que.empty()){\n      \
    \  T p;\n        int now;\n        tie(p,now)=que.top();\n        que.pop();\n\
    \        for(auto d:v[now]){\n            auto next=add(p,d.second);\n       \
    \     if(f(next,ans[d.first])){\n\t\t\t\tans[d.first]=next;\n\t\t\t\tque.modify(node[d.first],make_pair(next,d.first));\n\
    \t\t\t}\n        }\n    }\n\treturn ans;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<tuple>\n#include<functional>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/priority_queue.hpp>\n#include\"graph_template.hpp\"\n\n/**\n\
    \ * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)\n */\n\ntemplate<typename\
    \ T,typename Add=std::plus<T>,typename F=std::less<T>>\nstd::vector<T> dijkstra(const\
    \ graph_w<T>&v,int s,const T& zero,const T& inf,F f=F(),Add add=Add()){\n    int\
    \ n=v.size();\n    std::vector<T> ans(std::vector<T>(n,inf));\n    ans[s]=zero;\n\
    \    auto cmp=[&f](auto s,auto t){return f(t.first,s.first);};\n    using pq_t=__gnu_pbds::priority_queue<std::pair<T,int>,decltype(cmp),__gnu_pbds::pairing_heap_tag>;\n\
    \    pq_t que(cmp);\n    typename pq_t::point_iterator node[n];\n    for(int i=0;i<n;i++)node[i]=que.push(make_pair(inf,i));\n\
    \    que.modify(node[s],make_pair(zero,s));\n    while(!que.empty()){\n      \
    \  T p;\n        int now;\n        tie(p,now)=que.top();\n        que.pop();\n\
    \        for(auto d:v[now]){\n            auto next=add(p,d.second);\n       \
    \     if(f(next,ans[d.first])){\n\t\t\t\tans[d.first]=next;\n\t\t\t\tque.modify(node[d.first],make_pair(next,d.first));\n\
    \t\t\t}\n        }\n    }\n\treturn ans;\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/fast_dijkstra.hpp
  requiredBy: []
  timestamp: '2020-09-18 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/fast_dijkstra.hpp
layout: document
redirect_from:
- /library/graph_tree/fast_dijkstra.hpp
- /library/graph_tree/fast_dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)"
---
