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
  bundledCode: "#line 1 \"math/NTT2d.hpp\"\nvector<vector<mint>>NTT2d(const vector<vector<mint>>&s,const\
    \ vector<vector<mint>>&t){\n    int sh=s.size()+t.size()-1;\n    int sw=s[0].size()+t[0].size()-1;\n\
    \    int h=1,w=1;\n    while(h<sh)h*=2;\n    while(w<sw)w*=2;\n    fps<mint>f(h*w),g(h*w);\n\
    \    vector<vector<mint>>res(sh,vector<mint>(sw));\n    rep(i,s.size())rep(j,s[0].size()){\n\
    \        f[i*w+j]=s[i][j];\n    }\n    rep(i,t.size())rep(j,t[0].size()){\n  \
    \      g[i*w+j]=t[i][j];\n    }\n    f*=g;\n    rep(i,sh)rep(j,sw){\n        res[i][j]=f[i*w+j];\n\
    \    }\n    return res;\n}\n"
  code: "vector<vector<mint>>NTT2d(const vector<vector<mint>>&s,const vector<vector<mint>>&t){\n\
    \    int sh=s.size()+t.size()-1;\n    int sw=s[0].size()+t[0].size()-1;\n    int\
    \ h=1,w=1;\n    while(h<sh)h*=2;\n    while(w<sw)w*=2;\n    fps<mint>f(h*w),g(h*w);\n\
    \    vector<vector<mint>>res(sh,vector<mint>(sw));\n    rep(i,s.size())rep(j,s[0].size()){\n\
    \        f[i*w+j]=s[i][j];\n    }\n    rep(i,t.size())rep(j,t[0].size()){\n  \
    \      g[i*w+j]=t[i][j];\n    }\n    f*=g;\n    rep(i,sh)rep(j,sw){\n        res[i][j]=f[i*w+j];\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/NTT2d.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/NTT2d.hpp
layout: document
redirect_from:
- /library/math/NTT2d.hpp
- /library/math/NTT2d.hpp.html
title: math/NTT2d.hpp
---
