---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: segment_tree/test/AOJ_dual_segment_tree.test.cpp
    title: segment_tree/test/AOJ_dual_segment_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n\
    \ * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 3\
    \ \"segment_tree/dual_segment_tree.hpp\"\n\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n */\n\ntemplate<typename T,typename F>\nclass dual_segment_tree{\n\
    \tstruct node;\n\tusing np=node*;\n\tstruct node{\n\t\tmaybe<T> val;\n\t\tnp ch[2]={nullptr,nullptr};\n\
    \t\tnode(maybe<T> val=maybe<T>()):val(val){}\n\t};\n\tnp root=nullptr;\n\tint\
    \ n=1,sz;\n    F op;\n\tpublic:\n\tdual_segment_tree(int sz,F op=F()):sz(sz),op(op){while(n<sz)n<<=1;}\n\
    \tinline void update(int l,int r,T x){update(l,r,x,0,n,root);}\n\tinline maybe<T>\
    \ get(int x){return get(x,0,n,root);}\n\tprivate:\n\tvoid eval(np& t){\n     \
    \   auto f=expand<T,F>(op);\n\t\tif(t->val.is_none())return;\n\t\tif(!t->ch[0])t->ch[0]=new\
    \ node();\n\t\tif(!t->ch[1])t->ch[1]=new node();\n\t\tt->ch[0]->val=f(t->ch[0]->val,t->val);\n\
    \t\tt->ch[1]->val=f(t->ch[1]->val,t->val);\n\t\tt->val=maybe<T>();\n\t}\n\tvoid\
    \ update(int a,int b,T x,int l,int r,np& t){\n        auto f=expand<T,F>(op);\n\
    \        if(!t)t=new node();\n\t\tif(r-l>1)eval(t);\n\t\tif(r<=a||b<=l)return;\n\
    \t\telse if(a<=l&&r<=b)t->val=f(t->val,x);\n\t    else if(r-l>1){\n\t\t\tupdate(a,b,x,l,(l+r)/2,t->ch[0]);\n\
    \t\t\tupdate(a,b,x,(l+r)/2,r,t->ch[1]);\n\t\t}\n\t}\n\tmaybe<T> get(int x,int\
    \ l,int r,np& t){\n        auto f=expand<T,F>(op);\n        if(!t)t=new node();\n\
    \t\tif(r-l>1)eval(t);\n\t\tif(x<l||r<=x)return maybe<T>();\n        else if(r-l==1){\n\
    \            return t->val;\n        }\n\t\telse return f(get(x,l,(l+r)/2,t->ch[0]),get(x,(l+r)/2,r,t->ch[1]));\n\
    \t}\n};\n"
  code: "#pragma once\n#include\"../alga/maybe.hpp\"\n\n/**\n * @brief \u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\ntemplate<typename T,typename F>\n\
    class dual_segment_tree{\n\tstruct node;\n\tusing np=node*;\n\tstruct node{\n\t\
    \tmaybe<T> val;\n\t\tnp ch[2]={nullptr,nullptr};\n\t\tnode(maybe<T> val=maybe<T>()):val(val){}\n\
    \t};\n\tnp root=nullptr;\n\tint n=1,sz;\n    F op;\n\tpublic:\n\tdual_segment_tree(int\
    \ sz,F op=F()):sz(sz),op(op){while(n<sz)n<<=1;}\n\tinline void update(int l,int\
    \ r,T x){update(l,r,x,0,n,root);}\n\tinline maybe<T> get(int x){return get(x,0,n,root);}\n\
    \tprivate:\n\tvoid eval(np& t){\n        auto f=expand<T,F>(op);\n\t\tif(t->val.is_none())return;\n\
    \t\tif(!t->ch[0])t->ch[0]=new node();\n\t\tif(!t->ch[1])t->ch[1]=new node();\n\
    \t\tt->ch[0]->val=f(t->ch[0]->val,t->val);\n\t\tt->ch[1]->val=f(t->ch[1]->val,t->val);\n\
    \t\tt->val=maybe<T>();\n\t}\n\tvoid update(int a,int b,T x,int l,int r,np& t){\n\
    \        auto f=expand<T,F>(op);\n        if(!t)t=new node();\n\t\tif(r-l>1)eval(t);\n\
    \t\tif(r<=a||b<=l)return;\n\t\telse if(a<=l&&r<=b)t->val=f(t->val,x);\n\t    else\
    \ if(r-l>1){\n\t\t\tupdate(a,b,x,l,(l+r)/2,t->ch[0]);\n\t\t\tupdate(a,b,x,(l+r)/2,r,t->ch[1]);\n\
    \t\t}\n\t}\n\tmaybe<T> get(int x,int l,int r,np& t){\n        auto f=expand<T,F>(op);\n\
    \        if(!t)t=new node();\n\t\tif(r-l>1)eval(t);\n\t\tif(x<l||r<=x)return maybe<T>();\n\
    \        else if(r-l==1){\n            return t->val;\n        }\n\t\telse return\
    \ f(get(x,l,(l+r)/2,t->ch[0]),get(x,(l+r)/2,r,t->ch[1]));\n\t}\n};"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: segment_tree/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:52:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - segment_tree/test/AOJ_dual_segment_tree.test.cpp
documentation_of: segment_tree/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/dual_segment_tree.hpp
- /library/segment_tree/dual_segment_tree.hpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
