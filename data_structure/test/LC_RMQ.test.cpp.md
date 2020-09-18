---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/RMQ.hpp
    title: RMQ&amp;lt;O(N),O(1)&amp;gt;
  - icon: ':question:'
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
  bundledCode: "#line 1 \"data_structure/test/LC_RMQ.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"data_structure/RMQ.hpp\"\
    \n#include<assert.h>\n#include<vector>\n#include<stack>\n#include<numeric>\n#include<cmath>\n\
    #include<algorithm>\n\n/**\n * @brief RMQ&amp;lt;O(N),O(1)&amp;gt;\n * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415\n\
    \ */\n\ntemplate<typename T>\nclass RMQ{\n    class small_rmq{\n        using\
    \ u64=unsigned long long;\n        std::vector<u64>table;\n        std::vector<T>\
    \ v;\n        public:\n        small_rmq(std::vector<T> v):v(v){\n           \
    \ assert(v.size()<=64);\n            std::vector<int>tmp(v.size());\n        \
    \    table.resize(v.size(),0);\n            std::stack<T>stk;\n            for(int\
    \ i=0;i<(int)v.size();++i){\n                tmp.resize(v.size());\n         \
    \       while(!stk.empty()&&v[stk.top()]>=v[i]){\n                    stk.pop();\n\
    \                }\n                tmp[i]=stk.empty()?-1:stk.top();\n       \
    \         stk.emplace(i);\n            }\n            for(int i=0;i<(int)v.size();++i){\n\
    \                if(tmp[i]!=-1)table[i]=table[tmp[i]]|(1ULL<<(tmp[i]));\n    \
    \        }\n        }\n        T query(int l,int r){\n            if(l==r)return\
    \ std::numeric_limits<T>::max();\n            const u64 tmp=table[r-1]&~((1ULL<<l)-1);\n\
    \            if(tmp==0)return v[r-1];\n            else return v[__builtin_ctzll(tmp)];\n\
    \        }\n    };\n    class sparse_table{\n        std::vector<std::vector<T>>data;\n\
    \        public:\n        sparse_table(std::vector<T> v){\n            int n=v.size(),log=log2(n)+1;\n\
    \            data.resize(n,std::vector<T>(log));\n            for(int i=0;i<n;i++)data[i][0]=v[i];\n\
    \            for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){\n        \
    \        data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);\n            }\n\
    \        }\n        T get(int l,int r){\n            if(l==r)return std::numeric_limits<T>::max();\n\
    \            if(r<l)std::swap(l,r);\n            int k=log2(r-l);\n          \
    \  return f(data[l][k],data[r-(1<<k)][k]);\n        }\n        constexpr static\
    \ T e=std::numeric_limits<T>::max();\n        T f(T s,T t){\n            return\
    \ std::min(s,t);\n        }\n    };\n    constexpr static int b=64;\n    std::vector<T>v;\n\
    \    std::vector<small_rmq*>backet;\n    sparse_table* st=0;\n    public:\n  \
    \  RMQ(std::vector<T>v):v(v){\n        std::vector<T>tmp2;\n        for(int i=0;i<(int)v.size();i+=b){\n\
    \            std::vector<T>tmp;\n            T mn=std::numeric_limits<T>::max();\n\
    \            for(int j=0;i+j<(int)v.size()&&j<b;j++){\n                tmp.push_back(v[i+j]);\n\
    \                if(mn>v[i+j])mn=v[i+j];\n            }\n            tmp2.push_back(mn);\n\
    \            backet.push_back(new small_rmq(tmp));\n        }\n        st=new\
    \ sparse_table(tmp2);\n    }\n    T query(int s,int t){\n        if(s/b==t/b)return\
    \ backet[s/b]->query(s%b,t%b);\n        return std::min({backet[s/b]->query(s%b,b),st->get(s/b+1,t/b),backet[t/b]->query(0,t%b)});\n\
    \    }\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma\
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
    \ 4 \"data_structure/test/LC_RMQ.test.cpp\"\n\nint main(){\n\tlint n,q;\n\tcin>>n>>q;\n\
    \tvector<lint>a(n);\n\trep(i,n)cin>>a[i];\n\tRMQ<lint> rmq(a);\n\twhile(q--){\n\
    \t\tlint s,t;\n\t\tcin>>s>>t;\n\t\tcout<<rmq.query(s,t)<<endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../RMQ.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\tlint n,q;\n\
    \tcin>>n>>q;\n\tvector<lint>a(n);\n\trep(i,n)cin>>a[i];\n\tRMQ<lint> rmq(a);\n\
    \twhile(q--){\n\t\tlint s,t;\n\t\tcin>>s>>t;\n\t\tcout<<rmq.query(s,t)<<endl;\n\
    \t}\n}"
  dependsOn:
  - data_structure/RMQ.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_RMQ.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 13:26:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_RMQ.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_RMQ.test.cpp
- /verify/data_structure/test/LC_RMQ.test.cpp.html
title: data_structure/test/LC_RMQ.test.cpp
---