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


# :question: (x^y)%mod <small>(math/mod_pow.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mod_pow.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Required by

* :x: <a href="mod_log.hpp.html">離散対数(ModLog) <small>(math/mod_log.hpp)</small></a>
* :heavy_check_mark: <a href="mod_sqrt.hpp.html">ModSqrt <small>(math/mod_sqrt.hpp)</small></a>
* :heavy_check_mark: <a href="tetration.hpp.html">テトレーション <small>(math/tetration.hpp)</small></a>


## Verified with

* :x: <a href="../../verify/math/test/LC_mod_log.test.cpp.html">math/test/LC_mod_log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/math/test/LC_mod_sqrt.test.cpp.html">math/test/LC_mod_sqrt.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/math/test/LC_tetration.test.cpp.html">math/test/LC_tetration.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

