---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cartesian_tree.hpp
    title: cartesian_tree
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"data_structure/test/LC_cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#line 2 \"data_structure/cartesian_tree.hpp\"\
    \n#include<vector>\n#include<stack>\n#include<cstdint>\n#include<functional>\n\
    \n/**\n * @brief cartesian_tree\n */\n\ntemplate<typename T,typename F=std::less<T>>\n\
    struct cartesian_tree{\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        np ch[2]={0,0};\n        T val;\n        int pos;\n        int sz=0;\n\
    \        node(T val,int pos):val(val),pos(pos){}\n    };\n    int size(np t){return\
    \ t?t->sz:0;}\n    np update(np t){}\n    np root=0;\n    int sz=0;\n    F comp;\n\
    \    cartesian_tree(std::vector<T>v,F comp):comp(comp){\n        for(auto e:v)push_back(e);\n\
    \    }\n    cartesian_tree(std::vector<T>v):comp(F()){\n        for(auto e:v)push_back(e);\n\
    \    }\n    cartesian_tree(F comp):comp(comp){}\n    cartesian_tree():comp(F()){}\n\
    \n    void push_back(int val){\n        static std::stack<np>stk;\n        while(!stk.empty()&&comp(val,stk.top()->val))stk.pop();\n\
    \        np t=new node(val,sz);\n        if(stk.empty()){\n            t->ch[0]=root;\n\
    \            root=t;\n        }else{\n            t->ch[0]=stk.top()->ch[1];\n\
    \            stk.top()->ch[1]=t;\n        }\n        stk.emplace(t);\n       \
    \ sz++;\n    }\n    std::int64_t update_size(np t){\n        if(!t)return 0;\n\
    \        return t->sz=update_size(t->ch[0])+1+update_size(t->ch[1]);\n    }\n\
    \    std::vector<T>get(){\n\t\tstd::vector<T>v(sz);\n\t\tauto f=[&](auto f,np\
    \ t){\n\t\t\tif(!t)return;\n\t\t\tf(f,t->ch[0]);\n\t\t\tif(t->ch[0])v[t->ch[0]->pos]=t->pos;\n\
    \t\t\tif(t->ch[1])v[t->ch[1]->pos]=t->pos;\n\t\t\tf(f,t->ch[1]);\n\t\t};\n\t\t\
    v[root->pos]=root->pos;\n\t\tf(f,root);\n\t\treturn v;\n\t}\n};\n#line 2 \"util/template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
    typedef long long lint;\n#define INF (1LL<<60)\n#define IINF (1<<30)\n#define\
    \ EPS (1e-10)\n#define endl ('\\n')\ntypedef vector<lint> vec;\ntypedef vector<vector<lint>>\
    \ mat;\ntypedef vector<vector<vector<lint>>> mat3;\ntypedef vector<string> svec;\n\
    typedef vector<vector<string>> smat;\ntemplate<typename T>inline void output(T\
    \ t){bool f=0;for(auto i:t){cout<<(f?\" \":\"\")<<i;f=1;}cout<<endl;}\ntemplate<typename\
    \ T>inline void output2(T t){for(auto i:t)output(i);}\ntemplate<typename T>inline\
    \ void debug(T t){bool f=0;for(auto i:t){cerr<<(f?\" \":\"\")<<i;f=1;}cerr<<endl;}\n\
    template<typename T>inline void debug2(T t){for(auto i:t)output(i);}\n#define\
    \ loop(n) for(long long _=0;_<(long long)(n);++_)\n#define rep(i,...) for(auto\
    \ i:range(__VA_ARGS__)) \n#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))\n\
    #define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)\n#define rrepi(i,a,b)\
    \ for(lint i=lint(b)-1;i>=lint(a);--i)\n#define irep(i) for(lint i=0;;++i)\ninline\
    \ vector<long long> range(long long n){if(n<=0)return vector<long long>();vector<long\
    \ long>v(n);iota(v.begin(),v.end(),0LL);return v;}\ninline vector<long long> range(long\
    \ long a,long long b){if(b<=a)return vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
    \ v;}\ninline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\ntemplate<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n#define\
    \ extrep(v,...) for(auto v:__MAKE_MAT__({__VA_ARGS__}))\nvector<vector<long long>>\
    \ __MAKE_MAT__(vector<long long> v){if(v.empty())return vector<vector<long long>>(1,vector<long\
    \ long>());long long n=v.back();v.pop_back();vector<vector<long long>> ret;vector<vector<long\
    \ long>> tmp=__MAKE_MAT__(v);for(auto e:tmp)for(long long i=0;i<n;++i){ret.push_back(e);ret.back().push_back(i);}return\
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\ntemplate<typename T,typename\
    \ E>ostream& operator<<(ostream& out,pair<T,E>v){out<<\"(\"<<v.first<<\",\"<<v.second<<\"\
    )\";return out;}\n#line 4 \"data_structure/test/LC_cartesian_tree.test.cpp\"\n\
    \nint main(){\n\tlint n;\n\tcin>>n;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\tcartesian_tree<lint>ct(a);\n\
    \toutput(ct.get());\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#include\
    \ \"../cartesian_tree.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \tlint n;\n\tcin>>n;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\tcartesian_tree<lint>ct(a);\n\
    \toutput(ct.get());\n}"
  dependsOn:
  - data_structure/cartesian_tree.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 18:26:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_cartesian_tree.test.cpp
- /verify/data_structure/test/LC_cartesian_tree.test.cpp.html
title: data_structure/test/LC_cartesian_tree.test.cpp
---
