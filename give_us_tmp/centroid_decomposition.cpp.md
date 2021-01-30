---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u91CD\u5FC3\u5206\u89E3"
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    - https://judge.yosupo.jp/submission/28303
  bundledCode: "#line 1 \"give_us_tmp/centroid_decomposition.cpp\"\n/**\n * @brief\
    \ \u91CD\u5FC3\u5206\u89E3\n * \u69CB\u7BC9:O(NlogN)\n * get_root()          \
    \ :\u51FA\u6765\u4E0A\u304C\u3063\u305F\u6728\u306E\u6839\u3092\u8FD4\u3059 O(1)\n\
    \ * operator[](int i)    :\u51FA\u6765\u4E0A\u304C\u3063\u305F\u6728\u306E\u5B50\
    \u3092\u8FD4\u3059\n * get_euler_tour(int i):\u51FA\u6765\u4E0A\u304C\u3063\u305F\
    \u6728\u306Edfs\u9806\u3092\u8FD4\u3059\n * \n * \u30FB\u5168\u3066\u306E\u30D1\
    \u30B9\u306B\u3064\u3044\u3066\u8ABF\u3079\u308B\u65B9\u6CD5\n * dfs\u9806\u3092\
    \u53D6\u5F97\u3057\u3066\u30EB\u30FC\u30D7\u3092\u56DE\u3057\u3001\n * \u30D1\u30B9\
    \u4E0A\u306B\u3042\u308A\u3001dfs\u9806\u3067\u6700\u5C0F\u3068\u306A\u308B\u9802\
    \u70B9\u304Ci\u3067\u3042\u308B\u3088\u3046\u306A\u30D1\u30B9\u3092\u306A\u3081\
    \u3066\u3044\u304F\n * \n * verified with    :https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n\
    \ * submission       :https://judge.yosupo.jp/submission/28303\n */\n\nclass centroid_decomposition{\n\
    \    using graph=vector<vector<int>>;\n    graph g;\n    vector<int>used;\n  \
    \  vector<int>v;\n    graph ch;\n    int s;\n    int dfs(int n,int p,int sz,int\
    \ root){\n        if(used[n])return 0;\n        bool b=1;\n        int res=1;\n\
    \        for(auto e:g[n]){\n            if(p==e)continue;\n            auto t=dfs(e,n,sz,root);\n\
    \            res+=t;\n            if(t>sz/2)b=0;\n        }\n        if(!b||sz-res>sz/2)return\
    \ res;\n        if(root!=-1)ch[root].push_back(n);\n        else s=n;\n      \
    \  v.push_back(n);\n        used[n]=1;\n        for(auto e:g[n]){\n          \
    \  dfs(e,n,dfs(e,n,g.size()*2,n),n);\n        }\n        return g.size()*2;\n\
    \    }\n    public:\n    centroid_decomposition(const graph&g):g(g){\n       \
    \ int n=g.size();\n        used.resize(n);\n        ch.resize(n);\n        dfs(0,-1,n,-1);\n\
    \    }\n\n    int get_root(){return s;}\n    vector<int> operator[](int i){return\
    \ ch[i];}\n    vector<int> get_euler_tour(){return v;}\n};\n"
  code: "/**\n * @brief \u91CD\u5FC3\u5206\u89E3\n * \u69CB\u7BC9:O(NlogN)\n * get_root()\
    \           :\u51FA\u6765\u4E0A\u304C\u3063\u305F\u6728\u306E\u6839\u3092\u8FD4\
    \u3059 O(1)\n * operator[](int i)    :\u51FA\u6765\u4E0A\u304C\u3063\u305F\u6728\
    \u306E\u5B50\u3092\u8FD4\u3059\n * get_euler_tour(int i):\u51FA\u6765\u4E0A\u304C\
    \u3063\u305F\u6728\u306Edfs\u9806\u3092\u8FD4\u3059\n * \n * \u30FB\u5168\u3066\
    \u306E\u30D1\u30B9\u306B\u3064\u3044\u3066\u8ABF\u3079\u308B\u65B9\u6CD5\n * dfs\u9806\
    \u3092\u53D6\u5F97\u3057\u3066\u30EB\u30FC\u30D7\u3092\u56DE\u3057\u3001\n * \u30D1\
    \u30B9\u4E0A\u306B\u3042\u308A\u3001dfs\u9806\u3067\u6700\u5C0F\u3068\u306A\u308B\
    \u9802\u70B9\u304Ci\u3067\u3042\u308B\u3088\u3046\u306A\u30D1\u30B9\u3092\u306A\
    \u3081\u3066\u3044\u304F\n * \n * verified with    :https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n\
    \ * submission       :https://judge.yosupo.jp/submission/28303\n */\n\nclass centroid_decomposition{\n\
    \    using graph=vector<vector<int>>;\n    graph g;\n    vector<int>used;\n  \
    \  vector<int>v;\n    graph ch;\n    int s;\n    int dfs(int n,int p,int sz,int\
    \ root){\n        if(used[n])return 0;\n        bool b=1;\n        int res=1;\n\
    \        for(auto e:g[n]){\n            if(p==e)continue;\n            auto t=dfs(e,n,sz,root);\n\
    \            res+=t;\n            if(t>sz/2)b=0;\n        }\n        if(!b||sz-res>sz/2)return\
    \ res;\n        if(root!=-1)ch[root].push_back(n);\n        else s=n;\n      \
    \  v.push_back(n);\n        used[n]=1;\n        for(auto e:g[n]){\n          \
    \  dfs(e,n,dfs(e,n,g.size()*2,n),n);\n        }\n        return g.size()*2;\n\
    \    }\n    public:\n    centroid_decomposition(const graph&g):g(g){\n       \
    \ int n=g.size();\n        used.resize(n);\n        ch.resize(n);\n        dfs(0,-1,n,-1);\n\
    \    }\n\n    int get_root(){return s;}\n    vector<int> operator[](int i){return\
    \ ch[i];}\n    vector<int> get_euler_tour(){return v;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/give_us_tmp/centroid_decomposition.cpp
- /library/give_us_tmp/centroid_decomposition.cpp.html
title: "\u91CD\u5FC3\u5206\u89E3"
---
