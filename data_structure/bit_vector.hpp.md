---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: WaveletMatrix(WIP)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_wavelet_matrix.test.cpp
    title: data_structure/test/LC_wavelet_matrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: BitVector
    links: []
  bundledCode: "#line 2 \"data_structure/bit_vector.hpp\"\n\n/**\n * @brief BitVector\n\
    \ */\n\nclass bitvec{\n\tusing u32=unsigned int;\n\tusing u8=unsigned char;\n\
    \    using lint=long long;\n\t//4*10^6\u5BFE\u5FDC\n\t//\u30D6\u30ED\u30C3\u30AF\
    \u5E458,\u30C1\u30E3\u30F3\u30AF\u5E45256\n\tconst int bw=8,cw=256;\n\tconst int\
    \ len=15625,sz=4000000;\n\tbool data[4000000]={0};\n\tu32 chunk[15626];\n\tu8\
    \ block[15625][33];\n\tpublic:\n\tbitvec(){}\n\tvoid build(){\n\t\tchunk[0]=0;\n\
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
    \t}\n};\n"
  code: "#pragma once\n\n/**\n * @brief BitVector\n */\n\nclass bitvec{\n\tusing u32=unsigned\
    \ int;\n\tusing u8=unsigned char;\n    using lint=long long;\n\t//4*10^6\u5BFE\
    \u5FDC\n\t//\u30D6\u30ED\u30C3\u30AF\u5E458,\u30C1\u30E3\u30F3\u30AF\u5E45256\n\
    \tconst int bw=8,cw=256;\n\tconst int len=15625,sz=4000000;\n\tbool data[4000000]={0};\n\
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
    \t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/bit_vector.hpp
  requiredBy:
  - data_structure/wavelet_matrix.hpp
  timestamp: '2020-09-18 12:11:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_wavelet_matrix.test.cpp
documentation_of: data_structure/bit_vector.hpp
layout: document
redirect_from:
- /library/data_structure/bit_vector.hpp
- /library/data_structure/bit_vector.hpp.html
title: BitVector
---
