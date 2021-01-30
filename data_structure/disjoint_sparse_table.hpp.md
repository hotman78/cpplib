---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_disjoint_sparse_table.test.cpp
    title: data_structure/test/LC_disjoint_sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: DisjointSparseTable
    links: []
  bundledCode: "#line 2 \"data_structure/disjoint_sparse_table.hpp\"\n#include<functional>\n\
    #include<vector>\n\n/**\n * @brief DisjointSparseTable\n */\n\ntemplate<typename\
    \ T,typename F=std::plus<T>>\nclass disjoint_sparse_table{\n\tT** table;\n\tT*\
    \ data;\n\tint n=1,cnt=0;\n\tpublic:\n\tF f;\n\tdisjoint_sparse_table(const std::vector<T>&\
    \ v,F f):f(f){init(v);}\n\tdisjoint_sparse_table(const std::vector<T>& v):f(F()){init(v);}\n\
    \tvoid init(const std::vector<T>& v){\n\t\twhile(n<(int)v.size())n<<=1,cnt++;\n\
    \t\ttable=new T*[cnt];\n\t\tfor(int i=0;i<cnt;i++){\n\t\t\ttable[i]=new T[n]();\n\
    \t\t}\n\t\tdata =new T[n];\n\t\tfor(int i=0;i<(int)v.size();i++)data[i]=v[i];\n\
    \t\tfor(int i=0;i<cnt;i++){\n\t\t\tfor(int j=0;j<(n>>(i+1));j++){\n\t\t\t\tconst\
    \ int mid=(j<<(i+1))+(1<<i);\n\t\t\t\tfor(int k=0;k<(1<<i);k++){\n\t\t\t\t\tif(k==0){\n\
    \t\t\t\t\t\tif(0<=mid-1&&mid-1<(int)v.size())table[i][mid-1]=v[mid-1];\n\t\t\t\
    \t\t\tif(0<=mid&&mid<(int)v.size())table[i][mid]=v[mid];\n\t\t\t\t\t}\n\t\t\t\t\
    \telse{\n\t\t\t\t\t\tif(0<=mid-1-k&&mid-1-k<(int)v.size())table[i][mid-1-k]=f(table[i][mid-k],v[mid-1-k]);\n\
    \t\t\t\t\t\tif(0<=mid+k&&mid+k<(int)v.size())table[i][mid+k]=f(table[i][mid+k-1],v[mid+k]);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tT get(int l,int r){\n\t\tr--;\n\
    \t\tif(l==r)return data[l];\n\t\tconst int t=31-__builtin_clz((int)(l^r));\n\t\
    \treturn f(table[t][l],table[t][r]);\n\t}\n};\n"
  code: "#pragma once\n#include<functional>\n#include<vector>\n\n/**\n * @brief DisjointSparseTable\n\
    \ */\n\ntemplate<typename T,typename F=std::plus<T>>\nclass disjoint_sparse_table{\n\
    \tT** table;\n\tT* data;\n\tint n=1,cnt=0;\n\tpublic:\n\tF f;\n\tdisjoint_sparse_table(const\
    \ std::vector<T>& v,F f):f(f){init(v);}\n\tdisjoint_sparse_table(const std::vector<T>&\
    \ v):f(F()){init(v);}\n\tvoid init(const std::vector<T>& v){\n\t\twhile(n<(int)v.size())n<<=1,cnt++;\n\
    \t\ttable=new T*[cnt];\n\t\tfor(int i=0;i<cnt;i++){\n\t\t\ttable[i]=new T[n]();\n\
    \t\t}\n\t\tdata =new T[n];\n\t\tfor(int i=0;i<(int)v.size();i++)data[i]=v[i];\n\
    \t\tfor(int i=0;i<cnt;i++){\n\t\t\tfor(int j=0;j<(n>>(i+1));j++){\n\t\t\t\tconst\
    \ int mid=(j<<(i+1))+(1<<i);\n\t\t\t\tfor(int k=0;k<(1<<i);k++){\n\t\t\t\t\tif(k==0){\n\
    \t\t\t\t\t\tif(0<=mid-1&&mid-1<(int)v.size())table[i][mid-1]=v[mid-1];\n\t\t\t\
    \t\t\tif(0<=mid&&mid<(int)v.size())table[i][mid]=v[mid];\n\t\t\t\t\t}\n\t\t\t\t\
    \telse{\n\t\t\t\t\t\tif(0<=mid-1-k&&mid-1-k<(int)v.size())table[i][mid-1-k]=f(table[i][mid-k],v[mid-1-k]);\n\
    \t\t\t\t\t\tif(0<=mid+k&&mid+k<(int)v.size())table[i][mid+k]=f(table[i][mid+k-1],v[mid+k]);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tT get(int l,int r){\n\t\tr--;\n\
    \t\tif(l==r)return data[l];\n\t\tconst int t=31-__builtin_clz((int)(l^r));\n\t\
    \treturn f(table[t][l],table[t][r]);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2020-09-18 13:26:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_disjoint_sparse_table.test.cpp
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/disjoint_sparse_table.hpp
- /library/data_structure/disjoint_sparse_table.hpp.html
title: DisjointSparseTable
---
