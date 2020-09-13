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


# :warning: math/prime_set.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime_set.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<vector>
#include<bitset>
#include<set>

template<typename T>
std::set<T> primeSet(T n) {
    std::vector<bool> p(n+1,1);
    std::set<T> set;
    p[0]=0;
    for(int i=2;i<=std::sqrt(n);i++) {
        if(p[i])for(int j=2;j<n/i+1;j++)p[i*j]=0;
    }
    for(int i=2;i<=n;i++)if(p[i])set.insert(i);
    return set;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/prime_set.hpp"
#include<vector>
#include<bitset>
#include<set>

template<typename T>
std::set<T> primeSet(T n) {
    std::vector<bool> p(n+1,1);
    std::set<T> set;
    p[0]=0;
    for(int i=2;i<=std::sqrt(n);i++) {
        if(p[i])for(int j=2;j<n/i+1;j++)p[i*j]=0;
    }
    for(int i=2;i<=n;i++)if(p[i])set.insert(i);
    return set;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

