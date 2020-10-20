---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alga/maybe.hpp
    title: Maybe
  - icon: ':x:'
    path: functional/update.hpp
    title: "\u66F4\u65B0"
  - icon: ':x:'
    path: segment_tree/dual_segment_tree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"segment_tree/test/AOJ_dual_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#line 2 \"alga/maybe.hpp\"\n#include<cassert>\n\n/**\n * @brief Maybe\n * @see\
    \ https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 3\
    \ \"segment_tree/dual_segment_tree.hpp\"\n\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n */\n\ntemplate<typename T,typename F>\nclass dual_segment_tree{\n\
    \tstruct node;\n\tusing np=node*;\n\tusing i64=long long;\n\tstruct node{\n\t\t\
    maybe<T> val;\n\t\tnp ch[2]={nullptr,nullptr};\n\t\tnode(maybe<T> val=maybe<T>()):val(val){}\n\
    \t};\n\tnp root=nullptr;\n\ti64 n=1,sz;\n    F op;\n\tpublic:\n\tdual_segment_tree(i64\
    \ sz,F op=F()):sz(sz),op(op){while(n<sz)n<<=1;}\n\tinline void update(i64 l,i64\
    \ r,T x){update(l,r,x,0,n,root);}\n\tinline maybe<T> get(i64 x){return get(x,0,n,root);}\n\
    \tprivate:\n\tvoid eval(np& t){\n        auto f=expand<T,F>(op);\n\t\tif(t->val.is_none())return;\n\
    \t\tif(!t->ch[0])t->ch[0]=new node();\n\t\tif(!t->ch[1])t->ch[1]=new node();\n\
    \t\tt->ch[0]->val=f(t->ch[0]->val,t->val);\n\t\tt->ch[1]->val=f(t->ch[1]->val,t->val);\n\
    \t\tt->val=maybe<T>();\n\t}\n\tvoid update(i64 a,i64 b,T x,i64 l,i64 r,np& t){\n\
    \        auto f=expand<T,F>(op);\n        if(!t)t=new node();\n\t\tif(r-l>1)eval(t);\n\
    \t\tif(r<=a||b<=l)return;\n\t\telse if(a<=l&&r<=b)t->val=f(t->val,x);\n\t    else\
    \ if(r-l>1){\n\t\t\tupdate(a,b,x,l,(l+r)/2,t->ch[0]);\n\t\t\tupdate(a,b,x,(l+r)/2,r,t->ch[1]);\n\
    \t\t}\n\t}\n\tmaybe<T> get(i64 x,i64 l,i64 r,np& t){\n        auto f=expand<T,F>(op);\n\
    \        if(!t)t=new node();\n\t\tif(r-l>1)eval(t);\n\t\tif(x<l||r<=x)return maybe<T>();\n\
    \        else if(r-l==1){\n            return t->val;\n        }\n\t\telse return\
    \ f(get(x,l,(l+r)/2,t->ch[0]),get(x,(l+r)/2,r,t->ch[1]));\n\t}\n};\n#line 2 \"\
    functional/update.hpp\"\n\n/**\n * @brief \u66F4\u65B0\n */\n\ntemplate<typename\
    \ T>\nstruct update{\n    T operator()(const T& s,const T& t){\n        return\
    \ t;\n    }\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\n\
    using namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ ret;}\n//#include \"../graph_tree/graph_template.hpp\"\n#line 5 \"segment_tree/test/AOJ_dual_segment_tree.test.cpp\"\
    \n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n    dual_segment_tree<lint,update<lint>>seg(n);\n\
    \    while(q--){\n        lint c;\n        cin>>c;\n        if(c==0){\n      \
    \      lint s,t,u;\n            cin>>s>>t>>u;\n            seg.update(s,t+1,u);\n\
    \        }else{\n            lint x;\n            cin>>x;\n            cout<<seg.get(x).unwrap_or((1LL<<31)-1)<<endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include \"../dual_segment_tree.hpp\"\n#include \"../../functional/update.hpp\"\
    \n#include \"../../util/template.hpp\"\n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n\
    \    dual_segment_tree<lint,update<lint>>seg(n);\n    while(q--){\n        lint\
    \ c;\n        cin>>c;\n        if(c==0){\n            lint s,t,u;\n          \
    \  cin>>s>>t>>u;\n            seg.update(s,t+1,u);\n        }else{\n         \
    \   lint x;\n            cin>>x;\n            cout<<seg.get(x).unwrap_or((1LL<<31)-1)<<endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - segment_tree/dual_segment_tree.hpp
  - alga/maybe.hpp
  - functional/update.hpp
  - util/template.hpp
  isVerificationFile: true
  path: segment_tree/test/AOJ_dual_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: segment_tree/test/AOJ_dual_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/AOJ_dual_segment_tree.test.cpp
- /verify/segment_tree/test/AOJ_dual_segment_tree.test.cpp.html
title: segment_tree/test/AOJ_dual_segment_tree.test.cpp
---
