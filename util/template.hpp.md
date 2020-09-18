---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/test/LC_sum_power_poly_limit.cpp
    title: math/test/LC_sum_power_poly_limit.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/segment_tree.test.cpp
    title: segment_tree/test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/LC_convolution_1000000007.test.cpp
    title: convolution/test/LC_convolution_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/LC_convolution_998244353.test.cpp
    title: convolution/test/LC_convolution_998244353.test.cpp
  - icon: ':heavy_check_mark:'
    path: util/test/LC_Suffix_Array.test.cpp
    title: util/test/LC_Suffix_Array.test.cpp
  - icon: ':heavy_check_mark:'
    path: util/test/LC_Number_of_Substrings.test.cpp
    title: util/test/LC_Number_of_Substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/AOJ_prime_factor.test.cpp
    title: math/test/AOJ_prime_factor.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_prime_factor.test.cpp
    title: math/test/LC_prime_factor.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_mod_sqrt.test.cpp
    title: math/test/LC_mod_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_totient_sum.test.cpp
    title: math/test/LC_totient_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_mod_log.test.cpp
    title: math/test/LC_mod_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/AOJ_is_prime.test.cpp
    title: math/test/AOJ_is_prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_floor_sum.test.cpp
    title: math/test/LC_floor_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/AOJ_binary_search.test.cpp
    title: math/test/AOJ_binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/AOJ_prime_list.test.cpp
    title: math/test/AOJ_prime_list.test.cpp
  - icon: ':heavy_check_mark:'
    path: math/test/LC_tetration.test.cpp
    title: math/test/LC_tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/test/YUKI_Aho_Corasick.test.cpp
    title: string/test/YUKI_Aho_Corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/test/LC_Z_algorizm.test.cpp
    title: string/test/LC_Z_algorizm.test.cpp
  - icon: ':heavy_check_mark:'
    path: string/test/LC_online_Z_algorizm.test.cpp
    title: string/test/LC_online_Z_algorizm.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_sparse_table.test.cpp
    title: data_structure/test/LC_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_fast_set.test.cpp
    title: data_structure/test/LC_fast_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_binary_indexed_tree.test.cpp
    title: data_structure/test/LC_binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_birary_heap.test.cpp
    title: data_structure/test/LC_birary_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_cartesian_tree.test.cpp
    title: data_structure/test/LC_cartesian_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_binary_trie.test.cpp
    title: data_structure/test/LC_binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_segment_add_get_min.test.cpp
    title: data_structure/test/LC_segment_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_line_add_get_min.test.cpp
    title: data_structure/test/LC_line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_disjoint_sparse_table.test.cpp
    title: data_structure/test/LC_disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_RMQ.test.cpp
    title: data_structure/test/LC_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_wavelet_matrix.test.cpp
    title: data_structure/test/LC_wavelet_matrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma\
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
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n"
  code: "#pragma once\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#pragma GCC target(\"avx\")\n#include<bits/stdc++.h>\nusing namespace std;\n\
    struct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n"
  dependsOn: []
  isVerificationFile: false
  path: util/template.hpp
  requiredBy:
  - math/test/LC_sum_power_poly_limit.cpp
  timestamp: '2020-09-18 12:55:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/segment_tree.test.cpp
  - convolution/test/LC_convolution_1000000007.test.cpp
  - convolution/test/LC_convolution_998244353.test.cpp
  - util/test/LC_Suffix_Array.test.cpp
  - util/test/LC_Number_of_Substrings.test.cpp
  - math/test/AOJ_prime_factor.test.cpp
  - math/test/LC_prime_factor.test.cpp
  - math/test/LC_mod_sqrt.test.cpp
  - math/test/LC_totient_sum.test.cpp
  - math/test/LC_mod_log.test.cpp
  - math/test/AOJ_is_prime.test.cpp
  - math/test/LC_floor_sum.test.cpp
  - math/test/AOJ_binary_search.test.cpp
  - math/test/AOJ_prime_list.test.cpp
  - math/test/LC_tetration.test.cpp
  - string/test/YUKI_Aho_Corasick.test.cpp
  - string/test/LC_Z_algorizm.test.cpp
  - string/test/LC_online_Z_algorizm.test.cpp
  - data_structure/test/LC_sparse_table.test.cpp
  - data_structure/test/LC_fast_set.test.cpp
  - data_structure/test/LC_binary_indexed_tree.test.cpp
  - data_structure/test/LC_birary_heap.test.cpp
  - data_structure/test/LC_cartesian_tree.test.cpp
  - data_structure/test/LC_binary_trie.test.cpp
  - data_structure/test/LC_segment_add_get_min.test.cpp
  - data_structure/test/LC_line_add_get_min.test.cpp
  - data_structure/test/LC_disjoint_sparse_table.test.cpp
  - data_structure/test/LC_RMQ.test.cpp
  - data_structure/test/LC_wavelet_matrix.test.cpp
documentation_of: util/template.hpp
layout: document
redirect_from:
- /library/util/template.hpp
- /library/util/template.hpp.html
title: util/template.hpp
---
