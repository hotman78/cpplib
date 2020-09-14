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


# :warning: osa_k法 <small>(math/osa_k.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/osa_k.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<map>

/**
 * @brief osa_k法
 */

template<typename Int>
std::map<int,int> osa_k(Int n){
    constexpr int mx=10'000'000;
    assert(n<mx);
    static init=false;
    static int v[mx];
    static vector<int>pr;
    if(!init){
        init=true;
        for(int i=2;i<mx;++i){
            if(v[i]==0){
                v[i]=i;
                pr.push_back(i);
            }
            for(int j=0;j<(int)pr.size() && pr[j]<=v[i] && i*pr[j]<mx;++j){
                v[i*pr[j]]=pr[j];
            }
        }
    }
    map<int,int>ret;
    while(n!=1){
        ret[v[n]]++;
        n/=v[n];
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/osa_k.hpp"
#include<map>

/**
 * @brief osa_k法
 */

template<typename Int>
std::map<int,int> osa_k(Int n){
    constexpr int mx=10'000'000;
    assert(n<mx);
    static init=false;
    static int v[mx];
    static vector<int>pr;
    if(!init){
        init=true;
        for(int i=2;i<mx;++i){
            if(v[i]==0){
                v[i]=i;
                pr.push_back(i);
            }
            for(int j=0;j<(int)pr.size() && pr[j]<=v[i] && i*pr[j]<mx;++j){
                v[i*pr[j]]=pr[j];
            }
        }
    }
    map<int,int>ret;
    while(n!=1){
        ret[v[n]]++;
        n/=v[n];
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
