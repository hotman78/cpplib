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


# :heavy_check_mark: string/test/LC_online_Z_algorizm.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#1a7427d145086499c399a0f95224a581">string/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/test/LC_online_Z_algorizm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 22:49:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/online_Zalgo.hpp.html">オンラインZアルゴリズム <small>(string/online_Zalgo.hpp)</small></a>
* :question: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../online_Zalgo.hpp"
#include "../../util/template.hpp"

int main(){
    string s;
    cin>>s;
    online_Zalgo z;
    for(auto e:s)z.add(e);
    vec v(s.size());
    rep(i,s.size())v[i]=z[i];
    output(v);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/test/LC_online_Z_algorizm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#line 2 "string/online_Zalgo.hpp"
#include<string>
#include<vector>
#include<set>

/**
 * @brief オンラインZアルゴリズム
 */

struct online_Zalgo{
    std::vector<int>z;
    std::set<int>memo;
    std::vector<std::vector<int>>hist;
    std::string s="";
    int sz=0;
    void add(char c){
        s+=c;
        memo.emplace(sz);
        z.push_back(-1);
        hist.push_back(std::vector<int>());
        sz++;
        int mx=-1;
        for(auto itr=next(memo.begin(),1);itr!=memo.end();){
            auto idx=*itr;
            if(s[sz-idx-1]!=s.back()){
                itr=memo.erase(itr);
                z[idx]=sz-idx-1;
                hist.back().push_back(idx);
            }else{
                mx=idx;
                break;
            }
        }
        if(mx==-1)return;
        for(auto e:hist[sz-1-mx]){
            memo.erase(mx+e);
            z[mx+e]=sz-(mx+e)-1;
            hist.back().push_back(mx+e);
        }
    }
    int operator[](int idx){
        if(memo.count(idx))return sz-idx;
        else return z[idx];
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
#line 4 "string/test/LC_online_Z_algorizm.test.cpp"

int main(){
    string s;
    cin>>s;
    online_Zalgo z;
    for(auto e:s)z.add(e);
    vec v(s.size());
    rep(i,s.size())v[i]=z[i];
    output(v);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

