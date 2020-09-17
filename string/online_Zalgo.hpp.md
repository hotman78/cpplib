---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: string/test/LC_online_Z_algorizm.test.cpp
    title: string/test/LC_online_Z_algorizm.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30AA\u30F3\u30E9\u30A4\u30F3Z\u30A2\u30EB\u30B4\u30EA\u30BA\
      \u30E0"
    links: []
  bundledCode: "#line 2 \"string/online_Zalgo.hpp\"\n#include<string>\n#include<vector>\n\
    #include<set>\n\n/**\n * @brief \u30AA\u30F3\u30E9\u30A4\u30F3Z\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\n */\n\nstruct online_Zalgo{\n    std::vector<int>z;\n    std::set<int>memo;\n\
    \    std::vector<std::vector<int>>hist;\n    std::string s=\"\";\n    int sz=0;\n\
    \    void add(char c){\n        s+=c;\n        memo.emplace(sz);\n        z.push_back(-1);\n\
    \        hist.push_back(std::vector<int>());\n        sz++;\n        int mx=-1;\n\
    \        for(auto itr=next(memo.begin(),1);itr!=memo.end();){\n            auto\
    \ idx=*itr;\n            if(s[sz-idx-1]!=s.back()){\n                itr=memo.erase(itr);\n\
    \                z[idx]=sz-idx-1;\n                hist.back().push_back(idx);\n\
    \            }else{\n                mx=idx;\n                break;\n       \
    \     }\n        }\n        if(mx==-1)return;\n        for(auto e:hist[sz-1-mx]){\n\
    \            memo.erase(mx+e);\n            z[mx+e]=sz-(mx+e)-1;\n           \
    \ hist.back().push_back(mx+e);\n        }\n    }\n    int operator[](int idx){\n\
    \        if(memo.count(idx))return sz-idx;\n        else return z[idx];\n    }\n\
    };\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n#include<set>\n\n/**\n\
    \ * @brief \u30AA\u30F3\u30E9\u30A4\u30F3Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \n */\n\nstruct online_Zalgo{\n    std::vector<int>z;\n    std::set<int>memo;\n\
    \    std::vector<std::vector<int>>hist;\n    std::string s=\"\";\n    int sz=0;\n\
    \    void add(char c){\n        s+=c;\n        memo.emplace(sz);\n        z.push_back(-1);\n\
    \        hist.push_back(std::vector<int>());\n        sz++;\n        int mx=-1;\n\
    \        for(auto itr=next(memo.begin(),1);itr!=memo.end();){\n            auto\
    \ idx=*itr;\n            if(s[sz-idx-1]!=s.back()){\n                itr=memo.erase(itr);\n\
    \                z[idx]=sz-idx-1;\n                hist.back().push_back(idx);\n\
    \            }else{\n                mx=idx;\n                break;\n       \
    \     }\n        }\n        if(mx==-1)return;\n        for(auto e:hist[sz-1-mx]){\n\
    \            memo.erase(mx+e);\n            z[mx+e]=sz-(mx+e)-1;\n           \
    \ hist.back().push_back(mx+e);\n        }\n    }\n    int operator[](int idx){\n\
    \        if(memo.count(idx))return sz-idx;\n        else return z[idx];\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: string/online_Zalgo.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - string/test/LC_online_Z_algorizm.test.cpp
documentation_of: string/online_Zalgo.hpp
layout: document
redirect_from:
- /library/string/online_Zalgo.hpp
- /library/string/online_Zalgo.hpp.html
title: "\u30AA\u30F3\u30E9\u30A4\u30F3Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---
