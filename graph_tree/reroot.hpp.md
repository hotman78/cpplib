---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
    links: []
  bundledCode: "#line 2 \"graph_tree/reroot.hpp\"\n#include<vector>\n\n/**\n * @brief\
    \ \u5168\u65B9\u4F4D\u6728DP\n */\n\ntemplate<typename T,typename F,typename Fix>\n\
    struct reroot{\n    std::vector<std::vector<long long>>g;\n    std::vector<int>p_list;\n\
    \    std::vector<T>p_table;\n    std::vector<bool>p_checked;\n    std::vector<map<int,T>>table;\n\
    \    std::vector<T>ans;\n    F f;\n    Fix fix;\n    reroot(const std::vector<std::vector<long\
    \ long>>& g,F f=F(),Fix fix=Fix()):g(g),f(f),fix(fix){\n        int n=g.size();\n\
    \        p_list.resize(n,-1);\n        p_checked.resize(n,0);\n        table.resize(n);\n\
    \        p_table.resize(n,e);\n        ans.resize(n,e);\n        dfs1(0,-1);\n\
    \        for(int i=0;i<n;++i)ans[i]=dfs2(i,-1);\n    }\n    T dfs1(int n,int p){\n\
    \        p_list[n]=p;\n        T tmp1=e,tmp2=e;\n        std::vector<T>tmp(g[n].size());\n\
    \        rep(i,g[n].size()){\n            int t=g[n][i];\n            if(t==p)continue;\n\
    \            table[n][t]=tmp1;\n            tmp1=f(tmp1,tmp[i]=dfs1(t,n));\n \
    \       }\n        for(int i=g[n].size()-1;i>=0;--i){\n            int t=g[n][i];\n\
    \            if(t==p)continue;\n            table[n][t]=f(table[n][t],tmp2);\n\
    \            tmp2=f(tmp[i],tmp2);\n        }\n        return fix(table[n][p]=tmp1,n,p);\n\
    \    }\n    T dfs2(int n,int p){\n        if(n==-1)return e;\n        if(!p_checked[n]){\n\
    \            p_checked[n]=1;\n            p_table[n]=dfs2(p_list[n],n);\n    \
    \    }\n        if(p==-1){\n            return f(table[n][p_list[n]],p_table[n]);\n\
    \        }else{\n            if(p_list[n]==-1)return fix(table[n][p],n,p);\n \
    \           else return fix(f(table[n][p],p_table[n]),n,p);\n        }\n    }\n\
    \    vector<T>query(){\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n\n/**\n * @brief \u5168\u65B9\u4F4D\u6728\
    DP\n */\n\ntemplate<typename T,typename F,typename Fix>\nstruct reroot{\n    std::vector<std::vector<long\
    \ long>>g;\n    std::vector<int>p_list;\n    std::vector<T>p_table;\n    std::vector<bool>p_checked;\n\
    \    std::vector<map<int,T>>table;\n    std::vector<T>ans;\n    F f;\n    Fix\
    \ fix;\n    reroot(const std::vector<std::vector<long long>>& g,F f=F(),Fix fix=Fix()):g(g),f(f),fix(fix){\n\
    \        int n=g.size();\n        p_list.resize(n,-1);\n        p_checked.resize(n,0);\n\
    \        table.resize(n);\n        p_table.resize(n,e);\n        ans.resize(n,e);\n\
    \        dfs1(0,-1);\n        for(int i=0;i<n;++i)ans[i]=dfs2(i,-1);\n    }\n\
    \    T dfs1(int n,int p){\n        p_list[n]=p;\n        T tmp1=e,tmp2=e;\n  \
    \      std::vector<T>tmp(g[n].size());\n        rep(i,g[n].size()){\n        \
    \    int t=g[n][i];\n            if(t==p)continue;\n            table[n][t]=tmp1;\n\
    \            tmp1=f(tmp1,tmp[i]=dfs1(t,n));\n        }\n        for(int i=g[n].size()-1;i>=0;--i){\n\
    \            int t=g[n][i];\n            if(t==p)continue;\n            table[n][t]=f(table[n][t],tmp2);\n\
    \            tmp2=f(tmp[i],tmp2);\n        }\n        return fix(table[n][p]=tmp1,n,p);\n\
    \    }\n    T dfs2(int n,int p){\n        if(n==-1)return e;\n        if(!p_checked[n]){\n\
    \            p_checked[n]=1;\n            p_table[n]=dfs2(p_list[n],n);\n    \
    \    }\n        if(p==-1){\n            return f(table[n][p_list[n]],p_table[n]);\n\
    \        }else{\n            if(p_list[n]==-1)return fix(table[n][p],n,p);\n \
    \           else return fix(f(table[n][p],p_table[n]),n,p);\n        }\n    }\n\
    \    vector<T>query(){\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/reroot.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/reroot.hpp
layout: document
redirect_from:
- /library/graph_tree/reroot.hpp
- /library/graph_tree/reroot.hpp.html
title: "\u5168\u65B9\u4F4D\u6728DP"
---
