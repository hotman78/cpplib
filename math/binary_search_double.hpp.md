---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u4E8C\u5206\u63A2\u7D22(double)"
    links: []
  bundledCode: "#line 2 \"math/binary_search_double.hpp\"\n#include<functional>\n\
    /**\n * @brief \u4E8C\u5206\u63A2\u7D22(double)\n */\n\ntemplate<typename F>\n\
    long double bs(long double mn,long double mx,F func) {\n    long double left =\
    \ mn;\n    long double right =mx;\n    for(int i=0;i<100;i++){\n        long double\
    \ mid=(right+left)*0.5;\n        if (!func(mid)) right = mid;\n        else left\
    \ = mid;\n    }\n    return left;\n}\n"
  code: "#pragma once\n#include<functional>\n/**\n * @brief \u4E8C\u5206\u63A2\u7D22\
    (double)\n */\n\ntemplate<typename F>\nlong double bs(long double mn,long double\
    \ mx,F func) {\n    long double left = mn;\n    long double right =mx;\n    for(int\
    \ i=0;i<100;i++){\n        long double mid=(right+left)*0.5;\n        if (!func(mid))\
    \ right = mid;\n        else left = mid;\n    }\n    return left;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/binary_search_double.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binary_search_double.hpp
layout: document
redirect_from:
- /library/math/binary_search_double.hpp
- /library/math/binary_search_double.hpp.html
title: "\u4E8C\u5206\u63A2\u7D22(double)"
---
