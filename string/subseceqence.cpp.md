---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u90E8\u5206\u5217DP(WIP)"
    links: []
  bundledCode: "#line 2 \"string/subseceqence.cpp\"\n#include<string>\n#include<vector>\n\
    #include<set>\n#include<tuple>\n\n/**\n * @brief \u90E8\u5206\u5217DP(WIP)\n */\n\
    \nstruct subsequence{\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        np ch[26]={};\n        int idx;\n        char c;\n        node(int idx,char\
    \ c):idx(idx),c(c){}\n    };\n    std::string s;int n;\n    std::vector<std::vector<int>>m;\n\
    \    std::vector<np>v;\n    np root=0;\n    subsequence(std::string s):s(s),n(s.size()),m(n+1,std::vector<int>(26,-1)),v(n+1){\n\
    \        for(int i=n-1;i>=0;--i){\n            m[i]=m[i+1];\n            m[i][s[i]-'a']=i;\n\
    \        }\n        for(int i=0;i<n+1;++i)v[i]=new node(i,(i?s[i-1]:'#'));\n \
    \       for(int i=0;i<n;++i){\n            for(int j=0;j<26;++j){\n          \
    \      if(~m[i][j])v[i]->ch[j]=v[m[i][j]+1];\n            }\n        }\n     \
    \   root=v[0];\n    }\n    //\u3053\u3053\u304B\u3089\u554F\u984C\u3054\u3068\u306B\
    \u66F8\u304F\n    std::vector<long long>dp;\n    void dp2(){\n        dp.resize(n+1);\n\
    \        for(int i=n;i>=0;--i){\n            np t=v[i];\n            dp[i]=;\n\
    \            for(int j=0;j<26;++j){\n                if(!t->ch[j])dp[i]=1;\n \
    \               else dp[i]=min(dp[i],dp[t->ch[j]->idx]+1);\n            }\n  \
    \      }\n    }\n    string ans;\n    void dfs(np t){\n        for(int i=0;i<26;i++){\n\
    \            if(!t->ch[i]){\n                if(t!=root)ans+=t->c;\n         \
    \       ans+=char(i+'a');\n                return;\n            }\n          \
    \  if(dp[t->ch[i]->idx]==dp[t->idx]-1){\n                if(t!=root)ans+=t->c;\n\
    \                dfs(t->ch[i]);\n                return;\n            }\n    \
    \    }\n    }\n    string solve(){\n        dp2();\n        dfs(root);\n     \
    \   return ans;\n    }\n};\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n#include<set>\n#include<tuple>\n\
    \n/**\n * @brief \u90E8\u5206\u5217DP(WIP)\n */\n\nstruct subsequence{\n    struct\
    \ node;\n    using np=node*;\n    struct node{\n        np ch[26]={};\n      \
    \  int idx;\n        char c;\n        node(int idx,char c):idx(idx),c(c){}\n \
    \   };\n    std::string s;int n;\n    std::vector<std::vector<int>>m;\n    std::vector<np>v;\n\
    \    np root=0;\n    subsequence(std::string s):s(s),n(s.size()),m(n+1,std::vector<int>(26,-1)),v(n+1){\n\
    \        for(int i=n-1;i>=0;--i){\n            m[i]=m[i+1];\n            m[i][s[i]-'a']=i;\n\
    \        }\n        for(int i=0;i<n+1;++i)v[i]=new node(i,(i?s[i-1]:'#'));\n \
    \       for(int i=0;i<n;++i){\n            for(int j=0;j<26;++j){\n          \
    \      if(~m[i][j])v[i]->ch[j]=v[m[i][j]+1];\n            }\n        }\n     \
    \   root=v[0];\n    }\n    //\u3053\u3053\u304B\u3089\u554F\u984C\u3054\u3068\u306B\
    \u66F8\u304F\n    std::vector<long long>dp;\n    void dp2(){\n        dp.resize(n+1);\n\
    \        for(int i=n;i>=0;--i){\n            np t=v[i];\n            dp[i]=;\n\
    \            for(int j=0;j<26;++j){\n                if(!t->ch[j])dp[i]=1;\n \
    \               else dp[i]=min(dp[i],dp[t->ch[j]->idx]+1);\n            }\n  \
    \      }\n    }\n    string ans;\n    void dfs(np t){\n        for(int i=0;i<26;i++){\n\
    \            if(!t->ch[i]){\n                if(t!=root)ans+=t->c;\n         \
    \       ans+=char(i+'a');\n                return;\n            }\n          \
    \  if(dp[t->ch[i]->idx]==dp[t->idx]-1){\n                if(t!=root)ans+=t->c;\n\
    \                dfs(t->ch[i]);\n                return;\n            }\n    \
    \    }\n    }\n    string solve(){\n        dp2();\n        dfs(root);\n     \
    \   return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/subseceqence.cpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/subseceqence.cpp
layout: document
redirect_from:
- /library/string/subseceqence.cpp
- /library/string/subseceqence.cpp.html
title: "\u90E8\u5206\u5217DP(WIP)"
---
