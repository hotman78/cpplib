---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph_tree/max_flow.hpp
    title: "max_flow(Dinic\u6CD5)"
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
    links: []
  bundledCode: "#line 2 \"graph_tree/min_cost_flow.hpp\"\n#include<vector>\n#include<queue>\n\
    #include<cmath>\n#line 5 \"graph_tree/max_flow.hpp\"\n\r\n/**\r\n * @brief max_flow(Dinic\u6CD5\
    )\r\n */\r\n\r\ntemplate<typename T>\r\nstruct max_flow {\r\n    struct edge {\
    \ T to, cap, rev; };\r\n    int V;\r\n    vector<vector<edge>> G;\r\n    vector<int>\
    \ itr, level;\r\n\r\n    max_flow(int V) : V(V) { G.assign(V,vector<edge>());\
    \ }\r\n\r\n    void add_edge(int from, int to, T cap) {\r\n        G[from].push_back((edge)\
    \ {to, cap, (int) G[to].size()});\r\n        G[to].push_back((edge) {from, 0,\
    \ (int) G[from].size()-1});\r\n    }\r\n\r\n    void bfs(int s) {\r\n        level.assign(V,-1);\r\
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
    \    return ret;\r\n    }\r\n};\n#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\
    \n/**\n * @brief Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [op](const maybe<T>& s,const maybe<T>&\
    \ t){\n        if(s.is_none())return t;\n        if(t.is_none())return s;\n  \
    \      return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 7 \"graph_tree/min_cost_flow.hpp\"\
    \n\n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)\n */\n\n//Res\u306F\
    \u7B54\u3048\u304Clong long\u306E\u6700\u5927\u5024\u3092\u8D85\u3048\u308B\u6642\
    \u7528\ntemplate<typename T,typename Res=T>\nstruct min_cost_flow{\n    int v;\n\
    \    constexpr static T inf=1LL<<60;\n    Res ans=0;\n    struct edge{\n     \
    \   int to;\n        T cap,cost,st;\n        int rev;\n        bool is_rev,edge_rev;\n\
    \        int id;\n    };\n    max_flow<T> mf;\n    std::vector<T>p;\n    std::vector<vector<edge*>>e;//\u8FBA\
    \u306E\u30AD\u30E3\u30D1\u30B7\u30C6\u30A3\n    std::vector<T>d;//\u9802\u70B9\
    \u306E\u30AD\u30E3\u30D1\u30B7\u30C6\u30A3\n    std::queue<int>active;\n    T\
    \ eps=1;\n    int idx=0;\n    std::vector<T>res;\n    min_cost_flow(int v):v(v),mf(v+2),p(v,0),e(v),d(v,0){}\n\
    \    void add_edge(int from,int to,T mn,T mx,T cost){\n        res.push_back(0);\n\
    \        if(from==to){\n            if(cost<0)res[idx++]=mx,ans+=mx*cost;\n  \
    \          else res[idx++]=mn,ans+=mn*cost;\n            return;\n        }\n\
    \        if(cost>=0){\n            e[from].push_back(new edge{to,mx-mn,cost*v,mn,(int)e[to].size(),0,0,idx});\n\
    \            e[to].push_back(new edge{from,0,-cost*v,mn,(int)e[from].size()-1,1,0,idx++});\n\
    \            ans+=mn*cost;\n            d[from]-=mn;d[to]+=mn;\n            eps=max(eps,cost*v*v);\n\
    \            mf.add_edge(from,to,mx-mn);\n        }\n        else{\n         \
    \   e[to].push_back(new edge{from,mx-mn,-cost*v,mx,(int)e[from].size(),0,1,idx});\n\
    \            e[from].push_back(new edge{to,0,cost*v,mx,(int)e[to].size()-1,1,1,idx++});\n\
    \            ans+=mx*cost;\n            d[from]-=mx;d[to]+=mx;\n            eps=max(eps,-cost*v*v);\n\
    \            mf.add_edge(to,from,mx-mn);\n        }\n    }\n    void add_edge(int\
    \ from,int to,T cap,T cost){\n        add_edge(from,to,T(),cap,cost);\n    }\n\
    \n    Res flow(){\n        for(;eps;eps>>=1){\n            for(int i=0;i<v;i++){\n\
    \                for(auto ed:e[i]){\n                    if(ed->is_rev)continue;\n\
    \                    if(ed->cost-p[i]+p[ed->to]<0){\n                        T\
    \ f=ed->cap;\n                        ed->cap-=f;\n                        d[i]-=f;\n\
    \                        d[ed->to]+=f;\n                        e[ed->to][ed->rev]->cap+=f;\n\
    \                    }\n                    if(ed->cost-p[i]+p[ed->to]>0){\n \
    \                       T f=-e[ed->to][ed->rev]->cap;\n                      \
    \  ed->cap-=f;\n                        d[i]-=f;\n                        d[ed->to]+=f;\n\
    \                        e[ed->to][ed->rev]->cap+=f;\n                    }\n\
    \                }\n            }\n            for(int i=0;i<v;i++)if(d[i]>0){active.emplace(i);}\n\
    \            while(!active.empty()){\n                int node=active.front();\n\
    \                active.pop();\n                if(d[node]<=0)continue;\n    \
    \            bool b=0;\n                for(auto ed:e[node]){\n              \
    \      if(!d[node])break;\n                    if(-eps<=ed->cost-p[node]+p[ed->to]&&ed->cost-p[node]+p[ed->to]<0){\n\
    \                        auto f=std::min(d[node],ed->cap);\n                 \
    \       if(!f)continue;\n                        ed->cap-=f;\n               \
    \         d[node]-=f;\n                        d[ed->to]+=f;\n               \
    \         e[ed->to][ed->rev]->cap+=f;\n                        if(d[ed->to]>0)active.emplace(ed->to);\n\
    \                        b=1;\n                    }\n                }\n    \
    \            if(d[node]>0)active.emplace(node);\n                if(!b)p[node]+=eps;\n\
    \            }\n        }\n        for(int i=0;i<v;i++)for(auto ed:e[i]){\n  \
    \          if(ed->is_rev)continue;\n            ans+=e[ed->to][ed->rev]->cap*(ed->cost/v);\n\
    \        }\n        return ans;\n    }\n    bool ok(vector<T>b){\n        T tmp=0,tmp2=0;\n\
    \        for(int i=0;i<v;++i){\n            if(d[i]+b[i]>=0){\n              \
    \  mf.add_edge(v,i,d[i]+b[i]);\n                tmp2+=d[i]+b[i];\n           \
    \ }\n            else{\n                mf.add_edge(i,v+1,-(d[i]+b[i]));\n   \
    \             tmp+=-(d[i]+b[i]);\n            }\n        }\n        return tmp==tmp2&&mf.run(v,v+1)==tmp;\n\
    \    }\n    maybe<Res> run(int s,int t,T f){\n        d[s]+=f;\n        d[t]-=f;\n\
    \        if(ok(d))return maybe<Res>(flow());\n        else maybe<Res>();\n   \
    \ }\n    maybe<Res> run(vector<T>b){\n        for(int i=0;i<v;++i)d[i]+=b[i];\n\
    \        if(ok(d))return maybe<Res>(flow());\n        else maybe<Res>();\n   \
    \ }\n    vector<T> flow_result(){\n        for(int i=0;i<v;i++)for(auto ed:e[i]){\n\
    \            if(ed->is_rev)continue;\n            res[ed->id]=ed->st+e[ed->to][ed->rev]->cap*(ed->edge_rev?-1:1);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<queue>\n#include<cmath>\n#include\"\
    max_flow.hpp\"\n#include\"../alga/maybe.hpp\"\n\n/**\n * @brief \u6700\u5C0F\u8CBB\
    \u7528\u6D41(CostScaling)\n */\n\n//Res\u306F\u7B54\u3048\u304Clong long\u306E\
    \u6700\u5927\u5024\u3092\u8D85\u3048\u308B\u6642\u7528\ntemplate<typename T,typename\
    \ Res=T>\nstruct min_cost_flow{\n    int v;\n    constexpr static T inf=1LL<<60;\n\
    \    Res ans=0;\n    struct edge{\n        int to;\n        T cap,cost,st;\n \
    \       int rev;\n        bool is_rev,edge_rev;\n        int id;\n    };\n   \
    \ max_flow<T> mf;\n    std::vector<T>p;\n    std::vector<vector<edge*>>e;//\u8FBA\
    \u306E\u30AD\u30E3\u30D1\u30B7\u30C6\u30A3\n    std::vector<T>d;//\u9802\u70B9\
    \u306E\u30AD\u30E3\u30D1\u30B7\u30C6\u30A3\n    std::queue<int>active;\n    T\
    \ eps=1;\n    int idx=0;\n    std::vector<T>res;\n    min_cost_flow(int v):v(v),mf(v+2),p(v,0),e(v),d(v,0){}\n\
    \    void add_edge(int from,int to,T mn,T mx,T cost){\n        res.push_back(0);\n\
    \        if(from==to){\n            if(cost<0)res[idx++]=mx,ans+=mx*cost;\n  \
    \          else res[idx++]=mn,ans+=mn*cost;\n            return;\n        }\n\
    \        if(cost>=0){\n            e[from].push_back(new edge{to,mx-mn,cost*v,mn,(int)e[to].size(),0,0,idx});\n\
    \            e[to].push_back(new edge{from,0,-cost*v,mn,(int)e[from].size()-1,1,0,idx++});\n\
    \            ans+=mn*cost;\n            d[from]-=mn;d[to]+=mn;\n            eps=max(eps,cost*v*v);\n\
    \            mf.add_edge(from,to,mx-mn);\n        }\n        else{\n         \
    \   e[to].push_back(new edge{from,mx-mn,-cost*v,mx,(int)e[from].size(),0,1,idx});\n\
    \            e[from].push_back(new edge{to,0,cost*v,mx,(int)e[to].size()-1,1,1,idx++});\n\
    \            ans+=mx*cost;\n            d[from]-=mx;d[to]+=mx;\n            eps=max(eps,-cost*v*v);\n\
    \            mf.add_edge(to,from,mx-mn);\n        }\n    }\n    void add_edge(int\
    \ from,int to,T cap,T cost){\n        add_edge(from,to,T(),cap,cost);\n    }\n\
    \n    Res flow(){\n        for(;eps;eps>>=1){\n            for(int i=0;i<v;i++){\n\
    \                for(auto ed:e[i]){\n                    if(ed->is_rev)continue;\n\
    \                    if(ed->cost-p[i]+p[ed->to]<0){\n                        T\
    \ f=ed->cap;\n                        ed->cap-=f;\n                        d[i]-=f;\n\
    \                        d[ed->to]+=f;\n                        e[ed->to][ed->rev]->cap+=f;\n\
    \                    }\n                    if(ed->cost-p[i]+p[ed->to]>0){\n \
    \                       T f=-e[ed->to][ed->rev]->cap;\n                      \
    \  ed->cap-=f;\n                        d[i]-=f;\n                        d[ed->to]+=f;\n\
    \                        e[ed->to][ed->rev]->cap+=f;\n                    }\n\
    \                }\n            }\n            for(int i=0;i<v;i++)if(d[i]>0){active.emplace(i);}\n\
    \            while(!active.empty()){\n                int node=active.front();\n\
    \                active.pop();\n                if(d[node]<=0)continue;\n    \
    \            bool b=0;\n                for(auto ed:e[node]){\n              \
    \      if(!d[node])break;\n                    if(-eps<=ed->cost-p[node]+p[ed->to]&&ed->cost-p[node]+p[ed->to]<0){\n\
    \                        auto f=std::min(d[node],ed->cap);\n                 \
    \       if(!f)continue;\n                        ed->cap-=f;\n               \
    \         d[node]-=f;\n                        d[ed->to]+=f;\n               \
    \         e[ed->to][ed->rev]->cap+=f;\n                        if(d[ed->to]>0)active.emplace(ed->to);\n\
    \                        b=1;\n                    }\n                }\n    \
    \            if(d[node]>0)active.emplace(node);\n                if(!b)p[node]+=eps;\n\
    \            }\n        }\n        for(int i=0;i<v;i++)for(auto ed:e[i]){\n  \
    \          if(ed->is_rev)continue;\n            ans+=e[ed->to][ed->rev]->cap*(ed->cost/v);\n\
    \        }\n        return ans;\n    }\n    bool ok(vector<T>b){\n        T tmp=0,tmp2=0;\n\
    \        for(int i=0;i<v;++i){\n            if(d[i]+b[i]>=0){\n              \
    \  mf.add_edge(v,i,d[i]+b[i]);\n                tmp2+=d[i]+b[i];\n           \
    \ }\n            else{\n                mf.add_edge(i,v+1,-(d[i]+b[i]));\n   \
    \             tmp+=-(d[i]+b[i]);\n            }\n        }\n        return tmp==tmp2&&mf.run(v,v+1)==tmp;\n\
    \    }\n    maybe<Res> run(int s,int t,T f){\n        d[s]+=f;\n        d[t]-=f;\n\
    \        if(ok(d))return maybe<Res>(flow());\n        else maybe<Res>();\n   \
    \ }\n    maybe<Res> run(vector<T>b){\n        for(int i=0;i<v;++i)d[i]+=b[i];\n\
    \        if(ok(d))return maybe<Res>(flow());\n        else maybe<Res>();\n   \
    \ }\n    vector<T> flow_result(){\n        for(int i=0;i<v;i++)for(auto ed:e[i]){\n\
    \            if(ed->is_rev)continue;\n            res[ed->id]=ed->st+e[ed->to][ed->rev]->cap*(ed->edge_rev?-1:1);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - graph_tree/max_flow.hpp
  - alga/maybe.hpp
  isVerificationFile: false
  path: graph_tree/min_cost_flow.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/min_cost_flow.hpp
layout: document
redirect_from:
- /library/graph_tree/min_cost_flow.hpp
- /library/graph_tree/min_cost_flow.hpp.html
title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
---
