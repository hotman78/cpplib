---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Manacher
    links: []
  bundledCode: "#line 2 \"string/manacher.hpp\"\n#include<string>\n#include<vector>\n\
    \n/**\n * @brief Manacher\n */\n\nstd::vector<int> manacher(std::string S){\n\
    \    int i = 0, j = 0;\n    std::string s;\n    for(int i=0;i<(int)S.size();i++){\n\
    \        if(i)s+='$';\n        s+=S[i];\n    }\n    int n=s.size();\n    std::vector<int>res(n,0);\n\
    \    while (i<n) {\n        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])++j;\n       \
    \ res[i]=j;\n        int k=1;\n        while (i-k >= 0 && k+res[i-k]<j)res[i+k]=res[i-k],++k;\n\
    \        i+=k;j-=k;\n    }\n    for(int i=0;i<n;++i){\n        if(i%2)res[i]=res[i]/2;\n\
    \        else res[i]=(res[i]+1)/2;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n\n/**\n * @brief Manacher\n\
    \ */\n\nstd::vector<int> manacher(std::string S){\n    int i = 0, j = 0;\n   \
    \ std::string s;\n    for(int i=0;i<(int)S.size();i++){\n        if(i)s+='$';\n\
    \        s+=S[i];\n    }\n    int n=s.size();\n    std::vector<int>res(n,0);\n\
    \    while (i<n) {\n        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])++j;\n       \
    \ res[i]=j;\n        int k=1;\n        while (i-k >= 0 && k+res[i-k]<j)res[i+k]=res[i-k],++k;\n\
    \        i+=k;j-=k;\n    }\n    for(int i=0;i<n;++i){\n        if(i%2)res[i]=res[i]/2;\n\
    \        else res[i]=(res[i]+1)/2;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: Manacher
---
