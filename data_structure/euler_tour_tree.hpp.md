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
  bundledCode: "#line 1 \"data_structure/euler_tour_tree.hpp\"\ntemplate<typename\
    \ T,typename E>\nclass euler_tour_tree{\n\tpublic:\n    struct node;\n    using\
    \ np=node*;\n\tusing lint=long long;\n    struct node{\n        np ch[2]={nullptr,nullptr};\n\
    \        np p=nullptr;\n        int l,r,sz=1,sz2=0;\n\t\tT val=et,sum=et;\n  \
    \      E lazy=ee;\n        node(){}\n        node(int l,int r,int sz2):l(l),r(r),sz2(sz2){}\n\
    \        bool is_root() {\n            return !p;\n        }\n    };\n\tvector<hash_map<int,np>>ptr;\n\
    \tnp get_node(int l,int r){\n        if(ptr[l].find(r)==ptr[l].end())ptr[l][r]=new\
    \ node(l,r,l==r);\n        return ptr[l][r];\n    }\n\tnp root(np t){\n\t\tif(!t)return\
    \ t;\n        while(t->p)t=t->p;\n        return t;\n    }\n\tbool same(np s,np\
    \ t){\n\t\treturn root(s)==root(t);\n\t}\n\tbool same(int s,int t){\n\t\treturn\
    \ root(get_node(s,s))==root(get_node(t,t));\n\t}\n\tnp reroot(np t){\n       \
    \ auto s=split(t);\n        return merge(s.second,s.first);\n    }\n\tpair<np,np>\
    \ split(np s){\n\t\tsplay(s);\n\t\tnp t=s->ch[0];\n\t\tif(t)t->p=nullptr;\n\t\t\
    s->ch[0]=nullptr;\n\t\treturn {t,update(s)};\n\t}\n\tpair<np,np> split2(np s){\n\
    \t\tsplay(s);\n\t\tnp t=s->ch[0];\n\t\tnp u=s->ch[1];\n\t\tif(t)t->p=nullptr;\n\
    \t\ts->ch[0]=nullptr;\n\t\tif(u)u->p=nullptr;\n\t\ts->ch[1]=nullptr;\n\t\treturn\
    \ {t,u};\n\t}\n\ttuple<np,np,np> split(np s,np t){\n\t\tauto u=split2(s);\n\t\t\
    if(same(u.first,t)){\n\t\t\tauto r=split2(t);\n\t\t\treturn {r.first,r.second,u.second};\n\
    \t\t}else{\n\t\t\tauto r=split2(t);\n\t\t\treturn {u.first,r.first,r.second};\n\
    \t\t}\n\t}\n\ttemplate<typename First, typename... Rest>\n\tnp merge(First s,Rest...\
    \ t){\n\t\treturn merge(s,merge(t...));\n\t}\n\tnp merge(np s,np t){\n\t\twhile(s->ch[1])s=s->ch[1];\n\
    \t\tsplay(s);\n\t\ts->ch[1]=t;\n\t\tif(t)t->p=s;\n\t\treturn update(s);\n\t}\n\
    \    int size(np t){return t?t->sz:0;}\n    int size2(np t){return t?t->sz2:0;}\n\
    \    np update(np t){\n        t->sz=size(t->ch[0])+1+size(t->ch[1]);\n      \
    \  t->sz2=size2(t->ch[0])+(t->l==t->r)+size2(t->ch[1]);\n\t\tt->sum=et;\n\t\t\
    if(t->ch[0])t->sum=fn(t->sum,t->ch[0]->sum);\n\t\tif(t->l==t->r)t->sum=fn(t->sum,t->val);\n\
    \t\tif(t->ch[1])t->sum=fn(t->sum,t->ch[1]->sum);\n\t\treturn t;\n    }\n\tvoid\
    \ push(np t){\n        if(t->lazy!=ee){\n            if(t->ch[0])propagate(t->ch[0],t->lazy);\n\
    \            if(t->ch[1])propagate(t->ch[1],t->lazy);\n            t->lazy=ee;\n\
    \        }\n    }\n    void propagate(np t,E x){\n        t->lazy=g(t->lazy,x);\n\
    \        t->val=h(t->val,x,1);\n        t->sum=h(t->sum,x,t->sz2);\n    }\n  \
    \  void set_propagate(np t,E x){\n        splay(t);\n        propagate(t,x);\n\
    \        push(t);\n    }\n    void rot(np t,bool b){\n        np x=t->p,y=x->p;\n\
    \        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;\n        t->ch[b]=x,x->p=t;\n\
    \        update(x);update(t);\n        if((t->p=y)){\n            if(y->ch[0]==x)y->ch[0]=t;\n\
    \            if(y->ch[1]==x)y->ch[1]=t;\n            update(y);\n        }\n \
    \   }\n    void splay(np t){\n        push(t);\n        while(!t->is_root()){\n\
    \            np q=t->p;\n            if(q->is_root()){\n                push(q),push(t);\n\
    \                rot(t,q->ch[0]==t);\n            }else{\n                np r=q->p;\n\
    \                push(r), push(q), push(t);\n                bool b=r->ch[0]==q;\n\
    \                if(q->ch[1-b]==t)rot(q,b),rot(t,b);\n                else rot(t,1-b),rot(t,b);\n\
    \            }\n        }\n    }\n\tvoid debug(np t){\n\t\tif(!t)return;\n\t\t\
    debug(t->ch[0]);\n\t\tcerr<<t->l<<\"-\"<<t->r<<\" \";\n\t\tdebug(t->ch[1]);\n\t\
    }\n\tconstexpr static T et=0;\n    constexpr static T ee=0;\n\tconstexpr static\
    \ T fn(T s,T t){\n\t\treturn s+t;\n\t}\n    constexpr static E g(E s,E t){\n\t\
    \treturn s+t;\n\t}\n    constexpr static T h(T s,E t,int sz){\n\t\treturn s+t*sz;\n\
    \t}\n\tpublic:\n    void reroot(int s){\n        reroot(get_node(s,s));\n    }\n\
    \tvoid update(int s,T x){\n\t\tnp t=get_node(s,s);\n\t\tsplay(t);\n\t\tt->val=fn(t->val,x);\n\
    \t\tupdate(t);\n\t}\n    void update_subtree(int p,int v,E x){\n        cut(p,v);\n\
    \t\tnp t=get_node(v,v);\n\t\tset_propagate(t,x);\n\t\tlink(p,v);\n    }\n\teuler_tour_tree(int\
    \ sz){\n\t\tptr.resize(sz);\n\t\tfor(int i=0;i<sz;i++)ptr[i][i]=new node(i,i,1);\n\
    \t}\n\tbool link(int l,int r){\n        if(same(l,r))return 0;\n        merge(reroot(get_node(l,l)),get_node(l,r),reroot(get_node(r,r)),get_node(r,l));\n\
    \        return 1;\n    }\n\tbool cut(int l,int r){\n        if(ptr[l].find(r)==ptr[l].end())return\
    \ 0;\n        np s,t,u;\n        tie(s,t,u)=split(get_node(l,r),get_node(r,l));\n\
    \        merge(s,u);\n        ptr[l].erase(r);\n        ptr[r].erase(l);\n   \
    \     return 1;\n    }\n\tT get_sum(int p,int v){\n\t\tcut(p,v);\n\t\tnp t=get_node(v,v);\n\
    \t\tsplay(t);\n\t\tT res=t->sum;\n\t\tlink(p,v);\n\t\treturn res;\n\t}\n};\n"
  code: "template<typename T,typename E>\nclass euler_tour_tree{\n\tpublic:\n    struct\
    \ node;\n    using np=node*;\n\tusing lint=long long;\n    struct node{\n    \
    \    np ch[2]={nullptr,nullptr};\n        np p=nullptr;\n        int l,r,sz=1,sz2=0;\n\
    \t\tT val=et,sum=et;\n        E lazy=ee;\n        node(){}\n        node(int l,int\
    \ r,int sz2):l(l),r(r),sz2(sz2){}\n        bool is_root() {\n            return\
    \ !p;\n        }\n    };\n\tvector<hash_map<int,np>>ptr;\n\tnp get_node(int l,int\
    \ r){\n        if(ptr[l].find(r)==ptr[l].end())ptr[l][r]=new node(l,r,l==r);\n\
    \        return ptr[l][r];\n    }\n\tnp root(np t){\n\t\tif(!t)return t;\n   \
    \     while(t->p)t=t->p;\n        return t;\n    }\n\tbool same(np s,np t){\n\t\
    \treturn root(s)==root(t);\n\t}\n\tbool same(int s,int t){\n\t\treturn root(get_node(s,s))==root(get_node(t,t));\n\
    \t}\n\tnp reroot(np t){\n        auto s=split(t);\n        return merge(s.second,s.first);\n\
    \    }\n\tpair<np,np> split(np s){\n\t\tsplay(s);\n\t\tnp t=s->ch[0];\n\t\tif(t)t->p=nullptr;\n\
    \t\ts->ch[0]=nullptr;\n\t\treturn {t,update(s)};\n\t}\n\tpair<np,np> split2(np\
    \ s){\n\t\tsplay(s);\n\t\tnp t=s->ch[0];\n\t\tnp u=s->ch[1];\n\t\tif(t)t->p=nullptr;\n\
    \t\ts->ch[0]=nullptr;\n\t\tif(u)u->p=nullptr;\n\t\ts->ch[1]=nullptr;\n\t\treturn\
    \ {t,u};\n\t}\n\ttuple<np,np,np> split(np s,np t){\n\t\tauto u=split2(s);\n\t\t\
    if(same(u.first,t)){\n\t\t\tauto r=split2(t);\n\t\t\treturn {r.first,r.second,u.second};\n\
    \t\t}else{\n\t\t\tauto r=split2(t);\n\t\t\treturn {u.first,r.first,r.second};\n\
    \t\t}\n\t}\n\ttemplate<typename First, typename... Rest>\n\tnp merge(First s,Rest...\
    \ t){\n\t\treturn merge(s,merge(t...));\n\t}\n\tnp merge(np s,np t){\n\t\twhile(s->ch[1])s=s->ch[1];\n\
    \t\tsplay(s);\n\t\ts->ch[1]=t;\n\t\tif(t)t->p=s;\n\t\treturn update(s);\n\t}\n\
    \    int size(np t){return t?t->sz:0;}\n    int size2(np t){return t?t->sz2:0;}\n\
    \    np update(np t){\n        t->sz=size(t->ch[0])+1+size(t->ch[1]);\n      \
    \  t->sz2=size2(t->ch[0])+(t->l==t->r)+size2(t->ch[1]);\n\t\tt->sum=et;\n\t\t\
    if(t->ch[0])t->sum=fn(t->sum,t->ch[0]->sum);\n\t\tif(t->l==t->r)t->sum=fn(t->sum,t->val);\n\
    \t\tif(t->ch[1])t->sum=fn(t->sum,t->ch[1]->sum);\n\t\treturn t;\n    }\n\tvoid\
    \ push(np t){\n        if(t->lazy!=ee){\n            if(t->ch[0])propagate(t->ch[0],t->lazy);\n\
    \            if(t->ch[1])propagate(t->ch[1],t->lazy);\n            t->lazy=ee;\n\
    \        }\n    }\n    void propagate(np t,E x){\n        t->lazy=g(t->lazy,x);\n\
    \        t->val=h(t->val,x,1);\n        t->sum=h(t->sum,x,t->sz2);\n    }\n  \
    \  void set_propagate(np t,E x){\n        splay(t);\n        propagate(t,x);\n\
    \        push(t);\n    }\n    void rot(np t,bool b){\n        np x=t->p,y=x->p;\n\
    \        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;\n        t->ch[b]=x,x->p=t;\n\
    \        update(x);update(t);\n        if((t->p=y)){\n            if(y->ch[0]==x)y->ch[0]=t;\n\
    \            if(y->ch[1]==x)y->ch[1]=t;\n            update(y);\n        }\n \
    \   }\n    void splay(np t){\n        push(t);\n        while(!t->is_root()){\n\
    \            np q=t->p;\n            if(q->is_root()){\n                push(q),push(t);\n\
    \                rot(t,q->ch[0]==t);\n            }else{\n                np r=q->p;\n\
    \                push(r), push(q), push(t);\n                bool b=r->ch[0]==q;\n\
    \                if(q->ch[1-b]==t)rot(q,b),rot(t,b);\n                else rot(t,1-b),rot(t,b);\n\
    \            }\n        }\n    }\n\tvoid debug(np t){\n\t\tif(!t)return;\n\t\t\
    debug(t->ch[0]);\n\t\tcerr<<t->l<<\"-\"<<t->r<<\" \";\n\t\tdebug(t->ch[1]);\n\t\
    }\n\tconstexpr static T et=0;\n    constexpr static T ee=0;\n\tconstexpr static\
    \ T fn(T s,T t){\n\t\treturn s+t;\n\t}\n    constexpr static E g(E s,E t){\n\t\
    \treturn s+t;\n\t}\n    constexpr static T h(T s,E t,int sz){\n\t\treturn s+t*sz;\n\
    \t}\n\tpublic:\n    void reroot(int s){\n        reroot(get_node(s,s));\n    }\n\
    \tvoid update(int s,T x){\n\t\tnp t=get_node(s,s);\n\t\tsplay(t);\n\t\tt->val=fn(t->val,x);\n\
    \t\tupdate(t);\n\t}\n    void update_subtree(int p,int v,E x){\n        cut(p,v);\n\
    \t\tnp t=get_node(v,v);\n\t\tset_propagate(t,x);\n\t\tlink(p,v);\n    }\n\teuler_tour_tree(int\
    \ sz){\n\t\tptr.resize(sz);\n\t\tfor(int i=0;i<sz;i++)ptr[i][i]=new node(i,i,1);\n\
    \t}\n\tbool link(int l,int r){\n        if(same(l,r))return 0;\n        merge(reroot(get_node(l,l)),get_node(l,r),reroot(get_node(r,r)),get_node(r,l));\n\
    \        return 1;\n    }\n\tbool cut(int l,int r){\n        if(ptr[l].find(r)==ptr[l].end())return\
    \ 0;\n        np s,t,u;\n        tie(s,t,u)=split(get_node(l,r),get_node(r,l));\n\
    \        merge(s,u);\n        ptr[l].erase(r);\n        ptr[r].erase(l);\n   \
    \     return 1;\n    }\n\tT get_sum(int p,int v){\n\t\tcut(p,v);\n\t\tnp t=get_node(v,v);\n\
    \t\tsplay(t);\n\t\tT res=t->sum;\n\t\tlink(p,v);\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/euler_tour_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/euler_tour_tree.hpp
layout: document
redirect_from:
- /library/data_structure/euler_tour_tree.hpp
- /library/data_structure/euler_tour_tree.hpp.html
title: data_structure/euler_tour_tree.hpp
---
