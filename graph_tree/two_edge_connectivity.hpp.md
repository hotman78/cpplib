---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"graph_tree/two_edge_connectivity.hpp\"\n#include<vector>\n\
    #include<stack>\n#include<algorithm>\n#line 3 \"graph_tree/graph_template.hpp\"\
    \n#include<tuple>\n#include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\n\
    template<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 5 \"graph_tree/two_edge_connectivity.hpp\"\
    \n\n/**\n * @brief \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n */\n\nstruct\
    \ two_edge_connectivity{\n\tstd::vector<int>order,cmp;\n\tstd::stack<int> s,roots;\n\
    \tstd::vector<bool> ins;\n\tstd::vector<std::vector<int>>each_bcc;\n\tstd::vector<std::pair<int,int>>brige;\n\
    \ttwo_edge_connectivity(graph g){\n\t\tint n=g.size();\n\t\torder.resize(n,0);\n\
    \t\tins.resize(n,0);\n\t\tcmp.resize(n);\n\t\tfor(int i=0;i<n;i++){\n\t\t\tif(!order[i])dfs(g,i,-1);\n\
    \t\t}\n\t}\n\tvoid dfs(const graph& g,int v,int p){\n\t\torder[v]=(p==-1?0:order[p])+1;\n\
    \t\ts.emplace(v);\n\t\tins[v]=1;\n\t\troots.emplace(v);\n\t\tbool f=1;\n\t\tfor(auto\
    \ e:g[v]){\n\t\t\tif(e==p&&f){f=0;continue;}\n\t\t\tif(!order[e])dfs(g,e,v);\n\
    \t\t\telse if(e!=v&&ins[e])while(order[roots.top()]>order[e])roots.pop();\n\t\t\
    }\n\t\tif(v==roots.top()){\n\t\t\tif(p!=-1)brige.push_back(std::minmax(p,v));\n\
    \t\t\tstd::vector<int>bcc;\n\t\t\twhile(1){\n\t\t\t\tint e=s.top();s.pop();ins[e]=0;\n\
    \t\t\t\tbcc.push_back(e);\n\t\t\t\tcmp[v]=each_bcc.size();\n\t\t\t\tif(e==v)break;\n\
    \t\t\t}\n\t\t\teach_bcc.push_back(bcc);\n\t\t\troots.pop();\n\t\t}\n\t}\n\tauto\
    \ get_bcc(){return each_bcc;}\n\tauto get_v(){return cmp;}\n\tauto get_brige(){return\
    \ brige;}\n};\n"
  code: "#include<vector>\n#include<stack>\n#include<algorithm>\n#include\"graph_template.hpp\"\
    \n\n/**\n * @brief \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n */\n\nstruct\
    \ two_edge_connectivity{\n\tstd::vector<int>order,cmp;\n\tstd::stack<int> s,roots;\n\
    \tstd::vector<bool> ins;\n\tstd::vector<std::vector<int>>each_bcc;\n\tstd::vector<std::pair<int,int>>brige;\n\
    \ttwo_edge_connectivity(graph g){\n\t\tint n=g.size();\n\t\torder.resize(n,0);\n\
    \t\tins.resize(n,0);\n\t\tcmp.resize(n);\n\t\tfor(int i=0;i<n;i++){\n\t\t\tif(!order[i])dfs(g,i,-1);\n\
    \t\t}\n\t}\n\tvoid dfs(const graph& g,int v,int p){\n\t\torder[v]=(p==-1?0:order[p])+1;\n\
    \t\ts.emplace(v);\n\t\tins[v]=1;\n\t\troots.emplace(v);\n\t\tbool f=1;\n\t\tfor(auto\
    \ e:g[v]){\n\t\t\tif(e==p&&f){f=0;continue;}\n\t\t\tif(!order[e])dfs(g,e,v);\n\
    \t\t\telse if(e!=v&&ins[e])while(order[roots.top()]>order[e])roots.pop();\n\t\t\
    }\n\t\tif(v==roots.top()){\n\t\t\tif(p!=-1)brige.push_back(std::minmax(p,v));\n\
    \t\t\tstd::vector<int>bcc;\n\t\t\twhile(1){\n\t\t\t\tint e=s.top();s.pop();ins[e]=0;\n\
    \t\t\t\tbcc.push_back(e);\n\t\t\t\tcmp[v]=each_bcc.size();\n\t\t\t\tif(e==v)break;\n\
    \t\t\t}\n\t\t\teach_bcc.push_back(bcc);\n\t\t\troots.pop();\n\t\t}\n\t}\n\tauto\
    \ get_bcc(){return each_bcc;}\n\tauto get_v(){return cmp;}\n\tauto get_brige(){return\
    \ brige;}\n};"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/two_edge_connectivity.hpp
  requiredBy: []
  timestamp: '2020-09-18 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/two_edge_connectivity.hpp
layout: document
redirect_from:
- /library/graph_tree/two_edge_connectivity.hpp
- /library/graph_tree/two_edge_connectivity.hpp.html
title: "\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
