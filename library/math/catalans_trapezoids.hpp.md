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


# :warning: カタラン台形 <small>(math/catalans_trapezoids.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/catalans_trapezoids.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief カタラン台形
 */
template<typename T>
T catalans_trapezoids(long long n,long long k,long long m=1){
    if(m<=0)return T();
    else if(0<=k&&k<m)return T(n+k).comb(k);
    else if(m<=k&&k<n+m)return T(n+k).comb(k)-T(n+k).comb(k-m);
    else return T(0);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/catalans_trapezoids.hpp"
/**
 * @brief カタラン台形
 */
template<typename T>
T catalans_trapezoids(long long n,long long k,long long m=1){
    if(m<=0)return T();
    else if(0<=k&&k<m)return T(n+k).comb(k);
    else if(m<=k&&k<n+m)return T(n+k).comb(k)-T(n+k).comb(k-m);
    else return T(0);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

