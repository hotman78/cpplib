---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/push_relabel.hpp
    title: "\u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221AE))"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_min_cost_flow.test.cpp
    title: graph_tree/test/LC_min_cost_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
    links: []
  bundledCode: "#line 2 \"graph_tree/min_cost_flow.hpp\"\n#include<vector>\n#include<queue>\n\
    #include<cmath>\n#line 5 \"graph_tree/push_relabel.hpp\"\n#include<tuple>\n\n\
    /**\n * @brief \u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221AE))\n */\ntemplate<typename\
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
    \       return f;\n    }\n};\n#line 6 \"graph_tree/min_cost_flow.hpp\"\n\n/**\n\
    \ * @brief \u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)\n */\n\n//Res\u306F\u7B54\
    \u3048\u304Clong long\u306E\u6700\u5927\u5024\u3092\u8D85\u3048\u308B\u6642\u7528\
    \ntemplate<typename T,typename Res=T>\nstruct min_cost_flow{\n    int v;\n   \
    \ Res ans=0;\n    struct edge{\n        int to;\n        T cap,cost,st;\n    \
    \    int rev;\n        bool is_rev,edge_rev;\n        int id;\n    };\n    push_relabel<T>\
    \ mf;\n    std::vector<T>p;\n    std::vector<vector<edge*>>e;//\u8FBA\u306E\u30AD\
    \u30E3\u30D1\u30B7\u30C6\u30A3\n    std::vector<T>d;//\u9802\u70B9\u306E\u30AD\
    \u30E3\u30D1\u30B7\u30C6\u30A3\n    std::queue<int>active;\n    std::vector<tuple<int,int,T,T,T>>edges;\n\
    \    T eps=1;\n    int idx=0;\n    std::vector<T>res;\n    min_cost_flow(int v):v(v),mf(v+2),p(v,0),e(v),d(v,0){}\n\
    \    void add_edge(int from,int to,T mn,T mx,T cost){\n        edges.emplace_back(from,to,mn,mx,cost);\n\
    \        res.push_back(0);\n        if(from==to){\n            if(cost<0)res[idx++]=mx,ans+=mx*cost;\n\
    \            else res[idx++]=mn,ans+=mn*cost;\n            return;\n        }\n\
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
    \        }\n        return ans;\n    }\n    bool ok(std::vector<T>b){\n      \
    \  T tmp=0,tmp2=0;\n        for(int i=0;i<v;++i){\n            if(d[i]+b[i]>=0){\n\
    \                mf.add_edge(v,i,d[i]+b[i]);\n                tmp2+=d[i]+b[i];\n\
    \            }\n            else{\n                mf.add_edge(i,v+1,-(d[i]+b[i]));\n\
    \                tmp+=-(d[i]+b[i]);\n            }\n        }\n        return\
    \ tmp==tmp2&&mf.run(v,v+1)==tmp;\n    }\n    Res run(int s,int t,T f){\n     \
    \   d[s]+=f;\n        d[t]-=f;\n        return flow();\n    }\n    Res run(std::vector<T>b){\n\
    \        for(int i=0;i<v;++i)d[i]+=b[i];\n        return flow();\n    }\n    std::vector<T>\
    \ flow_result(){\n        for(int i=0;i<v;i++)for(auto ed:e[i]){\n           \
    \ if(ed->is_rev)continue;\n            res[ed->id]=ed->st+e[ed->to][ed->rev]->cap*(ed->edge_rev?-1:1);\n\
    \        }\n        return res;\n    }\n    //flow_result\u3092\u6E21\u3059\n\
    \    std::vector<T>potential(const std::vector<T>& f){\n        std::vector<T>p(v,0);\n\
    \        std::vector<tuple<int,int,T>>g;\n        int idx=0;\n        for(auto\
    \ [from,to,mn,mx,cost]:edges){\n            if(mn<f[idx])g.emplace_back(to,from,-cost);\n\
    \            if(f[idx]<mx)g.emplace_back(from,to,cost);\n            idx++;\n\
    \        }\n        for(int i=0;i<v;++i)for(auto [s,t,c]:g){\n            p[t]=std::min(p[t],p[s]+c);\n\
    \        }\n        return p;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<queue>\n#include<cmath>\n#include\"\
    push_relabel.hpp\"\n\n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)\n\
    \ */\n\n//Res\u306F\u7B54\u3048\u304Clong long\u306E\u6700\u5927\u5024\u3092\u8D85\
    \u3048\u308B\u6642\u7528\ntemplate<typename T,typename Res=T>\nstruct min_cost_flow{\n\
    \    int v;\n    Res ans=0;\n    struct edge{\n        int to;\n        T cap,cost,st;\n\
    \        int rev;\n        bool is_rev,edge_rev;\n        int id;\n    };\n  \
    \  push_relabel<T> mf;\n    std::vector<T>p;\n    std::vector<vector<edge*>>e;//\u8FBA\
    \u306E\u30AD\u30E3\u30D1\u30B7\u30C6\u30A3\n    std::vector<T>d;//\u9802\u70B9\
    \u306E\u30AD\u30E3\u30D1\u30B7\u30C6\u30A3\n    std::queue<int>active;\n    std::vector<tuple<int,int,T,T,T>>edges;\n\
    \    T eps=1;\n    int idx=0;\n    std::vector<T>res;\n    min_cost_flow(int v):v(v),mf(v+2),p(v,0),e(v),d(v,0){}\n\
    \    void add_edge(int from,int to,T mn,T mx,T cost){\n        edges.emplace_back(from,to,mn,mx,cost);\n\
    \        res.push_back(0);\n        if(from==to){\n            if(cost<0)res[idx++]=mx,ans+=mx*cost;\n\
    \            else res[idx++]=mn,ans+=mn*cost;\n            return;\n        }\n\
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
    \        }\n        return ans;\n    }\n    bool ok(std::vector<T>b){\n      \
    \  T tmp=0,tmp2=0;\n        for(int i=0;i<v;++i){\n            if(d[i]+b[i]>=0){\n\
    \                mf.add_edge(v,i,d[i]+b[i]);\n                tmp2+=d[i]+b[i];\n\
    \            }\n            else{\n                mf.add_edge(i,v+1,-(d[i]+b[i]));\n\
    \                tmp+=-(d[i]+b[i]);\n            }\n        }\n        return\
    \ tmp==tmp2&&mf.run(v,v+1)==tmp;\n    }\n    Res run(int s,int t,T f){\n     \
    \   d[s]+=f;\n        d[t]-=f;\n        return flow();\n    }\n    Res run(std::vector<T>b){\n\
    \        for(int i=0;i<v;++i)d[i]+=b[i];\n        return flow();\n    }\n    std::vector<T>\
    \ flow_result(){\n        for(int i=0;i<v;i++)for(auto ed:e[i]){\n           \
    \ if(ed->is_rev)continue;\n            res[ed->id]=ed->st+e[ed->to][ed->rev]->cap*(ed->edge_rev?-1:1);\n\
    \        }\n        return res;\n    }\n    //flow_result\u3092\u6E21\u3059\n\
    \    std::vector<T>potential(const std::vector<T>& f){\n        std::vector<T>p(v,0);\n\
    \        std::vector<tuple<int,int,T>>g;\n        int idx=0;\n        for(auto\
    \ [from,to,mn,mx,cost]:edges){\n            if(mn<f[idx])g.emplace_back(to,from,-cost);\n\
    \            if(f[idx]<mx)g.emplace_back(from,to,cost);\n            idx++;\n\
    \        }\n        for(int i=0;i<v;++i)for(auto [s,t,c]:g){\n            p[t]=std::min(p[t],p[s]+c);\n\
    \        }\n        return p;\n    }\n};"
  dependsOn:
  - graph_tree/push_relabel.hpp
  isVerificationFile: false
  path: graph_tree/min_cost_flow.hpp
  requiredBy: []
  timestamp: '2020-09-24 16:21:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_min_cost_flow.test.cpp
documentation_of: graph_tree/min_cost_flow.hpp
layout: document
redirect_from:
- /library/graph_tree/min_cost_flow.hpp
- /library/graph_tree/min_cost_flow.hpp.html
title: "\u6700\u5C0F\u8CBB\u7528\u6D41(CostScaling)"
---
