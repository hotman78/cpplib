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


# :warning: 離散対数(ModLog) <small>(math/mod_log.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mod_log.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Depends on

* :heavy_check_mark: <a href="euler_phi.hpp.html">オイラーのファイ関数 <small>(math/euler_phi.hpp)</small></a>
* :heavy_check_mark: <a href="mod_pow.hpp.html">(x^y)%mod <small>(math/mod_pow.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include"mod_pow.hpp"
#include"euler_phi.hpp"
#include<map>
#include<numeric>
#include<cmath>

/**
 * @brief 離散対数(ModLog)
 */

long long mod_log(long long x,long long y,long long m){
    if(1==y||(x==0&&y==0&&m==1))return 0;
    if(x==0){
        if(y==1)return 0;
        if(y==0)return 1;
        else return -1;
    }
    long long _x=x,_y=y;
    long long g=m;
    long long cnt=0;
    while(std::gcd(x,m)!=1)m/=std::gcd(x,m),cnt++;
    g/=m;
    x%=m;
    y%=m;
    std::map<long long,long long>b;
    long long B=std::sqrt(m*g)+1;
    long long phi=euler_phi(m);
    long long a=mod_pow(x,B-1,m);
    long long inv_x=mod_pow(x,phi-1,m);
    for(long long i=B-1;i>=cnt;--i){
        b[a]=i;
        a=a*inv_x%m;
    }
    long long A=mod_pow(x,B*(phi-1),m);
    long long A2=y;
    for(long long i=0;i<B;++i){
        for(long long j=0;j<cnt;++j)if(mod_pow(_x,i*B+j,m*g)==_y)return i*B+j;
        if(b.count(A2)){
            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return i*B+b[A2];
        }
        A2=A2*A%m;
    }
    return -1;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
#line 4 "math/mod_log.hpp"
#include<map>
#include<numeric>
#include<cmath>

/**
 * @brief 離散対数(ModLog)
 */

long long mod_log(long long x,long long y,long long m){
    if(1==y||(x==0&&y==0&&m==1))return 0;
    if(x==0){
        if(y==1)return 0;
        if(y==0)return 1;
        else return -1;
    }
    long long _x=x,_y=y;
    long long g=m;
    long long cnt=0;
    while(std::gcd(x,m)!=1)m/=std::gcd(x,m),cnt++;
    g/=m;
    x%=m;
    y%=m;
    std::map<long long,long long>b;
    long long B=std::sqrt(m*g)+1;
    long long phi=euler_phi(m);
    long long a=mod_pow(x,B-1,m);
    long long inv_x=mod_pow(x,phi-1,m);
    for(long long i=B-1;i>=cnt;--i){
        b[a]=i;
        a=a*inv_x%m;
    }
    long long A=mod_pow(x,B*(phi-1),m);
    long long A2=y;
    for(long long i=0;i<B;++i){
        for(long long j=0;j<cnt;++j)if(mod_pow(_x,i*B+j,m*g)==_y)return i*B+j;
        if(b.count(A2)){
            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return i*B+b[A2];
        }
        A2=A2*A%m;
    }
    return -1;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

