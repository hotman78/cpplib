---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D04\u6570\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"math/divisor_list.hpp\"\n/**\n * @brief \u7D04\u6570\u5217\
    \u6319\n */\ntemplate<typename T>\nauto divisor_list(T n){\n    vector<T>res;\n\
    \    for(int i=1;i<=sqrt(n);i++){\n        if(n%i)continue;\n        res.push_back(i);\n\
    \        if(i*i!=n)res.push_back(n/i);\n    }\n    sort(res.begin(),res.end());\n\
    \    return res;\n}\n"
  code: "#pragma once\n/**\n * @brief \u7D04\u6570\u5217\u6319\n */\ntemplate<typename\
    \ T>\nauto divisor_list(T n){\n    vector<T>res;\n    for(int i=1;i<=sqrt(n);i++){\n\
    \        if(n%i)continue;\n        res.push_back(i);\n        if(i*i!=n)res.push_back(n/i);\n\
    \    }\n    sort(res.begin(),res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor_list.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor_list.hpp
layout: document
redirect_from:
- /library/math/divisor_list.hpp
- /library/math/divisor_list.hpp.html
title: "\u7D04\u6570\u5217\u6319"
---
