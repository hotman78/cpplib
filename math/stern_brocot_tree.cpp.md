---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/stern_brocot_tree.cpp\"\n#include<iostream>\n\n//\u5206\
    \u6BCD\u304Cm\u4EE5\u4E0B\u306Ek\u756A\u76EE\u306E\u6570\nlong long m;\nvoid bs(long\
    \ long a,long long b,long long c,long long d,long long& k){\n    if(b+d>m)return;\n\
    \    bs(a,b,a+c,b+d,k);\n    k--;\n    if(k==0){\n        std::cout<<a+c<<\" \"\
    <<b+d<<std::endl;\n        exit(0);\n    }\n    bs(a+c,b+d,c,d,k); \n}\n"
  code: "#include<iostream>\n\n//\u5206\u6BCD\u304Cm\u4EE5\u4E0B\u306Ek\u756A\u76EE\
    \u306E\u6570\nlong long m;\nvoid bs(long long a,long long b,long long c,long long\
    \ d,long long& k){\n    if(b+d>m)return;\n    bs(a,b,a+c,b+d,k);\n    k--;\n \
    \   if(k==0){\n        std::cout<<a+c<<\" \"<<b+d<<std::endl;\n        exit(0);\n\
    \    }\n    bs(a+c,b+d,c,d,k); \n}"
  dependsOn: []
  isVerificationFile: false
  path: math/stern_brocot_tree.cpp
  requiredBy: []
  timestamp: '2020-09-13 14:58:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/stern_brocot_tree.cpp
layout: document
redirect_from:
- /library/math/stern_brocot_tree.cpp
- /library/math/stern_brocot_tree.cpp.html
title: math/stern_brocot_tree.cpp
---
