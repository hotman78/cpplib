---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dsu/UF_list.hpp\"\nclass UF{\n    public:\n    vector<int>\
    \ data;\n    int sz;\n\tpublic:\n    UF(int sz):sz(sz){\n        for(int i=0;i<sz;++i)data[i]=i;\n\
    \    }\n    bool unite(int x,int y){\n        data.swap(x,y);\n        return\
    \ 1;\n    }\n};\n"
  code: "class UF{\n    public:\n    vector<int> data;\n    int sz;\n\tpublic:\n \
    \   UF(int sz):sz(sz){\n        for(int i=0;i<sz;++i)data[i]=i;\n    }\n    bool\
    \ unite(int x,int y){\n        data.swap(x,y);\n        return 1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu/UF_list.hpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dsu/UF_list.hpp
layout: document
redirect_from:
- /library/dsu/UF_list.hpp
- /library/dsu/UF_list.hpp.html
title: dsu/UF_list.hpp
---
