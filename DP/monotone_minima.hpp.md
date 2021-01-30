---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/concave_max_plus_convolution.hpp
    title: math/concave_max_plus_convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/monotone_minima.hpp\"\n//monotone\u306A\u4E8C\u5909\u6570\
    \u95A2\u6570\u306B\u5BFE\u3057\u3066\u5404\u884C\u306E\u6700\u5C0F\u5024\u3092\
    \u6C42\u3081\u308B\ntemplate<typename T,typename F>\nvector<int> monotone_minima(int\
    \ h,int w,T inf,F f){\n    vector<int>ret(h);\n    auto g=[&](auto g,int a,int\
    \ b,int c,int d,T inf,auto f)->void{\n        int e=(a+b)/2,idx=0;\n        T\
    \ mn=inf;\n        for(int i=c;i<d;++i){\n            if(mn>f(e,i))mn=f(e,i),idx=i;\n\
    \        }\n        ret[e]=idx;\n        if(b>a+1){\n            g(g,a,e,c,idx+1,inf,f);\n\
    \            g(g,e,b,idx,d,inf,f);\n        }\n    };\n    g(g,0,h,0,w,inf,f);\n\
    \    return ret;\n}\n"
  code: "//monotone\u306A\u4E8C\u5909\u6570\u95A2\u6570\u306B\u5BFE\u3057\u3066\u5404\
    \u884C\u306E\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\ntemplate<typename T,typename\
    \ F>\nvector<int> monotone_minima(int h,int w,T inf,F f){\n    vector<int>ret(h);\n\
    \    auto g=[&](auto g,int a,int b,int c,int d,T inf,auto f)->void{\n        int\
    \ e=(a+b)/2,idx=0;\n        T mn=inf;\n        for(int i=c;i<d;++i){\n       \
    \     if(mn>f(e,i))mn=f(e,i),idx=i;\n        }\n        ret[e]=idx;\n        if(b>a+1){\n\
    \            g(g,a,e,c,idx+1,inf,f);\n            g(g,e,b,idx,d,inf,f);\n    \
    \    }\n    };\n    g(g,0,h,0,w,inf,f);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DP/monotone_minima.hpp
  requiredBy:
  - math/concave_max_plus_convolution.hpp
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/monotone_minima.hpp
layout: document
redirect_from:
- /library/DP/monotone_minima.hpp
- /library/DP/monotone_minima.hpp.html
title: DP/monotone_minima.hpp
---
