---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/lca
    - https://judge.yosupo.jp/submission/28297
  bundledCode: "#line 1 \"give_us_tmp/lca.cpp\"\n/**\n * LCA\n * \n * \u69CB\u7BC9\
    \ :O(N)\n * LCA :O(1)\n * \u8DDD\u96E2 :O(1)\n * \n * verified with    :https://judge.yosupo.jp/problem/lca\n\
    \ * submission       :https://judge.yosupo.jp/submission/28297\n */\n\nstruct\
    \ lca{\n    using graph=vector<vector<int>>;\n    graph g;\n    vector<int>sz,in,out,nxt,par;\n\
    \    lca(const graph& g,int s):g(g){\n        int n=g.size();\n        sz.resize(n,0);\n\
    \        in.resize(n,0);\n        out.resize(n,0);\n        nxt.resize(n,s);\n\
    \        par.resize(n,s);\n        dfs_sz(s,-1);\n        dfs_hld(s,-1);\n   \
    \ }\n    void dfs_sz(int v,int p) {\n        sz[v] = 1;\n        for(auto &u:\
    \ g[v]) {\n            if(p==u)continue;\n            dfs_sz(u,v);\n         \
    \   sz[v]+=sz[u];\n            if(sz[u]>sz[g[v][0]])std::swap(u,g[v][0]);\n  \
    \      }\n    }\n    void dfs_hld(int v,int p) {\n        static int t=0;\n  \
    \      in[v]=t++;\n        for(auto u: g[v]){\n            if(p==u)continue;\n\
    \            nxt[u]=(u==g[v][0]?nxt[v]:u);\n            par[u]=(u==g[v][0]?par[v]:v);\n\
    \            dfs_hld(u,v);\n        }\n        out[v] = t;\n    }\n    int query(int\
    \ s,int t){\n        while(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]])t=par[t];\n\
    \t\t\telse s=par[s];\n\t\t}\n        return sz[s]>sz[t]?s:t;\n    }\n    int distance(int\
    \ s,int t){\n\t\tint res=0;\n\t\twhile(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]]){\n\
    \t\t\t\tres+=in[t]-in[nxt[t]]+1;\n\t\t\t\tt=par[t];\n\t\t\t}\n\t\t\telse {\n\t\
    \t\t\tres+=in[s]-in[nxt[s]]+1;\n\t\t\t\ts=par[s];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res+std::abs(in[s]-in[t]);\n\t}\n};\n"
  code: "/**\n * LCA\n * \n * \u69CB\u7BC9 :O(N)\n * LCA :O(1)\n * \u8DDD\u96E2 :O(1)\n\
    \ * \n * verified with    :https://judge.yosupo.jp/problem/lca\n * submission\
    \       :https://judge.yosupo.jp/submission/28297\n */\n\nstruct lca{\n    using\
    \ graph=vector<vector<int>>;\n    graph g;\n    vector<int>sz,in,out,nxt,par;\n\
    \    lca(const graph& g,int s):g(g){\n        int n=g.size();\n        sz.resize(n,0);\n\
    \        in.resize(n,0);\n        out.resize(n,0);\n        nxt.resize(n,s);\n\
    \        par.resize(n,s);\n        dfs_sz(s,-1);\n        dfs_hld(s,-1);\n   \
    \ }\n    void dfs_sz(int v,int p) {\n        sz[v] = 1;\n        for(auto &u:\
    \ g[v]) {\n            if(p==u)continue;\n            dfs_sz(u,v);\n         \
    \   sz[v]+=sz[u];\n            if(sz[u]>sz[g[v][0]])std::swap(u,g[v][0]);\n  \
    \      }\n    }\n    void dfs_hld(int v,int p) {\n        static int t=0;\n  \
    \      in[v]=t++;\n        for(auto u: g[v]){\n            if(p==u)continue;\n\
    \            nxt[u]=(u==g[v][0]?nxt[v]:u);\n            par[u]=(u==g[v][0]?par[v]:v);\n\
    \            dfs_hld(u,v);\n        }\n        out[v] = t;\n    }\n    int query(int\
    \ s,int t){\n        while(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]])t=par[t];\n\
    \t\t\telse s=par[s];\n\t\t}\n        return sz[s]>sz[t]?s:t;\n    }\n    int distance(int\
    \ s,int t){\n\t\tint res=0;\n\t\twhile(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]]){\n\
    \t\t\t\tres+=in[t]-in[nxt[t]]+1;\n\t\t\t\tt=par[t];\n\t\t\t}\n\t\t\telse {\n\t\
    \t\t\tres+=in[s]-in[nxt[s]]+1;\n\t\t\t\ts=par[s];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res+std::abs(in[s]-in[t]);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/lca.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/lca.cpp
layout: document
redirect_from:
- /library/give_us_tmp/lca.cpp
- /library/give_us_tmp/lca.cpp.html
title: give_us_tmp/lca.cpp
---
