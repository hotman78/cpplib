---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"math/carmichael_function.hpp\"\n#include<map>\n/**\n * @brief\
    \ \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\n */\ntemplate<typename T>\n\
    auto carmichael_function(T n){\n    map<T,long long>ret;\n    for(auto i=2;i*i<=n;i++){\n\
    \        while(n%i==0){\n            ret[i]++;\n            n/=i;\n        }\n\
    \    }\n    if(n!=1)ret[n]=1;\n    long long res=1;\n    for(auto d:ret){\n  \
    \      if(d.first==2){\n            if(d.second<3)res=pow(d.first,d.second-1);\n\
    \            else res=pow(d.first,d.second-2);\n        }\n        else res=lcm(res,(long\
    \ long)pow(d.first,d.second-1)*(d.first-1));\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include<map>\n/**\n * @brief \u30AB\u30FC\u30DE\u30A4\u30B1\
    \u30EB\u95A2\u6570\n */\ntemplate<typename T>\nauto carmichael_function(T n){\n\
    \    map<T,long long>ret;\n    for(auto i=2;i*i<=n;i++){\n        while(n%i==0){\n\
    \            ret[i]++;\n            n/=i;\n        }\n    }\n    if(n!=1)ret[n]=1;\n\
    \    long long res=1;\n    for(auto d:ret){\n        if(d.first==2){\n       \
    \     if(d.second<3)res=pow(d.first,d.second-1);\n            else res=pow(d.first,d.second-2);\n\
    \        }\n        else res=lcm(res,(long long)pow(d.first,d.second-1)*(d.first-1));\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/carmichael_function.hpp
  requiredBy: []
  timestamp: '2020-09-13 18:00:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichael_function.hpp
layout: document
redirect_from:
- /library/math/carmichael_function.hpp
- /library/math/carmichael_function.hpp.html
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
---
