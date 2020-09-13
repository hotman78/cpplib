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


# :heavy_check_mark: math/test/LC_tetration.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac0e84f4e067560125d03878b32a00d3">math/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/test/LC_tetration.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 19:29:07+09:00


* see: <a href="https://judge.yosupo.jp/problem/tetration_mod">https://judge.yosupo.jp/problem/tetration_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/euler_phi.hpp.html">オイラーのファイ関数 <small>(math/euler_phi.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/math/mod_pow.hpp.html">(x^y)%mod <small>(math/mod_pow.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/math/tetration.hpp.html">テトレーション <small>(math/tetration.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#include "../tetration.hpp"
#include "../../util/template.hpp"

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,m;
        cin>>a>>b>>m;
        cout<<tetration(a,b,m)<<endl;
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/test/LC_tetration.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#line 2 "math/tetration.hpp"
#include<vector>
#include<algorithm>
#include<cmath>
#line 1 "math/mod_pow.hpp"
/**
 * @brief (x^y)%mod
 */

long long mod_pow(long long x,long long y,long long mod){
    long long ret=1;
    while(y>0) {
        if(y&1)(ret*=x)%=mod;
        (x*=x)%=mod;
        y>>=1;
    }
    return ret;
}
#line 1 "math/euler_phi.hpp"
/**
 * @brief オイラーのファイ関数
 */

long long euler_phi(long long n) {
    long long ret = n;
    for(long long i=2;i*i<=n;i++) {
        if(n%i==0) {
            ret-=ret/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ret-=ret/n;
    return ret;
}
#line 7 "math/tetration.hpp"

/**
 * @brief テトレーション
 */

long long tetration(long long a,long long b,long long m){
    std::vector<long long> v;
    long long d=m;
    while(d!=1){
        v.push_back(d);
        d=euler_phi(d);
    }
    v.push_back(1);
    if(a==0)return (b+1)%2%m;
    if(m==1)return 0;
    if(a==1||b==0){
        return 1;
    }
    if((long long)(v.size())>=b)v.resize(b-1,1);
    std::reverse(v.begin(),v.end());
    long long ans=a;
    for(auto e:v){
        long long ad=(ans<=32&&a<e&&std::pow((double)a,ans)<e?0:e);
        ans=mod_pow(a%e,ans,e)+ad;
    }
    return ans%m;
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
#line 4 "math/test/LC_tetration.test.cpp"

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,m;
        cin>>a>>b>>m;
        cout<<tetration(a,b,m)<<endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

