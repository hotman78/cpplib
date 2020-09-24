---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: max_flow.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/min_cost_flow.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/min_cost_flow.hpp
layout: document
redirect_from:
- /library/graph_tree/min_cost_flow.hpp
- /library/graph_tree/min_cost_flow.hpp.html
title: graph_tree/min_cost_flow.hpp
---
