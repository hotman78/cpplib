---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':warning:'
    path: graph_tree/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 2-SAT
    links: []
  bundledCode: "#line 2 \"graph_tree/two_sat.hpp\"\n#include<vector>\n#include<algorithm>\n\
    #line 3 \"graph_tree/scc.hpp\"\n#include<tuple>\n#line 4 \"graph_tree/graph_template.hpp\"\
    \n#include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\ntemplate<typename\
    \ T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\ngraph load_graph(int\
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
    \ g;}\n#line 6 \"graph_tree/scc.hpp\"\n\n/**\n * @brief \u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\n */\n\nstd::pair<std::vector<int>,graph> scc(const graph&\
    \ g){\n    int n=g.size();\n    std::vector<std::vector<int>>rev(n);\n    for(int\
    \ i=0;i<n;i++)for(auto e:g[i]){\n        rev[e].emplace_back(i);\n    }\n    int\
    \ idx=0;\n    std::vector<int>v(n,-1);\n    std::vector<bool>visited(n,0);\n \
    \   auto dfs=[&](auto dfs,int now)->void{\n        visited[now]=1;\n        for(auto\
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
    \    }\n    return {res,res2};\n}\n#line 6 \"graph_tree/two_sat.hpp\"\n\n/**\n\
    \ * @brief 2-SAT\n */\nstruct two_sat{\n    int n;\n    graph v;\n    std::vector<int>list;\n\
    \    graph g;\n    two_sat(int n):n(n){\n        v.resize(n*2);\n        list.resize(n*2,-1);\n\
    \    }\n    //add s==p&&t==q\n    void add_edge(int s,int t,bool p,bool q){\n\
    \        v[s+p*n].push_back(t+(1-q)*n);\n        v[t+q*n].push_back(s+(1-p)*n);\n\
    \    }\n    bool solve(){\n        static int scced=0;\n        static bool ans=1;\n\
    \        if(!scced){\n            scced=1;\n            tie(list,v)=scc(v);\n\
    \            for(int i=0;i<n;i++){\n                if(list[i]==list[i+n])ans=0;\n\
    \            }\n        }\n        return ans;\n    }\n    bool operator[](int\
    \ i){\n        return list[i]>list[i+n];\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\n#include\"scc.hpp\"\n\
    #include\"graph_template.hpp\"\n\n/**\n * @brief 2-SAT\n */\nstruct two_sat{\n\
    \    int n;\n    graph v;\n    std::vector<int>list;\n    graph g;\n    two_sat(int\
    \ n):n(n){\n        v.resize(n*2);\n        list.resize(n*2,-1);\n    }\n    //add\
    \ s==p&&t==q\n    void add_edge(int s,int t,bool p,bool q){\n        v[s+p*n].push_back(t+(1-q)*n);\n\
    \        v[t+q*n].push_back(s+(1-p)*n);\n    }\n    bool solve(){\n        static\
    \ int scced=0;\n        static bool ans=1;\n        if(!scced){\n            scced=1;\n\
    \            tie(list,v)=scc(v);\n            for(int i=0;i<n;i++){\n        \
    \        if(list[i]==list[i+n])ans=0;\n            }\n        }\n        return\
    \ ans;\n    }\n    bool operator[](int i){\n        return list[i]>list[i+n];\n\
    \    }\n};"
  dependsOn:
  - graph_tree/scc.hpp
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/two_sat.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/two_sat.hpp
layout: document
redirect_from:
- /library/graph_tree/two_sat.hpp
- /library/graph_tree/two_sat.hpp.html
title: 2-SAT
---
