---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph_tree/push_relabel.hpp
    title: "\u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221AE))"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"graph_tree/test/LC_push_relabel.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n#line\
    \ 2 \"graph_tree/push_relabel.hpp\"\n#include<vector>\n#include<cmath>\n#include<queue>\n\
    #include<tuple>\n\n/**\n * @brief \u6700\u5927\u6D41(push_relabel\u6CD5O(V^2\u221A\
    E))\n */\ntemplate<typename T>\nclass push_relabel{\n    int n;\n    T f=0;\n\
    \    using i64=long long;\n    struct edge{\n        int from,to,rev;\n      \
    \  T flow,cap;\n    };\n    std::vector<i64>h,d;\n    std::vector<std::vector<edge*>>g;\n\
    \    std::vector<size_t>seen;\n    std::priority_queue<std::pair<i64,int>,std::vector<std::pair<i64,int>>,std::greater<std::pair<i64,int>>>que;\n\
    \    public:\n    push_relabel(int n):n(n){\n        h.resize(n,0);\n        d.resize(n,0);\n\
    \        g.resize(n);\n        seen.resize(n,0);\n    }\n    void add_edge(int\
    \ u,int v,T cap){\n        g[u].emplace_back(new edge{u,v,(int)g[v].size(),0,cap});\n\
    \        g[v].emplace_back(new edge{v,u,(int)g[u].size()-1,0,0});\n    }\n   \
    \ void push(edge* e){\n        int u=e->from,v=e->to;\n        i64 df=std::min(d[u],e->cap-e->flow);\n\
    \        e->flow+=df;\n        g[v][e->rev]->flow-=df;\n        d[u]-=df;\n  \
    \      d[v]+=df;\n        if(d[v]>0)que.emplace(h[v],v);\n        if(d[u]>0)que.emplace(h[u],u);\n\
    \    }\n    void relabel(int u){\n        i64 mn=n*2;\n        for(edge* e:g[u]){\n\
    \            if(e->cap-e->flow>0){\n                mn=std::min(mn,h[e->to]);\n\
    \            }\n        }\n        h[u]=1+mn;\n        que.emplace(h[u],u);\n\
    \    }\n    void discharge(int u){\n        while(d[u]>0){\n            if(seen[u]<g[u].size()){\n\
    \                edge* e=g[u][seen[u]];\n                if(e->cap-e->flow>0 &&\
    \ h[u]==h[e->to]+1){\n                    push(e);\n                }else{\n \
    \                   seen[u]+=1;\n                }\n            }else{\n     \
    \           relabel(u);\n                seen[u]=0;\n            }\n        }\n\
    \    }\n    T run(int s,int t){\n        h[s]=n;\n        for(auto e:g[s]){\n\
    \            d[s]+=e->cap;\n            push(e);\n        }\n        while(!que.empty()){\n\
    \            int u=que.top().second;\n            que.pop();\n            if(u==s||u==t)continue;\n\
    \            discharge(u);\n        }\n        for(auto e:g[s])f+=e->flow;\n \
    \       return f;\n    }\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
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
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n//#include\
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"graph_tree/test/LC_push_relabel.test.cpp\"\
    \n\nint main(){\n    lint n,m;\n    cin>>n>>m;\n    push_relabel<lint>mf(n);\n\
    \    while(m--){\n        lint u,v,c;\n        cin>>u>>v>>c;\n        mf.add_edge(u,v,c);\n\
    \    }\n    cout<<mf.run(0,n-1)<<endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#include \"../push_relabel.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n    lint n,m;\n    cin>>n>>m;\n    push_relabel<lint>mf(n);\n    while(m--){\n\
    \        lint u,v,c;\n        cin>>u>>v>>c;\n        mf.add_edge(u,v,c);\n   \
    \ }\n    cout<<mf.run(0,n-1)<<endl;\n}"
  dependsOn:
  - graph_tree/push_relabel.hpp
  - util/template.hpp
  isVerificationFile: true
  path: graph_tree/test/LC_push_relabel.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph_tree/test/LC_push_relabel.test.cpp
layout: document
redirect_from:
- /verify/graph_tree/test/LC_push_relabel.test.cpp
- /verify/graph_tree/test/LC_push_relabel.test.cpp.html
title: graph_tree/test/LC_push_relabel.test.cpp
---