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
  bundledCode: "#line 2 \"data_structure/cht.hpp\"\n#include<set>\n#include<functional>\n\
    #include<climits>\n#include<cassert>\n\nstruct Line {\n\tmutable long long k,\
    \ m, p;\n\tbool operator<(const Line& o) const { return k < o.k; }\n\tbool operator<(long\
    \ long x) const { return p < x; }\n};\n\nstruct cht : std::multiset<Line, std::less<>>\
    \ {\n\t// (for doubles, use inf = 1/.0, div(a,b) = a/b)\n\tstatic const long long\
    \ inf = LLONG_MAX;\n\tlong long div(long long a, long long b) { // floored division\n\
    \t\treturn a / b - ((a ^ b) < 0 && a % b);\n    }\n\tbool isect(iterator x, iterator\
    \ y) {\n\t\tif (y == end()) return x->p = inf, 0;\n\t\tif (x->k == y->k) x->p\
    \ = x->m > y->m ? inf : -inf;\n\t\telse x->p = div(y->m - x->m, x->k - y->k);\n\
    \t\treturn x->p >= y->p;\n\t}\n\tvoid add(long long k, long long m) {\n\t\tauto\
    \ z = insert({k, m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) z = erase(z);\n\
    \t\tif (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n\t\twhile ((y\
    \ = x) != begin() && (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\t}\n\tlong\
    \ long query(long long x) {\n\t\tassert(!empty());\n\t\tauto l = *lower_bound(x);\n\
    \t\treturn l.k * x + l.m;\n\t}\n};\n"
  code: "#pragma once\n#include<set>\n#include<functional>\n#include<climits>\n#include<cassert>\n\
    \nstruct Line {\n\tmutable long long k, m, p;\n\tbool operator<(const Line& o)\
    \ const { return k < o.k; }\n\tbool operator<(long long x) const { return p <\
    \ x; }\n};\n\nstruct cht : std::multiset<Line, std::less<>> {\n\t// (for doubles,\
    \ use inf = 1/.0, div(a,b) = a/b)\n\tstatic const long long inf = LLONG_MAX;\n\
    \tlong long div(long long a, long long b) { // floored division\n\t\treturn a\
    \ / b - ((a ^ b) < 0 && a % b);\n    }\n\tbool isect(iterator x, iterator y) {\n\
    \t\tif (y == end()) return x->p = inf, 0;\n\t\tif (x->k == y->k) x->p = x->m >\
    \ y->m ? inf : -inf;\n\t\telse x->p = div(y->m - x->m, x->k - y->k);\n\t\treturn\
    \ x->p >= y->p;\n\t}\n\tvoid add(long long k, long long m) {\n\t\tauto z = insert({k,\
    \ m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) z = erase(z);\n\t\tif (x !=\
    \ begin() && isect(--x, y)) isect(x, y = erase(y));\n\t\twhile ((y = x) != begin()\
    \ && (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\t}\n\tlong long query(long\
    \ long x) {\n\t\tassert(!empty());\n\t\tauto l = *lower_bound(x);\n\t\treturn\
    \ l.k * x + l.m;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cht.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/cht.hpp
layout: document
redirect_from:
- /library/data_structure/cht.hpp
- /library/data_structure/cht.hpp.html
title: data_structure/cht.hpp
---
