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


# :warning: math/sum_of_floor_linear.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/sum_of_floor_linear.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
// \sum_{i=0}^{n-1}\floor(a*i+b/c)
long long sum_of_floor_linear(long long a,long long b,long long c,long long n){
    long long tmp=b/c*n+a/c*n*(n-1)/2;
    if(a%c==0){
        return tmp;
    }
    long long next=(c-b%c+a%c-1)/(a%c);
    if(next>=n){
        return tmp;
    }
    a%=c;
    b=b%c+a*next;
    n-=next;
    return tmp+sum_of_floor_linear(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/sum_of_floor_linear.hpp"
// \sum_{i=0}^{n-1}\floor(a*i+b/c)
long long sum_of_floor_linear(long long a,long long b,long long c,long long n){
    long long tmp=b/c*n+a/c*n*(n-1)/2;
    if(a%c==0){
        return tmp;
    }
    long long next=(c-b%c+a%c-1)/(a%c);
    if(next>=n){
        return tmp;
    }
    a%=c;
    b=b%c+a*next;
    n-=next;
    return tmp+sum_of_floor_linear(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

