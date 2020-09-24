---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/lca.hpp
    title: "LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\u306E\u901F\
      \u3055)"
  - icon: ':heavy_check_mark:'
    path: graph_tree/depth.hpp
    title: "\u6839\u304B\u3089\u306E\u6DF1\u3055"
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph_tree/distance.hpp
    title: graph_tree/distance.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/arg_rmq.hpp
    title: RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
  - icon: ':heavy_check_mark:'
    path: data_structure/small_rmq.hpp
    title: data_structure/small_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: SparseTable
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  - icon: ':heavy_check_mark:'
    path: functional/argmin.hpp
    title: "\u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"graph_tree/test/LC_lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#line 2 \"graph_tree/lca.hpp\"\n#include<vector>\n#include<cmath>\n#include<tuple>\n\
    #line 4 \"graph_tree/graph_template.hpp\"\n#include<iostream>\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\n\
    template<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
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
    \ g;}\n#line 5 \"graph_tree/depth.hpp\"\n\n/**\n * @brief \u6839\u304B\u3089\u306E\
    \u6DF1\u3055\n */\n\nstd::vector<int> depth(const graph& g,int start){\n\tstd::vector<int>memo(g.size());\n\
    \tauto f=[&](auto f,int v,int p)->int{\n\t\tint mx=0;\n\t\tfor(auto t:g[v]){\n\
    \t\t\tif(t==p)continue;\n\t\t\tmx=std::max(mx,f(f,t,v));\n\t\t}\n\t\treturn memo[v]=mx+1;\n\
    \t};\n\tf(f,start,-1);\n\treturn memo;\n}\n#line 1 \"graph_tree/distance.hpp\"\
    \nstd::vector<int> distance(const graph& G,int start){\n    std::vector<int>memo(G.size());\n\
    \    auto f=[&](auto f,int v,int p,int i)->void{\n        for(auto t:G[v]){\n\
    \            if(t==p)continue;\n            f(f,t,v,i+1);\n        }\n       \
    \ memo[v]=i;\n    };\n    f(f,start,-1,0);\n    return memo;\n}\n#line 2 \"data_structure/arg_rmq.hpp\"\
    \n#include<assert.h>\n#line 4 \"data_structure/arg_rmq.hpp\"\n#include<stack>\n\
    #include<numeric>\n#line 7 \"data_structure/arg_rmq.hpp\"\n#include<algorithm>\n\
    #line 3 \"data_structure/small_rmq.hpp\"\n\n/**\n * RMQ(small) &amp;lt;O(N),O(1)&amp;gt;(N<=64)\n\
    \ */\n\ntemplate<typename T>\nclass small_rmq{\n    using u64=unsigned long long;\n\
    \    std::vector<u64>table;\n    std::vector<T> v;\n    public:\n    small_rmq(std::vector<T>\
    \ v):v(v){\n        assert(v.size()<=64);\n        std::vector<int>tmp(v.size());\n\
    \        table.resize(v.size(),0);\n        std::stack<T>stk;\n        for(int\
    \ i=0;i<(int)v.size();++i){\n            tmp.resize(v.size());\n            while(!stk.empty()&&v[stk.top()]>=v[i]){\n\
    \                stk.pop();\n            }\n            tmp[i]=stk.empty()?-1:stk.top();\n\
    \            stk.emplace(i);\n        }\n        for(int i=0;i<(int)v.size();++i){\n\
    \            if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n        }\n\
    \    }\n    T query(int l,int r){\n        assert(l!=r);\n        const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \        if(tmp==0)return r-1;\n        else return __builtin_ctzll(tmp);\n  \
    \  }\n};\n#line 3 \"data_structure/sparse_table.hpp\"\n#include<functional>\n\
    #line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n * @see\
    \ https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 7\
    \ \"data_structure/sparse_table.hpp\"\n/**\n * @brief SparseTable\n */\n\ntemplate<typename\
    \ T,typename F>\nclass sparse_table{\n    F f;\n    std::vector<std::vector<T>>data;\n\
    \    public:\n    sparse_table(std::vector<T> v,F f=F()):f(f){\n        int n=v.size(),log=log2(n)+1;\n\
    \        data.resize(n,std::vector<T>(log));\n        for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \        for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    maybe<T> get(int l,int r){\n        if(l==r)return maybe<T>();\n\
    \        if(r<l)std::swap(l,r);\n        int k=std::log2(r-l);\n        return\
    \ maybe<T>(f(data[l][k],data[r-(1<<k)][k]));\n    }\n};\n#line 3 \"functional/argmin.hpp\"\
    \n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E\n */\n\ntemplate<typename\
    \ T,typename E>\nstruct argmin{\n    std::pair<T,E> operator()(const std::pair<T,E>&\
    \ s,const std::pair<T,E>& t){\n        return s.second<=t.second?s:t;\n    }\n\
    };\n#line 11 \"data_structure/arg_rmq.hpp\"\n\n/**\n * @brief RangeArgminQuery\
    \ &amp;lt;O(N),O(1)&amp;gt;\n * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n\
    \ */\n\ntemplate<typename T>\nclass arg_rmq{\n    constexpr static int b=64;\n\
    \    std::vector<T>v;\n    std::vector<small_rmq<T>*>backet;\n    sparse_table<std::pair<int,T>,argmin<int,T>>*\
    \ st=0;\n    public:\n    arg_rmq(std::vector<T>v):v(v){\n        std::vector<std::pair<int,T>>tmp2;\n\
    \        for(int i=0;i<(int)v.size();i+=b){\n            std::vector<T>tmp;\n\
    \            T mn=std::numeric_limits<T>::max();\n            int idx=-1;\n  \
    \          for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j]){\n                    mn=v[i+j];\n            \
    \        idx=i+j;\n                }\n            }\n            tmp2.emplace_back(idx,mn);\n\
    \            backet.push_back(new small_rmq<T>(tmp));\n        }\n        st=new\
    \ sparse_table<std::pair<int,T>,argmin<int,T>>(tmp2);\n    }\n    maybe<std::pair<int,T>>\
    \ query(int s,int t){\n        if(s==t)return maybe<std::pair<int,T>>();\n   \
    \     if(s/b==t/b){\n            int idx=s/b*b+backet[s/b]->query(s%b,t%b);\n\
    \            return maybe<std::pair<int,T>>(std::make_pair(idx,v[idx]));\n   \
    \     }\n        std::pair<int,T> res=std::make_pair(-1,std::numeric_limits<T>::max());\n\
    \n        {\n            int idx=s/b*b+backet[s/b]->query(s%b,b);\n          \
    \  res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));\n        }\n\n       \
    \ if(s/b+1!=t/b)res=argmin<int,T>()(res,st->get(s/b+1,t/b).unwrap());\n\n    \
    \    if(t%b!=0){\n            int idx=t/b*b+backet[t/b]->query(0,t%b);\n     \
    \       res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));\n        }\n\n  \
    \      return maybe<std::pair<int,T>>(res);\n    }\n};\n#line 9 \"graph_tree/lca.hpp\"\
    \n\n/**\n * @brief LCA &amp;lt;O(N),O(1)&amp;gt;(HL\u5206\u89E3\u3068\u540C\u7B49\
    \u306E\u901F\u3055)\n */\n\nclass lca{\n    std::vector<int>data;\n    std::vector<int>comp_data;\n\
    \    std::vector<int>start;\n    arg_rmq<int>*st;\n    std::vector<int> __dist;\n\
    \    public:\n    lca(){}\n    lca(std::vector<std::vector<int>>v,int s){\n  \
    \      data.resize(v.size()*2-1);\n        comp_data.resize(v.size()*2-1);\n \
    \       start.resize(v.size());\n        int i=0;\n        __dist=distance(v,s);\n\
    \        auto f=[&](auto f,int n,int p)->void{\n            start[n]=i;\n    \
    \        data[i]=n;\n            comp_data[i++]=__dist[n];\n            for(int\
    \ t:v[n]){\n                if(t==p)continue;\n                f(f,t,n);\n   \
    \             data[i]=n;\n                comp_data[i++]=__dist[n];\n        \
    \    }\n        };\n        f(f,s,-1);\n        st=new arg_rmq<int>(comp_data);\n\
    \    }\n    int query(int p,int q){\n        return data[st->query(std::min(start[p],start[q]),std::max(start[p],start[q])+1).unwrap().first];\n\
    \    }\n    int dist(int p,int q){\n        return __dist[p]+__dist[q]-2*__dist[query(p,q)];\n\
    \    }\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma\
    \ GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\n\
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
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"graph_tree/test/LC_lca.test.cpp\"\
    \n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n    auto g=load_treep(n);\n  \
    \  lca lca(g,0);\n    while(q--){\n        lint s,t;\n        cin>>s>>t;\n   \
    \     cout<<lca.query(s,t)<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../lca.hpp\"\
    \n#include \"../../util/template.hpp\"\n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n\
    \    auto g=load_treep(n);\n    lca lca(g,0);\n    while(q--){\n        lint s,t;\n\
    \        cin>>s>>t;\n        cout<<lca.query(s,t)<<endl;\n    }\n}"
  dependsOn:
  - graph_tree/lca.hpp
  - graph_tree/depth.hpp
  - graph_tree/graph_template.hpp
  - graph_tree/distance.hpp
  - data_structure/arg_rmq.hpp
  - data_structure/small_rmq.hpp
  - data_structure/sparse_table.hpp
  - alga/maybe.hpp
  - functional/argmin.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_lca.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_lca.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_lca.test.cpp
- /verify/graph_tree/test/LC_lca.test.cpp.html
title: graph_tree/test/LC_lca.test.cpp
---
