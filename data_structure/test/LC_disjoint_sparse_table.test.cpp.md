---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/disjoint_sparse_table.hpp
    title: DisjointSparseTable
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"data_structure/test/LC_disjoint_sparse_table.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2\
    \ \"data_structure/disjoint_sparse_table.hpp\"\n#include<functional>\n#include<vector>\n\
    \n/**\n * @brief DisjointSparseTable\n */\n\ntemplate<typename T,typename F=std::plus<T>>\n\
    class disjoint_sparse_table{\n\tT** table;\n\tT* data;\n\tint n=1,cnt=0;\n\tpublic:\n\
    \tF f;\n\tdisjoint_sparse_table(const std::vector<T>& v,F f):f(f){init(v);}\n\t\
    disjoint_sparse_table(const std::vector<T>& v):f(F()){init(v);}\n\tvoid init(const\
    \ std::vector<T>& v){\n\t\twhile(n<(int)v.size())n<<=1,cnt++;\n\t\ttable=new T*[cnt];\n\
    \t\tfor(int i=0;i<cnt;i++){\n\t\t\ttable[i]=new T[n]();\n\t\t}\n\t\tdata =new\
    \ T[n];\n\t\tfor(int i=0;i<(int)v.size();i++)data[i]=v[i];\n\t\tfor(int i=0;i<cnt;i++){\n\
    \t\t\tfor(int j=0;j<(n>>(i+1));j++){\n\t\t\t\tconst int mid=(j<<(i+1))+(1<<i);\n\
    \t\t\t\tfor(int k=0;k<(1<<i);k++){\n\t\t\t\t\tif(k==0){\n\t\t\t\t\t\tif(0<=mid-1&&mid-1<(int)v.size())table[i][mid-1]=v[mid-1];\n\
    \t\t\t\t\t\tif(0<=mid&&mid<(int)v.size())table[i][mid]=v[mid];\n\t\t\t\t\t}\n\t\
    \t\t\t\telse{\n\t\t\t\t\t\tif(0<=mid-1-k&&mid-1-k<(int)v.size())table[i][mid-1-k]=f(table[i][mid-k],v[mid-1-k]);\n\
    \t\t\t\t\t\tif(0<=mid+k&&mid+k<(int)v.size())table[i][mid+k]=f(table[i][mid+k-1],v[mid+k]);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tT get(int l,int r){\n\t\tr--;\n\
    \t\tif(l==r)return data[l];\n\t\tconst int t=31-__builtin_clz((int)(l^r));\n\t\
    \treturn f(table[t][l],table[t][r]);\n\t}\n};\n#line 2 \"util/template.hpp\"\n\
    #pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx2\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct\
    \ __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    #line 4 \"data_structure/test/LC_disjoint_sparse_table.test.cpp\"\n\nint main(){\n\
    \tlint n,q;\n\tcin>>n>>q;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\tdisjoint_sparse_table<lint>dst(a);\n\
    \twhile(q--){\n\t\tlint s,t;\n\t\tcin>>s>>t;\n\t\tcout<<dst.get(s,t)<<endl;\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../disjoint_sparse_table.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\tdisjoint_sparse_table<lint>dst(a);\n\
    \twhile(q--){\n\t\tlint s,t;\n\t\tcin>>s>>t;\n\t\tcout<<dst.get(s,t)<<endl;\n\t\
    }\n}"
  dependsOn:
  - data_structure/disjoint_sparse_table.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_disjoint_sparse_table.test.cpp
- /verify/data_structure/test/LC_disjoint_sparse_table.test.cpp.html
title: data_structure/test/LC_disjoint_sparse_table.test.cpp
---
