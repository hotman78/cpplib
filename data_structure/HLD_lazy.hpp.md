---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/HLD_lazy.hpp\"\ntemplate<typename T,typename\
    \ E>\nclass HLD_lazy{\n\tclass lazy_segment_tree{\n\t\tint n=1,sz;\n\t\tT* node;\n\
    \t\tE* lazy;\n\t\tint ids[64];\n\t\tint idx;\n\t\tvoid eval(const auto& t){\n\t\
    \t\tif(lazy[t]==ee)return;\n\t\t\tnode[t]=h(node[t],lazy[t],n>>(int)(log2(t+1)));\n\
    \t\t\tif(t<n-1){\n\t\t\t\tlazy[(t<<1)+1]=g(lazy[(t<<1)+1],lazy[t]);\n\t\t\t\t\
    lazy[(t<<1)+2]=g(lazy[(t<<1)+2],lazy[t]);\n\t\t\t}\n\t\t\tlazy[t]=ee;\n\t\t}\n\
    \t\tvoid get_eval(auto l,auto r){\n\t\t\tl+=n;r+=n;\n\t\t\tconst int lm=(l/(l&-l))>>1;\n\
    \t\t\tconst int rm=(r/(r&-r))>>1;\n\t\t\tidx=0;\n\t\t\twhile(r>l){\n\t\t\t\tif(r<=rm&&r)ids[idx++]=r-1;\n\
    \t\t\t\tif(l<=lm&&l)ids[idx++]=l-1;\n\t\t\t\tl>>=1;r>>=1;\n\t\t\t}\n\t\t\twhile(l){\n\
    \t\t\t\tids[idx++]=l-1;\n\t\t\t\tl>>=1;\n\t\t\t}\n\t\t}\n\t\tpublic:\n\t\tlazy_segment_tree(const\
    \ vector<T>& v):sz(v.size()){\n\t\t\twhile(n<(int)v.size())n<<=1;\n\t\t\tnode=new\
    \ T[(n<<1)-1];\n\t\t\tlazy=new E[(n<<1)-1];\n\t\t\tfor(int i=(int)v.size()+n-1;i<(n<<1)-1;i++)node[i]=et;\n\
    \t\t\tfor(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;\n\t\t\tfor(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];\n\
    \t\t\tfor(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);\n\t\t}\n\
    \t\tlazy_segment_tree(const auto& sz):sz(sz){\n\t\t\twhile(n<(int)sz)n<<=1;\n\t\
    \t\tnode=new T[(n<<1)-1];\n\t\t\tlazy=new E[(n<<1)-1];\n\t\t\tfor(int i=0;i<(n<<1)-1;i++)node[i]=et;\n\
    \t\t\tfor(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;\n\t\t}\n\t\tvoid update(auto l,auto\
    \ r,E val){\n\t\t\tif(l>r)swap(l,r);\n\t\t\tr++;\n\t\t\tget_eval(l,r);\n\t\t\t\
    for(int i=idx-1;i>=0;i--)eval(ids[i]);\n\t\t\tl+=n;r+=n;\n\t\t\twhile(l<r){\n\t\
    \t\t\tif(l&1){lazy[l-1]=g(lazy[l-1],val);eval(l-1);++l;}\n\t\t\t\tif(r&1){--r;lazy[r-1]=g(lazy[r-1],val);eval(r-1);}\n\
    \t\t\t\tl>>=1;r>>=1;\n\t\t\t}\n\t\t\tfor(int i=0;i<idx;i++){\n\t\t\t\teval((ids[i]<<1)+1);\n\
    \t\t\t\teval((ids[i]<<1)+2);\n\t\t\t\tnode[ids[i]]=f(node[(ids[i]<<1)+1],node[(ids[i]<<1)+2]);\n\
    \t\t\t}\n\t\t}\n\t\tT get(auto l,auto r){\n\t\t\tif(l>r)swap(l,r);\n\t\t\tr++;\n\
    \t\t\tget_eval(l,r);\n\t\t\tfor(int i=idx-1;i>=0;i--)eval(ids[i]);\n\t\t\tl+=n;r+=n;\n\
    \t\t\tT res=et;\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1){eval(l-1);res=f(res,node[l-1]);l++;}\n\
    \t\t\t\tif(r&1){--r;eval(r-1);res=f(res,node[r-1]);}\n\t\t\t\tl>>=1;r>>=1;\n\t\
    \t\t}\n\t\t\treturn res;\n\t\t}\n\t};\n\tint child_size(const auto& v,int n,int\
    \ p){\n\t\tint cnt=0;\n\t\tfor(auto t:v[n]){\n\t\t\tif(t!=p)cnt+=child_size(v,t,n);\n\
    \t\t}\n\t\treturn sz[n]=cnt+1;\n\t}\n\tvoid make(const auto& v,int root){\n\t\t\
    sz=new int[v.size()];\n\t\tvertex=new int[v.size()];\n\t\tpar=new int[v.size()];\n\
    \t\thead=new int[v.size()];\n\t\tchild_size(v,root,-1);\n\t\tstack<tuple<int,int>>stk;\n\
    \t\tstk.emplace(root,-1);\n\t\tint idx=0;\n\t\tpar[root]=root;\n\t\thead[root]=root;\n\
    \t\twhile(!stk.empty()){\n\t\t\tint n,p;\n\t\t\ttie(n,p)=stk.top();\n\t\t\tstk.pop();\n\
    \t\t\tvertex[n]=idx++;\n\t\t\tint mx=0,heavy=-1;\n\t\t\tfor(auto t:v[n])if(t!=p&&mx<sz[t]){\n\
    \t\t\t\tmx=sz[t];\n\t\t\t\theavy=t;\n\t\t\t}\n\t\t\tfor(auto t:v[n]){\n\t\t\t\t\
    if(t!=heavy&&t!=p){\n\t\t\t\t\tpar[t]=n;\n\t\t\t\t\thead[t]=t;\n\t\t\t\t\tstk.emplace(t,n);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif(heavy!=-1){\n\t\t\t\tpar[heavy]=par[n];\n\t\t\t\t\
    head[heavy]=head[n];\n\t\t\t\tstk.emplace(heavy,n);\n\t\t\t}\n\t\t}\n\t}\n\tint*\
    \ sz;\n\tint* vertex;\n\tint* par;\n\tint* head;\n\tlazy_segment_tree* seg;\n\t\
    public:\n\tHLD_lazy(const auto& v,int root=0){\n\t\tmake(v,root);\n\t\tseg=new\
    \ lazy_segment_tree(v.size());\n\t}\n\tHLD_lazy(const auto& v,const auto& a,int\
    \ root=0){\n\t\tvector<T>tmp(v.size());\n\t\tmake(v,root);\n\t\tfor(int i=0;i<(int)v.size();i++){\n\
    \t\t\ttmp[vertex[i]]=a[i];\n\t\t}\n\t\tseg=new lazy_segment_tree(tmp);\n\t}\n\t\
    int lca(auto l,auto r){\n\t\twhile(1){\n\t\t\tif(head[l]==head[r])return sz[l]>sz[r]?l:r;\n\
    \t\t\telse if(sz[head[l]]>sz[head[r]])r=par[r];\n\t\t\telse l=par[l];\n\t\t}\n\
    \t}\n\tinline void update_vertex(auto u,E x){\n\t\tseg->update(vertex[u],vertex[u],x);\n\
    \t}\n\tinline T get_vertex(auto u){\n\t\treturn seg->get(vertex[u],vertex[u]);\n\
    \t}\n\tinline void update_subtree(auto u,E x){\n\t\tseg->update(vertex[u],vertex[u]+sz[u]-1);\n\
    \t}\n\tinline T get_subtree(auto u){\n\t\treturn seg->get(vertex[u],vertex[u]+sz[u]-1);\n\
    \t}\n\tvoid update_path(auto u,auto v,E x){\n\t\twhile(1){\n\t\t\tif(head[u]==head[v]){\n\
    \t\t\t\tseg->update(vertex[u],vertex[v],x);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\telse\
    \ if(sz[head[u]]>sz[head[v]]){\n\t\t\t\tseg->update(vertex[v],vertex[head[v]],x);\n\
    \t\t\t\tv=par[v];\n\t\t\t}\n\t\t\telse{\n\t\t\t\tseg->update(vertex[u],vertex[head[u]],x);\n\
    \t\t\t\tu=par[u];\n\t\t\t}\n\t\t}\n\t}\n\tT get_path(auto u,auto v){\n\t\tT res=et;\n\
    \t\twhile(1){\n\t\t\tif(head[u]==head[v]){\n\t\t\t\treturn f(res,seg->get(vertex[u],vertex[v]));\n\
    \t\t\t}\n\t\t\telse if(sz[head[u]]>sz[head[v]]){\n\t\t\t\tres=f(res,seg->get(vertex[v],vertex[head[v]]));\n\
    \t\t\t\tv=par[v];\n\t\t\t}\n\t\t\telse{\n\t\t\t\tres=f(res,seg->get(vertex[u],vertex[head[u]]));\n\
    \t\t\t\tu=par[u];\n\t\t\t}\n\t\t}\n\t}\n\tprotected:\n\tconstexpr static T et=0;\n\
    \tconstexpr static E ee=0;\n\tconstexpr static\n\tT f(const T& a,const T& b){\n\
    \t\treturn a+b;\n\t}\n\tconstexpr static\n\tT h(const T& a,const E& b,const auto&\
    \ sz){\n\t\treturn a+b*sz;\n\t}\n\tconstexpr static\n\tE g(const E& a,const E&\
    \ b){\n\t\treturn a+b;\n\t}\n\tconstexpr static\n\tauto update(auto a,auto b){return\
    \ b==ee?a:b;}\n};\n"
  code: "template<typename T,typename E>\nclass HLD_lazy{\n\tclass lazy_segment_tree{\n\
    \t\tint n=1,sz;\n\t\tT* node;\n\t\tE* lazy;\n\t\tint ids[64];\n\t\tint idx;\n\t\
    \tvoid eval(const auto& t){\n\t\t\tif(lazy[t]==ee)return;\n\t\t\tnode[t]=h(node[t],lazy[t],n>>(int)(log2(t+1)));\n\
    \t\t\tif(t<n-1){\n\t\t\t\tlazy[(t<<1)+1]=g(lazy[(t<<1)+1],lazy[t]);\n\t\t\t\t\
    lazy[(t<<1)+2]=g(lazy[(t<<1)+2],lazy[t]);\n\t\t\t}\n\t\t\tlazy[t]=ee;\n\t\t}\n\
    \t\tvoid get_eval(auto l,auto r){\n\t\t\tl+=n;r+=n;\n\t\t\tconst int lm=(l/(l&-l))>>1;\n\
    \t\t\tconst int rm=(r/(r&-r))>>1;\n\t\t\tidx=0;\n\t\t\twhile(r>l){\n\t\t\t\tif(r<=rm&&r)ids[idx++]=r-1;\n\
    \t\t\t\tif(l<=lm&&l)ids[idx++]=l-1;\n\t\t\t\tl>>=1;r>>=1;\n\t\t\t}\n\t\t\twhile(l){\n\
    \t\t\t\tids[idx++]=l-1;\n\t\t\t\tl>>=1;\n\t\t\t}\n\t\t}\n\t\tpublic:\n\t\tlazy_segment_tree(const\
    \ vector<T>& v):sz(v.size()){\n\t\t\twhile(n<(int)v.size())n<<=1;\n\t\t\tnode=new\
    \ T[(n<<1)-1];\n\t\t\tlazy=new E[(n<<1)-1];\n\t\t\tfor(int i=(int)v.size()+n-1;i<(n<<1)-1;i++)node[i]=et;\n\
    \t\t\tfor(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;\n\t\t\tfor(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];\n\
    \t\t\tfor(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);\n\t\t}\n\
    \t\tlazy_segment_tree(const auto& sz):sz(sz){\n\t\t\twhile(n<(int)sz)n<<=1;\n\t\
    \t\tnode=new T[(n<<1)-1];\n\t\t\tlazy=new E[(n<<1)-1];\n\t\t\tfor(int i=0;i<(n<<1)-1;i++)node[i]=et;\n\
    \t\t\tfor(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;\n\t\t}\n\t\tvoid update(auto l,auto\
    \ r,E val){\n\t\t\tif(l>r)swap(l,r);\n\t\t\tr++;\n\t\t\tget_eval(l,r);\n\t\t\t\
    for(int i=idx-1;i>=0;i--)eval(ids[i]);\n\t\t\tl+=n;r+=n;\n\t\t\twhile(l<r){\n\t\
    \t\t\tif(l&1){lazy[l-1]=g(lazy[l-1],val);eval(l-1);++l;}\n\t\t\t\tif(r&1){--r;lazy[r-1]=g(lazy[r-1],val);eval(r-1);}\n\
    \t\t\t\tl>>=1;r>>=1;\n\t\t\t}\n\t\t\tfor(int i=0;i<idx;i++){\n\t\t\t\teval((ids[i]<<1)+1);\n\
    \t\t\t\teval((ids[i]<<1)+2);\n\t\t\t\tnode[ids[i]]=f(node[(ids[i]<<1)+1],node[(ids[i]<<1)+2]);\n\
    \t\t\t}\n\t\t}\n\t\tT get(auto l,auto r){\n\t\t\tif(l>r)swap(l,r);\n\t\t\tr++;\n\
    \t\t\tget_eval(l,r);\n\t\t\tfor(int i=idx-1;i>=0;i--)eval(ids[i]);\n\t\t\tl+=n;r+=n;\n\
    \t\t\tT res=et;\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1){eval(l-1);res=f(res,node[l-1]);l++;}\n\
    \t\t\t\tif(r&1){--r;eval(r-1);res=f(res,node[r-1]);}\n\t\t\t\tl>>=1;r>>=1;\n\t\
    \t\t}\n\t\t\treturn res;\n\t\t}\n\t};\n\tint child_size(const auto& v,int n,int\
    \ p){\n\t\tint cnt=0;\n\t\tfor(auto t:v[n]){\n\t\t\tif(t!=p)cnt+=child_size(v,t,n);\n\
    \t\t}\n\t\treturn sz[n]=cnt+1;\n\t}\n\tvoid make(const auto& v,int root){\n\t\t\
    sz=new int[v.size()];\n\t\tvertex=new int[v.size()];\n\t\tpar=new int[v.size()];\n\
    \t\thead=new int[v.size()];\n\t\tchild_size(v,root,-1);\n\t\tstack<tuple<int,int>>stk;\n\
    \t\tstk.emplace(root,-1);\n\t\tint idx=0;\n\t\tpar[root]=root;\n\t\thead[root]=root;\n\
    \t\twhile(!stk.empty()){\n\t\t\tint n,p;\n\t\t\ttie(n,p)=stk.top();\n\t\t\tstk.pop();\n\
    \t\t\tvertex[n]=idx++;\n\t\t\tint mx=0,heavy=-1;\n\t\t\tfor(auto t:v[n])if(t!=p&&mx<sz[t]){\n\
    \t\t\t\tmx=sz[t];\n\t\t\t\theavy=t;\n\t\t\t}\n\t\t\tfor(auto t:v[n]){\n\t\t\t\t\
    if(t!=heavy&&t!=p){\n\t\t\t\t\tpar[t]=n;\n\t\t\t\t\thead[t]=t;\n\t\t\t\t\tstk.emplace(t,n);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif(heavy!=-1){\n\t\t\t\tpar[heavy]=par[n];\n\t\t\t\t\
    head[heavy]=head[n];\n\t\t\t\tstk.emplace(heavy,n);\n\t\t\t}\n\t\t}\n\t}\n\tint*\
    \ sz;\n\tint* vertex;\n\tint* par;\n\tint* head;\n\tlazy_segment_tree* seg;\n\t\
    public:\n\tHLD_lazy(const auto& v,int root=0){\n\t\tmake(v,root);\n\t\tseg=new\
    \ lazy_segment_tree(v.size());\n\t}\n\tHLD_lazy(const auto& v,const auto& a,int\
    \ root=0){\n\t\tvector<T>tmp(v.size());\n\t\tmake(v,root);\n\t\tfor(int i=0;i<(int)v.size();i++){\n\
    \t\t\ttmp[vertex[i]]=a[i];\n\t\t}\n\t\tseg=new lazy_segment_tree(tmp);\n\t}\n\t\
    int lca(auto l,auto r){\n\t\twhile(1){\n\t\t\tif(head[l]==head[r])return sz[l]>sz[r]?l:r;\n\
    \t\t\telse if(sz[head[l]]>sz[head[r]])r=par[r];\n\t\t\telse l=par[l];\n\t\t}\n\
    \t}\n\tinline void update_vertex(auto u,E x){\n\t\tseg->update(vertex[u],vertex[u],x);\n\
    \t}\n\tinline T get_vertex(auto u){\n\t\treturn seg->get(vertex[u],vertex[u]);\n\
    \t}\n\tinline void update_subtree(auto u,E x){\n\t\tseg->update(vertex[u],vertex[u]+sz[u]-1);\n\
    \t}\n\tinline T get_subtree(auto u){\n\t\treturn seg->get(vertex[u],vertex[u]+sz[u]-1);\n\
    \t}\n\tvoid update_path(auto u,auto v,E x){\n\t\twhile(1){\n\t\t\tif(head[u]==head[v]){\n\
    \t\t\t\tseg->update(vertex[u],vertex[v],x);\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\telse\
    \ if(sz[head[u]]>sz[head[v]]){\n\t\t\t\tseg->update(vertex[v],vertex[head[v]],x);\n\
    \t\t\t\tv=par[v];\n\t\t\t}\n\t\t\telse{\n\t\t\t\tseg->update(vertex[u],vertex[head[u]],x);\n\
    \t\t\t\tu=par[u];\n\t\t\t}\n\t\t}\n\t}\n\tT get_path(auto u,auto v){\n\t\tT res=et;\n\
    \t\twhile(1){\n\t\t\tif(head[u]==head[v]){\n\t\t\t\treturn f(res,seg->get(vertex[u],vertex[v]));\n\
    \t\t\t}\n\t\t\telse if(sz[head[u]]>sz[head[v]]){\n\t\t\t\tres=f(res,seg->get(vertex[v],vertex[head[v]]));\n\
    \t\t\t\tv=par[v];\n\t\t\t}\n\t\t\telse{\n\t\t\t\tres=f(res,seg->get(vertex[u],vertex[head[u]]));\n\
    \t\t\t\tu=par[u];\n\t\t\t}\n\t\t}\n\t}\n\tprotected:\n\tconstexpr static T et=0;\n\
    \tconstexpr static E ee=0;\n\tconstexpr static\n\tT f(const T& a,const T& b){\n\
    \t\treturn a+b;\n\t}\n\tconstexpr static\n\tT h(const T& a,const E& b,const auto&\
    \ sz){\n\t\treturn a+b*sz;\n\t}\n\tconstexpr static\n\tE g(const E& a,const E&\
    \ b){\n\t\treturn a+b;\n\t}\n\tconstexpr static\n\tauto update(auto a,auto b){return\
    \ b==ee?a:b;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/HLD_lazy.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/HLD_lazy.hpp
layout: document
redirect_from:
- /library/data_structure/HLD_lazy.hpp
- /library/data_structure/HLD_lazy.hpp.html
title: data_structure/HLD_lazy.hpp
---
