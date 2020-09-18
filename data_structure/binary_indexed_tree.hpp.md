---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: BinaryIndexedTree
    links: []
  bundledCode: "#line 2 \"data_structure/binary_indexed_tree.hpp\"\n#include<vector>\r\
    \n\r\n/**\r\n * @brief BinaryIndexedTree\r\n */\r\n\r\nstruct BIT{\r\n    std::vector<long\
    \ long> bit;\r\n    int n;\r\n    BIT(long long n):n(n){\r\n        //bit.resize(n+1,0);\r\
    \n    }\r\n    //0-indexed [0,x)-sum\r\n    long long sum(long long x){\r\n  \
    \      long long res=0;\r\n        for(int i=x;i;i-=i&-i)res+=bit[i];\r\n    \
    \    return res;\r\n    }\r\n    //0-indexed [x,y)-sum\r\n    long long sum(long\
    \ long x,long long y){\r\n        return sum(y)-sum(x);\r\n    }\r\n    //0-indexed\r\
    \n    void add(long long x,long long val){\r\n        ++x;\r\n        if(x>=n)return;\r\
    \n        for(long long i=x;i<=n;i+=i&-i)bit[i]+=val;\r\n    }\r\n};\n"
  code: "#pragma once\r\n#include<vector>\r\n\r\n/**\r\n * @brief BinaryIndexedTree\r\
    \n */\r\n\r\nstruct BIT{\r\n    std::vector<long long> bit;\r\n    int n;\r\n\
    \    BIT(long long n):n(n){\r\n        //bit.resize(n+1,0);\r\n    }\r\n    //0-indexed\
    \ [0,x)-sum\r\n    long long sum(long long x){\r\n        long long res=0;\r\n\
    \        for(int i=x;i;i-=i&-i)res+=bit[i];\r\n        return res;\r\n    }\r\n\
    \    //0-indexed [x,y)-sum\r\n    long long sum(long long x,long long y){\r\n\
    \        return sum(y)-sum(x);\r\n    }\r\n    //0-indexed\r\n    void add(long\
    \ long x,long long val){\r\n        ++x;\r\n        if(x>=n)return;\r\n      \
    \  for(long long i=x;i<=n;i+=i&-i)bit[i]+=val;\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_indexed_tree.hpp
- /library/data_structure/binary_indexed_tree.hpp.html
title: BinaryIndexedTree
---
