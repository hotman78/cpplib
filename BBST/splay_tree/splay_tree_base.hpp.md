---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: BBST/splay_tree/splay_tree_array.hpp
    title: BBST/splay_tree/splay_tree_array.hpp
  - icon: ':warning:'
    path: BBST/splay_tree/splay_tree_array_ushi.hpp
    title: BBST/splay_tree/splay_tree_array_ushi.hpp
  - icon: ':warning:'
    path: BBST/splay_tree/splay_tree_set.hpp
    title: BBST/splay_tree/splay_tree_set.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"BBST/splay_tree/splay_tree_base.hpp\"\n#include<vector>\n\
    #include<tuple>\n#include<assert.h>\n\ntemplate<typename Node>\nstruct splay_tree_base{\n\
    \    using np=Node*;\n    np root=0;\n    inline int size(np t){return t?t->sz:0;}\n\
    \    int size(){return size(root);}\n    np rot(np t,bool b){\n        np s=t->ch[1-b];\n\
    \        assert(s);\n        np u=s->ch[b];\n        t->ch[1-b]=u;\n        s->ch[b]=t;\n\
    \        t->update();s->update();\n        return s;\n    }\n    void erase(int\
    \ idx){\n        auto [p,q]=split(root,idx);\n        auto [s,t]=split(q,1);\n\
    \        delete s;\n        root=merge(p,t);\n    }\n    void insert(int idx,np\
    \ val){\n        if(size(root)==idx){\n            root=merge(root,val);\n   \
    \     }else{\n            auto [p,q]=split(root,idx);\n            root=merge(merge(p,val),q);\n\
    \        }\n    }\n    np merge(np s,np t){\n        if(!s||!t)return s?s:t;\n\
    \        s=splay(s,size(s)-1);\n        s->ch[1]=t;\n        return s->update();\n\
    \    }\n    std::pair<np,np> split(np t,int idx){\n        if(size(t)==idx)return\
    \ std::make_pair(t,nullptr);\n        t=splay(t,idx);\n        np s=t->ch[0];\n\
    \        t->ch[0]=nullptr;\n        return std::make_pair(s,t->update());\n  \
    \  }\n    np splay(np t,int idx){\n        if(idx==size(t->ch[0]))return t;\n\n\
    \        bool b1=size(t->ch[0])<idx;\n        if(b1)idx-=size(t->ch[0])+1;\n\n\
    \        if(idx==size(t->ch[b1]->ch[0]))return rot(t,1-b1);\n        bool b2=size(t->ch[b1]->ch[0])<idx;\n\
    \        if(b2)idx-=size(t->ch[b1]->ch[0])+1;\n\n        t->ch[b1]->ch[b2]=splay(t->ch[b1]->ch[b2],idx);\n\
    \        if(b1==b2)t=rot(t,1-b2);\n        else t->ch[b1]=rot(t->ch[b1],1-b2);\n\
    \n        return rot(t,1-b1);\n    }\n    std::vector<np> output(){\n        std::vector<np>res;\n\
    \        auto dfs=[&](auto dfs,np t)->void{\n            if(!t)return;\n     \
    \       dfs(dfs,t->ch[0]);\n            res.push_back(t);\n            dfs(dfs,t->ch[1]);\n\
    \        };\n        dfs(dfs,root);\n        return res;\n    }\n    np get_root(){return\
    \ root;}\n    np get(int i){root=splay(root,i);return root;}\n    \n    template<typename\
    \ C>\n    int lower_bound(C less){\n        int res=__lower_bound(root,less);\n\
    \        root=splay(root,res);\n        return res;\n    }\n    template<typename\
    \ C>\n    int __lower_bound(np t,C less){\n        bool b=less(t);\n        if(b)__lower_bound(t->ch[0],less);\n\
    \        else __lower_bound(t->ch[1],less);\n    }\n};\n"
  code: "#include<vector>\n#include<tuple>\n#include<assert.h>\n\ntemplate<typename\
    \ Node>\nstruct splay_tree_base{\n    using np=Node*;\n    np root=0;\n    inline\
    \ int size(np t){return t?t->sz:0;}\n    int size(){return size(root);}\n    np\
    \ rot(np t,bool b){\n        np s=t->ch[1-b];\n        assert(s);\n        np\
    \ u=s->ch[b];\n        t->ch[1-b]=u;\n        s->ch[b]=t;\n        t->update();s->update();\n\
    \        return s;\n    }\n    void erase(int idx){\n        auto [p,q]=split(root,idx);\n\
    \        auto [s,t]=split(q,1);\n        delete s;\n        root=merge(p,t);\n\
    \    }\n    void insert(int idx,np val){\n        if(size(root)==idx){\n     \
    \       root=merge(root,val);\n        }else{\n            auto [p,q]=split(root,idx);\n\
    \            root=merge(merge(p,val),q);\n        }\n    }\n    np merge(np s,np\
    \ t){\n        if(!s||!t)return s?s:t;\n        s=splay(s,size(s)-1);\n      \
    \  s->ch[1]=t;\n        return s->update();\n    }\n    std::pair<np,np> split(np\
    \ t,int idx){\n        if(size(t)==idx)return std::make_pair(t,nullptr);\n   \
    \     t=splay(t,idx);\n        np s=t->ch[0];\n        t->ch[0]=nullptr;\n   \
    \     return std::make_pair(s,t->update());\n    }\n    np splay(np t,int idx){\n\
    \        if(idx==size(t->ch[0]))return t;\n\n        bool b1=size(t->ch[0])<idx;\n\
    \        if(b1)idx-=size(t->ch[0])+1;\n\n        if(idx==size(t->ch[b1]->ch[0]))return\
    \ rot(t,1-b1);\n        bool b2=size(t->ch[b1]->ch[0])<idx;\n        if(b2)idx-=size(t->ch[b1]->ch[0])+1;\n\
    \n        t->ch[b1]->ch[b2]=splay(t->ch[b1]->ch[b2],idx);\n        if(b1==b2)t=rot(t,1-b2);\n\
    \        else t->ch[b1]=rot(t->ch[b1],1-b2);\n\n        return rot(t,1-b1);\n\
    \    }\n    std::vector<np> output(){\n        std::vector<np>res;\n        auto\
    \ dfs=[&](auto dfs,np t)->void{\n            if(!t)return;\n            dfs(dfs,t->ch[0]);\n\
    \            res.push_back(t);\n            dfs(dfs,t->ch[1]);\n        };\n \
    \       dfs(dfs,root);\n        return res;\n    }\n    np get_root(){return root;}\n\
    \    np get(int i){root=splay(root,i);return root;}\n    \n    template<typename\
    \ C>\n    int lower_bound(C less){\n        int res=__lower_bound(root,less);\n\
    \        root=splay(root,res);\n        return res;\n    }\n    template<typename\
    \ C>\n    int __lower_bound(np t,C less){\n        bool b=less(t);\n        if(b)__lower_bound(t->ch[0],less);\n\
    \        else __lower_bound(t->ch[1],less);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: BBST/splay_tree/splay_tree_base.hpp
  requiredBy:
  - BBST/splay_tree/splay_tree_array.hpp
  - BBST/splay_tree/splay_tree_array_ushi.hpp
  - BBST/splay_tree/splay_tree_set.hpp
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: BBST/splay_tree/splay_tree_base.hpp
layout: document
redirect_from:
- /library/BBST/splay_tree/splay_tree_base.hpp
- /library/BBST/splay_tree/splay_tree_base.hpp.html
title: BBST/splay_tree/splay_tree_base.hpp
---
