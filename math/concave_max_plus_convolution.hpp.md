---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DP/monotone_minima.hpp
    title: DP/monotone_minima.hpp
  _extendedRequiredBy: []
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
    \    return ret;\n}\n#line 2 \"math/concave_max_plus_convolution.hpp\"\nvector<lint>\
    \ concave_max_plus_convolution(const vector<lint>& a,const vec& b){\n    auto\
    \ f=[&](lint i,lint j){\n        if(i-j<0||(int)a.size()<=j||(int)b.size()<=i-j)return\
    \ INF;\n        else return -(a[j]+b[i-j]);\n    };\n    auto v=monotone_minima(a.size()+b.size()-1,b.size(),INF,f);\n\
    \    output(v);\n    vec res((int)a.size()+(int)b.size()-1);\n    rep(i,a.size()+b.size()-1){\n\
    \        res[i]=-f(i,v[i]);\n    }\n    return res;\n};\n"
  code: "#include\"../DP/monotone_minima.hpp\"\nvector<lint> concave_max_plus_convolution(const\
    \ vector<lint>& a,const vec& b){\n    auto f=[&](lint i,lint j){\n        if(i-j<0||(int)a.size()<=j||(int)b.size()<=i-j)return\
    \ INF;\n        else return -(a[j]+b[i-j]);\n    };\n    auto v=monotone_minima(a.size()+b.size()-1,b.size(),INF,f);\n\
    \    output(v);\n    vec res((int)a.size()+(int)b.size()-1);\n    rep(i,a.size()+b.size()-1){\n\
    \        res[i]=-f(i,v[i]);\n    }\n    return res;\n};"
  dependsOn:
  - DP/monotone_minima.hpp
  isVerificationFile: false
  path: math/concave_max_plus_convolution.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/concave_max_plus_convolution.hpp
layout: document
redirect_from:
- /library/math/concave_max_plus_convolution.hpp
- /library/math/concave_max_plus_convolution.hpp.html
title: math/concave_max_plus_convolution.hpp
---
