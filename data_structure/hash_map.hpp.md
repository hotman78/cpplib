---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: data_structure/test/LC_hash_map.test.cpp
    title: data_structure/test/LC_hash_map.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: HashMap(WIP)
    links: []
  bundledCode: "#line 2 \"data_structure/hash_map.hpp\"\n#include<tuple>\n/**\n *\
    \ @brief HashMap(WIP)\n */\n\ntemplate<typename T,typename E,typename F=std::hash<T>>\n\
    struct hash_map{\n    struct node{\n        T key;E val;\n        unsigned long\
    \ b;\n        node():key(T()),val(E()),b(0){}\n        node(T key,E val):key(key),val(val),b(0){}\n\
    \        static node* alc;\n        static size_t cnt;\n        static size_t\
    \ alc_sz;\n        void* operator new(size_t){\n            if(alc_sz==cnt){\n\
    \                alc_sz*=2;\n                alc=(node*)malloc(alc_sz*sizeof(node));\n\
    \                cnt=0;\n            }\n            return alc+cnt++;\n      \
    \  }\n    };\n    size_t sz;\n    node* point;\n    constexpr static size_t mod_list[24]={37,67,131,257,521,1031,2053,4099,8209,16411,32771,65537,131101,262147,524309,1048583,2097169,4194319,8388617,16777259,33554467,67108879,134217757,268435459};\n\
    \    node** table;\n    F op;\n    hash_map(F op=F()):sz(15),op(op){\n       \
    \ table=new node*[mod_list[sz]]();\n    }\n    node** _realloc(){\n        const\
    \ size_t old_sz=sz;\n        while(1){\n            sz++;\n            bool fail=0;\n\
    \            node** tmp=new node*[mod_list[sz]]();\n            for(node** itr=table;itr<table+mod_list[old_sz];++itr){\n\
    \                if(*itr==0)continue;\n                const size_t ha=op((*itr)->key)%mod_list[sz];\n\
    \                (*itr)->b=0;\n                if(insert(tmp,*itr,ha).first==0){fail=1;break;}\n\
    \            }\n            if(fail){\n                delete[] tmp;\n       \
    \     }\n            else {\n                delete[] table;\n               \
    \ table=tmp;\n                break;\n            }\n        }\n        return\
    \ table;\n    }\n    std::pair<bool,node*> insert(node** table,node* t,size_t\
    \ tmp){\n        if(!table[tmp])return {true,table[tmp]=t};\n        size_t k=0;\n\
    \        unsigned long tt=~table[tmp]->b;\n        const size_t pre=tmp;\n   \
    \     unsigned long x=1;\n        while(tt){\n            tmp+=(k=__builtin_ctzl(tt)+1);\n\
    \            x<<=k;\n            tt>>=k;\n            tmp%=mod_list[sz];\n   \
    \         if(!table[tmp]){\n                table[tmp]=t;\n                table[pre]->b|=x>>1;\n\
    \                return {true,table[tmp]};\n            }\n        }\n       \
    \ return {false,nullptr};\n    }\n    std::pair<bool,node*> search(T key,size_t\
    \ tmp){\n        int k=0;\n        if(!table[tmp])return {false,nullptr};\n  \
    \      if(table[tmp]->key==key)return {true,table[tmp]};\n\n        unsigned long\
    \ t=table[tmp]->b;\n        while(t){\n            tmp+=(k=__builtin_ctzl(t)+1);\n\
    \            tmp%=mod_list[sz];\n            t>>=k;\n            if(table[tmp]->key==key)return\
    \ {true,table[tmp]};\n        }\n        return {false,nullptr};\n    }\n    E&\
    \ operator[](T key){\n        size_t ha=op(key)%mod_list[sz];\n        auto res=search(key,ha);\n\
    \        if(res.first)return res.second->val;\n        else {\n            while(1){\n\
    \                auto res=insert(table,new node(key,E()),ha);\n              \
    \  if(res.first)return res.second->val;\n                _realloc();\n       \
    \         ha=op(key)%mod_list[sz];\n            }\n        }\n    }\n};\ntemplate<typename\
    \ T,typename E,typename F=std::hash<T>>typename hash_map<T,E,F>::node* hash_map<T,E,F>::node::alc=(node*)malloc(sizeof(node));\n\
    template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::cnt=0;\n\
    template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::alc_sz=1;\n"
  code: "#pragma once\n#include<tuple>\n/**\n * @brief HashMap(WIP)\n */\n\ntemplate<typename\
    \ T,typename E,typename F=std::hash<T>>\nstruct hash_map{\n    struct node{\n\
    \        T key;E val;\n        unsigned long b;\n        node():key(T()),val(E()),b(0){}\n\
    \        node(T key,E val):key(key),val(val),b(0){}\n        static node* alc;\n\
    \        static size_t cnt;\n        static size_t alc_sz;\n        void* operator\
    \ new(size_t){\n            if(alc_sz==cnt){\n                alc_sz*=2;\n   \
    \             alc=(node*)malloc(alc_sz*sizeof(node));\n                cnt=0;\n\
    \            }\n            return alc+cnt++;\n        }\n    };\n    size_t sz;\n\
    \    node* point;\n    constexpr static size_t mod_list[24]={37,67,131,257,521,1031,2053,4099,8209,16411,32771,65537,131101,262147,524309,1048583,2097169,4194319,8388617,16777259,33554467,67108879,134217757,268435459};\n\
    \    node** table;\n    F op;\n    hash_map(F op=F()):sz(15),op(op){\n       \
    \ table=new node*[mod_list[sz]]();\n    }\n    node** _realloc(){\n        const\
    \ size_t old_sz=sz;\n        while(1){\n            sz++;\n            bool fail=0;\n\
    \            node** tmp=new node*[mod_list[sz]]();\n            for(node** itr=table;itr<table+mod_list[old_sz];++itr){\n\
    \                if(*itr==0)continue;\n                const size_t ha=op((*itr)->key)%mod_list[sz];\n\
    \                (*itr)->b=0;\n                if(insert(tmp,*itr,ha).first==0){fail=1;break;}\n\
    \            }\n            if(fail){\n                delete[] tmp;\n       \
    \     }\n            else {\n                delete[] table;\n               \
    \ table=tmp;\n                break;\n            }\n        }\n        return\
    \ table;\n    }\n    std::pair<bool,node*> insert(node** table,node* t,size_t\
    \ tmp){\n        if(!table[tmp])return {true,table[tmp]=t};\n        size_t k=0;\n\
    \        unsigned long tt=~table[tmp]->b;\n        const size_t pre=tmp;\n   \
    \     unsigned long x=1;\n        while(tt){\n            tmp+=(k=__builtin_ctzl(tt)+1);\n\
    \            x<<=k;\n            tt>>=k;\n            tmp%=mod_list[sz];\n   \
    \         if(!table[tmp]){\n                table[tmp]=t;\n                table[pre]->b|=x>>1;\n\
    \                return {true,table[tmp]};\n            }\n        }\n       \
    \ return {false,nullptr};\n    }\n    std::pair<bool,node*> search(T key,size_t\
    \ tmp){\n        int k=0;\n        if(!table[tmp])return {false,nullptr};\n  \
    \      if(table[tmp]->key==key)return {true,table[tmp]};\n\n        unsigned long\
    \ t=table[tmp]->b;\n        while(t){\n            tmp+=(k=__builtin_ctzl(t)+1);\n\
    \            tmp%=mod_list[sz];\n            t>>=k;\n            if(table[tmp]->key==key)return\
    \ {true,table[tmp]};\n        }\n        return {false,nullptr};\n    }\n    E&\
    \ operator[](T key){\n        size_t ha=op(key)%mod_list[sz];\n        auto res=search(key,ha);\n\
    \        if(res.first)return res.second->val;\n        else {\n            while(1){\n\
    \                auto res=insert(table,new node(key,E()),ha);\n              \
    \  if(res.first)return res.second->val;\n                _realloc();\n       \
    \         ha=op(key)%mod_list[sz];\n            }\n        }\n    }\n};\ntemplate<typename\
    \ T,typename E,typename F=std::hash<T>>typename hash_map<T,E,F>::node* hash_map<T,E,F>::node::alc=(node*)malloc(sizeof(node));\n\
    template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::cnt=0;\n\
    template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::alc_sz=1;\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/hash_map.hpp
  requiredBy: []
  timestamp: '2020-09-26 18:27:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - data_structure/test/LC_hash_map.test.cpp
documentation_of: data_structure/hash_map.hpp
layout: document
redirect_from:
- /library/data_structure/hash_map.hpp
- /library/data_structure/hash_map.hpp.html
title: HashMap(WIP)
---
