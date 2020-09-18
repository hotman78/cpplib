---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: dsu/uf_min.hpp
    title: dsu/uf_min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u652F\u914D\u6728"
    links: []
  bundledCode: "#line 2 \"graph_tree/dominator_tree.hpp\"\n#include<vector>\n#include<stack>\n\
    #line 3 \"dsu/uf_min.hpp\"\n\nstruct uf_min{\n    constexpr static int inf=1<<30;\n\
    \    std::vector<int>par,mn,mnid;\n    uf_min(int v){\n        par.resize(v);\n\
    \        mn.resize(v,inf);\n        mnid.resize(v);\n        iota(par.begin(),par.end(),0);\n\
    \        iota(mnid.begin(),mnid.end(),0);\n    }\n    int find(int v){\n     \
    \   if(par[v]==v)return v;\n        int r=find(par[v]);\n        if(mn[v]>mn[par[v]]){\n\
    \            mnid[v]=mnid[par[v]];\n            mn[v]=mn[par[v]];\n        }\n\
    \        par[v]=r;\n        return r;\n    }\n    void set(int v,int x){\n   \
    \     mn[v]=x;\n    }\n    int eval(int v){\n        find(v);\n        return\
    \ mnid[v];\n    }\n    //x\u3092y\u306E\u89AA\u306B\u3059\u308B\n    void link(int\
    \ x,int y){\n        par[y]=x;\n    }\n};\n#line 5 \"graph_tree/dominator_tree.hpp\"\
    \n\n/**\n * @brief \u652F\u914D\u6728\n */\n\n// root\u304B\u3089v\u306B\u5411\
    \u304B\u3046\u969B\u306B\u7D76\u5BFE\u901A\u3089\u306A\u3044\u3068\u3044\u3051\
    \u306A\u3044\u9802\u70B9\u3092\n// v\u306E\u7956\u5148\u3068\u3059\u308B\u3088\
    \u3046\u306B\u6728\u3092\u69CB\u7BC9\u3059\u308B\nstd::vector<int> dominator_tree(std::vector<std::vector<int>>g,int\
    \ s){\n\tint n=g.size();\n\tstd::vector<std::vector<int>> rev_g(n);\n\tfor(int\
    \ i=0;i<n;++i){\n\t\tfor(auto e:g[i]){\n\t\t\trev_g[e].push_back(i);\n\t\t}\n\t\
    }\n\tstd::stack<int>stk;\n    std::vector<bool>used(n,0);\n    std::vector<int>id(n+1,n);\n\
    \    std::vector<int>id2(n+1,n);\n    std::vector<int>sdom(n,n);\n    std::vector<int>idom(n,n);\n\
    \    std::vector<std::vector<int>>ch(n);\n    sdom[s]=s;\n    int idx=0;\n   \
    \ stk.emplace(s);\n    while(!stk.empty()){\n        auto v=stk.top();\n     \
    \   stk.pop();\n        id2[v]=idx;\n        id[idx++]=v;\n        for(auto e:g[v]){\n\
    \            if(!used[e]){\n                ch[v].push_back(e);\n            \
    \    stk.emplace(e);\n                used[e]=1;\n            }\n        }\n \
    \   }\n    for(int i=0;i<n;++i){\n        int v=id[i];\n        if(v==n)continue;\n\
    \        if(v==s)continue;\n        for(auto e:rev_g[v]){\n            if(id2[e]<i){\n\
    \                if(id2[sdom[v]]>id2[e]){\n                    sdom[v]=e;\n  \
    \              }\n            }\n        }\n    }\n    uf_min uf(n);\n    std::vector<std::vector<int>>sdom_list(n+1);\n\
    \    std::vector<int>u(n,-1);\n    for(int i=n-1;i>=0;--i){\n        int v=id[i];\n\
    \        if(v==n)continue;\n        for(auto e:sdom_list[v]){\n            u[e]=uf.eval(e);\n\
    \        }\n        if(v==s)continue;\n        for(auto e:rev_g[v]){\n       \
    \     if(id2[e]<i)continue;\n            auto d=uf.eval(e);\n            if(id2[sdom[v]]>id2[sdom[d]])sdom[v]=sdom[d];\n\
    \        }\n        sdom_list[sdom[v]].push_back(v);\n        uf.set(v,id2[sdom[v]]);\n\
    \        for(auto e:ch[v]){\n            uf.link(v,e);\n        }\n    }\n   \
    \ for(int i=0;i<n;++i){\n        auto v=id[i];\n        if(v==n)continue;\n  \
    \      if(v==s){\n            idom[v]=v;\n            continue;\n        }\n \
    \       if(sdom[v]==sdom[u[v]])idom[v]=sdom[v];\n        else idom[v]=idom[u[v]];\n\
    \    }\n    for(int i=0;i<n;++i)if(idom[i]==n)idom[i]=-1;\n\treturn idom;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<stack>\n#include\"../dsu/uf_min.hpp\"\
    \n\n/**\n * @brief \u652F\u914D\u6728\n */\n\n// root\u304B\u3089v\u306B\u5411\
    \u304B\u3046\u969B\u306B\u7D76\u5BFE\u901A\u3089\u306A\u3044\u3068\u3044\u3051\
    \u306A\u3044\u9802\u70B9\u3092\n// v\u306E\u7956\u5148\u3068\u3059\u308B\u3088\
    \u3046\u306B\u6728\u3092\u69CB\u7BC9\u3059\u308B\nstd::vector<int> dominator_tree(std::vector<std::vector<int>>g,int\
    \ s){\n\tint n=g.size();\n\tstd::vector<std::vector<int>> rev_g(n);\n\tfor(int\
    \ i=0;i<n;++i){\n\t\tfor(auto e:g[i]){\n\t\t\trev_g[e].push_back(i);\n\t\t}\n\t\
    }\n\tstd::stack<int>stk;\n    std::vector<bool>used(n,0);\n    std::vector<int>id(n+1,n);\n\
    \    std::vector<int>id2(n+1,n);\n    std::vector<int>sdom(n,n);\n    std::vector<int>idom(n,n);\n\
    \    std::vector<std::vector<int>>ch(n);\n    sdom[s]=s;\n    int idx=0;\n   \
    \ stk.emplace(s);\n    while(!stk.empty()){\n        auto v=stk.top();\n     \
    \   stk.pop();\n        id2[v]=idx;\n        id[idx++]=v;\n        for(auto e:g[v]){\n\
    \            if(!used[e]){\n                ch[v].push_back(e);\n            \
    \    stk.emplace(e);\n                used[e]=1;\n            }\n        }\n \
    \   }\n    for(int i=0;i<n;++i){\n        int v=id[i];\n        if(v==n)continue;\n\
    \        if(v==s)continue;\n        for(auto e:rev_g[v]){\n            if(id2[e]<i){\n\
    \                if(id2[sdom[v]]>id2[e]){\n                    sdom[v]=e;\n  \
    \              }\n            }\n        }\n    }\n    uf_min uf(n);\n    std::vector<std::vector<int>>sdom_list(n+1);\n\
    \    std::vector<int>u(n,-1);\n    for(int i=n-1;i>=0;--i){\n        int v=id[i];\n\
    \        if(v==n)continue;\n        for(auto e:sdom_list[v]){\n            u[e]=uf.eval(e);\n\
    \        }\n        if(v==s)continue;\n        for(auto e:rev_g[v]){\n       \
    \     if(id2[e]<i)continue;\n            auto d=uf.eval(e);\n            if(id2[sdom[v]]>id2[sdom[d]])sdom[v]=sdom[d];\n\
    \        }\n        sdom_list[sdom[v]].push_back(v);\n        uf.set(v,id2[sdom[v]]);\n\
    \        for(auto e:ch[v]){\n            uf.link(v,e);\n        }\n    }\n   \
    \ for(int i=0;i<n;++i){\n        auto v=id[i];\n        if(v==n)continue;\n  \
    \      if(v==s){\n            idom[v]=v;\n            continue;\n        }\n \
    \       if(sdom[v]==sdom[u[v]])idom[v]=sdom[v];\n        else idom[v]=idom[u[v]];\n\
    \    }\n    for(int i=0;i<n;++i)if(idom[i]==n)idom[i]=-1;\n\treturn idom;\n}"
  dependsOn:
  - dsu/uf_min.hpp
  isVerificationFile: false
  path: graph_tree/dominator_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/dominator_tree.hpp
layout: document
redirect_from:
- /library/graph_tree/dominator_tree.hpp
- /library/graph_tree/dominator_tree.hpp.html
title: "\u652F\u914D\u6728"
---
