---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: BitVector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_wavelet_matrix.test.cpp
    title: data_structure/test/LC_wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: WaveletMatrix(WIP)
    links: []
  bundledCode: "#line 2 \"data_structure/wavelet_matrix.hpp\"\n#include<vector>\n\
    #include<algorithm>\n#line 2 \"data_structure/bit_vector.hpp\"\n\n/**\n * @brief\
    \ BitVector\n */\n\nclass bitvec{\n\tusing u32=unsigned int;\n\tusing u8=unsigned\
    \ char;\n    using lint=long long;\n\t//4*10^6\u5BFE\u5FDC\n\t//\u30D6\u30ED\u30C3\
    \u30AF\u5E458,\u30C1\u30E3\u30F3\u30AF\u5E45256\n\tconst int bw=8,cw=256;\n\t\
    const int len=15625,sz=4000000;\n\tbool data[4000000]={0};\n\tu32 chunk[15626];\n\
    \tu8 block[15625][33];\n\tpublic:\n\tbitvec(){}\n\tvoid build(){\n\t\tchunk[0]=0;\n\
    \t\tfor(int i=0;i<15625;i++){\n\t\t\tblock[i][0]=0;\n\t\t\tfor(int j=0;j<31;j++){\n\
    \t\t\t\tblock[i][j+1]=block[i][j];\n\t\t\t\tfor(int k=0;k<8;k++)block[i][j+1]+=data[i*cw+j*bw+k];\n\
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
    \              r+=t;\n            }\n        }\n        return ans;\n    }\n \
    \   lint lower_bound(lint l,lint r,lint k){\n        lint ans=0;\n        for(int\
    \ i=MAXLOG-1;i>=0;i--){\n            lint cnt=matrix[i].rank(r,0)-matrix[i].rank(l,0);\n\
    \            lint b=(k>>i&1);\n            if(b)ans+=cnt;\n            l=matrix[i].rank(l,b);\n\
    \            r=matrix[i].rank(r,b);\n            if(b==1){\n                lint\
    \ t=matrix[i].rank(sz,0);\n                l+=t;\n                r+=t;\n    \
    \        }\n        }\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\n#include\"bit_vector.hpp\"\
    \n\n/**\n * @brief WaveletMatrix(WIP)\n */\n\nclass wavelet_matrix{\n    using\
    \ lint=long long;\n    const lint MAXLOG=32;\n\tstd::vector<bitvec> matrix;\n\
    \    lint sz;\n\tpublic:\n\twavelet_matrix(std::vector<lint> data){\n        sz=data.size();\n\
    \t\tmatrix.resize(MAXLOG);\n\t\tfor(int i=MAXLOG-1;i>=0;i--){\n\t\t\tfor(int j=0;j<(int)data.size();j++){\n\
    \t\t\t\tmatrix[i].set(j,data[j]&(1LL<<i));\n\t\t\t}\n\t\t\tmatrix[i].build();\n\
    \t\t\tstd::stable_sort(data.begin(),data.end(),[&](auto s,auto t){return (s&(1LL<<i))<(t&(1LL<<i));});\n\
    \t\t}\n\t}\n    lint rank(lint pos,lint x){\n        lint s=0,e=pos;\n       \
    \ for(int i=MAXLOG-1;i>=0;i--){\n            bool b=x&(1LL<<i);\n            s=matrix[i].rank(s,b);\n\
    \            e=matrix[i].rank(e,b);\n            if(b==1){\n                lint\
    \ l=matrix[i].rank(sz,0);\n                s+=l;\n                e+=l;\n    \
    \        }\n        }\n        return e-s;\n    }\n\tvoid select(){\n\t\tfor(int\
    \ i=MAXLOG;i>=0;i--){\n\n\t\t}\n\t}\n    lint kth_element(lint l,lint r,lint k){\n\
    \        lint ans=0;\n        for(int i=MAXLOG-1;i>=0;i--){\n            lint\
    \ cnt=matrix[i].rank(r,0)-matrix[i].rank(l,0);\n            lint b=cnt<=k;\n \
    \           ans+=b<<i;\n            l=matrix[i].rank(l,b);\n            r=matrix[i].rank(r,b);\n\
    \            if(b==1){\n                lint t=matrix[i].rank(sz,0);\n       \
    \         k-=cnt;\n                l+=t;\n                r+=t;\n            }\n\
    \        }\n        return ans;\n    }\n    lint lower_bound(lint l,lint r,lint\
    \ k){\n        lint ans=0;\n        for(int i=MAXLOG-1;i>=0;i--){\n          \
    \  lint cnt=matrix[i].rank(r,0)-matrix[i].rank(l,0);\n            lint b=(k>>i&1);\n\
    \            if(b)ans+=cnt;\n            l=matrix[i].rank(l,b);\n            r=matrix[i].rank(r,b);\n\
    \            if(b==1){\n                lint t=matrix[i].rank(sz,0);\n       \
    \         l+=t;\n                r+=t;\n            }\n        }\n        return\
    \ ans;\n    }\n};\n"
  dependsOn:
  - data_structure/bit_vector.hpp
  isVerificationFile: false
  path: data_structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2021-01-30 10:06:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_wavelet_matrix.test.cpp
documentation_of: data_structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/data_structure/wavelet_matrix.hpp
- /library/data_structure/wavelet_matrix.hpp.html
title: WaveletMatrix(WIP)
---
