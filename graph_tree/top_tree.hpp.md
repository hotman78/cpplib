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
  bundledCode: "#line 1 \"graph_tree/top_tree.hpp\"\n/**\n * TopTree(WIP)\n */\n\n\
    template<typename T,typename E>\nclass top_tree{\n\tstruct node;\n\tusing np=node*;\n\
    \tstruct cluster{\n\t\tbool is_compress,is_edge,guarded;\n\t\tint l,r;\n\t\tT\
    \ key=et;\n\t\tnp ch[3]={nullptr,nullptr,nullptr};\n\t\tnp p=nullptr;\n\t\tcluster(){}\n\
    \t\tcluster(int l,int r,bool is_compress,bool is_edge):l(l),r(r),is_compress(is_compress),is_edge(is_edge){}\n\
    \        bool is_root(){\n            return !p||p->guarded||(p->ch[0]!=this&&p->ch[1]!=this);\n\
    \        }\n\t};\n\tnp root=nullptr;\n\tvoid join(np p,np t,int i){\n\t\tif(t)t->p=p;\n\
    \t\tif(p)p->ch[i]=t,update(p);\n\t}\n\t//\u5DE6\u53F3\u306E\u5B50\u3092\u5165\u308C\
    \u66FF\u3048\u308B\n\tvoid swap(np t){\n\t\tswap(t->l,t->r);\n\t\tswap(t->ch[0],t->ch[1]);\n\
    \t\ttoggle(t->ch[0]);toggle(t->ch[1]);\n\t}\n    void update(np t){\n\n    }\n\
    \    void rot(np t,bool b){\n        np x=t->p,y=x->p;\n        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;\n\
    \        t->ch[b]=x,x->p=t;\n        update(x);update(t);\n        if((t->p=y)){\n\
    \            if(y->ch[0]==x)y->ch[0]=t;\n            if(y->ch[1]==x)y->ch[1]=t;\n\
    \            update(y);\n        }\n    }\n    void splay(np t){\n        push(t);\n\
    \        while(!t->is_root()){\n            np q=t->p;\n            if(q->is_root()){\n\
    \                push(q),push(t);\n                rot(t,q->ch[0]==t);\n     \
    \       }else{\n                np r=q->p;\n                push(r),push(q),push(t);\n\
    \                bool b=r->ch[0]==q;\n                if(q->ch[1-b]==t)rot(q,b),rot(t,b);\n\
    \                else rot(t,1-b),rot(t,b);\n            }\n        }\n    }\n\t\
    void push(np t){\n\t\t\n    }\n\tvoid toggle(np t){\n\n\t}\n\tvoid splice(np s,np\
    \ t,bool b){\n\t\tif(!b){\n\t\t\tjoin(s->p,t,(s->p->ch[1]==s)+2*(s->p->ch[2]==s));\n\
    \t\t\tjoin(t->p,s,(t->p->ch[1]==t)+2*(t->p->ch[2]==t));\n\t\t}else{\n\t\t\ttoggle(s);toggle(t);\n\
    \t\t\tjoin(s->p,t,(s->p->ch[1]==s)+2*(s->p->ch[2]==s));\n\t\t\tjoin(t->p,s,(t->p->ch[1]==t)+2*(t->p->ch[2]==t));\n\
    \t\t}\n\t}\n\tvoid expose(np t){\n\t\twhile(1){\n\t\t\tsplay(t);\n\t\t\tif(!t->p)return;\n\
    \t\t\tnp n;\n\t\t\tif(t->p->is_compress){\n\t\t\t\tn=t->p;\n\t\t\t}else{\n\t\t\
    \t\tnp s=t->p;\n\t\t\t\tsplay(s);\n\t\t\t\tn=s->p;\n\t\t\t}\n\t\t\tbool b=n->p&&n->p->guarded;\n\
    \t\t\tsplice(t,n->ch[b],b);\n\t\t\tif(t->is_edge)t=n;\n\t\t}\n\t}\n\tvoid soft_expose(np\
    \ s,np t){\n\t\texpose(s);\n\t\tif(s!=t){\n\t\t\tguard(s,1);\n\t\t\texpose(t);\n\
    \t\t\tguard(s,0);\n\t\t}\n\t\tif(s->ch[0]=t){\n\t\t\tswap(s);\n\t\t}\n\t}\n\t\
    np handle(int s){\n\n\t}\n\tvoid link(int s,int t){\n\t\tnp v=handle(s),w=handle(t);\n\
    \t\tif(w){\n\t\t\texpose(w);\n\t\t\tif(v->l!=t&&v->r!=t){\n\t\t\t\tnp rp=new node(-1,-1,0,0);\n\
    \t\t\t\tnp q=new node(s,t,0,1);\n\t\t\t\tjoin(rp,v->ch[2],0);\n\t\t\t\tjoin(rp,v->ch[0],1);\n\
    \t\t\t\tjoin(v,q,0);\n\t\t\t\tjoin(v,rp,2);\n\t\t\t}else{\n\t\t\t\tif(v->r==t)swap(v);\n\
    \t\t\t\tnp p=new node(s,v->r,1,0);\n\t\t\t\tnp q=new node(s,t,0,1);\n\t\t\t\t\
    join(p,q,0);\n\t\t\t\tjoin(p,v,1);\n\t\t\t\tv=p;\n\t\t\t}\n\t\t}else{\n\t\t\t\
    v=new node(s,t,0,1);\n\t\t}\n\t\t\n\t}\n\tvoid cut(){\n\n\t}\n};\n"
  code: "/**\n * TopTree(WIP)\n */\n\ntemplate<typename T,typename E>\nclass top_tree{\n\
    \tstruct node;\n\tusing np=node*;\n\tstruct cluster{\n\t\tbool is_compress,is_edge,guarded;\n\
    \t\tint l,r;\n\t\tT key=et;\n\t\tnp ch[3]={nullptr,nullptr,nullptr};\n\t\tnp p=nullptr;\n\
    \t\tcluster(){}\n\t\tcluster(int l,int r,bool is_compress,bool is_edge):l(l),r(r),is_compress(is_compress),is_edge(is_edge){}\n\
    \        bool is_root(){\n            return !p||p->guarded||(p->ch[0]!=this&&p->ch[1]!=this);\n\
    \        }\n\t};\n\tnp root=nullptr;\n\tvoid join(np p,np t,int i){\n\t\tif(t)t->p=p;\n\
    \t\tif(p)p->ch[i]=t,update(p);\n\t}\n\t//\u5DE6\u53F3\u306E\u5B50\u3092\u5165\u308C\
    \u66FF\u3048\u308B\n\tvoid swap(np t){\n\t\tswap(t->l,t->r);\n\t\tswap(t->ch[0],t->ch[1]);\n\
    \t\ttoggle(t->ch[0]);toggle(t->ch[1]);\n\t}\n    void update(np t){\n\n    }\n\
    \    void rot(np t,bool b){\n        np x=t->p,y=x->p;\n        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;\n\
    \        t->ch[b]=x,x->p=t;\n        update(x);update(t);\n        if((t->p=y)){\n\
    \            if(y->ch[0]==x)y->ch[0]=t;\n            if(y->ch[1]==x)y->ch[1]=t;\n\
    \            update(y);\n        }\n    }\n    void splay(np t){\n        push(t);\n\
    \        while(!t->is_root()){\n            np q=t->p;\n            if(q->is_root()){\n\
    \                push(q),push(t);\n                rot(t,q->ch[0]==t);\n     \
    \       }else{\n                np r=q->p;\n                push(r),push(q),push(t);\n\
    \                bool b=r->ch[0]==q;\n                if(q->ch[1-b]==t)rot(q,b),rot(t,b);\n\
    \                else rot(t,1-b),rot(t,b);\n            }\n        }\n    }\n\t\
    void push(np t){\n\t\t\n    }\n\tvoid toggle(np t){\n\n\t}\n\tvoid splice(np s,np\
    \ t,bool b){\n\t\tif(!b){\n\t\t\tjoin(s->p,t,(s->p->ch[1]==s)+2*(s->p->ch[2]==s));\n\
    \t\t\tjoin(t->p,s,(t->p->ch[1]==t)+2*(t->p->ch[2]==t));\n\t\t}else{\n\t\t\ttoggle(s);toggle(t);\n\
    \t\t\tjoin(s->p,t,(s->p->ch[1]==s)+2*(s->p->ch[2]==s));\n\t\t\tjoin(t->p,s,(t->p->ch[1]==t)+2*(t->p->ch[2]==t));\n\
    \t\t}\n\t}\n\tvoid expose(np t){\n\t\twhile(1){\n\t\t\tsplay(t);\n\t\t\tif(!t->p)return;\n\
    \t\t\tnp n;\n\t\t\tif(t->p->is_compress){\n\t\t\t\tn=t->p;\n\t\t\t}else{\n\t\t\
    \t\tnp s=t->p;\n\t\t\t\tsplay(s);\n\t\t\t\tn=s->p;\n\t\t\t}\n\t\t\tbool b=n->p&&n->p->guarded;\n\
    \t\t\tsplice(t,n->ch[b],b);\n\t\t\tif(t->is_edge)t=n;\n\t\t}\n\t}\n\tvoid soft_expose(np\
    \ s,np t){\n\t\texpose(s);\n\t\tif(s!=t){\n\t\t\tguard(s,1);\n\t\t\texpose(t);\n\
    \t\t\tguard(s,0);\n\t\t}\n\t\tif(s->ch[0]=t){\n\t\t\tswap(s);\n\t\t}\n\t}\n\t\
    np handle(int s){\n\n\t}\n\tvoid link(int s,int t){\n\t\tnp v=handle(s),w=handle(t);\n\
    \t\tif(w){\n\t\t\texpose(w);\n\t\t\tif(v->l!=t&&v->r!=t){\n\t\t\t\tnp rp=new node(-1,-1,0,0);\n\
    \t\t\t\tnp q=new node(s,t,0,1);\n\t\t\t\tjoin(rp,v->ch[2],0);\n\t\t\t\tjoin(rp,v->ch[0],1);\n\
    \t\t\t\tjoin(v,q,0);\n\t\t\t\tjoin(v,rp,2);\n\t\t\t}else{\n\t\t\t\tif(v->r==t)swap(v);\n\
    \t\t\t\tnp p=new node(s,v->r,1,0);\n\t\t\t\tnp q=new node(s,t,0,1);\n\t\t\t\t\
    join(p,q,0);\n\t\t\t\tjoin(p,v,1);\n\t\t\t\tv=p;\n\t\t\t}\n\t\t}else{\n\t\t\t\
    v=new node(s,t,0,1);\n\t\t}\n\t\t\n\t}\n\tvoid cut(){\n\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/top_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/top_tree.hpp
layout: document
redirect_from:
- /library/graph_tree/top_tree.hpp
- /library/graph_tree/top_tree.hpp.html
title: graph_tree/top_tree.hpp
---
