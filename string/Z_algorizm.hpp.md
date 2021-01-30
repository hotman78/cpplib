---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: string/test/LC_Z_algorizm.test.cpp
    title: string/test/LC_Z_algorizm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links: []
  bundledCode: "#line 2 \"string/Z_algorizm.hpp\"\n#include<string>\n#include<vector>\n\
    #include<algorithm>\n\n/**\n * @brief Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n\
    \ */\n\nstd::vector<int> Z_algorizm(const std::string& s){\n    std::vector<int>res(s.size());\n\
    \    res[0]=s.size();\n    int i=1,j=0;\n    while(i<(int)s.size()){\n       \
    \ while(i+j<(int)s.size()&&s[j]==s[i+j])++j;\n        res[i]=j;\n        if(j==0){++i;continue;}\n\
    \        int k=1;\n        while(i+k<(int)s.size()&&k+res[k]<j)res[i+k]=res[k],++k;\n\
    \        i+=k;j-=k;\n    }\n    return res;\n}\nint find_first(const std::string&\
    \ s,const std::string& t){\n    auto d=Z_algorizm(s+\"#\"+t);\n    auto itr=std::find(d.begin()+s.size(),d.end(),s.size());\n\
    \    if(itr!=d.end())return itr-d.begin()-s.size();\n    else return -1;\n}\n\
    int count(const std::string& s,const std::string& t){\n    auto d=Z_algorizm(s+\"\
    #\"+t);\n    return std::count(d.begin()+s.size(),d.end(),s.size());\n}\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n#include<algorithm>\n\n\
    /**\n * @brief Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n */\n\nstd::vector<int>\
    \ Z_algorizm(const std::string& s){\n    std::vector<int>res(s.size());\n    res[0]=s.size();\n\
    \    int i=1,j=0;\n    while(i<(int)s.size()){\n        while(i+j<(int)s.size()&&s[j]==s[i+j])++j;\n\
    \        res[i]=j;\n        if(j==0){++i;continue;}\n        int k=1;\n      \
    \  while(i+k<(int)s.size()&&k+res[k]<j)res[i+k]=res[k],++k;\n        i+=k;j-=k;\n\
    \    }\n    return res;\n}\nint find_first(const std::string& s,const std::string&\
    \ t){\n    auto d=Z_algorizm(s+\"#\"+t);\n    auto itr=std::find(d.begin()+s.size(),d.end(),s.size());\n\
    \    if(itr!=d.end())return itr-d.begin()-s.size();\n    else return -1;\n}\n\
    int count(const std::string& s,const std::string& t){\n    auto d=Z_algorizm(s+\"\
    #\"+t);\n    return std::count(d.begin()+s.size(),d.end(),s.size());\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/Z_algorizm.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/test/LC_Z_algorizm.test.cpp
documentation_of: string/Z_algorizm.hpp
layout: document
redirect_from:
- /library/string/Z_algorizm.hpp
- /library/string/Z_algorizm.hpp.html
title: "Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---
