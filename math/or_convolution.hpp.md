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
  bundledCode: "#line 1 \"math/or_convolution.hpp\"\ntemplate<typename T>\nvector<T>\
    \ or_conv(vector<T>s,vector<T>t,int n){\n\tauto zeta=[](vector<T>& f,int n){\n\
    \t\tfor(int i=0;i<n;++i){\n\t\t\tfor(int j=0;j<(1<<n);++j){\n\t\t\t\tif((j&(1<<i))==0)f[j^(1<<i)]+=f[j];\n\
    \t\t\t}\n\t\t}\n\t};\n\tauto mebius=[](vector<T>& f,int n){\n\t\tfor(int i=0;i<n;++i){\n\
    \t\t\tfor(int j=0;j<(1<<n);++j){\n\t\t\t\tif((j&(1<<i))==0)f[j^(1<<i)]-=f[j];\n\
    \t\t\t}\n\t\t}\n\t};\n\tzeta(s,n);\n\tzeta(t,n);\n\tfor(int i=0;i<(1<<n);++i)s[i]*=t[i];\n\
    \tmebius(s,n);\n\treturn s;\n}\n"
  code: "template<typename T>\nvector<T> or_conv(vector<T>s,vector<T>t,int n){\n\t\
    auto zeta=[](vector<T>& f,int n){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tfor(int j=0;j<(1<<n);++j){\n\
    \t\t\t\tif((j&(1<<i))==0)f[j^(1<<i)]+=f[j];\n\t\t\t}\n\t\t}\n\t};\n\tauto mebius=[](vector<T>&\
    \ f,int n){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tfor(int j=0;j<(1<<n);++j){\n\t\t\
    \t\tif((j&(1<<i))==0)f[j^(1<<i)]-=f[j];\n\t\t\t}\n\t\t}\n\t};\n\tzeta(s,n);\n\t\
    zeta(t,n);\n\tfor(int i=0;i<(1<<n);++i)s[i]*=t[i];\n\tmebius(s,n);\n\treturn s;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/or_convolution.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/or_convolution.hpp
layout: document
redirect_from:
- /library/math/or_convolution.hpp
- /library/math/or_convolution.hpp.html
title: math/or_convolution.hpp
---
