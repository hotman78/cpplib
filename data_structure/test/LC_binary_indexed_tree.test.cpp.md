---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_indexed_tree.hpp
    title: BinaryIndexedTree
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
  bundledCode: "#line 1 \"data_structure/test/LC_binary_indexed_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"data_structure/binary_indexed_tree.hpp\"\n#include<vector>\r\n\r\n/**\r\n\
    \ * @brief BinaryIndexedTree\r\n */\r\n\r\nstruct BIT{\r\n    std::vector<long\
    \ long> bit;\r\n    int n;\r\n    BIT(long long n):n(n){\r\n        bit.resize(n+1,0);\r\
    \n    }\r\n    //0-indexed [0,x)-sum\r\n    long long sum(long long x){\r\n  \
    \      long long res=0;\r\n        for(int i=x;i;i-=i&-i)res+=bit[i];\r\n    \
    \    return res;\r\n    }\r\n    //0-indexed [x,y)-sum\r\n    long long sum(long\
    \ long x,long long y){\r\n        return sum(y)-sum(x);\r\n    }\r\n    //0-indexed\r\
    \n    void add(long long x,long long val){\r\n        if(x>=n)return;\r\n    \
    \    for(long long i=x+1;i<=n;i+=i&-i)bit[i]+=val;\r\n    }\r\n};\n#line 2 \"\
    util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"data_structure/test/LC_binary_indexed_tree.test.cpp\"\
    \n\nint main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tBIT bit(n);\n\trep(i,n){\n\t\tlint\
    \ x;\n\t\tcin>>x;\n\t\tbit.add(i,x);\n\t}\n\twhile(q--){\n\t\tlint c,s,t;\n\t\t\
    cin>>c>>s>>t;\n\t\tif(c==0){\n\t\t\tbit.add(s,t);\n\t\t}else{\n\t\t\tcout<<bit.sum(s,t)<<endl;\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../binary_indexed_tree.hpp\"\n#include \"../../util/template.hpp\"\n\
    \nint main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tBIT bit(n);\n\trep(i,n){\n\t\tlint\
    \ x;\n\t\tcin>>x;\n\t\tbit.add(i,x);\n\t}\n\twhile(q--){\n\t\tlint c,s,t;\n\t\t\
    cin>>c>>s>>t;\n\t\tif(c==0){\n\t\t\tbit.add(s,t);\n\t\t}else{\n\t\t\tcout<<bit.sum(s,t)<<endl;\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - data_structure/binary_indexed_tree.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_binary_indexed_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_binary_indexed_tree.test.cpp
- /verify/data_structure/test/LC_binary_indexed_tree.test.cpp.html
title: data_structure/test/LC_binary_indexed_tree.test.cpp
---
