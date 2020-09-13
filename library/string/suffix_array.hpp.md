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


# :warning: string/suffix_array.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/suffix_array.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:40:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include<cmath>

std::vector<int> suffix_array(std::string s){
    int n=s.size();
    std::vector<int> v1(n,-1),v2(n,-1);
    std::vector<int> rank(n,-1);
    std::iota(v1.begin(),v1.end(),0);
    std::iota(v2.begin(),v2.end(),0);
    std::sort(v1.begin(),v1.end(),[&](auto p,auto q){return s[p]<s[q];});
    int idx=0;
    for(int i=0;i<n;++i){
        rank[v1[i]]=idx;
        if(i<n-1&&s[v1[i]]!=s[v1[i+1]])idx++;
    }
    for(int i=0;i<(int)std::log2(n)+2;++i){
        const int h=1<<i;
        std::sort(v2.begin(),v2.end(),[&](auto p,auto q){
            return make_pair(rank[p],p+h<n?rank[p+h]:-1)<make_pair(rank[q],q+h<n?rank[q+h]:-1);
        });
        swap(v1,v2);
        idx=0;
        std::vector<int> tmp(n,-1);
        for(int j=0;j<n;++j){
            tmp[v1[j]]=idx;
            if(j<n-1&&std::make_pair(rank[v1[j]],v1[j]+h<n?rank[v1[j]+h]:-1)<std::make_pair(rank[v1[j+1]],v1[j+1]+h<n?rank[v1[j+1]+h]:-1))idx++;
        }
        std::swap(rank,tmp);
    }
    return v1;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/suffix_array.hpp"
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include<cmath>

std::vector<int> suffix_array(std::string s){
    int n=s.size();
    std::vector<int> v1(n,-1),v2(n,-1);
    std::vector<int> rank(n,-1);
    std::iota(v1.begin(),v1.end(),0);
    std::iota(v2.begin(),v2.end(),0);
    std::sort(v1.begin(),v1.end(),[&](auto p,auto q){return s[p]<s[q];});
    int idx=0;
    for(int i=0;i<n;++i){
        rank[v1[i]]=idx;
        if(i<n-1&&s[v1[i]]!=s[v1[i+1]])idx++;
    }
    for(int i=0;i<(int)std::log2(n)+2;++i){
        const int h=1<<i;
        std::sort(v2.begin(),v2.end(),[&](auto p,auto q){
            return make_pair(rank[p],p+h<n?rank[p+h]:-1)<make_pair(rank[q],q+h<n?rank[q+h]:-1);
        });
        swap(v1,v2);
        idx=0;
        std::vector<int> tmp(n,-1);
        for(int j=0;j<n;++j){
            tmp[v1[j]]=idx;
            if(j<n-1&&std::make_pair(rank[v1[j]],v1[j]+h<n?rank[v1[j]+h]:-1)<std::make_pair(rank[v1[j+1]],v1[j+1]+h<n?rank[v1[j+1]+h]:-1))idx++;
        }
        std::swap(rank,tmp);
    }
    return v1;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

