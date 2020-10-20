---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30DE\u30FC\u30B8\u53EF\u80FD\u30D2\u30FC\u30D7(LeftistHeap)"
    links: []
  bundledCode: "#line 2 \"data_structure/leftist_heap.hpp\"\n\n/**\n * @brief \u30DE\
    \u30FC\u30B8\u53EF\u80FD\u30D2\u30FC\u30D7(LeftistHeap)\n */\n\ntemplate<typename\
    \ T>\nstruct heap{\n    struct node{\n        node* ch[2]={0,0};\n        int\
    \ s;\n        T val;\n        node(T val):s(1),val(val){}\n    };\n    using np=node*;\n\
    \    np root=0;\n    heap(np t=0):root(t){}\n    np meld(np a,np b){\n       \
    \ if(!a||!b)return a?a:b;\n        if(a->val>b->val)swap(a,b);\n        a->ch[1]=meld(a->ch[1],b);\n\
    \        if(!a->ch[0]||a->ch[0]->s<a->ch[1]->s)swap(a->ch[0],a->ch[1]);\n    \
    \    a->s=(a->ch[1]?a->ch[1]->s:0)+1;\n        return a;\n    }\n    void meld(heap\
    \ b){\n        root=meld(root,b.root);\n    }\n    void insert(T x){\n       \
    \ root=meld(root,new node(x));\n    }\n    void pop(){\n        root=meld(root->ch[0],root->ch[1]);\n\
    \    }\n    T top(){\n        return root?root->val:T();\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u30DE\u30FC\u30B8\u53EF\u80FD\u30D2\u30FC\
    \u30D7(LeftistHeap)\n */\n\ntemplate<typename T>\nstruct heap{\n    struct node{\n\
    \        node* ch[2]={0,0};\n        int s;\n        T val;\n        node(T val):s(1),val(val){}\n\
    \    };\n    using np=node*;\n    np root=0;\n    heap(np t=0):root(t){}\n   \
    \ np meld(np a,np b){\n        if(!a||!b)return a?a:b;\n        if(a->val>b->val)swap(a,b);\n\
    \        a->ch[1]=meld(a->ch[1],b);\n        if(!a->ch[0]||a->ch[0]->s<a->ch[1]->s)swap(a->ch[0],a->ch[1]);\n\
    \        a->s=(a->ch[1]?a->ch[1]->s:0)+1;\n        return a;\n    }\n    void\
    \ meld(heap b){\n        root=meld(root,b.root);\n    }\n    void insert(T x){\n\
    \        root=meld(root,new node(x));\n    }\n    void pop(){\n        root=meld(root->ch[0],root->ch[1]);\n\
    \    }\n    T top(){\n        return root?root->val:T();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/leftist_heap.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/leftist_heap.hpp
layout: document
redirect_from:
- /library/data_structure/leftist_heap.hpp
- /library/data_structure/leftist_heap.hpp.html
title: "\u30DE\u30FC\u30B8\u53EF\u80FD\u30D2\u30FC\u30D7(LeftistHeap)"
---
