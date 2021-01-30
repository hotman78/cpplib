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
  bundledCode: '#line 2 "math/mod_inv.hpp"

    long long mod_inv(x,m){return x==1?1:m+(-m*mod_inv(m%a,a)+1);}

    '
  code: '#pragma once

    long long mod_inv(x,m){return x==1?1:m+(-m*mod_inv(m%a,a)+1);}'
  dependsOn: []
  isVerificationFile: false
  path: math/mod_inv.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_inv.hpp
layout: document
redirect_from:
- /library/math/mod_inv.hpp
- /library/math/mod_inv.hpp.html
title: math/mod_inv.hpp
---
