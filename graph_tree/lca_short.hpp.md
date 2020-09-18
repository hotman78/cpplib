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
    document_title: "LCA(HL\u5206\u89E3)&amp;lt;O(N),O(logN)&amp;gt;"
    links: []
  bundledCode: "#line 2 \"graph_tree/lca_short.hpp\"\n#include<vector>\n#line 3 \"\
    graph_tree/graph_template.hpp\"\n#include<tuple>\n#include<iostream>\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing\
    \ graph=std::vector<std::vector<int>>;\ntemplate<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 4 \"graph_tree/lca_short.hpp\"\
    \n\n/**\n * @brief LCA(HL\u5206\u89E3)&amp;lt;O(N),O(logN)&amp;gt;\n */\n\nstruct\
    \ lca{\n    graph g;\n    std::vector<int>sz,in,out,nxt,par;\n    lca(const graph&\
    \ g,int s):g(g){\n        int n=g.size();\n        sz.resize(n,0);\n        in.resize(n,0);\n\
    \        out.resize(n,0);\n        nxt.resize(n,s);\n        par.resize(n,s);\n\
    \        dfs_sz(s,-1);\n        dfs_hld(s,-1);\n    }\n    void dfs_sz(int v,int\
    \ p) {\n        sz[v] = 1;\n        for(auto &u: g[v]) {\n            if(p==u)continue;\n\
    \            dfs_sz(u,v);\n            sz[v]+=sz[u];\n            if(sz[u]>sz[g[v][0]])std::swap(u,g[v][0]);\n\
    \        }\n    }\n    void dfs_hld(int v,int p) {\n        static int t=0;\n\
    \        in[v]=t++;\n        for(auto u: g[v]){\n            if(p==u)continue;\n\
    \            nxt[u]=(u==g[v][0]?nxt[v]:u);\n            par[u]=(u==g[v][0]?par[v]:v);\n\
    \            dfs_hld(u,v);\n        }\n        out[v] = t;\n    }\n    int query(int\
    \ s,int t){\n        while(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]])t=par[t];\n\
    \t\t\telse s=par[s];\n\t\t}\n        return sz[s]>sz[t]?s:t;\n    }\n    int distance(int\
    \ s,int t){\n\t\tint res=0;\n\t\twhile(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]]){\n\
    \t\t\t\tres+=in[t]-in[nxt[t]]+1;\n\t\t\t\tt=par[t];\n\t\t\t}\n\t\t\telse {\n\t\
    \t\t\tres+=in[s]-in[nxt[s]]+1;\n\t\t\t\ts=par[s];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res+std::abs(in[s]-in[t]);\n\t}\n};\n"
  code: "#pragma once\n#include<vector>\n#include\"graph_template.hpp\"\n\n/**\n *\
    \ @brief LCA(HL\u5206\u89E3)&amp;lt;O(N),O(logN)&amp;gt;\n */\n\nstruct lca{\n\
    \    graph g;\n    std::vector<int>sz,in,out,nxt,par;\n    lca(const graph& g,int\
    \ s):g(g){\n        int n=g.size();\n        sz.resize(n,0);\n        in.resize(n,0);\n\
    \        out.resize(n,0);\n        nxt.resize(n,s);\n        par.resize(n,s);\n\
    \        dfs_sz(s,-1);\n        dfs_hld(s,-1);\n    }\n    void dfs_sz(int v,int\
    \ p) {\n        sz[v] = 1;\n        for(auto &u: g[v]) {\n            if(p==u)continue;\n\
    \            dfs_sz(u,v);\n            sz[v]+=sz[u];\n            if(sz[u]>sz[g[v][0]])std::swap(u,g[v][0]);\n\
    \        }\n    }\n    void dfs_hld(int v,int p) {\n        static int t=0;\n\
    \        in[v]=t++;\n        for(auto u: g[v]){\n            if(p==u)continue;\n\
    \            nxt[u]=(u==g[v][0]?nxt[v]:u);\n            par[u]=(u==g[v][0]?par[v]:v);\n\
    \            dfs_hld(u,v);\n        }\n        out[v] = t;\n    }\n    int query(int\
    \ s,int t){\n        while(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]])t=par[t];\n\
    \t\t\telse s=par[s];\n\t\t}\n        return sz[s]>sz[t]?s:t;\n    }\n    int distance(int\
    \ s,int t){\n\t\tint res=0;\n\t\twhile(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]]){\n\
    \t\t\t\tres+=in[t]-in[nxt[t]]+1;\n\t\t\t\tt=par[t];\n\t\t\t}\n\t\t\telse {\n\t\
    \t\t\tres+=in[s]-in[nxt[s]]+1;\n\t\t\t\ts=par[s];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res+std::abs(in[s]-in[t]);\n\t}\n};"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/lca_short.hpp
  requiredBy: []
  timestamp: '2020-09-18 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/lca_short.hpp
layout: document
redirect_from:
- /library/graph_tree/lca_short.hpp
- /library/graph_tree/lca_short.hpp.html
title: "LCA(HL\u5206\u89E3)&amp;lt;O(N),O(logN)&amp;gt;"
---
