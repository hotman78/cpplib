---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570(ModLog)"
  - icon: ':x:'
    path: math/tetration.hpp
    title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: math/test/LC_mod_log.test.cpp
    title: math/test/LC_mod_log.test.cpp
  - icon: ':x:'
    path: math/test/LC_tetration.test.cpp
    title: math/test/LC_tetration.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
    links: []
  bundledCode: "#line 1 \"math/euler_phi.hpp\"\n/**\n * @brief \u30AA\u30A4\u30E9\u30FC\
    \u306E\u30D5\u30A1\u30A4\u95A2\u6570\n */\n\nlong long euler_phi(long long n)\
    \ {\n    long long ret = n;\n    for(long long i=2;i*i<=n;i++) {\n        if(n%i==0)\
    \ {\n            ret-=ret/i;\n            while(n%i==0)n/=i;\n        }\n    }\n\
    \    if(n>1)ret-=ret/n;\n    return ret;\n}\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\
    \n */\n\nlong long euler_phi(long long n) {\n    long long ret = n;\n    for(long\
    \ long i=2;i*i<=n;i++) {\n        if(n%i==0) {\n            ret-=ret/i;\n    \
    \        while(n%i==0)n/=i;\n        }\n    }\n    if(n>1)ret-=ret/n;\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy:
  - math/mod_log.hpp
  - math/tetration.hpp
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - math/test/LC_tetration.test.cpp
  - math/test/LC_mod_log.test.cpp
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
---
