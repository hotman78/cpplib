---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: string/test/YUKI_Aho_Corasick.test.cpp
    title: string/test/YUKI_Aho_Corasick.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Aho-Corasick\u6CD5"
    links: []
  bundledCode: "#line 2 \"string/AhoCorasick.hpp\"\n#include<string>\n#include<queue>\n\
    \n/**\n * @brief Aho-Corasick\u6CD5\n */\n\nclass AhoCorasick{\n    struct node;\n\
    \    using np=node*;\n    constexpr static int num=26;\n    constexpr static char\
    \ base='A';\n    struct node{\n        np ch[num];\n        np link=nullptr;\n\
    \        int val=0;\n        node(){\n            for(int i=0;i<num;++i)ch[i]=nullptr;\n\
    \        }\n    };\n    np root=new node();\n    np root_par=new node();\n   \
    \ public:\n    AhoCorasick(){\n        root->link=root_par;\n        for(int i=0;i<num;++i)root_par->ch[i]=root;\n\
    \    }\n    void insert(std::string v){\n        np t=root;\n        int idx=0;\n\
    \        while(idx<(int)v.size()){\n            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new\
    \ node();\n            t=t->ch[v[idx]-base];\n            idx++;\n        }\n\
    \        t->val++;\n    }\n    void build(){\n        built=1;\n        std::queue<np>que;\n\
    \        que.push(root);\n        while(!que.empty()){\n            np t=que.front();\n\
    \            que.pop();\n            for(int i=0;i<num;++i){\n               \
    \ if(!t->ch[i])continue;\n                if(t==root){\n                    t->ch[i]->link=t;\n\
    \                }else{\n                    np s=t->link;\n                 \
    \   while(!s->ch[i]){\n                        s=s->link;\n                  \
    \  }\n                    t->ch[i]->link=s->ch[i];\n                }\n      \
    \          que.push(t->ch[i]);\n            }\n        }\n    }\n    bool built=0;\n\
    \    int count(std::string v){\n        if(!built){build();built=1;}\n       \
    \ np t=root;\n        int idx=0;\n        int res=0;\n        while(idx<(int)v.size()){\n\
    \            while(!t->ch[v[idx]-base]){\n                if(t==root){\n     \
    \               idx++;\n                    if(idx==(int)v.size())return res;\n\
    \                }else{\n                    t=t->link;\n                }\n \
    \           }\n            t=t->ch[v[idx++]-base];\n            auto s=t;\n  \
    \          while(s!=root){\n                res+=s->val;\n                s=s->link;\n\
    \            }\n        }\n        return res;\n    }\n    int find_first(std::string\
    \ v){\n        if(!built){build();built=1;}\n        np t=root;\n        int idx=0;\n\
    \        int res=0;\n        while(idx<(int)v.size()){\n            while(!t->ch[v[idx]-base]){\n\
    \                if(t==root){\n                    res++;\n                  \
    \  idx++;\n                    if(idx==(int)v.size())return -1;\n            \
    \    }else{\n                    res++;\n                    t=t->link;\n    \
    \            }\n            }\n            t=t->ch[v[idx++]-base];\n         \
    \   if(t->val>0)return res;\n        }\n        return -1;\n    }\n};\n"
  code: "#pragma once\n#include<string>\n#include<queue>\n\n/**\n * @brief Aho-Corasick\u6CD5\
    \n */\n\nclass AhoCorasick{\n    struct node;\n    using np=node*;\n    constexpr\
    \ static int num=26;\n    constexpr static char base='A';\n    struct node{\n\
    \        np ch[num];\n        np link=nullptr;\n        int val=0;\n        node(){\n\
    \            for(int i=0;i<num;++i)ch[i]=nullptr;\n        }\n    };\n    np root=new\
    \ node();\n    np root_par=new node();\n    public:\n    AhoCorasick(){\n    \
    \    root->link=root_par;\n        for(int i=0;i<num;++i)root_par->ch[i]=root;\n\
    \    }\n    void insert(std::string v){\n        np t=root;\n        int idx=0;\n\
    \        while(idx<(int)v.size()){\n            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new\
    \ node();\n            t=t->ch[v[idx]-base];\n            idx++;\n        }\n\
    \        t->val++;\n    }\n    void build(){\n        built=1;\n        std::queue<np>que;\n\
    \        que.push(root);\n        while(!que.empty()){\n            np t=que.front();\n\
    \            que.pop();\n            for(int i=0;i<num;++i){\n               \
    \ if(!t->ch[i])continue;\n                if(t==root){\n                    t->ch[i]->link=t;\n\
    \                }else{\n                    np s=t->link;\n                 \
    \   while(!s->ch[i]){\n                        s=s->link;\n                  \
    \  }\n                    t->ch[i]->link=s->ch[i];\n                }\n      \
    \          que.push(t->ch[i]);\n            }\n        }\n    }\n    bool built=0;\n\
    \    int count(std::string v){\n        if(!built){build();built=1;}\n       \
    \ np t=root;\n        int idx=0;\n        int res=0;\n        while(idx<(int)v.size()){\n\
    \            while(!t->ch[v[idx]-base]){\n                if(t==root){\n     \
    \               idx++;\n                    if(idx==(int)v.size())return res;\n\
    \                }else{\n                    t=t->link;\n                }\n \
    \           }\n            t=t->ch[v[idx++]-base];\n            auto s=t;\n  \
    \          while(s!=root){\n                res+=s->val;\n                s=s->link;\n\
    \            }\n        }\n        return res;\n    }\n    int find_first(std::string\
    \ v){\n        if(!built){build();built=1;}\n        np t=root;\n        int idx=0;\n\
    \        int res=0;\n        while(idx<(int)v.size()){\n            while(!t->ch[v[idx]-base]){\n\
    \                if(t==root){\n                    res++;\n                  \
    \  idx++;\n                    if(idx==(int)v.size())return -1;\n            \
    \    }else{\n                    res++;\n                    t=t->link;\n    \
    \            }\n            }\n            t=t->ch[v[idx++]-base];\n         \
    \   if(t->val>0)return res;\n        }\n        return -1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - string/test/YUKI_Aho_Corasick.test.cpp
documentation_of: string/AhoCorasick.hpp
layout: document
redirect_from:
- /library/string/AhoCorasick.hpp
- /library/string/AhoCorasick.hpp.html
title: "Aho-Corasick\u6CD5"
---
