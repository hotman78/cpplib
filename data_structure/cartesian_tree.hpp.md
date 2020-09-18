---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: cartesian_tree
    links: []
  bundledCode: "#line 2 \"data_structure/cartesian_tree.hpp\"\n#include<vector>\n\
    #include<stack>\n\n/**\n * @brief cartesian_tree\n */\n\n\ntemplate<typename T>\n\
    struct cartesian_tree{\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        np ch[2]={0,0};\n        T val;\n        int pos;\n        int sz=0;\n\
    \        node(T val,int pos):val(val),pos(pos){}\n    };\n    int size(np t){return\
    \ t?t->sz:0;}\n    np update(np t){}\n    np root=0;\n    int sz=0;\n    cartesian_tree(std::vector<T>v){\n\
    \        for(auto e:v)push_back(e);\n    }\n    void push_back(int val){\n   \
    \     static std::stack<np>stk;\n        while(!stk.empty()&&stk.top()->val<=val)stk.pop();\n\
    \        np t=new node(val,sz);\n        if(stk.empty()){\n            t->ch[0]=root;\n\
    \            root=t;\n        }else{\n            t->ch[0]=stk.top()->ch[1];\n\
    \            stk.top()->ch[1]=t;\n        }\n        stk.emplace(t);\n       \
    \ sz++;\n    }\n    std::int64_t update_size(np t){\n        if(!t)return 0;\n\
    \        return t->sz=update_size(t->ch[0])+1+update_size(t->ch[1]);\n    }\n\
    };\n"
  code: "#pragma once\n#include<vector>\n#include<stack>\n\n/**\n * @brief cartesian_tree\n\
    \ */\n\n\ntemplate<typename T>\nstruct cartesian_tree{\n    struct node;\n   \
    \ using np=node*;\n    struct node{\n        np ch[2]={0,0};\n        T val;\n\
    \        int pos;\n        int sz=0;\n        node(T val,int pos):val(val),pos(pos){}\n\
    \    };\n    int size(np t){return t?t->sz:0;}\n    np update(np t){}\n    np\
    \ root=0;\n    int sz=0;\n    cartesian_tree(std::vector<T>v){\n        for(auto\
    \ e:v)push_back(e);\n    }\n    void push_back(int val){\n        static std::stack<np>stk;\n\
    \        while(!stk.empty()&&stk.top()->val<=val)stk.pop();\n        np t=new\
    \ node(val,sz);\n        if(stk.empty()){\n            t->ch[0]=root;\n      \
    \      root=t;\n        }else{\n            t->ch[0]=stk.top()->ch[1];\n     \
    \       stk.top()->ch[1]=t;\n        }\n        stk.emplace(t);\n        sz++;\n\
    \    }\n    std::int64_t update_size(np t){\n        if(!t)return 0;\n       \
    \ return t->sz=update_size(t->ch[0])+1+update_size(t->ch[1]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/cartesian_tree.hpp
layout: document
redirect_from:
- /library/data_structure/cartesian_tree.hpp
- /library/data_structure/cartesian_tree.hpp.html
title: cartesian_tree
---
