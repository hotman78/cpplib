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


# :heavy_check_mark: data_structure/dsu/union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7490ac1138b0c79126fd7a453fe0bd8b">data_structure/dsu</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/dsu/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 11:38:51+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structure/dsu/union_find.hpp.html">Union Find <small>(data_structure/dsu/union_find.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<bits/stdc++.h>
using namespace std;
#include "union_find.hpp"

int main(){
    int n,q;
    cin>>n>>q;
    UF uf(n);
    for(int i=0;i<q;++i){
        int c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            uf.unite(s,t);
        }else{
            cout<<uf.same(s,t)<<endl;
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/dsu/union_find.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<bits/stdc++.h>
using namespace std;
#line 1 "data_structure/dsu/union_find.hpp"
/**
 * @brief Union Find
 * @docs docs/union_find.md
 * @see https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0
 */

class UF{
    public:
    vector<int> data;
    int sz;
	public:
    UF(int sz):sz(sz){data.resize(sz,-1);}
    bool unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return 0;
        if(data[x]>data[y])swap(x,y);
		data[x]+=data[y];
		data[y]=x;
		sz--;
        return 1;
    }
    inline int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
    inline bool same(int x, int y){return root(x)==root(y);}
    inline int size(){return sz;}
	inline int size(int x){return -data[root(x)];}
};
#line 5 "data_structure/dsu/union_find.test.cpp"

int main(){
    int n,q;
    cin>>n>>q;
    UF uf(n);
    for(int i=0;i<q;++i){
        int c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            uf.unite(s,t);
        }else{
            cout<<uf.same(s,t)<<endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

