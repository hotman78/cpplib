---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/li_chao_tree.hpp
    title: LiChaoTree
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"data_structure/test/LC_segment_add_get_min.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line\
    \ 2 \"data_structure/li_chao_tree.hpp\"\n#include<limits>\n#include<cmath>\n#include<algorithm>\n\
    /**\n * @brief LiChaoTree\n */\n\ntemplate<typename T>\nclass LHT{\n    using\
    \ lint = long long;\n    struct node;\n    using np = node*;\n    struct node{\n\
    \        T a,b;\n        np ch[2]={nullptr,nullptr};\n        node(T a,T b):a(a),b(b){}\n\
    \    };\n    np root=nullptr;\n    T sign(T x){return (x>0)-(x<0);}\n    np update(T\
    \ a,T b,lint p,lint q,lint l,lint r,np t){\n        if(!t)t=new node(0,std::numeric_limits<T>::max());\n\
    \        //\u533A\u9593\u5916\n        if(r<=p||q<=l)return t;\n        //\u5168\
    \u3066\u533A\u9593\u5185\n        if(p<=l&&r<=q){\n            lint m=(l+r)/2;\n\
    \            if(a*m+b<=(t->a)*m+(t->b)){\n                std::swap(a,t->a);\n\
    \                std::swap(b,t->b);\n            }\n            if(r-l==1||a==t->a)return\
    \ t;\n            if(sign((a-t->a)*l+(b-t->b))*sign((a-t->a)*m+(b-t->b))<=0)t->ch[0]=update(a,b,p,q,l,m,t->ch[0]);\n\
    \            if(sign((a-t->a)*m+(b-t->b))*sign((a-t->a)*r+(b-t->b))<=0)t->ch[1]=update(a,b,p,q,m,r,t->ch[1]);\n\
    \            return t;\n        }\n        //\u4E00\u90E8\u533A\u9593\u5185\n\
    \        t->ch[0]=update(a,b,p,q,l,(l+r)/2,t->ch[0]);\n        t->ch[1]=update(a,b,p,q,(l+r)/2,r,t->ch[1]);\n\
    \        return t;\n    }\n    T get(lint x,lint l,lint r,np t){\n        if(!t)return\
    \ std::numeric_limits<T>::max();\n        if(r-l==1)return t->a*x+t->b;\n    \
    \    lint m=(l+r)/2;\n        if(l<=x&&x<m)return std::min(t->a*x+t->b,get(x,l,m,t->ch[0]));\n\
    \        else return std::min(t->a*x+t->b,get(x,m,r,t->ch[1]));\n    }\n    lint\
    \ mn;\n    lint mx;\n    public:\n    LHT(lint mn=-1LL<<30,lint mx=1LL<<30):mn(mn),mx(mx){}\n\
    \    T get(lint x){\n        return get(x,mn,mx,root);\n    }\n    void add_line(T\
    \ a,T b){\n        root=update(a,b,mn,mx,mn,mx,root);\n    }\n    void add_segment(lint\
    \ l,lint r,T a,T b){\n        root=update(a,b,l,r,mn,mx,root);\n    }\n};\n#line\
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
    \ 4 \"data_structure/test/LC_segment_add_get_min.test.cpp\"\n\nint main(){\n\t\
    lint n,q;\n\tcin>>n>>q;\n\tLHT<lint>lht;\n\twhile(n--){\n\t\tlint l,r,s,t;\n\t\
    \tcin>>l>>r>>s>>t;\n\t\tlht.add_segment(l,r,s,t);\n\t}\n\twhile(q--){\n\t\tlint\
    \ c;\n\t\tcin>>c;\n\t\tif(c==0){\n\t\t\tlint l,r,s,t;\n\t\t\tcin>>l>>r>>s>>t;\n\
    \t\t\tlht.add_segment(l,r,s,t);\n\t\t}else{\n\t\t\tlint x;\n\t\t\tcin>>x;\n\t\t\
    \tlint t=lht.get(x);\n\t\t\tif(t==std::numeric_limits<lint>::max())cout<<\"INFINITY\"\
    <<endl;\n\t\t\telse cout<<t<<endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"../li_chao_tree.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tLHT<lint>lht;\n\twhile(n--){\n\t\tlint\
    \ l,r,s,t;\n\t\tcin>>l>>r>>s>>t;\n\t\tlht.add_segment(l,r,s,t);\n\t}\n\twhile(q--){\n\
    \t\tlint c;\n\t\tcin>>c;\n\t\tif(c==0){\n\t\t\tlint l,r,s,t;\n\t\t\tcin>>l>>r>>s>>t;\n\
    \t\t\tlht.add_segment(l,r,s,t);\n\t\t}else{\n\t\t\tlint x;\n\t\t\tcin>>x;\n\t\t\
    \tlint t=lht.get(x);\n\t\t\tif(t==std::numeric_limits<lint>::max())cout<<\"INFINITY\"\
    <<endl;\n\t\t\telse cout<<t<<endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - data_structure/li_chao_tree.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 14:05:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_segment_add_get_min.test.cpp
- /verify/data_structure/test/LC_segment_add_get_min.test.cpp.html
title: data_structure/test/LC_segment_add_get_min.test.cpp
---
