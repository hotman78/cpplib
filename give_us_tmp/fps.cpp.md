---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    - https://judge.yosupo.jp/submission/28303
  bundledCode: "#line 1 \"give_us_tmp/fps.cpp\"\n\n/**\n * @brief \u5F62\u5F0F\u7684\
    \u51AA\u7D1A\u6570\n * \n * verified with    :https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n\
    \ * submission       :https://judge.yosupo.jp/submission/28303\n * \n */\ntemplate<typename\
    \ T,typename F>\nstruct fps_base:vector<T>{\n    using std::vector<T>::vector;\n\
    \    using P=fps_base<T,F>;\n    F op;\n    fps_base(F op=F()):op(op){}\n    P\
    \ operator +(T x)const{return P(*this)+=x;}\n    P operator -(T x)const{return\
    \ P(*this)-=x;}\n    P operator *(T x)const{return P(*this)*=x;}\n    P operator\
    \ /(T x)const{return P(*this)/=x;}\n    P operator <<(int x){return P(*this)<<=x;}\n\
    \    P operator >>(int x){return P(*this)>>=x;}\n    P operator +(const P& x)const{return\
    \ P(*this)+=x;}\n    P operator -(const P& x)const{return P(*this)-=x;}\n    P\
    \ operator -()const{return P(1,T(0))-=P(*this);}\n    P operator *(const P& x)const{return\
    \ P(*this)*=x;}\n    P operator /(const P& x)const{return P(*this)/=x;}\n    P\
    \ operator %(const P& x)const{return P(*this)%=x;}\n    bool operator ==(P x){\n\
    \        return shrink()==x.shrink();\n    }\n    P &operator +=(T x){\n     \
    \   if(this->size()==0)return *this=P{x};\n        (*this)[0]+=x;\n        return\
    \ *this;\n    }\n    P &operator -=(T x){\n        if(this->size()==0)return *this=P{-x};\n\
    \        (*this)[0]+=x;\n        return *this;\n    }\n    P &operator *=(T x){\n\
    \        rep(i,0,this->size())(*this)[i]*=x;\n        return *this;\n    }\n \
    \   P &operator /=(T x){\n        return *this*=T(1)/x;\n    }\n    P &operator\
    \ <<=(int x){\n        P ret(x,T(0));\n        ret.insert(ret.end(),this->begin(),this->end());\n\
    \        return *this=ret;\n    }\n    P &operator >>=(int x){\n        if((int)this->size()<=x)return\
    \ *this=P();\n        P ret;\n        ret.insert(ret.end(),this->begin()+x,this->end());\n\
    \        return (*this)=ret;\n    }\n    P &operator +=(const P& x){\n       \
    \ if(this->size()<x.size())this->resize(x.size(),T(0));\n        rep(i,0,x.size())(*this)[i]+=x[i];\n\
    \        return *this;\n    }\n    P &operator -=(const P& x){\n        if(this->size()<x.size())this->resize(x.size(),T(0));\n\
    \        rep(i,0,x.size())(*this)[i]-=x[i];\n        return *this;\n    }\n  \
    \  P &operator *=(const P& x){\n        return *this=op(*this,x);\n    }\n   \
    \ P &operator /=(P x){\n        if(this->size()<x.size()){this->clear();return\
    \ *this;}\n        int n=this->size()-x.size()+1;\n        return *this=(rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n    P &operator %=(const P& x){\n        return (*this)-=(*this)/x*x;\n\
    \    }\n    P& shrink(){while(this->size()&&this->back()==T(0))this->pop_back();return\
    \ *this;}\n    P pre(int sz)const{\n        return P(this->begin(),this->begin()+min<int>(this->size(),sz));\n\
    \    }\n    P rev(int deg=-1){\n        P ret(*this);\n        if(deg!=-1)ret.resize(deg,T(0));\n\
    \        reverse(all(ret));\n        return ret;\n    }\n    P inv(int deg=-1){\n\
    \        assert((*this)[0]!=T(0));\n        const int n=deg==-1?this->size():deg;\n\
    \        P ret({T(1)/(*this)[0]});\n        for(int i=1;i<n;i<<=1){\n        \
    \    ret*=(-ret*pre(i<<1)+2).pre(i<<1);\n        }\n        return ret.pre(n);\n\
    \    }\n    P diff(){\n        if((int)this->size()<=1)return P();\n        P\
    \ ret(*this);\n        rep(i,0,ret.size())ret[i]*=i;\n        return ret>>1;\n\
    \    }\n    P integral(){\n        P ret(*this);\n        rep(i,0,ret.size())ret[i]/=i+1;\n\
    \        return ret<<1;\n    }\n    P log(int deg=-1){\n        assert((*this)[0]==T(1));\n\
    \        int n=deg==-1?this->size():deg;\n        return (diff()*inv(n)).pre(n-1).integral();\n\
    \    }\n    P exp(int deg=-1){\n        assert((*this)[0]==T(0));\n        int\
    \ n=deg==-1?this->size():deg;\n        P ret({T(1)});\n        for(int i=1;i<n;i<<=1){\n\
    \            ret=ret*(pre(i<<1)+1-ret.log(i<<1)).pre(i<<1);\n        }\n     \
    \   return ret.pre(n);\n    }\n    P pow(int c,int deg=-1){\n        const int\
    \ n=deg==-1?this->size():deg;\n\t\tlong long i=0;\n\t\tP ret(*static_cast<P*>(this));\n\
    \t\twhile(i!=(int)this->size()&&ret[i]==0)i++;\n\t\tif(i==(int)this->size())return\
    \ P(n,0);\n\t\tif(i*c>=n)return P(n,0);\n\t\tT k=ret[i];\n\t\treturn ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);\n\
    \    }\n    template<typename G>\n    P sqrt(int deg=-1,G sq=G()){\n        const\
    \ int n=deg==-1?this->size():deg;\n        int tmp=0;\n        while((*this)[tmp]==T(0))tmp++;\n\
    \        if(tmp&1)return {};\n        if(n-tmp/2<=0)return P(n,0);\n        if(tmp){\n\
    \            return ((*this>>tmp).sqrt(n-tmp/2)<<(tmp/2)).resize(n,T(0));\n  \
    \      }else{\n            P ret({T(1)});\n            for(int i=1;i<n;i<<=1){\n\
    \                ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);\n         \
    \   }\n            return ret.pre(n);\n        }\n    }\n};\nstruct __F__{template<typename\
    \ T>T operator()(T s,T t){auto tmp=mul(s,t);return *static_cast<T*>(&tmp);}};\n\
    template<typename T>\nusing fps=fps_base<T,__F__>;\n"
  code: "\n/**\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * \n * verified with\
    \    :https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n * submission\
    \       :https://judge.yosupo.jp/submission/28303\n * \n */\ntemplate<typename\
    \ T,typename F>\nstruct fps_base:vector<T>{\n    using std::vector<T>::vector;\n\
    \    using P=fps_base<T,F>;\n    F op;\n    fps_base(F op=F()):op(op){}\n    P\
    \ operator +(T x)const{return P(*this)+=x;}\n    P operator -(T x)const{return\
    \ P(*this)-=x;}\n    P operator *(T x)const{return P(*this)*=x;}\n    P operator\
    \ /(T x)const{return P(*this)/=x;}\n    P operator <<(int x){return P(*this)<<=x;}\n\
    \    P operator >>(int x){return P(*this)>>=x;}\n    P operator +(const P& x)const{return\
    \ P(*this)+=x;}\n    P operator -(const P& x)const{return P(*this)-=x;}\n    P\
    \ operator -()const{return P(1,T(0))-=P(*this);}\n    P operator *(const P& x)const{return\
    \ P(*this)*=x;}\n    P operator /(const P& x)const{return P(*this)/=x;}\n    P\
    \ operator %(const P& x)const{return P(*this)%=x;}\n    bool operator ==(P x){\n\
    \        return shrink()==x.shrink();\n    }\n    P &operator +=(T x){\n     \
    \   if(this->size()==0)return *this=P{x};\n        (*this)[0]+=x;\n        return\
    \ *this;\n    }\n    P &operator -=(T x){\n        if(this->size()==0)return *this=P{-x};\n\
    \        (*this)[0]+=x;\n        return *this;\n    }\n    P &operator *=(T x){\n\
    \        rep(i,0,this->size())(*this)[i]*=x;\n        return *this;\n    }\n \
    \   P &operator /=(T x){\n        return *this*=T(1)/x;\n    }\n    P &operator\
    \ <<=(int x){\n        P ret(x,T(0));\n        ret.insert(ret.end(),this->begin(),this->end());\n\
    \        return *this=ret;\n    }\n    P &operator >>=(int x){\n        if((int)this->size()<=x)return\
    \ *this=P();\n        P ret;\n        ret.insert(ret.end(),this->begin()+x,this->end());\n\
    \        return (*this)=ret;\n    }\n    P &operator +=(const P& x){\n       \
    \ if(this->size()<x.size())this->resize(x.size(),T(0));\n        rep(i,0,x.size())(*this)[i]+=x[i];\n\
    \        return *this;\n    }\n    P &operator -=(const P& x){\n        if(this->size()<x.size())this->resize(x.size(),T(0));\n\
    \        rep(i,0,x.size())(*this)[i]-=x[i];\n        return *this;\n    }\n  \
    \  P &operator *=(const P& x){\n        return *this=op(*this,x);\n    }\n   \
    \ P &operator /=(P x){\n        if(this->size()<x.size()){this->clear();return\
    \ *this;}\n        int n=this->size()-x.size()+1;\n        return *this=(rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n    P &operator %=(const P& x){\n        return (*this)-=(*this)/x*x;\n\
    \    }\n    P& shrink(){while(this->size()&&this->back()==T(0))this->pop_back();return\
    \ *this;}\n    P pre(int sz)const{\n        return P(this->begin(),this->begin()+min<int>(this->size(),sz));\n\
    \    }\n    P rev(int deg=-1){\n        P ret(*this);\n        if(deg!=-1)ret.resize(deg,T(0));\n\
    \        reverse(all(ret));\n        return ret;\n    }\n    P inv(int deg=-1){\n\
    \        assert((*this)[0]!=T(0));\n        const int n=deg==-1?this->size():deg;\n\
    \        P ret({T(1)/(*this)[0]});\n        for(int i=1;i<n;i<<=1){\n        \
    \    ret*=(-ret*pre(i<<1)+2).pre(i<<1);\n        }\n        return ret.pre(n);\n\
    \    }\n    P diff(){\n        if((int)this->size()<=1)return P();\n        P\
    \ ret(*this);\n        rep(i,0,ret.size())ret[i]*=i;\n        return ret>>1;\n\
    \    }\n    P integral(){\n        P ret(*this);\n        rep(i,0,ret.size())ret[i]/=i+1;\n\
    \        return ret<<1;\n    }\n    P log(int deg=-1){\n        assert((*this)[0]==T(1));\n\
    \        int n=deg==-1?this->size():deg;\n        return (diff()*inv(n)).pre(n-1).integral();\n\
    \    }\n    P exp(int deg=-1){\n        assert((*this)[0]==T(0));\n        int\
    \ n=deg==-1?this->size():deg;\n        P ret({T(1)});\n        for(int i=1;i<n;i<<=1){\n\
    \            ret=ret*(pre(i<<1)+1-ret.log(i<<1)).pre(i<<1);\n        }\n     \
    \   return ret.pre(n);\n    }\n    P pow(int c,int deg=-1){\n        const int\
    \ n=deg==-1?this->size():deg;\n\t\tlong long i=0;\n\t\tP ret(*static_cast<P*>(this));\n\
    \t\twhile(i!=(int)this->size()&&ret[i]==0)i++;\n\t\tif(i==(int)this->size())return\
    \ P(n,0);\n\t\tif(i*c>=n)return P(n,0);\n\t\tT k=ret[i];\n\t\treturn ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);\n\
    \    }\n    template<typename G>\n    P sqrt(int deg=-1,G sq=G()){\n        const\
    \ int n=deg==-1?this->size():deg;\n        int tmp=0;\n        while((*this)[tmp]==T(0))tmp++;\n\
    \        if(tmp&1)return {};\n        if(n-tmp/2<=0)return P(n,0);\n        if(tmp){\n\
    \            return ((*this>>tmp).sqrt(n-tmp/2)<<(tmp/2)).resize(n,T(0));\n  \
    \      }else{\n            P ret({T(1)});\n            for(int i=1;i<n;i<<=1){\n\
    \                ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);\n         \
    \   }\n            return ret.pre(n);\n        }\n    }\n};\nstruct __F__{template<typename\
    \ T>T operator()(T s,T t){auto tmp=mul(s,t);return *static_cast<T*>(&tmp);}};\n\
    template<typename T>\nusing fps=fps_base<T,__F__>;"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/fps.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/fps.cpp
layout: document
redirect_from:
- /library/give_us_tmp/fps.cpp
- /library/give_us_tmp/fps.cpp.html
title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
