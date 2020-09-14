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


# :heavy_check_mark: math/ceil_pow2.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/ceil_pow2.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 19:36:00+09:00




## Required by

* :heavy_check_mark: <a href="../convolution/FPS.hpp.html">形式的冪級数(ModInt) <small>(convolution/FPS.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/convolution/test/LC_convolution_1000000007.test.cpp.html">convolution/test/LC_convolution_1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/convolution/test/LC_convolution_998244353.test.cpp.html">convolution/test/LC_convolution_998244353.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/ceil_pow2.hpp"
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

