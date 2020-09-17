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
  bundledCode: "#line 2 \"data_structure/Li_Chao_tree.hpp\"\n\ntemplate<typename T>\n\
    class LHT{\n    using lint = long long;\n    struct node;\n    using np = node*;\n\
    \    struct node{\n        T a,b;\n        np ch[2]={nullptr,nullptr};\n     \
    \   node(T a,T b):a(a),b(b){}\n    };\n    np root=nullptr;\n    T sign(T x){return\
    \ (x>0)-(x<0);}\n    np update(T a,T b,lint p,lint q,lint l,lint r,np t){\n  \
    \      if(!t)t=new node(0,numeric_limits<T>::max());\n        //\u533A\u9593\u5916\
    \n        if(r<=p||q<=l)return t;\n        //\u5168\u3066\u533A\u9593\u5185\n\
    \        if(p<=l&&r<=q){\n            lint m=(l+r)/2;\n            if(a*m+b<=(t->a)*m+(t->b)){\n\
    \                swap(a,t->a);\n                swap(b,t->b);\n            }\n\
    \            if(r-l==1||a==t->a)return t;\n            if(sign((a-t->a)*l+(b-t->b))*sign((a-t->a)*m+(b-t->b))<=0)t->ch[0]=update(a,b,p,q,l,m,t->ch[0]);\n\
    \            if(sign((a-t->a)*m+(b-t->b))*sign((a-t->a)*r+(b-t->b))<=0)t->ch[1]=update(a,b,p,q,m,r,t->ch[1]);\n\
    \            return t;\n        }\n        //\u4E00\u90E8\u533A\u9593\u5185\n\
    \        t->ch[0]=update(a,b,p,q,l,(l+r)/2,t->ch[0]);\n        t->ch[1]=update(a,b,p,q,(l+r)/2,r,t->ch[1]);\n\
    \        return t;\n    }\n    T get(lint x,lint l,lint r,np t){\n        if(!t)return\
    \ numeric_limits<T>::max();\n        if(r-l==1)return t->a*x+t->b;\n        lint\
    \ m=(l+r)/2;\n        if(l<=x&&x<m)return min(t->a*x+t->b,get(x,l,m,t->ch[0]));\n\
    \        else return min(t->a*x+t->b,get(x,m,r,t->ch[1]));\n    }\n    lint mn=-1LL<<32;\n\
    \    lint mx=1LL<<32;\n    public:\n    T get(lint x){\n        return get(x,mn,mx,root);\n\
    \    }\n    void add_line(T a,T b){\n        root=update(a,b,mn,mx,mn,mx,root);\n\
    \    }\n    void add_segment(lint l,lint r,T a,T b){\n        root=update(a,b,l,r,mn,mx,root);\n\
    \    }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nclass LHT{\n    using lint = long long;\n\
    \    struct node;\n    using np = node*;\n    struct node{\n        T a,b;\n \
    \       np ch[2]={nullptr,nullptr};\n        node(T a,T b):a(a),b(b){}\n    };\n\
    \    np root=nullptr;\n    T sign(T x){return (x>0)-(x<0);}\n    np update(T a,T\
    \ b,lint p,lint q,lint l,lint r,np t){\n        if(!t)t=new node(0,numeric_limits<T>::max());\n\
    \        //\u533A\u9593\u5916\n        if(r<=p||q<=l)return t;\n        //\u5168\
    \u3066\u533A\u9593\u5185\n        if(p<=l&&r<=q){\n            lint m=(l+r)/2;\n\
    \            if(a*m+b<=(t->a)*m+(t->b)){\n                swap(a,t->a);\n    \
    \            swap(b,t->b);\n            }\n            if(r-l==1||a==t->a)return\
    \ t;\n            if(sign((a-t->a)*l+(b-t->b))*sign((a-t->a)*m+(b-t->b))<=0)t->ch[0]=update(a,b,p,q,l,m,t->ch[0]);\n\
    \            if(sign((a-t->a)*m+(b-t->b))*sign((a-t->a)*r+(b-t->b))<=0)t->ch[1]=update(a,b,p,q,m,r,t->ch[1]);\n\
    \            return t;\n        }\n        //\u4E00\u90E8\u533A\u9593\u5185\n\
    \        t->ch[0]=update(a,b,p,q,l,(l+r)/2,t->ch[0]);\n        t->ch[1]=update(a,b,p,q,(l+r)/2,r,t->ch[1]);\n\
    \        return t;\n    }\n    T get(lint x,lint l,lint r,np t){\n        if(!t)return\
    \ numeric_limits<T>::max();\n        if(r-l==1)return t->a*x+t->b;\n        lint\
    \ m=(l+r)/2;\n        if(l<=x&&x<m)return min(t->a*x+t->b,get(x,l,m,t->ch[0]));\n\
    \        else return min(t->a*x+t->b,get(x,m,r,t->ch[1]));\n    }\n    lint mn=-1LL<<32;\n\
    \    lint mx=1LL<<32;\n    public:\n    T get(lint x){\n        return get(x,mn,mx,root);\n\
    \    }\n    void add_line(T a,T b){\n        root=update(a,b,mn,mx,mn,mx,root);\n\
    \    }\n    void add_segment(lint l,lint r,T a,T b){\n        root=update(a,b,l,r,mn,mx,root);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Li_Chao_tree.hpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/Li_Chao_tree.hpp
layout: document
redirect_from:
- /library/data_structure/Li_Chao_tree.hpp
- /library/data_structure/Li_Chao_tree.hpp.html
title: data_structure/Li_Chao_tree.hpp
---