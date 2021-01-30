---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dsu/uf_min.hpp
    title: "\u6839\u3068\u306EPath\u306E\u4E2D\u3067\u306E\u6700\u5C0F\u5024\u3092\
      \u8FD4\u3059UnionFind"
  - icon: ':heavy_check_mark:'
    path: graph_tree/dominator_tree.hpp
    title: "\u652F\u914D\u6728"
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    PROBLEM: https://judge.yosupo.jp/problem/dominatortree
    links:
    - https://judge.yosupo.jp/problem/dominatortree
  bundledCode: "#line 1 \"graph_tree/test/LC_dominator_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/dominatortree\"\n#line 2 \"graph_tree/dominator_tree.hpp\"\
    \n#include<vector>\n#include<stack>\n#line 3 \"dsu/uf_min.hpp\"\n#include<numeric>\n\
    #include<limits>\n\n/**\n * @brief \u6839\u3068\u306EPath\u306E\u4E2D\u3067\u306E\
    \u6700\u5C0F\u5024\u3092\u8FD4\u3059UnionFind\n */\n\ntemplate<typename T>\nstruct\
    \ uf_min{\n    constexpr static int inf=std::numeric_limits<T>::max();\n    std::vector<int>par,mnid;\n\
    \    std::vector<T>mn;\n    uf_min(int v){\n        par.resize(v);\n        mn.resize(v,inf);\n\
    \        mnid.resize(v);\n        std::iota(par.begin(),par.end(),0);\n      \
    \  std::iota(mnid.begin(),mnid.end(),0);\n    }\n    int find(int v){\n      \
    \  if(par[v]==v)return v;\n        int r=find(par[v]);\n        if(mn[v]>mn[par[v]]){\n\
    \            mnid[v]=mnid[par[v]];\n            mn[v]=mn[par[v]];\n        }\n\
    \        par[v]=r;\n        return r;\n    }\n    void set(int v,T x){\n     \
    \   mn[v]=x;\n    }\n    T eval(int v){\n        find(v);\n        return mnid[v];\n\
    \    }\n    //x\u3092y\u306E\u89AA\u306B\u3059\u308B\n    void link(int x,int\
    \ y){\n        par[y]=x;\n    }\n};\n#line 5 \"graph_tree/dominator_tree.hpp\"\
    \n\n/**\n * @brief \u652F\u914D\u6728\n */\n\n// root\u304B\u3089v\u306B\u5411\
    \u304B\u3046\u969B\u306B\u7D76\u5BFE\u901A\u3089\u306A\u3044\u3068\u3044\u3051\
    \u306A\u3044\u9802\u70B9\u3092\n// v\u306E\u7956\u5148\u3068\u3059\u308B\u3088\
    \u3046\u306B\u6728\u3092\u69CB\u7BC9\u3059\u308B\nstd::vector<int> dominator_tree(std::vector<std::vector<int>>g,int\
    \ s){\n\tint n=g.size();\n\tstd::vector<std::vector<int>> rev_g(n);\n\tfor(int\
    \ i=0;i<n;++i){\n\t\tfor(auto e:g[i]){\n\t\t\trev_g[e].push_back(i);\n\t\t}\n\t\
    }\n\tstd::stack<int>stk;\n    std::vector<bool>used(n,0);\n    std::vector<int>id(n+1,n);\n\
    \    std::vector<int>id2(n+1,n);\n    std::vector<int>sdom(n,n);\n    std::vector<int>idom(n,n);\n\
    \    std::vector<std::vector<int>>ch(n);\n    sdom[s]=s;\n    int idx=0;\n   \
    \ stk.emplace(s);\n    while(!stk.empty()){\n        auto v=stk.top();\n     \
    \   stk.pop();\n        id2[v]=idx;\n        id[idx++]=v;\n        for(auto e:g[v]){\n\
    \            if(!used[e]){\n                ch[v].push_back(e);\n            \
    \    stk.emplace(e);\n                used[e]=1;\n            }\n        }\n \
    \   }\n    for(int i=0;i<n;++i){\n        int v=id[i];\n        if(v==n)continue;\n\
    \        if(v==s)continue;\n        for(auto e:rev_g[v]){\n            if(id2[e]<i){\n\
    \                if(id2[sdom[v]]>id2[e]){\n                    sdom[v]=e;\n  \
    \              }\n            }\n        }\n    }\n    uf_min<int> uf(n);\n  \
    \  std::vector<std::vector<int>>sdom_list(n+1);\n    std::vector<int>u(n,-1);\n\
    \    for(int i=n-1;i>=0;--i){\n        int v=id[i];\n        if(v==n)continue;\n\
    \        for(auto e:sdom_list[v]){\n            u[e]=uf.eval(e);\n        }\n\
    \        if(v==s)continue;\n        for(auto e:rev_g[v]){\n            if(id2[e]<i)continue;\n\
    \            auto d=uf.eval(e);\n            if(id2[sdom[v]]>id2[sdom[d]])sdom[v]=sdom[d];\n\
    \        }\n        sdom_list[sdom[v]].push_back(v);\n        uf.set(v,id2[sdom[v]]);\n\
    \        for(auto e:ch[v]){\n            uf.link(v,e);\n        }\n    }\n   \
    \ for(int i=0;i<n;++i){\n        auto v=id[i];\n        if(v==n)continue;\n  \
    \      if(v==s){\n            idom[v]=v;\n            continue;\n        }\n \
    \       if(sdom[v]==sdom[u[v]])idom[v]=sdom[v];\n        else idom[v]=idom[u[v]];\n\
    \    }\n    for(int i=0;i<n;++i)if(idom[i]==n)idom[i]=-1;\n\treturn idom;\n}\n\
    #line 3 \"graph_tree/graph_template.hpp\"\n#include<tuple>\n#include<iostream>\n\
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
    \ g;}\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma\
    \ GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx2\")\n#include<bits/stdc++.h>\n\
    using namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    #line 5 \"graph_tree/test/LC_dominator_tree.test.cpp\"\n\nint main(){\n    lint\
    \ n,m,s;\n    cin>>n>>m>>s;\n    auto g=load_digraph0(n,m);\n    output(dominator_tree(g,s));\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dominatortree\"\n#include\"\
    ../dominator_tree.hpp\"\n#include\"../graph_template.hpp\"\n#include\"../../util/template.hpp\"\
    \n\nint main(){\n    lint n,m,s;\n    cin>>n>>m>>s;\n    auto g=load_digraph0(n,m);\n\
    \    output(dominator_tree(g,s));\n}"
  dependsOn:
  - graph_tree/dominator_tree.hpp
  - dsu/uf_min.hpp
  - graph_tree/graph_template.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_dominator_tree.test.cpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_dominator_tree.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_dominator_tree.test.cpp
- /verify/graph_tree/test/LC_dominator_tree.test.cpp.html
title: graph_tree/test/LC_dominator_tree.test.cpp
---
