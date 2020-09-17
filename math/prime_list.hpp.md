---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: math/test/AOJ_prime_list.test.cpp
    title: math/test/AOJ_prime_list.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7D20\u6570\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"math/prime_list.hpp\"\n#include<vector>\n#include<bitset>\n\
    #include<cmath>\n#include<set>\n\n/**\n * @brief \u7D20\u6570\u5217\u6319\n */\n\
    \nstd::bitset<500'000'001> p;\nstd::vector<long long> prime_list(int n) {\n  \
    \  p.set();\n    p[0]=0;\n    for(int i=2;i*i<=n;++i){\n        if(!p[i])continue;\n\
    \        for(int j=2*i;j<=n;j+=i)p[j]=0;\n    }\n    std::vector<long long>list;\n\
    \    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);\n    return list;\n}\n\n"
  code: "#pragma once\n#include<vector>\n#include<bitset>\n#include<cmath>\n#include<set>\n\
    \n/**\n * @brief \u7D20\u6570\u5217\u6319\n */\n\nstd::bitset<500'000'001> p;\n\
    std::vector<long long> prime_list(int n) {\n    p.set();\n    p[0]=0;\n    for(int\
    \ i=2;i*i<=n;++i){\n        if(!p[i])continue;\n        for(int j=2*i;j<=n;j+=i)p[j]=0;\n\
    \    }\n    std::vector<long long>list;\n    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);\n\
    \    return list;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_list.hpp
  requiredBy: []
  timestamp: '2020-09-13 18:30:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - math/test/AOJ_prime_list.test.cpp
documentation_of: math/prime_list.hpp
layout: document
redirect_from:
- /library/math/prime_list.hpp
- /library/math/prime_list.hpp.html
title: "\u7D20\u6570\u5217\u6319"
---
