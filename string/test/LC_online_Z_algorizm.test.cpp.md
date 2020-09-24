---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/online_Zalgo.hpp
    title: "\u30AA\u30F3\u30E9\u30A4\u30F3Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"string/test/LC_online_Z_algorizm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"string/online_Zalgo.hpp\"\
    \n#include<string>\n#include<vector>\n#include<set>\n\n/**\n * @brief \u30AA\u30F3\
    \u30E9\u30A4\u30F3Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n */\n\nstruct online_Zalgo{\n\
    \    std::vector<int>z;\n    std::set<int>memo;\n    std::vector<std::vector<int>>hist;\n\
    \    std::string s=\"\";\n    int sz=0;\n    void add(char c){\n        s+=c;\n\
    \        memo.emplace(sz);\n        z.push_back(-1);\n        hist.push_back(std::vector<int>());\n\
    \        sz++;\n        int mx=-1;\n        for(auto itr=next(memo.begin(),1);itr!=memo.end();){\n\
    \            auto idx=*itr;\n            if(s[sz-idx-1]!=s.back()){\n        \
    \        itr=memo.erase(itr);\n                z[idx]=sz-idx-1;\n            \
    \    hist.back().push_back(idx);\n            }else{\n                mx=idx;\n\
    \                break;\n            }\n        }\n        if(mx==-1)return;\n\
    \        for(auto e:hist[sz-1-mx]){\n            memo.erase(mx+e);\n         \
    \   z[mx+e]=sz-(mx+e)-1;\n            hist.back().push_back(mx+e);\n        }\n\
    \    }\n    int operator[](int idx){\n        if(memo.count(idx))return sz-idx;\n\
    \        else return z[idx];\n    }\n};\n#line 2 \"util/template.hpp\"\n#pragma\
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
    \ i=0;i<t.size();i++)output(t[i]);}\n#define loop(n) for(long long _=0;_<(long\
    \ long)(n);++_)\n#define rep(i,...) for(auto i:range(__VA_ARGS__)) \n#define rrep(i,...)\
    \ for(auto i:reversed(range(__VA_ARGS__)))\n#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)\n\
    #define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)\n#define irep(i) for(lint\
    \ i=0;;++i)\ninline vector<long long> range(long long n){if(n<=0)return vector<long\
    \ long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return v;}\ninline\
    \ vector<long long> range(long long a,long long b){if(b<=a)return vector<long\
    \ long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return v;}\ninline\
    \ vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\ntemplate<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n//#include\
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"string/test/LC_online_Z_algorizm.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin>>s;\n    online_Zalgo z;\n    for(auto\
    \ e:s)z.add(e);\n    vec v(s.size());\n    rep(i,s.size())v[i]=z[i];\n    output(v);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../online_Zalgo.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \    string s;\n    cin>>s;\n    online_Zalgo z;\n    for(auto e:s)z.add(e);\n\
    \    vec v(s.size());\n    rep(i,s.size())v[i]=z[i];\n    output(v);\n}"
  dependsOn:
  - string/online_Zalgo.hpp
  - util/template.hpp
  isVerificationFile: true
  path: string/test/LC_online_Z_algorizm.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 16:21:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: string/test/LC_online_Z_algorizm.test.cpp
layout: document
redirect_from:
- /verify/string/test/LC_online_Z_algorizm.test.cpp
- /verify/string/test/LC_online_Z_algorizm.test.cpp.html
title: string/test/LC_online_Z_algorizm.test.cpp
---
