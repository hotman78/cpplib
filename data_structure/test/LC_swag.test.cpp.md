---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_int998244353.hpp
    title: ModInt(998'244'353)
  - icon: ':heavy_check_mark:'
    path: math/mod_int.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: data_structure/swag.hpp
    title: SWAG(Queue)
  - icon: ':heavy_check_mark:'
    path: alga/maybe.hpp
    title: Maybe
  - icon: ':heavy_check_mark:'
    path: functional/composite.hpp
    title: "\u4E00\u6B21\u95A2\u6570\u306E\u5408\u6210"
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  - icon: ':heavy_check_mark:'
    path: graph_tree/graph_template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"data_structure/test/LC_swag.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n#line 2 \"\
    math/mod_int.hpp\"\n#include<cstdint>\n#include<iostream>\n#include<vector>\n\n\
    /**\n * @brief ModInt\n */\n\ntemplate<int MOD>\nstruct mod_int {\n    using mint=mod_int<MOD>;\n\
    \    using u64 = std::uint_fast64_t;\n    u64 a;\n    constexpr mod_int(const\
    \ long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}\n  \
    \  constexpr u64 &value()noexcept{return a;}\n    constexpr const u64 &value()\
    \ const noexcept {return a;}\n    constexpr mint operator+(const mint rhs)const\
    \ noexcept{return mint(*this) += rhs;}\n    constexpr mint operator-(const mint\
    \ rhs)const noexcept{return mint(*this)-=rhs;}\n    constexpr mint operator*(const\
    \ mint rhs) const noexcept {return mint(*this) *= rhs;}\n    constexpr mint operator/(const\
    \ mint rhs) const noexcept {return mint(*this) /= rhs;}\n    constexpr mint &operator+=(const\
    \ mint rhs) noexcept {\n        a += rhs.a;\n        if (a >= get_mod())a -= get_mod();\n\
    \        return *this;\n    }\n    constexpr mint &operator-=(const mint rhs)\
    \ noexcept {\n        if (a<rhs.a)a += get_mod();\n        a -= rhs.a;\n     \
    \   return *this;\n    }\n    constexpr mint &operator*=(const mint rhs) noexcept\
    \ {\n        a = a * rhs.a % get_mod();\n        return *this;\n    }\n    constexpr\
    \ mint operator++(int) noexcept {\n        a += 1;\n        if (a >= get_mod())a\
    \ -= get_mod();\n        return *this;\n    }\n    constexpr mint operator--(int)\
    \ noexcept {\n        if (a<1)a += get_mod();\n        a -= 1;\n        return\
    \ *this;\n    }\n    constexpr mint &operator/=(mint rhs) noexcept {\n       \
    \ u64 exp=get_mod()-2;\n        while (exp) {\n            if (exp % 2) {\n  \
    \              *this *= rhs;\n            }\n            rhs *= rhs;\n       \
    \     exp /= 2;\n        }\n        return *this;\n    }\n    constexpr bool operator==(mint\
    \ x) noexcept {\n        return a==x.a;\n    }\n    constexpr bool operator!=(mint\
    \ x) noexcept {\n        return a!=x.a;\n    }\n    constexpr bool operator<(mint\
    \ x) noexcept {\n        return a<x.a;\n    }\n    constexpr bool operator>(mint\
    \ x) noexcept {\n        return a>x.a;\n    }\n    constexpr bool operator<=(mint\
    \ x) noexcept {\n        return a<=x.a;\n    }\n    constexpr bool operator>=(mint\
    \ x) noexcept {\n        return a>=x.a;\n    }\n    constexpr static int root(){\n\
    \        mint root = 2;\n        while(root.pow((get_mod()-1)>>1).a==1)root++;\n\
    \        return root.a;\n    }\n    constexpr mint pow(long long n){\n       \
    \ long long x=a;\n        mint ret = 1;\n        while(n>0) {\n            if(n&1)(ret*=x);\n\
    \            (x*=x)%=get_mod();\n            n>>=1;\n        }\n        return\
    \ ret;\n    }\n    constexpr mint inv(){\n        return pow(get_mod()-2);\n \
    \   }\n    static std::vector<mint> fac;\n    static std::vector<mint> ifac;\n\
    \    static bool init;\n    constexpr static int mx=10000001;\n    void build(){\n\
    \        init=0;\n        fac.resize(mx);\n        ifac.resize(mx);\n        fac[0]=1,ifac[0]=1;\n\
    \        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;\n        ifac[mx-1]=fac[mx-1].inv();\n\
    \        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);\n    }\n    mint comb(long\
    \ long b){\n        if(init)build();\n        if(a==0&&b==0)return 1;\n      \
    \  if((long long)a<b)return 0;\n        return fac[a]*ifac[a-b]*ifac[b];\n   \
    \ }\n    mint fact(){\n        if(init)build();\n        return fac[a];\n    }\n\
    \    mint fact_inv(){\n        if(init)build();\n        return ifac[a];\n   \
    \ }\n    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept\
    \ {\n        lhs << rhs.a;\n        return lhs;\n    }\n    friend std::istream&\
    \ operator>>(std::istream& lhs,mint& rhs) noexcept {\n        lhs >> rhs.a;\n\
    \        return lhs;\n    }\n    constexpr static u64 get_mod(){\n        return\
    \ MOD;\n    }\n};\ntemplate<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;\n\
    template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;\ntemplate<int MOD>bool\
    \ mod_int<MOD>::init=1;\n#line 3 \"math/mod_int998244353.hpp\"\nusing mint=mod_int<998'244'353>;\n\
    \n/**\n * @brief ModInt(998'244'353)\n */\n#line 2 \"data_structure/swag.hpp\"\
    \n#include<stack>\n#include<tuple>\n#include<cmath>\n#line 2 \"alga/maybe.hpp\"\
    \n#include<cassert>\n\n/**\n * @brief Maybe\n * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89\n\
    \ */\n\ntemplate<typename T>\nstruct maybe{\n    bool _is_none;\n    T val;\n\
    \    maybe():_is_none(true){}\n    maybe(T val):_is_none(false),val(val){}\n \
    \   T unwrap()const{\n        assert(!_is_none);\n        return val;\n    }\n\
    \    T unwrap_or(T e)const{\n        return _is_none?e:val;\n    }\n    bool is_none()const{return\
    \ _is_none;}\n    bool is_some()const{return !_is_none;}\n};\n\ntemplate<typename\
    \ T,typename F>\nauto expand(F op){\n    return [&op](const maybe<T>& s,const\
    \ maybe<T>& t){\n        if(s.is_none())return t;\n        if(t.is_none())return\
    \ s;\n        return maybe<T>(op(s.unwrap(),t.unwrap()));\n    };\n}\n#line 6\
    \ \"data_structure/swag.hpp\"\n/**\n * @brief SWAG(Queue)\n */\n\ntemplate<typename\
    \ T,typename F>\nclass swag{\n    std::stack<std::pair<T,T>>front,back;\n    F\
    \ f;\n    public:\n    swag(F f=F()):f(f){}\n    inline int size(){\n        return\
    \ front.size()+back.size();\n    }\n    inline int empty(){\n        return front.empty()&&back.empty();\n\
    \    }\n    void push(T val){\n        if(back.empty()){\n            back.emplace(val,val);\n\
    \        }else{\n            back.emplace(val,f(back.top().second,val));\n   \
    \     }\n    }\n    void pop(){\n        if(front.empty()){\n            while(!back.empty()){\n\
    \                const T val=back.top().first;\n                back.pop();\n\
    \                if(front.empty())front.emplace(val,val);\n                else\
    \ front.emplace(val,f(val,front.top().second));\n            }\n        }\n  \
    \      front.pop();\n    }\n    maybe<T> fold(){\n        if(front.empty()&&back.empty())return\
    \ maybe<T>();\n        else if(front.empty()||back.empty())return front.empty()?back.top().second:front.top().second;\n\
    \        return f(front.top().second,back.top().second);\n    }\n};\n#line 3 \"\
    functional/composite.hpp\"\n\n/**\n * @brief \u4E00\u6B21\u95A2\u6570\u306E\u5408\
    \u6210\n */\n\ntemplate<typename T>\nstruct composite{\n    //t(s(x))\n    std::pair<T,T>\
    \ operator()(const std::pair<T,T>& s,const std::pair<T,T>& t){\n        return\
    \ std::make_pair(s.first*t.first,s.second*t.first+t.second);\n    }\n};\n#line\
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
    \ 5 \"graph_tree/graph_template.hpp\"\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\nusing graph=std::vector<std::vector<int>>;\n\
    template<typename T>\nusing graph_w=std::vector<std::vector<std::pair<int,T>>>;\n\
    \ngraph load_graph(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n\
    \        int s,t;\n        std::cin>>s>>t;\n        --s;--t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_digraph(int n,int\
    \ m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n    }\n    return g;\n}\ngraph\
    \ load_graph0(int n,int m){\n    graph g(n);\n    for(int i=0;i<m;++i){\n    \
    \    int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n\
    \    }\n    return g;\n}\ngraph load_digraph0(int n,int m){\n    graph g(n);\n\
    \    for(int i=0;i<m;++i){\n        int s,t;\n        std::cin>>s>>t;\n      \
    \  g[s].push_back(t);\n    }\n    return g;\n}\ngraph load_tree(int n){\n    graph\
    \ g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n\
    \        --s;--t;\n        g[s].push_back(t);\n        g[t].push_back(s);\n  \
    \  }\n    return g;\n}\ngraph load_tree0(int n){\n    graph g(n);\n    for(int\
    \ i=0;i<n-1;++i){\n        int s,t;\n        std::cin>>s>>t;\n        g[s].push_back(t);\n\
    \        g[t].push_back(s);\n    }\n    return g;\n}\ngraph load_treep(int n){\n\
    \    graph g(n);\n    for(int i=0;i<n-1;++i){\n        int t;\n        std::cin>>t;\n\
    \        g[i+1].push_back(t);\n        g[t].push_back(i+1);\n    }\n    return\
    \ g;\n}\n\ntemplate<typename T>\ngraph_w<T> load_graph_weight(int n,int m){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T\
    \ u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_digraph_weight(int n,int m){\n    graph_w<T> g(n);\n    for(int\
    \ i=0;i<m;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        --s;--t;\n        g[s].emplace_back(t,u);\n    }\n    return g;\n}\n\
    template<typename T>\ngraph_w<T> load_graph0_weight(int n,int m){\n    graph_w<T>\
    \ g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n\
    \        g[s].emplace_back(t,u);\n        g[t].emplace_back(s,u);\n    }\n   \
    \ return g;\n}\ntemplate<typename T>\ngraph_w<T> load_digraph0_weight(int n,int\
    \ m){\n    graph_w<T> g(n);\n    for(int i=0;i<m;++i){\n        int s,t;\n   \
    \     T u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n    }\n\
    \    return g;\n}\ntemplate<typename T>\ngraph_w<T> load_tree_weight(int n){\n\
    \    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n        int s,t;\n       \
    \ T u;\n        std::cin>>s>>t>>u;\n        --s;--t;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_tree0_weight(int n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n\
    \        int s,t;\n        T u;\n        std::cin>>s>>t>>u;\n        g[s].emplace_back(t,u);\n\
    \        g[t].emplace_back(s,u);\n    }\n    return g;\n}\ntemplate<typename T>\n\
    graph_w<T> load_treep_weight(int n){\n    graph_w<T> g(n);\n    for(int i=0;i<n-1;++i){\n\
    \        int t;\n        T u;\n        std::cin>>t>>u;\n        g[i+1].emplace_back(t,u);\n\
    \        g[t].emplace_back(i+1,u);\n    }\n    return g;\n}\n#line 6 \"data_structure/test/LC_swag.test.cpp\"\
    \n\nint main(){\n\tlint n;\n\tcin>>n;\n\tswag<pair<mint,mint>,composite<mint>>sw;\n\
    \twhile(n--){\n\t\tlint c;\n\t\tcin>>c;\n\t\tif(c==0){\n\t\t\tlint s,t;\n\t\t\t\
    cin>>s>>t;\n\t\t\tsw.push(make_pair(s,t));\n\t\t}\n\t\tif(c==1){\n\t\t\tsw.pop();\n\
    \t\t}\n\t\tif(c==2){\n\t\t\tlint x;\n\t\t\tcin>>x;\n\t\t\tcout<<composite<mint>()(make_pair(0,x),sw.fold().unwrap_or(make_pair(1,0))).second<<endl;\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../../math/mod_int998244353.hpp\"\n#include \"../swag.hpp\"\n#include\
    \ \"../../functional/composite.hpp\"\n#include \"../../util/template.hpp\"\n\n\
    int main(){\n\tlint n;\n\tcin>>n;\n\tswag<pair<mint,mint>,composite<mint>>sw;\n\
    \twhile(n--){\n\t\tlint c;\n\t\tcin>>c;\n\t\tif(c==0){\n\t\t\tlint s,t;\n\t\t\t\
    cin>>s>>t;\n\t\t\tsw.push(make_pair(s,t));\n\t\t}\n\t\tif(c==1){\n\t\t\tsw.pop();\n\
    \t\t}\n\t\tif(c==2){\n\t\t\tlint x;\n\t\t\tcin>>x;\n\t\t\tcout<<composite<mint>()(make_pair(0,x),sw.fold().unwrap_or(make_pair(1,0))).second<<endl;\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - math/mod_int998244353.hpp
  - math/mod_int.hpp
  - data_structure/swag.hpp
  - alga/maybe.hpp
  - functional/composite.hpp
  - util/template.hpp
  - graph_tree/graph_template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_swag.test.cpp
  requiredBy: []
  timestamp: '2020-09-19 12:18:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_swag.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_swag.test.cpp
- /verify/data_structure/test/LC_swag.test.cpp.html
title: data_structure/test/LC_swag.test.cpp
---
