---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/LC_hash_map.test.cpp
    title: data_structure/test/LC_hash_map.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9AD8\u901F\u5165\u51FA\u529B(WIP)"
    links: []
  bundledCode: "#line 1 \"util/fastIO.hpp\"\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\
    \u529B(WIP)\n */\n\nstruct fastI{\n    char in[1<<26];\n    char const*o;\n  \
    \  fastI(){\n        o = in; \n        in[fread(in,1,sizeof(in)-4,stdin)]=0;\n\
    \    }\n    fastI& operator>>(char& c){\n        while(*o&&*o<=32)++o;\n     \
    \   c=*o++;\n        return *this;\n    }\n    fastI& operator>>(int& u){\n  \
    \      u=0; \n        unsigned s=0;\n        while(*o&&*o<=32)++o;\n        if\
    \ (*o == '-')s = ~s, ++o; else if (*o == '+')++o;\n        while('0'<=*o && *o<='9')u\
    \ = (u<<3) + (u << 1) + (*o++ - '0');\n        (u^=s)+=!!s;\n        return *this;\n\
    \    }\n    fastI& operator>>(long long& u){\n        u=0;\n        uint64_t s=0;\n\
    \        while(*o&&*o<=32)++o;\n        if (*o == '-')s = ~s, ++o; else if (*o\
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
    \     }else *o++='0';\n        return *this;\n    }\n} fout;\n"
  code: "/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B(WIP)\n */\n\nstruct fastI{\n\
    \    char in[1<<26];\n    char const*o;\n    fastI(){\n        o = in; \n    \
    \    in[fread(in,1,sizeof(in)-4,stdin)]=0;\n    }\n    fastI& operator>>(char&\
    \ c){\n        while(*o&&*o<=32)++o;\n        c=*o++;\n        return *this;\n\
    \    }\n    fastI& operator>>(int& u){\n        u=0; \n        unsigned s=0;\n\
    \        while(*o&&*o<=32)++o;\n        if (*o == '-')s = ~s, ++o; else if (*o\
    \ == '+')++o;\n        while('0'<=*o && *o<='9')u = (u<<3) + (u << 1) + (*o++\
    \ - '0');\n        (u^=s)+=!!s;\n        return *this;\n    }\n    fastI& operator>>(long\
    \ long& u){\n        u=0;\n        uint64_t s=0;\n        while(*o&&*o<=32)++o;\n\
    \        if (*o == '-')s = ~s, ++o; else if (*o == '+')++o;\n        while('0'<=*o\
    \ && *o<='9')u = (u<<3) + (u << 1) + (*o++ - '0');\n        (u^=s)+=!!s;\n   \
    \     return *this;\n    }\n} fin;\n\nstruct fastO{\n    char out[1<<26];\n  \
    \  char *o;\n    fastO(){\n        o=out;\n    }\n    ~fastO(){\n        fwrite(out,1,o-out,stdout);\n\
    \    }\n    fastO& operator<<(const char& c){\n        *o++=c;\n        return\
    \ *this;\n    }\n    fastO& operator<<(int u){\n         if(u){\n            auto\
    \ be=o;\n            while(u)*o++=u%10+'0',u/=10;\n            auto en=o;\n  \
    \          while(be<en)std::swap(*--en,*be++);\n        }else *o++='0';\n    \
    \    return *this;\n    }\n    fastO& operator<<(long long u){\n        if(u){\n\
    \            auto be=o;\n            while(u)*o++=u%10+'0',u/=10;\n          \
    \  auto en=o;\n            while(be<en)std::swap(*--en,*be++);\n        }else\
    \ *o++='0';\n        return *this;\n    }\n} fout;"
  dependsOn: []
  isVerificationFile: false
  path: util/fastIO.hpp
  requiredBy: []
  timestamp: '2020-10-21 08:20:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/LC_hash_map.test.cpp
documentation_of: util/fastIO.hpp
layout: document
redirect_from:
- /library/util/fastIO.hpp
- /library/util/fastIO.hpp.html
title: "\u9AD8\u901F\u5165\u51FA\u529B(WIP)"
---
