---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph_tree/maximum_independent_set.hpp
    title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"graph_tree/test/LC_maximum_independent_set.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\
    #line 2 \"graph_tree/maximum_independent_set.hpp\"\n#include<tuple>\n#include<vector>\n\
    #include<bitset>\n#line 4 \"graph_tree/graph_template.hpp\"\n#include<iostream>\n\
    /**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n\
    using graph=std::vector<std::vector<int>>;\ntemplate<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
    \ngraph load_graph(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_digraph(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);}return\
    \ g;}\ngraph load_graph0(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_digraph0(int n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;g[s].push_back(t);}return\
    \ g;}\ngraph load_tree(int n){graph g(n);for(int i=0;i<n-1;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_tree0(int n){graph g(n);for(int i=0;i<n-1;++i){int s,t;std::cin>>s>>t;g[s].push_back(t);g[t].push_back(s);}return\
    \ g;}\ngraph load_treep(int n){graph g(n);for(int i=0;i<n-1;++i){int t;std::cin>>t;g[i+1].push_back(t);g[t].push_back(i+1);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_graph_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;--s;--t;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_digraph_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;--s;--t;g[s].emplace_back(t,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_graph0_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_digraph0_weight(int n,int m){graph_w<T>\
    \ g(n);for(int i=0;i<m;++i){int s,t;T u;std::cin>>s>>t>>u;g[s].emplace_back(t,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_tree_weight(int n){graph_w<T> g(n);for(int\
    \ i=0;i<n-1;++i){int s,t;T u;std::cin>>s>>t>>u;--s;--t;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_tree0_weight(int n){graph_w<T> g(n);for(int\
    \ i=0;i<n-1;++i){int s,t;T u;std::cin>>s>>t>>u;g[s].emplace_back(t,u);g[t].emplace_back(s,u);}return\
    \ g;}\ntemplate<typename T>graph_w<T> load_treep_weight(int n){graph_w<T> g(n);for(int\
    \ i=0;i<n-1;++i){int t;T u;std::cin>>t>>u;g[i+1].emplace_back(t,u);g[t].emplace_back(i+1,u);}return\
    \ g;}\n#line 6 \"graph_tree/maximum_independent_set.hpp\"\n\n/**\n * @brief \u6700\
    \u5927\u72EC\u7ACB\u96C6\u5408(V<=50)\n */\n\nstd::pair<int,std::bitset<50>> __maximum_independent_set(std::vector<std::bitset<50>>v,std::bitset<50>b=std::bitset<50>()){\n\
    \tint n=v.size();\n\tauto del=[&](int k){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tv[k][i]=0;\n\
    \t\t\tv[i][k]=0;\n\t\t}\n\t\tb[k]=1;\n\t};\n\tint t=-1;\n\tfor(int i=0;i<n;++i)if(b[i]==0)t=i;\n\
    \tif(t==-1)return std::make_pair(0,std::bitset<50>());\n\tif(v[t].count()<=1){\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])del(i);\n\t\tdel(t);\n\t\tauto p=__maximum_independent_set(v,b);\n\
    \t\tp.first++;\n\t\tp.second[t]=1;\n\t\treturn p;\n\t}else{\n\t\tstd::vector<int>tmp;\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])tmp.push_back(i);\n\t\tdel(t);\n\t\tauto p=__maximum_independent_set(v,b);\n\
    \t\tfor(auto e:tmp)del(e);\n\t\tauto q=__maximum_independent_set(v,b);\n\t\tq.first++;\n\
    \t\tq.second[t]=1;\n\t\treturn p.first>q.first?p:q;\n\t}\n}\n\nstd::vector<int>\
    \ maximum_independent_set(const graph& g){\n\tstd::vector<std::bitset<50>>v(g.size());\n\
    \tfor(size_t i=0;i<g.size();++i){\n\t\tfor(auto e:g[i]){\n\t\t\tv[i][e]=1;\n\t\
    \t}\n\t}\n\tauto res=__maximum_independent_set(v);\n\tstd::vector<int>ret;\n\t\
    for(size_t i=0;i<res.second.size();++i){\n\t\tif(res.second[i])ret.push_back(i);\n\
    \t}\n\treturn ret;\n}\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
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
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\n#line 4 \"graph_tree/test/LC_maximum_independent_set.test.cpp\"\
    \n\nint main(){\n    lint n,m;\n    cin>>n>>m;\n    auto g=load_graph0(n,m);\n\
    \    auto e=maximum_independent_set(g);\n    cout<<e.size()<<endl;\n    output(e);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n#include \"../maximum_independent_set.hpp\"\n#include \"../../util/template.hpp\"\
    \n\nint main(){\n    lint n,m;\n    cin>>n>>m;\n    auto g=load_graph0(n,m);\n\
    \    auto e=maximum_independent_set(g);\n    cout<<e.size()<<endl;\n    output(e);\n\
    }"
  dependsOn:
  - graph_tree/maximum_independent_set.hpp
  - graph_tree/graph_template.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_maximum_independent_set.test.cpp
- /verify/graph_tree/test/LC_maximum_independent_set.test.cpp.html
title: graph_tree/test/LC_maximum_independent_set.test.cpp
---
