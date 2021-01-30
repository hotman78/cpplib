---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "osa_k\u6CD5"
    links: []
  bundledCode: "#line 2 \"math/osa_k.hpp\"\n#include<map>\n\n/**\n * @brief osa_k\u6CD5\
    \n */\n\nstd::map<int,int> osa_k(int n){\n    constexpr int mx=10'000'000;\n \
    \   assert(n<mx);\n    static bool init=false;\n    static int v[mx];\n    static\
    \ vector<int>pr;\n    if(!init){\n        init=true;\n        for(int i=2;i<mx;++i){\n\
    \            if(v[i]==0){\n                v[i]=i;\n                pr.push_back(i);\n\
    \            }\n            for(int j=0;j<(int)pr.size() && pr[j]<=v[i] && i*pr[j]<mx;++j){\n\
    \                v[i*pr[j]]=pr[j];\n            }\n        }\n    }\n    map<int,int>ret;\n\
    \    while(n!=1){\n        ret[v[n]]++;\n        n/=v[n];\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include<map>\n\n/**\n * @brief osa_k\u6CD5\n */\n\nstd::map<int,int>\
    \ osa_k(int n){\n    constexpr int mx=10'000'000;\n    assert(n<mx);\n    static\
    \ bool init=false;\n    static int v[mx];\n    static vector<int>pr;\n    if(!init){\n\
    \        init=true;\n        for(int i=2;i<mx;++i){\n            if(v[i]==0){\n\
    \                v[i]=i;\n                pr.push_back(i);\n            }\n  \
    \          for(int j=0;j<(int)pr.size() && pr[j]<=v[i] && i*pr[j]<mx;++j){\n \
    \               v[i*pr[j]]=pr[j];\n            }\n        }\n    }\n    map<int,int>ret;\n\
    \    while(n!=1){\n        ret[v[n]]++;\n        n/=v[n];\n    }\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osa_k.hpp
layout: document
redirect_from:
- /library/math/osa_k.hpp
- /library/math/osa_k.hpp.html
title: "osa_k\u6CD5"
---
