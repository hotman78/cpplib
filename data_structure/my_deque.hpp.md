---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/my_deque.hpp\"\ntemplate<typename T>\nstruct\
    \ my_deque{\n    T* v;\n    int l=0,r=0,sz=1;\n    inline int mod(int x){\n  \
    \      if(x>=sz)return x-sz;\n        else return x;\n    }\n    my_deque(){\n\
    \        v=(T*)malloc(sizeof(T));\n    }\n    bool empty(){\n        return l==r;\n\
    \    }\n    int size(){\n        return mod(r-l+sz);\n    }\n    void resize(){\n\
    \        T* nv=(T*)malloc(sizeof(T)*sz*2);\n        int idx=l;\n        for(int\
    \ i=0;i<sz;++i){\n            nv[i]=v[idx];\n            idx=mod(idx+1);\n   \
    \     }\n        l=0;\n        r=sz;\n        swap(v,nv);\n        free(nv);\n\
    \        sz*=2;\n    }\n    void pop_back(){\n        r=mod(r-1+sz);\n    }\n\
    \    void pop_front(){\n        l=mod(l+1);\n    }\n    void push_back(T x){\n\
    \        v[r]=x;\n        r=mod(r+1);\n        if(l==r)resize();\n    }\n    void\
    \ push_front(T x){\n        l=mod(l-1+sz);\n        v[l]=x;\n        if(l==r)resize();\n\
    \    }\n    T& back(){\n        return v[mod(r-1+sz)];\n    }\n    T& front(){\n\
    \        return v[l];\n    }\n    T& operator[](size_t idx){\n        assert(0<=idx&&idx<size());\n\
    \        return v[mod(l+idx)];\n    }\n};\n"
  code: "template<typename T>\nstruct my_deque{\n    T* v;\n    int l=0,r=0,sz=1;\n\
    \    inline int mod(int x){\n        if(x>=sz)return x-sz;\n        else return\
    \ x;\n    }\n    my_deque(){\n        v=(T*)malloc(sizeof(T));\n    }\n    bool\
    \ empty(){\n        return l==r;\n    }\n    int size(){\n        return mod(r-l+sz);\n\
    \    }\n    void resize(){\n        T* nv=(T*)malloc(sizeof(T)*sz*2);\n      \
    \  int idx=l;\n        for(int i=0;i<sz;++i){\n            nv[i]=v[idx];\n   \
    \         idx=mod(idx+1);\n        }\n        l=0;\n        r=sz;\n        swap(v,nv);\n\
    \        free(nv);\n        sz*=2;\n    }\n    void pop_back(){\n        r=mod(r-1+sz);\n\
    \    }\n    void pop_front(){\n        l=mod(l+1);\n    }\n    void push_back(T\
    \ x){\n        v[r]=x;\n        r=mod(r+1);\n        if(l==r)resize();\n    }\n\
    \    void push_front(T x){\n        l=mod(l-1+sz);\n        v[l]=x;\n        if(l==r)resize();\n\
    \    }\n    T& back(){\n        return v[mod(r-1+sz)];\n    }\n    T& front(){\n\
    \        return v[l];\n    }\n    T& operator[](size_t idx){\n        assert(0<=idx&&idx<size());\n\
    \        return v[mod(l+idx)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/my_deque.hpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/my_deque.hpp
layout: document
redirect_from:
- /library/data_structure/my_deque.hpp
- /library/data_structure/my_deque.hpp.html
title: data_structure/my_deque.hpp
---
