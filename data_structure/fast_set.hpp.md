---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: data_structure/test/LC_fast_set.test.cpp
    title: data_structure/test/LC_fast_set.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data_structure/fast_set.hpp\"\n#include<cstdint>\n#include<vector>\n\
    #include<tuple>\n#include<algorithm>\n#include <cassert>\n#include<iostream>\n\
    \ntemplate<typename T>\nstruct fast_set{\n\tconstexpr static int B=4;\n    constexpr\
    \ static int S=(1<<B);\n\tstruct node{\n\t\tT val=0;\n        bool b=0;\n\t\t\
    node* ch[S]={};\n        static int node_count;\n        void* operator new(std::size_t){\n\
    \            static node* pool=(node*)malloc(4096*sizeof(node));\n           \
    \ if(node_count==4096){\n                node_count=0;\n                pool=(node*)malloc(4096*sizeof(node));\n\
    \            }\n            return pool + node_count++;\n        }\n        node(){}\n\
    \t};\n\tusing np=node*;\n\tnp root=new node(),root2=new node();\n\tinline T& operator[](int64_t\
    \ k){\n        return get(std::abs(k),k>0?root:root2);\n    }\n    inline bool\
    \ count(int64_t k){\n        return count(std::abs(k),k>0?root:root2);\n    }\n\
    \    inline std::vector<std::pair<int64_t,T>> out(){\n        std::vector<std::pair<int64_t,T>>v;\n\
    \        out(v,root2,0,-1,0);\n        out(v,root,0,1,0);\n        std::sort(v.begin(),v.end());\n\
    \        return v;\n    }\n\tT& get(int64_t k,np t){\n        while(k){\n    \
    \        if(!t->ch[k&(S-1)])t->ch[k&(S-1)]=new node();\n            t=t->ch[k&(S-1)];\n\
    \            k>>=B;\n        }\n        t->b=1;\n        return t->val;\n\t}\n\
    \    bool count(int64_t k,np& t){\n        if(!t)return 0;\n        if(!k)return\
    \ t->b;\n        else return count(k>>B,t->ch[k&(S-1)]);\n    }\n    void out(std::vector<std::pair<int64_t,T>>&v,np&\
    \ t,int64_t k,int f,int b){\n        if(!t)return;\n        if(t->b)v.emplace_back(k*f,t->val);\n\
    \        for(int i=0;i<S;++i){\n            out(v,t->ch[i],k+(i<<(B*b)),f,b+1);\n\
    \        }\n    }\n};\ntemplate<typename T>int fast_set<T>::node::node_count =\
    \ 0;\n"
  code: "#pragma once\n#include<cstdint>\n#include<vector>\n#include<tuple>\n#include<algorithm>\n\
    #include <cassert>\n#include<iostream>\n\ntemplate<typename T>\nstruct fast_set{\n\
    \tconstexpr static int B=4;\n    constexpr static int S=(1<<B);\n\tstruct node{\n\
    \t\tT val=0;\n        bool b=0;\n\t\tnode* ch[S]={};\n        static int node_count;\n\
    \        void* operator new(std::size_t){\n            static node* pool=(node*)malloc(4096*sizeof(node));\n\
    \            if(node_count==4096){\n                node_count=0;\n          \
    \      pool=(node*)malloc(4096*sizeof(node));\n            }\n            return\
    \ pool + node_count++;\n        }\n        node(){}\n\t};\n\tusing np=node*;\n\
    \tnp root=new node(),root2=new node();\n\tinline T& operator[](int64_t k){\n \
    \       return get(std::abs(k),k>0?root:root2);\n    }\n    inline bool count(int64_t\
    \ k){\n        return count(std::abs(k),k>0?root:root2);\n    }\n    inline std::vector<std::pair<int64_t,T>>\
    \ out(){\n        std::vector<std::pair<int64_t,T>>v;\n        out(v,root2,0,-1,0);\n\
    \        out(v,root,0,1,0);\n        std::sort(v.begin(),v.end());\n        return\
    \ v;\n    }\n\tT& get(int64_t k,np t){\n        while(k){\n            if(!t->ch[k&(S-1)])t->ch[k&(S-1)]=new\
    \ node();\n            t=t->ch[k&(S-1)];\n            k>>=B;\n        }\n    \
    \    t->b=1;\n        return t->val;\n\t}\n    bool count(int64_t k,np& t){\n\
    \        if(!t)return 0;\n        if(!k)return t->b;\n        else return count(k>>B,t->ch[k&(S-1)]);\n\
    \    }\n    void out(std::vector<std::pair<int64_t,T>>&v,np& t,int64_t k,int f,int\
    \ b){\n        if(!t)return;\n        if(t->b)v.emplace_back(k*f,t->val);\n  \
    \      for(int i=0;i<S;++i){\n            out(v,t->ch[i],k+(i<<(B*b)),f,b+1);\n\
    \        }\n    }\n};\ntemplate<typename T>int fast_set<T>::node::node_count =\
    \ 0;"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fast_set.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - data_structure/test/LC_fast_set.test.cpp
documentation_of: data_structure/fast_set.hpp
layout: document
redirect_from:
- /library/data_structure/fast_set.hpp
- /library/data_structure/fast_set.hpp.html
title: data_structure/fast_set.hpp
---
