---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/dijkstra_fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)"
  - icon: ':question:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"graph_tree/test/LC_dijkstra_fast.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"graph_tree/dijkstra_fast.hpp\"\
    \n#include<vector>\n#include<tuple>\n#include<functional>\n#include<ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/priority_queue.hpp>\n#line 4 \"graph_tree/graph_template.hpp\"\
    \n#include<iostream>\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\ntemplate<typename\
    \ T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\ngraph load_graph(int\
    \ n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n  \
    \      std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n       \
    \ g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_digraph(int n,int m){\n\
    \    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
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
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 8 \"graph_tree/dijkstra_fast.hpp\"\
    \n\n/**\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9 O(E+VlogE)\n */\n\n\n\
    template<typename T,typename F=std::less<T>,typename Add=std::plus<T>>\nstruct\
    \ dijkstra{\n    int s;\n    std::vector<T> diff;\n    std::vector<int> par;\n\
    \    dijkstra(const graph_w<T>& list,int s,T zero=T(),T inf=std::numeric_limits<T>::max(),F\
    \ f=F(),Add add=Add()):s(s){\n        int n=list.size();\n        diff.resize(n,inf);\n\
    \        par.resize(n,-1);\n        diff[s]=zero;\n        auto cmp=[f](auto s,auto\
    \ t){return f(t.first,s.first);};\n        using pq_t=__gnu_pbds::priority_queue<std::pair<T,int>,decltype(cmp),__gnu_pbds::pairing_heap_tag>;\n\
    \        pq_t que(cmp);\n        typename pq_t::point_iterator node[n];\n    \
    \    for(int i=0;i<n;i++)node[i]=que.push(std::make_pair(inf,i));\n        que.modify(node[s],std::make_pair(zero,s));\n\
    \        while(!que.empty()){\n            T p;\n            int now;\n      \
    \      std::tie(p,now)=que.top();\n            if(p==inf)break;\n            que.pop();\n\
    \            for(auto d:list[now]){\n                auto next=add(p,d.second);\n\
    \                if(f(next,diff[d.first])){\n                    diff[d.first]=next;\n\
    \                    par[d.first]=now;\n                    que.modify(node[d.first],std::make_pair(next,d.first));\n\
    \                }\n            }\n        }\n    }\n    T operator[](int idx){\n\
    \        return diff[idx];\n    }\n    bool reachable(int t){\n        return\
    \ par[t]!=-1;\n    }\n    std::vector<int> get_path(int t){\n        std::vector<int>res;\n\
    \        while(t!=s){\n            res.push_back(t);\n            t=par[t];\n\
    \        }\n        res.push_back(s);\n        std::reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
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
    \ 5 \"graph_tree/test/LC_dijkstra_fast.test.cpp\"\n\nint main(){\n    lint n,m,s,t;\n\
    \    cin>>n>>m>>s>>t;\n    auto g=load_digraph0_weight<lint>(n,m);\n    dijkstra<lint>\
    \ d(g,s);\n    if(d.reachable(t)){\n        auto p=d.get_path(t);\n        cout<<d[t]<<\"\
    \ \"<<p.size()-1<<endl;\n        rep(i,p.size()-1){\n            cout<<p[i]<<\"\
    \ \"<<p[i+1]<<endl;\n        }\n    }else{\n        cout<<-1<<endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\"\
    ../dijkstra_fast.hpp\"\n#include\"../graph_template.hpp\"\n#include\"../../util/template.hpp\"\
    \n\nint main(){\n    lint n,m,s,t;\n    cin>>n>>m>>s>>t;\n    auto g=load_digraph0_weight<lint>(n,m);\n\
    \    dijkstra<lint> d(g,s);\n    if(d.reachable(t)){\n        auto p=d.get_path(t);\n\
    \        cout<<d[t]<<\" \"<<p.size()-1<<endl;\n        rep(i,p.size()-1){\n  \
    \          cout<<p[i]<<\" \"<<p[i+1]<<endl;\n        }\n    }else{\n        cout<<-1<<endl;\n\
    \    }\n}"
  dependsOn:
  - graph_tree/dijkstra_fast.hpp
  - graph_tree/graph_template.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_dijkstra_fast.test.cpp
  requiredBy: []
  timestamp: '2020-09-19 09:30:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_dijkstra_fast.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_dijkstra_fast.test.cpp
- /verify/graph_tree/test/LC_dijkstra_fast.test.cpp.html
title: graph_tree/test/LC_dijkstra_fast.test.cpp
---