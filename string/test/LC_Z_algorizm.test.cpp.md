---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/Z_algorizm.hpp
    title: "Z\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
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
  bundledCode: "#line 1 \"string/test/LC_Z_algorizm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\n#line 2 \"string/Z_algorizm.hpp\"\
    \n#include<string>\n#include<vector>\n#include<algorithm>\n\n/**\n * @brief Z\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\n */\n\nstd::vector<int> Z_algorizm(const std::string&\
    \ s){\n    std::vector<int>res(s.size());\n    res[0]=s.size();\n    int i=1,j=0;\n\
    \    while(i<(int)s.size()){\n        while(i+j<(int)s.size()&&s[j]==s[i+j])++j;\n\
    \        res[i]=j;\n        if(j==0){++i;continue;}\n        int k=1;\n      \
    \  while(i+k<(int)s.size()&&k+res[k]<j)res[i+k]=res[k],++k;\n        i+=k;j-=k;\n\
    \    }\n    return res;\n}\nint find_first(const std::string& s,const std::string&\
    \ t){\n    auto d=Z_algorizm(s+\"#\"+t);\n    auto itr=std::find(d.begin()+s.size(),d.end(),s.size());\n\
    \    if(itr!=d.end())return itr-d.begin()-s.size();\n    else return -1;\n}\n\
    int count(const std::string& s,const std::string& t){\n    auto d=Z_algorizm(s+\"\
    #\"+t);\n    return std::count(d.begin()+s.size(),d.end(),s.size());\n}\n#line\
    \ 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
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
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"string/test/LC_Z_algorizm.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin>>s;\n    output(Z_algorizm(s));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../Z_algorizm.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \    string s;\n    cin>>s;\n    output(Z_algorizm(s));\n}"
  dependsOn:
  - string/Z_algorizm.hpp
  - util/template.hpp
  isVerificationFile: true
  path: string/test/LC_Z_algorizm.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 16:21:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: string/test/LC_Z_algorizm.test.cpp
layout: document
redirect_from:
- /verify/string/test/LC_Z_algorizm.test.cpp
- /verify/string/test/LC_Z_algorizm.test.cpp.html
title: string/test/LC_Z_algorizm.test.cpp
---
