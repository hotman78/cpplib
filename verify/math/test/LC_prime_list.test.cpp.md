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


# :x: math/test/LC_prime_list.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac0e84f4e067560125d03878b32a00d3">math/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/test/LC_prime_list.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:29:24+09:00


* see: <a href="https://judge.yosupo.jp/problem/enumerate_primes">https://judge.yosupo.jp/problem/enumerate_primes</a>


## Depends on

* :x: <a href="../../../library/math/prime_list.hpp.html">math/prime_list.hpp</a>
* :question: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../prime_list.hpp"
#include "../../util/template.hpp"

int main(){
    lint n,a,b;
    cin>>n>>a>>b;
    auto v=prime_list<510'000'000>();
    cout<<lower_bound(all(v),n)-v.begin()<<endl;
    vector<int>ans;
    for(int i=b;v[i]<n;i+=a){
        ans.push_back(v[i]);
    }
    output(ans);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/test/LC_prime_list.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#line 2 "math/prime_list.hpp"
#include<vector>
#include<bitset>
#include<set>

template<int n=10'000'000>
std::vector<long long> prime_list() {
    std::bitset<n+1> p;
    p.set();
    p[0]=0;
    for(int i=2;i<std::sqrt(n)+10;++i){
        if(!p[i])continue;
        for(int j=2*i;j<n;j+=i)p[j]=0;
    }
    std::vector<long long>list;
    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);
    return list;
}

#line 1 "util/template.hpp"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
__attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}
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
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
#line 4 "math/test/LC_prime_list.test.cpp"

int main(){
    lint n,a,b;
    cin>>n>>a>>b;
    auto v=prime_list<510'000'000>();
    cout<<lower_bound(all(v),n)-v.begin()<<endl;
    vector<int>ans;
    for(int i=b;v[i]<n;i+=a){
        ans.push_back(v[i]);
    }
    output(ans);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

