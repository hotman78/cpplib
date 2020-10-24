---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Trie\u6728"
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n#include<string>\n\n/**\n * @brief Trie\u6728\
    \n */\n\nstruct trie{\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        int sz=0,sz2=0;\n        np ch[10];\n        node(){\n            for(int\
    \ i=0;i<10;i++)ch[i]=nullptr;\n        }\n    };\n    np root=new node();\n  \
    \  void add(const std::string& s){\n        np t=root;\n        t->sz++;\n   \
    \     for(int i=0;i<(int)s.size();++i){\n            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new\
    \ node();\n            t=t->ch[s[i]-'0'];\n            t->sz++;\n        }\n \
    \       t->sz2=1;\n    }\n    int count(const std::string& s){\n        np t=root;\n\
    \        for(int i=0;i<(int)s.size();++i){\n            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new\
    \ node();\n            t=t->ch[s[i]-'0'];\n            if(!t->sz)return 0;\n \
    \       }\n        return t->sz2;\n    }\n};\n"
  code: "#pragma once\n#include<string>\n\n/**\n * @brief Trie\u6728\n */\n\nstruct\
    \ trie{\n    struct node;\n    using np=node*;\n    struct node{\n        int\
    \ sz=0,sz2=0;\n        np ch[10];\n        node(){\n            for(int i=0;i<10;i++)ch[i]=nullptr;\n\
    \        }\n    };\n    np root=new node();\n    void add(const std::string& s){\n\
    \        np t=root;\n        t->sz++;\n        for(int i=0;i<(int)s.size();++i){\n\
    \            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new node();\n            t=t->ch[s[i]-'0'];\n\
    \            t->sz++;\n        }\n        t->sz2=1;\n    }\n    int count(const\
    \ std::string& s){\n        np t=root;\n        for(int i=0;i<(int)s.size();++i){\n\
    \            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new node();\n            t=t->ch[s[i]-'0'];\n\
    \            if(!t->sz)return 0;\n        }\n        return t->sz2;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2020-10-24 18:28:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: "Trie\u6728"
---
