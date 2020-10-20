---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_cartesian_tree.test.cpp
    title: data_structure/test/LC_cartesian_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: cartesian_tree
    links: []
  bundledCode: "#line 2 \"data_structure/cartesian_tree.hpp\"\n#include<vector>\n\
    #include<stack>\n#include<cstdint>\n#include<functional>\n\n/**\n * @brief cartesian_tree\n\
    \ */\n\ntemplate<typename T,typename F=std::less<T>>\nstruct cartesian_tree{\n\
    \    struct node;\n    using np=node*;\n    struct node{\n        np ch[2]={0,0};\n\
    \        T val;\n        int pos;\n        int sz=0;\n        node(T val,int pos):val(val),pos(pos){}\n\
    \    };\n    int size(np t){return t?t->sz:0;}\n    np update(np t){}\n    np\
    \ root=0;\n    int sz=0;\n    F comp;\n    cartesian_tree(std::vector<T>v,F comp):comp(comp){\n\
    \        for(auto e:v)push_back(e);\n    }\n    cartesian_tree(std::vector<T>v):comp(F()){\n\
    \        for(auto e:v)push_back(e);\n    }\n    cartesian_tree(F comp):comp(comp){}\n\
    \    cartesian_tree():comp(F()){}\n\n    void push_back(int val){\n        static\
    \ std::stack<np>stk;\n        while(!stk.empty()&&comp(val,stk.top()->val))stk.pop();\n\
    \        np t=new node(val,sz);\n        if(stk.empty()){\n            t->ch[0]=root;\n\
    \            root=t;\n        }else{\n            t->ch[0]=stk.top()->ch[1];\n\
    \            stk.top()->ch[1]=t;\n        }\n        stk.emplace(t);\n       \
    \ sz++;\n    }\n    std::int64_t update_size(np t){\n        if(!t)return 0;\n\
    \        return t->sz=update_size(t->ch[0])+1+update_size(t->ch[1]);\n    }\n\
    \    std::vector<T>get(){\n\t\tstd::vector<T>v(sz);\n\t\tauto f=[&](auto f,np\
    \ t){\n\t\t\tif(!t)return;\n\t\t\tf(f,t->ch[0]);\n\t\t\tif(t->ch[0])v[t->ch[0]->pos]=t->pos;\n\
    \t\t\tif(t->ch[1])v[t->ch[1]->pos]=t->pos;\n\t\t\tf(f,t->ch[1]);\n\t\t};\n\t\t\
    v[root->pos]=root->pos;\n\t\tf(f,root);\n\t\treturn v;\n\t}\n};\n"
  code: "#pragma once\n#include<vector>\n#include<stack>\n#include<cstdint>\n#include<functional>\n\
    \n/**\n * @brief cartesian_tree\n */\n\ntemplate<typename T,typename F=std::less<T>>\n\
    struct cartesian_tree{\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        np ch[2]={0,0};\n        T val;\n        int pos;\n        int sz=0;\n\
    \        node(T val,int pos):val(val),pos(pos){}\n    };\n    int size(np t){return\
    \ t?t->sz:0;}\n    np update(np t){}\n    np root=0;\n    int sz=0;\n    F comp;\n\
    \    cartesian_tree(std::vector<T>v,F comp):comp(comp){\n        for(auto e:v)push_back(e);\n\
    \    }\n    cartesian_tree(std::vector<T>v):comp(F()){\n        for(auto e:v)push_back(e);\n\
    \    }\n    cartesian_tree(F comp):comp(comp){}\n    cartesian_tree():comp(F()){}\n\
    \n    void push_back(int val){\n        static std::stack<np>stk;\n        while(!stk.empty()&&comp(val,stk.top()->val))stk.pop();\n\
    \        np t=new node(val,sz);\n        if(stk.empty()){\n            t->ch[0]=root;\n\
    \            root=t;\n        }else{\n            t->ch[0]=stk.top()->ch[1];\n\
    \            stk.top()->ch[1]=t;\n        }\n        stk.emplace(t);\n       \
    \ sz++;\n    }\n    std::int64_t update_size(np t){\n        if(!t)return 0;\n\
    \        return t->sz=update_size(t->ch[0])+1+update_size(t->ch[1]);\n    }\n\
    \    std::vector<T>get(){\n\t\tstd::vector<T>v(sz);\n\t\tauto f=[&](auto f,np\
    \ t){\n\t\t\tif(!t)return;\n\t\t\tf(f,t->ch[0]);\n\t\t\tif(t->ch[0])v[t->ch[0]->pos]=t->pos;\n\
    \t\t\tif(t->ch[1])v[t->ch[1]->pos]=t->pos;\n\t\t\tf(f,t->ch[1]);\n\t\t};\n\t\t\
    v[root->pos]=root->pos;\n\t\tf(f,root);\n\t\treturn v;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 13:13:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_cartesian_tree.test.cpp
documentation_of: data_structure/cartesian_tree.hpp
layout: document
redirect_from:
- /library/data_structure/cartesian_tree.hpp
- /library/data_structure/cartesian_tree.hpp.html
title: cartesian_tree
---
