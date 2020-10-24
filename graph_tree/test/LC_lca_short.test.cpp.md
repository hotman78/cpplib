---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca_short.hpp
    title: "LCA(HL\u5206\u89E3)&amp;lt;O(N),O(logN)&amp;gt;"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"graph_tree/test/LC_lca_short.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"graph_tree/lca_short.hpp\"\
    \n#include<vector>\n#line 3 \"graph_tree/graph_template.hpp\"\n#include<tuple>\n\
    #include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\ntemplate<typename T>\n\
    using graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\ngraph load_graph(int\
    \ n,int m){graph g(n);for(int i=0;i<m;++i){int s,t;std::cin>>s>>t;--s;--t;g[s].push_back(t);g[t].push_back(s);}return\
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
    \ g;}\n#line 4 \"graph_tree/lca_short.hpp\"\n\n/**\n * @brief LCA(HL\u5206\u89E3\
    )&amp;lt;O(N),O(logN)&amp;gt;\n */\n\nstruct lca{\n    graph g;\n    std::vector<int>sz,in,out,nxt,par;\n\
    \    lca(const graph& g,int s):g(g){\n        int n=g.size();\n        sz.resize(n,0);\n\
    \        in.resize(n,0);\n        out.resize(n,0);\n        nxt.resize(n,s);\n\
    \        par.resize(n,s);\n        dfs_sz(s,-1);\n        dfs_hld(s,-1);\n   \
    \ }\n    void dfs_sz(int v,int p) {\n        sz[v] = 1;\n        for(auto &u:\
    \ g[v]) {\n            if(p==u)continue;\n            dfs_sz(u,v);\n         \
    \   sz[v]+=sz[u];\n            if(sz[u]>sz[g[v][0]])std::swap(u,g[v][0]);\n  \
    \      }\n    }\n    void dfs_hld(int v,int p) {\n        static int t=0;\n  \
    \      in[v]=t++;\n        for(auto u: g[v]){\n            if(p==u)continue;\n\
    \            nxt[u]=(u==g[v][0]?nxt[v]:u);\n            par[u]=(u==g[v][0]?par[v]:v);\n\
    \            dfs_hld(u,v);\n        }\n        out[v] = t;\n    }\n    int query(int\
    \ s,int t){\n        while(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]])t=par[t];\n\
    \t\t\telse s=par[s];\n\t\t}\n        return sz[s]>sz[t]?s:t;\n    }\n    int distance(int\
    \ s,int t){\n\t\tint res=0;\n\t\twhile(nxt[s]!=nxt[t]){\n\t\t\tif(sz[nxt[s]]>sz[nxt[t]]){\n\
    \t\t\t\tres+=in[t]-in[nxt[t]]+1;\n\t\t\t\tt=par[t];\n\t\t\t}\n\t\t\telse {\n\t\
    \t\t\tres+=in[s]-in[nxt[s]]+1;\n\t\t\t\ts=par[s];\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res+std::abs(in[s]-in[t]);\n\t}\n};\n#line 2 \"util/template.hpp\"\n#pragma\
    \ GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC\
    \ target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    )\";return out;}\n#line 4 \"graph_tree/test/LC_lca_short.test.cpp\"\n\nint main(){\n\
    \    lint n,q;\n    cin>>n>>q;\n    auto g=load_treep(n);\n    lca lca(g,0);\n\
    \    while(q--){\n        lint s,t;\n        cin>>s>>t;\n        cout<<lca.query(s,t)<<endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../lca_short.hpp\"\
    \n#include \"../../util/template.hpp\"\n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n\
    \    auto g=load_treep(n);\n    lca lca(g,0);\n    while(q--){\n        lint s,t;\n\
    \        cin>>s>>t;\n        cout<<lca.query(s,t)<<endl;\n    }\n}"
  dependsOn:
  - graph_tree/lca_short.hpp
  - graph_tree/graph_template.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_lca_short.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 18:26:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_lca_short.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_lca_short.test.cpp
- /verify/graph_tree/test/LC_lca_short.test.cpp.html
title: graph_tree/test/LC_lca_short.test.cpp
---
