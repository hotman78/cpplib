---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u5E73\u65B9\u5206\u5272(WIP)"
    links: []
  bundledCode: "#line 1 \"data_structure/sqrtd.hpp\"\n/**\n * @brief \u5E73\u65B9\u5206\
    \u5272(WIP)\n */\n\ntemplate<typename T>\nstruct sqrtd{\n    vector<T>v;\n   \
    \ int n,b,geta;\n    sqrtd(vector<T>v):v(v),n(v.size()),b(sqrt(n)),geta(n),val(v),bukket((n+b)/b),sum((n+b)/b),cnt((n+b)/b),cnt2((n+b)/b,vector<int>(2*n)){\n\
    \        for(int i=0;i<n;i++){\n            cnt2[i/b][v[i]+geta]++;\n        \
    \    if(v[i]<0)continue;\n            sum[i/b]+=v[i];\n            cnt[i/b]++;\n\
    \        }\n    }\n    vector<T>val;\n    vector<T>bukket,sum,cnt;\n    vector<vector<int>>cnt2;\n\
    \    void add(int l,int r){\n        if(l/b==r/b){\n            for(int i=l;i<r;i++){\n\
    \                cnt2[i/b][val[i]+geta]--;\n                val[i]++;\n      \
    \          cnt2[i/b][val[i]+geta]++;\n                if(val[i]+bukket[i/b]>0)sum[i/b]++;\n\
    \                if(val[i]+bukket[i/b]==0)cnt[i/b]++;\n            }\n       \
    \     return;\n        }\n        for(int i=l;i<l/b*b+b;i++){\n            cnt2[i/b][val[i]+geta]--;\n\
    \            val[i]++;\n            cnt2[i/b][val[i]+geta]++;\n            if(val[i]+bukket[i/b]>0)sum[i/b]++;\n\
    \            if(val[i]+bukket[i/b]==0)cnt[i/b]++;\n        }\n        for(int\
    \ i=l/b+1;i<r/b;i++){\n            bukket[i]++;\n            sum[i]+=cnt[i];\n\
    \            cnt[i]+=cnt2[i][-bukket[i]+geta];\n        }\n        for(int i=r/b*b;i<r;i++){\n\
    \            cnt2[i/b][val[i]+geta]--;\n            val[i]++;\n            cnt2[i/b][val[i]+geta]++;\n\
    \            if(val[i]+bukket[i/b]>0)sum[i/b]++;\n            if(val[i]+bukket[i/b]==0)cnt[i/b]++;\n\
    \        }\n    }\n    void sub(int l,int r){\n        if(l/b==r/b){\n       \
    \     for(int i=l;i<r;i++){\n                cnt2[i/b][val[i]+geta]--;\n     \
    \           val[i]--;\n                cnt2[i/b][val[i]+geta]++;\n           \
    \     if(val[i]+bukket[i/b]>-1)sum[i/b]--;\n                if(val[i]+bukket[i/b]==-1)cnt[i/b]--;\n\
    \            }\n            return;\n        }\n        for(int i=l;i<l/b*b+b;i++){\n\
    \            cnt2[i/b][val[i]+geta]--;\n            val[i]--;\n            cnt2[i/b][val[i]+geta]++;\n\
    \            if(val[i]+bukket[i/b]>-1)sum[i/b]--;\n            if(val[i]+bukket[i/b]==-1)cnt[i/b]--;\n\
    \        }\n        for(int i=l/b+1;i<r/b;i++){\n            cnt[i]-=cnt2[i][-bukket[i]+geta];\n\
    \            bukket[i]--;\n            sum[i]-=cnt[i];\n        }\n        for(int\
    \ i=r/b*b;i<r;i++){\n            cnt2[i/b][val[i]+geta]--;\n            val[i]--;\n\
    \            cnt2[i/b][val[i]+geta]++;\n            if(val[i]+bukket[i/b]>-1)sum[i/b]--;\n\
    \            if(val[i]+bukket[i/b]==-1)cnt[i/b]--;\n        }\n    }\n    T query(int\
    \ l,int r){\n        T res=T();\n        if(l/b==r/b){\n            for(int i=l;i<r;i++){\n\
    \                if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];\n          \
    \  }\n            return res;\n        }\n        for(int i=l;i<l/b*b+b;i++){\n\
    \            if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];\n        }\n   \
    \     for(int i=l/b+1;i<r/b;i++){\n            res+=sum[i];\n        }\n     \
    \   for(int i=r/b*b;i<r;i++){\n            if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];\n\
    \        }\n        return res;\n    }\n};\n"
  code: "/**\n * @brief \u5E73\u65B9\u5206\u5272(WIP)\n */\n\ntemplate<typename T>\n\
    struct sqrtd{\n    vector<T>v;\n    int n,b,geta;\n    sqrtd(vector<T>v):v(v),n(v.size()),b(sqrt(n)),geta(n),val(v),bukket((n+b)/b),sum((n+b)/b),cnt((n+b)/b),cnt2((n+b)/b,vector<int>(2*n)){\n\
    \        for(int i=0;i<n;i++){\n            cnt2[i/b][v[i]+geta]++;\n        \
    \    if(v[i]<0)continue;\n            sum[i/b]+=v[i];\n            cnt[i/b]++;\n\
    \        }\n    }\n    vector<T>val;\n    vector<T>bukket,sum,cnt;\n    vector<vector<int>>cnt2;\n\
    \    void add(int l,int r){\n        if(l/b==r/b){\n            for(int i=l;i<r;i++){\n\
    \                cnt2[i/b][val[i]+geta]--;\n                val[i]++;\n      \
    \          cnt2[i/b][val[i]+geta]++;\n                if(val[i]+bukket[i/b]>0)sum[i/b]++;\n\
    \                if(val[i]+bukket[i/b]==0)cnt[i/b]++;\n            }\n       \
    \     return;\n        }\n        for(int i=l;i<l/b*b+b;i++){\n            cnt2[i/b][val[i]+geta]--;\n\
    \            val[i]++;\n            cnt2[i/b][val[i]+geta]++;\n            if(val[i]+bukket[i/b]>0)sum[i/b]++;\n\
    \            if(val[i]+bukket[i/b]==0)cnt[i/b]++;\n        }\n        for(int\
    \ i=l/b+1;i<r/b;i++){\n            bukket[i]++;\n            sum[i]+=cnt[i];\n\
    \            cnt[i]+=cnt2[i][-bukket[i]+geta];\n        }\n        for(int i=r/b*b;i<r;i++){\n\
    \            cnt2[i/b][val[i]+geta]--;\n            val[i]++;\n            cnt2[i/b][val[i]+geta]++;\n\
    \            if(val[i]+bukket[i/b]>0)sum[i/b]++;\n            if(val[i]+bukket[i/b]==0)cnt[i/b]++;\n\
    \        }\n    }\n    void sub(int l,int r){\n        if(l/b==r/b){\n       \
    \     for(int i=l;i<r;i++){\n                cnt2[i/b][val[i]+geta]--;\n     \
    \           val[i]--;\n                cnt2[i/b][val[i]+geta]++;\n           \
    \     if(val[i]+bukket[i/b]>-1)sum[i/b]--;\n                if(val[i]+bukket[i/b]==-1)cnt[i/b]--;\n\
    \            }\n            return;\n        }\n        for(int i=l;i<l/b*b+b;i++){\n\
    \            cnt2[i/b][val[i]+geta]--;\n            val[i]--;\n            cnt2[i/b][val[i]+geta]++;\n\
    \            if(val[i]+bukket[i/b]>-1)sum[i/b]--;\n            if(val[i]+bukket[i/b]==-1)cnt[i/b]--;\n\
    \        }\n        for(int i=l/b+1;i<r/b;i++){\n            cnt[i]-=cnt2[i][-bukket[i]+geta];\n\
    \            bukket[i]--;\n            sum[i]-=cnt[i];\n        }\n        for(int\
    \ i=r/b*b;i<r;i++){\n            cnt2[i/b][val[i]+geta]--;\n            val[i]--;\n\
    \            cnt2[i/b][val[i]+geta]++;\n            if(val[i]+bukket[i/b]>-1)sum[i/b]--;\n\
    \            if(val[i]+bukket[i/b]==-1)cnt[i/b]--;\n        }\n    }\n    T query(int\
    \ l,int r){\n        T res=T();\n        if(l/b==r/b){\n            for(int i=l;i<r;i++){\n\
    \                if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];\n          \
    \  }\n            return res;\n        }\n        for(int i=l;i<l/b*b+b;i++){\n\
    \            if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];\n        }\n   \
    \     for(int i=l/b+1;i<r/b;i++){\n            res+=sum[i];\n        }\n     \
    \   for(int i=r/b*b;i<r;i++){\n            if(val[i]+bukket[i/b]>0)res+=val[i]+bukket[i/b];\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sqrtd.hpp
  requiredBy: []
  timestamp: '2020-09-18 12:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sqrtd.hpp
layout: document
redirect_from:
- /library/data_structure/sqrtd.hpp
- /library/data_structure/sqrtd.hpp.html
title: "\u5E73\u65B9\u5206\u5272(WIP)"
---
