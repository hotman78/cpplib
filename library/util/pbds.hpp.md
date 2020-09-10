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


# :warning: util/pbds.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/pbds.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 19:03:25+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/pbds.hpp"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

