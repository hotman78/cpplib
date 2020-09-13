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


# :warning: カーマイケル数 <small>(math/carmichael_function.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/carmichael_function.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<map>
/**
 * @brief カーマイケル数
 */
template<typename T>
auto carmichael_function(T n){
    map<T,long long>ret;
    for(auto i=2;i*i<=n;i++){
        while(n%i==0){
            ret[i]++;
            n/=i;
        }
    }
    if(n!=1)ret[n]=1;
    long long res=1;
    for(auto d:ret){
        if(d.first==2){
            if(d.second<3)res=pow(d.first,d.second-1);
            else res=pow(d.first,d.second-2);
        }
        else res=lcm(res,(long long)pow(d.first,d.second-1)*(d.first-1));
    }
    return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/carmichael_function.hpp"
#include<map>
/**
 * @brief カーマイケル数
 */
template<typename T>
auto carmichael_function(T n){
    map<T,long long>ret;
    for(auto i=2;i*i<=n;i++){
        while(n%i==0){
            ret[i]++;
            n/=i;
        }
    }
    if(n!=1)ret[n]=1;
    long long res=1;
    for(auto d:ret){
        if(d.first==2){
            if(d.second<3)res=pow(d.first,d.second-1);
            else res=pow(d.first,d.second-2);
        }
        else res=lcm(res,(long long)pow(d.first,d.second-1)*(d.first-1));
    }
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

