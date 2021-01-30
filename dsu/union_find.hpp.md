---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: dsu/test/union_find.test.cpp
    title: dsu/test/union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union Find
    links:
    - https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0
  bundledCode: "#line 1 \"dsu/union_find.hpp\"\n/**\r\n * @brief Union Find\r\n *\
    \ @see https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0\r\
    \n */\r\n\r\nclass UF{\r\n    public:\r\n    vector<int> data;\r\n    int sz;\r\
    \n\tpublic:\r\n    UF(int sz):sz(sz){data.resize(sz,-1);}\r\n    bool unite(int\
    \ x,int y){\r\n        x=root(x);y=root(y);\r\n        if(x==y)return 0;\r\n \
    \       if(data[x]>data[y])swap(x,y);\r\n\t\tdata[x]+=data[y];\r\n\t\tdata[y]=x;\r\
    \n\t\tsz--;\r\n        return 1;\r\n    }\r\n    inline int root(int x){return\
    \ data[x]<0?x:data[x]=root(data[x]);}\r\n    inline bool same(int x, int y){return\
    \ root(x)==root(y);}\r\n    inline int size(){return sz;}\r\n\tinline int size(int\
    \ x){return -data[root(x)];}\r\n};\n"
  code: "/**\r\n * @brief Union Find\r\n * @see https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0\r\
    \n */\r\n\r\nclass UF{\r\n    public:\r\n    vector<int> data;\r\n    int sz;\r\
    \n\tpublic:\r\n    UF(int sz):sz(sz){data.resize(sz,-1);}\r\n    bool unite(int\
    \ x,int y){\r\n        x=root(x);y=root(y);\r\n        if(x==y)return 0;\r\n \
    \       if(data[x]>data[y])swap(x,y);\r\n\t\tdata[x]+=data[y];\r\n\t\tdata[y]=x;\r\
    \n\t\tsz--;\r\n        return 1;\r\n    }\r\n    inline int root(int x){return\
    \ data[x]<0?x:data[x]=root(data[x]);}\r\n    inline bool same(int x, int y){return\
    \ root(x)==root(y);}\r\n    inline int size(){return sz;}\r\n\tinline int size(int\
    \ x){return -data[root(x)];}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu/union_find.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:48:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - dsu/test/union_find.test.cpp
documentation_of: dsu/union_find.hpp
layout: document
redirect_from:
- /library/dsu/union_find.hpp
- /library/dsu/union_find.hpp.html
title: Union Find
---
