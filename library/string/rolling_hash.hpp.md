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


# :warning: string/rolling_hash.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling_hash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:40:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<vector>
#include<set>
#include<tuple>

struct rolling_hash{
    using u64=std::uint64_t;
    constexpr static u64 mod=(1ULL<<61)-1;
    constexpr static u64 base=10007;
    int sz;
    u64 hash;
    constexpr rolling_hash():sz(0),hash(0){}
    constexpr rolling_hash(char c):sz(1),hash(c){}
    rolling_hash(std::string s):sz(0),hash(0){
        for(auto c:s)(*this)+=c;
    }
    constexpr u64 pow(u64 s,int t){
        u64 ret=1;
        while(t){
            if(t&1)ret=mul(ret,s);
            s=mul(s,s);
            t/=2;
        }
        return ret;
    }
    constexpr u64 add(u64 s,u64 t)noexcept{
        s+=t;
        return s>=mod?s-mod:s;
    }
    constexpr u64 sub(u64 s,u64 t)noexcept{
        if(s<t)s+=mod;
        return s-t;
    }
    constexpr u64 mul(u64 a,u64 b)noexcept{
        u64 au=a>>31,ad=a&((1ULL<<31)-1);
        u64 bu=b>>31,bd=b&((1ULL<<31)-1);
        u64 mid=au*bd+ad*bu;
        u64 ret=(au*bu*2+ad*bd+(mid>>30)+((mid&((1ULL<<30)-1))<<31));
        ret=(ret>>61)+(ret&mod);
        return ret>=mod?ret-mod:ret;
    }
    constexpr rolling_hash operator+(rolling_hash s)const noexcept{return rolling_hash(*this)+=s;}
    constexpr bool operator==(rolling_hash s)noexcept{return hash==s.hash&&sz==s.sz;}
    constexpr bool operator<(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<std::make_pair(s.hash,s.sz);}
    constexpr bool operator>(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>std::make_pair(s.hash,s.sz);}
    constexpr bool operator<=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<=std::make_pair(s.hash,s.sz);}
    constexpr bool operator>=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>=std::make_pair(s.hash,s.sz);}
    constexpr rolling_hash operator+=(rolling_hash s)noexcept{
        (*this).hash=add((*this).hash*pow(base,s.sz),s.hash);
        (*this).sz+=s.sz;
        return *this;
    }
    constexpr int size(){return sz;}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/rolling_hash.hpp"
#include<string>
#include<vector>
#include<set>
#include<tuple>

struct rolling_hash{
    using u64=std::uint64_t;
    constexpr static u64 mod=(1ULL<<61)-1;
    constexpr static u64 base=10007;
    int sz;
    u64 hash;
    constexpr rolling_hash():sz(0),hash(0){}
    constexpr rolling_hash(char c):sz(1),hash(c){}
    rolling_hash(std::string s):sz(0),hash(0){
        for(auto c:s)(*this)+=c;
    }
    constexpr u64 pow(u64 s,int t){
        u64 ret=1;
        while(t){
            if(t&1)ret=mul(ret,s);
            s=mul(s,s);
            t/=2;
        }
        return ret;
    }
    constexpr u64 add(u64 s,u64 t)noexcept{
        s+=t;
        return s>=mod?s-mod:s;
    }
    constexpr u64 sub(u64 s,u64 t)noexcept{
        if(s<t)s+=mod;
        return s-t;
    }
    constexpr u64 mul(u64 a,u64 b)noexcept{
        u64 au=a>>31,ad=a&((1ULL<<31)-1);
        u64 bu=b>>31,bd=b&((1ULL<<31)-1);
        u64 mid=au*bd+ad*bu;
        u64 ret=(au*bu*2+ad*bd+(mid>>30)+((mid&((1ULL<<30)-1))<<31));
        ret=(ret>>61)+(ret&mod);
        return ret>=mod?ret-mod:ret;
    }
    constexpr rolling_hash operator+(rolling_hash s)const noexcept{return rolling_hash(*this)+=s;}
    constexpr bool operator==(rolling_hash s)noexcept{return hash==s.hash&&sz==s.sz;}
    constexpr bool operator<(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<std::make_pair(s.hash,s.sz);}
    constexpr bool operator>(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>std::make_pair(s.hash,s.sz);}
    constexpr bool operator<=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<=std::make_pair(s.hash,s.sz);}
    constexpr bool operator>=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>=std::make_pair(s.hash,s.sz);}
    constexpr rolling_hash operator+=(rolling_hash s)noexcept{
        (*this).hash=add((*this).hash*pow(base,s.sz),s.hash);
        (*this).sz+=s.sz;
        return *this;
    }
    constexpr int size(){return sz;}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

