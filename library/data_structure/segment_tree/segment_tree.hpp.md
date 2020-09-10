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


# :heavy_check_mark: Segment Tree <small>(data_structure/segment_tree/segment_tree.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fba856dbe1aaa5374a50a27f6dcea717">data_structure/segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 20:32:02+09:00




## Operations

モノイド$M$の列$(a_1,a_2,\dots,a_n)$を扱う。
1添加を行う為、単位元を渡す必要はない。
空間計算量$\Theta(n)$

## How to use

- 初期化

```cpp
auto seg=make_segment_tree(vector<T>(n),plus<lint>());//+ monoid
auto seg=make_segment_tree(vector<T>(n),min<lint>);//min monoid
```

- 更新

``seg.apply(s,t)``で$a_s \leftarrow a_s \dot t$と更新

``seg.apply_left(s,t)``で$a_s \leftarrow t \dot a_s$と更新

``seg.change(s,t)``で$a_s \leftarrow	 t$と更新

- 取得

``seg.get(s,t)``で$a_s \dot a_{s+1} \dot \dots \dot a_{t-1}$をmaybe<T>型で取得


## Depends on

* :heavy_check_mark: <a href="../../alga/maybe.hpp.html">alga/maybe.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/data_structure/segment_tree/segment_tree.test.cpp.html">data_structure/segment_tree/segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Segment Tree
 * @docs docs/segment_tree.md
 */

#pragma once
#include"../../alga/maybe.hpp"
template<typename T,typename F>
class segment_tree{
	maybe<T>* node;
    F op;
	int n=1;
	public:
    segment_tree(){}
	segment_tree(int sz,F op):op(op){
		while(n<=sz)n<<=1;
		node=new maybe<T>[n*2];
		for(int i=0;i<n*2;i++)node[i]=maybe<T>();
	}
    segment_tree(const vector<T>&v,F op):op(op){
        auto f=expand<T,F>(op);
        const int sz=v.size();
		while(n<=sz)n<<=1;
		node=new maybe<T>[n*2]();
        for(int i=0;i<sz;i++)node[i+n]=maybe<T>(v[i]);
        for(int i=n-1;i>=1;i--)node[i]=f(node[i*2],node[i*2+1]);
	}
    maybe<T> get(int l,int r){
        auto f=expand<T,F>(op);
        l+=n;r+=n;
        maybe<T> s,t;
        while(l<r){
            if(l&1)s=f(s,node[l++]);
            if(r&1)t=f(node[--r],t);
            l>>=1;r>>=1;
        }
        return f(s,t);
    }
    void apply(int t,T _val){
        auto f=expand<T,F>(op);
        t+=n;
        maybe<T> val=maybe<T>(_val);
        while(t){
            node[t]=f(node[t],val);
            t=t>>1;
        }
    }
    void apply_left(int t,T _val){
        auto f=expand<T,F>(op);
        t+=n;
        maybe<T> val=maybe<T>(_val);
        while(t){
            node[t]=f(val,node[t]);
            t=t>>1;
        }
    }
    void change(int t,T val){
        auto f=expand<T,F>(op);
        t+=n;
        node[t]=maybe<T>(val);
        while(t>1){
            t=t>>1;
            node[t]=f(node[t*2],node[t*2+1]);
        }
    }
};

template<typename T,typename F>
segment_tree<T,F> make_segment_tree(vector<T> v,F op){
    return segment_tree<T,F>(v,op);
}
template<typename T,typename F>
segment_tree<T,F> make_segment_tree(int size,T goast,F op){
    return segment_tree<T,F>(size,op);
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data_structure/segment_tree/segment_tree.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

