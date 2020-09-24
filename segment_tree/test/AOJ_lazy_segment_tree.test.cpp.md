---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: segment_tree/lazy_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  - icon: ':heavy_check_mark:'
    path: functional/range_add_and_range_sum.hpp
    title: "\u533A\u9593\u52A0\u7B97"
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"segment_tree/test/AOJ_lazy_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
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
    \ \"segment_tree/lazy_segment_tree.hpp\"\n\ntemplate<typename T,typename E,typename\
    \ F,typename G,typename H>\nclass lazy_segment_tree{\n    using i64=long long;\n\
    \    i64 n;\n    i64 sz;\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        maybe<T> val=maybe<T>();\n        maybe<E> lazy=maybe<E>();\n       \
    \ np lch=nullptr,rch=nullptr;\n        node(){}\n    };\n    np root=new node();\n\
    \    maybe<T> update(i64 a,i64 b,E x,i64 l,i64 r,np t){\n        auto f=expand<T,F>(_f);\n\
    \        eval(t,l,r);\n        //\u533A\u9593\u5916\n        if(r<=a||b<=l)return\
    \ t->val;\n        //\u5168\u90E8\u533A\u9593\u5185\n        if(a<=l&&r<=b){\n\
    \            t->lazy=x;\n            eval(t,l,r);\n            return t->val;\n\
    \        }\n        //\u4E00\u90E8\u533A\u9593\u5185\n        return t->val=f(update(a,b,x,l,(l+r)/2,t->lch),update(a,b,x,(l+r)/2,r,t->rch));\n\
    \    }\n    maybe<T> get(i64 a,i64 b,i64 l,i64 r,np t){\n        auto f=expand<T,F>(_f);\n\
    \        eval(t,l,r);\n        //\u533A\u9593\u5916\n        if(r<=a||b<=l)return\
    \ maybe<T>();\n        //\u5168\u90E8\u533A\u9593\u5185\n        if(a<=l&&r<=b)return\
    \ t->val;\n        //\u4E00\u90E8\u533A\u9593\u5185\n        return f(get(a,b,l,(l+r)/2,t->lch),get(a,b,(l+r)/2,r,t->rch));\n\
    \    }\n    void eval(np t,i64 l,i64 r){\n        auto g=expand<E,G>(_g);\n  \
    \      if(r-l>1){\n            if(!t->lch)t->lch=new node();\n            if(!t->rch)t->rch=new\
    \ node();\n            t->lch->lazy=g(t->lch->lazy,t->lazy);\n            t->rch->lazy=g(t->rch->lazy,t->lazy);\n\
    \        }\n        t->val=h(t->val,t->lazy,l,r);\n        t->lazy=maybe<E>();\n\
    \    }\n    F _f;G _g;H _h;\n    maybe<T> h(const maybe<T>&s,const maybe<E>&t,int\
    \ l,int r){\n        if(t.is_none())return s;\n        else return maybe<T>(_h(s,t.unwrap(),l,r));\n\
    \    }\n    public:\n    lazy_segment_tree(i64 sz,F f=F(),G g=G(),H h=H()):n(1),sz(sz),_f(f),_g(g),_h(h){while(n<sz)n<<=1;}\n\
    \    //0-indexed [a,b)\n    void update(i64 a,i64 b,E x){update(a,b,x,0,n,root);}\n\
    \    //0-indexed [a,b)\n    maybe<T> get(i64 a,i64 b){return get(a,b,0,n,root);}\n\
    };\n#line 3 \"functional/range_add_and_range_sum.hpp\"\n\n/**\n * @brief \u533A\
    \u9593\u52A0\u7B97\n */\n\ntemplate<typename T,typename E>\nstruct range_add_and_range_sum{\n\
    \    T operator()(const maybe<T>& s,const E& t,int l,int r){\n        return s.unwrap_or(T())+t*(r-l);\n\
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
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n//#include\
    \ \"../graph_tree/graph_template.hpp\"\n#line 5 \"segment_tree/test/AOJ_lazy_segment_tree.test.cpp\"\
    \n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n    lazy_segment_tree<lint,lint,plus<lint>,plus<lint>,range_add_and_range_sum<lint,lint>>seg(n);\n\
    \    while(q--){\n        lint c;\n        cin>>c;\n        if(c==0){\n      \
    \      lint s,t,u;\n            cin>>s>>t>>u;\n            seg.update(s-1,t,u);\n\
    \        }else{\n            lint s,t;\n            cin>>s>>t;\n            cout<<seg.get(s-1,t).unwrap_or(0)<<endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include \"../lazy_segment_tree.hpp\"\n#include \"../../functional/range_add_and_range_sum.hpp\"\
    \n#include \"../../util/template.hpp\"\n\nint main(){\n    lint n,q;\n    cin>>n>>q;\n\
    \    lazy_segment_tree<lint,lint,plus<lint>,plus<lint>,range_add_and_range_sum<lint,lint>>seg(n);\n\
    \    while(q--){\n        lint c;\n        cin>>c;\n        if(c==0){\n      \
    \      lint s,t,u;\n            cin>>s>>t>>u;\n            seg.update(s-1,t,u);\n\
    \        }else{\n            lint s,t;\n            cin>>s>>t;\n            cout<<seg.get(s-1,t).unwrap_or(0)<<endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - segment_tree/lazy_segment_tree.hpp
  - alga/maybe.hpp
  - functional/range_add_and_range_sum.hpp
  - util/template.hpp
  isVerificationFile: true
  path: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/segment_tree/test/AOJ_lazy_segment_tree.test.cpp
- /verify/segment_tree/test/AOJ_lazy_segment_tree.test.cpp.html
title: segment_tree/test/AOJ_lazy_segment_tree.test.cpp
---
