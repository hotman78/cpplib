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


# :heavy_check_mark: math/tetration.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/tetration.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Depends on

* :heavy_check_mark: <a href="euler_phi.hpp.html">math/euler_phi.hpp</a>
* :heavy_check_mark: <a href="mod_pow.hpp.html">math/mod_pow.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/math/test/LC_tetration.test.cpp.html">math/test/LC_tetration.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<vector>
#include<algorithm>
#include<cmath>
#include"mod_pow.hpp"
#include"euler_phi.hpp"

long long tetration(long long a,long long b,long long m){
    std::vector<long long> v;
    long long d=m;
    while(d!=1){
        v.push_back(d);
        d=euler_phi(d);
    }
    v.push_back(1);
    if(a==0)return (b+1)%2%m;
    if(m==1)return 0;
    if(a==1||b==0){
        return 1;
    }
    if((long long)(v.size())>=b)v.resize(b-1,1);
    std::reverse(v.begin(),v.end());
    long long ans=a;
    for(auto e:v){
        long long ad=(ans<=32&&a<e&&std::pow((double)a,ans)<e?0:e);
        ans=mod_pow(a%e,ans,e)+ad;
    }
    return ans%m;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/tetration.hpp"
#include<vector>
#include<algorithm>
#include<cmath>
#line 1 "math/mod_pow.hpp"
long long mod_pow(long long x,long long y,long long mod){
    long long ret=1;
    while(y>0) {
        if(y&1)(ret*=x)%=mod;
        (x*=x)%=mod;
        y>>=1;
    }
    return ret;
}
#line 1 "math/euler_phi.hpp"
long long euler_phi(long long n) {
    long long ret = n;
    for(long long i=2;i*i<=n;i++) {
        if(n%i==0) {
            ret-=ret/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ret-=ret/n;
    return ret;
}
#line 7 "math/tetration.hpp"

long long tetration(long long a,long long b,long long m){
    std::vector<long long> v;
    long long d=m;
    while(d!=1){
        v.push_back(d);
        d=euler_phi(d);
    }
    v.push_back(1);
    if(a==0)return (b+1)%2%m;
    if(m==1)return 0;
    if(a==1||b==0){
        return 1;
    }
    if((long long)(v.size())>=b)v.resize(b-1,1);
    std::reverse(v.begin(),v.end());
    long long ans=a;
    for(auto e:v){
        long long ad=(ans<=32&&a<e&&std::pow((double)a,ans)<e?0:e);
        ans=mod_pow(a%e,ans,e)+ad;
    }
    return ans%m;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

