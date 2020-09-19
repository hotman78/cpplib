---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/LC_segment_tree.test.cpp
    title: segment_tree/test/LC_segment_tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links:
    - https://en.wikipedia.org/wiki/Segment_tree
  bundledCode: "#line 2 \"segment_tree/segment_tree.hpp\"\n#include<vector>\n#line\
    \ 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 4\
    \ \"segment_tree/segment_tree.hpp\"\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @see https://en.wikipedia.org/wiki/Segment_tree\n */\ntemplate<typename\
    \ T,typename F>\nclass segment_tree{\n\tmaybe<T>* node;\n    F op;\n\tint n=1;\n\
    \tpublic:\n    segment_tree(){}\n\tsegment_tree(int sz,F op=F()):op(op){\n\t\t\
    while(n<=sz)n<<=1;\n\t\tnode=new maybe<T>[n*2];\n\t\tfor(int i=0;i<n*2;i++)node[i]=maybe<T>();\n\
    \t}\n    segment_tree(const std::vector<T>&v,F op=F()):op(op){\n        auto f=expand<T,F>(op);\n\
    \        const int sz=v.size();\n\t\twhile(n<=sz)n<<=1;\n\t\tnode=new maybe<T>[n*2]();\n\
    \        for(int i=0;i<sz;i++)node[i+n]=maybe<T>(v[i]);\n        for(int i=n-1;i>=1;i--)node[i]=f(node[i*2],node[i*2+1]);\n\
    \t}\n    maybe<T> get(int l,int r){\n        auto f=expand<T,F>(op);\n       \
    \ l+=n;r+=n;\n        maybe<T> s,t;\n        while(l<r){\n            if(l&1)s=f(s,node[l++]);\n\
    \            if(r&1)t=f(node[--r],t);\n            l>>=1;r>>=1;\n        }\n \
    \       return f(s,t);\n    }\n    void apply(int t,T _val){\n        auto f=expand<T,F>(op);\n\
    \        t+=n;\n        maybe<T> val=maybe<T>(_val);\n        while(t){\n    \
    \        node[t]=f(node[t],val);\n            t=t>>1;\n        }\n    }\n    void\
    \ apply_left(int t,T _val){\n        auto f=expand<T,F>(op);\n        t+=n;\n\
    \        maybe<T> val=maybe<T>(_val);\n        while(t){\n            node[t]=f(val,node[t]);\n\
    \            t=t>>1;\n        }\n    }\n    void change(int t,T val){\n      \
    \  auto f=expand<T,F>(op);\n        t+=n;\n        node[t]=maybe<T>(val);\n  \
    \      while(t>1){\n            t=t>>1;\n            node[t]=f(node[t*2],node[t*2+1]);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include\"../alga/maybe.hpp\"\n/**\n * @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @see https://en.wikipedia.org/wiki/Segment_tree\n\
    \ */\ntemplate<typename T,typename F>\nclass segment_tree{\n\tmaybe<T>* node;\n\
    \    F op;\n\tint n=1;\n\tpublic:\n    segment_tree(){}\n\tsegment_tree(int sz,F\
    \ op=F()):op(op){\n\t\twhile(n<=sz)n<<=1;\n\t\tnode=new maybe<T>[n*2];\n\t\tfor(int\
    \ i=0;i<n*2;i++)node[i]=maybe<T>();\n\t}\n    segment_tree(const std::vector<T>&v,F\
    \ op=F()):op(op){\n        auto f=expand<T,F>(op);\n        const int sz=v.size();\n\
    \t\twhile(n<=sz)n<<=1;\n\t\tnode=new maybe<T>[n*2]();\n        for(int i=0;i<sz;i++)node[i+n]=maybe<T>(v[i]);\n\
    \        for(int i=n-1;i>=1;i--)node[i]=f(node[i*2],node[i*2+1]);\n\t}\n    maybe<T>\
    \ get(int l,int r){\n        auto f=expand<T,F>(op);\n        l+=n;r+=n;\n   \
    \     maybe<T> s,t;\n        while(l<r){\n            if(l&1)s=f(s,node[l++]);\n\
    \            if(r&1)t=f(node[--r],t);\n            l>>=1;r>>=1;\n        }\n \
    \       return f(s,t);\n    }\n    void apply(int t,T _val){\n        auto f=expand<T,F>(op);\n\
    \        t+=n;\n        maybe<T> val=maybe<T>(_val);\n        while(t){\n    \
    \        node[t]=f(node[t],val);\n            t=t>>1;\n        }\n    }\n    void\
    \ apply_left(int t,T _val){\n        auto f=expand<T,F>(op);\n        t+=n;\n\
    \        maybe<T> val=maybe<T>(_val);\n        while(t){\n            node[t]=f(val,node[t]);\n\
    \            t=t>>1;\n        }\n    }\n    void change(int t,T val){\n      \
    \  auto f=expand<T,F>(op);\n        t+=n;\n        node[t]=maybe<T>(val);\n  \
    \      while(t>1){\n            t=t>>1;\n            node[t]=f(node[t*2],node[t*2+1]);\n\
    \        }\n    }\n};"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: segment_tree/segment_tree.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:52:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/LC_segment_tree.test.cpp
documentation_of: segment_tree/segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/segment_tree.hpp
- /library/segment_tree/segment_tree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
