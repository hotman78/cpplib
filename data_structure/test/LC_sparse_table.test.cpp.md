---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: SparseTable
  - icon: ':heavy_check_mark:'
    path: functional/MIN.hpp
    title: functional/MIN.hpp
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"data_structure/test/LC_sparse_table.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n#include<vector>\n#include<functional>\n#include<cmath>\n#include<algorithm>\n\
    \n/**\n * @brief SparseTable\n */\n\ntemplate<typename T,typename F>\nclass sparse_table{\n\
    \    F f;\n    std::vector<std::vector<T>>data;\n    public:\n    sparse_table(std::vector<T>\
    \ v,F f=F()):f(f){\n        int n=v.size(),log=log2(n)+1;\n        data.resize(n,std::vector<T>(log));\n\
    \        for(int i=0;i<n;i++)data[i][0]=v[i];\n        for(int j=1;j<log;j++)for(int\
    \ i=0;i+(1<<(j-1))<n;i++){\n            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n\
    \        }\n    }\n    T get(int l,int r){\n        if(r<l)std::swap(l,r);\n \
    \       //assert(0<l||r<=(T)data.size());\n        int k=std::log2(r-l);\n   \
    \     return f(data[l][k],data[r-(1<<k)][k]);\n    }\n};\n#line 3 \"functional/MIN.hpp\"\
    \n\ntemplate<typename T>\nstruct MIN{\n    T operator()(const T& s,const T& t){\n\
    \        return std::min(s,t);\n    }\n};\n#line 2 \"util/template.hpp\"\n#pragma\
    \ GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC\
    \ target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ 5 \"data_structure/test/LC_sparse_table.test.cpp\"\n\nint main(){\n\tlint n,q;\n\
    \tcin>>n>>q;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\tsparse_table<lint,MIN<lint>>s(a);\n\
    \twhile(q--){\n\t\tlint l,r;\n\t\tcin>>l>>r;\n\t\tcout<<s.get(l,r)<<endl;\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../sparse_table.hpp\"\n#include \"../../functional/MIN.hpp\"\n#include \"../../util/template.hpp\"\
    \n\nint main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\
    \tsparse_table<lint,MIN<lint>>s(a);\n\twhile(q--){\n\t\tlint l,r;\n\t\tcin>>l>>r;\n\
    \t\tcout<<s.get(l,r)<<endl;\n\t}\n}"
  dependsOn:
  - data_structure/sparse_table.hpp
  - functional/MIN.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 14:18:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_sparse_table.test.cpp
- /verify/data_structure/test/LC_sparse_table.test.cpp.html
title: data_structure/test/LC_sparse_table.test.cpp
---
