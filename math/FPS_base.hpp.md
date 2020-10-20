---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/FPS_long.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(Integer)"
  - icon: ':question:'
    path: math/FPS_mint.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph_tree/test/LC_centroid_decomposition.test.cpp
    title: graph_tree/test/LC_centroid_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_1000000007.test.cpp
    title: math/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_convolution_998244353.test.cpp
    title: math/test/LC_convolution_998244353.test.cpp
  - icon: ':x:'
    path: math/test/LC_interpolation.test.cpp
    title: math/test/LC_interpolation.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(BASE)"
    links: []
  bundledCode: "#line 2 \"math/FPS_base.hpp\"\n#include<vector>\n#include<tuple>\n\
    #include<iostream>\n#include<cmath>\n#include<type_traits>\n#include<cassert>\n\
    \n/**\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(BASE)\n */\n\ntemplate<typename\
    \ T,typename F>\nstruct FPS_BASE:std::vector<T>{\n    using std::vector<T>::vector;\n\
    \    using P=FPS_BASE<T,F>;\n    F fft;\n    FPS_BASE(){}\n    inline P operator\
    \ +(T x)const noexcept{return P(*this)+=x;}\n    inline P operator -(T x)const\
    \ noexcept{return P(*this)-=x;}\n    inline P operator *(T x)const noexcept{return\
    \ P(*this)*=x;}\n    inline P operator /(T x)const noexcept{return P(*this)/=x;}\n\
    \    inline P operator <<(int x)noexcept{return P(*this)<<=x;}\n    inline P operator\
    \ >>(int x)noexcept{return P(*this)>>=x;}\n    inline P operator +(const P& x)const\
    \ noexcept{return P(*this)+=x;}\n    inline P operator -(const P& x)const noexcept{return\
    \ P(*this)-=x;}\n    inline P operator -()const noexcept{return P(1,T(0))-=P(*this);}\n\
    \    inline P operator *(const P& x)const noexcept{return P(*this)*=x;}\n    inline\
    \ P operator /(const P& x)const noexcept{return P(*this)/=x;}\n    inline P operator\
    \ %(const P& x)const noexcept{return P(*this)%=x;}\n    bool operator ==(P x){\n\
    \        for(int i=0;i<(int)max((*this).size(),x.size());++i){\n            if(i>=(int)(*this).size()&&x[i]!=T())return\
    \ 0;\n            if(i>=(int)x.size()&&(*this)[i]!=T())return 0;\n           \
    \ if(i<(int)min((*this).size(),x.size()))if((*this)[i]!=x[i])return 0;\n     \
    \   }\n        return 1;\n    }\n    P &operator +=(T x){\n        if(this->size()==0)this->resize(1,T(0));\n\
    \        (*this)[0]+=x;\n        return (*this);\n    }\n    P &operator -=(T\
    \ x){\n        if(this->size()==0)this->resize(1,T(0));\n        (*this)[0]-=x;\n\
    \        return (*this);\n    }\n    P &operator *=(T x){\n        for(int i=0;i<(int)this->size();++i){\n\
    \            (*this)[i]*=x;\n        }\n        return (*this);\n    }\n    P\
    \ &operator /=(T x){\n        if(std::is_same<T,long long>::value){\n        \
    \    for(int i=0;i<(int)this->size();++i){\n                (*this)[i]/=x;\n \
    \           }\n            return (*this);\n        }\n        return (*this)*=(T(1)/x);\n\
    \    }\n    P &operator <<=(int x){\n        P ret(x,T(0));\n        ret.insert(ret.end(),begin(*this),end(*this));\n\
    \        return (*this)=ret;\n    }\n    P &operator >>=(int x){\n        if((int)(*this).size()<=x)return\
    \ (*this)=P();\n        P ret;\n        ret.insert(ret.end(),begin(*this)+x,end(*this));\n\
    \        return (*this)=ret;\n    }\n    P &operator +=(const P& x){\n       \
    \ if(this->size()<x.size())this->resize(x.size(),T(0));\n        for(int i=0;i<(int)x.size();++i){\n\
    \            (*this)[i]+=x[i];\n        }\n        return (*this);\n    }\n  \
    \  P &operator -=(const P& x){\n        if(this->size()<x.size())this->resize(x.size(),T(0));\n\
    \        for(int i=0;i<(int)x.size();++i){\n            (*this)[i]-=x[i];\n  \
    \      }\n        return (*this);\n    }\n    P &operator *=(const P& x){\n  \
    \      return (*this)=F()(*this,x);\n    }\n    P &operator /=(P x){\n       \
    \ if(this->size()<x.size()) {\n            this->clear();\n            return\
    \ (*this);\n        }\n        const int n=this->size()-x.size()+1;\n        return\
    \ (*this) = (rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);\n    }\n    P &operator\
    \ %=(const P& x){\n        return ((*this)-=(*this)/x*x);\n    }\n    inline void\
    \ print(){\n        for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<\"\
    \ \\n\"[i==(int)(*this).size()-1];\n        if((int)(*this).size()==0)std::cerr<<'\\\
    n';\n    }\n    inline P& shrink(){while((*this).back()==0)(*this).pop_back();return\
    \ (*this);}\n    inline P pre(int sz)const{\n        return P(begin(*this),begin(*this)+std::min((int)this->size(),sz));\n\
    \    }\n    P rev(int deg=-1){\n        P ret(*this);\n        if(deg!=-1)ret.resize(deg,T(0));\n\
    \        reverse(begin(ret),end(ret));\n        return ret;\n    }\n    P inv(int\
    \ deg=-1){\n        assert((*this)[0]!=T(0));\n        const int n=deg==-1?this->size():deg;\n\
    \        P ret({T(1)/(*this)[0]});\n        for(int i=1;i<n;i<<=1){\n        \
    \    ret*=(-ret*pre(i<<1)+2).pre(i<<1);\n        }\n        return ret.pre(n);\n\
    \    }\n    inline P dot(const P& x){\n        P ret(*this);\n        for(int\
    \ i=0;i<int(min(this->size(),x.size()));++i){\n            ret[i]*=x[i];\n   \
    \     }\n        return ret;\n    }\n    P diff(){\n        if((int)(*this).size()<=1)return\
    \ P();\n        P ret(*this);\n        for(int i=0;i<(int)ret.size();i++){\n \
    \           ret[i]*=i;\n        }\n        return ret>>1;\n    }\n    P integral(){\n\
    \        P ret(*this);\n        for(int i=0;i<(int)ret.size();i++){\n        \
    \    ret[i]/=i+1;\n        }\n        return ret<<1;\n    }\n    P log(int deg=-1){\n\
    \        assert((*this)[0]==T(1));\n        const int n=deg==-1?this->size():deg;\n\
    \        return (diff()*inv(n)).pre(n-1).integral();\n    }\n    P exp(int deg=-1){\n\
    \        assert((*this)[0]==T(0));\n        const int n=deg==-1?this->size():deg;\n\
    \        P ret({T(1)});\n        for(int i=1;i<n;i<<=1){\n            ret=ret*(pre(i<<1)+1-ret.log(i<<1)).pre(i<<1);\n\
    \        }\n        return ret.pre(n);\n    }\n    P pow(int c,int deg=-1){\n\
    \        const int n=deg==-1?this->size():deg;\n\t\tlong long i=0;\n\t\tP ret(*static_cast<P*>(this));\n\
    \t\twhile(i!=(int)this->size()&&ret[i]==0)i++;\n\t\tif(i==(int)this->size())return\
    \ P(n,0);\n\t\tif(i*c>=n)return P(n,0);\n\t\tT k=ret[i];\n\t\treturn ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);\n\
    \        // const int n=deg==-1?this->size():deg;\n        // long long i=0;\n\
    \        // P ret(*this);\n        // while(i!=(int)this->size()&&ret[i]==0)i++;\n\
    \        // if(i==(int)this->size())return P(n,0);\n        // if(i*c>=n)return\
    \ P(n,0);\n        // T k=ret[i];\n        // return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);\n\
    \        // P x(*this);\n        // P ret(1,1);\n        // while(c) {\n     \
    \   //     if(c&1){\n        //         ret*=x;\n        //         if(~deg)ret=ret.pre(deg);\n\
    \        //     }\n        //     x*=x;\n        //     if(~deg)x=x.pre(deg);\n\
    \        //     c>>=1;\n        // }\n        // return ret;\n    }\n    P sqrt(int\
    \ deg=-1){\n        const int n=deg==-1?this->size():deg;\n        if((*this)[0]==T(0))\
    \ {\n            for(int i=1;i<(int)this->size();i++) {\n                if((*this)[i]!=T(0))\
    \ {\n                    if(i&1)return{};\n                    if(n-i/2<=0)break;\n\
    \                    auto ret=(*this>>i).sqrt(n-i/2)<<(i/2);\n               \
    \     if((int)ret.size()<n)ret.resize(n,T(0));\n                    return ret;\n\
    \                }\n            }\n            return P(n,0);\n        }\n   \
    \     P ret({T(1)});\n        for(int i=1;i<n;i<<=1){\n            ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);\n\
    \        }\n        return ret.pre(n);\n    }\n    P shift(int c){\n        const\
    \ int n=this->size();\n        P f(*this),g(n,0);\n        for(int i=0;i<n;++i)f[i]*=F().fact(T(i));\n\
    \        for(int i=0;i<n;++i)g[i]=F().pow(T(c),i)/F().fact(T(i));\n        g=g.rev();\n\
    \        f*=g;\n        f>>=n-1;\n        for(int i=0;i<n;++i)f[i]/=F().fact(T(i));\n\
    \        return f;\n    }\n    T eval(T x){\n        T res=0;\n        for(int\
    \ i=(int)this->size()-1;i>=0;--i){\n            res*=x;\n            res+=(*this)[i];\n\
    \        }\n        return res;\n    }\n    static P interpolation(const std::vector<T>&x,const\
    \ std::vector<T>& y){\n        const int n=x.size();\n        std::vector<std::pair<P,P>>a(n*2-1);\n\
    \        std::vector<P> b(n*2-1);\n        for(int i=0;i<n;++i)a[i+n-1]=std::make_pair(P{1},P{T()-x[i],1});\n\
    \        for(int i=n-2;i>=0;--i)a[i]={a[2*i+1].first*a[2*i+2].second+a[2*i+2].first*a[2*i+1].second,a[2*i+1].second*a[2*i+2].second};\n\
    \        auto d=(a[0].first).multipoint_eval(x);\n        for(int i=0;i<n;++i)b[i+n-1]=P{T(y[i]/d[i])};\n\
    \        for(int i=n-2;i>=0;--i)b[i]=b[2*i+1]*a[2*i+2].second+b[2*i+2]*a[2*i+1].second;\n\
    \        return b[0];\n    }\n    static P interpolation(const std::vector<T>&\
    \ y){\n        const int n=y.size();\n        std::vector<std::pair<P,P>>a(n*2-1);\n\
    \        std::vector<P>b(n*2-1);\n        for(int i=0;i<n;++i)a[i+n-1]=std::make_pair(P{1},P{T()-i,1});\n\
    \        for(int i=n-2;i>=0;--i)a[i]={a[2*i+1].first*a[2*i+2].second+a[2*i+2].first*a[2*i+1].second,a[2*i+1].second*a[2*i+2].second};\n\
    \        for(int i=0;i<n;++i){\n            T tmp=F().fact(T(i))*F().pow(T(-1),i)*F().fact(T(n-1-i));\n\
    \            b[i+n-1]=P{T(y[i]/tmp)};\n        }\n        for(int i=n-2;i>=0;--i)b[i]=b[2*i+1]*a[2*i+2].second+b[2*i+2]*a[2*i+1].second;\n\
    \        return b[0];\n    }\n    std::vector<T> multipoint_eval(const std::vector<T>&x){\n\
    \        const int n=x.size();\n        P* v=new P[2*n-1];\n        for(int i=0;i<n;i++)v[i+n-1]={T()-x[i],T(1)};\n\
    \        for(int i=n-2;i>=0;i--){v[i]=v[i*2+1]*v[i*2+2];}\n        v[0]=P(*this)%v[0];v[0].shrink();\n\
    \        for(int i=1;i<n*2-1;i++){\n            v[i]=v[(i-1)/2]%v[i];\n      \
    \      v[i].shrink();\n        }\n        std::vector<T>res(n);\n        for(int\
    \ i=0;i<n;i++)res[i]=v[i+n-1][0];\n        return res;\n    }\n    P slice(int\
    \ s,int e,int k){\n        P res;\n        for(int i=s;i<e;i+=k)res.push_back((*this)[i]);\n\
    \        return res;\n    }\n    T nth_term(P q,int64_t x){\n        if(x==0)return\
    \ (*this)[0]/q[0];\n        P p(*this);\n        P q2=q;\n        for(int i=1;i<(int)q2.size();i+=2)q2[i]*=-1;\n\
    \        q*=q2;\n        p*=q2;\n        return p.slice(x%2,p.size(),2).nth_term(q.slice(0,q.size(),2),x/2);\n\
    \    }\n    \n    //(*this)(t(x))\n    P manipulate(P t,int deg){\n        P s=P(*this);\n\
    \        if(deg==0)return P();\n        if((int)t.size()==1)return P{s.eval(t[0])};\n\
    \        int k=std::min((int)::sqrt(deg/(::log2(deg)+1))+1,(int)t.size());\n \
    \       int b=deg/k+1;\n        P t2=t.pre(k);\n        std::vector<P>table(s.size()/2+1,P{1});\n\
    \        for(int i=1;i<(int)table.size();i++){\n            table[i]=((table[i-1])*t2).pre(deg);\n\
    \        }\n        auto f=[&](auto f,auto l,auto r,int deg)->P{\n           \
    \ if(r-l==1)return P{*l};\n            auto m=l+(r-l)/2;\n            return f(f,l,m,deg)+(table[m-l]*f(f,m,r,deg)).pre(deg);\n\
    \        };\n        P ans=P();\n        P tmp=f(f,s.begin(),s.end(),deg);\n \
    \       P tmp2=P{1};\n        T tmp3=T(1);\n        int tmp5=-1;\n        P tmp6=t2.diff();\n\
    \        if(tmp6==P()){\n            for(int i=0;i<b;++i){\n                if(tmp.size()==0)break;\n\
    \                ans+=(tmp2*tmp[0]).pre(deg)/tmp3;\n                tmp=tmp.diff();\n\
    \                tmp2=(tmp2*(t-t2)).pre(deg);\n                tmp3*=T(i+1);\n\
    \            }\n        }else{\n            while(t2[++tmp5]==T());\n        \
    \    P tmp4=(tmp6>>(tmp5-1)).inv(deg);\n            for(int i=0;i<b;++i){\n  \
    \              ans+=(tmp*tmp2).pre(deg)/tmp3;\n                tmp=((tmp.diff()>>(tmp5-1))*tmp4).pre(deg);\n\
    \                tmp2=(tmp2*(t-t2)).pre(deg);\n                tmp3*=T(i+1);\n\
    \            }\n        }\n        return ans;\n    }\n    //(*this)(t(x))\n \
    \   P manipulate2(P t,int deg){\n        P ans=P();\n        P s=(*this).rev();\n\
    \        for(int i=0;i<(int)s.size();++i){\n            ans=(ans*t+s[i]).pre(deg);\n\
    \        }\n        return ans;\n    }\n    static P stirling_second(int n){\n\
    \        P a(n+1,0),b(n+1,0);\n        for(int i=0;i<=n;++i){\n            a[i]=F().pow(T(i),n)/F().fact(T(i));\n\
    \            b[i]=(i%2?T(-1):T(1))/F().fact(T(i));\n        }\n        return\
    \ (a*b).pre(n+1);\n    }\n    void debug(){\n        for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<\"\
    \ \\n\"[i==(int)(*this).size()-1];\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<tuple>\n#include<iostream>\n#include<cmath>\n\
    #include<type_traits>\n#include<cassert>\n\n/**\n * @brief \u5F62\u5F0F\u7684\u51AA\
    \u7D1A\u6570(BASE)\n */\n\ntemplate<typename T,typename F>\nstruct FPS_BASE:std::vector<T>{\n\
    \    using std::vector<T>::vector;\n    using P=FPS_BASE<T,F>;\n    F fft;\n \
    \   FPS_BASE(){}\n    inline P operator +(T x)const noexcept{return P(*this)+=x;}\n\
    \    inline P operator -(T x)const noexcept{return P(*this)-=x;}\n    inline P\
    \ operator *(T x)const noexcept{return P(*this)*=x;}\n    inline P operator /(T\
    \ x)const noexcept{return P(*this)/=x;}\n    inline P operator <<(int x)noexcept{return\
    \ P(*this)<<=x;}\n    inline P operator >>(int x)noexcept{return P(*this)>>=x;}\n\
    \    inline P operator +(const P& x)const noexcept{return P(*this)+=x;}\n    inline\
    \ P operator -(const P& x)const noexcept{return P(*this)-=x;}\n    inline P operator\
    \ -()const noexcept{return P(1,T(0))-=P(*this);}\n    inline P operator *(const\
    \ P& x)const noexcept{return P(*this)*=x;}\n    inline P operator /(const P& x)const\
    \ noexcept{return P(*this)/=x;}\n    inline P operator %(const P& x)const noexcept{return\
    \ P(*this)%=x;}\n    bool operator ==(P x){\n        for(int i=0;i<(int)max((*this).size(),x.size());++i){\n\
    \            if(i>=(int)(*this).size()&&x[i]!=T())return 0;\n            if(i>=(int)x.size()&&(*this)[i]!=T())return\
    \ 0;\n            if(i<(int)min((*this).size(),x.size()))if((*this)[i]!=x[i])return\
    \ 0;\n        }\n        return 1;\n    }\n    P &operator +=(T x){\n        if(this->size()==0)this->resize(1,T(0));\n\
    \        (*this)[0]+=x;\n        return (*this);\n    }\n    P &operator -=(T\
    \ x){\n        if(this->size()==0)this->resize(1,T(0));\n        (*this)[0]-=x;\n\
    \        return (*this);\n    }\n    P &operator *=(T x){\n        for(int i=0;i<(int)this->size();++i){\n\
    \            (*this)[i]*=x;\n        }\n        return (*this);\n    }\n    P\
    \ &operator /=(T x){\n        if(std::is_same<T,long long>::value){\n        \
    \    for(int i=0;i<(int)this->size();++i){\n                (*this)[i]/=x;\n \
    \           }\n            return (*this);\n        }\n        return (*this)*=(T(1)/x);\n\
    \    }\n    P &operator <<=(int x){\n        P ret(x,T(0));\n        ret.insert(ret.end(),begin(*this),end(*this));\n\
    \        return (*this)=ret;\n    }\n    P &operator >>=(int x){\n        if((int)(*this).size()<=x)return\
    \ (*this)=P();\n        P ret;\n        ret.insert(ret.end(),begin(*this)+x,end(*this));\n\
    \        return (*this)=ret;\n    }\n    P &operator +=(const P& x){\n       \
    \ if(this->size()<x.size())this->resize(x.size(),T(0));\n        for(int i=0;i<(int)x.size();++i){\n\
    \            (*this)[i]+=x[i];\n        }\n        return (*this);\n    }\n  \
    \  P &operator -=(const P& x){\n        if(this->size()<x.size())this->resize(x.size(),T(0));\n\
    \        for(int i=0;i<(int)x.size();++i){\n            (*this)[i]-=x[i];\n  \
    \      }\n        return (*this);\n    }\n    P &operator *=(const P& x){\n  \
    \      return (*this)=F()(*this,x);\n    }\n    P &operator /=(P x){\n       \
    \ if(this->size()<x.size()) {\n            this->clear();\n            return\
    \ (*this);\n        }\n        const int n=this->size()-x.size()+1;\n        return\
    \ (*this) = (rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);\n    }\n    P &operator\
    \ %=(const P& x){\n        return ((*this)-=(*this)/x*x);\n    }\n    inline void\
    \ print(){\n        for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<\"\
    \ \\n\"[i==(int)(*this).size()-1];\n        if((int)(*this).size()==0)std::cerr<<'\\\
    n';\n    }\n    inline P& shrink(){while((*this).back()==0)(*this).pop_back();return\
    \ (*this);}\n    inline P pre(int sz)const{\n        return P(begin(*this),begin(*this)+std::min((int)this->size(),sz));\n\
    \    }\n    P rev(int deg=-1){\n        P ret(*this);\n        if(deg!=-1)ret.resize(deg,T(0));\n\
    \        reverse(begin(ret),end(ret));\n        return ret;\n    }\n    P inv(int\
    \ deg=-1){\n        assert((*this)[0]!=T(0));\n        const int n=deg==-1?this->size():deg;\n\
    \        P ret({T(1)/(*this)[0]});\n        for(int i=1;i<n;i<<=1){\n        \
    \    ret*=(-ret*pre(i<<1)+2).pre(i<<1);\n        }\n        return ret.pre(n);\n\
    \    }\n    inline P dot(const P& x){\n        P ret(*this);\n        for(int\
    \ i=0;i<int(min(this->size(),x.size()));++i){\n            ret[i]*=x[i];\n   \
    \     }\n        return ret;\n    }\n    P diff(){\n        if((int)(*this).size()<=1)return\
    \ P();\n        P ret(*this);\n        for(int i=0;i<(int)ret.size();i++){\n \
    \           ret[i]*=i;\n        }\n        return ret>>1;\n    }\n    P integral(){\n\
    \        P ret(*this);\n        for(int i=0;i<(int)ret.size();i++){\n        \
    \    ret[i]/=i+1;\n        }\n        return ret<<1;\n    }\n    P log(int deg=-1){\n\
    \        assert((*this)[0]==T(1));\n        const int n=deg==-1?this->size():deg;\n\
    \        return (diff()*inv(n)).pre(n-1).integral();\n    }\n    P exp(int deg=-1){\n\
    \        assert((*this)[0]==T(0));\n        const int n=deg==-1?this->size():deg;\n\
    \        P ret({T(1)});\n        for(int i=1;i<n;i<<=1){\n            ret=ret*(pre(i<<1)+1-ret.log(i<<1)).pre(i<<1);\n\
    \        }\n        return ret.pre(n);\n    }\n    P pow(int c,int deg=-1){\n\
    \        const int n=deg==-1?this->size():deg;\n\t\tlong long i=0;\n\t\tP ret(*static_cast<P*>(this));\n\
    \t\twhile(i!=(int)this->size()&&ret[i]==0)i++;\n\t\tif(i==(int)this->size())return\
    \ P(n,0);\n\t\tif(i*c>=n)return P(n,0);\n\t\tT k=ret[i];\n\t\treturn ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);\n\
    \        // const int n=deg==-1?this->size():deg;\n        // long long i=0;\n\
    \        // P ret(*this);\n        // while(i!=(int)this->size()&&ret[i]==0)i++;\n\
    \        // if(i==(int)this->size())return P(n,0);\n        // if(i*c>=n)return\
    \ P(n,0);\n        // T k=ret[i];\n        // return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);\n\
    \        // P x(*this);\n        // P ret(1,1);\n        // while(c) {\n     \
    \   //     if(c&1){\n        //         ret*=x;\n        //         if(~deg)ret=ret.pre(deg);\n\
    \        //     }\n        //     x*=x;\n        //     if(~deg)x=x.pre(deg);\n\
    \        //     c>>=1;\n        // }\n        // return ret;\n    }\n    P sqrt(int\
    \ deg=-1){\n        const int n=deg==-1?this->size():deg;\n        if((*this)[0]==T(0))\
    \ {\n            for(int i=1;i<(int)this->size();i++) {\n                if((*this)[i]!=T(0))\
    \ {\n                    if(i&1)return{};\n                    if(n-i/2<=0)break;\n\
    \                    auto ret=(*this>>i).sqrt(n-i/2)<<(i/2);\n               \
    \     if((int)ret.size()<n)ret.resize(n,T(0));\n                    return ret;\n\
    \                }\n            }\n            return P(n,0);\n        }\n   \
    \     P ret({T(1)});\n        for(int i=1;i<n;i<<=1){\n            ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);\n\
    \        }\n        return ret.pre(n);\n    }\n    P shift(int c){\n        const\
    \ int n=this->size();\n        P f(*this),g(n,0);\n        for(int i=0;i<n;++i)f[i]*=F().fact(T(i));\n\
    \        for(int i=0;i<n;++i)g[i]=F().pow(T(c),i)/F().fact(T(i));\n        g=g.rev();\n\
    \        f*=g;\n        f>>=n-1;\n        for(int i=0;i<n;++i)f[i]/=F().fact(T(i));\n\
    \        return f;\n    }\n    T eval(T x){\n        T res=0;\n        for(int\
    \ i=(int)this->size()-1;i>=0;--i){\n            res*=x;\n            res+=(*this)[i];\n\
    \        }\n        return res;\n    }\n    static P interpolation(const std::vector<T>&x,const\
    \ std::vector<T>& y){\n        const int n=x.size();\n        std::vector<std::pair<P,P>>a(n*2-1);\n\
    \        std::vector<P> b(n*2-1);\n        for(int i=0;i<n;++i)a[i+n-1]=std::make_pair(P{1},P{T()-x[i],1});\n\
    \        for(int i=n-2;i>=0;--i)a[i]={a[2*i+1].first*a[2*i+2].second+a[2*i+2].first*a[2*i+1].second,a[2*i+1].second*a[2*i+2].second};\n\
    \        auto d=(a[0].first).multipoint_eval(x);\n        for(int i=0;i<n;++i)b[i+n-1]=P{T(y[i]/d[i])};\n\
    \        for(int i=n-2;i>=0;--i)b[i]=b[2*i+1]*a[2*i+2].second+b[2*i+2]*a[2*i+1].second;\n\
    \        return b[0];\n    }\n    static P interpolation(const std::vector<T>&\
    \ y){\n        const int n=y.size();\n        std::vector<std::pair<P,P>>a(n*2-1);\n\
    \        std::vector<P>b(n*2-1);\n        for(int i=0;i<n;++i)a[i+n-1]=std::make_pair(P{1},P{T()-i,1});\n\
    \        for(int i=n-2;i>=0;--i)a[i]={a[2*i+1].first*a[2*i+2].second+a[2*i+2].first*a[2*i+1].second,a[2*i+1].second*a[2*i+2].second};\n\
    \        for(int i=0;i<n;++i){\n            T tmp=F().fact(T(i))*F().pow(T(-1),i)*F().fact(T(n-1-i));\n\
    \            b[i+n-1]=P{T(y[i]/tmp)};\n        }\n        for(int i=n-2;i>=0;--i)b[i]=b[2*i+1]*a[2*i+2].second+b[2*i+2]*a[2*i+1].second;\n\
    \        return b[0];\n    }\n    std::vector<T> multipoint_eval(const std::vector<T>&x){\n\
    \        const int n=x.size();\n        P* v=new P[2*n-1];\n        for(int i=0;i<n;i++)v[i+n-1]={T()-x[i],T(1)};\n\
    \        for(int i=n-2;i>=0;i--){v[i]=v[i*2+1]*v[i*2+2];}\n        v[0]=P(*this)%v[0];v[0].shrink();\n\
    \        for(int i=1;i<n*2-1;i++){\n            v[i]=v[(i-1)/2]%v[i];\n      \
    \      v[i].shrink();\n        }\n        std::vector<T>res(n);\n        for(int\
    \ i=0;i<n;i++)res[i]=v[i+n-1][0];\n        return res;\n    }\n    P slice(int\
    \ s,int e,int k){\n        P res;\n        for(int i=s;i<e;i+=k)res.push_back((*this)[i]);\n\
    \        return res;\n    }\n    T nth_term(P q,int64_t x){\n        if(x==0)return\
    \ (*this)[0]/q[0];\n        P p(*this);\n        P q2=q;\n        for(int i=1;i<(int)q2.size();i+=2)q2[i]*=-1;\n\
    \        q*=q2;\n        p*=q2;\n        return p.slice(x%2,p.size(),2).nth_term(q.slice(0,q.size(),2),x/2);\n\
    \    }\n    \n    //(*this)(t(x))\n    P manipulate(P t,int deg){\n        P s=P(*this);\n\
    \        if(deg==0)return P();\n        if((int)t.size()==1)return P{s.eval(t[0])};\n\
    \        int k=std::min((int)::sqrt(deg/(::log2(deg)+1))+1,(int)t.size());\n \
    \       int b=deg/k+1;\n        P t2=t.pre(k);\n        std::vector<P>table(s.size()/2+1,P{1});\n\
    \        for(int i=1;i<(int)table.size();i++){\n            table[i]=((table[i-1])*t2).pre(deg);\n\
    \        }\n        auto f=[&](auto f,auto l,auto r,int deg)->P{\n           \
    \ if(r-l==1)return P{*l};\n            auto m=l+(r-l)/2;\n            return f(f,l,m,deg)+(table[m-l]*f(f,m,r,deg)).pre(deg);\n\
    \        };\n        P ans=P();\n        P tmp=f(f,s.begin(),s.end(),deg);\n \
    \       P tmp2=P{1};\n        T tmp3=T(1);\n        int tmp5=-1;\n        P tmp6=t2.diff();\n\
    \        if(tmp6==P()){\n            for(int i=0;i<b;++i){\n                if(tmp.size()==0)break;\n\
    \                ans+=(tmp2*tmp[0]).pre(deg)/tmp3;\n                tmp=tmp.diff();\n\
    \                tmp2=(tmp2*(t-t2)).pre(deg);\n                tmp3*=T(i+1);\n\
    \            }\n        }else{\n            while(t2[++tmp5]==T());\n        \
    \    P tmp4=(tmp6>>(tmp5-1)).inv(deg);\n            for(int i=0;i<b;++i){\n  \
    \              ans+=(tmp*tmp2).pre(deg)/tmp3;\n                tmp=((tmp.diff()>>(tmp5-1))*tmp4).pre(deg);\n\
    \                tmp2=(tmp2*(t-t2)).pre(deg);\n                tmp3*=T(i+1);\n\
    \            }\n        }\n        return ans;\n    }\n    //(*this)(t(x))\n \
    \   P manipulate2(P t,int deg){\n        P ans=P();\n        P s=(*this).rev();\n\
    \        for(int i=0;i<(int)s.size();++i){\n            ans=(ans*t+s[i]).pre(deg);\n\
    \        }\n        return ans;\n    }\n    static P stirling_second(int n){\n\
    \        P a(n+1,0),b(n+1,0);\n        for(int i=0;i<=n;++i){\n            a[i]=F().pow(T(i),n)/F().fact(T(i));\n\
    \            b[i]=(i%2?T(-1):T(1))/F().fact(T(i));\n        }\n        return\
    \ (a*b).pre(n+1);\n    }\n    void debug(){\n        for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<\"\
    \ \\n\"[i==(int)(*this).size()-1];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/FPS_base.hpp
  requiredBy:
  - math/FPS_long.hpp
  - math/FPS_mint.hpp
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - graph_tree/test/LC_centroid_decomposition.test.cpp
  - math/test/LC_convolution_1000000007.test.cpp
  - math/test/LC_interpolation.test.cpp
  - math/test/LC_convolution_998244353.test.cpp
documentation_of: math/FPS_base.hpp
layout: document
redirect_from:
- /library/math/FPS_base.hpp
- /library/math/FPS_base.hpp.html
title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(BASE)"
---
