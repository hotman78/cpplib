---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_factor.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)"
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  - icon: ':question:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"math/test/AOJ_prime_factor.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\n#line 2 \"\
    math/prime_factor.hpp\"\n#include<vector>\n#include<numeric>\n#include<cmath>\n\
    #include<algorithm>\n#line 2 \"math/is_prime.hpp\"\n#include <initializer_list>\n\
    /**\n * @brief \u7D20\u6570\u5224\u5B9A(\u9AD8\u901F)\n */\nbool is_prime(long\
    \ long n){\n    if(n<=1)return 0;\n    if(n==2)return 1;\n    if(n%2==0)return\
    \ 0;\n    long long s=0,d=n-1;\n    while(d%2)d/=2,s++;\n    auto mod_pow=[](__int128_t\
    \ a,__int128_t b,__int128_t n){\n        long long res=1;\n        while(b){\n\
    \            if(b%2)res=res*a%n;\n            a=a*a%n;\n            b/=2;\n  \
    \      }\n        return (long long)(res);\n    };\n    for(long long e:{2,3,5,7,11,13,17,19,23,29,31,37}){\n\
    \        if(n<=e)break;\n        if(mod_pow(e,d,n)==1)continue;\n        bool\
    \ b=1;\n        for(int i=0;i<s;i++){\n            if(mod_pow(e,d<<i,n)==n-1)b=0;\n\
    \        }\n        if(b)return 0;\n    }\n    return 1;\n}\n#line 7 \"math/prime_factor.hpp\"\
    \n\n/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3(\u9AD8\u901F)\n */\n\nvoid __prime_factor(long\
    \ long n,long long& c,std::vector<long long>& v){\n    if(n==1)return;\n    if(n%2==0){\n\
    \        v.emplace_back(2);\n        __prime_factor(n/2,c,v);\n        return;\n\
    \    }\n    if(is_prime(n)){\n        v.emplace_back(n);\n        return;\n  \
    \  }\n    while(1){\n        long long x=2,y=2,d=1;\n        while(d==1){\n  \
    \          x=((__int128_t)x*x+c)%n;\n            y=((__int128_t)y*y%n+c)%n;\n\
    \            y=((__int128_t)y*y%n+c)%n;\n            d=std::gcd(std::abs(x-y),n);\n\
    \        }\n        if(d==n){\n            c++;\n            continue;\n     \
    \   }\n        __prime_factor(d,c,v);\n        __prime_factor(n/d,c,v);\n    \
    \    return;\n    }\n}\n\nstd::vector<long long>prime_factor(long long n){\n \
    \   std::vector<long long>v;\n    long long c=1;\n    __prime_factor(n,c,v);\n\
    \    std::sort(v.begin(),v.end());\n    return v;\n}\n#line 2 \"util/template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ 5 \"graph_tree/graph_template.hpp\"\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\n\
    template<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
    \ngraph load_graph(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n\
    \        int s,t;\n        std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_digraph(int n,int\
    \ m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n    }\n    return g;\n}\ngraph\
    \ load_graph0(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n    \
    \    int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n\
    \    }\n    return g;\n}\ngraph load_digraph0(int n,int m){\n    graph g(n);\n\
    \    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n      \
    \  g[s].push_back(t);\n    }\n    return g;\n}\ngraph load_tree(int n){\n    graph\
    \ g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n  \
    \  }\n    return g;\n}\ngraph load_tree0(int n){\n    graph g(n);\n    for(int\
    \ i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_treep(int n){\n\
    \    graph g(n);\n    for(int i=0;i<n-1;++i){\n        int t;\n        std::cin>>t;\n\
    \        g[i+1].push_back(t);\n        g[t].push_back(i+1);\n    }\n    return\
    \ g;\n}\n\ntemplate<typename T>\ngraph_w<T> load_graph_weight(int n,int m){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T\
    \ u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_digraph_weight(int n,int m){\n    graph_w<T> g(n);\n    for(int\
    \ i=0;i<m;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        --s;--t;\n        g[s].emplace_back(t,u);\n    }\n    return g;\n}\n\
    template<typename T>\ngraph_w<T> load_graph0_weight(int n,int m){\n    graph_w<T>\
    \ g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        g[s].emplace_back(t,u);\n        g[t].emplace_back(s,u);\n    }\n   \
    \ return g;\n}\ntemplate<typename T>\ngraph_w<T> load_digraph0_weight(int n,int\
    \ m){\n    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n   \
    \     T u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n    }\n\
    \    return g;\n}\ntemplate<typename T>\ngraph_w<T> load_tree_weight(int n){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n       \
    \ T u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_tree0_weight(int n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n\
    \        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_treep_weight(int n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n\
    \        int t;\n        T u;\n        std::cin>>t>>u;\n        g[i+1].emplace_back(t,u);\n\
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 4 \"math/test/AOJ_prime_factor.test.cpp\"\
    \n\nint main(){\n    lint n;\n    cin>>n;\n    auto v=prime_factor(n);\n    cout<<n<<\"\
    : \";\n    output(v);\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include \"../prime_factor.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n    lint n;\n    cin>>n;\n    auto v=prime_factor(n);\n    cout<<n<<\"\
    : \";\n    output(v);\n}"
  dependsOn:
  - math/prime_factor.hpp
  - math/is_prime.hpp
  - util/template.hpp
  - graph_tree/graph_template.hpp
  isVerificationFile: true
  path: math/test/AOJ_prime_factor.test.cpp
  requiredBy: []
  timestamp: '2020-09-19 09:30:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/AOJ_prime_factor.test.cpp
layout: document
redirect_from:
- /verify/math/test/AOJ_prime_factor.test.cpp
- /verify/math/test/AOJ_prime_factor.test.cpp.html
title: math/test/AOJ_prime_factor.test.cpp
---
