---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570 mod P"
    links: []
  bundledCode: "#line 1 \"math/comb.hpp\"\n/**\r\n * @brief \u4E8C\u9805\u4FC2\u6570\
    \ mod P\r\n */\r\ntemplate<int mod>\r\nlong long comb(long long a, long long b){\r\
    \n    static bool init=1;\r\n    static long long fac[1000001],ifac[1000001];\r\
    \n    if(init){\r\n        init=0;\r\n        fac[0]=1;\r\n        ifac[0]=1;\r\
    \n        auto mod_pow=[&](lint x,lint n){\r\n            lint ans = 1;\r\n  \
    \          while(n != 0){\r\n                if(n&1)ans=ans*x%mod;\r\n       \
    \         x=x*x%mod;\r\n                n=n>>1;\r\n            }\r\n         \
    \   return ans;\r\n        };\r\n        for(int i=0;i<1000000;i++){\r\n     \
    \       fac[i+1]=fac[i]*(i+1)%mod;\r\n            ifac[i+1]=ifac[i]*mod_pow(i+1,\
    \ MOD-2)%mod;\r\n        }\r\n    }\r\n    if(a==0&&b==0)return 1;\r\n    if(a<b||a<0)return\
    \ 0;\r\n    long long tmp=ifac[a-b]*ifac[b]%mod;\r\n    return tmp*fac[a]%mod;\r\
    \n}\n"
  code: "/**\r\n * @brief \u4E8C\u9805\u4FC2\u6570 mod P\r\n */\r\ntemplate<int mod>\r\
    \nlong long comb(long long a, long long b){\r\n    static bool init=1;\r\n   \
    \ static long long fac[1000001],ifac[1000001];\r\n    if(init){\r\n        init=0;\r\
    \n        fac[0]=1;\r\n        ifac[0]=1;\r\n        auto mod_pow=[&](lint x,lint\
    \ n){\r\n            lint ans = 1;\r\n            while(n != 0){\r\n         \
    \       if(n&1)ans=ans*x%mod;\r\n                x=x*x%mod;\r\n              \
    \  n=n>>1;\r\n            }\r\n            return ans;\r\n        };\r\n     \
    \   for(int i=0;i<1000000;i++){\r\n            fac[i+1]=fac[i]*(i+1)%mod;\r\n\
    \            ifac[i+1]=ifac[i]*mod_pow(i+1, MOD-2)%mod;\r\n        }\r\n    }\r\
    \n    if(a==0&&b==0)return 1;\r\n    if(a<b||a<0)return 0;\r\n    long long tmp=ifac[a-b]*ifac[b]%mod;\r\
    \n    return tmp*fac[a]%mod;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/comb.hpp
  requiredBy: []
  timestamp: '2020-09-13 16:40:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/comb.hpp
layout: document
redirect_from:
- /library/math/comb.hpp
- /library/math/comb.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570 mod P"
---
