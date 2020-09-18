---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: RMQ&amp;lt;O(N),O(1)&amp;gt;
    links:
    - https://noshi91.hatenablog.com/entry/2018/08/16/125415
  bundledCode: "#line 2 \"data_structure/RMQ.hpp\"\n#include<assert.h>\n#include<vector>\n\
    #include<numeric>\n#include<cmath>\n\n/**\n * @brief RMQ&amp;lt;O(N),O(1)&amp;gt;\n\
    \ * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n */\n\ntemplate<typename\
    \ T>\nclass RMQ{\n    class small_rmq{\n        using u64=unsigned long long;\n\
    \        std::vector<u64>table;\n        std::vector<T> v;\n        public:\n\
    \        small_rmq(std::vector<T> v):v(v){\n            assert(v.size()<=64);\n\
    \            vector<int>tmp(v.size());\n            table.resize(v.size(),0);\n\
    \            stack<T>stk;\n            for(int i=0;i<(int)v.size();++i){\n   \
    \             tmp.resize(v.size());\n                while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                    stk.pop();\n                }\n                tmp[i]=stk.empty()?-1:stk.top();\n\
    \                stk.emplace(i);\n            }\n            for(int i=0;i<(int)v.size();++i){\n\
    \                if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n    \
    \        }\n        }\n        T query(int l,int r){\n            if(l==r)return\
    \ numeric_limits<T>::max();\n            const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \            if(tmp==0)return v[r-1];\n            else return v[__builtin_ctzll(tmp)];\n\
    \        }\n    };\n    class sparse_table{\n        std::vector<std::vector<T>>data;\n\
    \        public:\n        sparse_table(std::vector<T> v){\n            int n=v.size(),log=log2(n)+1;\n\
    \            data.resize(n,vector<T>(log));\n            for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \            for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n        \
    \        data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n            }\n\
    \        }\n        T get(int l,int r){\n            if(l==r)return std::numeric_limits<T>::max();\n\
    \            if(r<l)swap(l,r);\n            int k=log2(r-l);\n            return\
    \ f(data[l][k],data[r-(1<<k)][k]);\n        }\n        constexpr static T e=std::numeric_limits<T>::max();\n\
    \        T f(T s,T t){\n            return std::min(s,t);\n        }\n    };\n\
    \    constexpr static int b=64;\n    std::vector<T>v;\n    std::vector<small_rmq*>backet;\n\
    \    sparse_table* st=0;\n    public:\n    RMQ(std::vector<T>v):v(v){\n      \
    \  std::vector<T>tmp2;\n        for(int i=0;i<(int)v.size();i+=b){\n         \
    \   std::vector<T>tmp;\n            T mn=std::numeric_limits<T>::max();\n    \
    \        for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j])mn=v[i+j];\n            }\n            tmp2.push_back(mn);\n\
    \            backet.push_back(new small_rmq(tmp));\n        }\n        st=new\
    \ sparse_table(tmp2);\n    }\n    T query(int s,int t){\n        if(s/b==t/b)return\
    \ backet[s/b]->query(s%b,t%b);\n        return std::min({backet[s/b]->query(s%b,b),st->get(s/b+1,t/b),backet[t/b]->query(0,t%b)});\n\
    \    }\n};\n"
  code: "#pragma once\n#include<assert.h>\n#include<vector>\n#include<numeric>\n#include<cmath>\n\
    \n/**\n * @brief RMQ&amp;lt;O(N),O(1)&amp;gt;\n * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n\
    \ */\n\ntemplate<typename T>\nclass RMQ{\n    class small_rmq{\n        using\
    \ u64=unsigned long long;\n        std::vector<u64>table;\n        std::vector<T>\
    \ v;\n        public:\n        small_rmq(std::vector<T> v):v(v){\n           \
    \ assert(v.size()<=64);\n            vector<int>tmp(v.size());\n            table.resize(v.size(),0);\n\
    \            stack<T>stk;\n            for(int i=0;i<(int)v.size();++i){\n   \
    \             tmp.resize(v.size());\n                while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                    stk.pop();\n                }\n                tmp[i]=stk.empty()?-1:stk.top();\n\
    \                stk.emplace(i);\n            }\n            for(int i=0;i<(int)v.size();++i){\n\
    \                if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n    \
    \        }\n        }\n        T query(int l,int r){\n            if(l==r)return\
    \ numeric_limits<T>::max();\n            const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \            if(tmp==0)return v[r-1];\n            else return v[__builtin_ctzll(tmp)];\n\
    \        }\n    };\n    class sparse_table{\n        std::vector<std::vector<T>>data;\n\
    \        public:\n        sparse_table(std::vector<T> v){\n            int n=v.size(),log=log2(n)+1;\n\
    \            data.resize(n,vector<T>(log));\n            for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \            for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n        \
    \        data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n            }\n\
    \        }\n        T get(int l,int r){\n            if(l==r)return std::numeric_limits<T>::max();\n\
    \            if(r<l)swap(l,r);\n            int k=log2(r-l);\n            return\
    \ f(data[l][k],data[r-(1<<k)][k]);\n        }\n        constexpr static T e=std::numeric_limits<T>::max();\n\
    \        T f(T s,T t){\n            return std::min(s,t);\n        }\n    };\n\
    \    constexpr static int b=64;\n    std::vector<T>v;\n    std::vector<small_rmq*>backet;\n\
    \    sparse_table* st=0;\n    public:\n    RMQ(std::vector<T>v):v(v){\n      \
    \  std::vector<T>tmp2;\n        for(int i=0;i<(int)v.size();i+=b){\n         \
    \   std::vector<T>tmp;\n            T mn=std::numeric_limits<T>::max();\n    \
    \        for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j])mn=v[i+j];\n            }\n            tmp2.push_back(mn);\n\
    \            backet.push_back(new small_rmq(tmp));\n        }\n        st=new\
    \ sparse_table(tmp2);\n    }\n    T query(int s,int t){\n        if(s/b==t/b)return\
    \ backet[s/b]->query(s%b,t%b);\n        return std::min({backet[s/b]->query(s%b,b),st->get(s/b+1,t/b),backet[t/b]->query(0,t%b)});\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/RMQ.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:12:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/RMQ.hpp
layout: document
redirect_from:
- /library/data_structure/RMQ.hpp
- /library/data_structure/RMQ.hpp.html
title: RMQ&amp;lt;O(N),O(1)&amp;gt;
---
