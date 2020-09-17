---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/fast_set.hpp
    title: data_structure/fast_set.hpp
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data_structure/fast_set.hpp\"\n#include<cstdint>\n#include<vector>\n\
    #include<tuple>\n#include<algorithm>\n#include <cassert>\n#include<iostream>\n\
    \ntemplate<typename T>\nstruct fast_set{\n\tconstexpr static int B=4;\n    constexpr\
    \ static int S=(1<<B);\n\tstruct node{\n\t\tT val=0;\n        bool b=0;\n\t\t\
    node* ch[S]={};\n        static int node_count;\n        void* operator new(std::size_t){\n\
    \            static node* pool=(node*)malloc(4096*sizeof(node));\n           \
    \ if(node_count==4096){\n                node_count=0;\n                pool=(node*)malloc(4096*sizeof(node));\n\
    \            }\n            return pool + node_count++;\n        }\n        node(){}\n\
    \t};\n\tusing np=node*;\n\tnp root=new node(),root2=new node();\n\tinline T& operator[](int64_t\
    \ k){\n        return get(std::abs(k),k>0?root:root2);\n    }\n    inline bool\
    \ count(int64_t k){\n        return count(std::abs(k),k>0?root:root2);\n    }\n\
    \    inline std::vector<std::pair<int64_t,T>> out(){\n        std::vector<std::pair<int64_t,T>>v;\n\
    \        out(v,root2,0,-1,0);\n        out(v,root,0,1,0);\n        std::sort(v.begin(),v.end());\n\
    \        return v;\n    }\n\tT& get(int64_t k,np t){\n        while(k){\n    \
    \        if(!t->ch[k&(S-1)])t->ch[k&(S-1)]=new node();\n            t=t->ch[k&(S-1)];\n\
    \            k>>=B;\n        }\n        t->b=1;\n        return t->val;\n\t}\n\
    \    bool count(int64_t k,np& t){\n        if(!t)return 0;\n        if(!k)return\
    \ t->b;\n        else return count(k>>B,t->ch[k&(S-1)]);\n    }\n    void out(std::vector<std::pair<int64_t,T>>&v,np&\
    \ t,int64_t k,int f,int b){\n        if(!t)return;\n        if(t->b)v.emplace_back(k*f,t->val);\n\
    \        for(int i=0;i<S;++i){\n            out(v,t->ch[i],k+(i<<(B*b)),f,b+1);\n\
    \        }\n    }\n};\ntemplate<typename T>int fast_set<T>::node::node_count =\
    \ 0;\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma\
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
    #define irep(i) for(lint i=0;;++i)\ninline vector<long long> range(long long n){vector<long\
    \ long>v(n);iota(v.begin(),v.end(),0LL);return v;}\ninline vector<long long> range(long\
    \ long a,long long b){vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
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
    \ 3 \"data_structure/test/LC_fast_set.test.cpp\"\n\nint main(){\n    lint q;\n\
    \    cin>>q;\n    fast_set<lint>v;\n    while(q--){\n        lint c;\n       \
    \ cin>>c;\n        if(c==0){\n            lint s,t;\n            cin>>s>>t;\n\
    \            v[s]=t;\n        }else{\n            lint s;\n            cin>>s;\n\
    \            cout<<v[s]<<endl;\n        }\n    }\n}\n"
  code: "#include \"../fast_set.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n    lint q;\n    cin>>q;\n    fast_set<lint>v;\n    while(q--){\n \
    \       lint c;\n        cin>>c;\n        if(c==0){\n            lint s,t;\n \
    \           cin>>s>>t;\n            v[s]=t;\n        }else{\n            lint\
    \ s;\n            cin>>s;\n            cout<<v[s]<<endl;\n        }\n    }\n}"
  dependsOn:
  - data_structure/fast_set.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_fast_set.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 10:09:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: data_structure/test/LC_fast_set.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_fast_set.test.cpp
- /verify/data_structure/test/LC_fast_set.test.cpp.html
title: data_structure/test/LC_fast_set.test.cpp
---
