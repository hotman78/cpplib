---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E"
    links: []
  bundledCode: "#line 2 \"functional/argmax.hpp\"\n#include<tuple>\n\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E\n */\n\ntemplate<typename T,typename\
    \ E>\nstruct argmax{\n    std::pair<T,E> operator()(const std::pair<T,E>& s,const\
    \ std::pair<T,E>& t){\n        return s.second>=t.second?s:t;\n    }\n};\n"
  code: "#pragma once\n#include<tuple>\n\n/**\n * @brief \u6700\u5927\u5024\u3068\u305D\
    \u306E\u4F4D\u7F6E\n */\n\ntemplate<typename T,typename E>\nstruct argmax{\n \
    \   std::pair<T,E> operator()(const std::pair<T,E>& s,const std::pair<T,E>& t){\n\
    \        return s.second>=t.second?s:t;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: functional/argmax.hpp
  requiredBy: []
  timestamp: '2020-09-18 14:44:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: functional/argmax.hpp
layout: document
redirect_from:
- /library/functional/argmax.hpp
- /library/functional/argmax.hpp.html
title: "\u6700\u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E"
---
