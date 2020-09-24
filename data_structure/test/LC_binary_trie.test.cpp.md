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
    \ GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"data_structure/test/LC_binary_trie.test.cpp\"\
    \n\nint main(){\n\tlint n;\n\tcin>>n;\n\tbinary_trie b;\n\twhile(n--){\n\t\tlint\
    \ c,x;\n\t\tcin>>c>>x;\n\t\tif(c==0&&!b.count(x))b.insert(x);\n\t\tif(c==1)b.erase(x);\n\
    \t\tif(c==2)cout<<b.xor_min(x)<<endl;\n\t}\n}\n"
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
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_binary_trie.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_binary_trie.test.cpp
- /verify/data_structure/test/LC_binary_trie.test.cpp.html
title: data_structure/test/LC_binary_trie.test.cpp
---
