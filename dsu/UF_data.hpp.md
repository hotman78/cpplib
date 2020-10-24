---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dsu/UF_data.hpp\"\ntemplate<typename T,typename F>\nclass\
    \ UF_data{\n    public:\n    vector<int> data;\n    vector<T>val;\n    int sz;\n\
    \    F merge;\n\tpublic:\n    UF_data(int sz,F merge=F()):sz(sz),merge(merge){data.resize(sz,-1);val.resize(sz,T());}\n\
    \    bool unite(int x,int y){\n        x=root(x);y=root(y);\n        if(x==y)return\
    \ 0;\n        if(data[x]>data[y])swap(x,y);\n\t\tdata[x]+=data[y];\n\t\tdata[y]=x;\n\
    \        val[x]=merge(move(val[x]),move(val[y]));\n\t\tsz--;\n        return 1;\n\
    \    }\n    inline void set(int x,const T&v){\n        x=root(x);\n        val[x]=v;\n\
    \    }\n    inline T get(int x){\n        return val[root(x)];\n    }\n    inline\
    \ int root(int x){return data[x]<0?x:data[x]=root(data[x]);}\n    inline bool\
    \ same(int x, int y){return root(x)==root(y);}\n    inline int size(){return sz;}\n\
    \tinline int size(int x){return -data[root(x)];}\n};\n"
  code: "template<typename T,typename F>\nclass UF_data{\n    public:\n    vector<int>\
    \ data;\n    vector<T>val;\n    int sz;\n    F merge;\n\tpublic:\n    UF_data(int\
    \ sz,F merge=F()):sz(sz),merge(merge){data.resize(sz,-1);val.resize(sz,T());}\n\
    \    bool unite(int x,int y){\n        x=root(x);y=root(y);\n        if(x==y)return\
    \ 0;\n        if(data[x]>data[y])swap(x,y);\n\t\tdata[x]+=data[y];\n\t\tdata[y]=x;\n\
    \        val[x]=merge(move(val[x]),move(val[y]));\n\t\tsz--;\n        return 1;\n\
    \    }\n    inline void set(int x,const T&v){\n        x=root(x);\n        val[x]=v;\n\
    \    }\n    inline T get(int x){\n        return val[root(x)];\n    }\n    inline\
    \ int root(int x){return data[x]<0?x:data[x]=root(data[x]);}\n    inline bool\
    \ same(int x, int y){return root(x)==root(y);}\n    inline int size(){return sz;}\n\
    \tinline int size(int x){return -data[root(x)];}\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu/UF_data.hpp
  requiredBy: []
  timestamp: '2020-10-24 18:26:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/UF_data.hpp
layout: document
redirect_from:
- /library/dsu/UF_data.hpp
- /library/dsu/UF_data.hpp.html
title: dsu/UF_data.hpp
---
