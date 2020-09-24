---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: BBST/AVL/base.hpp
    title: BBST/AVL/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"BBST/AVL/base.hpp\"\n#include<tuple>\n\ntemplate<typename\
    \ Node>\nstruct AVL_base{\n    using np=Node*;\n    int sz(np t){return t?t->sz:0;}\n\
    \    int dep(np t){return t?t->dep:0;}\n    np update(np t){\n        t->sz=sz(t->ch[0])+1+sz(t->ch[1]);\n\
    \        t->dep=std::max(dep(t->ch[0]),dep(t->ch[1]))+1;\n        return t;\n\
    \    }\n    np merge_with_root(np s,np t,np u){\n        if(abs(sz(s)-sz(u))<2){\n\
    \            t->ch[0]=s;t->ch[1]=u;\n            return update(t);\n        }\n\
    \        if(sz(s)>sz(u)){\n            s->ch[1]=merge_with_root(s->ch[1],t,u);\n\
    \            return update(s);\n        }else{\n            u->ch[0]=merge_with_root(s,t,u->ch[0]);\n\
    \            return update(t);\n        }\n    }\n    np make_root(np& t){\n \
    \       if(t->ch[1]){\n            np res=make_root(t->ch[1]);\n            update(t);\n\
    \            return res;\n        }else{\n            np res=t;\n            t=t->ch[0];\n\
    \            return res;\n        }\n    }\n    np merge(np s,np t){\n       \
    \ if(!s||!t)return s?s:t;\n        np u=make_root(s);\n        return merge_with_root(s,u,t);\n\
    \    }\n    std::pair<np,np> split(np t,int i){\n        if(!t)return std::make_pair(0,0);\n\
    \        np s=t->ch[0],u=t->ch[1];\n        t->ch[0]=0;t->ch[1]=0;\n        if(i==sz(s)){\n\
    \            return make_pair(s,merge_with_root(0,t,u));\n        }\n        if(i<sz(s)){\n\
    \            auto r=split(s,i);\n            return make_pair(r.first,merge_with_root(r.second,t,u));\n\
    \        }else{\n            auto r=split(u,i-sz(s)-1);\n            return make_pair(merge_with_root(s,t,r.first),r.second);\n\
    \        }\n    }\n    //insert erase\n    void insert(const np& x,np& t){\n \
    \       if(!t)t=x;\n        else if(*x<=*t)insert(x,t->ch[1]);\n        else insert(x,t->ch[0]);\n\
    \        t=balance(update(t));\n    }\n    bool erase(const np& x,np& t){\n  \
    \      if(!t)return false;\n        else if(*x==*t){\n            if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];\n\
    \            else move_down(t->ch[0],t);\n            return true;\n        }\n\
    \        bool b;\n        if(*x<*t)b=erase(x,t->ch[0]);\n        else b=erase(x,t->ch[1]);\n\
    \        t=balance(update(t));\n        return b;\n    }\n    void move_down(np&\
    \ t,np& p){\n\t\tif(t->ch[1])move_down(t->ch[1],p);\n\t\telse p->val=t->val,t=t->ch[0];\n\
    \t\tt=balance(update(t));\n\t}\n    np rot(np t){\n\t\tint b=dep(t->ch[0])<dep(t->ch[1]);\n\
    \t\tif(dep(t->ch[0])==dep(t->ch[1]))return t;\n\t\tnp s=t->ch[b];\n\t\tt->ch[b]=s->ch[1-b];\n\
    \t\ts->ch[1-b]=t;\n\t\tupdate(t);update(s);\n\t\treturn s;\n\t}\n    np balance(np\
    \ t){\n        if(abs(dep(t->ch[0])-dep(t->ch[1]))!=2)return t;\n        bool\
    \ b=dep(t->ch[0])<dep(t->ch[1]);\n\t\tif(t->ch[b]&&dep(t->ch[b]->ch[b])<dep(t->ch[b]->ch[1-b])){\n\
    \t\t\tt->ch[b]=rot(t->ch[b]);\n\t\t}\n\t\treturn rot(update(t));\n    }\n};\n\
    #line 3 \"BBST/AVL/set.hpp\"\n\ntemplate<typename T>\nstruct Node{\n    T val,sum;\n\
    \    int sz=1,dep=1;\n    Node* ch[2]={0,0};\n    Node(T val):val(val),sum(val){}\n\
    \    void cpy(Node* t){val=t->val;}\n    bool operator <(const Node& x)const{\n\
    \        return val<x.val;\n    }\n    bool operator >(const Node& x)const{return\
    \ (x)<(*this);}\n    bool operator <=(const Node& x)const{return !((x)>(*this));}\n\
    \    bool operator >=(const Node& x)const{return !((x)<(*this));}\n    bool operator\
    \ ==(const Node& x)const{return (x)<=(*this)&&(*this)<=(x);}\n    void update(Node*\
    \ t){\n        \n    }\n};\n\ntemplate<typename T>\nstruct avl_set:public AVL_base<Node<T>>{\n\
    \    using AVL_base<Node<T>>::AVL_base;\n    using np=Node<T>*;\n    np root=0;\n\
    \    int lower_bound(np t,np x){\n        if(*x<*t)return lower_bound(t->ch[0],x);\n\
    \        else return AVL_base<Node<T>>::sz(t->ch[0])+1+lower_bound(t->ch[1],x);\n\
    \    }\n    int upper_bound(np t,np x){\n        if(*x<=*t)return upper_bound(t->ch[0],x);\n\
    \        else return AVL_base<Node<T>>::sz(t->ch[0])+1+upper_bound(t->ch[1],x);\n\
    \    }\n    int count(T x){\n        np t=new Node<T>(x);\n        return upper_bound(root,t)-lower_bound(root,t);\n\
    \    }\n    void insert(T x){\n        np s=new Node<T>(x);\n        AVL_base<Node<T>>::insert(s,root);\n\
    \    }\n    void erase(T x){\n        np s=new Node<T>(x);\n        AVL_base<Node<T>>::erase(s,root);\n\
    \    }\n};\n"
  code: "#pragma once\n#include\"base.hpp\"\n\ntemplate<typename T>\nstruct Node{\n\
    \    T val,sum;\n    int sz=1,dep=1;\n    Node* ch[2]={0,0};\n    Node(T val):val(val),sum(val){}\n\
    \    void cpy(Node* t){val=t->val;}\n    bool operator <(const Node& x)const{\n\
    \        return val<x.val;\n    }\n    bool operator >(const Node& x)const{return\
    \ (x)<(*this);}\n    bool operator <=(const Node& x)const{return !((x)>(*this));}\n\
    \    bool operator >=(const Node& x)const{return !((x)<(*this));}\n    bool operator\
    \ ==(const Node& x)const{return (x)<=(*this)&&(*this)<=(x);}\n    void update(Node*\
    \ t){\n        \n    }\n};\n\ntemplate<typename T>\nstruct avl_set:public AVL_base<Node<T>>{\n\
    \    using AVL_base<Node<T>>::AVL_base;\n    using np=Node<T>*;\n    np root=0;\n\
    \    int lower_bound(np t,np x){\n        if(*x<*t)return lower_bound(t->ch[0],x);\n\
    \        else return AVL_base<Node<T>>::sz(t->ch[0])+1+lower_bound(t->ch[1],x);\n\
    \    }\n    int upper_bound(np t,np x){\n        if(*x<=*t)return upper_bound(t->ch[0],x);\n\
    \        else return AVL_base<Node<T>>::sz(t->ch[0])+1+upper_bound(t->ch[1],x);\n\
    \    }\n    int count(T x){\n        np t=new Node<T>(x);\n        return upper_bound(root,t)-lower_bound(root,t);\n\
    \    }\n    void insert(T x){\n        np s=new Node<T>(x);\n        AVL_base<Node<T>>::insert(s,root);\n\
    \    }\n    void erase(T x){\n        np s=new Node<T>(x);\n        AVL_base<Node<T>>::erase(s,root);\n\
    \    }\n};"
  dependsOn:
  - BBST/AVL/base.hpp
  isVerificationFile: false
  path: BBST/AVL/set.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BBST/AVL/set.hpp
layout: document
redirect_from:
- /library/BBST/AVL/set.hpp
- /library/BBST/AVL/set.hpp.html
title: BBST/AVL/set.hpp
---
