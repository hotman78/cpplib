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


# :heavy_check_mark: ガーナーのアルゴリズム <small>(math/garner.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/garner.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 19:36:00+09:00




## Depends on

* :heavy_check_mark: <a href="mod_pow.hpp.html">(x^y)%mod <small>(math/mod_pow.hpp)</small></a>


## Required by

* :heavy_check_mark: <a href="../convolution/FPS.hpp.html">形式的冪級数(ModInt) <small>(convolution/FPS.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/convolution/test/LC_convolution_998244353.test.cpp.html">convolution/test/LC_convolution_998244353.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/convolution/test/LC_covolution_1000000007.test.cpp.html">convolution/test/LC_covolution_1000000007.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<vector>
#include"mod_pow.hpp"

/**
 * 
 * @brief ガーナーのアルゴリズム
 *
 */

long long garner(std::vector<long long>a,std::vector<long long>mods){
    const int sz=3;
    long long coeffs[sz+1]={1,1,1,1};
    long long constants[sz+1]={};
    for(int i=0;i<sz;i++){
        long long v=(mods[i]+a[i]-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];
        for(int j=i+1;j<sz+1;j++) {
            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
            coeffs[j]=(coeffs[j]*mods[i])%mods[j];
        }
    }
    return constants[3];
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/garner.hpp"
#include<vector>
#line 1 "math/mod_pow.hpp"
/**
 * @brief (x^y)%mod
 */

long long mod_pow(long long x,long long y,long long mod){
    long long ret=1;
    while(y>0) {
        if(y&1)(ret*=x)%=mod;
        (x*=x)%=mod;
        y>>=1;
    }
    return ret;
}
#line 4 "math/garner.hpp"

/**
 * 
 * @brief ガーナーのアルゴリズム
 *
 */

long long garner(std::vector<long long>a,std::vector<long long>mods){
    const int sz=3;
    long long coeffs[sz+1]={1,1,1,1};
    long long constants[sz+1]={};
    for(int i=0;i<sz;i++){
        long long v=(mods[i]+a[i]-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];
        for(int j=i+1;j<sz+1;j++) {
            constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
            coeffs[j]=(coeffs[j]*mods[i])%mods[j];
        }
    }
    return constants[3];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

