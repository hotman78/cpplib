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


# :warning: ラグランジュ補完(連続点->一点) <small>(math/lagrange_interpolation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/lagrange_interpolation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 16:40:58+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief ラグランジュ補完(連続点->一点)
 */

template<typename T>
T lagrange_interpolation(vector<T>v,lint n){
    long long k=v.size();
    if(n<k)return v[n];
    vector<T> tmp1(k+1,1),tmp2(k+1,1);
    T ans=0;
    for(int i=0;i<k;++i)tmp1[i]=(i?tmp1[i-1]:1)*(n-i);
    for(int i=k-1;i>=0;--i)tmp2[i]=(i<k-1?tmp2[i+1]:1)*(n-i);
    rep(i,k){
        ans+=v[i]*(i<k-1?tmp2[i+1]:1)*(i?tmp1[i-1]:1)/(T(k-1-i).fact()*T(i).fact()*T((k-1-i)%2?-1:1));
    }
    return ans;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/lagrange_interpolation.hpp"
/**
 * @brief ラグランジュ補完(連続点->一点)
 */

template<typename T>
T lagrange_interpolation(vector<T>v,lint n){
    long long k=v.size();
    if(n<k)return v[n];
    vector<T> tmp1(k+1,1),tmp2(k+1,1);
    T ans=0;
    for(int i=0;i<k;++i)tmp1[i]=(i?tmp1[i-1]:1)*(n-i);
    for(int i=k-1;i>=0;--i)tmp2[i]=(i<k-1?tmp2[i+1]:1)*(n-i);
    rep(i,k){
        ans+=v[i]*(i<k-1?tmp2[i+1]:1)*(i?tmp1[i-1]:1)/(T(k-1-i).fact()*T(i).fact()*T((k-1-i)%2?-1:1));
    }
    return ans;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

