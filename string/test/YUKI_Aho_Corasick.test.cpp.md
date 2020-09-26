---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/AhoCorasick.hpp
    title: "Aho-Corasick\u6CD5"
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"string/test/YUKI_Aho_Corasick.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/430\"\n#line 2 \"string/AhoCorasick.hpp\"\
    \n#include<string>\n#include<queue>\n\n/**\n * @brief Aho-Corasick\u6CD5\n */\n\
    \nclass AhoCorasick{\n    struct node;\n    using np=node*;\n    constexpr static\
    \ int num=26;\n    constexpr static char base='A';\n    struct node{\n       \
    \ np ch[num];\n        np link=nullptr;\n        int val=0;\n        node(){\n\
    \            for(int i=0;i<num;++i)ch[i]=nullptr;\n        }\n    };\n    np root=new\
    \ node();\n    np root_par=new node();\n    public:\n    AhoCorasick(){\n    \
    \    root->link=root_par;\n        for(int i=0;i<num;++i)root_par->ch[i]=root;\n\
    \    }\n    void insert(std::string v){\n        np t=root;\n        int idx=0;\n\
    \        while(idx<(int)v.size()){\n            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new\
    \ node();\n            t=t->ch[v[idx]-base];\n            idx++;\n        }\n\
    \        t->val++;\n    }\n    void build(){\n        built=1;\n        std::queue<np>que;\n\
    \        que.push(root);\n        while(!que.empty()){\n            np t=que.front();\n\
    \            que.pop();\n            for(int i=0;i<num;++i){\n               \
    \ if(!t->ch[i])continue;\n                if(t==root){\n                    t->ch[i]->link=t;\n\
    \                }else{\n                    np s=t->link;\n                 \
    \   while(!s->ch[i]){\n                        s=s->link;\n                  \
    \  }\n                    t->ch[i]->link=s->ch[i];\n                }\n      \
    \          que.push(t->ch[i]);\n            }\n        }\n    }\n    bool built=0;\n\
    \    int count(std::string v){\n        if(!built){build();built=1;}\n       \
    \ np t=root;\n        int idx=0;\n        int res=0;\n        while(idx<(int)v.size()){\n\
    \            while(!t->ch[v[idx]-base]){\n                if(t==root){\n     \
    \               idx++;\n                    if(idx==(int)v.size())return res;\n\
    \                }else{\n                    t=t->link;\n                }\n \
    \           }\n            t=t->ch[v[idx++]-base];\n            auto s=t;\n  \
    \          while(s!=root){\n                res+=s->val;\n                s=s->link;\n\
    \            }\n        }\n        return res;\n    }\n    int find_first(std::string\
    \ v){\n        if(!built){build();built=1;}\n        np t=root;\n        int idx=0;\n\
    \        int res=0;\n        while(idx<(int)v.size()){\n            while(!t->ch[v[idx]-base]){\n\
    \                if(t==root){\n                    res++;\n                  \
    \  idx++;\n                    if(idx==(int)v.size())return -1;\n            \
    \    }else{\n                    res++;\n                    t=t->link;\n    \
    \            }\n            }\n            t=t->ch[v[idx++]-base];\n         \
    \   if(t->val>0)return res;\n        }\n        return -1;\n    }\n};\n#line 2\
    \ \"util/template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
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
    \ i=0;i<t.size();i++)output(t[i]);}\n#define loop(n) for(long long _=0;_<(long\
    \ long)(n);++_)\n#define rep(i,...) for(auto i:range(__VA_ARGS__)) \n#define rrep(i,...)\
    \ for(auto i:reversed(range(__VA_ARGS__)))\n#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)\n\
    #define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)\n#define irep(i) for(lint\
    \ i=0;;++i)\ninline vector<long long> range(long long n){if(n<=0)return vector<long\
    \ long>();vector<long long>v(n);iota(v.begin(),v.end(),0LL);return v;}\ninline\
    \ vector<long long> range(long long a,long long b){if(b<=a)return vector<long\
    \ long>();vector<long long>v(b-a);iota(v.begin(),v.end(),a);return v;}\ninline\
    \ vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return\
    \ vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return\
    \ v;}\ntemplate<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return\
    \ v;}\n#define all(n) begin(n),end(n)\ntemplate<typename T,typename E>bool chmin(T&\
    \ s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}\ntemplate<typename T,typename\
    \ E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}\nconst\
    \ vector<lint> dx={1,0,-1,0,1,1,-1,-1};\nconst vector<lint> dy={0,1,0,-1,1,-1,1,-1};\n\
    #define SUM(v) accumulate(all(v),0LL)\ntemplate<typename T,typename ...Args>auto\
    \ make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return\
    \ vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}\n//#include\
    \ \"../graph_tree/graph_template.hpp\"\n#line 4 \"string/test/YUKI_Aho_Corasick.test.cpp\"\
    \n\nint main(){\n    string s;\n    cin>>s;\n    lint q;\n    cin>>q;\n    AhoCorasick\
    \ aho;\n    while(q--){\n        string t;\n        cin>>t;\n        aho.insert(t);\n\
    \    }\n    cout<<aho.count(s)<<endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\n#include\"../AhoCorasick.hpp\"\
    \n#include \"../../util/template.hpp\"\n\nint main(){\n    string s;\n    cin>>s;\n\
    \    lint q;\n    cin>>q;\n    AhoCorasick aho;\n    while(q--){\n        string\
    \ t;\n        cin>>t;\n        aho.insert(t);\n    }\n    cout<<aho.count(s)<<endl;\n\
    }"
  dependsOn:
  - string/AhoCorasick.hpp
  - util/template.hpp
  isVerificationFile: true
  path: string/test/YUKI_Aho_Corasick.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 16:21:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: string/test/YUKI_Aho_Corasick.test.cpp
layout: document
redirect_from:
- /verify/string/test/YUKI_Aho_Corasick.test.cpp
- /verify/string/test/YUKI_Aho_Corasick.test.cpp.html
title: string/test/YUKI_Aho_Corasick.test.cpp
---
