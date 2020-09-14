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


# :warning: Manacher <small>(string/manacher.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/manacher.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 10:40:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<vector>

/**
 * @brief Manacher
 */

std::vector<int> manacher(std::string S){
    int i = 0, j = 0;
    std::string s;
    for(int i=0;i<(int)S.size();i++){
        if(i)s+='$';
        s+=S[i];
    }
    int n=s.size();
    std::vector<int>res(n,0);
    while (i<n) {
        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])++j;
        res[i]=j;
        int k=1;
        while (i-k >= 0 && k+res[i-k]<j)res[i+k]=res[i-k],++k;
        i+=k;j-=k;
    }
    for(int i=0;i<n;++i){
        if(i%2)res[i]=res[i]/2;
        else res[i]=(res[i]+1)/2;
    }
    return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/manacher.hpp"
#include<string>
#include<vector>

/**
 * @brief Manacher
 */

std::vector<int> manacher(std::string S){
    int i = 0, j = 0;
    std::string s;
    for(int i=0;i<(int)S.size();i++){
        if(i)s+='$';
        s+=S[i];
    }
    int n=s.size();
    std::vector<int>res(n,0);
    while (i<n) {
        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j])++j;
        res[i]=j;
        int k=1;
        while (i-k >= 0 && k+res[i-k]<j)res[i+k]=res[i-k],++k;
        i+=k;j-=k;
    }
    for(int i=0;i<n;++i){
        if(i%2)res[i]=res[i]/2;
        else res[i]=(res[i]+1)/2;
    }
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

