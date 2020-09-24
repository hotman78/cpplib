---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_swag.test.cpp
    title: data_structure/test/LC_swag.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: SWAG(Queue)
    links: []
  bundledCode: "#line 2 \"data_structure/swag.hpp\"\n#include<stack>\n#include<tuple>\n\
    #include<cmath>\n#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief\
    \ Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 6\
    \ \"data_structure/swag.hpp\"\n/**\n * @brief SWAG(Queue)\n */\n\ntemplate<typename\
    \ T,typename F>\nclass swag{\n    std::stack<std::pair<T,T>>front,back;\n    F\
    \ f;\n    public:\n    swag(F f=F()):f(f){}\n    inline int size(){\n        return\
    \ front.size()+back.size();\n    }\n    inline int empty(){\n        return front.empty()&&back.empty();\n\
    \    }\n    void push(T val){\n        if(back.empty()){\n            back.emplace(val,val);\n\
    \        }else{\n            back.emplace(val,f(back.top().second,val));\n   \
    \     }\n    }\n    void pop(){\n        if(front.empty()){\n            while(!back.empty()){\n\
    \                const T val=back.top().first;\n                back.pop();\n\
    \                if(front.empty())front.emplace(val,val);\n                else\
    \ front.emplace(val,f(val,front.top().second));\n            }\n        }\n  \
    \      front.pop();\n    }\n    maybe<T> fold(){\n        if(front.empty()&&back.empty())return\
    \ maybe<T>();\n        else if(front.empty()||back.empty())return front.empty()?back.top().second:front.top().second;\n\
    \        return f(front.top().second,back.top().second);\n    }\n};\n"
  code: "#pragma once\n#include<stack>\n#include<tuple>\n#include<cmath>\n#include\"\
    ../alga/maybe.hpp\"\n/**\n * @brief SWAG(Queue)\n */\n\ntemplate<typename T,typename\
    \ F>\nclass swag{\n    std::stack<std::pair<T,T>>front,back;\n    F f;\n    public:\n\
    \    swag(F f=F()):f(f){}\n    inline int size(){\n        return front.size()+back.size();\n\
    \    }\n    inline int empty(){\n        return front.empty()&&back.empty();\n\
    \    }\n    void push(T val){\n        if(back.empty()){\n            back.emplace(val,val);\n\
    \        }else{\n            back.emplace(val,f(back.top().second,val));\n   \
    \     }\n    }\n    void pop(){\n        if(front.empty()){\n            while(!back.empty()){\n\
    \                const T val=back.top().first;\n                back.pop();\n\
    \                if(front.empty())front.emplace(val,val);\n                else\
    \ front.emplace(val,f(val,front.top().second));\n            }\n        }\n  \
    \      front.pop();\n    }\n    maybe<T> fold(){\n        if(front.empty()&&back.empty())return\
    \ maybe<T>();\n        else if(front.empty()||back.empty())return front.empty()?back.top().second:front.top().second;\n\
    \        return f(front.top().second,back.top().second);\n    }\n};"
  dependsOn:
  - alga/maybe.hpp
  isVerificationFile: false
  path: data_structure/swag.hpp
  requiredBy: []
  timestamp: '2020-09-19 12:18:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_swag.test.cpp
documentation_of: data_structure/swag.hpp
layout: document
redirect_from:
- /library/data_structure/swag.hpp
- /library/data_structure/swag.hpp.html
title: SWAG(Queue)
---
