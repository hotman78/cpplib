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
  bundledCode: "#line 2 \"data_structure/binary_heap.hpp\"\n#include<vector>\n#include<algorithm>\n\
    \ntemplate<typename T>\nstruct binary_heap{\n\tint idx=1;\n\tstruct node{\n\t\t\
    int idx;\n\t\tT val;\n\t\tnode(int idx,T val):idx(idx),val(val){}\n\t};\n\tusing\
    \ np=node*;\n\tstd::vector<np>v;\n\tbinary_heap():v(2,0){}\n\tvoid __swap(np&\
    \ s,np& t){\n\t\tstd::swap(s,t);\n\t\tstd::swap(s->idx,t->idx);\n\t}\n\tvoid up(int\
    \ k){\n\t\twhile(k>1&&comp(v[k]->val,v[k/2]->val)){\n\t\t\t__swap(v[k],v[k/2]);\n\
    \t\t\tk/=2;\n\t\t}\n\t}\n\tvoid down(int k){\n\t\twhile(1){\n\t\t\tif(k*2+1<idx&&(comp(v[k*2]->val,v[k]->val)||comp(v[k*2+1]->val,v[k]->val))){\n\
    \t\t\t\tif(comp(v[k*2]->val,v[k*2+1]->val)){\n\t\t\t\t\t__swap(v[k],v[k*2]);\n\
    \t\t\t\t\tk=k*2;\n\t\t\t\t}else{\n\t\t\t\t\t__swap(v[k],v[k*2+1]);\n\t\t\t\t\t\
    k=k*2+1;\n\t\t\t\t}\n\t\t\t}else if(k*2<idx&&comp(v[k*2]->val,v[k]->val)){\n\t\
    \t\t\t__swap(v[k],v[k*2]);\n\t\t\t\tk=k*2;\n\t\t\t}else{\n\t\t\t\tbreak;\n\t\t\
    \t}\n\t\t}\n\t}\n\tnp insert(T val){\n\t\tif((int)v.size()<=idx+1)v.resize(v.size()*2,0);\n\
    \t\tnp res=new node(idx,val);\n\t\tv[idx]=res;\n\t\tup(idx++);\n\t\treturn res;\n\
    \t}\n\tT top(){\n\t\treturn v[1]->val;\n\t}\n\tvoid pop(){\n\t\t__swap(v[1],v[--idx]);\n\
    \t\tdown(1);\n\t}\n\tint size(){\n\t\treturn idx-1;\n\t}\n\tbool empty(){\n\t\t\
    return idx==1;\n\t}\n\tvoid modify(np t,T val){\n\t\tt->val=val;\n\t\tup(t->idx);\n\
    \t\tdown(t->idx);\n\t}\n\tbool comp(T s,T t){\n\t\treturn s<t;\n\t}\n};\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\n\ntemplate<typename\
    \ T>\nstruct binary_heap{\n\tint idx=1;\n\tstruct node{\n\t\tint idx;\n\t\tT val;\n\
    \t\tnode(int idx,T val):idx(idx),val(val){}\n\t};\n\tusing np=node*;\n\tstd::vector<np>v;\n\
    \tbinary_heap():v(2,0){}\n\tvoid __swap(np& s,np& t){\n\t\tstd::swap(s,t);\n\t\
    \tstd::swap(s->idx,t->idx);\n\t}\n\tvoid up(int k){\n\t\twhile(k>1&&comp(v[k]->val,v[k/2]->val)){\n\
    \t\t\t__swap(v[k],v[k/2]);\n\t\t\tk/=2;\n\t\t}\n\t}\n\tvoid down(int k){\n\t\t\
    while(1){\n\t\t\tif(k*2+1<idx&&(comp(v[k*2]->val,v[k]->val)||comp(v[k*2+1]->val,v[k]->val))){\n\
    \t\t\t\tif(comp(v[k*2]->val,v[k*2+1]->val)){\n\t\t\t\t\t__swap(v[k],v[k*2]);\n\
    \t\t\t\t\tk=k*2;\n\t\t\t\t}else{\n\t\t\t\t\t__swap(v[k],v[k*2+1]);\n\t\t\t\t\t\
    k=k*2+1;\n\t\t\t\t}\n\t\t\t}else if(k*2<idx&&comp(v[k*2]->val,v[k]->val)){\n\t\
    \t\t\t__swap(v[k],v[k*2]);\n\t\t\t\tk=k*2;\n\t\t\t}else{\n\t\t\t\tbreak;\n\t\t\
    \t}\n\t\t}\n\t}\n\tnp insert(T val){\n\t\tif((int)v.size()<=idx+1)v.resize(v.size()*2,0);\n\
    \t\tnp res=new node(idx,val);\n\t\tv[idx]=res;\n\t\tup(idx++);\n\t\treturn res;\n\
    \t}\n\tT top(){\n\t\treturn v[1]->val;\n\t}\n\tvoid pop(){\n\t\t__swap(v[1],v[--idx]);\n\
    \t\tdown(1);\n\t}\n\tint size(){\n\t\treturn idx-1;\n\t}\n\tbool empty(){\n\t\t\
    return idx==1;\n\t}\n\tvoid modify(np t,T val){\n\t\tt->val=val;\n\t\tup(t->idx);\n\
    \t\tdown(t->idx);\n\t}\n\tbool comp(T s,T t){\n\t\treturn s<t;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_heap.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_heap.hpp
layout: document
redirect_from:
- /library/data_structure/binary_heap.hpp
- /library/data_structure/binary_heap.hpp.html
title: data_structure/binary_heap.hpp
---
