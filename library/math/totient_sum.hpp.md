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


# :x: math/totient_sum.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/totient_sum.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 15:59:09+09:00




## Verified with

* :x: <a href="../../verify/math/test/LC_totient_sum.test.cpp.html">math/test/LC_totient_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<map>

template<typename T>
T totient_sum(long long n){
    static std::map<long long,T> m2;
    static bool init=1;
    static long long* m=new long long[10000000]();
    if(init){
        init=0;
        long long k=1e7;
        for(long long i=1;i<=k;i++)m[i]=i;
        for(long long i=1;i<=k;i++)for(long long j=i*2;j<=k;j+=i)m[j]-=m[i];
        for(long long i=1;i<k;i++)m[i+1]+=m[i];
    }
    if(n<1e7)return m[n];
    else if(m2.count(n))return m2[n];
    T ans=T(n)*(n+1)/2;
    long long mx=0;
    for(long long i=1;i*i<n;i++){
        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);
        mx=n/(i+1)+1;
    }
    for(long long i=2;i<mx;i++){
        ans-=totient_sum<T>(n/i);
    }
    return m2[n]=ans;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/totient_sum.hpp"
#include<map>

template<typename T>
T totient_sum(long long n){
    static std::map<long long,T> m2;
    static bool init=1;
    static long long* m=new long long[10000000]();
    if(init){
        init=0;
        long long k=1e7;
        for(long long i=1;i<=k;i++)m[i]=i;
        for(long long i=1;i<=k;i++)for(long long j=i*2;j<=k;j+=i)m[j]-=m[i];
        for(long long i=1;i<k;i++)m[i+1]+=m[i];
    }
    if(n<1e7)return m[n];
    else if(m2.count(n))return m2[n];
    T ans=T(n)*(n+1)/2;
    long long mx=0;
    for(long long i=1;i*i<n;i++){
        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);
        mx=n/(i+1)+1;
    }
    for(long long i=2;i<mx;i++){
        ans-=totient_sum<T>(n/i);
    }
    return m2[n]=ans;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

