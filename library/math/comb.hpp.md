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


# :warning: math/comb.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/comb.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 14:58:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<int mod>
long long comb(long long a, long long b){
    static bool init=1;
    static long long fac[1000001],ifac[1000001];
    if(init){
        init=0;
        fac[0]=1;
        ifac[0]=1;
        auto mod_pow=[&](lint x,lint n){
            lint ans = 1;
            while(n != 0){
                if(n&1)ans=ans*x%mod;
                x=x*x%mod;
                n=n>>1;
            }
            return ans;
        };
        for(int i=0;i<1000000;i++){
            fac[i+1]=fac[i]*(i+1)%mod;
            ifac[i+1]=ifac[i]*mod_pow(i+1, MOD-2)%mod;
        }
    }
    if(a==0&&b==0)return 1;
    if(a<b||a<0)return 0;
    long long tmp=ifac[a-b]*ifac[b]%mod;
    return tmp*fac[a]%mod;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/comb.hpp"
template<int mod>
long long comb(long long a, long long b){
    static bool init=1;
    static long long fac[1000001],ifac[1000001];
    if(init){
        init=0;
        fac[0]=1;
        ifac[0]=1;
        auto mod_pow=[&](lint x,lint n){
            lint ans = 1;
            while(n != 0){
                if(n&1)ans=ans*x%mod;
                x=x*x%mod;
                n=n>>1;
            }
            return ans;
        };
        for(int i=0;i<1000000;i++){
            fac[i+1]=fac[i]*(i+1)%mod;
            ifac[i+1]=ifac[i]*mod_pow(i+1, MOD-2)%mod;
        }
    }
    if(a==0&&b==0)return 1;
    if(a<b||a<0)return 0;
    long long tmp=ifac[a-b]*ifac[b]%mod;
    return tmp*fac[a]%mod;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

