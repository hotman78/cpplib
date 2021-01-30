---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_trie.hpp
    title: BinaryTrie
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"data_structure/test/LC_binary_trie.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 2 \"data_structure/binary_trie.hpp\"\
    \n#include<cstdint>\n\n/**\n * @brief BinaryTrie\n */\n\nstruct binary_trie{\n\
    \    constexpr static int B=64;\n    using u64=std::uint64_t;\n    struct node{\n\
    \        node* ch[2]={0,0};\n        int cnt=0;\n    };\n    using np=node*;\n\
    \    np root=new node();\n    void insert(u64 x){\n        np t=root;\n      \
    \  t->cnt++;\n        for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new\
    \ node();\n            if(!t->ch[1])t->ch[1]=new node();\n            t=t->ch[(x>>i)&1];\n\
    \            t->cnt++;\n        }\n    }\n    bool erase(u64 x){\n        np t=root;\n\
    \        if(!count(x))return 0;\n        t->cnt--;\n        for(int i=B-1;i>=0;--i){\n\
    \            if(!t->ch[0])t->ch[0]=new node();\n            if(!t->ch[1])t->ch[1]=new\
    \ node();\n            t=t->ch[(x>>i)&1];\n            t->cnt--;\n        }\n\
    \        return 1;\n    }\n    int count(u64 x){\n        np t=root;\n       \
    \ for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new node();\n  \
    \          if(!t->ch[1])t->ch[1]=new node();\n            t=t->ch[(x>>i)&1];\n\
    \        }\n        return t->cnt;\n    }\n    u64 xor_min(u64 x){\n        np\
    \ t=root;\n        u64 res=0;\n        for(int i=B-1;i>=0;--i){\n            if(!t->ch[0])t->ch[0]=new\
    \ node();\n            if(!t->ch[1])t->ch[1]=new node();\n            if(t->ch[(x>>i)&1]->cnt)t=t->ch[(x>>i)&1];\n\
    \            else{\n                t=t->ch[1-((x>>i)&1)];\n                res+=1ULL<<i;\n\
    \            }\n        }\n        return res;\n    }\n};\n#line 2 \"util/template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
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
    #line 4 \"data_structure/test/LC_binary_trie.test.cpp\"\n\nint main(){\n\tlint\
    \ n;\n\tcin>>n;\n\tbinary_trie b;\n\twhile(n--){\n\t\tlint c,x;\n\t\tcin>>c>>x;\n\
    \t\tif(c==0&&!b.count(x))b.insert(x);\n\t\tif(c==1)b.erase(x);\n\t\tif(c==2)cout<<b.xor_min(x)<<endl;\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"../binary_trie.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \tlint n;\n\tcin>>n;\n\tbinary_trie b;\n\twhile(n--){\n\t\tlint c,x;\n\t\tcin>>c>>x;\n\
    \t\tif(c==0&&!b.count(x))b.insert(x);\n\t\tif(c==1)b.erase(x);\n\t\tif(c==2)cout<<b.xor_min(x)<<endl;\n\
    \t}\n}"
  dependsOn:
  - data_structure/binary_trie.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_binary_trie.test.cpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_binary_trie.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_binary_trie.test.cpp
- /verify/data_structure/test/LC_binary_trie.test.cpp.html
title: data_structure/test/LC_binary_trie.test.cpp
---
