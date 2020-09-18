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
  code: "#include \"../binary_trie.hpp\"\n#include \"../../template.hpp\"\n\nint main(){\n\
    \tlint n;\n\tcin>>n;\n\tbinary_trie b;\n\twhile(n--){\n\t\tlint c,x;\n\t\tcin>>c>>x;\n\
    \t\tif(c==0&&!b.count(x))b.insert(x);\n\t\tif(c==1)b.erase(x);\n\t\tif(c==2)cout<<b.xor_min(x)<<endl;\n\
    \t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: data_structure/test/LC_binary_trie.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data_structure/test/LC_binary_trie.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_binary_trie.test.cpp
- /verify/data_structure/test/LC_binary_trie.test.cpp.html
title: data_structure/test/LC_binary_trie.test.cpp
---
