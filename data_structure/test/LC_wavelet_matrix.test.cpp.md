---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: WaveletMatrix(WIP)
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: BitVector
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"data_structure/test/LC_wavelet_matrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 2 \"data_structure/wavelet_matrix.hpp\"\
    \n#include<vector>\n#include<algorithm>\n#line 2 \"data_structure/bit_vector.hpp\"\
    \n\n/**\n * @brief BitVector\n */\n\nclass bitvec{\n\tusing u32=unsigned int;\n\
    \tusing u8=unsigned char;\n    using lint=long long;\n\t//4*10^6\u5BFE\u5FDC\n\
    \t//\u30D6\u30ED\u30C3\u30AF\u5E458,\u30C1\u30E3\u30F3\u30AF\u5E45256\n\tconst\
    \ int bw=8,cw=256;\n\tconst int len=15625,sz=4000000;\n\tbool data[4000000]={0};\n\
    \tu32 chunk[15626];\n\tu8 block[15625][33];\n\tpublic:\n\tbitvec(){}\n\tvoid build(){\n\
    \t\tchunk[0]=0;\n\t\tfor(int i=0;i<15625;i++){\n\t\t\tblock[i][0]=0;\n\t\t\tfor(int\
    \ j=0;j<31;j++){\n\t\t\t\tblock[i][j+1]=block[i][j];\n\t\t\t\tfor(int k=0;k<8;k++)block[i][j+1]+=data[i*cw+j*bw+k];\n\
    \t\t\t}\n\t\t\tchunk[i+1]=chunk[i]+block[i][31];\n\t\t\tfor(int k=0;k<8;k++)chunk[i+1]+=data[i*cw+31*bw+k];\n\
    \t\t}\n\t}\n\tinline void set(int idx,bool b){data[idx]=b;}\n\tinline bool get(int\
    \ idx){return data[idx];}\n    inline int rank(int idx,bool b)const{\n       \
    \ if(b)return rank1(idx);\n        else return idx-rank1(idx);\n\t}\n\tinline\
    \ int rank1(int idx)const{\n\t\tint a=idx/cw,b=idx%cw/bw,c=idx%bw;\n\t\tint res=chunk[a]+block[a][b];\n\
    \t\tfor(int i=1;i<c+1;i++)res+=data[idx-i];\n\t\treturn res;\n\t}\n\tinline int\
    \ select(int num){\n\t\tif (num==0)return 0;\n        if (rank1(sz)<num)return\
    \ -1;\n        int ok=sz,ng=0;\n\t\twhile (ok-ng>1) {\n\t\t\tint mid=(ok+ng)/2;\n\
    \t\t\tif (rank1(mid)>=num)ok =mid;\n\t\t\telse ng=mid;\n\t\t}\n\t\treturn ok;\n\
    \t}\n};\n#line 5 \"data_structure/wavelet_matrix.hpp\"\n\n/**\n * @brief WaveletMatrix(WIP)\n\
    \ */\n\nclass wavelet_matrix{\n    using lint=long long;\n    const lint MAXLOG=32;\n\
    \tstd::vector<bitvec> matrix;\n    lint sz;\n\tpublic:\n\twavelet_matrix(std::vector<lint>\
    \ data){\n        sz=data.size();\n\t\tmatrix.resize(MAXLOG);\n\t\tfor(int i=MAXLOG-1;i>=0;i--){\n\
    \t\t\tfor(int j=0;j<(int)data.size();j++){\n\t\t\t\tmatrix[i].set(j,data[j]&(1LL<<i));\n\
    \t\t\t}\n\t\t\tmatrix[i].build();\n\t\t\tstd::stable_sort(data.begin(),data.end(),[&](auto\
    \ s,auto t){return (s&(1LL<<i))<(t&(1LL<<i));});\n\t\t}\n\t}\n    lint rank(lint\
    \ pos,lint x){\n        lint s=0,e=pos;\n        for(int i=MAXLOG-1;i>=0;i--){\n\
    \            bool b=x&(1LL<<i);\n            s=matrix[i].rank(s,b);\n        \
    \    e=matrix[i].rank(e,b);\n            if(b==1){\n                lint l=matrix[i].rank(sz,0);\n\
    \                s+=l;\n                e+=l;\n            }\n        }\n    \
    \    return e-s;\n    }\n\tvoid select(){\n\t\tfor(int i=MAXLOG;i>=0;i--){\n\n\
    \t\t}\n\t}\n    lint kth_element(lint l,lint r,lint k){\n        lint ans=0;\n\
    \        for(int i=MAXLOG-1;i>=0;i--){\n            lint cnt=matrix[i].rank(r,0)-matrix[i].rank(l,0);\n\
    \            lint b=cnt<=k;\n            ans+=b<<i;\n            l=matrix[i].rank(l,b);\n\
    \            r=matrix[i].rank(r,b);\n            if(b==1){\n                lint\
    \ t=matrix[i].rank(sz,0);\n                k-=cnt;\n                l+=t;\n  \
    \              r+=t;\n            }\n        }\n        return ans;\n    }\n};\n\
    #line 2 \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
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
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n//#include\
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"data_structure/test/LC_wavelet_matrix.test.cpp\"\
    \n\nint main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\
    \twavelet_matrix wm(a);\n\twhile(q--){\n\t\tlint l,r,k;\n\t\tcin>>l>>r>>k;\n\t\
    \tcout<<wm.kth_element(l,r,k)<<endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"../wavelet_matrix.hpp\"\n#include \"../../util/template.hpp\"\n\nint\
    \ main(){\n\tlint n,q;\n\tcin>>n>>q;\n\tvec a(n);\n\trep(i,n)cin>>a[i];\n\twavelet_matrix\
    \ wm(a);\n\twhile(q--){\n\t\tlint l,r,k;\n\t\tcin>>l>>r>>k;\n\t\tcout<<wm.kth_element(l,r,k)<<endl;\n\
    \t}\n}"
  dependsOn:
  - data_structure/wavelet_matrix.hpp
  - data_structure/bit_vector.hpp
  - util/template.hpp
  isVerificationFile: true
  path: data_structure/test/LC_wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 10:34:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/LC_wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/LC_wavelet_matrix.test.cpp
- /verify/data_structure/test/LC_wavelet_matrix.test.cpp.html
title: data_structure/test/LC_wavelet_matrix.test.cpp
---
