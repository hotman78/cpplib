---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binary_search.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
  bundledCode: "#line 1 \"math/test/AOJ_binary_search.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\n#line\
    \ 2 \"math/binary_search.hpp\"\n#include<functional>\n/**\n * @brief \u4E8C\u5206\
    \u63A2\u7D22\n */\ntemplate<typename F>\nlong long bs(long long mn,long long mx,F\
    \ func){\n    mn--;\n    mx++;\n\twhile(mx-mn>1){\n\t\tlong long mid=(mn+mx)/2;\n\
    \t\tif(!func(mid))mx=mid;\n\t\telse mn=mid;\n\t}\n    return mn;\n}\n#line 2 \"\
    util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\n#line 4 \"math/test/AOJ_binary_search.test.cpp\"\
    \n\nint main(){\n    lint n,q;\n    cin>>n;\n    vec a(n);\n    rep(i,n)cin>>a[i];\n\
    \    cin>>q;\n    lint ans=0;\n    rep(i,q){\n        lint x;\n        cin>>x;\n\
    \        lint t=bs(0,n-1,[&](lint i){return a[i]<=x;});\n        if(t!=-1&&a[t]==x){\n\
    \            ans++;\n        }\n    }\n    cout<<ans<<endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n#include \"../binary_search.hpp\"\n#include \"../../util/template.hpp\"\n\n\
    int main(){\n    lint n,q;\n    cin>>n;\n    vec a(n);\n    rep(i,n)cin>>a[i];\n\
    \    cin>>q;\n    lint ans=0;\n    rep(i,q){\n        lint x;\n        cin>>x;\n\
    \        lint t=bs(0,n-1,[&](lint i){return a[i]<=x;});\n        if(t!=-1&&a[t]==x){\n\
    \            ans++;\n        }\n    }\n    cout<<ans<<endl;\n}"
  dependsOn:
  - math/binary_search.hpp
  - util/template.hpp
  isVerificationFile: true
  path: math/test/AOJ_binary_search.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/AOJ_binary_search.test.cpp
layout: document
redirect_from:
- /verify/math/test/AOJ_binary_search.test.cpp
- /verify/math/test/AOJ_binary_search.test.cpp.html
title: math/test/AOJ_binary_search.test.cpp
---
