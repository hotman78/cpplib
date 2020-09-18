---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph_tree/two_sat.hpp
    title: 2-SAT
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"graph_tree/scc.hpp\"\n#include<vector>\n#include<tuple>\n\
    #include<algorithm>\n#line 4 \"graph_tree/graph_template.hpp\"\n#include<iostream>\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 6 \"graph_tree/scc.hpp\"\
    \n\n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n */\n\nstd::pair<std::vector<int>,graph>\
    \ scc(const graph& g){\n    int n=g.size();\n    std::vector<std::vector<int>>rev(n);\n\
    \    for(int i=0;i<n;i++)for(auto e:g[i]){\n        rev[e].emplace_back(i);\n\
    \    }\n    int idx=0;\n    std::vector<int>v(n,-1);\n    std::vector<bool>visited(n,0);\n\
    \    auto dfs=[&](auto dfs,int now)->void{\n        visited[now]=1;\n        for(auto\
    \ e:g[now]){\n            if(!visited[e])dfs(dfs,e);\n        }\n        v[idx++]=now;\n\
    \    };\n    for(int i=0;i<n;i++){\n        if(!visited[i])dfs(dfs,i);\n    }\n\
    \    idx=-1;\n    std::vector<int>res(n,-1);\n    auto rdfs=[&](auto rdfs,int\
    \ now)->void{\n        for(auto e:rev[now]){\n            if(res[e]==-1)res[e]=idx,rdfs(rdfs,e);\n\
    \        }\n    };\n    for(int i=n-1;i>=0;--i){\n        if(res[v[i]]==-1){\n\
    \            res[v[i]]=++idx;\n            rdfs(rdfs,v[i]);\n        }\n    }\n\
    \    idx++;\n    std::vector<std::vector<int>>res2(idx);\n    for(int i=0;i<n;i++)for(auto\
    \ e:g[i]){\n        if(res[i]==res[e])continue;\n        res2[res[i]].push_back(res[e]);\n\
    \    }\n    for(int i=0;i<idx;i++){\n        std::sort(res2[i].begin(),res2[i].end());\n\
    \        res2[i].erase(std::unique(res2[i].begin(),res2[i].end()),res2[i].end());\n\
    \    }\n    return {res,res2};\n}\n"
  code: "#pragma once\n#include<vector>\n#include<tuple>\n#include<algorithm>\n#include\"\
    graph_template.hpp\"\n\n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n */\n\nstd::pair<std::vector<int>,graph> scc(const graph& g){\n    int n=g.size();\n\
    \    std::vector<std::vector<int>>rev(n);\n    for(int i=0;i<n;i++)for(auto e:g[i]){\n\
    \        rev[e].emplace_back(i);\n    }\n    int idx=0;\n    std::vector<int>v(n,-1);\n\
    \    std::vector<bool>visited(n,0);\n    auto dfs=[&](auto dfs,int now)->void{\n\
    \        visited[now]=1;\n        for(auto e:g[now]){\n            if(!visited[e])dfs(dfs,e);\n\
    \        }\n        v[idx++]=now;\n    };\n    for(int i=0;i<n;i++){\n       \
    \ if(!visited[i])dfs(dfs,i);\n    }\n    idx=-1;\n    std::vector<int>res(n,-1);\n\
    \    auto rdfs=[&](auto rdfs,int now)->void{\n        for(auto e:rev[now]){\n\
    \            if(res[e]==-1)res[e]=idx,rdfs(rdfs,e);\n        }\n    };\n    for(int\
    \ i=n-1;i>=0;--i){\n        if(res[v[i]]==-1){\n            res[v[i]]=++idx;\n\
    \            rdfs(rdfs,v[i]);\n        }\n    }\n    idx++;\n    std::vector<std::vector<int>>res2(idx);\n\
    \    for(int i=0;i<n;i++)for(auto e:g[i]){\n        if(res[i]==res[e])continue;\n\
    \        res2[res[i]].push_back(res[e]);\n    }\n    for(int i=0;i<idx;i++){\n\
    \        std::sort(res2[i].begin(),res2[i].end());\n        res2[i].erase(std::unique(res2[i].begin(),res2[i].end()),res2[i].end());\n\
    \    }\n    return {res,res2};\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/scc.hpp
  requiredBy:
  - graph_tree/two_sat.hpp
  timestamp: '2020-09-18 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/scc.hpp
layout: document
redirect_from:
- /library/graph_tree/scc.hpp
- /library/graph_tree/scc.hpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
