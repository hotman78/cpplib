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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: util/ACL/util.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3f6993c271f9d16deca67542cd4cc80e">util/ACL</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/ACL/util.hpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<atcoder/modint>
#include<iostream>
using namespace atcoder;

template<int MOD>
std::ostream& operator<<(std::ostream& lhs, const atcoder::static_modint<MOD>& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}

template<int MOD>
std::istream& operator>>(std::istream& lhs,atcoder::static_modint<MOD>& rhs) noexcept {
    unsigned int x;
    lhs >> x;
    rhs=x;
    return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const atcoder::modint& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}

std::istream& operator>>(std::istream& lhs,atcoder::modint& rhs) noexcept {
    unsigned int x;
    lhs >> x;
    rhs=x;
    return lhs;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "util/ACL/util.hpp"
#include<atcoder/modint>
#include<iostream>
using namespace atcoder;

template<int MOD>
std::ostream& operator<<(std::ostream& lhs, const atcoder::static_modint<MOD>& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}

template<int MOD>
std::istream& operator>>(std::istream& lhs,atcoder::static_modint<MOD>& rhs) noexcept {
    unsigned int x;
    lhs >> x;
    rhs=x;
    return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const atcoder::modint& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}

std::istream& operator>>(std::istream& lhs,atcoder::modint& rhs) noexcept {
    unsigned int x;
    lhs >> x;
    rhs=x;
    return lhs;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

