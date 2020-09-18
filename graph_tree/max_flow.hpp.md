---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph_tree/min_cost_flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "max_flow(Dinic\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph_tree/max_flow.hpp\"\n#include<vector>\r\n#include<queue>\r\
    \n#include<cmath>\r\n\r\n/**\r\n * @brief max_flow(Dinic\u6CD5)\r\n */\r\n\r\n\
    template<typename T>\r\nstruct max_flow {\r\n    struct edge { T to, cap, rev;\
    \ };\r\n    int V;\r\n    vector<vector<edge>> G;\r\n    vector<int> itr, level;\r\
    \n\r\n    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }\r\n\r\n    void\
    \ add_edge(int from, int to, T cap) {\r\n        G[from].push_back((edge) {to,\
    \ cap, (int) G[to].size()});\r\n        G[to].push_back((edge) {from, 0, (int)\
    \ G[from].size()-1});\r\n    }\r\n\r\n    void bfs(int s) {\r\n        level.assign(V,-1);\r\
    \n        std::queue<int> q;\r\n        level[s] = 0; q.push(s);\r\n        while\
    \ (!q.empty()) {\r\n            int v = q.front(); q.pop();\r\n            for(auto\
    \ &e: G[v]){\r\n                if (e.cap > 0 and level[e.to] < 0) {\r\n     \
    \               level[e.to] = level[v] + 1;\r\n                    q.push(e.to);\r\
    \n                }\r\n            }\r\n        }\r\n    }\r\n\r\n    int dfs(int\
    \ v, int t,T f) {\r\n        if (v == t) return f;\r\n        for (int& i = itr[v];\
    \ i < (int) G[v].size(); ++i) {\r\n            edge& e = G[v][i];\r\n        \
    \    if (e.cap > 0 and level[v] < level[e.to]) {\r\n                int d = dfs(e.to,\
    \ t, std::min(f, e.cap));\r\n                if (d > 0) {\r\n                \
    \    e.cap -= d;\r\n                    G[e.to][e.rev].cap += d;\r\n         \
    \           return d;\r\n                }\r\n            }\r\n        }\r\n \
    \       return 0;\r\n    }\r\n\r\n    T run(int s, int t) {\r\n        T ret =\
    \ 0, f;\r\n        while (bfs(s), level[t] >= 0) {\r\n            itr.assign(V,0);\r\
    \n            while ((f = dfs(s, t, INF)) > 0) ret += f;\r\n        }\r\n    \
    \    return ret;\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include<vector>\r\n#include<queue>\r\n#include<cmath>\r\n\
    \r\n/**\r\n * @brief max_flow(Dinic\u6CD5)\r\n */\r\n\r\ntemplate<typename T>\r\
    \nstruct max_flow {\r\n    struct edge { T to, cap, rev; };\r\n    int V;\r\n\
    \    vector<vector<edge>> G;\r\n    vector<int> itr, level;\r\n\r\n    max_flow(int\
    \ V) : V(V) { G.assign(V,vector<edge>()); }\r\n\r\n    void add_edge(int from,\
    \ int to, T cap) {\r\n        G[from].push_back((edge) {to, cap, (int) G[to].size()});\r\
    \n        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});\r\n    }\r\
    \n\r\n    void bfs(int s) {\r\n        level.assign(V,-1);\r\n        std::queue<int>\
    \ q;\r\n        level[s] = 0; q.push(s);\r\n        while (!q.empty()) {\r\n \
    \           int v = q.front(); q.pop();\r\n            for(auto &e: G[v]){\r\n\
    \                if (e.cap > 0 and level[e.to] < 0) {\r\n                    level[e.to]\
    \ = level[v] + 1;\r\n                    q.push(e.to);\r\n                }\r\n\
    \            }\r\n        }\r\n    }\r\n\r\n    int dfs(int v, int t,T f) {\r\n\
    \        if (v == t) return f;\r\n        for (int& i = itr[v]; i < (int) G[v].size();\
    \ ++i) {\r\n            edge& e = G[v][i];\r\n            if (e.cap > 0 and level[v]\
    \ < level[e.to]) {\r\n                int d = dfs(e.to, t, std::min(f, e.cap));\r\
    \n                if (d > 0) {\r\n                    e.cap -= d;\r\n        \
    \            G[e.to][e.rev].cap += d;\r\n                    return d;\r\n   \
    \             }\r\n            }\r\n        }\r\n        return 0;\r\n    }\r\n\
    \r\n    T run(int s, int t) {\r\n        T ret = 0, f;\r\n        while (bfs(s),\
    \ level[t] >= 0) {\r\n            itr.assign(V,0);\r\n            while ((f =\
    \ dfs(s, t, INF)) > 0) ret += f;\r\n        }\r\n        return ret;\r\n    }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/max_flow.hpp
  requiredBy:
  - graph_tree/min_cost_flow.hpp
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/max_flow.hpp
layout: document
redirect_from:
- /library/graph_tree/max_flow.hpp
- /library/graph_tree/max_flow.hpp.html
title: "max_flow(Dinic\u6CD5)"
---
