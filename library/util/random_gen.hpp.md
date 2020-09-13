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


# :warning: util/random_gen.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/random_gen.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Required by

* :warning: <a href="../math/mod_sqrt.hpp.html">math/mod_sqrt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

