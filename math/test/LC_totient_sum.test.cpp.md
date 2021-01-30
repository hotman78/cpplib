---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_int.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: math/mod_int998244353.hpp
    title: ModInt(998'244'353)
  - icon: ':heavy_check_mark:'
    path: math/totient_sum.hpp
    title: "\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\u306E\u548C"
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"math/test/LC_totient_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/sum_of_totient_function\"\n#line 2 \"math/totient_sum.hpp\"\
    \n#include<map>\n\n/**\n * @brief \u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\u6570\
    \u306E\u548C\n */\n\ntemplate<typename T>\nT totient_sum(long long n){\n    static\
    \ std::map<long long,T> m2;\n    static bool init=1;\n    static long long* m=new\
    \ long long[10000000]();\n    if(init){\n        init=0;\n        long long k=1e7;\n\
    \        for(long long i=1;i<=k;i++)m[i]=i;\n        for(long long i=1;i<=k;i++)for(long\
    \ long j=i*2;j<=k;j+=i)m[j]-=m[i];\n        for(long long i=1;i<k;i++)m[i+1]+=m[i];\n\
    \    }\n    if(n<1e7)return m[n];\n    else if(m2.count(n))return m2[n];\n   \
    \ T ans=T(n)*(n+1)/2;\n    long long mx=0;\n    for(long long i=1;i*i<n;i++){\n\
    \        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);\n        mx=n/(i+1)+1;\n    }\n\
    \    for(long long i=2;i<mx;i++){\n        ans-=totient_sum<T>(n/i);\n    }\n\
    \    return m2[n]=ans;\n}\n#line 2 \"math/mod_int.hpp\"\n#include<cstdint>\n#include<iostream>\n\
    #include<vector>\n\n/**\n * @brief ModInt\n */\n\ntemplate<int MOD>\nstruct mod_int\
    \ {\n    using mint=mod_int<MOD>;\n    using u64 = std::uint_fast64_t;\n    u64\
    \ a;\n    constexpr mod_int(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n\
    \    constexpr u64 &value()noexcept{return a;}\n    constexpr const u64 &value()\
    \ const noexcept {return a;}\n    constexpr mint operator+(const mint rhs)const\
    \ noexcept{return mint(*this) += rhs;}\n    constexpr mint operator-(const mint\
    \ rhs)const noexcept{return mint(*this)-=rhs;}\n    constexpr mint operator*(const\
    \ mint rhs) const noexcept {return mint(*this) *= rhs;}\n    constexpr mint operator/(const\
    \ mint rhs) const noexcept {return mint(*this) /= rhs;}\n    constexpr mint &operator+=(const\
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
    \    }\n    mint comb(long long b){\n        if(init)build();\n        if(a<0||b<0)return\
    \ 0;\n        if(a==0&&b==0)return 1;\n        if((long long)a<b)return 0;\n \
    \       return fac[a]*ifac[a-b]*ifac[b];\n    }\n    mint fact()const{\n     \
    \   if(init)build();\n        return fac[a];\n    }\n    mint fact_inv()const{\n\
    \        if(init)build();\n        return ifac[a];\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& lhs, const mint& rhs) noexcept {\n        lhs << rhs.a;\n\
    \        return lhs;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n        return lhs;\n    }\n\
    \    constexpr static bool is_static=true;\n    constexpr static u64 get_mod(){\n\
    \        return MOD;\n    }\n};\ntemplate<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;\n\
    template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;\ntemplate<int MOD>bool\
    \ mod_int<MOD>::init=1;\n#line 3 \"math/mod_int998244353.hpp\"\nusing mint=mod_int<998'244'353>;\n\
    \n/**\n * @brief ModInt(998'244'353)\n */\n#line 2 \"util/template.hpp\"\n#pragma\
    \ GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC\
    \ target(\"avx2\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
    typedef long long lint;\n#define INF (1LL<<60)\n#define IINF (1<<30)\n#define\
    \ EPS (1e-10)\n#define endl ('\\n')\ntypedef vector<lint> vec;\ntypedef vector<vector<lint>>\
    \ mat;\ntypedef vector<vector<vector<lint>>> mat3;\ntypedef vector<string> svec;\n\
    typedef vector<vector<string>> smat;\ntemplate<typename T>using V=vector<T>;\n\
    template<typename T>using VV=V<V<T>>;\ntemplate<typename T>inline void output(T\
    \ t){bool f=0;for(auto i:t){cout<<(f?\" \":\"\")<<i;f=1;}cout<<endl;}\ntemplate<typename\
    \ T>inline void output2(T t){for(auto i:t)output(i);}\ntemplate<typename T>inline\
    \ void debug(T t){bool f=0;for(auto i:t){cerr<<(f?\" \":\"\")<<i;f=1;}cerr<<endl;}\n\
    template<typename T>inline void debug2(T t){for(auto i:t)output(i);}\n#define\
    \ loop(n) for(long long _=0;_<(long long)(n);++_)\n#define _overload4(_1,_2,_3,_4,name,...)\
    \ name\n#define __rep(i,a) repi(i,0,a,1)\n#define _rep(i,a,b) repi(i,a,b,1)\n\
    #define repi(i,a,b,c) for(long long i=(long long)(a);i<(long long)(b);i+=c)\n\
    #define rep(...) _overload4(__VA_ARGS__,repi,_rep,__rep)(__VA_ARGS__)\n#define\
    \ _overload3_rev(_1,_2,_3,name,...) name\n#define _rep_rev(i,a) repi_rev(i,0,a)\n\
    #define repi_rev(i,a,b) for(long long i=(long long)(b)-1;i>=(long long)(a);--i)\n\
    #define rrep(...) _overload3_rev(__VA_ARGS__,repi_rev,_rep_rev)(__VA_ARGS__)\n\
    \n// #define rep(i,...) for(auto i:range(__VA_ARGS__)) \n// #define rrep(i,...)\
    \ for(auto i:reversed(range(__VA_ARGS__)))\n// #define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)\n\
    // #define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)\n// #define irep(i)\
    \ for(lint i=0;;++i)\n// inline vector<long long> range(long long n){if(n<=0)return\
    \ vector<long long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return\
    \ v;}\n// inline vector<long long> range(long long a,long long b){if(b<=a)return\
    \ vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
    \ v;}\n// inline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\n// template<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n#define\
    \ extrep(v,...) for(auto v:__MAKE_MAT__({__VA_ARGS__}))\n#define bit(n,a) ((n>>a)&1)\n\
    vector<vector<long long>> __MAKE_MAT__(vector<long long> v){if(v.empty())return\
    \ vector<vector<long long>>(1,vector<long long>());long long n=v.back();v.pop_back();vector<vector<long\
    \ long>> ret;vector<vector<long long>> tmp=__MAKE_MAT__(v);for(auto e:tmp)for(long\
    \ long i=0;i<n;++i){ret.push_back(e);ret.back().push_back(i);}return ret;}\nusing\
    \ graph=vector<vector<int>>;\ntemplate<typename T>using graph_w=vector<vector<pair<int,T>>>;\n\
    template<typename T,typename E>ostream& operator<<(ostream& out,pair<T,E>v){out<<\"\
    (\"<<v.first<<\",\"<<v.second<<\")\";return out;}\nconstexpr inline long long\
    \ powll(long long a,long long b){long long res=1;while(b--)res*=a;return res;}\n\
    #line 5 \"math/test/LC_totient_sum.test.cpp\"\n\nint main(){\n    lint n;\n  \
    \  cin>>n;\n    cout<<totient_sum<mint>(n)<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include \"../totient_sum.hpp\"\n#include \"../mod_int998244353.hpp\"\n#include\
    \ \"../../util/template.hpp\"\n\nint main(){\n    lint n;\n    cin>>n;\n    cout<<totient_sum<mint>(n)<<endl;\n\
    }"
  dependsOn:
  - math/totient_sum.hpp
  - math/mod_int998244353.hpp
  - math/mod_int.hpp
  - util/template.hpp
  isVerificationFile: true
  path: math/test/LC_totient_sum.test.cpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/LC_totient_sum.test.cpp
layout: document
redirect_from:
- /verify/math/test/LC_totient_sum.test.cpp
- /verify/math/test/LC_totient_sum.test.cpp.html
title: math/test/LC_totient_sum.test.cpp
---
