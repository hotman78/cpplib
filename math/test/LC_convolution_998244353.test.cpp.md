---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/FPS_base.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(BASE)"
  - icon: ':x:'
    path: math/FPS_mint.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570(ModInt)"
  - icon: ':question:'
    path: math/ceil_pow2.hpp
    title: math/ceil_pow2.hpp
  - icon: ':question:'
    path: math/garner.hpp
    title: "\u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':question:'
    path: math/mod_int.hpp
    title: ModInt
  - icon: ':question:'
    path: math/mod_int998244353.hpp
    title: ModInt(998'244'353)
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  - icon: ':question:'
    path: util/ACL.hpp
    title: util/ACL.hpp
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"math/test/LC_convolution_998244353.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n#line 2 \"util/template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
    typedef long long lint;\n#define INF (1LL<<60)\n#define IINF (1<<30)\n#define\
    \ EPS (1e-10)\n#define endl ('\\n')\ntypedef vector<lint> vec;\ntypedef vector<vector<lint>>\
    \ mat;\ntypedef vector<vector<vector<lint>>> mat3;\ntypedef vector<string> svec;\n\
    typedef vector<vector<string>> smat;\ntemplate<typename T>inline void output(T\
    \ t){bool f=0;for(auto i:t){cout<<(f?\" \":\"\")<<i;f=1;}cout<<endl;}\ntemplate<typename\
    \ T>inline void output2(T t){for(auto i:t)output(i);}\ntemplate<typename T>inline\
    \ void debug(T t){bool f=0;for(auto i:t){cerr<<(f?\" \":\"\")<<i;f=1;}cerr<<endl;}\n\
    template<typename T>inline void debug2(T t){for(auto i:t)output(i);}\n#define\
    \ loop(n) for(long long _=0;_<(long long)(n);++_)\n#define rep(i,...) for(auto\
    \ i:range(__VA_ARGS__)) \n#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))\n\
    #define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)\n#define rrepi(i,a,b)\
    \ for(lint i=lint(b)-1;i>=lint(a);--i)\n#define irep(i) for(lint i=0;;++i)\ninline\
    \ vector<long long> range(long long n){if(n<=0)return vector<long long>();vector<long\
    \ long>v(n);iota(v.begin(),v.end(),0LL);return v;}\ninline vector<long long> range(long\
    \ long a,long long b){if(b<=a)return vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
    \ v;}\ninline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\ntemplate<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n#define\
    \ extrep(v,...) for(auto v:__MAKE_MAT__({__VA_ARGS__}))\nvector<vector<long long>>\
    \ __MAKE_MAT__(vector<long long> v){if(v.empty())return vector<vector<long long>>(1,vector<long\
    \ long>());long long n=v.back();v.pop_back();vector<vector<long long>> ret;vector<vector<long\
    \ long>> tmp=__MAKE_MAT__(v);for(auto e:tmp)for(long long i=0;i<n;++i){ret.push_back(e);ret.back().push_back(i);}return\
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\ntemplate<typename T,typename\
    \ E>ostream& operator<<(ostream& out,pair<T,E>v){out<<\"(\"<<v.first<<\",\"<<v.second<<\"\
    )\";return out;}\n#line 5 \"math/mod_int.hpp\"\n\n/**\n * @brief ModInt\n */\n\
    \ntemplate<int MOD>\nstruct mod_int {\n    using mint=mod_int<MOD>;\n    using\
    \ u64 = std::uint_fast64_t;\n    u64 a;\n    constexpr mod_int(const long long\
    \ x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n    constexpr\
    \ u64 &value()noexcept{return a;}\n    constexpr const u64 &value() const noexcept\
    \ {return a;}\n    constexpr mint operator+(const mint rhs)const noexcept{return\
    \ mint(*this) += rhs;}\n    constexpr mint operator-(const mint rhs)const noexcept{return\
    \ mint(*this)-=rhs;}\n    constexpr mint operator*(const mint rhs) const noexcept\
    \ {return mint(*this) *= rhs;}\n    constexpr mint operator/(const mint rhs) const\
    \ noexcept {return mint(*this) /= rhs;}\n    constexpr mint &operator+=(const\
    \ mint rhs) noexcept {\n        a += rhs.a;\n        if (a >= get_mod())a -= get_mod();\n\
    \        return *this;\n    }\n    constexpr mint &operator-=(const mint rhs)\
    \ noexcept {\n        if (a<rhs.a)a += get_mod();\n        a -= rhs.a;\n     \
    \   return *this;\n    }\n    constexpr mint &operator*=(const mint rhs) noexcept\
    \ {\n        a = a * rhs.a % get_mod();\n        return *this;\n    }\n    constexpr\
    \ mint operator++(int) noexcept {\n        a += 1;\n        if (a >= get_mod())a\
    \ -= get_mod();\n        return *this;\n    }\n    constexpr mint operator--(int)\
    \ noexcept {\n        if (a<1)a += get_mod();\n        a -= 1;\n        return\
    \ *this;\n    }\n    constexpr mint &operator/=(mint rhs) noexcept {\n       \
    \ u64 exp=get_mod()-2;\n        while (exp) {\n            if (exp % 2) {\n  \
    \              *this *= rhs;\n            }\n            rhs *= rhs;\n       \
    \     exp /= 2;\n        }\n        return *this;\n    }\n    constexpr bool operator==(mint\
    \ x) noexcept {\n        return a==x.a;\n    }\n    constexpr bool operator!=(mint\
    \ x) noexcept {\n        return a!=x.a;\n    }\n    constexpr bool operator<(mint\
    \ x) noexcept {\n        return a<x.a;\n    }\n    constexpr bool operator>(mint\
    \ x) noexcept {\n        return a>x.a;\n    }\n    constexpr bool operator<=(mint\
    \ x) noexcept {\n        return a<=x.a;\n    }\n    constexpr bool operator>=(mint\
    \ x) noexcept {\n        return a>=x.a;\n    }\n    constexpr static int root(){\n\
    \        mint root = 2;\n        while(root.pow((get_mod()-1)>>1).a==1)root++;\n\
    \        return root.a;\n    }\n    constexpr mint pow(long long n)const{\n  \
    \      long long x=a;\n        mint ret = 1;\n        while(n>0) {\n         \
    \   if(n&1)(ret*=x);\n            (x*=x)%=get_mod();\n            n>>=1;\n   \
    \     }\n        return ret;\n    }\n    constexpr mint inv(){\n        return\
    \ pow(get_mod()-2);\n    }\n    static std::vector<mint> fac;\n    static std::vector<mint>\
    \ ifac;\n    static bool init;\n    constexpr static int mx=10000001;\n    void\
    \ build()const{\n        init=0;\n        fac.resize(mx);\n        ifac.resize(mx);\n\
    \        fac[0]=1,ifac[0]=1;\n        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;\n\
    \        ifac[mx-1]=fac[mx-1].inv();\n        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);\n\
    \    }\n    mint comb(long long b){\n        if(init)build();\n        if(a==0&&b==0)return\
    \ 1;\n        if((long long)a<b)return 0;\n        return fac[a]*ifac[a-b]*ifac[b];\n\
    \    }\n    mint fact()const{\n        if(init)build();\n        return fac[a];\n\
    \    }\n    mint fact_inv()const{\n        if(init)build();\n        return ifac[a];\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs)\
    \ noexcept {\n        lhs << rhs.a;\n        return lhs;\n    }\n    friend std::istream&\
    \ operator>>(std::istream& lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n\
    \        return lhs;\n    }\n    constexpr static u64 get_mod(){\n        return\
    \ MOD;\n    }\n};\ntemplate<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;\n\
    template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;\ntemplate<int MOD>bool\
    \ mod_int<MOD>::init=1;\n#line 3 \"math/mod_int998244353.hpp\"\nusing mint=mod_int<998'244'353>;\n\
    \n/**\n * @brief ModInt(998'244'353)\n */\n#line 6 \"math/FPS_base.hpp\"\n#include<type_traits>\n\
    #line 8 \"math/FPS_base.hpp\"\n\n/**\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\
    \u6570(BASE)\n */\n\ntemplate<typename T,typename F>\nstruct FPS_BASE:std::vector<T>{\n\
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
    \        }\n        return ans;\n    }\n    P find_linear_recurrence()const{\n\
    \        const int n=this->size();\n        P b={T(-1)},c={T(-1)};\n        T\
    \ y=T(1);\n        for(int i=1;i<=n;++i){\n            int l=c.size(),m=b.size();\n\
    \            T x=0;\n            for(int j=0;j<l;++j)x+=c[j]*(*this)[i-l+j];\n\
    \            b.emplace_back(0);\n            m++;\n            if(x==T(0))continue;\n\
    \            T freq=x/y;\n            if(l<m){\n                auto tmp=c;\n\
    \                c<<=m-l;\n                c-=b*freq;\n                b=tmp;\n\
    \                y=x;\n            }else{\n                c-=(b*freq)<<(l-m);\n\
    \            }\n        }\n        return c;\n    }\n    static P stirling_second(int\
    \ n){\n        P a(n+1,0),b(n+1,0);\n        for(int i=0;i<=n;++i){\n        \
    \    a[i]=F().pow(T(i),n)/F().fact(T(i));\n            b[i]=(i%2?T(-1):T(1))/F().fact(T(i));\n\
    \        }\n        return (a*b).pre(n+1);\n    }\n    void debug(){\n       \
    \ for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<\" \\n\"[i==(int)(*this).size()-1];\n\
    \    }\n};\n#line 4 \"util/ACL.hpp\"\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\
    namespace atcoder {\nnamespace internal {\n// @param n `0 <= n`\n// @return minimum\
    \ non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n\
    \    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n// @param n\
    \ `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint\
    \ bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n}  //\
    \ namespace internal\n}  // namespace atcoder\n#line 30 \"util/ACL.hpp\"\nnamespace\
    \ atcoder {\nnamespace internal {\n// @param m `1 <= m`\n// @return x mod m\n\
    constexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\n// Fast modular multiplication by barrett\
    \ reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n//\
    \ NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n  \
    \  unsigned long long im;\n    // @param m `1 <= m < 2^31`\n    barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n      \
    \  // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <=\
    \ c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 +\
    \ c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n// @param n `0 <= n`\n// @param m\
    \ `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n// @param b\
    \ `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x <\
    \ b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n    while (t) {\n        long long u = s / t;\n        s -= t\
    \ * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    // Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n}  // namespace internal\n}  // namespace atcoder\n\
    #line 189 \"util/ACL.hpp\"\nnamespace atcoder {\nnamespace internal {\n#ifndef\
    \ _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <class T>\nusing is_unsigned_int128 =\n  \
    \  typename std::conditional<std::is_same<T, __uint128_t>::value ||\n        \
    \                          std::is_same<T, unsigned __int128>::value,\n      \
    \                        std::true_type,\n                              std::false_type>::type;\n\
    template <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    template <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n#else\ntemplate <class T> using is_integral\
    \ = typename std::is_integral<T>;\ntemplate <class T>\nusing is_signed_int =\n\
    \    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <class T>\nusing is_unsigned_int =\n    typename\
    \ std::conditional<is_integral<T>::value &&\n                                \
    \  std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\ntemplate <class T>\nusing\
    \ to_unsigned = typename std::conditional<is_signed_int<T>::value,\n         \
    \                                     std::make_unsigned<T>,\n               \
    \                               std::common_type<T>>::type;\n#endif\ntemplate\
    \ <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    template <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    template <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n}  //\
    \ namespace internal\n}  // namespace atcoder\n#line 263 \"util/ACL.hpp\"\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\nnamespace atcoder {\nnamespace internal\
    \ {\nstruct modint_base {};\nstruct static_modint_base : modint_base {};\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n}  // namespace\
    \ internal\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\nstruct static_modint\
    \ : internal::static_modint_base {\n    using mint = static_modint;\n  public:\n\
    \    static constexpr int mod() { return m; }\n    static mint raw(int v) {\n\
    \        mint x;\n        x._v = v;\n        return x;\n    }\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n    static_modint(bool\
    \ v) { _v = ((unsigned int)(v) % umod()); }\n    unsigned int val() const { return\
    \ _v; }\n    mint& operator++() {\n        _v++;\n        if (_v == umod()) _v\
    \ = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if (_v\
    \ == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint result = *this;\n        ++*this;\n        return result;\n\
    \    }\n    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n    mint& operator+=(const mint& rhs) {\n    \
    \    _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return *this;\n\
    \    }\n    mint& operator-=(const mint& rhs) {\n        _v -= rhs._v;\n     \
    \   if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n   \
    \     _v = (unsigned int)(z % umod());\n        return *this;\n    }\n    mint&\
    \ operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n    mint\
    \ operator+() const { return *this; }\n    mint operator-() const { return mint()\
    \ - *this; }\n    mint pow(long long n) const {\n        assert(0 <= n);\n   \
    \     mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *=\
    \ x;\n            x *= x;\n            n >>= 1;\n        }\n        return r;\n\
    \    }\n    mint inv() const {\n        if (prime) {\n            assert(_v);\n\
    \            return pow(umod() - 2);\n        } else {\n            auto eg =\
    \ internal::inv_gcd(_v, m);\n            assert(eg.first == 1);\n            return\
    \ eg.second;\n        }\n    }\n    friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend mint operator/(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n  private:\n    unsigned int _v;\n    static constexpr unsigned\
    \ int umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n    dynamic_modint() : _v(0) {}\n    template <class T,\
    \ internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n      \
    \  long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x +=\
    \ mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }\n   \
    \ unsigned int val() const { return _v; }\n    mint& operator++() {\n        _v++;\n\
    \        if (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += mod() - rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& rhs) {\n        _v = bt.mul(_v,\
    \ rhs._v);\n        return *this;\n    }\n    mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\n    mint operator+() const { return *this;\
    \ }\n    mint operator-() const { return mint() - *this; }\n    mint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n \
    \       while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n   \
    \         n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ {\n        auto eg = internal::inv_gcd(_v, mod());\n        assert(eg.first\
    \ == 1);\n        return eg.second;\n    }\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend\
    \ mint operator-(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ -= rhs;\n    }\n    friend mint operator*(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) /= rhs;\n    }\n   \
    \ friend bool operator==(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ == rhs._v;\n    }\n    friend bool operator!=(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v != rhs._v;\n    }\n  private:\n    unsigned int _v;\n\
    \    static internal::barrett bt;\n    static unsigned int umod() { return bt.umod();\
    \ }\n};\ntemplate <int id> internal::barrett dynamic_modint<id>::bt = 998244353;\n\
    using modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\nnamespace internal {\ntemplate <class T>\n\
    using is_static_modint = std::is_base_of<internal::static_modint_base, T>;\ntemplate\
    \ <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    template <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    }  // namespace internal\n}  // namespace atcoder\n#line 498 \"util/ACL.hpp\"\n\
    namespace atcoder {\nnamespace internal {\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly(std::vector<mint>& a) {\n    static constexpr int\
    \ g = internal::primitive_root<mint::mod()>;\n    int n = int(a.size());\n   \
    \ int h = internal::ceil_pow2(n);\n    static bool first = true;\n    static mint\
    \ sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n    if (first)\
    \ {\n        first = false;\n        mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n        int cnt2 = bsf(mint::mod() - 1);\n        mint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_e[i] =\
    \ es[i] * now;\n            now *= ies[i];\n        }\n    }\n    for (int ph\
    \ = 1; ph <= h; ph++) {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n \
    \       mint now = 1;\n        for (int s = 0; s < w; s++) {\n            int\
    \ offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n   \
    \             auto l = a[i + offset];\n                auto r = a[i + offset +\
    \ p] * now;\n                a[i + offset] = l + r;\n                a[i + offset\
    \ + p] = l - r;\n            }\n            now *= sum_e[bsf(~(unsigned int)(s))];\n\
    \        }\n    }\n}\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    static constexpr\
    \ int g = internal::primitive_root<mint::mod()>;\n    int n = int(a.size());\n\
    \    int h = internal::ceil_pow2(n);\n    static bool first = true;\n    static\
    \ mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n    if (first)\
    \ {\n        first = false;\n        mint es[30], ies[30];  // es[i]^(2^(2+i))\
    \ == 1\n        int cnt2 = bsf(mint::mod() - 1);\n        mint e = mint(g).pow((mint::mod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_ie[i] =\
    \ ies[i] * now;\n            now *= es[i];\n        }\n    }\n    for (int ph\
    \ = h; ph >= 1; ph--) {\n        int w = 1 << (ph - 1), p = 1 << (h - ph);\n \
    \       mint inow = 1;\n        for (int s = 0; s < w; s++) {\n            int\
    \ offset = s << (h - ph + 1);\n            for (int i = 0; i < p; i++) {\n   \
    \             auto l = a[i + offset];\n                auto r = a[i + offset +\
    \ p];\n                a[i + offset] = l + r;\n                a[i + offset +\
    \ p] =\n                    (unsigned long long)(mint::mod() + l.val() - r.val())\
    \ *\n                    inow.val();\n            }\n            inow *= sum_ie[bsf(~(unsigned\
    \ int)(s))];\n        }\n    }\n}\n}  // namespace internal\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   if (!n || !m) return {};\n    if (std::min(n, m) <= 60) {\n        if (n <\
    \ m) {\n            std::swap(n, m);\n            std::swap(a, b);\n        }\n\
    \        std::vector<mint> ans(n + m - 1);\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < m; j++) {\n                ans[i + j] +=\
    \ a[i] * b[j];\n            }\n        }\n        return ans;\n    }\n    int\
    \ z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n\
    \    b.resize(z);\n    internal::butterfly(b);\n    for (int i = 0; i < z; i++)\
    \ {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1;\
    \ i++) a[i] *= iz;\n    return a;\n}\ntemplate <unsigned int mod = 998244353,\n\
    \          class T,\n          std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\nstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    using mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n\
    \    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for\
    \ (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 =\
    \ convolution(move(a2), move(b2));\n    std::vector<T> c(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return\
    \ c;\n}\nstd::vector<long long> convolution_ll(const std::vector<long long>& a,\n\
    \                                      const std::vector<long long>& b) {\n  \
    \  int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n \
    \   static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n    static\
    \ constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr unsigned\
    \ long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3\
    \ = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n + m\
    \ - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1) %\
    \ MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n    return c;\n}\n}  // namespace\
    \ atcoder\n#line 692 \"util/ACL.hpp\"\nnamespace atcoder {\n// Implement (union\
    \ by size) + (path compression)\n// Reference:\n// Zvi Galil and Giuseppe F. Italiano,\n\
    // Data structures and algorithms for disjoint set union problems\nstruct dsu\
    \ {\n  public:\n    dsu() : _n(0) {}\n    dsu(int n) : _n(n), parent_or_size(n,\
    \ -1) {}\n    int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n \
    \       assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n    int leader(int a) {\n        assert(0 <= a && a <\
    \ _n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    \  private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n}  // namespace atcoder\n\
    #line 753 \"util/ACL.hpp\"\nnamespace atcoder {\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \  public:\n    fenwick_tree() : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n)\
    \ {}\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n\
    \        while (p <= _n) {\n            data[p - 1] += U(x);\n            p +=\
    \ p & -p;\n        }\n    }\n    T sum(int l, int r) {\n        assert(0 <= l\
    \ && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n  private:\n\
    \    int _n;\n    std::vector<U> data;\n    U sum(int r) {\n        U s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n}  // namespace atcoder\n#line\
    \ 789 \"util/ACL.hpp\"\nnamespace atcoder {\ntemplate <class S,\n          S (*op)(S,\
    \ S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n\
    \          F (*composition)(F, F),\n          F (*id)()>\nstruct lazy_segtree\
    \ {\n  public:\n    lazy_segtree() : lazy_segtree(0) {}\n    lazy_segtree(int\
    \ n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n        l += size;\n        r += size;\n        for (int i =\
    \ log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n \
    \           if (((r >> i) << i) != r) push(r >> i);\n        }\n        S sml\
    \ = e(), smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    S all_prod()\
    \ { return d[1]; }\n    void apply(int p, F f) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        if (l == r) return;\n        l += size;\n     \
    \   r += size;\n        for (int i = log; i >= 1; i--) {\n            if (((l\
    \ >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n       \
    \     while (l < r) {\n                if (l & 1) all_apply(l++, f);\n       \
    \         if (r & 1) all_apply(--r, f);\n                l >>= 1;\n          \
    \      r >>= 1;\n            }\n            l = l2;\n            r = r2;\n   \
    \     }\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i) <<\
    \ i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r -\
    \ 1) >> i);\n        }\n    }\n    template <bool (*g)(S)> int max_right(int l)\
    \ {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n}  // namespace atcoder\n#line 951 \"util/ACL.hpp\"\nnamespace atcoder\
    \ {\nlong long pow_mod(long long x, long long n, int m) {\n    assert(0 <= n &&\
    \ 1 <= m);\n    if (m == 1) return 0;\n    internal::barrett bt((unsigned int)(m));\n\
    \    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));\n    while\
    \ (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y, y);\n   \
    \     n >>= 1;\n    }\n    return r;\n}\nlong long inv_mod(long long x, long long\
    \ m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n    assert(z.first\
    \ == 1);\n    return z.second;\n}\n// (rem, mod)\nstd::pair<long long, long long>\
    \ crt(const std::vector<long long>& r,\n                                    const\
    \ std::vector<long long>& m) {\n    assert(r.size() == m.size());\n    int n =\
    \ int(r.size());\n    // Contracts: 0 <= r0 < m0\n    long long r0 = 0, m0 = 1;\n\
    \    for (int i = 0; i < n; i++) {\n        assert(1 <= m[i]);\n        long long\
    \ r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];\n        if (m0 < m1) {\n  \
    \          std::swap(r0, r1);\n            std::swap(m0, m1);\n        }\n   \
    \     if (m0 % m1 == 0) {\n            if (r0 % m1 != r1) return {0, 0};\n   \
    \         continue;\n        }\n        // assume: m0 > m1, lcm(m0, m1) >= 2 *\
    \ max(m0, m1)\n        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));\n    \
    \    // r2 % m0 = r0\n        // r2 % m1 = r1\n        // -> (r0 + x*m0) % m1\
    \ = r1\n        // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)\n   \
    \     // -> x = (r1 - r0) / g * inv(u0) (mod u1)\n        // im = inv(u0) (mod\
    \ u1) (0 <= im < u1)\n        long long g, im;\n        std::tie(g, im) = internal::inv_gcd(m0,\
    \ m1);\n        long long u1 = (m1 / g);\n        // |r1 - r0| < (m0 + m1) <=\
    \ lcm(m0, m1)\n        if ((r1 - r0) % g) return {0, 0};\n        // u1 * u1 <=\
    \ m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n        long long x = (r1 - r0)\
    \ / g % u1 * im % u1;\n        // |r0| + |m0 * x|\n        // < m0 + m0 * (u1\
    \ - 1)\n        // = m0 + m0 * m1 / g - m0\n        // = lcm(m0, m1)\n       \
    \ r0 += x * m0;\n        m0 *= u1;  // -> lcm(m0, m1)\n        if (r0 < 0) r0\
    \ += m0;\n    }\n    return {r0, m0};\n}\nlong long floor_sum(long long n, long\
    \ long m, long long a, long long b) {\n    long long ans = 0;\n    if (a >= m)\
    \ {\n        ans += (n - 1) * n * (a / m) / 2;\n        a %= m;\n    }\n    if\
    \ (b >= m) {\n        ans += n * (b / m);\n        b %= m;\n    }\n    long long\
    \ y_max = (a * n + b) / m, x_max = (y_max * m - b);\n    if (y_max == 0) return\
    \ ans;\n    ans += (n - (x_max + a - 1) / a) * y_max;\n    ans += floor_sum(y_max,\
    \ a, m, (a - x_max % a) % a);\n    return ans;\n}\n}  // namespace atcoder\n#line\
    \ 1032 \"util/ACL.hpp\"\nnamespace atcoder {\nnamespace internal {\ntemplate <class\
    \ T> struct simple_queue {\n    std::vector<T> payload;\n    int pos = 0;\n  \
    \  void reserve(int n) { payload.reserve(n); }\n    int size() const { return\
    \ int(payload.size()) - pos; }\n    bool empty() const { return pos == int(payload.size());\
    \ }\n    void push(const T& t) { payload.push_back(t); }\n    T& front() { return\
    \ payload[pos]; }\n    void clear() {\n        payload.clear();\n        pos =\
    \ 0;\n    }\n    void pop() { pos++; }\n};\n}  // namespace internal\n}  // namespace\
    \ atcoder\n#line 1054 \"util/ACL.hpp\"\nnamespace atcoder {\ntemplate <class Cap>\
    \ struct mf_graph {\n  public:\n    mf_graph() : _n(0) {}\n    mf_graph(int n)\
    \ : _n(n), g(n) {}\n    int add_edge(int from, int to, Cap cap) {\n        assert(0\
    \ <= from && from < _n);\n        assert(0 <= to && to < _n);\n        assert(0\
    \ <= cap);\n        int m = int(pos.size());\n        pos.push_back({from, int(g[from].size())});\n\
    \        int from_id = int(g[from].size());\n        int to_id = int(g[to].size());\n\
    \        if (from == to) to_id++;\n        g[from].push_back(_edge{to, to_id,\
    \ cap});\n        g[to].push_back(_edge{from, from_id, 0});\n        return m;\n\
    \    }\n    struct edge {\n        int from, to;\n        Cap cap, flow;\n   \
    \ };\n    edge get_edge(int i) {\n        int m = int(pos.size());\n        assert(0\
    \ <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n       \
    \ auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n        int m\
    \ = int(pos.size());\n        std::vector<edge> result;\n        for (int i =\
    \ 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n  \
    \      return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) break;\n            }\n       \
    \     return res;\n        };\n        Cap flow = 0;\n        while (flow < flow_limit)\
    \ {\n            bfs();\n            if (level[t] == -1) break;\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            while (flow < flow_limit) {\n                Cap\
    \ f = dfs(dfs, t, flow_limit - flow);\n                if (!f) break;\n      \
    \          flow += f;\n            }\n        }\n        return flow;\n    }\n\
    \    std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n  private:\n    int _n;\n    struct _edge\
    \ {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n}  // namespace atcoder\n\
    #line 1187 \"util/ACL.hpp\"\nnamespace atcoder {\ntemplate <class Cap, class Cost>\
    \ struct mcf_graph {\n  public:\n    mcf_graph() {}\n    mcf_graph(int n) : _n(n),\
    \ g(n) {}\n    int add_edge(int from, int to, Cap cap, Cost cost) {\n        assert(0\
    \ <= from && from < _n);\n        assert(0 <= to && to < _n);\n        int m =\
    \ int(pos.size());\n        pos.push_back({from, int(g[from].size())});\n    \
    \    int from_id = int(g[from].size());\n        int to_id = int(g[to].size());\n\
    \        if (from == to) to_id++;\n        g[from].push_back(_edge{to, to_id,\
    \ cap, cost});\n        g[to].push_back(_edge{from, from_id, 0, -cost});\n   \
    \     return m;\n    }\n    struct edge {\n        int from, to;\n        Cap\
    \ cap, flow;\n        Cost cost;\n    };\n    edge get_edge(int i) {\n       \
    \ int m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e\
    \ = g[pos[i].first][pos[i].second];\n        auto _re = g[_e.to][_e.rev];\n  \
    \      return edge{\n            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap,\
    \ _e.cost,\n        };\n    }\n    std::vector<edge> edges() {\n        int m\
    \ = int(pos.size());\n        std::vector<edge> result(m);\n        for (int i\
    \ = 0; i < m; i++) {\n            result[i] = get_edge(i);\n        }\n      \
    \  return result;\n    }\n    std::pair<Cap, Cost> flow(int s, int t) {\n    \
    \    return flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n        return slope(s, t, flow_limit).back();\n\
    \    }\n    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n        return\
    \ slope(s, t, std::numeric_limits<Cap>::max());\n    }\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n\
    \        assert(0 <= t && t < _n);\n        assert(s != t);\n        // variants\
    \ (C = maxcost):\n        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n  \
    \      // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge\n\
    \        std::vector<Cost> dual(_n, 0), dist(_n);\n        std::vector<int> pv(_n),\
    \ pe(_n);\n        std::vector<bool> vis(_n);\n        auto dual_ref = [&]() {\n\
    \            std::fill(dist.begin(), dist.end(),\n                      std::numeric_limits<Cost>::max());\n\
    \            std::fill(pv.begin(), pv.end(), -1);\n            std::fill(pe.begin(),\
    \ pe.end(), -1);\n            std::fill(vis.begin(), vis.end(), false);\n    \
    \        struct Q {\n                Cost key;\n                int to;\n    \
    \            bool operator<(Q r) const { return key > r.key; }\n            };\n\
    \            std::priority_queue<Q> que;\n            dist[s] = 0;\n         \
    \   que.push(Q{0, s});\n            while (!que.empty()) {\n                int\
    \ v = que.top().to;\n                que.pop();\n                if (vis[v]) continue;\n\
    \                vis[v] = true;\n                if (v == t) break;\n        \
    \        // dist[v] = shortest(s, v) + dual[s] - dual[v]\n                // dist[v]\
    \ >= 0 (all reduced cost are positive)\n                // dist[v] <= (n-1)C\n\
    \                for (int i = 0; i < int(g[v].size()); i++) {\n              \
    \      auto e = g[v][i];\n                    if (vis[e.to] || !e.cap) continue;\n\
    \                    // |-dual[e.to] + dual[v]| <= (n-1)C\n                  \
    \  // cost <= C - -(n-1)C + 0 = nC\n                    Cost cost = e.cost - dual[e.to]\
    \ + dual[v];\n                    if (dist[e.to] - dist[v] > cost) {\n       \
    \                 dist[e.to] = dist[v] + cost;\n                        pv[e.to]\
    \ = v;\n                        pe[e.to] = i;\n                        que.push(Q{dist[e.to],\
    \ e.to});\n                    }\n                }\n            }\n         \
    \   if (!vis[t]) {\n                return false;\n            }\n           \
    \ for (int v = 0; v < _n; v++) {\n                if (!vis[v]) continue;\n   \
    \             // dual[v] = dual[v] - dist[t] + dist[v]\n                //   \
    \      = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s]\
    \ - dual[v])\n                //         = - shortest(s, t) + dual[t] + shortest(s,\
    \ v)\n                //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C\n\
    \                dual[v] -= dist[t] - dist[v];\n            }\n            return\
    \ true;\n        };\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        std::vector<std::pair<Cap, Cost>> result;\n        result.push_back({flow,\
    \ cost});\n        while (flow < flow_limit) {\n            if (!dual_ref()) break;\n\
    \            Cap c = flow_limit - flow;\n            for (int v = t; v != s; v\
    \ = pv[v]) {\n                c = std::min(c, g[pv[v]][pe[v]].cap);\n        \
    \    }\n            for (int v = t; v != s; v = pv[v]) {\n                auto&\
    \ e = g[pv[v]][pe[v]];\n                e.cap -= c;\n                g[v][e.rev].cap\
    \ += c;\n            }\n            Cost d = -dual[s];\n            flow += c;\n\
    \            cost += c * d;\n            if (prev_cost_per_flow == d) {\n    \
    \            result.pop_back();\n            }\n            result.push_back({flow,\
    \ cost});\n            prev_cost_per_flow = d;\n        }\n        return result;\n\
    \    }\n  private:\n    int _n;\n    struct _edge {\n        int to, rev;\n  \
    \      Cap cap;\n        Cost cost;\n    };\n    std::vector<std::pair<int, int>>\
    \ pos;\n    std::vector<std::vector<_edge>> g;\n};\n}  // namespace atcoder\n\
    #line 1336 \"util/ACL.hpp\"\nnamespace atcoder {\nnamespace internal {\ntemplate\
    \ <class E> struct csr {\n    std::vector<int> start;\n    std::vector<E> elist;\n\
    \    csr(int n, const std::vector<std::pair<int, E>>& edges)\n        : start(n\
    \ + 1), elist(edges.size()) {\n        for (auto e : edges) {\n            start[e.first\
    \ + 1]++;\n        }\n        for (int i = 1; i <= n; i++) {\n            start[i]\
    \ += start[i - 1];\n        }\n        auto counter = start;\n        for (auto\
    \ e : edges) {\n            elist[counter[e.first]++] = e.second;\n        }\n\
    \    }\n};\n// Reference:\n// R. Tarjan,\n// Depth-First Search and Linear Graph\
    \ Algorithms\nstruct scc_graph {\n  public:\n    scc_graph(int n) : _n(n) {}\n\
    \    int num_vertices() { return _n; }\n    void add_edge(int from, int to) {\
    \ edges.push_back({from, {to}}); }\n    // @return pair of (# of scc, scc id)\n\
    \    std::pair<int, std::vector<int>> scc_ids() {\n        auto g = csr<edge>(_n,\
    \ edges);\n        int now_ord = 0, group_num = 0;\n        std::vector<int> visited,\
    \ low(_n), ord(_n, -1), ids(_n);\n        visited.reserve(_n);\n        auto dfs\
    \ = [&](auto self, int v) -> void {\n            low[v] = ord[v] = now_ord++;\n\
    \            visited.push_back(v);\n            for (int i = g.start[v]; i < g.start[v\
    \ + 1]; i++) {\n                auto to = g.elist[i].to;\n                if (ord[to]\
    \ == -1) {\n                    self(self, to);\n                    low[v] =\
    \ std::min(low[v], low[to]);\n                } else {\n                    low[v]\
    \ = std::min(low[v], ord[to]);\n                }\n            }\n           \
    \ if (low[v] == ord[v]) {\n                while (true) {\n                  \
    \  int u = visited.back();\n                    visited.pop_back();\n        \
    \            ord[u] = _n;\n                    ids[u] = group_num;\n         \
    \           if (u == v) break;\n                }\n                group_num++;\n\
    \            }\n        };\n        for (int i = 0; i < _n; i++) {\n         \
    \   if (ord[i] == -1) dfs(dfs, i);\n        }\n        for (auto& x : ids) {\n\
    \            x = group_num - 1 - x;\n        }\n        return {group_num, ids};\n\
    \    }\n    std::vector<std::vector<int>> scc() {\n        auto ids = scc_ids();\n\
    \        int group_num = ids.first;\n        std::vector<int> counts(group_num);\n\
    \        for (auto x : ids.second) counts[x]++;\n        std::vector<std::vector<int>>\
    \ groups(ids.first);\n        for (int i = 0; i < group_num; i++) {\n        \
    \    groups[i].reserve(counts[i]);\n        }\n        for (int i = 0; i < _n;\
    \ i++) {\n            groups[ids.second[i]].push_back(i);\n        }\n       \
    \ return groups;\n    }\n  private:\n    int _n;\n    struct edge {\n        int\
    \ to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n};\n}  // namespace\
    \ internal\n}  // namespace atcoder\n#line 1425 \"util/ACL.hpp\"\nnamespace atcoder\
    \ {\nstruct scc_graph {\n  public:\n    scc_graph() : internal(0) {}\n    scc_graph(int\
    \ n) : internal(n) {}\n    void add_edge(int from, int to) {\n        int n =\
    \ internal.num_vertices();\n        assert(0 <= from && from < n);\n        assert(0\
    \ <= to && to < n);\n        internal.add_edge(from, to);\n    }\n    std::vector<std::vector<int>>\
    \ scc() { return internal.scc(); }\n  private:\n    internal::scc_graph internal;\n\
    };\n}  // namespace atcoder\n#line 1444 \"util/ACL.hpp\"\nnamespace atcoder {\n\
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n    segtree()\
    \ : segtree(0) {}\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n \
    \   segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        return d[p + size];\n    }\n\
    \    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n  \
    \      S sml = e(), smr = e();\n        l += size;\n        r += size;\n     \
    \   while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n         \
    \   if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return op(sml, smr);\n    }\n    S all_prod() { return\
    \ d[1]; }\n    template <bool (*f)(S)> int max_right(int l) {\n        return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n    template <class F> int max_right(int\
    \ l, F f) {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n   \
    \     if (l == _n) return _n;\n        l += size;\n        S sm = e();\n     \
    \   do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l])))\
    \ {\n                while (l < size) {\n                    l = (2 * l);\n  \
    \                  if (f(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return _n;\n\
    \    }\n    template <bool (*f)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return f(x); });\n    }\n    template <class F> int min_left(int r,\
    \ F f) {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        S sm = e();\n        do\
    \ {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n       \
    \     if (!f(op(d[r], sm))) {\n                while (r < size) {\n          \
    \          r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n    \
    \                    sm = op(d[r], sm);\n                        r--;\n      \
    \              }\n                }\n                return r + 1 - size;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n}  //\
    \ namespace atcoder\n#line 1545 \"util/ACL.hpp\"\nnamespace atcoder {\nnamespace\
    \ internal {\nstd::vector<int> sa_naive(const std::vector<int>& s) {\n    int\
    \ n = int(s.size());\n    std::vector<int> sa(n);\n    std::iota(sa.begin(), sa.end(),\
    \ 0);\n    std::sort(sa.begin(), sa.end(), [&](int l, int r) {\n        if (l\
    \ == r) return false;\n        while (l < n && r < n) {\n            if (s[l]\
    \ != s[r]) return s[l] < s[r];\n            l++;\n            r++;\n        }\n\
    \        return l == n;\n    });\n    return sa;\n}\nstd::vector<int> sa_doubling(const\
    \ std::vector<int>& s) {\n    int n = int(s.size());\n    std::vector<int> sa(n),\
    \ rnk = s, tmp(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    for (int k =\
    \ 1; k < n; k *= 2) {\n        auto cmp = [&](int x, int y) {\n            if\
    \ (rnk[x] != rnk[y]) return rnk[x] < rnk[y];\n            int rx = x + k < n ?\
    \ rnk[x + k] : -1;\n            int ry = y + k < n ? rnk[y + k] : -1;\n      \
    \      return rx < ry;\n        };\n        std::sort(sa.begin(), sa.end(), cmp);\n\
    \        tmp[sa[0]] = 0;\n        for (int i = 1; i < n; i++) {\n            tmp[sa[i]]\
    \ = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        std::swap(tmp,\
    \ rnk);\n    }\n    return sa;\n}\n// SA-IS, linear-time suffix array construction\n\
    // Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n// Two Efficient Algorithms\
    \ for Linear Time Suffix Array Construction\ntemplate <int THRESHOLD_NAIVE = 10,\
    \ int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n    int n = int(s.size());\n    if (n == 0) return {};\n  \
    \  if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0] < s[1]) {\n  \
    \          return {0, 1};\n        } else {\n            return {1, 0};\n    \
    \    }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n \
    \   }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n   \
    \ }\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int i\
    \ = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i]\
    \ < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);\n\
    \    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n            sum_s[s[i]]++;\n\
    \        } else {\n            sum_l[s[i] + 1]++;\n        }\n    }\n    for (int\
    \ i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n        if (i < upper)\
    \ sum_l[i + 1] += sum_s[i];\n    }\n    auto induce = [&](const std::vector<int>&\
    \ lms) {\n        std::fill(sa.begin(), sa.end(), -1);\n        std::vector<int>\
    \ buf(upper + 1);\n        std::copy(sum_s.begin(), sum_s.end(), buf.begin());\n\
    \        for (auto d : lms) {\n            if (d == n) continue;\n           \
    \ sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(), sum_l.end(),\
    \ buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for (int i = 0;\
    \ i < n; i++) {\n            int v = sa[i];\n            if (v >= 1 && !ls[v -\
    \ 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n            }\n       \
    \ }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n        for\
    \ (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n            if (v\
    \ >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] = v - 1;\n   \
    \         }\n        }\n    };\n    std::vector<int> lms_map(n + 1, -1);\n   \
    \ int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i - 1] && ls[i])\
    \ {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int> lms;\n\
    \    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i - 1]\
    \ && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n    induce(lms);\n\
    \    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n}  // namespace internal\nstd::vector<int> suffix_array(const std::vector<int>&\
    \ s, int upper) {\n    assert(0 <= upper);\n    for (int d : s) {\n        assert(0\
    \ <= d && d <= upper);\n    }\n    auto sa = internal::sa_is(s, upper);\n    return\
    \ sa;\n}\ntemplate <class T> std::vector<int> suffix_array(const std::vector<T>&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int l, int r) { return\
    \ s[l] < s[r]; });\n    std::vector<int> s2(n);\n    int now = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) now++;\n\
    \        s2[idx[i]] = now;\n    }\n    return internal::sa_is(s2, now);\n}\nstd::vector<int>\
    \ suffix_array(const std::string& s) {\n    int n = int(s.size());\n    std::vector<int>\
    \ s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n  \
    \  return internal::sa_is(s2, 255);\n}\n// Reference:\n// T. Kasai, G. Lee, H.\
    \ Arimura, S. Arikawa, and K. Park,\n// Linear-Time Longest-Common-Prefix Computation\
    \ in Suffix Arrays and Its\n// Applications\ntemplate <class T>\nstd::vector<int>\
    \ lcp_array(const std::vector<T>& s,\n                           const std::vector<int>&\
    \ sa) {\n    int n = int(s.size());\n    assert(n >= 1);\n    std::vector<int>\
    \ rnk(n);\n    for (int i = 0; i < n; i++) {\n        rnk[sa[i]] = i;\n    }\n\
    \    std::vector<int> lcp(n - 1);\n    int h = 0;\n    for (int i = 0; i < n;\
    \ i++) {\n        if (h > 0) h--;\n        if (rnk[i] == 0) continue;\n      \
    \  int j = sa[rnk[i] - 1];\n        for (; j + h < n && i + h < n; h++) {\n  \
    \          if (s[j + h] != s[i + h]) break;\n        }\n        lcp[rnk[i] - 1]\
    \ = h;\n    }\n    return lcp;\n}\nstd::vector<int> lcp_array(const std::string&\
    \ s, const std::vector<int>& sa) {\n    int n = int(s.size());\n    std::vector<int>\
    \ s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n  \
    \  return lcp_array(s2, sa);\n}\n// Reference:\n// D. Gusfield,\n// Algorithms\
    \ on Strings, Trees, and Sequences: Computer Science and\n// Computational Biology\n\
    template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {\n \
    \   int n = int(s.size());\n    if (n == 0) return {};\n    std::vector<int> z(n);\n\
    \    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n\
    \        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n       \
    \ while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i + z[i])\
    \ j = i;\n    }\n    z[0] = n;\n    return z;\n}\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n\
    \    for (int i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n}  // namespace atcoder\n#line 1791 \"util/ACL.hpp\"\nnamespace atcoder {\n\
    // Reference:\n// B. Aspvall, M. Plass, and R. Tarjan,\n// A Linear-Time Algorithm\
    \ for Testing the Truth of Certain Quantified Boolean\n// Formulas\nstruct two_sat\
    \ {\n  public:\n    two_sat() : _n(0), scc(0) {}\n    two_sat(int n) : _n(n),\
    \ _answer(n), scc(2 * n) {}\n    void add_clause(int i, bool f, int j, bool g)\
    \ {\n        assert(0 <= i && i < _n);\n        assert(0 <= j && j < _n);\n  \
    \      scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n        scc.add_edge(2\
    \ * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n    bool satisfiable() {\n\
    \        auto id = scc.scc_ids().second;\n        for (int i = 0; i < _n; i++)\
    \ {\n            if (id[2 * i] == id[2 * i + 1]) return false;\n            _answer[i]\
    \ = id[2 * i] < id[2 * i + 1];\n        }\n        return true;\n    }\n    std::vector<bool>\
    \ answer() { return _answer; }\n  private:\n    int _n;\n    std::vector<bool>\
    \ _answer;\n    internal::scc_graph scc;\n};\n}  // namespace atcoder\n#line 1\
    \ \"math/ceil_pow2.hpp\"\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U\
    \ << x) < (unsigned int)(n)) x++;\n    return x;\n}\n#line 1 \"math/mod_pow.hpp\"\
    \n/**\n * @brief (x^y)%mod\n */\n\nlong long mod_pow(long long x,long long y,long\
    \ long mod){\n    long long ret=1;\n    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n\
    \        (x*=x)%=mod;\n        y>>=1;\n    }\n    return ret;\n}\n#line 4 \"math/garner.hpp\"\
    \n\n/**\n * \n * @brief \u30AC\u30FC\u30CA\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\n *\n */\n\nlong long garner(std::vector<long long>a,std::vector<long\
    \ long>mods){\n    const int sz=3;\n    long long coeffs[sz+1]={1,1,1,1};\n  \
    \  long long constants[sz+1]={};\n    for(int i=0;i<sz;i++){\n        long long\
    \ v=(mods[i]+a[i]-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];\n\
    \        for(int j=i+1;j<sz+1;j++) {\n            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];\n\
    \            coeffs[j]=(coeffs[j]*mods[i])%mods[j];\n        }\n    }\n    return\
    \ constants[3];\n}\n#line 6 \"math/FPS_mint.hpp\"\n/**\n * @brief \u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570(ModInt)\n */\n\ntemplate<typename Mint>\nstruct _FPS{\n\
    \    template<typename T>\n    T operator()(const T& _s,const T& _t){\n      \
    \  if(_s.size()==0||_t.size()==0)return T();\n        const size_t sz=_s.size()+_t.size()-1;\n\
    \        if((Mint::get_mod()&((1<<ceil_pow2(sz))-1))==1){\n            std::vector<atcoder::static_modint<Mint::get_mod()>>s(_s.size()),t(_t.size());\n\
    \            for(size_t i=0;i<_s.size();++i)s[i]=_s[i].value();\n            for(size_t\
    \ i=0;i<_t.size();++i)t[i]=_t[i].value();\n            std::vector<atcoder::static_modint<Mint::get_mod()>>\
    \ _v=atcoder::convolution(s,t);\n            T v(_v.size());\n            for\
    \ (size_t i=0;i<_v.size();++i)v[i]=_v[i].val();\n            return v;\n     \
    \   }else{\n            std::vector<atcoder::static_modint<1224736769>>s1(_s.size()),t1(_t.size());\n\
    \            std::vector<atcoder::static_modint<1045430273>>s2(_s.size()),t2(_t.size());\n\
    \            std::vector<atcoder::static_modint<1007681537>>s3(_s.size()),t3(_t.size());\n\
    \            for(size_t i=0;i<_s.size();++i){\n                s1[i]=_s[i].value();\n\
    \                s2[i]=_s[i].value();\n                s3[i]=_s[i].value();\n\
    \            }\n            for(size_t i=0;i<_t.size();++i){\n               \
    \ t1[i]=_t[i].value();\n                t2[i]=_t[i].value();\n               \
    \ t3[i]=_t[i].value();\n            }\n            auto v1=atcoder::convolution(s1,t1);\n\
    \            auto v2=atcoder::convolution(s2,t2);\n            auto v3=atcoder::convolution(s3,t3);\n\
    \            T v(sz);\n            for(size_t i=0;i<sz;++i){\n               \
    \ v[i]=garner(std::vector<long long>{v1[i].val(),v2[i].val(),v3[i].val()},std::vector<long\
    \ long>{1224736769,1045430273,1007681537,Mint::get_mod()});\n            }\n \
    \           return v;\n        }\n    }\n    template<typename T>\n    T fact(const\
    \ T& s){\n        return s.fact();\n    }\n    template<typename T>\n    T pow(const\
    \ T& s,long long i){\n        return s.pow(i);\n    }\n};\ntemplate<typename Mint>using\
    \ fps=FPS_BASE<Mint,_FPS<Mint>>;\n#line 5 \"math/test/LC_convolution_998244353.test.cpp\"\
    \n\nint main(){\n    lint n,m;\n    cin>>n>>m;\n    fps<mint> a(n),b(m);\n   \
    \ rep(i,n)cin>>a[i];\n    rep(i,m)cin>>b[i];\n    output(a*b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"../../util/template.hpp\"\n#include \"../../math/mod_int998244353.hpp\"\n\
    #include \"../FPS_mint.hpp\"\n\nint main(){\n    lint n,m;\n    cin>>n>>m;\n \
    \   fps<mint> a(n),b(m);\n    rep(i,n)cin>>a[i];\n    rep(i,m)cin>>b[i];\n   \
    \ output(a*b);\n}"
  dependsOn:
  - util/template.hpp
  - math/mod_int998244353.hpp
  - math/mod_int.hpp
  - math/FPS_mint.hpp
  - math/FPS_base.hpp
  - util/ACL.hpp
  - math/ceil_pow2.hpp
  - math/garner.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: math/test/LC_convolution_998244353.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 18:26:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: math/test/LC_convolution_998244353.test.cpp
layout: document
redirect_from:
- /verify/math/test/LC_convolution_998244353.test.cpp
- /verify/math/test/LC_convolution_998244353.test.cpp.html
title: math/test/LC_convolution_998244353.test.cpp
---
