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


# :warning: Zアルゴリズム <small>(string/Z_algorizm.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/Z_algorizm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 10:40:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<vector>
#include<algorithm>

/**
 * @brief Zアルゴリズム
 */

std::vector<int> Z_algorizm(const std::string& s){
    std::vector<int>res(s.size());
    res[0]=s.size();
    int i=1,j=0;
    while(i<(int)s.size()){
        while(i+j<(int)s.size()&&s[j]==s[i+j])++j;
        res[i]=j;
        if(j==0){++i;continue;}
        int k=1;
        while(i+k<(int)s.size()&&k+res[k]<j)res[i+k]=res[k],++k;
        i+=k;j-=k;
    }
    return res;
}
int find_first(const std::string& s,const std::string& t){
    auto d=Z_algorizm(s+"#"+t);
    auto itr=std::find(d.begin()+s.size(),d.end(),s.size());
    if(itr!=d.end())return itr-d.begin()-s.size();
    else return -1;
}
int count(const std::string& s,const std::string& t){
    auto d=Z_algorizm(s+"#"+t);
    return std::count(d.begin()+s.size(),d.end(),s.size());
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/Z_algorizm.hpp"
#include<string>
#include<vector>
#include<algorithm>

/**
 * @brief Zアルゴリズム
 */

std::vector<int> Z_algorizm(const std::string& s){
    std::vector<int>res(s.size());
    res[0]=s.size();
    int i=1,j=0;
    while(i<(int)s.size()){
        while(i+j<(int)s.size()&&s[j]==s[i+j])++j;
        res[i]=j;
        if(j==0){++i;continue;}
        int k=1;
        while(i+k<(int)s.size()&&k+res[k]<j)res[i+k]=res[k],++k;
        i+=k;j-=k;
    }
    return res;
}
int find_first(const std::string& s,const std::string& t){
    auto d=Z_algorizm(s+"#"+t);
    auto itr=std::find(d.begin()+s.size(),d.end(),s.size());
    if(itr!=d.end())return itr-d.begin()-s.size();
    else return -1;
}
int count(const std::string& s,const std::string& t){
    auto d=Z_algorizm(s+"#"+t);
    return std::count(d.begin()+s.size(),d.end(),s.size());
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

