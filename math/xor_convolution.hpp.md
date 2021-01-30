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
  bundledCode: "#line 1 \"math/xor_convolution.hpp\"\ntemplate <typename T>\nvector<T>xor_conv(vector<T>\
    \ s,vector<T> t){\n    auto fwt=[](vector<T>& f){\n        int n = f.size();\n\
    \        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n;\
    \ j++) {\n                if ((j & i) == 0) {\n                    T x = f[j],\
    \ y = f[j | i];\n                    f[j] = x + y, f[j | i] = x - y;\n       \
    \         }\n            }\n        }\n    };\n    auto ifwt=[](vector<T>& f){\n\
    \        int n = f.size();\n        for (int i = 1; i < n; i <<= 1) {\n      \
    \      for (int j = 0; j < n; j++) {\n                if ((j & i) == 0) {\n  \
    \                  T x = f[j], y = f[j | i];\n                    f[j] = (x +\
    \ y) / 2, f[j | i] = (x - y) / 2;\n                }\n            }\n        }\n\
    \    };\n    fwt(s);\n    fwt(t);\n    for(int i=0;i<(int)s.size();i++){\n   \
    \     s[i]*=t[i];\n    }\n    ifwt(s);\n    return s;\n}\n"
  code: "template <typename T>\nvector<T>xor_conv(vector<T> s,vector<T> t){\n    auto\
    \ fwt=[](vector<T>& f){\n        int n = f.size();\n        for (int i = 1; i\
    \ < n; i <<= 1) {\n            for (int j = 0; j < n; j++) {\n               \
    \ if ((j & i) == 0) {\n                    T x = f[j], y = f[j | i];\n       \
    \             f[j] = x + y, f[j | i] = x - y;\n                }\n           \
    \ }\n        }\n    };\n    auto ifwt=[](vector<T>& f){\n        int n = f.size();\n\
    \        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n;\
    \ j++) {\n                if ((j & i) == 0) {\n                    T x = f[j],\
    \ y = f[j | i];\n                    f[j] = (x + y) / 2, f[j | i] = (x - y) /\
    \ 2;\n                }\n            }\n        }\n    };\n    fwt(s);\n    fwt(t);\n\
    \    for(int i=0;i<(int)s.size();i++){\n        s[i]*=t[i];\n    }\n    ifwt(s);\n\
    \    return s;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/xor_convolution.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/xor_convolution.hpp
layout: document
redirect_from:
- /library/math/xor_convolution.hpp
- /library/math/xor_convolution.hpp.html
title: math/xor_convolution.hpp
---
