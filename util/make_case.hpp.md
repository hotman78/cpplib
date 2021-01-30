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
  bundledCode: "#line 1 \"util/make_case.hpp\"\ntemplate<typename F,typename G>\n\
    void make_case(string name,lint num,F in,G out){\n    for(int i=0;i<num;++i){\n\
    \        string s=to_string(i);\n        while(s.size()<2)s=\"0\"+s;\n       \
    \ ofstream input(\"in/\"+name+s+\".txt\");\n        in(input);\n        input<<flush;\n\
    \        ifstream input2(\"in/\"+name+s+\".txt\");\n        ofstream output(\"\
    out/\"+name+s+\".txt\");\n        out(input2,output);\n        output<<flush;\n\
    \    }\n}\n"
  code: "template<typename F,typename G>\nvoid make_case(string name,lint num,F in,G\
    \ out){\n    for(int i=0;i<num;++i){\n        string s=to_string(i);\n       \
    \ while(s.size()<2)s=\"0\"+s;\n        ofstream input(\"in/\"+name+s+\".txt\"\
    );\n        in(input);\n        input<<flush;\n        ifstream input2(\"in/\"\
    +name+s+\".txt\");\n        ofstream output(\"out/\"+name+s+\".txt\");\n     \
    \   out(input2,output);\n        output<<flush;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: util/make_case.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/make_case.hpp
layout: document
redirect_from:
- /library/util/make_case.hpp
- /library/util/make_case.hpp.html
title: util/make_case.hpp
---
