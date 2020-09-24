---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph_tree/lex_bfs.hpp\"\nvector<int> lex_bfs(graph g,int\
    \ n,int m){\n    list<list<int>>que;\n    vector<list<list<int>>::iterator>pos1(n);\n\
    \    vector<list<int>::iterator>pos2(n);\n    list<int>s;\n    rep(i,n)s.emplace_back(i);\n\
    \    que.emplace_back(s);\n    rep(i,n)pos1[i]=que.begin();\n    {\n        int\
    \ idx=0;\n        for(auto i=que.front().begin();i!=que.front().end();++i){\n\
    \            pos2[idx++]=i;\n        }\n    }\n    vector<int>used(n);\n    vector<int>ans;\n\
    \    while(!que.empty()){\n        auto v=que.front().front();\n        que.front().pop_front();\n\
    \        if(que.front().empty())que.pop_front();\n        ans.push_back(v);\n\
    \        used[v]=1;\n        for(auto e:g[v]){\n            if(used[e])continue;\n\
    \            if(pos1[e]==que.begin()||prev(pos1[e])->front()!=-1){\n         \
    \       que.insert(pos1[e],list<int>{-1});\n            }\n            prev(pos1[e])->push_back(e);\n\
    \            auto tmp1=prev(pos1[e]);\n            auto tmp2=prev(tmp1->end());\n\
    \            pos1[e]->erase(pos2[e]);\n            if(pos1[e]->empty())que.erase(pos1[e]);\n\
    \            pos1[e]=tmp1;\n            pos2[e]=tmp2;\n        }\n        for(auto\
    \ e:g[v]){\n            if(used[e])continue;\n            if(pos1[e]->front()==-1){\n\
    \                pos1[e]->pop_front();\n            }\n        }\n    }\n    return\
    \ ans;\n}\n"
  code: "vector<int> lex_bfs(graph g,int n,int m){\n    list<list<int>>que;\n    vector<list<list<int>>::iterator>pos1(n);\n\
    \    vector<list<int>::iterator>pos2(n);\n    list<int>s;\n    rep(i,n)s.emplace_back(i);\n\
    \    que.emplace_back(s);\n    rep(i,n)pos1[i]=que.begin();\n    {\n        int\
    \ idx=0;\n        for(auto i=que.front().begin();i!=que.front().end();++i){\n\
    \            pos2[idx++]=i;\n        }\n    }\n    vector<int>used(n);\n    vector<int>ans;\n\
    \    while(!que.empty()){\n        auto v=que.front().front();\n        que.front().pop_front();\n\
    \        if(que.front().empty())que.pop_front();\n        ans.push_back(v);\n\
    \        used[v]=1;\n        for(auto e:g[v]){\n            if(used[e])continue;\n\
    \            if(pos1[e]==que.begin()||prev(pos1[e])->front()!=-1){\n         \
    \       que.insert(pos1[e],list<int>{-1});\n            }\n            prev(pos1[e])->push_back(e);\n\
    \            auto tmp1=prev(pos1[e]);\n            auto tmp2=prev(tmp1->end());\n\
    \            pos1[e]->erase(pos2[e]);\n            if(pos1[e]->empty())que.erase(pos1[e]);\n\
    \            pos1[e]=tmp1;\n            pos2[e]=tmp2;\n        }\n        for(auto\
    \ e:g[v]){\n            if(used[e])continue;\n            if(pos1[e]->front()==-1){\n\
    \                pos1[e]->pop_front();\n            }\n        }\n    }\n    return\
    \ ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/lex_bfs.hpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/lex_bfs.hpp
layout: document
redirect_from:
- /library/graph_tree/lex_bfs.hpp
- /library/graph_tree/lex_bfs.hpp.html
title: graph_tree/lex_bfs.hpp
---
