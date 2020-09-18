---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)"
    links: []
  bundledCode: "#line 2 \"graph_tree/maximum_independent_set.hpp\"\n#include<tuple>\n\
    #include<vector>\n#include<bitset>\n\n/**\n * @brief \u6700\u5927\u72EC\u7ACB\u96C6\
    \u5408(V<=50)\n */\n\nstd::pair<int,std::bitset<50>> maximum_independent_set(std::vector<std::bitset<50>>v,std::bitset<50>b=std::bitset<50>()){\n\
    \tint n=v.size();\n\tauto del=[&](int k){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tv[k][i]=0;\n\
    \t\t\tv[i][k]=0;\n\t\t}\n\t\tb[k]=1;\n\t};\n\tint t=-1;\n\tfor(int i=0;i<n;++i)if(b[i]==0)t=i;\n\
    \tif(t==-1)return std::make_pair(0,std::bitset<50>());\n\tif(v[t].count()<=1){\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])del(i);\n\t\tdel(t);\n\t\tauto p=maximum_independent_set(v,b);\n\
    \t\tp.first++;\n\t\tp.second[t]=1;\n\t\treturn p;\n\t}else{\n\t\tstd::vector<int>tmp;\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])tmp.push_back(i);\n\t\tdel(t);\n\t\tauto p=maximum_independent_set(v,b);\n\
    \t\tfor(auto e:tmp)del(e);\n\t\tauto q=maximum_independent_set(v,b);\n\t\tq.first++;\n\
    \t\tq.second[t]=1;\n\t\treturn p.first>q.first?p:q;\n\t}\n}\n"
  code: "#pragma once\n#include<tuple>\n#include<vector>\n#include<bitset>\n\n/**\n\
    \ * @brief \u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)\n */\n\nstd::pair<int,std::bitset<50>>\
    \ maximum_independent_set(std::vector<std::bitset<50>>v,std::bitset<50>b=std::bitset<50>()){\n\
    \tint n=v.size();\n\tauto del=[&](int k){\n\t\tfor(int i=0;i<n;++i){\n\t\t\tv[k][i]=0;\n\
    \t\t\tv[i][k]=0;\n\t\t}\n\t\tb[k]=1;\n\t};\n\tint t=-1;\n\tfor(int i=0;i<n;++i)if(b[i]==0)t=i;\n\
    \tif(t==-1)return std::make_pair(0,std::bitset<50>());\n\tif(v[t].count()<=1){\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])del(i);\n\t\tdel(t);\n\t\tauto p=maximum_independent_set(v,b);\n\
    \t\tp.first++;\n\t\tp.second[t]=1;\n\t\treturn p;\n\t}else{\n\t\tstd::vector<int>tmp;\n\
    \t\tfor(int i=0;i<n;++i)if(v[t][i])tmp.push_back(i);\n\t\tdel(t);\n\t\tauto p=maximum_independent_set(v,b);\n\
    \t\tfor(auto e:tmp)del(e);\n\t\tauto q=maximum_independent_set(v,b);\n\t\tq.first++;\n\
    \t\tq.second[t]=1;\n\t\treturn p.first>q.first?p:q;\n\t}\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph_tree/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph_tree/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/graph_tree/maximum_independent_set.hpp
- /library/graph_tree/maximum_independent_set.hpp.html
title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408(V<=50)"
---
