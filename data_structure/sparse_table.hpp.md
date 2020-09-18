---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: SparseTable
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n#include<vector>\n#include<functional>\n\
    #include<cmath>\n#include<algorithm>\n\n/**\n * @brief SparseTable\n */\n\ntemplate<typename\
    \ T>\nclass sparse_table{\n    using F=std::function<T(T,T)>;\n    F f;\n    std::vector<std::vector<T>>data;\n\
    \    public:\n    sparse_table(std::vector<T> v,F f):f(f){\n        int n=v.size(),log=log2(n)+1;\n\
    \        data.resize(n,vector<T>(log));\n        for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \        for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    T get(int l,int r){\n        if(r<l)std::swap(l,r);\n \
    \       //assert(0<l||r<=(T)data.size());\n        int k=std::log2(r-l);\n   \
    \     return f(data[l][k],data[r-(1<<k)][k]);\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<functional>\n#include<cmath>\n#include<algorithm>\n\
    \n/**\n * @brief SparseTable\n */\n\ntemplate<typename T>\nclass sparse_table{\n\
    \    using F=std::function<T(T,T)>;\n    F f;\n    std::vector<std::vector<T>>data;\n\
    \    public:\n    sparse_table(std::vector<T> v,F f):f(f){\n        int n=v.size(),log=log2(n)+1;\n\
    \        data.resize(n,vector<T>(log));\n        for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \        for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    T get(int l,int r){\n        if(r<l)std::swap(l,r);\n \
    \       //assert(0<l||r<=(T)data.size());\n        int k=std::log2(r-l);\n   \
    \     return f(data[l][k],data[r-(1<<k)][k]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: SparseTable
---
