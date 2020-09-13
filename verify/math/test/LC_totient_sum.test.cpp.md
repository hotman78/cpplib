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


# :heavy_check_mark: math/test/LC_totient_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ac0e84f4e067560125d03878b32a00d3">math/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/test/LC_totient_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 17:06:03+09:00


* see: <a href="https://judge.yosupo.jp/problem/sum_of_totient_function">https://judge.yosupo.jp/problem/sum_of_totient_function</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/mod_int.hpp.html">ModInt <small>(math/mod_int.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/math/mod_int998244353.hpp.html">ModInt(998'244'353) <small>(math/mod_int998244353.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/math/totient_sum.hpp.html">トーシェント関数の和 <small>(math/totient_sum.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "../totient_sum.hpp"
#include "../mod_int998244353.hpp"
#include "../../util/template.hpp"

int main(){
    lint n;
    cin>>n;
    cout<<totient_sum<mint>(n)<<endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/test/LC_totient_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#line 2 "math/totient_sum.hpp"
#include<map>

/**
 * @brief トーシェント関数の和
 */

template<typename T>
T totient_sum(long long n){
    static std::map<long long,T> m2;
    static bool init=1;
    static long long* m=new long long[10000000]();
    if(init){
        init=0;
        long long k=1e7;
        for(long long i=1;i<=k;i++)m[i]=i;
        for(long long i=1;i<=k;i++)for(long long j=i*2;j<=k;j+=i)m[j]-=m[i];
        for(long long i=1;i<k;i++)m[i+1]+=m[i];
    }
    if(n<1e7)return m[n];
    else if(m2.count(n))return m2[n];
    T ans=T(n)*(n+1)/2;
    long long mx=0;
    for(long long i=1;i*i<n;i++){
        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);
        mx=n/(i+1)+1;
    }
    for(long long i=2;i<mx;i++){
        ans-=totient_sum<T>(n/i);
    }
    return m2[n]=ans;
}
#line 2 "math/mod_int.hpp"
#include<cstdint>
#include<iostream>
#include<vector>

/**
 * @brief ModInt
 */

template<int MOD>
struct mod_int {
    using mint=mod_int<MOD>;
    using u64 = std::uint_fast64_t;
    u64 a;
    constexpr mod_int(const long long x = 0)noexcept:a(x>=0?x%get_mod():get_mod()-(-x)%get_mod()){}
    constexpr u64 &value()noexcept{return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr mint operator+(const mint rhs)const noexcept{return mint(*this) += rhs;}
    constexpr mint operator-(const mint rhs)const noexcept{return mint(*this)-=rhs;}
    constexpr mint operator*(const mint rhs) const noexcept {return mint(*this) *= rhs;}
    constexpr mint operator/(const mint rhs) const noexcept {return mint(*this) /= rhs;}
    constexpr mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
        if (a<rhs.a)a += get_mod();
        a -= rhs.a;
        return *this;
    }
    constexpr mint &operator*=(const mint rhs) noexcept {
        a = a * rhs.a % get_mod();
        return *this;
    }
    constexpr mint operator++(int) noexcept {
        a += 1;
        if (a >= get_mod())a -= get_mod();
        return *this;
    }
    constexpr mint operator--(int) noexcept {
        if (a<1)a += get_mod();
        a -= 1;
        return *this;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
        u64 exp=get_mod()-2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr bool operator==(mint x) noexcept {
        return a==x.a;
    }
    constexpr bool operator!=(mint x) noexcept {
        return a!=x.a;
    }
    constexpr bool operator<(mint x) noexcept {
        return a<x.a;
    }
    constexpr bool operator>(mint x) noexcept {
        return a>x.a;
    }
    constexpr bool operator<=(mint x) noexcept {
        return a<=x.a;
    }
    constexpr bool operator>=(mint x) noexcept {
        return a>=x.a;
    }
    constexpr static int root(){
        mint root = 2;
        while(root.pow((get_mod()-1)>>1).a==1)root++;
        return root.a;
    }
    constexpr mint pow(long long n){
        long long x=a;
        mint ret = 1;
        while(n>0) {
            if(n&1)(ret*=x);
            (x*=x)%=get_mod();
            n>>=1;
        }
        return ret;
    }
    constexpr mint inv(){
        return pow(get_mod()-2);
    }
    static std::vector<mint> fac;
    static std::vector<mint> ifac;
    static bool init;
    constexpr static int mx=10000001;
    void build(){
        init=0;
        fac.resize(mx);
        ifac.resize(mx);
        fac[0]=1,ifac[0]=1;
        for(int i=1;i<mx;i++)fac[i]=fac[i-1]*i;
        ifac[mx-1]=fac[mx-1].inv();
        for(int i=mx-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1);
    }
    mint comb(long long b){
        if(init)build();
        if(a==0&&b==0)return 1;
        if((long long)a<b)return 0;
        return fac[a]*ifac[a-b]*ifac[b];
    }
    mint fact(){
        if(init)build();
        return fac[a];
    }
    mint fact_inv(){
        if(init)build();
        return ifac[a];
    }
    friend std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {
        lhs << rhs.a;
        return lhs;
    }
    friend std::istream& operator>>(std::istream& lhs,mint& rhs) noexcept {
        lhs >> rhs.a;
        return lhs;
    }
    constexpr static u64 get_mod(){
        return MOD;
    }
};
template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::fac;
template<int MOD>std::vector<mod_int<MOD>> mod_int<MOD>::ifac;
template<int MOD>bool mod_int<MOD>::init=1;
#line 3 "math/mod_int998244353.hpp"
using mint=mod_int<998'244'353>;

/**
 * @brief ModInt(998'244'353)
 */
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
#line 5 "math/test/LC_totient_sum.test.cpp"

int main(){
    lint n;
    cin>>n;
    cout<<totient_sum<mint>(n)<<endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

