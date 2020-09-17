---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data_structure/disjoint_sparse_table.hpp\"\n\ntemplate<typename\
    \ T>\nclass disjoint_sparse_table{\n\tT** table;\n\tT* data;\n\tint n=1,cnt=0;\n\
    \tpublic:\n\tdisjoint_sparse_table(const vector<T>& v){\n\t\twhile(n<(int)v.size())n<<=1,cnt++;\n\
    \t\ttable=new T*[cnt];\n\t\tfor(int i=0;i<cnt;i++){\n\t\t\ttable[i]=new T[n]();\n\
    \t\t}\n\t\tdata =new T[n];\n\t\tfor(int i=0;i<(int)v.size();i++)data[i]=v[i];\n\
    \t\tfor(int i=0;i<cnt;i++){\n\t\t\tfor(int j=0;j<(n>>(i+1));j++){\n\t\t\t\tconst\
    \ int mid=(j<<(i+1))+(1<<i);\n\t\t\t\tfor(int k=0;k<(1<<i);k++){\n\t\t\t\t\tif(k==0){\n\
    \t\t\t\t\t\tif(0<=mid-1&&mid-1<(int)v.size())table[i][mid-1]=v[mid-1];\n\t\t\t\
    \t\t\tif(0<=mid&&mid<(int)v.size())table[i][mid]=v[mid];\n\t\t\t\t\t}\n\t\t\t\t\
    \telse{\n\t\t\t\t\t\tif(0<=mid-1-k&&mid-1-k<(int)v.size())table[i][mid-1-k]=f(table[i][mid-k],v[mid-1-k]);\n\
    \t\t\t\t\t\tif(0<=mid+k&&mid+k<(int)v.size())table[i][mid+k]=f(table[i][mid+k-1],v[mid+k]);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tT get(auto l,auto r){\n\t\tr--;\n\
    \t\tif(l==r)return data[l];\n\t\tconst int t=31-__builtin_clz((int)(l^r));\n\t\
    \treturn f(table[t][l],table[t][r]);\n\t}\n\tinline T f(const T& a,const T& b){\n\
    \t\treturn min(a,b);\n\t}\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nclass disjoint_sparse_table{\n\tT**\
    \ table;\n\tT* data;\n\tint n=1,cnt=0;\n\tpublic:\n\tdisjoint_sparse_table(const\
    \ vector<T>& v){\n\t\twhile(n<(int)v.size())n<<=1,cnt++;\n\t\ttable=new T*[cnt];\n\
    \t\tfor(int i=0;i<cnt;i++){\n\t\t\ttable[i]=new T[n]();\n\t\t}\n\t\tdata =new\
    \ T[n];\n\t\tfor(int i=0;i<(int)v.size();i++)data[i]=v[i];\n\t\tfor(int i=0;i<cnt;i++){\n\
    \t\t\tfor(int j=0;j<(n>>(i+1));j++){\n\t\t\t\tconst int mid=(j<<(i+1))+(1<<i);\n\
    \t\t\t\tfor(int k=0;k<(1<<i);k++){\n\t\t\t\t\tif(k==0){\n\t\t\t\t\t\tif(0<=mid-1&&mid-1<(int)v.size())table[i][mid-1]=v[mid-1];\n\
    \t\t\t\t\t\tif(0<=mid&&mid<(int)v.size())table[i][mid]=v[mid];\n\t\t\t\t\t}\n\t\
    \t\t\t\telse{\n\t\t\t\t\t\tif(0<=mid-1-k&&mid-1-k<(int)v.size())table[i][mid-1-k]=f(table[i][mid-k],v[mid-1-k]);\n\
    \t\t\t\t\t\tif(0<=mid+k&&mid+k<(int)v.size())table[i][mid+k]=f(table[i][mid+k-1],v[mid+k]);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tT get(auto l,auto r){\n\t\tr--;\n\
    \t\tif(l==r)return data[l];\n\t\tconst int t=31-__builtin_clz((int)(l^r));\n\t\
    \treturn f(table[t][l],table[t][r]);\n\t}\n\tinline T f(const T& a,const T& b){\n\
    \t\treturn min(a,b);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/disjoint_sparse_table.hpp
- /library/data_structure/disjoint_sparse_table.hpp.html
title: data_structure/disjoint_sparse_table.hpp
---
