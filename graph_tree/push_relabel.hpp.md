---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph_tree/min_cost_flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_min_cost_flow.test.cpp
    title: graph_tree/test/LC_min_cost_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_push_relabel.test.cpp
    title: graph_tree/test/LC_push_relabel.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221AE))"
    links: []
  bundledCode: "#line 2 \"graph_tree/push_relabel.hpp\"\n#include<vector>\n#include<cmath>\n\
    #include<queue>\n#include<tuple>\n\n/**\n * @brief \u6700\u5927\u6D41(push_relabel\u6CD5\
    O(V^2\u221AE))\n */\ntemplate<typename T>\nclass push_relabel{\n    int n;\n \
    \   T f=0;\n    using i64=long long;\n    struct edge{\n        int from,to,rev;\n\
    \        T flow,cap;\n    };\n    std::vector<i64>h,d;\n    std::vector<std::vector<edge*>>g;\n\
    \    std::vector<size_t>seen;\n    std::priority_queue<std::pair<i64,int>,std::vector<std::pair<i64,int>>,std::greater<std::pair<i64,int>>>que;\n\
    \    public:\n    push_relabel(int n):n(n){\n        h.resize(n,0);\n        d.resize(n,0);\n\
    \        g.resize(n);\n        seen.resize(n,0);\n    }\n    void add_edge(int\
    \ u,int v,T cap){\n        g[u].emplace_back(new edge{u,v,(int)g[v].size(),0,cap});\n\
    \        g[v].emplace_back(new edge{v,u,(int)g[u].size()-1,0,0});\n    }\n   \
    \ void push(edge* e){\n        int u=e->from,v=e->to;\n        i64 df=std::min(d[u],e->cap-e->flow);\n\
    \        e->flow+=df;\n        g[v][e->rev]->flow-=df;\n        d[u]-=df;\n  \
    \      d[v]+=df;\n        if(d[v]>0)que.emplace(h[v],v);\n        if(d[u]>0)que.emplace(h[u],u);\n\
    \    }\n    void relabel(int u){\n        i64 mn=n*2;\n        for(edge* e:g[u]){\n\
    \            if(e->cap-e->flow>0){\n                mn=std::min(mn,h[e->to]);\n\
    \            }\n        }\n        h[u]=1+mn;\n        que.emplace(h[u],u);\n\
    \    }\n    void discharge(int u){\n        while(d[u]>0){\n            if(seen[u]<g[u].size()){\n\
    \                edge* e=g[u][seen[u]];\n                if(e->cap-e->flow>0 &&\
    \ h[u]==h[e->to]+1){\n                    push(e);\n                }else{\n \
    \                   seen[u]+=1;\n                }\n            }else{\n     \
    \           relabel(u);\n                seen[u]=0;\n            }\n        }\n\
    \    }\n    T run(int s,int t){\n        h[s]=n;\n        for(auto e:g[s]){\n\
    \            d[s]+=e->cap;\n            push(e);\n        }\n        while(!que.empty()){\n\
    \            int u=que.top().second;\n            que.pop();\n            if(u==s||u==t)continue;\n\
    \            discharge(u);\n        }\n        for(auto e:g[s])f+=e->flow;\n \
    \       return f;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<cmath>\n#include<queue>\n#include<tuple>\n\
    \n/**\n * @brief \u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221AE))\n */\ntemplate<typename\
    \ T>\nclass push_relabel{\n    int n;\n    T f=0;\n    using i64=long long;\n\
    \    struct edge{\n        int from,to,rev;\n        T flow,cap;\n    };\n   \
    \ std::vector<i64>h,d;\n    std::vector<std::vector<edge*>>g;\n    std::vector<size_t>seen;\n\
    \    std::priority_queue<std::pair<i64,int>,std::vector<std::pair<i64,int>>,std::greater<std::pair<i64,int>>>que;\n\
    \    public:\n    push_relabel(int n):n(n){\n        h.resize(n,0);\n        d.resize(n,0);\n\
    \        g.resize(n);\n        seen.resize(n,0);\n    }\n    void add_edge(int\
    \ u,int v,T cap){\n        g[u].emplace_back(new edge{u,v,(int)g[v].size(),0,cap});\n\
    \        g[v].emplace_back(new edge{v,u,(int)g[u].size()-1,0,0});\n    }\n   \
    \ void push(edge* e){\n        int u=e->from,v=e->to;\n        i64 df=std::min(d[u],e->cap-e->flow);\n\
    \        e->flow+=df;\n        g[v][e->rev]->flow-=df;\n        d[u]-=df;\n  \
    \      d[v]+=df;\n        if(d[v]>0)que.emplace(h[v],v);\n        if(d[u]>0)que.emplace(h[u],u);\n\
    \    }\n    void relabel(int u){\n        i64 mn=n*2;\n        for(edge* e:g[u]){\n\
    \            if(e->cap-e->flow>0){\n                mn=std::min(mn,h[e->to]);\n\
    \            }\n        }\n        h[u]=1+mn;\n        que.emplace(h[u],u);\n\
    \    }\n    void discharge(int u){\n        while(d[u]>0){\n            if(seen[u]<g[u].size()){\n\
    \                edge* e=g[u][seen[u]];\n                if(e->cap-e->flow>0 &&\
    \ h[u]==h[e->to]+1){\n                    push(e);\n                }else{\n \
    \                   seen[u]+=1;\n                }\n            }else{\n     \
    \           relabel(u);\n                seen[u]=0;\n            }\n        }\n\
    \    }\n    T run(int s,int t){\n        h[s]=n;\n        for(auto e:g[s]){\n\
    \            d[s]+=e->cap;\n            push(e);\n        }\n        while(!que.empty()){\n\
    \            int u=que.top().second;\n            que.pop();\n            if(u==s||u==t)continue;\n\
    \            discharge(u);\n        }\n        for(auto e:g[s])f+=e->flow;\n \
    \       return f;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/push_relabel.hpp
  requiredBy:
  - graph_tree/min_cost_flow.hpp
  timestamp: '2020-09-19 19:17:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_push_relabel.test.cpp
  - graph_tree/test/LC_min_cost_flow.test.cpp
documentation_of: graph_tree/push_relabel.hpp
layout: document
redirect_from:
- /library/graph_tree/push_relabel.hpp
- /library/graph_tree/push_relabel.hpp.html
title: "\u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221AE))"
---
