---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_dinic.test.cpp
    title: graph_tree/test/LC_dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u6D41(Dinic\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph_tree/dinic.hpp\"\n#include<vector>\r\n#include<queue>\r\
    \n#include<cmath>\r\n#include<limits>\r\n#include<cassert>\r\n#include<iostream>\r\
    \n#include<map>\r\n#include<list>\r\n\r\n/**\r\n * @brief \u6700\u5927\u6D41(Dinic\u6CD5\
    )\r\n */\r\n\r\ntemplate<typename T>\r\nstruct dinic {\r\n    struct edge {\r\n\
    \        int to;\r\n        typename std::list<edge>::iterator rev;\r\n      \
    \  T cap,flow;\r\n        edge(int to,T cap):to(to),cap(cap),flow(T()){}\r\n \
    \   };\r\n    int n,src,dst;\r\n    T ret=T();\r\n    std::vector<std::list<edge>>\
    \ g;\r\n    std::vector<typename std::list<edge>::iterator>itr;\r\n    std::vector<int>level,seen;\r\
    \n    std::map<std::pair<int,int>,bool>exist;\r\n    std::map<std::pair<int,int>,typename\
    \ std::list<edge>::iterator>m;\r\n    dinic(int n,int s,int t):n(n),src(s),dst(t){g.assign(n,std::list<edge>());itr.resize(n);}\r\
    \n\r\n    void add_edge(int from, int to, T cap) {\r\n        g[from].push_back(edge(to,cap));\r\
    \n        g[to].push_back(edge(from,0));\r\n        m[std::make_pair(from,to)]=prev(g[from].end());\r\
    \n        m[std::make_pair(to,from)]=prev(g[to].end());\r\n        g[from].back().rev=prev(g[to].end());\r\
    \n        g[to].back().rev=prev(g[from].end());\r\n        exist[std::make_pair(from,to)]=1;\r\
    \n        exist[std::make_pair(to,from)]=1;\r\n    }\r\n    bool update_edge(int\
    \ from, int to, T cap){\r\n        if(cap>0){\r\n            if(exist[std::make_pair(from,to)]){\r\
    \n                auto e=m[std::make_pair(from,to)];\r\n                e->cap+=cap;\r\
    \n            }else{\r\n                add_edge(from,to,cap);\r\n           \
    \ }\r\n            return 1;\r\n        }else{\r\n            cap*=-1;\r\n   \
    \         if(exist[std::make_pair(from,to)]){\r\n                auto e=m[std::make_pair(from,to)];\r\
    \n                if(e->cap-e->flow>=cap){\r\n                    e->cap-=cap;\r\
    \n                }else{\r\n                    e->cap-=cap;\r\n             \
    \       T req=e->flow-e->cap;\r\n                    e->flow-=req;\r\n       \
    \             e->rev->flow+=req;\r\n                    ret-=req;\r\n        \
    \            assert(cancel(dst,to,req));\r\n                    assert(cancel(from,src,req));\r\
    \n                    if(e->cap==0&&e->rev->cap==0){\r\n                     \
    \   g[from].erase(e);\r\n                        g[to].erase(e->rev);\r\n    \
    \                    exist[std::make_pair(from,to)]=0;\r\n                   \
    \     exist[std::make_pair(to,from)]=0;\r\n                    }\r\n         \
    \       }\r\n                return 1;\r\n            }else{\r\n             \
    \   return 0;\r\n            }\r\n        }\r\n    }\r\n\r\n    void bfs(int s)\
    \ {\r\n        level.assign(n,-1);\r\n        std::queue<int> q;\r\n        level[s]\
    \ = 0; q.push(s);\r\n        while (!q.empty()) {\r\n            int v = q.front();\
    \ q.pop();\r\n            for(edge e: g[v]){\r\n                if (e.cap-e.flow\
    \ > 0 and level[e.to] < 0) {\r\n                    level[e.to] = level[v] + 1;\r\
    \n                    q.push(e.to);\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    T dfs(int v, int t,T f) {\r\n        if (v == t)\
    \ return f;\r\n        for(auto &e=itr[v];e!=g[v].end();++e){\r\n            if\
    \ (e->cap-e->flow > 0 and level[v] < level[e->to]) {\r\n                T d =\
    \ dfs(e->to, t, std::min(f, e->cap-e->flow));\r\n                if (d > 0) {\r\
    \n                    e->flow+=d;\r\n                    e->rev->flow -= d;\r\n\
    \                    return d;\r\n                }\r\n            }\r\n     \
    \   }\r\n        return 0;\r\n    }\r\n\r\n    T __cancel(int v,int t,T f){\r\n\
    \        if (v == t) return f;\r\n        seen[v]=1;\r\n        for (edge& e:\
    \ g[v]){\r\n            if (e.rev->flow > 0&&!seen[e.to]) {\r\n              \
    \  T d = __cancel(e.to, t, std::min(f,e.rev->flow));\r\n                if (d\
    \ > 0) {\r\n                    e.flow+=d;\r\n                    e.rev->flow-=d;\r\
    \n                    return d;\r\n                }\r\n            }\r\n    \
    \    }\r\n        return 0;\r\n    }\r\n    T run() {\r\n        T f;\r\n    \
    \    while (bfs(src), level[dst] >= 0) {\r\n            for(int i=0;i<n;++i)itr[i]=g[i].begin();\r\
    \n            while ((f = dfs(src, dst, std::numeric_limits<T>::max())) > 0) {\r\
    \n                ret += f;\r\n            }\r\n        }\r\n        return ret;\r\
    \n    }\r\n    T cancel(int s,int t,T mx){\r\n        T f;\r\n        while(seen.assign(n,0),seen[s]=1,(f=__cancel(s,\
    \ t, mx))>0)mx-=f;\r\n        return mx==0;\r\n    }\r\n    T cap(int s,int t){\r\
    \n        if(exist[std::make_pair(s,t)]){\r\n            return m[std::make_pair(s,t)]->cap;\r\
    \n        }else{\r\n            return 0;\r\n        }\r\n    }\r\n    T flow(int\
    \ s,int t){\r\n        if(exist[std::make_pair(s,t)]){\r\n            return m[std::make_pair(s,t)]->flow;\r\
    \n        }else{\r\n            return 0;\r\n        }\r\n    }\r\n    void debug(){\r\
    \n        for(int i=0;i<n;++i)for(int j=0;j<n;++j){\r\n            if(i==j)continue;\r\
    \n            if(flow(i,j)>0)std::cerr<<\"(\"<<i<<\",\"<<j<<\")\";\r\n       \
    \ }\r\n        std::cerr<<'\\n';\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include<vector>\r\n#include<queue>\r\n#include<cmath>\r\n\
    #include<limits>\r\n#include<cassert>\r\n#include<iostream>\r\n#include<map>\r\
    \n#include<list>\r\n\r\n/**\r\n * @brief \u6700\u5927\u6D41(Dinic\u6CD5)\r\n */\r\
    \n\r\ntemplate<typename T>\r\nstruct dinic {\r\n    struct edge {\r\n        int\
    \ to;\r\n        typename std::list<edge>::iterator rev;\r\n        T cap,flow;\r\
    \n        edge(int to,T cap):to(to),cap(cap),flow(T()){}\r\n    };\r\n    int\
    \ n,src,dst;\r\n    T ret=T();\r\n    std::vector<std::list<edge>> g;\r\n    std::vector<typename\
    \ std::list<edge>::iterator>itr;\r\n    std::vector<int>level,seen;\r\n    std::map<std::pair<int,int>,bool>exist;\r\
    \n    std::map<std::pair<int,int>,typename std::list<edge>::iterator>m;\r\n  \
    \  dinic(int n,int s,int t):n(n),src(s),dst(t){g.assign(n,std::list<edge>());itr.resize(n);}\r\
    \n\r\n    void add_edge(int from, int to, T cap) {\r\n        g[from].push_back(edge(to,cap));\r\
    \n        g[to].push_back(edge(from,0));\r\n        m[std::make_pair(from,to)]=prev(g[from].end());\r\
    \n        m[std::make_pair(to,from)]=prev(g[to].end());\r\n        g[from].back().rev=prev(g[to].end());\r\
    \n        g[to].back().rev=prev(g[from].end());\r\n        exist[std::make_pair(from,to)]=1;\r\
    \n        exist[std::make_pair(to,from)]=1;\r\n    }\r\n    bool update_edge(int\
    \ from, int to, T cap){\r\n        if(cap>0){\r\n            if(exist[std::make_pair(from,to)]){\r\
    \n                auto e=m[std::make_pair(from,to)];\r\n                e->cap+=cap;\r\
    \n            }else{\r\n                add_edge(from,to,cap);\r\n           \
    \ }\r\n            return 1;\r\n        }else{\r\n            cap*=-1;\r\n   \
    \         if(exist[std::make_pair(from,to)]){\r\n                auto e=m[std::make_pair(from,to)];\r\
    \n                if(e->cap-e->flow>=cap){\r\n                    e->cap-=cap;\r\
    \n                }else{\r\n                    e->cap-=cap;\r\n             \
    \       T req=e->flow-e->cap;\r\n                    e->flow-=req;\r\n       \
    \             e->rev->flow+=req;\r\n                    ret-=req;\r\n        \
    \            assert(cancel(dst,to,req));\r\n                    assert(cancel(from,src,req));\r\
    \n                    if(e->cap==0&&e->rev->cap==0){\r\n                     \
    \   g[from].erase(e);\r\n                        g[to].erase(e->rev);\r\n    \
    \                    exist[std::make_pair(from,to)]=0;\r\n                   \
    \     exist[std::make_pair(to,from)]=0;\r\n                    }\r\n         \
    \       }\r\n                return 1;\r\n            }else{\r\n             \
    \   return 0;\r\n            }\r\n        }\r\n    }\r\n\r\n    void bfs(int s)\
    \ {\r\n        level.assign(n,-1);\r\n        std::queue<int> q;\r\n        level[s]\
    \ = 0; q.push(s);\r\n        while (!q.empty()) {\r\n            int v = q.front();\
    \ q.pop();\r\n            for(edge e: g[v]){\r\n                if (e.cap-e.flow\
    \ > 0 and level[e.to] < 0) {\r\n                    level[e.to] = level[v] + 1;\r\
    \n                    q.push(e.to);\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    T dfs(int v, int t,T f) {\r\n        if (v == t)\
    \ return f;\r\n        for(auto &e=itr[v];e!=g[v].end();++e){\r\n            if\
    \ (e->cap-e->flow > 0 and level[v] < level[e->to]) {\r\n                T d =\
    \ dfs(e->to, t, std::min(f, e->cap-e->flow));\r\n                if (d > 0) {\r\
    \n                    e->flow+=d;\r\n                    e->rev->flow -= d;\r\n\
    \                    return d;\r\n                }\r\n            }\r\n     \
    \   }\r\n        return 0;\r\n    }\r\n\r\n    T __cancel(int v,int t,T f){\r\n\
    \        if (v == t) return f;\r\n        seen[v]=1;\r\n        for (edge& e:\
    \ g[v]){\r\n            if (e.rev->flow > 0&&!seen[e.to]) {\r\n              \
    \  T d = __cancel(e.to, t, std::min(f,e.rev->flow));\r\n                if (d\
    \ > 0) {\r\n                    e.flow+=d;\r\n                    e.rev->flow-=d;\r\
    \n                    return d;\r\n                }\r\n            }\r\n    \
    \    }\r\n        return 0;\r\n    }\r\n    T run() {\r\n        T f;\r\n    \
    \    while (bfs(src), level[dst] >= 0) {\r\n            for(int i=0;i<n;++i)itr[i]=g[i].begin();\r\
    \n            while ((f = dfs(src, dst, std::numeric_limits<T>::max())) > 0) {\r\
    \n                ret += f;\r\n            }\r\n        }\r\n        return ret;\r\
    \n    }\r\n    T cancel(int s,int t,T mx){\r\n        T f;\r\n        while(seen.assign(n,0),seen[s]=1,(f=__cancel(s,\
    \ t, mx))>0)mx-=f;\r\n        return mx==0;\r\n    }\r\n    T cap(int s,int t){\r\
    \n        if(exist[std::make_pair(s,t)]){\r\n            return m[std::make_pair(s,t)]->cap;\r\
    \n        }else{\r\n            return 0;\r\n        }\r\n    }\r\n    T flow(int\
    \ s,int t){\r\n        if(exist[std::make_pair(s,t)]){\r\n            return m[std::make_pair(s,t)]->flow;\r\
    \n        }else{\r\n            return 0;\r\n        }\r\n    }\r\n    void debug(){\r\
    \n        for(int i=0;i<n;++i)for(int j=0;j<n;++j){\r\n            if(i==j)continue;\r\
    \n            if(flow(i,j)>0)std::cerr<<\"(\"<<i<<\",\"<<j<<\")\";\r\n       \
    \ }\r\n        std::cerr<<'\\n';\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/dinic.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_dinic.test.cpp
documentation_of: graph_tree/dinic.hpp
layout: document
redirect_from:
- /library/graph_tree/dinic.hpp
- /library/graph_tree/dinic.hpp.html
title: "\u6700\u5927\u6D41(Dinic\u6CD5)"
---
