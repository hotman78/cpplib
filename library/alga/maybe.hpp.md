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


# :heavy_check_mark: Maybe <small>(alga/maybe.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e6f47b8acce0ca7627e3018b3efad838">alga</a>
* <a href="{{ site.github.repository_url }}/blob/master/alga/maybe.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 09:41:15+09:00


* see: <a href="https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89">https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8A%E3%83%89_(%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0)#Maybe%E3%83%A2%E3%83%8A%E3%83%89</a>




## Required by

* :warning: <a href="monoid.hpp.html">alga/monoid.hpp</a>
* :heavy_check_mark: <a href="../data_structure/segment_tree/segment_tree.hpp.html">Segment Tree <small>(data_structure/segment_tree/segment_tree.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/segment_tree/segment_tree.test.cpp.html">data_structure/segment_tree/segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
