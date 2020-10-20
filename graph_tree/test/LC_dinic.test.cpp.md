---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/dinic.hpp
    title: "\u6700\u5927\u6D41(Dinic\u6CD5)"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313
  bundledCode: "#line 1 \"graph_tree/test/LC_dinic.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313\"\n#line 2 \"graph_tree/dinic.hpp\"\
    \n#include<vector>\r\n#include<queue>\r\n#include<cmath>\r\n#include<limits>\r\
    \n#include<cassert>\r\n#include<iostream>\r\n#include<map>\r\n#include<list>\r\
    \n\r\n/**\r\n * @brief \u6700\u5927\u6D41(Dinic\u6CD5)\r\n */\r\n\r\ntemplate<typename\
    \ T>\r\nstruct dinic {\r\n    struct edge {\r\n        int to;\r\n        typename\
    \ std::list<edge>::iterator rev;\r\n        T cap,flow;\r\n        edge(int to,T\
    \ cap):to(to),cap(cap),flow(T()){}\r\n    };\r\n    int n,src,dst;\r\n    T ret=T();\r\
    \n    std::vector<std::list<edge>> g;\r\n    std::vector<typename std::list<edge>::iterator>itr;\r\
    \n    std::vector<int>level,seen;\r\n    std::map<std::pair<int,int>,bool>exist;\r\
    \n    std::map<std::pair<int,int>,typename std::list<edge>::iterator>m;\r\n  \
    \  dinic(int n,int s,int t):n(n),src(s),dst(t){g.assign(n,std::list<edge>());itr.resize(n);}\r\
    \n\r\n    void add_edge(int from, int to, T cap) {\r\n        g[from].push_back(edge(to,cap));\r\
    \n        g[to].push_back(edge(from,0));\r\n        m[std::make_pair(from,to)]=prev(g[from].end());\r\
    \n        m[std::make_pair(to,from)]=prev(g[to].end());\r\n        g[from].back().rev=prev(g[to].end());\r\
    \n        g[to].back().rev=prev(g[from].end());\r\n        exist[std::make_pair(from,to)]=1;\r\
    \n        exist[std::make_pair(to,from)]=1;\r\n    }\r\n    bool update_edge(int\
    \ from, int to, T cap){\r\n        if(cap>0){\r\n            if(exist[std::make_pair(from,to)]){\r\
    \n                auto e=m[std::make_pair(from,to)];\r\n                e->cap+=cap;\r\
    \n            }else{\r\n                add_edge(from,to,cap);\r\n           \
    \ }\r\n            return 1;\r\n        }else{\r\n            cap*=-1;\r\n   \
    \         if(exist[std::make_pair(from,to)]){\r\n                auto e=m[std::make_pair(from,to)];\r\
    \n                if(e->cap-e->flow>=cap){\r\n                    e->cap-=cap;\r\
    \n                }else{\r\n                    e->cap-=cap;\r\n             \
    \       T req=e->flow-e->cap;\r\n                    e->flow-=req;\r\n       \
    \             e->rev->flow+=req;\r\n                    ret-=req;\r\n        \
    \            assert(cancel(dst,to,req));\r\n                    assert(cancel(from,src,req));\r\
    \n                    if(e->cap==0&&e->rev->cap==0){\r\n                     \
    \   g[from].erase(e);\r\n                        g[to].erase(e->rev);\r\n    \
    \                    exist[std::make_pair(from,to)]=0;\r\n                   \
    \     exist[std::make_pair(to,from)]=0;\r\n                    }\r\n         \
    \       }\r\n                return 1;\r\n            }else{\r\n             \
    \   return 0;\r\n            }\r\n        }\r\n    }\r\n\r\n    void bfs(int s)\
    \ {\r\n        level.assign(n,-1);\r\n        std::queue<int> q;\r\n        level[s]\
    \ = 0; q.push(s);\r\n        while (!q.empty()) {\r\n            int v = q.front();\
    \ q.pop();\r\n            for(edge e: g[v]){\r\n                if (e.cap-e.flow\
    \ > 0 and level[e.to] < 0) {\r\n                    level[e.to] = level[v] + 1;\r\
    \n                    q.push(e.to);\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    T dfs(int v, int t,T f) {\r\n        if (v == t)\
    \ return f;\r\n        for(auto &e=itr[v];e!=g[v].end();++e){\r\n            if\
    \ (e->cap-e->flow > 0 and level[v] < level[e->to]) {\r\n                T d =\
    \ dfs(e->to, t, std::min(f, e->cap-e->flow));\r\n                if (d > 0) {\r\
    \n                    e->flow+=d;\r\n                    e->rev->flow -= d;\r\n\
    \                    return d;\r\n                }\r\n            }\r\n     \
    \   }\r\n        return 0;\r\n    }\r\n\r\n    T __cancel(int v,int t,T f){\r\n\
    \        if (v == t) return f;\r\n        seen[v]=1;\r\n        for (edge& e:\
    \ g[v]){\r\n            if (e.rev->flow > 0&&!seen[e.to]) {\r\n              \
    \  T d = __cancel(e.to, t, std::min(f,e.rev->flow));\r\n                if (d\
    \ > 0) {\r\n                    e.flow+=d;\r\n                    e.rev->flow-=d;\r\
    \n                    return d;\r\n                }\r\n            }\r\n    \
    \    }\r\n        return 0;\r\n    }\r\n    T run() {\r\n        T f;\r\n    \
    \    while (bfs(src), level[dst] >= 0) {\r\n            for(int i=0;i<n;++i)itr[i]=g[i].begin();\r\
    \n            while ((f = dfs(src, dst, std::numeric_limits<T>::max())) > 0) {\r\
    \n                ret += f;\r\n            }\r\n        }\r\n        return ret;\r\
    \n    }\r\n    T cancel(int s,int t,T mx){\r\n        T f;\r\n        while(seen.assign(n,0),seen[s]=1,(f=__cancel(s,\
    \ t, mx))>0)mx-=f;\r\n        return mx==0;\r\n    }\r\n    T cap(int s,int t){\r\
    \n        if(exist[std::make_pair(s,t)]){\r\n            return m[std::make_pair(s,t)]->cap;\r\
    \n        }else{\r\n            return 0;\r\n        }\r\n    }\r\n    T flow(int\
    \ s,int t){\r\n        if(exist[std::make_pair(s,t)]){\r\n            return m[std::make_pair(s,t)]->flow;\r\
    \n        }else{\r\n            return 0;\r\n        }\r\n    }\r\n    void debug(){\r\
    \n        for(int i=0;i<n;++i)for(int j=0;j<n;++j){\r\n            if(i==j)continue;\r\
    \n            if(flow(i,j)>0)std::cerr<<\"(\"<<i<<\",\"<<j<<\")\";\r\n       \
    \ }\r\n        std::cerr<<'\\n';\r\n    }\r\n};\n#line 2 \"util/template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\n#line 4 \"graph_tree/test/LC_dinic.test.cpp\"\
    \n\nint main(){\n    int n,e,q;\n    cin>>n>>e>>q;\n    dinic<lint>mf(n,0,n-1);\n\
    \    while(e--){\n        int s,t;\n        cin>>s>>t;\n        s--;t--;\n   \
    \     mf.update_edge(s,t,1);\n        mf.update_edge(t,s,1);\n    }\n    while(q--){\n\
    \        int c,s,t;\n        cin>>c>>s>>t;\n        s--;t--;\n        mf.update_edge(s,t,c==1?1:-1);\n\
    \        mf.update_edge(t,s,c==1?1:-1);\n        cout<<mf.run()<<endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313\"\
    \n#include\"../dinic.hpp\"\n#include\"../../util/template.hpp\"\n\nint main(){\n\
    \    int n,e,q;\n    cin>>n>>e>>q;\n    dinic<lint>mf(n,0,n-1);\n    while(e--){\n\
    \        int s,t;\n        cin>>s>>t;\n        s--;t--;\n        mf.update_edge(s,t,1);\n\
    \        mf.update_edge(t,s,1);\n    }\n    while(q--){\n        int c,s,t;\n\
    \        cin>>c>>s>>t;\n        s--;t--;\n        mf.update_edge(s,t,c==1?1:-1);\n\
    \        mf.update_edge(t,s,c==1?1:-1);\n        cout<<mf.run()<<endl;\n    }\n\
    }"
  dependsOn:
  - graph_tree/dinic.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_dinic.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_dinic.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_dinic.test.cpp
- /verify/graph_tree/test/LC_dinic.test.cpp.html
title: graph_tree/test/LC_dinic.test.cpp
---
