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


# :warning: alga/monoid.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e6f47b8acce0ca7627e3018b3efad838">alga</a>
* <a href="{{ site.github.repository_url }}/blob/master/alga/monoid.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 09:41:15+09:00




## Depends on

* :heavy_check_mark: <a href="maybe.hpp.html">Maybe <small>(alga/maybe.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include"maybe.hpp"

template<typename T,typename F>
struct monoid{
    using M=monoid<T,F>;
    maybe<T> val;
    F op;
    monoid(F op):val(maybe<T>()),op(op){}
    monoid(T val,F op):val(maybe<T>(val)),op(op){}
    maybe<T> get(){return val;}
    void set(T x){return val=maybe<T>(x);}
    M operator+(const M& rhs){
        if(val.is_none())return rhs;
        if(rhs.val.is_none())return *this;
        return monoid(op(get().unwrap(),rhs.get().unwrap()),op);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "alga/maybe.hpp"
/**
 * @brief Maybe
 * @docs docs/maybe.md
 * @see https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89
 */

template<typename T>
struct maybe{
    bool _is_none;
    T val;
    maybe():_is_none(true){}
    maybe(T val):_is_none(false),val(val){}
    T unwrap()const{
        assert(!_is_none);
        return val;
    }
    T unwrap_or(T e)const{
        return _is_none?e:val;
    }
    bool is_none()const{return _is_none;}
    bool is_some()const{return !_is_none;}
};

template<typename T,typename F>
auto expand(F op){
    return [op](const maybe<T>& s,const maybe<T>& t){
        if(s.is_none())return t;
        if(t.is_none())return s;
        return maybe<T>(op(s.unwrap(),t.unwrap()));
    };
}
#line 3 "alga/monoid.hpp"

template<typename T,typename F>
struct monoid{
    using M=monoid<T,F>;
    maybe<T> val;
    F op;
    monoid(F op):val(maybe<T>()),op(op){}
    monoid(T val,F op):val(maybe<T>(val)),op(op){}
    maybe<T> get(){return val;}
    void set(T x){return val=maybe<T>(x);}
    M operator+(const M& rhs){
        if(val.is_none())return rhs;
        if(rhs.val.is_none())return *this;
        return monoid(op(get().unwrap(),rhs.get().unwrap()),op);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
