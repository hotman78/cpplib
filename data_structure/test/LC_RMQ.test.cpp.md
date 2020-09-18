---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../RMQ.hpp\"\n#include \"../../template.hpp\"\n\nint main(){\n\tlint n,q;\n\t\
    cin>>n>>q;\n\tvector<lint>a(n);\n\trep(i,n)cin>>a[i];\n\tRMQ<lint> rmq(a);\n\t\
    while(q--){\n\t\tlint s,t;\n\t\tcin>>s>>t;\n\t\tcout<<rmq.query(s,t)<<endl;\n\t\
    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: data_structure/test/LC_RMQ.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data_structure/test/LC_RMQ.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_RMQ.test.cpp
- /verify/data_structure/test/LC_RMQ.test.cpp.html
title: data_structure/test/LC_RMQ.test.cpp
---
