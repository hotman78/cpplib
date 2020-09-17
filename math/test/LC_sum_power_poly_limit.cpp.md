---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor_sum.hpp
    title: \sum_{i=0}^{n-1}\floor(a*i+b/c)
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"math/test/LC_sum_power_poly_limit.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n#line 2 \"math/floor_sum.hpp\"\n/**\n * @brief \\sum_{i=0}^{n-1}\\floor(a*i+b/c)\n\
    \ */\nlong long floor_sum(long long a,long long b,long long c,long long n){\n\
    \    long long tmp=b/c*n+a/c*n*(n-1)/2;\n    if(a%c==0){\n        return tmp;\n\
    \    }\n    long long next=(c-b%c+a%c-1)/(a%c);\n    if(next>=n){\n        return\
    \ tmp;\n    }\n    a%=c;\n    b=b%c+a*next;\n    n-=next;\n    return tmp+floor_sum(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);\n\
    }\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\n\
    using namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    #define irep(i) for(lint i=0;;++i)\ninline vector<long long> range(long long n){vector<long\
    \ long>v(n);iota(v.begin(),v.end(),0LL);return v;}\ninline vector<long long> range(long\
    \ long a,long long b){vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
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
    \ 4 \"math/test/LC_sum_power_poly_limit.cpp\"\n\nint main(){\n    int t;\n   \
    \ cin>>t;\n    while(t--){\n        lint n,a,b,c;\n        cin>>n>>c>>a>>b;\n\
    \        cout<<floor_sum(a,b,c,n)<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n#include \"../floor_sum.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \    int t;\n    cin>>t;\n    while(t--){\n        lint n,a,b,c;\n        cin>>n>>c>>a>>b;\n\
    \        cout<<floor_sum(a,b,c,n)<<endl;\n    }\n}"
  dependsOn:
  - math/floor_sum.hpp
  - util/template.hpp
  isVerificationFile: false
  path: math/test/LC_sum_power_poly_limit.cpp
  requiredBy: []
  timestamp: '2020-09-17 09:30:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/test/LC_sum_power_poly_limit.cpp
layout: document
redirect_from:
- /library/math/test/LC_sum_power_poly_limit.cpp
- /library/math/test/LC_sum_power_poly_limit.cpp.html
title: math/test/LC_sum_power_poly_limit.cpp
---
