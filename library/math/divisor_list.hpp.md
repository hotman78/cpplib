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


# :warning: math/divisor_list.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/divisor_list.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

template<typename T>
auto divisor_list(T n){
    vector<T>res;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i)continue;
        res.push_back(i);
        if(i*i!=n)res.push_back(n/i);
    }
    sort(res.begin(),res.end());
    return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/divisor_list.hpp"

template<typename T>
auto divisor_list(T n){
    vector<T>res;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i)continue;
        res.push_back(i);
        if(i*i!=n)res.push_back(n/i);
    }
    sort(res.begin(),res.end());
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

