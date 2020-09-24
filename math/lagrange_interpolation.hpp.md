---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u5B8C(\u9023\u7D9A\
      \u70B9->\u4E00\u70B9)"
    links: []
  bundledCode: "#line 2 \"math/lagrange_interpolation.hpp\"\n#include<vector>\n/**\n\
    \ * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u5B8C(\u9023\u7D9A\u70B9\
    ->\u4E00\u70B9)\n */\n\ntemplate<typename T>\nT lagrange_interpolation(std::vector<T>v,long\
    \ long n){\n    long long k=v.size();\n    if(n<k)return v[n];\n    std::vector<T>\
    \ tmp1(k+1,1),tmp2(k+1,1);\n    T ans=0;\n    for(int i=0;i<k;++i)tmp1[i]=(i?tmp1[i-1]:1)*(n-i);\n\
    \    for(int i=k-1;i>=0;--i)tmp2[i]=(i<k-1?tmp2[i+1]:1)*(n-i);\n    for(int i=0;i<k;++i){\n\
    \        ans+=v[i]*(i<k-1?tmp2[i+1]:1)*(i?tmp1[i-1]:1)/(T(k-1-i).fact()*T(i).fact()*T((k-1-i)%2?-1:1));\n\
    \    }\n    return ans;\n}\n"
  code: "#pragma once\n#include<vector>\n/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\
    \u30E5\u88DC\u5B8C(\u9023\u7D9A\u70B9->\u4E00\u70B9)\n */\n\ntemplate<typename\
    \ T>\nT lagrange_interpolation(std::vector<T>v,long long n){\n    long long k=v.size();\n\
    \    if(n<k)return v[n];\n    std::vector<T> tmp1(k+1,1),tmp2(k+1,1);\n    T ans=0;\n\
    \    for(int i=0;i<k;++i)tmp1[i]=(i?tmp1[i-1]:1)*(n-i);\n    for(int i=k-1;i>=0;--i)tmp2[i]=(i<k-1?tmp2[i+1]:1)*(n-i);\n\
    \    for(int i=0;i<k;++i){\n        ans+=v[i]*(i<k-1?tmp2[i+1]:1)*(i?tmp1[i-1]:1)/(T(k-1-i).fact()*T(i).fact()*T((k-1-i)%2?-1:1));\n\
    \    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/lagrange_interpolation.hpp
- /library/math/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u5B8C(\u9023\u7D9A\u70B9->\u4E00\
  \u70B9)"
---
