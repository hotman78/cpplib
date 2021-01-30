---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dsu/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"dsu/test/union_find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"dsu/union_find.hpp\"\
    \n/**\r\n * @brief Union Find\r\n * @see https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0\r\
    \n */\r\n\r\nclass UF{\r\n    public:\r\n    vector<int> data;\r\n    int sz;\r\
    \n\tpublic:\r\n    UF(int sz):sz(sz){data.resize(sz,-1);}\r\n    bool unite(int\
    \ x,int y){\r\n        x=root(x);y=root(y);\r\n        if(x==y)return 0;\r\n \
    \       if(data[x]>data[y])swap(x,y);\r\n\t\tdata[x]+=data[y];\r\n\t\tdata[y]=x;\r\
    \n\t\tsz--;\r\n        return 1;\r\n    }\r\n    inline int root(int x){return\
    \ data[x]<0?x:data[x]=root(data[x]);}\r\n    inline bool same(int x, int y){return\
    \ root(x)==root(y);}\r\n    inline int size(){return sz;}\r\n\tinline int size(int\
    \ x){return -data[root(x)];}\r\n};\n#line 5 \"dsu/test/union_find.test.cpp\"\n\
    \nint main(){\n    int n,q;\n    cin>>n>>q;\n    UF uf(n);\n    for(int i=0;i<q;++i){\n\
    \        int c,s,t;\n        cin>>c>>s>>t;\n        if(c==0){\n            uf.unite(s,t);\n\
    \        }else{\n            cout<<uf.same(s,t)<<endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#include \"../union_find.hpp\"\n\nint main(){\n    int n,q;\n\
    \    cin>>n>>q;\n    UF uf(n);\n    for(int i=0;i<q;++i){\n        int c,s,t;\n\
    \        cin>>c>>s>>t;\n        if(c==0){\n            uf.unite(s,t);\n      \
    \  }else{\n            cout<<uf.same(s,t)<<endl;\n        }\n    }\n}"
  dependsOn:
  - dsu/union_find.hpp
  isVerificationFile: true
  path: dsu/test/union_find.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 09:48:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: dsu/test/union_find.test.cpp
layout: document
redirect_from:
- /verify/dsu/test/union_find.test.cpp
- /verify/dsu/test/union_find.test.cpp.html
title: dsu/test/union_find.test.cpp
---
