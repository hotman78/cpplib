---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_list.hpp
    title: "\u7D20\u6570\u5217\u6319"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"math/test/AOJ_prime_list.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n#line 2\
    \ \"math/prime_list.hpp\"\n#include<vector>\n#include<bitset>\n#include<cmath>\n\
    #include<set>\n\n/**\n * @brief \u7D20\u6570\u5217\u6319\n */\n\nstd::bitset<500'000'001>\
    \ p;\nstd::vector<long long> prime_list(int n) {\n    p.set();\n    p[0]=0;\n\
    \    for(int i=2;i*i<=n;++i){\n        if(!p[i])continue;\n        for(int j=2*i;j<=n;j+=i)p[j]=0;\n\
    \    }\n    std::vector<long long>list;\n    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);\n\
    \    return list;\n}\n\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 4 \"math/test/AOJ_prime_list.test.cpp\"\
    \n\nint main(){\n    lint n;\n    cin>>n;\n    vec a(n);\n    rep(i,n)cin>>a[i];\n\
    \    auto v=prime_list(100'000'000);\n    bitset<100'000'001>b;\n    for(auto\
    \ e:v){\n        b[e]=1;\n    }\n    lint ans=0;\n    for(auto e:a){\n       \
    \ if(b[e])ans++;\n    }\n    cout<<ans<<endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include \"../prime_list.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n    lint n;\n    cin>>n;\n    vec a(n);\n    rep(i,n)cin>>a[i];\n \
    \   auto v=prime_list(100'000'000);\n    bitset<100'000'001>b;\n    for(auto e:v){\n\
    \        b[e]=1;\n    }\n    lint ans=0;\n    for(auto e:a){\n        if(b[e])ans++;\n\
    \    }\n    cout<<ans<<endl;\n}"
  dependsOn:
  - math/prime_list.hpp
  - util/template.hpp
  - graph_tree/graph_template.hpp
  isVerificationFile: true
  path: math/test/AOJ_prime_list.test.cpp
  requiredBy: []
  timestamp: '2020-09-19 09:30:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: math/test/AOJ_prime_list.test.cpp
layout: document
redirect_from:
- /verify/math/test/AOJ_prime_list.test.cpp
- /verify/math/test/AOJ_prime_list.test.cpp.html
title: math/test/AOJ_prime_list.test.cpp
---
