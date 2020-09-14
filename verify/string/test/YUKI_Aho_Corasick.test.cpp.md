---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: string/test/YUKI_Aho_Corasick.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1a7427d145086499c399a0f95224a581">string/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/test/YUKI_Aho_Corasick.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 23:01:17+09:00


* see: <a href="https://yukicoder.me/problems/no/430">https://yukicoder.me/problems/no/430</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/AhoCorasick.hpp.html">Aho-Corasick法 <small>(string/AhoCorasick.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/430"
#include"../AhoCorasick.hpp"
#include "../../util/template.hpp"

int main(){
    string s;
    cin>>s;
    lint q;
    cin>>q;
    AhoCorasick aho;
    while(q--){
        string t;
        cin>>t;
        aho.insert(t);
    }
    cout<<aho.count(s)<<endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/test/YUKI_Aho_Corasick.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/430"
#line 2 "string/AhoCorasick.hpp"
#include<string>
#include<queue>

/**
 * @brief Aho-Corasick法
 */

class AhoCorasick{
    struct node;
    using np=node*;
    constexpr static int num=26;
    constexpr static char base='A';
    struct node{
        np ch[num];
        np link=nullptr;
        int val=0;
        node(){
            for(int i=0;i<num;++i)ch[i]=nullptr;
        }
    };
    np root=new node();
    np root_par=new node();
    public:
    AhoCorasick(){
        root->link=root_par;
        for(int i=0;i<num;++i)root_par->ch[i]=root;
    }
    void insert(std::string v){
        np t=root;
        int idx=0;
        while(idx<(int)v.size()){
            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new node();
            t=t->ch[v[idx]-base];
            idx++;
        }
        t->val++;
    }
    void build(){
        built=1;
        std::queue<np>que;
        que.push(root);
        while(!que.empty()){
            np t=que.front();
            que.pop();
            for(int i=0;i<num;++i){
                if(!t->ch[i])continue;
                if(t==root){
                    t->ch[i]->link=t;
                }else{
                    np s=t->link;
                    while(!s->ch[i]){
                        s=s->link;
                    }
                    t->ch[i]->link=s->ch[i];
                }
                que.push(t->ch[i]);
            }
        }
    }
    bool built=0;
    int count(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    idx++;
                    if(idx==(int)v.size())return res;
                }else{
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            auto s=t;
            while(s!=root){
                res+=s->val;
                s=s->link;
            }
        }
        return res;
    }
    int find_first(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    res++;
                    idx++;
                    if(idx==(int)v.size())return -1;
                }else{
                    res++;
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            if(t->val>0)return res;
        }
        return -1;
    }
};
#line 2 "util/template.hpp"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
struct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define endl ('\n')
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(lint i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(lint i=0;i<t.size();i++)output(t[i]);}
#define rep(i,...) for(auto i:range(__VA_ARGS__)) 
#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))
#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
#define irep(i) for(lint i=0;;++i)
inline vector<long long> range(long long n){vector<long long>v(n);iota(v.begin(),v.end(),0LL);return v;}
inline vector<long long> range(long long a,long long b){vector<long long>v(b-a);iota(v.begin(),v.end(),a);return v;}
inline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return v;}
template<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return v;}
#define all(n) begin(n),end(n)
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
#line 4 "string/test/YUKI_Aho_Corasick.test.cpp"

int main(){
    string s;
    cin>>s;
    lint q;
    cin>>q;
    AhoCorasick aho;
    while(q--){
        string t;
        cin>>t;
        aho.insert(t);
    }
    cout<<aho.count(s)<<endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

