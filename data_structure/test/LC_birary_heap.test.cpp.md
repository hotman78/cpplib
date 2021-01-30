---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_heap.hpp
    title: BinaryHeap
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"data_structure/test/LC_birary_heap.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"data_structure/binary_heap.hpp\"\
    \n#include<vector>\n#include<algorithm>\n#include<functional>\n\n/**\n * @brief\
    \ BinaryHeap\n */\n\ntemplate<typename T,typename F=std::less<T>>\nstruct binary_heap{\n\
    \tint idx=1;\n\tstruct node{\n\t\tint idx;\n\t\tT val;\n\t\tnode(int idx,T val):idx(idx),val(val){}\n\
    \t};\n\tusing np=node*;\n\tstd::vector<np>v;\n\tF comp;\n\tbinary_heap(F comp):v(2,0),comp(comp){}\n\
    \tbinary_heap():v(2,0),comp(F()){}\n\tvoid __swap(np& s,np& t){\n\t\tstd::swap(s,t);\n\
    \t\tstd::swap(s->idx,t->idx);\n\t}\n\tvoid up(int k){\n\t\twhile(k>1&&comp(v[k]->val,v[k/2]->val)){\n\
    \t\t\t__swap(v[k],v[k/2]);\n\t\t\tk/=2;\n\t\t}\n\t}\n\tvoid down(int k){\n\t\t\
    while(1){\n\t\t\tif(k*2+1<idx&&(comp(v[k*2]->val,v[k]->val)||comp(v[k*2+1]->val,v[k]->val))){\n\
    \t\t\t\tif(comp(v[k*2]->val,v[k*2+1]->val)){\n\t\t\t\t\t__swap(v[k],v[k*2]);\n\
    \t\t\t\t\tk=k*2;\n\t\t\t\t}else{\n\t\t\t\t\t__swap(v[k],v[k*2+1]);\n\t\t\t\t\t\
    k=k*2+1;\n\t\t\t\t}\n\t\t\t}else if(k*2<idx&&comp(v[k*2]->val,v[k]->val)){\n\t\
    \t\t\t__swap(v[k],v[k*2]);\n\t\t\t\tk=k*2;\n\t\t\t}else{\n\t\t\t\tbreak;\n\t\t\
    \t}\n\t\t}\n\t}\n\tnp insert(T val){\n\t\tif((int)v.size()<=idx+1)v.resize(v.size()*2,0);\n\
    \t\tnp res=new node(idx,val);\n\t\tv[idx]=res;\n\t\tup(idx++);\n\t\treturn res;\n\
    \t}\n\tT top(){\n\t\treturn v[1]->val;\n\t}\n\tvoid pop(){\n\t\t__swap(v[1],v[--idx]);\n\
    \t\tdown(1);\n\t}\n\tint size(){\n\t\treturn idx-1;\n\t}\n\tbool empty(){\n\t\t\
    return idx==1;\n\t}\n\tvoid modify(np t,T val){\n\t\tt->val=val;\n\t\tup(t->idx);\n\
    \t\tdown(t->idx);\n\t}\n};\n#line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx2\"\
    )\n#include<bits/stdc++.h>\nusing namespace std;\nstruct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;\n\
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
    #line 4 \"data_structure/test/LC_birary_heap.test.cpp\"\n\nint main(){\n\tlint\
    \ n,m,s,t;\n\tcin>>n>>m>>s>>t;\n\tvector<vector<pair<lint,lint>>>g(n);\n\trep(i,m){\n\
    \t\tlint a,b,c;\n\t\tcin>>a>>b>>c;\n\t\tg[a].emplace_back(b,c);\n\t}\n\tbinary_heap<pair<lint,lint>>que;\n\
    \tvector<binary_heap<pair<lint,lint>>::np>v(n);\n\trep(i,n)v[i]=que.insert(make_pair(INF,i));\n\
    \tque.modify(v[s],make_pair(0,s));\n\tvector<lint>from(n,-1);\n\tvector<lint>dif(n,INF);\n\
    \tdif[s]=0;\n\twhile(!que.empty()){\n\t\tauto [cost,now]=que.top();\n\t\tque.pop();\n\
    \t\tfor(auto [e,c]:g[now]){\n\t\t\tif(chmin(dif[e],dif[now]+c)){\n\t\t\t\tfrom[e]=now;\n\
    \t\t\t\tque.modify(v[e],make_pair(dif[e],e));\n\t\t\t}\n\t\t}\n\t}\n\tif(dif[t]==INF){\n\
    \t\tcout<<-1<<endl;\n\t\treturn 0;\n\t}\n\tlint now=t;\n\tvector<pair<lint,lint>>ans;\n\
    \twhile(1){\n\t\tif(now==s)break;\n\t\tans.emplace_back(from[now],now);\n\t\t\
    now=from[now];\n\t}\n\tcout<<dif[t]<<\" \"<<ans.size()<<endl;\n\treverse(all(ans));\n\
    \tfor(auto e:ans){\n\t\tcout<<e.first<<\" \"<<e.second<<endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../binary_heap.hpp\"\n#include \"../../util/template.hpp\"\n\nint main(){\n\
    \tlint n,m,s,t;\n\tcin>>n>>m>>s>>t;\n\tvector<vector<pair<lint,lint>>>g(n);\n\t\
    rep(i,m){\n\t\tlint a,b,c;\n\t\tcin>>a>>b>>c;\n\t\tg[a].emplace_back(b,c);\n\t\
    }\n\tbinary_heap<pair<lint,lint>>que;\n\tvector<binary_heap<pair<lint,lint>>::np>v(n);\n\
    \trep(i,n)v[i]=que.insert(make_pair(INF,i));\n\tque.modify(v[s],make_pair(0,s));\n\
    \tvector<lint>from(n,-1);\n\tvector<lint>dif(n,INF);\n\tdif[s]=0;\n\twhile(!que.empty()){\n\
    \t\tauto [cost,now]=que.top();\n\t\tque.pop();\n\t\tfor(auto [e,c]:g[now]){\n\t\
    \t\tif(chmin(dif[e],dif[now]+c)){\n\t\t\t\tfrom[e]=now;\n\t\t\t\tque.modify(v[e],make_pair(dif[e],e));\n\
    \t\t\t}\n\t\t}\n\t}\n\tif(dif[t]==INF){\n\t\tcout<<-1<<endl;\n\t\treturn 0;\n\t\
    }\n\tlint now=t;\n\tvector<pair<lint,lint>>ans;\n\twhile(1){\n\t\tif(now==s)break;\n\
    \t\tans.emplace_back(from[now],now);\n\t\tnow=from[now];\n\t}\n\tcout<<dif[t]<<\"\
    \ \"<<ans.size()<<endl;\n\treverse(all(ans));\n\tfor(auto e:ans){\n\t\tcout<<e.first<<\"\
    \ \"<<e.second<<endl;\n\t}\n}"
  dependsOn:
  - data_structure/binary_heap.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_birary_heap.test.cpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_birary_heap.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_birary_heap.test.cpp
- /verify/data_structure/test/LC_birary_heap.test.cpp.html
title: data_structure/test/LC_birary_heap.test.cpp
---
