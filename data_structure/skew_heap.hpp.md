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
  bundledCode: "#line 2 \"data_structure/skew_heap.hpp\"\n\ntemplate<typename T>\n\
    class skew_heap{\n\tstruct node;\n\tusing np=node*;\n\tstruct node{\n\t\tnp ch[2]={nullptr,nullptr};\n\
    \t\tT val;\n\t\tnode(T val):val(val){}\n\t};\n\tnp root=nullptr;\n\tnp meld(np\
    \ a,np b) {\n\t\tif(!a||!b)return a?a:b;\n\t\tif(a->val>b->val)swap(a,b);\n\t\t\
    a->ch[1]=meld(a->ch[1],b);\n\t\tswap(a->ch[0],a->ch[1]);\n\t\treturn a;\n\t}\n\
    \tpublic:\n\tskew_heap(np root=nullptr):root(root){}\n    bool empty(){return\
    \ !root;}\n\tvoid insert(T val){root=meld(root,new node(val));}\n\tvoid pop(){root=meld(root->ch[0],root->ch[1]);}\n\
    \tT top(){return root->val;}\n\tnp meld(skew_heap s,skew_heap t){return new skew_heap(meld(s->root,t->root));}\n\
    };\n"
  code: "#pragma once\n\ntemplate<typename T>\nclass skew_heap{\n\tstruct node;\n\t\
    using np=node*;\n\tstruct node{\n\t\tnp ch[2]={nullptr,nullptr};\n\t\tT val;\n\
    \t\tnode(T val):val(val){}\n\t};\n\tnp root=nullptr;\n\tnp meld(np a,np b) {\n\
    \t\tif(!a||!b)return a?a:b;\n\t\tif(a->val>b->val)swap(a,b);\n\t\ta->ch[1]=meld(a->ch[1],b);\n\
    \t\tswap(a->ch[0],a->ch[1]);\n\t\treturn a;\n\t}\n\tpublic:\n\tskew_heap(np root=nullptr):root(root){}\n\
    \    bool empty(){return !root;}\n\tvoid insert(T val){root=meld(root,new node(val));}\n\
    \tvoid pop(){root=meld(root->ch[0],root->ch[1]);}\n\tT top(){return root->val;}\n\
    \tnp meld(skew_heap s,skew_heap t){return new skew_heap(meld(s->root,t->root));}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/skew_heap.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/skew_heap.hpp
layout: document
redirect_from:
- /library/data_structure/skew_heap.hpp
- /library/data_structure/skew_heap.hpp.html
title: data_structure/skew_heap.hpp
---
