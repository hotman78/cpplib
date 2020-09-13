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


# :warning: string/suffix_automaton.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/suffix_automaton.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:40:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

struct suffix_automaton{
    struct node;
    using np=node*;
    struct node{
        int len,id;
        std::map<char,np> ch;
        np link=nullptr;
        node(int len,int id):len(len),id(id){}
    };
    std::vector<np>list;
    np root=new node(0,0);
    np t=root;
    suffix_automaton(std::string s){
        list.emplace_back(root);
        for(auto c:s)add(c);
        dfs(root);
        std::reverse(tsort.begin(),tsort.end());
    }
    void add(char c){
        np cur=new node(t->len+1,list.size());
        list.emplace_back(cur);
        for(;t&&!t->ch.count(c);t=t->link)t->ch[c]=cur;
        if(!t)cur->link=root;
        else{
            np p=t,q=p->ch[c];
            if(q->len==p->len+1)cur->link=q;
            else{
                np clone=new node(*q);
                clone->len=p->len+1;
                clone->id=list.size();
                list.emplace_back(clone);
                for(;p&&p->ch[c]==q;p=p->link)p->ch[c]=clone;
                q->link=cur->link=clone;
            }
        }
        t=cur;
    }
    std::vector<int>tsort;
    std::set<np>visited;
    void dfs(np cur){
        if(visited.count(cur))return;
        visited.insert(cur);
        for(auto e:cur->ch)dfs(e.second);
        tsort.emplace_back(cur->id);
    }
    long long size(){
        std::vector<long long>dp(list.size(),0);
        long long ret=0;
        dp[0]=1;
        for(int i:tsort){
            ret+=dp[i];
            for(auto e:list[i]->ch){
                dp[e.second->id]+=dp[i];
            }
        }
        return ret-1;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/suffix_automaton.hpp"
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

struct suffix_automaton{
    struct node;
    using np=node*;
    struct node{
        int len,id;
        std::map<char,np> ch;
        np link=nullptr;
        node(int len,int id):len(len),id(id){}
    };
    std::vector<np>list;
    np root=new node(0,0);
    np t=root;
    suffix_automaton(std::string s){
        list.emplace_back(root);
        for(auto c:s)add(c);
        dfs(root);
        std::reverse(tsort.begin(),tsort.end());
    }
    void add(char c){
        np cur=new node(t->len+1,list.size());
        list.emplace_back(cur);
        for(;t&&!t->ch.count(c);t=t->link)t->ch[c]=cur;
        if(!t)cur->link=root;
        else{
            np p=t,q=p->ch[c];
            if(q->len==p->len+1)cur->link=q;
            else{
                np clone=new node(*q);
                clone->len=p->len+1;
                clone->id=list.size();
                list.emplace_back(clone);
                for(;p&&p->ch[c]==q;p=p->link)p->ch[c]=clone;
                q->link=cur->link=clone;
            }
        }
        t=cur;
    }
    std::vector<int>tsort;
    std::set<np>visited;
    void dfs(np cur){
        if(visited.count(cur))return;
        visited.insert(cur);
        for(auto e:cur->ch)dfs(e.second);
        tsort.emplace_back(cur->id);
    }
    long long size(){
        std::vector<long long>dp(list.size(),0);
        long long ret=0;
        dp[0]=1;
        for(int i:tsort){
            ret+=dp[i];
            for(auto e:list[i]->ch){
                dp[e.second->id]+=dp[i];
            }
        }
        return ret-1;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

