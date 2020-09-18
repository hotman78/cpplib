---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570(ModLog)"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: (x^y)%mod
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"math/test/LC_mod_log.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#line 1 \"math/mod_pow.hpp\"\n/**\n * @brief (x^y)%mod\n */\n\nlong long mod_pow(long\
    \ long x,long long y,long long mod){\n    long long ret=1;\n    while(y>0) {\n\
    \        if(y&1)(ret*=x)%=mod;\n        (x*=x)%=mod;\n        y>>=1;\n    }\n\
    \    return ret;\n}\n#line 1 \"math/euler_phi.hpp\"\n/**\n * @brief \u30AA\u30A4\
    \u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\n */\n\nlong long euler_phi(long\
    \ long n) {\n    long long ret = n;\n    for(long long i=2;i*i<=n;i++) {\n   \
    \     if(n%i==0) {\n            ret-=ret/i;\n            while(n%i==0)n/=i;\n\
    \        }\n    }\n    if(n>1)ret-=ret/n;\n    return ret;\n}\n#line 4 \"math/mod_log.hpp\"\
    \n#include<map>\n#include<numeric>\n#include<cmath>\n\n/**\n * @brief \u96E2\u6563\
    \u5BFE\u6570(ModLog)\n */\n\nlong long mod_log(long long x,long long y,long long\
    \ m){\n    if(1==y||(x==0&&y==0&&m==1))return 0;\n    if(x==0){\n        if(y==1)return\
    \ 0;\n        if(y==0)return 1;\n        else return -1;\n    }\n    long long\
    \ _x=x,_y=y;\n    long long g=m;\n    long long cnt=0;\n    while(std::gcd(x,m)!=1)m/=std::gcd(x,m),cnt++;\n\
    \    g/=m;\n    x%=m;\n    y%=m;\n    std::map<long long,long long>b;\n    long\
    \ long B=std::sqrt(m*g)+1;\n    long long phi=euler_phi(m);\n    long long a=mod_pow(x,B-1,m);\n\
    \    long long inv_x=mod_pow(x,phi-1,m);\n    for(long long i=B-1;i>=cnt;--i){\n\
    \        b[a]=i;\n        a=a*inv_x%m;\n    }\n    long long A=mod_pow(x,B*(phi-1),m);\n\
    \    long long A2=y;\n    for(long long i=0;i<B;++i){\n        for(long long j=0;j<cnt;++j)if(mod_pow(_x,i*B+j,m*g)==_y)return\
    \ i*B+j;\n        if(b.count(A2)){\n            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return\
    \ i*B+b[A2];\n        }\n        A2=A2*A%m;\n    }\n    return -1;\n}\n#line 2\
    \ \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
    typedef long long lint;\n#define INF (1LL<<60)\n#define IINF (1<<30)\n#define\
    \ EPS (1e-10)\n#define endl ('\\n')\ntypedef vector<lint> vec;\ntypedef vector<vector<lint>>\
    \ mat;\ntypedef vector<vector<vector<lint>>> mat3;\ntypedef vector<string> svec;\n\
    typedef vector<vector<string>> smat;\ntemplate<typename T>inline void numout(T\
    \ t){bool f=0;for(auto i:t){cout<<(f?\" \":\"\")<<i<INF/2?i:\"INF\";f=1;}cout<<endl;}\n\
    template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}\ntemplate<typename\
    \ T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?\" \":\"\")<<i;f=1;}cout<<endl;}\n\
    template<typename T>inline void output2(T t){for(auto i:t)output(i);}\ntemplate<typename\
    \ T>inline void _output(T t){bool f=0;for(lint i=0;i<t.size();i++){cout<<f?\"\"\
    :\" \"<<t[i];f=1;}cout<<endl;}\ntemplate<typename T>inline void _output2(T t){for(lint\
    \ i=0;i<t.size();i++)output(t[i]);}\n#define rep(i,...) for(auto i:range(__VA_ARGS__))\
    \ \n#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))\n#define repi(i,a,b)\
    \ for(lint i=lint(a);i<(lint)(b);++i)\n#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)\n\
    #define irep(i) for(lint i=0;;++i)\ninline vector<long long> range(long long n){if(n<=0)return\
    \ vector<long long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return\
    \ v;}\ninline vector<long long> range(long long a,long long b){if(b<=a)return\
    \ vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
    \ v;}\ninline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\ntemplate<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n#line\
    \ 4 \"math/test/LC_mod_log.test.cpp\"\n\nint main(){\n    lint t;\n    cin>>t;\n\
    \    while(t--){\n        lint x,y,p;\n        cin>>x>>y>>p;\n        cout<<mod_log(x,y,p)<<endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include \"../mod_log.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \    lint t;\n    cin>>t;\n    while(t--){\n        lint x,y,p;\n        cin>>x>>y>>p;\n\
    \        cout<<mod_log(x,y,p)<<endl;\n    }\n}"
  dependsOn:
  - math/mod_log.hpp
  - math/mod_pow.hpp
  - math/euler_phi.hpp
  - util/template.hpp
  isVerificationFile: true
  path: math/test/LC_mod_log.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 12:55:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/LC_mod_log.test.cpp
layout: document
redirect_from:
- /verify/math/test/LC_mod_log.test.cpp
- /verify/math/test/LC_mod_log.test.cpp.html
title: math/test/LC_mod_log.test.cpp
---