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


# :x: data_structure/segment_tree/segment_tree.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fba856dbe1aaa5374a50a27f6dcea717">data_structure/segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 16:53:23+09:00




## Depends on

* :x: <a href="../../alga/maybe.hpp.html">alga/maybe.hpp</a>


## Verified with

* :x: <a href="../../../verify/data_structure/segment_tree/segment_tree.test.cpp.html">data_structure/segment_tree/segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
#line 1 "alga/maybe.hpp"
template<typename T>
struct maybe{
    bool _is_none;
    T val;
    maybe():_is_none(true){}
    maybe(T val):_is_none(false),val(val){}
    T unwrap()const{
        assert(!_is_none);
        return val;
    }
    T unwrap_or(T e)const{
        return _is_none?e:val;
    }
    bool is_none()const{return _is_none;}
    bool is_some()const{return !_is_none;}
};

template<typename T,typename F>
auto expand(F op){
    return [op](const maybe<T>& s,const maybe<T>& t){
        if(s.is_none())return t;
        if(t.is_none())return s;
        return maybe<T>(op(s.unwrap(),t.unwrap()));
    };
}
#line 3 "data_structure/segment_tree/segment_tree.hpp"
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

<a href="../../../index.html">Back to top page</a>

