---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: BinaryTrie
    links: []
  bundledCode: "#line 2 \"data_structure/binary_trie.hpp\"\n#include<cstdint>\n\n\
    /**\n * @brief BinaryTrie\n */\n\nstruct binary_trie{\n    constexpr static int\
    \ B=64;\n    using u64=std::uint64_t;\n    struct node{\n        node* ch[2]={0,0};\n\
    \        int cnt=0;\n    };\n    using np=node*;\n    np root=new node();\n  \
    \  void insert(u64 x){\n        np t=root;\n        t->cnt++;\n        for(int\
    \ i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new node();\n          \
    \  if(!t->ch[1])t->ch[1]=new node();\n            t=t->ch[(x>>i)&1];\n       \
    \     t->cnt++;\n        }\n    }\n    bool erase(u64 x){\n        np t=root;\n\
    \        if(!count(x))return 0;\n        t->cnt--;\n        for(int i=B-1;i>=0;--i){\n\
    \            if(!t->ch[0])t->ch[0]=new node();\n            if(!t->ch[1])t->ch[1]=new\
    \ node();\n            t=t->ch[(x>>i)&1];\n            t->cnt--;\n        }\n\
    \        return 1;\n    }\n    int count(u64 x){\n        np t=root;\n       \
    \ for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new node();\n  \
    \          if(!t->ch[1])t->ch[1]=new node();\n            t=t->ch[(x>>i)&1];\n\
    \        }\n        return t->cnt;\n    }\n    u64 xor_min(u64 x){\n        np\
    \ t=root;\n        u64 res=0;\n        for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new\
    \ node();\n            if(!t->ch[1])t->ch[1]=new node();\n            if(t->ch[(x>>i)&1]->cnt)t=t->ch[(x>>i)&1];\n\
    \            else{\n                t=t->ch[1-((x>>i)&1)];\n                res+=1ULL<<i;\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include<cstdint>\n\n/**\n * @brief BinaryTrie\n */\n\nstruct\
    \ binary_trie{\n    constexpr static int B=64;\n    using u64=std::uint64_t;\n\
    \    struct node{\n        node* ch[2]={0,0};\n        int cnt=0;\n    };\n  \
    \  using np=node*;\n    np root=new node();\n    void insert(u64 x){\n       \
    \ np t=root;\n        t->cnt++;\n        for(int i=B-1;i>=0;--i){\n          \
    \  if(!t->ch[0])t->ch[0]=new node();\n            if(!t->ch[1])t->ch[1]=new node();\n\
    \            t=t->ch[(x>>i)&1];\n            t->cnt++;\n        }\n    }\n   \
    \ bool erase(u64 x){\n        np t=root;\n        if(!count(x))return 0;\n   \
    \     t->cnt--;\n        for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new\
    \ node();\n            if(!t->ch[1])t->ch[1]=new node();\n            t=t->ch[(x>>i)&1];\n\
    \            t->cnt--;\n        }\n        return 1;\n    }\n    int count(u64\
    \ x){\n        np t=root;\n        for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new\
    \ node();\n            if(!t->ch[1])t->ch[1]=new node();\n            t=t->ch[(x>>i)&1];\n\
    \        }\n        return t->cnt;\n    }\n    u64 xor_min(u64 x){\n        np\
    \ t=root;\n        u64 res=0;\n        for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new\
    \ node();\n            if(!t->ch[1])t->ch[1]=new node();\n            if(t->ch[(x>>i)&1]->cnt)t=t->ch[(x>>i)&1];\n\
    \            else{\n                t=t->ch[1-((x>>i)&1)];\n                res+=1ULL<<i;\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:55:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: BinaryTrie
---
