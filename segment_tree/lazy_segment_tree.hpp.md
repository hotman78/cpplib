---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
    title: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ \"segment_tree/lazy_segment_tree.hpp\"\n\ntemplate<typename T,typename E,typename\
    \ F,typename G,typename H>\nclass lazy_segment_tree{\n    using i64=long long;\n\
    \    i64 n;\n    i64 sz;\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        maybe<T> val=maybe<T>();\n        maybe<E> lazy=maybe<E>();\n       \
    \ np lch=nullptr,rch=nullptr;\n        node(){}\n    };\n    np root=new node();\n\
    \    maybe<T> update(i64 a,i64 b,E x,i64 l,i64 r,np t){\n        auto f=expand<T,F>(_f);\n\
    \        eval(t,l,r);\n        //\u533A\u9593\u5916\n        if(r<=a||b<=l)return\
    \ t->val;\n        //\u5168\u90E8\u533A\u9593\u5185\n        if(a<=l&&r<=b){\n\
    \            t->lazy=x;\n            eval(t,l,r);\n            return t->val;\n\
    \        }\n        //\u4E00\u90E8\u533A\u9593\u5185\n        return t->val=f(update(a,b,x,l,(l+r)/2,t->lch),update(a,b,x,(l+r)/2,r,t->rch));\n\
    \    }\n    maybe<T> get(i64 a,i64 b,i64 l,i64 r,np t){\n        auto f=expand<T,F>(_f);\n\
    \        eval(t,l,r);\n        //\u533A\u9593\u5916\n        if(r<=a||b<=l)return\
    \ maybe<T>();\n        //\u5168\u90E8\u533A\u9593\u5185\n        if(a<=l&&r<=b)return\
    \ t->val;\n        //\u4E00\u90E8\u533A\u9593\u5185\n        return f(get(a,b,l,(l+r)/2,t->lch),get(a,b,(l+r)/2,r,t->rch));\n\
    \    }\n    void eval(np t,i64 l,i64 r){\n        auto g=expand<E,G>(_g);\n  \
    \      if(r-l>1){\n            if(!t->lch)t->lch=new node();\n            if(!t->rch)t->rch=new\
    \ node();\n            t->lch->lazy=g(t->lch->lazy,t->lazy);\n            t->rch->lazy=g(t->rch->lazy,t->lazy);\n\
    \        }\n        t->val=h(t->val,t->lazy,l,r);\n        t->lazy=maybe<E>();\n\
    \    }\n    F _f;G _g;H _h;\n    maybe<T> h(const maybe<T>&s,const maybe<E>&t,int\
    \ l,int r){\n        if(t.is_none())return s;\n        else return maybe<T>(_h(s,t.unwrap(),l,r));\n\
    \    }\n    public:\n    lazy_segment_tree(i64 sz,F f=F(),G g=G(),H h=H()):n(1),sz(sz),_f(f),_g(g),_h(h){while(n<sz)n<<=1;}\n\
    \    //0-indexed [a,b)\n    void update(i64 a,i64 b,E x){update(a,b,x,0,n,root);}\n\
    \    //0-indexed [a,b)\n    maybe<T> get(i64 a,i64 b){return get(a,b,0,n,root);}\n\
    };\n"
  code: "#pragma once\n#include\"../alga/maybe.hpp\"\n\ntemplate<typename T,typename\
    \ E,typename F,typename G,typename H>\nclass lazy_segment_tree{\n    using i64=long\
    \ long;\n    i64 n;\n    i64 sz;\n    struct node;\n    using np=node*;\n    struct\
    \ node{\n        maybe<T> val=maybe<T>();\n        maybe<E> lazy=maybe<E>();\n\
    \        np lch=nullptr,rch=nullptr;\n        node(){}\n    };\n    np root=new\
    \ node();\n    maybe<T> update(i64 a,i64 b,E x,i64 l,i64 r,np t){\n        auto\
    \ f=expand<T,F>(_f);\n        eval(t,l,r);\n        //\u533A\u9593\u5916\n   \
    \     if(r<=a||b<=l)return t->val;\n        //\u5168\u90E8\u533A\u9593\u5185\n\
    \        if(a<=l&&r<=b){\n            t->lazy=x;\n            eval(t,l,r);\n \
    \           return t->val;\n        }\n        //\u4E00\u90E8\u533A\u9593\u5185\
    \n        return t->val=f(update(a,b,x,l,(l+r)/2,t->lch),update(a,b,x,(l+r)/2,r,t->rch));\n\
    \    }\n    maybe<T> get(i64 a,i64 b,i64 l,i64 r,np t){\n        auto f=expand<T,F>(_f);\n\
    \        eval(t,l,r);\n        //\u533A\u9593\u5916\n        if(r<=a||b<=l)return\
    \ maybe<T>();\n        //\u5168\u90E8\u533A\u9593\u5185\n        if(a<=l&&r<=b)return\
    \ t->val;\n        //\u4E00\u90E8\u533A\u9593\u5185\n        return f(get(a,b,l,(l+r)/2,t->lch),get(a,b,(l+r)/2,r,t->rch));\n\
    \    }\n    void eval(np t,i64 l,i64 r){\n        auto g=expand<E,G>(_g);\n  \
    \      if(r-l>1){\n            if(!t->lch)t->lch=new node();\n            if(!t->rch)t->rch=new\
    \ node();\n            t->lch->lazy=g(t->lch->lazy,t->lazy);\n            t->rch->lazy=g(t->rch->lazy,t->lazy);\n\
    \        }\n        t->val=h(t->val,t->lazy,l,r);\n        t->lazy=maybe<E>();\n\
    \    }\n    F _f;G _g;H _h;\n    maybe<T> h(const maybe<T>&s,const maybe<E>&t,int\
    \ l,int r){\n        if(t.is_none())return s;\n        else return maybe<T>(_h(s,t.unwrap(),l,r));\n\
    \    }\n    public:\n    lazy_segment_tree(i64 sz,F f=F(),G g=G(),H h=H()):n(1),sz(sz),_f(f),_g(g),_h(h){while(n<sz)n<<=1;}\n\
    \    //0-indexed [a,b)\n    void update(i64 a,i64 b,E x){update(a,b,x,0,n,root);}\n\
    \    //0-indexed [a,b)\n    maybe<T> get(i64 a,i64 b){return get(a,b,0,n,root);}\n\
    };"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: segment_tree/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:47:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/AOJ_lazy_segment_tree.test.cpp
documentation_of: segment_tree/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/lazy_segment_tree.hpp
- /library/segment_tree/lazy_segment_tree.hpp.html
title: segment_tree/lazy_segment_tree.hpp
---
