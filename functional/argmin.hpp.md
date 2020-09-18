---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"functional/argmin.hpp\"\n\ntemplate<typename T,typename\
    \ E>\nstruct argmin{\n    pair<T,E> operator()(const pair<T,E>& s,const pair<T,E>&\
    \ t){\n        return s.second<=t.second?s:t;\n    }\n};\n"
  code: "#pragma once\n\ntemplate<typename T,typename E>\nstruct argmin{\n    pair<T,E>\
    \ operator()(const pair<T,E>& s,const pair<T,E>& t){\n        return s.second<=t.second?s:t;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: functional/argmin.hpp
  requiredBy: []
  timestamp: '2020-09-18 14:18:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: functional/argmin.hpp
layout: document
redirect_from:
- /library/functional/argmin.hpp
- /library/functional/argmin.hpp.html
title: functional/argmin.hpp
---
