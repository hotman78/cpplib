---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_maximum_independent_set.test.cpp
    title: graph_tree/test/LC_maximum_independent_set.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)"
    links: []
  bundledCode: "#line 2 \"graph_tree/maximum_independent_set.hpp\"\n#include<tuple>\n\
    #include<vector>\n#include<bitset>\n#line 4 \"graph_tree/graph_template.hpp\"\n\
    #include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\ntemplate<typename T>\n\
    using graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\ngraph load_graph(int\
    \ n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n  \
    \      std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n       \
    \ g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_digraph(int n,int m){\n\
    \    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 6 \"graph_tree/maximum_independent_set.hpp\"\
    \n\n/**\n * @brief \u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)\n */\n\nstd::pair<int,std::bitset<50>>\
    \ __maximum_independent_set(std::vector<std::bitset<50>>v,std::bitset<50>b=std::bitset<50>()){\n\
    \tint n=v.size();\n\tauto del=[&](int k){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tv[k][i]=0;\n\
    \t\t\tv[i][k]=0;\n\t\t}\n\t\tb[k]=1;\n\t};\n\tint t=-1;\n\tfor(int i=0;i<n;++i)if(b[i]==0)t=i;\n\
    \tif(t==-1)return std::make_pair(0,std::bitset<50>());\n\tif(v[t].count()<=1){\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])del(i);\n\t\tdel(t);\n\t\tauto p=__maximum_independent_set(v,b);\n\
    \t\tp.first++;\n\t\tp.second[t]=1;\n\t\treturn p;\n\t}else{\n\t\tstd::vector<int>tmp;\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])tmp.push_back(i);\n\t\tdel(t);\n\t\tauto p=__maximum_independent_set(v,b);\n\
    \t\tfor(auto e:tmp)del(e);\n\t\tauto q=__maximum_independent_set(v,b);\n\t\tq.first++;\n\
    \t\tq.second[t]=1;\n\t\treturn p.first>q.first?p:q;\n\t}\n}\n\nstd::vector<int>\
    \ maximum_independent_set(const graph& g){\n\tstd::vector<std::bitset<50>>v(g.size());\n\
    \tfor(size_t i=0;i<g.size();++i){\n\t\tfor(auto e:g[i]){\n\t\t\tv[i][e]=1;\n\t\
    \t}\n\t}\n\tauto res=__maximum_independent_set(v);\n\tstd::vector<int>ret;\n\t\
    for(size_t i=0;i<res.second.size();++i){\n\t\tif(res.second[i])ret.push_back(i);\n\
    \t}\n\treturn ret;\n}\n"
  code: "#pragma once\n#include<tuple>\n#include<vector>\n#include<bitset>\n#include\"\
    graph_template.hpp\"\n\n/**\n * @brief \u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)\n\
    \ */\n\nstd::pair<int,std::bitset<50>> __maximum_independent_set(std::vector<std::bitset<50>>v,std::bitset<50>b=std::bitset<50>()){\n\
    \tint n=v.size();\n\tauto del=[&](int k){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tv[k][i]=0;\n\
    \t\t\tv[i][k]=0;\n\t\t}\n\t\tb[k]=1;\n\t};\n\tint t=-1;\n\tfor(int i=0;i<n;++i)if(b[i]==0)t=i;\n\
    \tif(t==-1)return std::make_pair(0,std::bitset<50>());\n\tif(v[t].count()<=1){\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])del(i);\n\t\tdel(t);\n\t\tauto p=__maximum_independent_set(v,b);\n\
    \t\tp.first++;\n\t\tp.second[t]=1;\n\t\treturn p;\n\t}else{\n\t\tstd::vector<int>tmp;\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])tmp.push_back(i);\n\t\tdel(t);\n\t\tauto p=__maximum_independent_set(v,b);\n\
    \t\tfor(auto e:tmp)del(e);\n\t\tauto q=__maximum_independent_set(v,b);\n\t\tq.first++;\n\
    \t\tq.second[t]=1;\n\t\treturn p.first>q.first?p:q;\n\t}\n}\n\nstd::vector<int>\
    \ maximum_independent_set(const graph& g){\n\tstd::vector<std::bitset<50>>v(g.size());\n\
    \tfor(size_t i=0;i<g.size();++i){\n\t\tfor(auto e:g[i]){\n\t\t\tv[i][e]=1;\n\t\
    \t}\n\t}\n\tauto res=__maximum_independent_set(v);\n\tstd::vector<int>ret;\n\t\
    for(size_t i=0;i<res.second.size();++i){\n\t\tif(res.second[i])ret.push_back(i);\n\
    \t}\n\treturn ret;\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2020-09-19 11:01:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_maximum_independent_set.test.cpp
documentation_of: graph_tree/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/graph_tree/maximum_independent_set.hpp
- /library/graph_tree/maximum_independent_set.hpp.html
title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)"
---
