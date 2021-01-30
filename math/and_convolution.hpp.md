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
  bundledCode: "#line 1 \"math/and_convolution.hpp\"\ntemplate<typename T>\nvector<T>\
    \ and_conv(vector<T>s,vector<T>t,int n){\n\tauto zeta=[](vector<T>& f,int n){\n\
    \t\tfor(int i=0;i<n;++i){\n\t\t\tfor(int j=0;j<(1<<n);++j){\n\t\t\t\tif((j&(1<<i))==0)f[j]+=f[j^(1<<i)];\n\
    \t\t\t}\n\t\t}\n\t};\n\tauto mebius=[](vector<T>& f,int n){\n\t\tfor(int i=0;i<n;++i){\n\
    \t\t\tfor(int j=0;j<(1<<n);++j){\n\t\t\t\tif((j&(1<<i))==0)f[j]-=f[j^(1<<i)];\n\
    \t\t\t}\n\t\t}\n\t};\n\tzeta(s,n);\n\tzeta(t,n);\n\tfor(int i=0;i<(1<<n);++i)s[i]*=t[i];\n\
    \tmebius(s,n);\n\treturn s;\n}\n"
  code: "template<typename T>\nvector<T> and_conv(vector<T>s,vector<T>t,int n){\n\t\
    auto zeta=[](vector<T>& f,int n){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tfor(int j=0;j<(1<<n);++j){\n\
    \t\t\t\tif((j&(1<<i))==0)f[j]+=f[j^(1<<i)];\n\t\t\t}\n\t\t}\n\t};\n\tauto mebius=[](vector<T>&\
    \ f,int n){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tfor(int j=0;j<(1<<n);++j){\n\t\t\
    \t\tif((j&(1<<i))==0)f[j]-=f[j^(1<<i)];\n\t\t\t}\n\t\t}\n\t};\n\tzeta(s,n);\n\t\
    zeta(t,n);\n\tfor(int i=0;i<(1<<n);++i)s[i]*=t[i];\n\tmebius(s,n);\n\treturn s;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/and_convolution.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/and_convolution.hpp
layout: document
redirect_from:
- /library/math/and_convolution.hpp
- /library/math/and_convolution.hpp.html
title: math/and_convolution.hpp
---
