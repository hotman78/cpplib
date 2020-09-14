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


# :heavy_check_mark: 素数列挙 <small>(math/prime_list.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime_list.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 18:30:52+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/math/test/AOJ_prime_list.test.cpp.html">math/test/AOJ_prime_list.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<vector>
#include<bitset>
#include<cmath>
#include<set>

/**
 * @brief 素数列挙
 */

std::bitset<500'000'001> p;
std::vector<long long> prime_list(int n) {
    p.set();
    p[0]=0;
    for(int i=2;i*i<=n;++i){
        if(!p[i])continue;
        for(int j=2*i;j<=n;j+=i)p[j]=0;
    }
    std::vector<long long>list;
    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);
    return list;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/prime_list.hpp"
#include<vector>
#include<bitset>
#include<cmath>
#include<set>

/**
 * @brief 素数列挙
 */

std::bitset<500'000'001> p;
std::vector<long long> prime_list(int n) {
    p.set();
    p[0]=0;
    for(int i=2;i*i<=n;++i){
        if(!p[i])continue;
        for(int j=2*i;j<=n;j+=i)p[j]=0;
    }
    std::vector<long long>list;
    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);
    return list;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>
