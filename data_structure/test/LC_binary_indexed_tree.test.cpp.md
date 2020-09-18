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
  code: "#include \"../binary_indexed_tree.hpp\"\n#include \"../../template.hpp\"\n\
    \nint main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tBIT bit(n);\n\trep(i,n){\n\t\tlint\
    \ x;\n\t\tcin>>x;\n\t\tbit.add(i,x);\n\t}\n\twhile(q--){\n\t\tlint c,s,t;\n\t\t\
    cin>>c>>s>>t;\n\t\tif(c==0){\n\t\t\tbit.add(s,t);\n\t\t}else{\n\t\t\tcout<<bit.sum(s,t)<<endl;\n\
    \t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: data_structure/test/LC_binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data_structure/test/LC_binary_indexed_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_binary_indexed_tree.test.cpp
- /verify/data_structure/test/LC_binary_indexed_tree.test.cpp.html
title: data_structure/test/LC_binary_indexed_tree.test.cpp
---
