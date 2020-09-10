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


# :heavy_check_mark: data_structure/segment_tree/segment_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fba856dbe1aaa5374a50a27f6dcea717">data_structure/segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree/segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 20:32:02+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/alga/maybe.hpp.html">alga/maybe.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structure/segment_tree/segment_tree.hpp.html">Segment Tree <small>(data_structure/segment_tree/segment_tree.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../../util/template.hpp"
#include "segment_tree.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    vec v(n);
    rep(i,n){
        cin>>v[i];
    }
    auto seg=make_segment_tree(v,plus<lint>());
    rep(i,q){
        lint c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            seg.apply(s,t);
        }else{
            cout<<seg.get(s,t).unwrap()<<endl;
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data_structure/segment_tree/segment_tree.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

