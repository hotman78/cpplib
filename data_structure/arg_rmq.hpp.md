---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/small_rmq.hpp
    title: data_structure/small_rmq.hpp
  - icon: ':question:'
    path: data_structure/sparse_table.hpp
    title: SparseTable
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  - icon: ':heavy_check_mark:'
    path: functional/argmin.hpp
    title: "\u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_lca.test.cpp
    title: graph_tree/test/LC_lca.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
    links:
    - https://noshi91.hatenablog.com/entry/2018/08/16/125415
  bundledCode: "#line 2 \"data_structure/arg_rmq.hpp\"\n#include<assert.h>\n#include<vector>\n\
    #include<stack>\n#include<numeric>\n#include<cmath>\n#include<algorithm>\n#line\
    \ 3 \"data_structure/small_rmq.hpp\"\n\n/**\n * RMQ(small) &amp;lt;O(N),O(1)&amp;gt;(N<=64)\n\
    \ */\n\ntemplate<typename T>\nclass small_rmq{\n    using u64=unsigned long long;\n\
    \    std::vector<u64>table;\n    std::vector<T> v;\n    public:\n    small_rmq(std::vector<T>\
    \ v):v(v){\n        assert(v.size()<=64);\n        std::vector<int>tmp(v.size());\n\
    \        table.resize(v.size(),0);\n        std::stack<T>stk;\n        for(int\
    \ i=0;i<(int)v.size();++i){\n            tmp.resize(v.size());\n            while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                stk.pop();\n            }\n            tmp[i]=stk.empty()?-1:stk.top();\n\
    \            stk.emplace(i);\n        }\n        for(int i=0;i<(int)v.size();++i){\n\
    \            if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n        }\n\
    \    }\n    T query(int l,int r){\n        assert(l!=r);\n        const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \        if(tmp==0)return r-1;\n        else return __builtin_ctzll(tmp);\n  \
    \  }\n};\n#line 3 \"data_structure/sparse_table.hpp\"\n#include<functional>\n\
    #line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n * @see\
    \ https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [op](const maybe<T>& s,const maybe<T>&\
    \ t){\n        if(s.is_none())return t;\n        if(t.is_none())return s;\n  \
    \      return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 7 \"data_structure/sparse_table.hpp\"\
    \n/**\n * @brief SparseTable\n */\n\ntemplate<typename T,typename F>\nclass sparse_table{\n\
    \    F f;\n    std::vector<std::vector<T>>data;\n    public:\n    sparse_table(std::vector<T>\
    \ v,F f=F()):f(f){\n        int n=v.size(),log=log2(n)+1;\n        data.resize(n,std::vector<T>(log));\n\
    \        for(int i=0;i<n;i++)data[i][0]=v[i];\n        for(int j=1;j<log;j++)for(int\
    \ i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    maybe<T> get(int l,int r){\n        if(l==r)return maybe<T>();\n\
    \        if(r<l)std::swap(l,r);\n        int k=std::log2(r-l);\n        return\
    \ maybe<T>(f(data[l][k],data[r-(1<<k)][k]));\n    }\n};\n#line 2 \"functional/argmin.hpp\"\
    \n#include<tuple>\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\
    \u7F6E\n */\n\ntemplate<typename T,typename E>\nstruct argmin{\n    std::pair<T,E>\
    \ operator()(const std::pair<T,E>& s,const std::pair<T,E>& t){\n        return\
    \ s.second<=t.second?s:t;\n    }\n};\n#line 11 \"data_structure/arg_rmq.hpp\"\n\
    \n/**\n * @brief RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;\n * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n\
    \ */\n\ntemplate<typename T>\nclass arg_rmq{\n    constexpr static int b=64;\n\
    \    std::vector<T>v;\n    std::vector<small_rmq<T>*>backet;\n    sparse_table<std::pair<int,T>,argmin<int,T>>*\
    \ st=0;\n    public:\n    arg_rmq(std::vector<T>v):v(v){\n        std::vector<std::pair<int,T>>tmp2;\n\
    \        for(int i=0;i<(int)v.size();i+=b){\n            std::vector<T>tmp;\n\
    \            T mn=std::numeric_limits<T>::max();\n            int idx=-1;\n  \
    \          for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j]){\n                    mn=v[i+j];\n            \
    \        idx=i+j;\n                }\n            }\n            tmp2.emplace_back(idx,mn);\n\
    \            backet.push_back(new small_rmq<T>(tmp));\n        }\n        st=new\
    \ sparse_table<std::pair<int,T>,argmin<int,T>>(tmp2);\n    }\n    maybe<std::pair<int,T>>\
    \ query(int s,int t){\n        if(s==t)return maybe<std::pair<int,T>>();\n   \
    \     if(s/b==t/b){\n            int idx=s/b*b+backet[s/b]->query(s%b,t%b);\n\
    \            return maybe<std::pair<int,T>>(std::make_pair(idx,v[idx]));\n   \
    \     }\n        std::pair<int,T> res=std::make_pair(-1,std::numeric_limits<T>::max());\n\
    \n        {\n            int idx=s/b*b+backet[s/b]->query(s%b,b);\n          \
    \  res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));\n        }\n\n       \
    \ if(s/b+1!=t/b)res=argmin<int,T>()(res,st->get(s/b+1,t/b).unwrap());\n\n    \
    \    if(t%b!=0){\n            int idx=t/b*b+backet[t/b]->query(0,t%b);\n     \
    \       res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));\n        }\n\n  \
    \      return maybe<std::pair<int,T>>(res);\n    }\n};\n"
  code: "#pragma once\n#include<assert.h>\n#include<vector>\n#include<stack>\n#include<numeric>\n\
    #include<cmath>\n#include<algorithm>\n#include\"small_rmq.hpp\"\n#include\"sparse_table.hpp\"\
    \n#include\"../functional/argmin.hpp\"\n\n/**\n * @brief RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;\n\
    \ * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n */\n\ntemplate<typename\
    \ T>\nclass arg_rmq{\n    constexpr static int b=64;\n    std::vector<T>v;\n \
    \   std::vector<small_rmq<T>*>backet;\n    sparse_table<std::pair<int,T>,argmin<int,T>>*\
    \ st=0;\n    public:\n    arg_rmq(std::vector<T>v):v(v){\n        std::vector<std::pair<int,T>>tmp2;\n\
    \        for(int i=0;i<(int)v.size();i+=b){\n            std::vector<T>tmp;\n\
    \            T mn=std::numeric_limits<T>::max();\n            int idx=-1;\n  \
    \          for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j]){\n                    mn=v[i+j];\n            \
    \        idx=i+j;\n                }\n            }\n            tmp2.emplace_back(idx,mn);\n\
    \            backet.push_back(new small_rmq<T>(tmp));\n        }\n        st=new\
    \ sparse_table<std::pair<int,T>,argmin<int,T>>(tmp2);\n    }\n    maybe<std::pair<int,T>>\
    \ query(int s,int t){\n        if(s==t)return maybe<std::pair<int,T>>();\n   \
    \     if(s/b==t/b){\n            int idx=s/b*b+backet[s/b]->query(s%b,t%b);\n\
    \            return maybe<std::pair<int,T>>(std::make_pair(idx,v[idx]));\n   \
    \     }\n        std::pair<int,T> res=std::make_pair(-1,std::numeric_limits<T>::max());\n\
    \n        {\n            int idx=s/b*b+backet[s/b]->query(s%b,b);\n          \
    \  res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));\n        }\n\n       \
    \ if(s/b+1!=t/b)res=argmin<int,T>()(res,st->get(s/b+1,t/b).unwrap());\n\n    \
    \    if(t%b!=0){\n            int idx=t/b*b+backet[t/b]->query(0,t%b);\n     \
    \       res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));\n        }\n\n  \
    \      return maybe<std::pair<int,T>>(res);\n    }\n};"
  dependsOn:
  - data_structure/small_rmq.hpp
  - data_structure/sparse_table.hpp
  - alga/maybe.hpp
  - functional/argmin.hpp
  isVerificationFile: false
  path: data_structure/arg_rmq.hpp
  requiredBy:
  - graph_tree/lca.hpp
  timestamp: '2020-09-19 10:39:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph_tree/test/LC_lca.test.cpp
documentation_of: data_structure/arg_rmq.hpp
layout: document
redirect_from:
- /library/data_structure/arg_rmq.hpp
- /library/data_structure/arg_rmq.hpp.html
title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
---
