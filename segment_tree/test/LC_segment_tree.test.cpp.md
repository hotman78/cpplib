---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"segment_tree/test/LC_segment_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 2 \"segment_tree/segment_tree.hpp\"\
    \n#include<vector>\n#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief\
    \ Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 4\
    \ \"segment_tree/segment_tree.hpp\"\n\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n * @see https://en.wikipedia.org/wiki/Segment_tree\n */\n\ntemplate<typename\
    \ T,typename F>\nclass segment_tree{\n\tmaybe<T>* node;\n    F op;\n\tint n=1;\n\
    \tpublic:\n    segment_tree(){}\n\tsegment_tree(int sz,F op=F()):op(op){\n\t\t\
    while(n<=sz)n<<=1;\n\t\tnode=new maybe<T>[n*2];\n\t\tfor(int i=0;i<n*2;i++)node[i]=maybe<T>();\n\
    \t}\n    segment_tree(const std::vector<T>&v,F op=F()):op(op){\n        auto f=expand<T,F>(op);\n\
    \        const int sz=v.size();\n\t\twhile(n<=sz)n<<=1;\n\t\tnode=new maybe<T>[n*2]();\n\
    \        for(int i=0;i<sz;i++)node[i+n]=maybe<T>(v[i]);\n        for(int i=n-1;i>=1;i--)node[i]=f(node[i*2],node[i*2+1]);\n\
    \t}\n    maybe<T> get(int l,int r){\n        auto f=expand<T,F>(op);\n       \
    \ l+=n;r+=n;\n        maybe<T> s,t;\n        while(l<r){\n            if(l&1)s=f(s,node[l++]);\n\
    \            if(r&1)t=f(node[--r],t);\n            l>>=1;r>>=1;\n        }\n \
    \       return f(s,t);\n    }\n    void apply(int t,T _val){\n        auto f=expand<T,F>(op);\n\
    \        t+=n;\n        maybe<T> val=maybe<T>(_val);\n        while(t){\n    \
    \        node[t]=f(node[t],val);\n            t=t>>1;\n        }\n    }\n    void\
    \ apply_left(int t,T _val){\n        auto f=expand<T,F>(op);\n        t+=n;\n\
    \        maybe<T> val=maybe<T>(_val);\n        while(t){\n            node[t]=f(val,node[t]);\n\
    \            t=t>>1;\n        }\n    }\n    void change(int t,T val){\n      \
    \  auto f=expand<T,F>(op);\n        t+=n;\n        node[t]=maybe<T>(val);\n  \
    \      while(t>1){\n            t=t>>1;\n            node[t]=f(node[t*2],node[t*2+1]);\n\
    \        }\n    }\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
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
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"segment_tree/test/LC_segment_tree.test.cpp\"\
    \n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n    vec v(n);\n    rep(i,n){\n\
    \        cin>>v[i];\n    }\n    segment_tree<lint,plus<lint>> seg(v);\n    rep(i,q){\n\
    \        lint c,s,t;\n        cin>>c>>s>>t;\n        if(c==0){\n            seg.apply(s,t);\n\
    \        }else{\n            cout<<seg.get(s,t).unwrap()<<endl;\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../segment_tree.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n    lint n,q;\n    cin>>n>>q;\n    vec v(n);\n    rep(i,n){\n     \
    \   cin>>v[i];\n    }\n    segment_tree<lint,plus<lint>> seg(v);\n    rep(i,q){\n\
    \        lint c,s,t;\n        cin>>c>>s>>t;\n        if(c==0){\n            seg.apply(s,t);\n\
    \        }else{\n            cout<<seg.get(s,t).unwrap()<<endl;\n        }\n \
    \   }\n}"
  dependsOn:
  - segment_tree/segment_tree.hpp
  - alga/maybe.hpp
  - util/template.hpp
  isVerificationFile: true
  path: segment_tree/test/LC_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/LC_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/LC_segment_tree.test.cpp
- /verify/segment_tree/test/LC_segment_tree.test.cpp.html
title: segment_tree/test/LC_segment_tree.test.cpp
---
