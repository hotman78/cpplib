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


# :warning: math/is_prime.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/is_prime.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Required by

* :warning: <a href="prime_factor.hpp.html">math/prime_factor.hpp</a>
* :warning: <a href="test/AOJ_is_prime.cpp.html">math/test/AOJ_is_prime.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <initializer_list>

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/is_prime.hpp"
#include <initializer_list>

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

