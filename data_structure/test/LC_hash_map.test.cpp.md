---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/hash_map.hpp
    title: HashMap
  - icon: ':heavy_check_mark:'
    path: util/fastIO.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B(WIP)"
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"data_structure/test/LC_hash_map.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n#line 2 \"util/template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx2\")\n#include<bits/stdc++.h>\nusing namespace std;\nstruct\
    \ __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
    typedef long long lint;\n#define INF (1LL<<60)\n#define IINF (1<<30)\n#define\
    \ EPS (1e-10)\n#define endl ('\\n')\ntypedef vector<lint> vec;\ntypedef vector<vector<lint>>\
    \ mat;\ntypedef vector<vector<vector<lint>>> mat3;\ntypedef vector<string> svec;\n\
    typedef vector<vector<string>> smat;\ntemplate<typename T>using V=vector<T>;\n\
    template<typename T>using VV=V<V<T>>;\ntemplate<typename T>inline void output(T\
    \ t){bool f=0;for(auto i:t){cout<<(f?\" \":\"\")<<i;f=1;}cout<<endl;}\ntemplate<typename\
    \ T>inline void output2(T t){for(auto i:t)output(i);}\ntemplate<typename T>inline\
    \ void debug(T t){bool f=0;for(auto i:t){cerr<<(f?\" \":\"\")<<i;f=1;}cerr<<endl;}\n\
    template<typename T>inline void debug2(T t){for(auto i:t)output(i);}\n#define\
    \ loop(n) for(long long _=0;_<(long long)(n);++_)\n#define _overload4(_1,_2,_3,_4,name,...)\
    \ name\n#define __rep(i,a) repi(i,0,a,1)\n#define _rep(i,a,b) repi(i,a,b,1)\n\
    #define repi(i,a,b,c) for(long long i=(long long)(a);i<(long long)(b);i+=c)\n\
    #define rep(...) _overload4(__VA_ARGS__,repi,_rep,__rep)(__VA_ARGS__)\n#define\
    \ _overload3_rev(_1,_2,_3,name,...) name\n#define _rep_rev(i,a) repi_rev(i,0,a)\n\
    #define repi_rev(i,a,b) for(long long i=(long long)(b)-1;i>=(long long)(a);--i)\n\
    #define rrep(...) _overload3_rev(__VA_ARGS__,repi_rev,_rep_rev)(__VA_ARGS__)\n\
    \n// #define rep(i,...) for(auto i:range(__VA_ARGS__)) \n// #define rrep(i,...)\
    \ for(auto i:reversed(range(__VA_ARGS__)))\n// #define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)\n\
    // #define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)\n// #define irep(i)\
    \ for(lint i=0;;++i)\n// inline vector<long long> range(long long n){if(n<=0)return\
    \ vector<long long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return\
    \ v;}\n// inline vector<long long> range(long long a,long long b){if(b<=a)return\
    \ vector<long long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return\
    \ v;}\n// inline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\n// template<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n#define\
    \ extrep(v,...) for(auto v:__MAKE_MAT__({__VA_ARGS__}))\n#define bit(n,a) ((n>>a)&1)\n\
    vector<vector<long long>> __MAKE_MAT__(vector<long long> v){if(v.empty())return\
    \ vector<vector<long long>>(1,vector<long long>());long long n=v.back();v.pop_back();vector<vector<long\
    \ long>> ret;vector<vector<long long>> tmp=__MAKE_MAT__(v);for(auto e:tmp)for(long\
    \ long i=0;i<n;++i){ret.push_back(e);ret.back().push_back(i);}return ret;}\nusing\
    \ graph=vector<vector<int>>;\ntemplate<typename T>using graph_w=vector<vector<pair<int,T>>>;\n\
    template<typename T,typename E>ostream& operator<<(ostream& out,pair<T,E>v){out<<\"\
    (\"<<v.first<<\",\"<<v.second<<\")\";return out;}\nconstexpr inline long long\
    \ powll(long long a,long long b){long long res=1;while(b--)res*=a;return res;}\n\
    #line 3 \"data_structure/hash_map.hpp\"\n/**\n * @brief HashMap\n */\n\ntemplate<typename\
    \ T,typename E,typename F=std::hash<T>>\nstruct hash_map{\n    struct node{\n\
    \        T key;E val;\n        unsigned long b;\n        node():key(T()),val(E()),b(0){}\n\
    \        node(T key,E val):key(key),val(val),b(0){}\n        static node* alc;\n\
    \        static size_t cnt;\n        static size_t alc_sz;\n        void* operator\
    \ new(size_t){\n            if(alc_sz==cnt){\n                alc_sz*=2;\n   \
    \             alc=(node*)malloc(alc_sz*sizeof(node));\n                cnt=0;\n\
    \            }\n            return alc+cnt++;\n        }\n    };\n    size_t sz;\n\
    \    node* point;\n    constexpr static size_t mod_list[24]={37,67,131,257,521,1031,2053,4099,8209,16411,32771,65537,131101,262147,524309,1048583,2097169,4194319,8388617,16777259,33554467,67108879,134217757,268435459};\n\
    \    node** table;\n    F op;\n    hash_map(F op=F()):sz(15),op(op){\n       \
    \ table=new node*[mod_list[sz]]();\n    }\n    node** _realloc(){\n        const\
    \ size_t old_sz=sz;\n        while(1){\n            sz++;\n            bool fail=0;\n\
    \            node** tmp=new node*[mod_list[sz]]();\n            for(node** itr=table;itr<table+mod_list[old_sz];++itr){\n\
    \                if(*itr==0)continue;\n                const size_t ha=op((*itr)->key)%mod_list[sz];\n\
    \                (*itr)->b=0;\n                if(insert(tmp,*itr,ha).first==0){fail=1;break;}\n\
    \            }\n            if(fail){\n                delete[] tmp;\n       \
    \     }\n            else {\n                delete[] table;\n               \
    \ table=tmp;\n                break;\n            }\n        }\n        return\
    \ table;\n    }\n    std::pair<bool,node*> insert(node** table,node* t,size_t\
    \ tmp){\n        if(!table[tmp])return {true,table[tmp]=t};\n        size_t k=0;\n\
    \        unsigned long tt=~table[tmp]->b;\n        const size_t pre=tmp;\n   \
    \     unsigned long x=1;\n        while(tt){\n            tmp+=(k=__builtin_ctzl(tt)+1);\n\
    \            x<<=k;\n            tt>>=k;\n            tmp%=mod_list[sz];\n   \
    \         if(!table[tmp]){\n                table[tmp]=t;\n                table[pre]->b|=x>>1;\n\
    \                return {true,table[tmp]};\n            }\n        }\n       \
    \ return {false,nullptr};\n    }\n    std::pair<bool,node*> search(T key,size_t\
    \ tmp){\n        int k=0;\n        if(!table[tmp])return {false,nullptr};\n  \
    \      if(table[tmp]->key==key)return {true,table[tmp]};\n\n        unsigned long\
    \ t=table[tmp]->b;\n        while(t){\n            tmp+=(k=__builtin_ctzl(t)+1);\n\
    \            tmp%=mod_list[sz];\n            t>>=k;\n            if(table[tmp]->key==key)return\
    \ {true,table[tmp]};\n        }\n        return {false,nullptr};\n    }\n    E&\
    \ operator[](T key){\n        size_t ha=op(key)%mod_list[sz];\n        auto res=search(key,ha);\n\
    \        if(res.first)return res.second->val;\n        else {\n            while(1){\n\
    \                auto res=insert(table,new node(key,E()),ha);\n              \
    \  if(res.first)return res.second->val;\n                _realloc();\n       \
    \         ha=op(key)%mod_list[sz];\n            }\n        }\n    }\n};\ntemplate<typename\
    \ T,typename E,typename F=std::hash<T>>typename hash_map<T,E,F>::node* hash_map<T,E,F>::node::alc=(node*)malloc(sizeof(node));\n\
    template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::cnt=0;\n\
    template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::alc_sz=1;\n\
    #line 1 \"util/fastIO.hpp\"\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B(WIP)\n\
    \ */\n\nstruct fastI{\n    char in[1<<26];\n    char const*o;\n    fastI(){\n\
    \        o = in; \n        in[fread(in,1,sizeof(in)-4,stdin)]=0;\n    }\n    fastI&\
    \ operator>>(char& c){\n        while(*o&&*o<=32)++o;\n        c=*o++;\n     \
    \   return *this;\n    }\n    fastI& operator>>(int& u){\n        u=0; \n    \
    \    unsigned s=0;\n        while(*o&&*o<=32)++o;\n        if (*o == '-')s = ~s,\
    \ ++o; else if (*o == '+')++o;\n        while('0'<=*o && *o<='9')u = (u<<3) +\
    \ (u << 1) + (*o++ - '0');\n        (u^=s)+=!!s;\n        return *this;\n    }\n\
    \    fastI& operator>>(long long& u){\n        u=0;\n        uint64_t s=0;\n \
    \       while(*o&&*o<=32)++o;\n        if (*o == '-')s = ~s, ++o; else if (*o\
    \ == '+')++o;\n        while('0'<=*o && *o<='9')u = (u<<3) + (u << 1) + (*o++\
    \ - '0');\n        (u^=s)+=!!s;\n        return *this;\n    }\n} fin;\n\nstruct\
    \ fastO{\n    char out[1<<26];\n    char *o;\n    fastO(){\n        o=out;\n \
    \   }\n    ~fastO(){\n        fwrite(out,1,o-out,stdout);\n    }\n    fastO& operator<<(const\
    \ char& c){\n        *o++=c;\n        return *this;\n    }\n    fastO& operator<<(int\
    \ u){\n         if(u){\n            auto be=o;\n            while(u)*o++=u%10+'0',u/=10;\n\
    \            auto en=o;\n            while(be<en)std::swap(*--en,*be++);\n   \
    \     }else *o++='0';\n        return *this;\n    }\n    fastO& operator<<(long\
    \ long u){\n        if(u){\n            auto be=o;\n            while(u)*o++=u%10+'0',u/=10;\n\
    \            auto en=o;\n            while(be<en)std::swap(*--en,*be++);\n   \
    \     }else *o++='0';\n        return *this;\n    }\n} fout;\n#line 5 \"data_structure/test/LC_hash_map.test.cpp\"\
    \n\nint main(){\n    hash_map<lint,lint>m;\n    lint q;\n    fin>>q;\n    while(q--){\n\
    \        lint c;\n        fin>>c;\n        if(c==0){\n            lint k,v;\n\
    \            fin>>k>>v;\n            m[k]=v;\n        }else{\n            lint\
    \ k;\n            fin>>k;\n            fout<<m[k]<<endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\"\
    ../../util/template.hpp\"\n#include\"../hash_map.hpp\"\n#include\"../../util/fastIO.hpp\"\
    \n\nint main(){\n    hash_map<lint,lint>m;\n    lint q;\n    fin>>q;\n    while(q--){\n\
    \        lint c;\n        fin>>c;\n        if(c==0){\n            lint k,v;\n\
    \            fin>>k>>v;\n            m[k]=v;\n        }else{\n            lint\
    \ k;\n            fin>>k;\n            fout<<m[k]<<endl;\n        }\n    }\n}"
  dependsOn:
  - util/template.hpp
  - data_structure/hash_map.hpp
  - util/fastIO.hpp
  isVerificationFile: true
  path: data_structure/test/LC_hash_map.test.cpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_hash_map.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_hash_map.test.cpp
- /verify/data_structure/test/LC_hash_map.test.cpp.html
title: data_structure/test/LC_hash_map.test.cpp
---