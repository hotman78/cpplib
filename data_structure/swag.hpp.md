---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: SWAG(Queue)
    links: []
  bundledCode: "#line 2 \"data_structure/swag.hpp\"\n#include<stack>\n#include<tuple>\n\
    #include<cmath>\n\n/**\n * @brief SWAG(Queue)\n */\n\ntemplate<typename T,typename\
    \ E=T>\nclass swag{\n    std::stack<std::pair<T,E>>front,back;\n    public:\n\
    \    inline int size(){\n        return front.size()+back.size();\n    }\n   \
    \ inline int empty(){\n        return front.empty()&&back.empty();\n    }\n  \
    \  void push(T val){\n        if(back.empty()){\n            back.emplace(val,f(e,val));\n\
    \        }else{\n            back.emplace(val,f(back.top().second,val));\n   \
    \     }\n    }\n    void pop(){\n        if(front.empty()){\n            while(!back.empty()){\n\
    \                const T val=back.top().first;\n                back.pop();\n\
    \                if(front.empty())front.emplace(val,f(val,e));\n             \
    \   else front.emplace(val,f(val,front.top().second));\n            }\n      \
    \  }\n        front.pop();\n    }\n    E fold(){\n        return f(front.empty()?e:front.top().second,back.empty()?e:back.top().second);\n\
    \    }\n    private:\n    E f(const T& s,const T& t){\n        return std::min(s,t);\n\
    \    }\n    E e=1LL<<60;\n};\n"
  code: "#pragma once\n#include<stack>\n#include<tuple>\n#include<cmath>\n\n/**\n\
    \ * @brief SWAG(Queue)\n */\n\ntemplate<typename T,typename E=T>\nclass swag{\n\
    \    std::stack<std::pair<T,E>>front,back;\n    public:\n    inline int size(){\n\
    \        return front.size()+back.size();\n    }\n    inline int empty(){\n  \
    \      return front.empty()&&back.empty();\n    }\n    void push(T val){\n   \
    \     if(back.empty()){\n            back.emplace(val,f(e,val));\n        }else{\n\
    \            back.emplace(val,f(back.top().second,val));\n        }\n    }\n \
    \   void pop(){\n        if(front.empty()){\n            while(!back.empty()){\n\
    \                const T val=back.top().first;\n                back.pop();\n\
    \                if(front.empty())front.emplace(val,f(val,e));\n             \
    \   else front.emplace(val,f(val,front.top().second));\n            }\n      \
    \  }\n        front.pop();\n    }\n    E fold(){\n        return f(front.empty()?e:front.top().second,back.empty()?e:back.top().second);\n\
    \    }\n    private:\n    E f(const T& s,const T& t){\n        return std::min(s,t);\n\
    \    }\n    E e=1LL<<60;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/swag.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/swag.hpp
layout: document
redirect_from:
- /library/data_structure/swag.hpp
- /library/data_structure/swag.hpp.html
title: SWAG(Queue)
---
