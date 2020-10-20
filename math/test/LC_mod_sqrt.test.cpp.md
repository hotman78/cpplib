---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  - icon: ':x:'
    path: math/mod_sqrt.hpp
    title: ModSqrt
  - icon: ':x:'
    path: util/random_gen.hpp
    title: util/random_gen.hpp
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"math/test/LC_mod_sqrt.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n#line 1 \"math/mod_sqrt.hpp\"\n#include<tuple>\n#line 1 \"math/mod_pow.hpp\"\
    \n/**\n * @brief (x^y)%mod\n */\n\nlong long mod_pow(long long x,long long y,long\
    \ long mod){\n    long long ret=1;\n    while(y>0) {\n        if(y&1)(ret*=x)%=mod;\n\
    \        (x*=x)%=mod;\n        y>>=1;\n    }\n    return ret;\n}\n#line 2 \"util/random_gen.hpp\"\
    \n#include<random>\n#include<chrono>\n\nstruct RandomNumberGenerator {\n    std::mt19937\
    \ mt;\n    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    int operator()(int a, int b) { // [a, b)\n        std::uniform_int_distribution<\
    \ int > dist(a, b - 1);\n        return dist(mt);\n    }\n\n    int operator()(int\
    \ b) { // [0, b)\n        return (*this)(0, b);\n    }\n};\n#line 4 \"math/mod_sqrt.hpp\"\
    \n\n/**\n * @brief ModSqrt\n */\n\nlong long mod_sqrt(long long a,long long mod){\n\
    \    if(mod==2||a==0)return a;\n    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;\n\
    \    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);\n    long long q=(mod-1),s=0;\n\
    \    while(q%2==0)q/=2,s++;\n    long long z=1;\n    RandomNumberGenerator rnd;\n\
    \    while(mod_pow(z=rnd(0,mod),(mod-1)/2,mod)!=mod-1);\n    long long c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;\n\
    \    while(m>1){\n        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;\n   \
    \     else std::tie(c,t,r,m)=std::make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);\n\
    \    }\n    return r%mod;\n}\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n\
    #include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\n#line 4 \"math/test/LC_mod_sqrt.test.cpp\"\
    \n\nint main(){\n    lint t;\n    cin>>t;\n    while(t--){\n        lint y,p;\n\
    \        cin>>y>>p;\n        cout<<mod_sqrt(y,p)<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include \"\
    ../mod_sqrt.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n    lint\
    \ t;\n    cin>>t;\n    while(t--){\n        lint y,p;\n        cin>>y>>p;\n  \
    \      cout<<mod_sqrt(y,p)<<endl;\n    }\n}"
  dependsOn:
  - math/mod_sqrt.hpp
  - math/mod_pow.hpp
  - util/random_gen.hpp
  - util/template.hpp
  isVerificationFile: true
  path: math/test/LC_mod_sqrt.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: math/test/LC_mod_sqrt.test.cpp
layout: document
redirect_from:
- /verify/math/test/LC_mod_sqrt.test.cpp
- /verify/math/test/LC_mod_sqrt.test.cpp.html
title: math/test/LC_mod_sqrt.test.cpp
---
