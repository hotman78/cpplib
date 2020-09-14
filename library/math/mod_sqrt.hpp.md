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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: ModSqrt <small>(math/mod_sqrt.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mod_sqrt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 10:33:36+09:00




## Depends on

* :heavy_check_mark: <a href="mod_pow.hpp.html">(x^y)%mod <small>(math/mod_pow.hpp)</small></a>
* :heavy_check_mark: <a href="../util/random_gen.hpp.html">util/random_gen.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/math/test/LC_mod_sqrt.test.cpp.html">math/test/LC_mod_sqrt.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<tuple>
#include"mod_pow.hpp"
#include"../util/random_gen.hpp"

/**
 * @brief ModSqrt
 */

long long mod_sqrt(long long a,long long mod){
    if(mod==2||a==0)return a;
    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;
    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);
    long long q=(mod-1),s=0;
    while(q%2==0)q/=2,s++;
    long long z=1;
    RandomNumberGenerator rnd;
    while(mod_pow(z=rnd(0,mod),(mod-1)/2,mod)!=mod-1);
    long long c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;
    while(m>1){
        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;
        else std::tie(c,t,r,m)=std::make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);
    }
    return r%mod;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/mod_sqrt.hpp"
#include<tuple>
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
#line 2 "util/random_gen.hpp"
#include<random>
#include<chrono>

struct RandomNumberGenerator {
    std::mt19937 mt;
    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    int operator()(int a, int b) { // [a, b)
        std::uniform_int_distribution< int > dist(a, b - 1);
        return dist(mt);
    }

    int operator()(int b) { // [0, b)
        return (*this)(0, b);
    }
};
#line 4 "math/mod_sqrt.hpp"

/**
 * @brief ModSqrt
 */

long long mod_sqrt(long long a,long long mod){
    if(mod==2||a==0)return a;
    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;
    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);
    long long q=(mod-1),s=0;
    while(q%2==0)q/=2,s++;
    long long z=1;
    RandomNumberGenerator rnd;
    while(mod_pow(z=rnd(0,mod),(mod-1)/2,mod)!=mod-1);
    long long c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;
    while(m>1){
        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;
        else std::tie(c,t,r,m)=std::make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);
    }
    return r%mod;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

