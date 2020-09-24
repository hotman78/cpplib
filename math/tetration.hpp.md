---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  - icon: ':x:'
    path: math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: math/test/LC_tetration.test.cpp
    title: math/test/LC_tetration.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
    links: []
  bundledCode: "#line 2 \"math/tetration.hpp\"\n#include<vector>\n#include<algorithm>\n\
    #include<cmath>\n#line 1 \"math/mod_pow.hpp\"\n/**\n * @brief (x^y)%mod\n */\n\
    \nlong long mod_pow(long long x,long long y,long long mod){\n    long long ret=1;\n\
    \    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n        (x*=x)%=mod;\n     \
    \   y>>=1;\n    }\n    return ret;\n}\n#line 1 \"math/euler_phi.hpp\"\n/**\n *\
    \ @brief \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\n */\n\n\
    long long euler_phi(long long n) {\n    long long ret = n;\n    for(long long\
    \ i=2;i*i<=n;i++) {\n        if(n%i==0) {\n            ret-=ret/i;\n         \
    \   while(n%i==0)n/=i;\n        }\n    }\n    if(n>1)ret-=ret/n;\n    return ret;\n\
    }\n#line 7 \"math/tetration.hpp\"\n\n/**\n * @brief \u30C6\u30C8\u30EC\u30FC\u30B7\
    \u30E7\u30F3\n */\n\nlong long tetration(long long a,long long b,long long m){\n\
    \    std::vector<long long> v;\n    long long d=m;\n    while(d!=1){\n       \
    \ v.push_back(d);\n        d=euler_phi(d);\n    }\n    v.push_back(1);\n    if(a==0)return\
    \ (b+1)%2%m;\n    if(m==1)return 0;\n    if(a==1||b==0){\n        return 1;\n\
    \    }\n    if((long long)(v.size())>=b)v.resize(b-1,1);\n    std::reverse(v.begin(),v.end());\n\
    \    long long ans=a;\n    for(auto e:v){\n        long long ad=(ans<=32&&a<e&&std::pow((double)a,ans)<e?0:e);\n\
    \        ans=mod_pow(a%e,ans,e)+ad;\n    }\n    return ans%m;\n}\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\n#include<cmath>\n#include\"\
    mod_pow.hpp\"\n#include\"euler_phi.hpp\"\n\n/**\n * @brief \u30C6\u30C8\u30EC\u30FC\
    \u30B7\u30E7\u30F3\n */\n\nlong long tetration(long long a,long long b,long long\
    \ m){\n    std::vector<long long> v;\n    long long d=m;\n    while(d!=1){\n \
    \       v.push_back(d);\n        d=euler_phi(d);\n    }\n    v.push_back(1);\n\
    \    if(a==0)return (b+1)%2%m;\n    if(m==1)return 0;\n    if(a==1||b==0){\n \
    \       return 1;\n    }\n    if((long long)(v.size())>=b)v.resize(b-1,1);\n \
    \   std::reverse(v.begin(),v.end());\n    long long ans=a;\n    for(auto e:v){\n\
    \        long long ad=(ans<=32&&a<e&&std::pow((double)a,ans)<e?0:e);\n       \
    \ ans=mod_pow(a%e,ans,e)+ad;\n    }\n    return ans%m;\n}"
  dependsOn:
  - math/mod_pow.hpp
  - math/euler_phi.hpp
  isVerificationFile: false
  path: math/tetration.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - math/test/LC_tetration.test.cpp
documentation_of: math/tetration.hpp
layout: document
redirect_from:
- /library/math/tetration.hpp
- /library/math/tetration.hpp.html
title: "\u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3"
---
