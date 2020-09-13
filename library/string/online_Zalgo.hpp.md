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


# :warning: string/online_Zalgo.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/online_Zalgo.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:40:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<vector>
#include<set>

struct online_Zalgo{
    std::vector<int>z;
    std::set<int>memo;
    std::vector<std::vector<int>>hist;
    std::string s="";
    int sz=0;
    void add(char c){
        s+=c;
        memo.emplace(sz);
        z.push_back(-1);
        hist.push_back(std::vector<int>());
        sz++;
        int mx=-1;
        for(auto itr=next(memo.begin(),1);itr!=memo.end();){
            auto idx=*itr;
            if(s[sz-idx-1]!=s.back()){
                itr=memo.erase(itr);
                z[idx]=sz-idx-1;
                hist.back().push_back(idx);
            }else{
                mx=idx;
                break;
            }
        }
        if(mx==-1)return;
        for(auto e:hist[sz-1-mx]){
            memo.erase(mx+e);
            z[mx+e]=sz-(mx+e)-1;
            hist.back().push_back(mx+e);
        }
    }
    int operator[](int idx){
        if(memo.count(idx))return sz-idx;
        else return z[idx];
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/online_Zalgo.hpp"
#include<string>
#include<vector>
#include<set>

struct online_Zalgo{
    std::vector<int>z;
    std::set<int>memo;
    std::vector<std::vector<int>>hist;
    std::string s="";
    int sz=0;
    void add(char c){
        s+=c;
        memo.emplace(sz);
        z.push_back(-1);
        hist.push_back(std::vector<int>());
        sz++;
        int mx=-1;
        for(auto itr=next(memo.begin(),1);itr!=memo.end();){
            auto idx=*itr;
            if(s[sz-idx-1]!=s.back()){
                itr=memo.erase(itr);
                z[idx]=sz-idx-1;
                hist.back().push_back(idx);
            }else{
                mx=idx;
                break;
            }
        }
        if(mx==-1)return;
        for(auto e:hist[sz-1-mx]){
            memo.erase(mx+e);
            z[mx+e]=sz-(mx+e)-1;
            hist.back().push_back(mx+e);
        }
    }
    int operator[](int idx){
        if(memo.count(idx))return sz-idx;
        else return z[idx];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

