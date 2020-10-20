---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sum_power_poly_limit.hpp\"\n#include<vector>\n\n//\
    \ \\sum_{i=0}^{\\infty} r^i f(i) (deg f <= d)\ntemplate<typename T>\nT sum_power_poly_limit(T\
    \ r,int d,std::vector<T>fs){\n    vector<T>rr(d+1);\n    rr[0]=1;\n    for(int\
    \ i=1;i<d+1;++i)rr[i]=rr[i-1]*r;\n    T ans=0,sumRF=0;\n    for(int i=0;i<d+1;++i){\n\
    \        sumRF+=rr[i]*fs[i];\n        ans += T(d-i).fact_inv()*T(i+1).fact_inv()*(((d\
    \ - i)&1)?-1:1)*rr[d - i]*sumRF;\n    }\n    ans *= T(1-r).pow(MOD-(d+1))*T(d+1).fact();\n\
    \    return ans;\n}\n"
  code: "#pragma once\n#include<vector>\n\n// \\sum_{i=0}^{\\infty} r^i f(i) (deg\
    \ f <= d)\ntemplate<typename T>\nT sum_power_poly_limit(T r,int d,std::vector<T>fs){\n\
    \    vector<T>rr(d+1);\n    rr[0]=1;\n    for(int i=1;i<d+1;++i)rr[i]=rr[i-1]*r;\n\
    \    T ans=0,sumRF=0;\n    for(int i=0;i<d+1;++i){\n        sumRF+=rr[i]*fs[i];\n\
    \        ans += T(d-i).fact_inv()*T(i+1).fact_inv()*(((d - i)&1)?-1:1)*rr[d -\
    \ i]*sumRF;\n    }\n    ans *= T(1-r).pow(MOD-(d+1))*T(d+1).fact();\n    return\
    \ ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/sum_power_poly_limit.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sum_power_poly_limit.hpp
layout: document
redirect_from:
- /library/math/sum_power_poly_limit.hpp
- /library/math/sum_power_poly_limit.hpp.html
title: math/sum_power_poly_limit.hpp
---
