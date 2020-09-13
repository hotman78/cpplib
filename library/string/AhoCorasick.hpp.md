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


# :warning: string/AhoCorasick.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/AhoCorasick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:40:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<queue>

class AhoCorasick{
    struct node;
    using np=node*;
    constexpr static int num=26;
    constexpr static char base='A';
    struct node{
        np ch[num];
        np link=nullptr;
        int val=0;
        node(){
            for(int i=0;i<num;++i)ch[i]=nullptr;
        }
    };
    np root=new node();
    np root_par=new node();
    public:
    AhoCorasick(){
        root->link=root_par;
        for(int i=0;i<num;++i)root_par->ch[i]=root;
    }
    void insert(std::string v){
        np t=root;
        int idx=0;
        while(idx<(int)v.size()){
            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new node();
            t=t->ch[v[idx]-base];
            idx++;
        }
        t->val++;
    }
    void build(){
        built=1;
        std::queue<np>que;
        que.push(root);
        while(!que.empty()){
            np t=que.front();
            que.pop();
            for(int i=0;i<num;++i){
                if(!t->ch[i])continue;
                if(t==root){
                    t->ch[i]->link=t;
                }else{
                    np s=t->link;
                    while(!s->ch[i]){
                        s=s->link;
                    }
                    t->ch[i]->link=s->ch[i];
                }
                que.push(t->ch[i]);
            }
        }
    }
    bool built=0;
    int count(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    idx++;
                    if(idx==(int)v.size())return res;
                }else{
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            auto s=t;
            while(s!=root){
                res+=s->val;
                s=s->link;
            }
        }
        return res;
    }
    int find_first(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    res++;
                    idx++;
                    if(idx==(int)v.size())return -1;
                }else{
                    res++;
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            if(t->val>0)return res;
        }
        return -1;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/AhoCorasick.hpp"
#include<string>
#include<queue>

class AhoCorasick{
    struct node;
    using np=node*;
    constexpr static int num=26;
    constexpr static char base='A';
    struct node{
        np ch[num];
        np link=nullptr;
        int val=0;
        node(){
            for(int i=0;i<num;++i)ch[i]=nullptr;
        }
    };
    np root=new node();
    np root_par=new node();
    public:
    AhoCorasick(){
        root->link=root_par;
        for(int i=0;i<num;++i)root_par->ch[i]=root;
    }
    void insert(std::string v){
        np t=root;
        int idx=0;
        while(idx<(int)v.size()){
            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new node();
            t=t->ch[v[idx]-base];
            idx++;
        }
        t->val++;
    }
    void build(){
        built=1;
        std::queue<np>que;
        que.push(root);
        while(!que.empty()){
            np t=que.front();
            que.pop();
            for(int i=0;i<num;++i){
                if(!t->ch[i])continue;
                if(t==root){
                    t->ch[i]->link=t;
                }else{
                    np s=t->link;
                    while(!s->ch[i]){
                        s=s->link;
                    }
                    t->ch[i]->link=s->ch[i];
                }
                que.push(t->ch[i]);
            }
        }
    }
    bool built=0;
    int count(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    idx++;
                    if(idx==(int)v.size())return res;
                }else{
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            auto s=t;
            while(s!=root){
                res+=s->val;
                s=s->link;
            }
        }
        return res;
    }
    int find_first(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    res++;
                    idx++;
                    if(idx==(int)v.size())return -1;
                }else{
                    res++;
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            if(t->val>0)return res;
        }
        return -1;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

