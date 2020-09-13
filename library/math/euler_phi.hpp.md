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


# :heavy_check_mark: オイラーのファイ関数 <small>(math/euler_phi.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/euler_phi.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Required by

* :heavy_check_mark: <a href="mod_log.hpp.html">離散対数(ModLog) <small>(math/mod_log.hpp)</small></a>
* :heavy_check_mark: <a href="tetration.hpp.html">テトレーション <small>(math/tetration.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/math/test/LC_mod_log.test.cpp.html">math/test/LC_mod_log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/math/test/LC_tetration.test.cpp.html">math/test/LC_tetration.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

