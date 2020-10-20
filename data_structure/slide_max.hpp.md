---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/slide_max.hpp\"\nstruct slide_max{\n    my_deque<pair<unsigned,int>>deq;\n\
    \    int l=0,r=0;\n    bool empty(){\n        return l==r;\n    }\n    int size(){\n\
    \        return r-l;\n    }\n    void push(unsigned x){\n        while(!deq.empty()&&deq.back().first<=x){\n\
    \            deq.pop_back();\n        }\n        deq.push_back(make_pair(x,r++));\n\
    \    }\n    void pop(){\n        if(!deq.empty()&&deq.front().second==l){\n  \
    \          deq.pop_front();\n        }\n        l++;\n    }\n    unsigned fold(){\n\
    \        return deq.front().first;\n    }\n};\n"
  code: "struct slide_max{\n    my_deque<pair<unsigned,int>>deq;\n    int l=0,r=0;\n\
    \    bool empty(){\n        return l==r;\n    }\n    int size(){\n        return\
    \ r-l;\n    }\n    void push(unsigned x){\n        while(!deq.empty()&&deq.back().first<=x){\n\
    \            deq.pop_back();\n        }\n        deq.push_back(make_pair(x,r++));\n\
    \    }\n    void pop(){\n        if(!deq.empty()&&deq.front().second==l){\n  \
    \          deq.pop_front();\n        }\n        l++;\n    }\n    unsigned fold(){\n\
    \        return deq.front().first;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/slide_max.hpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/slide_max.hpp
layout: document
redirect_from:
- /library/data_structure/slide_max.hpp
- /library/data_structure/slide_max.hpp.html
title: data_structure/slide_max.hpp
---
