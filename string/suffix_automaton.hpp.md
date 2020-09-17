---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: SuffixAutomaton
    links: []
  bundledCode: "#line 2 \"string/suffix_automaton.hpp\"\n#include<string>\n#include<vector>\n\
    #include<algorithm>\n#include<map>\n#include<set>\n\n/**\n * @brief SuffixAutomaton\n\
    \ */\n\nstruct suffix_automaton{\n    struct node;\n    using np=node*;\n    struct\
    \ node{\n        int len,id;\n        std::map<char,np> ch;\n        np link=nullptr;\n\
    \        node(int len,int id):len(len),id(id){}\n    };\n    std::vector<np>list;\n\
    \    np root=new node(0,0);\n    np t=root;\n    suffix_automaton(std::string\
    \ s){\n        list.emplace_back(root);\n        for(auto c:s)add(c);\n      \
    \  dfs(root);\n        std::reverse(tsort.begin(),tsort.end());\n    }\n    void\
    \ add(char c){\n        np cur=new node(t->len+1,list.size());\n        list.emplace_back(cur);\n\
    \        for(;t&&!t->ch.count(c);t=t->link)t->ch[c]=cur;\n        if(!t)cur->link=root;\n\
    \        else{\n            np p=t,q=p->ch[c];\n            if(q->len==p->len+1)cur->link=q;\n\
    \            else{\n                np clone=new node(*q);\n                clone->len=p->len+1;\n\
    \                clone->id=list.size();\n                list.emplace_back(clone);\n\
    \                for(;p&&p->ch[c]==q;p=p->link)p->ch[c]=clone;\n             \
    \   q->link=cur->link=clone;\n            }\n        }\n        t=cur;\n    }\n\
    \    std::vector<int>tsort;\n    std::set<np>visited;\n    void dfs(np cur){\n\
    \        if(visited.count(cur))return;\n        visited.insert(cur);\n       \
    \ for(auto e:cur->ch)dfs(e.second);\n        tsort.emplace_back(cur->id);\n  \
    \  }\n    long long size(){\n        std::vector<long long>dp(list.size(),0);\n\
    \        long long ret=0;\n        dp[0]=1;\n        for(int i:tsort){\n     \
    \       ret+=dp[i];\n            for(auto e:list[i]->ch){\n                dp[e.second->id]+=dp[i];\n\
    \            }\n        }\n        return ret-1;\n    }\n};\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n#include<algorithm>\n#include<map>\n\
    #include<set>\n\n/**\n * @brief SuffixAutomaton\n */\n\nstruct suffix_automaton{\n\
    \    struct node;\n    using np=node*;\n    struct node{\n        int len,id;\n\
    \        std::map<char,np> ch;\n        np link=nullptr;\n        node(int len,int\
    \ id):len(len),id(id){}\n    };\n    std::vector<np>list;\n    np root=new node(0,0);\n\
    \    np t=root;\n    suffix_automaton(std::string s){\n        list.emplace_back(root);\n\
    \        for(auto c:s)add(c);\n        dfs(root);\n        std::reverse(tsort.begin(),tsort.end());\n\
    \    }\n    void add(char c){\n        np cur=new node(t->len+1,list.size());\n\
    \        list.emplace_back(cur);\n        for(;t&&!t->ch.count(c);t=t->link)t->ch[c]=cur;\n\
    \        if(!t)cur->link=root;\n        else{\n            np p=t,q=p->ch[c];\n\
    \            if(q->len==p->len+1)cur->link=q;\n            else{\n           \
    \     np clone=new node(*q);\n                clone->len=p->len+1;\n         \
    \       clone->id=list.size();\n                list.emplace_back(clone);\n  \
    \              for(;p&&p->ch[c]==q;p=p->link)p->ch[c]=clone;\n               \
    \ q->link=cur->link=clone;\n            }\n        }\n        t=cur;\n    }\n\
    \    std::vector<int>tsort;\n    std::set<np>visited;\n    void dfs(np cur){\n\
    \        if(visited.count(cur))return;\n        visited.insert(cur);\n       \
    \ for(auto e:cur->ch)dfs(e.second);\n        tsort.emplace_back(cur->id);\n  \
    \  }\n    long long size(){\n        std::vector<long long>dp(list.size(),0);\n\
    \        long long ret=0;\n        dp[0]=1;\n        for(int i:tsort){\n     \
    \       ret+=dp[i];\n            for(auto e:list[i]->ch){\n                dp[e.second->id]+=dp[i];\n\
    \            }\n        }\n        return ret-1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_automaton.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_automaton.hpp
layout: document
redirect_from:
- /library/string/suffix_automaton.hpp
- /library/string/suffix_automaton.hpp.html
title: SuffixAutomaton
---
