---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O((E+V)logE)"
    links: []
  bundledCode: "#line 2 \"graph_tree/dijkstra.hpp\"\n#include<vector>\n\n/**\n * @brief\
    \ \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O((E+V)logE)\n */\ntemplate<typename E,typename\
    \ T>\nstd::vector<T> __dijkstra(vector<vector<pair<E,T>>> list,lint s,T inf){\n\
    \    std::priority_queue<pair<T,E>,vector<pair<T,E>>,greater<pair<T,E>>>que;\n\
    \    vector<T>diff(list.size(),inf);\n    diff[s]=0;\n    que.push(make_pair(T(),s));\n\
    \    while(!que.empty()){\n        auto d=que.top();\n        que.pop();\n   \
    \     T x;E now;\n        tie(x,now)=d;\n        for(auto d2:list[now]){\n   \
    \         T sa;E to;\n            tie(to,sa)=d2;\n            if(chmin(diff[to],diff[now]+sa))que.emplace(diff[to],to);\n\
    \        }\n    }\n    return diff;\n}\n\n"
  code: "#pragma once\n#include<vector>\n\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9 O((E+V)logE)\n */\ntemplate<typename E,typename T>\nstd::vector<T>\
    \ __dijkstra(vector<vector<pair<E,T>>> list,lint s,T inf){\n    std::priority_queue<pair<T,E>,vector<pair<T,E>>,greater<pair<T,E>>>que;\n\
    \    vector<T>diff(list.size(),inf);\n    diff[s]=0;\n    que.push(make_pair(T(),s));\n\
    \    while(!que.empty()){\n        auto d=que.top();\n        que.pop();\n   \
    \     T x;E now;\n        tie(x,now)=d;\n        for(auto d2:list[now]){\n   \
    \         T sa;E to;\n            tie(to,sa)=d2;\n            if(chmin(diff[to],diff[now]+sa))que.emplace(diff[to],to);\n\
    \        }\n    }\n    return diff;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/dijkstra.hpp
layout: document
redirect_from:
- /library/graph_tree/dijkstra.hpp
- /library/graph_tree/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O((E+V)logE)"
---
