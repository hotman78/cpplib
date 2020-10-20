---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: math/test/AOJ_binary_search.test.cpp
    title: math/test/AOJ_binary_search.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 2 \"math/binary_search.hpp\"\n#include<functional>\n/**\n *\
    \ @brief \u4E8C\u5206\u63A2\u7D22\n */\ntemplate<typename F>\nlong long bs(long\
    \ long mn,long long mx,F func){\n    mn--;\n    mx++;\n\twhile(mx-mn>1){\n\t\t\
    long long mid=(mn+mx)/2;\n\t\tif(!func(mid))mx=mid;\n\t\telse mn=mid;\n\t}\n \
    \   return mn;\n}\n"
  code: "#pragma once\n#include<functional>\n/**\n * @brief \u4E8C\u5206\u63A2\u7D22\
    \n */\ntemplate<typename F>\nlong long bs(long long mn,long long mx,F func){\n\
    \    mn--;\n    mx++;\n\twhile(mx-mn>1){\n\t\tlong long mid=(mn+mx)/2;\n\t\tif(!func(mid))mx=mid;\n\
    \t\telse mn=mid;\n\t}\n    return mn;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/binary_search.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - math/test/AOJ_binary_search.test.cpp
documentation_of: math/binary_search.hpp
layout: document
redirect_from:
- /library/math/binary_search.hpp
- /library/math/binary_search.hpp.html
title: "\u4E8C\u5206\u63A2\u7D22"
---
