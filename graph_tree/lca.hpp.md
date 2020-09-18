---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: data_structure/RMQ.hpp
    title: RMQ&amp;lt;O(N),O(1)&amp;gt;
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: LCA &amp;lt;O(N),O(1)&amp;gt;
    links: []
  bundledCode: "#line 2 \"graph_tree/lca.hpp\"\n#include<vector>\n#include<cmath>\n\
    #include<tuple>\n#line 4 \"graph_tree/graph_template.hpp\"\n#include<iostream>\n\
    /**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n\
    using graph=std::vector<std::vector<int>>;\ntemplate<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 2 \"data_structure/RMQ.hpp\"\
    \n#include<assert.h>\n#line 4 \"data_structure/RMQ.hpp\"\n#include<stack>\n#include<numeric>\n\
    #line 7 \"data_structure/RMQ.hpp\"\n#include<algorithm>\n\n/**\n * @brief RMQ&amp;lt;O(N),O(1)&amp;gt;\n\
    \ * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n */\n\ntemplate<typename\
    \ T>\nclass RMQ{\n    class small_rmq{\n        using u64=unsigned long long;\n\
    \        std::vector<u64>table;\n        std::vector<T> v;\n        public:\n\
    \        small_rmq(std::vector<T> v):v(v){\n            assert(v.size()<=64);\n\
    \            std::vector<int>tmp(v.size());\n            table.resize(v.size(),0);\n\
    \            std::stack<T>stk;\n            for(int i=0;i<(int)v.size();++i){\n\
    \                tmp.resize(v.size());\n                while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                    stk.pop();\n                }\n                tmp[i]=stk.empty()?-1:stk.top();\n\
    \                stk.emplace(i);\n            }\n            for(int i=0;i<(int)v.size();++i){\n\
    \                if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n    \
    \        }\n        }\n        T query(int l,int r){\n            if(l==r)return\
    \ std::numeric_limits<T>::max();\n            const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \            if(tmp==0)return v[r-1];\n            else return v[__builtin_ctzll(tmp)];\n\
    \        }\n    };\n    class sparse_table{\n        std::vector<std::vector<T>>data;\n\
    \        public:\n        sparse_table(std::vector<T> v){\n            int n=v.size(),log=log2(n)+1;\n\
    \            data.resize(n,std::vector<T>(log));\n            for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \            for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n        \
    \        data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n            }\n\
    \        }\n        T get(int l,int r){\n            if(l==r)return std::numeric_limits<T>::max();\n\
    \            if(r<l)std::swap(l,r);\n            int k=log2(r-l);\n          \
    \  return f(data[l][k],data[r-(1<<k)][k]);\n        }\n        constexpr static\
    \ T e=std::numeric_limits<T>::max();\n        T f(T s,T t){\n            return\
    \ std::min(s,t);\n        }\n    };\n    constexpr static int b=64;\n    std::vector<T>v;\n\
    \    std::vector<small_rmq*>backet;\n    sparse_table* st=0;\n    public:\n  \
    \  RMQ(std::vector<T>v):v(v){\n        std::vector<T>tmp2;\n        for(int i=0;i<(int)v.size();i+=b){\n\
    \            std::vector<T>tmp;\n            T mn=std::numeric_limits<T>::max();\n\
    \            for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j])mn=v[i+j];\n            }\n            tmp2.push_back(mn);\n\
    \            backet.push_back(new small_rmq(tmp));\n        }\n        st=new\
    \ sparse_table(tmp2);\n    }\n    T query(int s,int t){\n        if(s/b==t/b)return\
    \ backet[s/b]->query(s%b,t%b);\n        return std::min({backet[s/b]->query(s%b,b),st->get(s/b+1,t/b),backet[t/b]->query(0,t%b)});\n\
    \    }\n};\n#line 7 \"graph_tree/lca.hpp\"\n\n/**\n * @brief LCA &amp;lt;O(N),O(1)&amp;gt;\n\
    \ */\n\nclass LCA{\n    std::vector<std::pair<int,int>>data;\n    std::vector<int>start;\n\
    \    RMQ<std::pair<int,int>>*st;\n    std::vector<int>dep;\n    std::vector<int>\
    \ __dist;\n    public:\n    LCA(){}\n    LCA(std::vector<std::vector<int>>v,int\
    \ s){\n        data.resize(v.size()*2-1);\n        start.resize(v.size());\n \
    \       int i=0;\n        dep=depth(s,v);\n        __dist=__distance(s,v);\n \
    \       auto f=[&](auto f,int n,int p)->void{\n            start[n]=i;\n     \
    \       data[i++]=std::make_pair(dep[n],n);\n            for(int t:v[n]){\n  \
    \              if(t==p)continue;\n                f(f,t,n);\n                data[i++]=std::make_pair(dep[n],n);\n\
    \            }\n        };\n        f(f,s,-1);\n        st=new RMQ<std::pair<int,int>>(data);\n\
    \    }\n    int lca(int p,int q){\n        return st->query(std::min(start[p],start[q]),std::max(start[p],start[q])+1).second;\n\
    \    }\n    int distance(int p,int q){\n        return __dist[p]+__dist[q]-2*__dist[lca(p,q)];\n\
    \    }\n    std::vector<int> __distance(int start,std::vector<std::vector<int>>G){\n\
    \t\tstd::vector<int>memo(G.size());\n\t\tauto f=[&](auto f,int v,int p,int i)->void{\n\
    \t\t\tfor(auto t:G[v]){\n\t\t\t\tif(t==p)continue;\n\t\t\t\tf(f,t,v,i+1);\n\t\t\
    \t}\n\t\t\treturn memo[v]=i;\n\t\t};\n\t\tf(f,start,-1,0);\n\t\treturn memo;\n\
    \    }\n    std::vector<int> depth(int start,std::vector<std::vector<int>>G){\n\
    \        std::vector<int>memo(G.size());\n        auto f=[&](auto f,int v,int\
    \ p)->int{\n            int mx=0;\n            for(int t:G[v]){\n            \
    \    if(t==p)continue;\n                mx=std::max(mx,f(f,t,v));\n          \
    \  }\n            return memo[v]=mx+1;\n        };\n        f(f,start,-1);\n \
    \       return memo;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<cmath>\n#include<tuple>\n#include\"\
    graph_template.hpp\"\n#include\"../data_structure/RMQ.hpp\"\n\n/**\n * @brief\
    \ LCA &amp;lt;O(N),O(1)&amp;gt;\n */\n\nclass LCA{\n    std::vector<std::pair<int,int>>data;\n\
    \    std::vector<int>start;\n    RMQ<std::pair<int,int>>*st;\n    std::vector<int>dep;\n\
    \    std::vector<int> __dist;\n    public:\n    LCA(){}\n    LCA(std::vector<std::vector<int>>v,int\
    \ s){\n        data.resize(v.size()*2-1);\n        start.resize(v.size());\n \
    \       int i=0;\n        dep=depth(s,v);\n        __dist=__distance(s,v);\n \
    \       auto f=[&](auto f,int n,int p)->void{\n            start[n]=i;\n     \
    \       data[i++]=std::make_pair(dep[n],n);\n            for(int t:v[n]){\n  \
    \              if(t==p)continue;\n                f(f,t,n);\n                data[i++]=std::make_pair(dep[n],n);\n\
    \            }\n        };\n        f(f,s,-1);\n        st=new RMQ<std::pair<int,int>>(data);\n\
    \    }\n    int lca(int p,int q){\n        return st->query(std::min(start[p],start[q]),std::max(start[p],start[q])+1).second;\n\
    \    }\n    int distance(int p,int q){\n        return __dist[p]+__dist[q]-2*__dist[lca(p,q)];\n\
    \    }\n    std::vector<int> __distance(int start,std::vector<std::vector<int>>G){\n\
    \t\tstd::vector<int>memo(G.size());\n\t\tauto f=[&](auto f,int v,int p,int i)->void{\n\
    \t\t\tfor(auto t:G[v]){\n\t\t\t\tif(t==p)continue;\n\t\t\t\tf(f,t,v,i+1);\n\t\t\
    \t}\n\t\t\treturn memo[v]=i;\n\t\t};\n\t\tf(f,start,-1,0);\n\t\treturn memo;\n\
    \    }\n    std::vector<int> depth(int start,std::vector<std::vector<int>>G){\n\
    \        std::vector<int>memo(G.size());\n        auto f=[&](auto f,int v,int\
    \ p)->int{\n            int mx=0;\n            for(int t:G[v]){\n            \
    \    if(t==p)continue;\n                mx=std::max(mx,f(f,t,v));\n          \
    \  }\n            return memo[v]=mx+1;\n        };\n        f(f,start,-1);\n \
    \       return memo;\n    }\n};"
  dependsOn:
  - graph_tree/graph_template.hpp
  - data_structure/RMQ.hpp
  isVerificationFile: false
  path: graph_tree/lca.hpp
  requiredBy: []
  timestamp: '2020-09-18 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/lca.hpp
layout: document
redirect_from:
- /library/graph_tree/lca.hpp
- /library/graph_tree/lca.hpp.html
title: LCA &amp;lt;O(N),O(1)&amp;gt;
---
