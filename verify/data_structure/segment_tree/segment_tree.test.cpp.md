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


# :heavy_check_mark: data_structure/segment_tree/segment_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fba856dbe1aaa5374a50a27f6dcea717">data_structure/segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segment_tree/segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 19:03:25+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/alga/maybe.hpp.html">alga/maybe.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structure/segment_tree/segment_tree.hpp.html">data_structure/segment_tree/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../../library/util/template.hpp.html">util/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include<bits/stdc++.h>
using namespace std;
#include "../../util/template.hpp"
#include "segment_tree.hpp"

int main(){
    lint n,q;
    cin>>n>>q;
    vec v(n);
    rep(i,n){
        cin>>v[i];
    }
    auto seg=make_segment_tree(v,plus<lint>());
    rep(i,q){
        lint c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            seg.apply(s,t);
        }else{
            cout<<seg.get(s,t).unwrap()<<endl;
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/segment_tree/segment_tree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include<bits/stdc++.h>
using namespace std;
#line 1 "util/template.hpp"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#line 5 "util/template.hpp"
using namespace std;
__attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define endl ('\n')
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(lint i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(lint i=0;i<t.size();i++)output(t[i]);}
#define rep(i,...) for(auto i:range(__VA_ARGS__)) 
#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))
#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
#define irep(i) for(lint i=0;;++i)
inline vector<long long> range(long long n){vector<long long>v(n);iota(v.begin(),v.end(),0LL);return v;}
inline vector<long long> range(long long a,long long b){vector<long long>v(b-a);iota(v.begin(),v.end(),a);return v;}
inline vector<long long> range(long long a,long long b,long long c){if((b-a+c-1)/c<=0)return vector<long long>();vector<long long>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return v;}
template<typename T>inline T reversed(T v){reverse(v.begin(),v.end());return v;}
#define all(n) begin(n),end(n)
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
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
#line 6 "data_structure/segment_tree/segment_tree.test.cpp"

int main(){
    lint n,q;
    cin>>n>>q;
    vec v(n);
    rep(i,n){
        cin>>v[i];
    }
    auto seg=make_segment_tree(v,plus<lint>());
    rep(i,q){
        lint c,s,t;
        cin>>c>>s>>t;
        if(c==0){
            seg.apply(s,t);
        }else{
            cout<<seg.get(s,t).unwrap()<<endl;
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

