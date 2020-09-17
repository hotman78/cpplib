---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: SuffixArray
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n#include<string>\n#include<vector>\n\
    #include<algorithm>\n#include <numeric>\n#include<cmath>\n\n/**\n * @brief SuffixArray\n\
    \ */\n\nstd::vector<int> suffix_array(std::string s){\n    int n=s.size();\n \
    \   std::vector<int> v1(n,-1),v2(n,-1);\n    std::vector<int> rank(n,-1);\n  \
    \  std::iota(v1.begin(),v1.end(),0);\n    std::iota(v2.begin(),v2.end(),0);\n\
    \    std::sort(v1.begin(),v1.end(),[&](auto p,auto q){return s[p]<s[q];});\n \
    \   int idx=0;\n    for(int i=0;i<n;++i){\n        rank[v1[i]]=idx;\n        if(i<n-1&&s[v1[i]]!=s[v1[i+1]])idx++;\n\
    \    }\n    for(int i=0;i<(int)std::log2(n)+2;++i){\n        const int h=1<<i;\n\
    \        std::sort(v2.begin(),v2.end(),[&](auto p,auto q){\n            return\
    \ make_pair(rank[p],p+h<n?rank[p+h]:-1)<make_pair(rank[q],q+h<n?rank[q+h]:-1);\n\
    \        });\n        swap(v1,v2);\n        idx=0;\n        std::vector<int> tmp(n,-1);\n\
    \        for(int j=0;j<n;++j){\n            tmp[v1[j]]=idx;\n            if(j<n-1&&std::make_pair(rank[v1[j]],v1[j]+h<n?rank[v1[j]+h]:-1)<std::make_pair(rank[v1[j+1]],v1[j+1]+h<n?rank[v1[j+1]+h]:-1))idx++;\n\
    \        }\n        std::swap(rank,tmp);\n    }\n    return v1;\n}\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n#include<algorithm>\n#include\
    \ <numeric>\n#include<cmath>\n\n/**\n * @brief SuffixArray\n */\n\nstd::vector<int>\
    \ suffix_array(std::string s){\n    int n=s.size();\n    std::vector<int> v1(n,-1),v2(n,-1);\n\
    \    std::vector<int> rank(n,-1);\n    std::iota(v1.begin(),v1.end(),0);\n   \
    \ std::iota(v2.begin(),v2.end(),0);\n    std::sort(v1.begin(),v1.end(),[&](auto\
    \ p,auto q){return s[p]<s[q];});\n    int idx=0;\n    for(int i=0;i<n;++i){\n\
    \        rank[v1[i]]=idx;\n        if(i<n-1&&s[v1[i]]!=s[v1[i+1]])idx++;\n   \
    \ }\n    for(int i=0;i<(int)std::log2(n)+2;++i){\n        const int h=1<<i;\n\
    \        std::sort(v2.begin(),v2.end(),[&](auto p,auto q){\n            return\
    \ make_pair(rank[p],p+h<n?rank[p+h]:-1)<make_pair(rank[q],q+h<n?rank[q+h]:-1);\n\
    \        });\n        swap(v1,v2);\n        idx=0;\n        std::vector<int> tmp(n,-1);\n\
    \        for(int j=0;j<n;++j){\n            tmp[v1[j]]=idx;\n            if(j<n-1&&std::make_pair(rank[v1[j]],v1[j]+h<n?rank[v1[j]+h]:-1)<std::make_pair(rank[v1[j+1]],v1[j+1]+h<n?rank[v1[j+1]+h]:-1))idx++;\n\
    \        }\n        std::swap(rank,tmp);\n    }\n    return v1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_array.hpp
layout: document
redirect_from:
- /library/string/suffix_array.hpp
- /library/string/suffix_array.hpp.html
title: SuffixArray
---
