---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/HLD_seg.hpp\"\ntemplate<typename T>\nclass\
    \ HLD_seg{\n\tclass segment{\n\t\tT* node;\n\t\tint n=1;\n\t\tpublic:\n\t\tsegment(int\
    \ sz){\n\t\t\twhile(n<sz)n<<=1;\n\t\t\tnode=new T[(n<<1)-1];\n\t\t\tfor(int i=0;i<(n<<1)-1;i++)node[i]=e;\n\
    \t\t}\n\t\tsegment(const vector<T>& v){\n\t\t\twhile(n<(int)v.size())n<<=1;\n\t\
    \t\tnode=new T[(n<<1)-1];\n\t\t\tfor(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];\n\
    \        \tfor(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);\n\t\
    \t}\n\t\tT get(auto l,auto r){\n\t\t\tif(l>r)swap(l,r);\n\t\t\tl+=n;r+=n+1;\n\t\
    \t\tT s=e;\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1)s=f(s,node[l++-1]);\n\t\t\t\tif(r&1)s=f(s,node[--r-1]);\n\
    \t\t\t\tl>>=1;r>>=1;\n\t\t\t}\n\t\t\treturn s;\n\t\t}\n\t\tvoid update(auto t,T\
    \ val){\n\t\t\tt+=n-1;\n\t\t\twhile(1){\n\t\t\t\tnode[t]=f(node[t],val);\n\t\t\
    \t\tt=(t-1)>>1;\n\t\t\t\tif(!t)break;\n\t\t\t}\n\t\t}\n\t};\n\tint child_size(const\
    \ auto& v,int n,int p){\n\t\tint cnt=0;\n\t\tfor(auto t:v[n]){\n\t\t\tif(t!=p)cnt+=child_size(v,t,n);\n\
    \t\t}\n\t\treturn sz[n]=cnt+1;\n\t}\n\tvoid make_hld(const auto&v,int n,int p){\n\
    \t\tstatic int idx=0;\n\t\tvertex[n]=idx++;\n\t\tint mx=0,heavy=-1;\n\t\tfor(auto\
    \ t:v[n])if(t!=p&&mx<sz[t]){\n\t\t\tmx=sz[t];\n\t\t\theavy=t;\n\t\t}\n\t\tif(heavy!=-1){\n\
    \t\t\tpar[heavy]=par[n];\n\t\t\thead[heavy]=head[n];\n\t\t\tmake_hld(v,heavy,n);\n\
    \t\t}\n\t\tfor(auto t:v[n]){\n\t\t\tif(t!=heavy&&t!=p){\n\t\t\t\tpar[t]=n;\n\t\
    \t\t\thead[t]=t;\n\t\t\t\tmake_hld(v,t,n);\n\t\t\t}\n\t\t}\n\t}\n\tint* sz;\n\t\
    int* vertex;\n\tint* par;\n\tint* head;\n\tsegment* seg;\n\tpublic:\n\tHLD_seg(const\
    \ auto& v,int root=0){\n\t\tmake(v,root);\n\t\tseg=new segment(v.size());\n\t\
    }\n\tHLD_seg(const auto& v,const auto& a,int root=0){\n\t\tmake(v,root);\n\t\t\
    vector<T>tmp(v.size());\n\t\tfor(int i=0;i<(int)v.size();i++){\n\t\t\ttmp[vertex[i]]=a[i];\n\
    \t\t}\n\t\tseg=new segment(tmp);\n\t}\n\tvoid make(const auto& v,int root){\n\t\
    \tsz=new int[v.size()];\n\t\tvertex=new int[v.size()];\n\t\tpar=new int[v.size()];\n\
    \t\thead=new int[v.size()];\n\t\tchild_size(v,root,-1);\n\t\tpar[root]=root;\n\
    \t\thead[root]=root;\n\t\tmake_hld(v,root,-1);\n\t}\n\tint lca(auto l,auto r){\n\
    \t\twhile(head[l]!=head[r]){\n\t\t\tif(sz[head[l]]>sz[head[r]])r=par[r];\n\t\t\
    \telse l=par[l];\n\t\t}\n\t\treturn sz[l]>sz[r]?l:r;\n\t}\n\tinline void update(auto\
    \ t,T x){\n\t\tseg->update(vertex[t],x);\n\t}\n\tT get(auto u,auto v){\n\t\tT\
    \ res=e;\n\t\twhile(head[u]!=head[v]){\n\t\t\tif(sz[head[u]]>sz[head[v]]){\n\t\
    \t\t\tres=f(res,seg->get(vertex[v],vertex[head[v]]));\n\t\t\t\tv=par[v];\n\t\t\
    \t}\n\t\t\telse{\n\t\t\t\tres=f(res,seg->get(vertex[u],vertex[head[u]]));\n\t\t\
    \t\tu=par[u];\n\t\t\t}\n\t\t}\n\t\treturn f(res,seg->get(vertex[u],vertex[v]));\n\
    \t}\n\tinline T get_subtree(auto u){\n\t\treturn seg->get(vertex[u],vertex[u]+sz[u]-1);\n\
    \t}\n\tprotected:\n\tconstexpr static T e=0;\n\tconstexpr static\n\tT f(const\
    \ T& s,const T& t){\n\t\treturn s+t;\n\t}\n};\n"
  code: "template<typename T>\nclass HLD_seg{\n\tclass segment{\n\t\tT* node;\n\t\t\
    int n=1;\n\t\tpublic:\n\t\tsegment(int sz){\n\t\t\twhile(n<sz)n<<=1;\n\t\t\tnode=new\
    \ T[(n<<1)-1];\n\t\t\tfor(int i=0;i<(n<<1)-1;i++)node[i]=e;\n\t\t}\n\t\tsegment(const\
    \ vector<T>& v){\n\t\t\twhile(n<(int)v.size())n<<=1;\n\t\t\tnode=new T[(n<<1)-1];\n\
    \t\t\tfor(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];\n        \tfor(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);\n\
    \t\t}\n\t\tT get(auto l,auto r){\n\t\t\tif(l>r)swap(l,r);\n\t\t\tl+=n;r+=n+1;\n\
    \t\t\tT s=e;\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1)s=f(s,node[l++-1]);\n\t\t\t\t\
    if(r&1)s=f(s,node[--r-1]);\n\t\t\t\tl>>=1;r>>=1;\n\t\t\t}\n\t\t\treturn s;\n\t\
    \t}\n\t\tvoid update(auto t,T val){\n\t\t\tt+=n-1;\n\t\t\twhile(1){\n\t\t\t\t\
    node[t]=f(node[t],val);\n\t\t\t\tt=(t-1)>>1;\n\t\t\t\tif(!t)break;\n\t\t\t}\n\t\
    \t}\n\t};\n\tint child_size(const auto& v,int n,int p){\n\t\tint cnt=0;\n\t\t\
    for(auto t:v[n]){\n\t\t\tif(t!=p)cnt+=child_size(v,t,n);\n\t\t}\n\t\treturn sz[n]=cnt+1;\n\
    \t}\n\tvoid make_hld(const auto&v,int n,int p){\n\t\tstatic int idx=0;\n\t\tvertex[n]=idx++;\n\
    \t\tint mx=0,heavy=-1;\n\t\tfor(auto t:v[n])if(t!=p&&mx<sz[t]){\n\t\t\tmx=sz[t];\n\
    \t\t\theavy=t;\n\t\t}\n\t\tif(heavy!=-1){\n\t\t\tpar[heavy]=par[n];\n\t\t\thead[heavy]=head[n];\n\
    \t\t\tmake_hld(v,heavy,n);\n\t\t}\n\t\tfor(auto t:v[n]){\n\t\t\tif(t!=heavy&&t!=p){\n\
    \t\t\t\tpar[t]=n;\n\t\t\t\thead[t]=t;\n\t\t\t\tmake_hld(v,t,n);\n\t\t\t}\n\t\t\
    }\n\t}\n\tint* sz;\n\tint* vertex;\n\tint* par;\n\tint* head;\n\tsegment* seg;\n\
    \tpublic:\n\tHLD_seg(const auto& v,int root=0){\n\t\tmake(v,root);\n\t\tseg=new\
    \ segment(v.size());\n\t}\n\tHLD_seg(const auto& v,const auto& a,int root=0){\n\
    \t\tmake(v,root);\n\t\tvector<T>tmp(v.size());\n\t\tfor(int i=0;i<(int)v.size();i++){\n\
    \t\t\ttmp[vertex[i]]=a[i];\n\t\t}\n\t\tseg=new segment(tmp);\n\t}\n\tvoid make(const\
    \ auto& v,int root){\n\t\tsz=new int[v.size()];\n\t\tvertex=new int[v.size()];\n\
    \t\tpar=new int[v.size()];\n\t\thead=new int[v.size()];\n\t\tchild_size(v,root,-1);\n\
    \t\tpar[root]=root;\n\t\thead[root]=root;\n\t\tmake_hld(v,root,-1);\n\t}\n\tint\
    \ lca(auto l,auto r){\n\t\twhile(head[l]!=head[r]){\n\t\t\tif(sz[head[l]]>sz[head[r]])r=par[r];\n\
    \t\t\telse l=par[l];\n\t\t}\n\t\treturn sz[l]>sz[r]?l:r;\n\t}\n\tinline void update(auto\
    \ t,T x){\n\t\tseg->update(vertex[t],x);\n\t}\n\tT get(auto u,auto v){\n\t\tT\
    \ res=e;\n\t\twhile(head[u]!=head[v]){\n\t\t\tif(sz[head[u]]>sz[head[v]]){\n\t\
    \t\t\tres=f(res,seg->get(vertex[v],vertex[head[v]]));\n\t\t\t\tv=par[v];\n\t\t\
    \t}\n\t\t\telse{\n\t\t\t\tres=f(res,seg->get(vertex[u],vertex[head[u]]));\n\t\t\
    \t\tu=par[u];\n\t\t\t}\n\t\t}\n\t\treturn f(res,seg->get(vertex[u],vertex[v]));\n\
    \t}\n\tinline T get_subtree(auto u){\n\t\treturn seg->get(vertex[u],vertex[u]+sz[u]-1);\n\
    \t}\n\tprotected:\n\tconstexpr static T e=0;\n\tconstexpr static\n\tT f(const\
    \ T& s,const T& t){\n\t\treturn s+t;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/HLD_seg.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/HLD_seg.hpp
layout: document
redirect_from:
- /library/data_structure/HLD_seg.hpp
- /library/data_structure/HLD_seg.hpp.html
title: data_structure/HLD_seg.hpp
---
