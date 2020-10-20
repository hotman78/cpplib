---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6700\u77ED\u7D4C\u8DEF\u6728 O((E+V)logE)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph_tree/shortest_path_tree_dijkstra.hpp: line 5: #pragma once found in a\
    \ non-first line\n"
  code: "#pragma once\n#include<vector>\n#include\"graph_template.hpp\"\n\n#pragma\
    \ once\n#include<vector>\n#include<queue>\n#include<functional>\n#include<tuple>\n\
    #include<limits>\n#include\"graph_template.hpp\"\n\n/**\n * @brief \u6700\u77ED\
    \u7D4C\u8DEF\u6728 O((E+V)logE)\n */\n\ntemplate<typename T,typename F=std::less<T>>\n\
    std::vector<int> shortest_path_tree_dijkstra(const graph_w<T>& list,int s,T zero=0,T\
    \ inf=std::numeric_limits<T>::max(),F f=F()){\n    std::priority_queue<std::pair<T,int>,std::vector<pair<T,int>>,std::greater<std::pair<T,int>>>que;\n\
    \    std::vector<T>diff(list.size(),inf);\n    diff[s]=zero;\n    que.push(make_pair(T(),s));\n\
    \    std::vector<int> par(list.size(),-1);\n    while(!que.empty()){\n       \
    \ auto d=que.top();\n        que.pop();\n        T x;\n        int now;\n    \
    \    tie(x,now)=d;\n        for(auto d2:list[now]){\n            T sa;\n     \
    \       int to;\n            tie(to,sa)=d2;\n            if(f(diff[now]+sa,diff[to])){\n\
    \                diff[to]=diff[now]+sa;\n                par[to]=now;\n      \
    \          que.emplace(diff[to],to);\n            }\n        }\n    }\n    return\
    \ par;\n}"
  dependsOn:
  - graph_tree/graph_template.hpp
  isVerificationFile: false
  path: graph_tree/shortest_path_tree_dijkstra.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/shortest_path_tree_dijkstra.hpp
layout: document
redirect_from:
- /library/graph_tree/shortest_path_tree_dijkstra.hpp
- /library/graph_tree/shortest_path_tree_dijkstra.hpp.html
title: "\u6700\u77ED\u7D4C\u8DEF\u6728 O((E+V)logE)"
---
