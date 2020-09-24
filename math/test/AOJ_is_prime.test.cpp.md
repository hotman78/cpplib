---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"math/test/AOJ_is_prime.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#line 2 \"math/is_prime.hpp\"\n#include <initializer_list>\n/**\n * @brief \u7D20\
    \u6570\u5224\u5B9A(\u9AD8\u901F)\n */\nbool is_prime(long long n){\n    if(n<=1)return\
    \ 0;\n    if(n==2)return 1;\n    if(n%2==0)return 0;\n    long long s=0,d=n-1;\n\
    \    while(d%2)d/=2,s++;\n    auto mod_pow=[](__int128_t a,__int128_t b,__int128_t\
    \ n){\n        long long res=1;\n        while(b){\n            if(b%2)res=res*a%n;\n\
    \            a=a*a%n;\n            b/=2;\n        }\n        return (long long)(res);\n\
    \    };\n    for(long long e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n        if(n<=e)break;\n\
    \        if(mod_pow(e,d,n)==1)continue;\n        bool b=1;\n        for(int i=0;i<s;i++){\n\
    \            if(mod_pow(e,d<<i,n)==n-1)b=0;\n        }\n        if(b)return 0;\n\
    \    }\n    return 1;\n}\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n\
    #include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n//#include\
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"math/test/AOJ_is_prime.test.cpp\"\
    \n\nint main(){\n    lint t;\n    cin>>t;\n    lint ans=0;\n    while(t--){\n\
    \        lint n;\n        cin>>n;\n        ans+=is_prime(n);\n    }\n    cout<<ans<<endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include \"../is_prime.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \    lint t;\n    cin>>t;\n    lint ans=0;\n    while(t--){\n        lint n;\n\
    \        cin>>n;\n        ans+=is_prime(n);\n    }\n    cout<<ans<<endl;\n}"
  dependsOn:
  - math/is_prime.hpp
  - util/template.hpp
  isVerificationFile: true
  path: math/test/AOJ_is_prime.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: math/test/AOJ_is_prime.test.cpp
layout: document
redirect_from:
- /verify/math/test/AOJ_is_prime.test.cpp
- /verify/math/test/AOJ_is_prime.test.cpp.html
title: math/test/AOJ_is_prime.test.cpp
---
