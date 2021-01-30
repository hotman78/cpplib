---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_swag.test.cpp
    title: data_structure/test/LC_swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E00\u6B21\u95A2\u6570\u306E\u5408\u6210"
    links: []
  bundledCode: "#line 2 \"functional/composite.hpp\"\n#include<tuple>\n\n/**\n * @brief\
    \ \u4E00\u6B21\u95A2\u6570\u306E\u5408\u6210\n */\n\ntemplate<typename T>\nstruct\
    \ composite{\n    //t(s(x))\n    std::pair<T,T> operator()(const std::pair<T,T>&\
    \ s,const std::pair<T,T>& t){\n        return std::make_pair(s.first*t.first,s.second*t.first+t.second);\n\
    \    }\n};\n"
  code: "#pragma once\n#include<tuple>\n\n/**\n * @brief \u4E00\u6B21\u95A2\u6570\u306E\
    \u5408\u6210\n */\n\ntemplate<typename T>\nstruct composite{\n    //t(s(x))\n\
    \    std::pair<T,T> operator()(const std::pair<T,T>& s,const std::pair<T,T>& t){\n\
    \        return std::make_pair(s.first*t.first,s.second*t.first+t.second);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: functional/composite.hpp
  requiredBy: []
  timestamp: '2020-09-18 14:44:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_swag.test.cpp
documentation_of: functional/composite.hpp
layout: document
redirect_from:
- /library/functional/composite.hpp
- /library/functional/composite.hpp.html
title: "\u4E00\u6B21\u95A2\u6570\u306E\u5408\u6210"
---
