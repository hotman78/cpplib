---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include<string>\n#include<vector>\n\
    #include<set>\n#include<tuple>\n\n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\n */\n\nstruct rolling_hash{\n    using u64=std::uint64_t;\n\
    \    constexpr static u64 mod=(1ULL<<61)-1;\n    constexpr static u64 base=10007;\n\
    \    int sz;\n    u64 hash;\n    constexpr rolling_hash():sz(0),hash(0){}\n  \
    \  constexpr rolling_hash(char c):sz(1),hash(c){}\n    rolling_hash(std::string\
    \ s):sz(0),hash(0){\n        for(auto c:s)(*this)+=c;\n    }\n    constexpr u64\
    \ pow(u64 s,int t){\n        u64 ret=1;\n        while(t){\n            if(t&1)ret=mul(ret,s);\n\
    \            s=mul(s,s);\n            t/=2;\n        }\n        return ret;\n\
    \    }\n    constexpr u64 add(u64 s,u64 t)noexcept{\n        s+=t;\n        return\
    \ s>=mod?s-mod:s;\n    }\n    constexpr u64 sub(u64 s,u64 t)noexcept{\n      \
    \  if(s<t)s+=mod;\n        return s-t;\n    }\n    constexpr u64 mul(u64 a,u64\
    \ b)noexcept{\n        u64 au=a>>31,ad=a&((1ULL<<31)-1);\n        u64 bu=b>>31,bd=b&((1ULL<<31)-1);\n\
    \        u64 mid=au*bd+ad*bu;\n        u64 ret=(au*bu*2+ad*bd+(mid>>30)+((mid&((1ULL<<30)-1))<<31));\n\
    \        ret=(ret>>61)+(ret&mod);\n        return ret>=mod?ret-mod:ret;\n    }\n\
    \    constexpr rolling_hash operator+(rolling_hash s)const noexcept{return rolling_hash(*this)+=s;}\n\
    \    constexpr bool operator==(rolling_hash s)noexcept{return hash==s.hash&&sz==s.sz;}\n\
    \    constexpr bool operator<(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<std::make_pair(s.hash,s.sz);}\n\
    \    constexpr bool operator>(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>std::make_pair(s.hash,s.sz);}\n\
    \    constexpr bool operator<=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<=std::make_pair(s.hash,s.sz);}\n\
    \    constexpr bool operator>=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>=std::make_pair(s.hash,s.sz);}\n\
    \    constexpr rolling_hash operator+=(rolling_hash s)noexcept{\n        (*this).hash=add((*this).hash*pow(base,s.sz),s.hash);\n\
    \        (*this).sz+=s.sz;\n        return *this;\n    }\n    constexpr int size(){return\
    \ sz;}\n};\n"
  code: "#pragma once\n#include<string>\n#include<vector>\n#include<set>\n#include<tuple>\n\
    \n/**\n * @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n */\n\
    \nstruct rolling_hash{\n    using u64=std::uint64_t;\n    constexpr static u64\
    \ mod=(1ULL<<61)-1;\n    constexpr static u64 base=10007;\n    int sz;\n    u64\
    \ hash;\n    constexpr rolling_hash():sz(0),hash(0){}\n    constexpr rolling_hash(char\
    \ c):sz(1),hash(c){}\n    rolling_hash(std::string s):sz(0),hash(0){\n       \
    \ for(auto c:s)(*this)+=c;\n    }\n    constexpr u64 pow(u64 s,int t){\n     \
    \   u64 ret=1;\n        while(t){\n            if(t&1)ret=mul(ret,s);\n      \
    \      s=mul(s,s);\n            t/=2;\n        }\n        return ret;\n    }\n\
    \    constexpr u64 add(u64 s,u64 t)noexcept{\n        s+=t;\n        return s>=mod?s-mod:s;\n\
    \    }\n    constexpr u64 sub(u64 s,u64 t)noexcept{\n        if(s<t)s+=mod;\n\
    \        return s-t;\n    }\n    constexpr u64 mul(u64 a,u64 b)noexcept{\n   \
    \     u64 au=a>>31,ad=a&((1ULL<<31)-1);\n        u64 bu=b>>31,bd=b&((1ULL<<31)-1);\n\
    \        u64 mid=au*bd+ad*bu;\n        u64 ret=(au*bu*2+ad*bd+(mid>>30)+((mid&((1ULL<<30)-1))<<31));\n\
    \        ret=(ret>>61)+(ret&mod);\n        return ret>=mod?ret-mod:ret;\n    }\n\
    \    constexpr rolling_hash operator+(rolling_hash s)const noexcept{return rolling_hash(*this)+=s;}\n\
    \    constexpr bool operator==(rolling_hash s)noexcept{return hash==s.hash&&sz==s.sz;}\n\
    \    constexpr bool operator<(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<std::make_pair(s.hash,s.sz);}\n\
    \    constexpr bool operator>(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>std::make_pair(s.hash,s.sz);}\n\
    \    constexpr bool operator<=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<=std::make_pair(s.hash,s.sz);}\n\
    \    constexpr bool operator>=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>=std::make_pair(s.hash,s.sz);}\n\
    \    constexpr rolling_hash operator+=(rolling_hash s)noexcept{\n        (*this).hash=add((*this).hash*pow(base,s.sz),s.hash);\n\
    \        (*this).sz+=s.sz;\n        return *this;\n    }\n    constexpr int size(){return\
    \ sz;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2020-09-14 10:40:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
