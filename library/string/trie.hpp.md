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


# :warning: Trie木 <small>(string/trie.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/trie.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 10:40:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>

/**
 * @brief Trie木
 */

struct trie{
    struct node;
    using np=node*;
    struct node{
        int sz=0,sz2=0;
        np ch[26]={};
    };
    np root=new node();
    void add(std::string s){
        np t=root;
        t->sz++;
        for(int i=0;i<(int)s.size();++i){
            if(!t->ch[s[i]-'a'])t->ch[s[i]-'a']=new node();
            t=t->ch[s[i]-'a'];
            t->sz++;
        }
        t->sz2=1;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/trie.hpp"
#include<string>

/**
 * @brief Trie木
 */

struct trie{
    struct node;
    using np=node*;
    struct node{
        int sz=0,sz2=0;
        np ch[26]={};
    };
    np root=new node();
    void add(std::string s){
        np t=root;
        t->sz++;
        for(int i=0;i<(int)s.size();++i){
            if(!t->ch[s[i]-'a'])t->ch[s[i]-'a']=new node();
            t=t->ch[s[i]-'a'];
            t->sz++;
        }
        t->sz2=1;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

