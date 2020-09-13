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


# :heavy_check_mark: math/test/LC_prime_factor.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac0e84f4e067560125d03878b32a00d3">math/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/test/LC_prime_factor.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 17:33:31+09:00


* see: <a href="https://judge.yosupo.jp/problem/factorize">https://judge.yosupo.jp/problem/factorize</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/is_prime.hpp.html">素数判定(高速) <small>(math/is_prime.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/math/prime_factor.hpp.html">素因数分解(高速) <small>(math/prime_factor.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../prime_factor.hpp"
#include "../../util/template.hpp"

int main(){
    lint q;
    cin>>q;
    while(q--){
        lint n;
        cin>>n;
        vec d=prime_factor(n);
        cout<<d.size()<<" "; 
        output(d);
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/test/LC_prime_factor.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#line 2 "math/prime_factor.hpp"
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
#line 2 "math/is_prime.hpp"
#include <initializer_list>
/**
 * @brief 素数判定(高速)
 */
bool is_prime(long long n){
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    long long s=0,d=n-1;
    while(d%2)d/=2,s++;
    auto mod_pow=[](__int128_t a,__int128_t b,__int128_t n){
        long long res=1;
        while(b){
            if(b%2)res=res*a%n;
            a=a*a%n;
            b/=2;
        }
        return (long long)(res);
    };
    for(long long e:{2,3,5,7,11,13,17,19,23,29,31,37}){
        if(n<=e)break;
        if(mod_pow(e,d,n)==1)continue;
        bool b=1;
        for(int i=0;i<s;i++){
            if(mod_pow(e,d<<i,n)==n-1)b=0;
        }
        if(b)return 0;
    }
    return 1;
}
#line 7 "math/prime_factor.hpp"

/**
 * @brief 素因数分解(高速)
 */

void __prime_factor(long long n,long long& c,std::vector<long long>& v){
    if(n==1)return;
    if(n%2==0){
        v.emplace_back(2);
        __prime_factor(n/2,c,v);
        return;
    }
    if(is_prime(n)){
        v.emplace_back(n);
        return;
    }
    while(1){
        long long x=2,y=2,d=1;
        while(d==1){
            x=((__int128_t)x*x+c)%n;
            y=((__int128_t)y*y%n+c)%n;
            y=((__int128_t)y*y%n+c)%n;
            d=std::gcd(std::abs(x-y),n);
        }
        if(d==n){
            c++;
            continue;
        }
        __prime_factor(d,c,v);
        __prime_factor(n/d,c,v);
        return;
    }
}

std::vector<long long>prime_factor(long long n){
    std::vector<long long>v;
    long long c=1;
    __prime_factor(n,c,v);
    std::sort(v.begin(),v.end());
    return v;
}
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
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
#line 4 "math/test/LC_prime_factor.test.cpp"

int main(){
    lint q;
    cin>>q;
    while(q--){
        lint n;
        cin>>n;
        vec d=prime_factor(n);
        cout<<d.size()<<" "; 
        output(d);
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

