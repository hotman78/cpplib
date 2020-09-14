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


# :heavy_check_mark: 形式的冪級数(BASE) <small>(convolution/FPS_base.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/FPS_base.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 10:40:12+09:00




## Required by

* :heavy_check_mark: <a href="FPS.hpp.html">形式的冪級数(ModInt) <small>(convolution/FPS.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/convolution/test/LC_convolution_1000000007.test.cpp.html">convolution/test/LC_convolution_1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/convolution/test/LC_convolution_998244353.test.cpp.html">convolution/test/LC_convolution_998244353.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 形式的冪級数(BASE)
 */

template<typename T,typename F>
struct FPS_BASE:std::vector<T>{
    using std::vector<T>::vector;
    using P=FPS_BASE<T,F>;
    F fft;
    FPS_BASE(){}
    inline P operator +(T x)const noexcept{return P(*this)+=x;}
    inline P operator -(T x)const noexcept{return P(*this)-=x;}
    inline P operator *(T x)const noexcept{return P(*this)*=x;}
    inline P operator /(T x)const noexcept{return P(*this)/=x;}
    inline P operator <<(int x)noexcept{return P(*this)<<=x;}
    inline P operator >>(int x)noexcept{return P(*this)>>=x;}
    inline P operator +(const P& x)const noexcept{return P(*this)+=x;}
    inline P operator -(const P& x)const noexcept{return P(*this)-=x;}
    inline P operator -()const noexcept{return P(1,T(0))-=P(*this);}
    inline P operator *(const P& x)const noexcept{return P(*this)*=x;}
    inline P operator /(const P& x)const noexcept{return P(*this)/=x;}
    inline P operator %(const P& x)const noexcept{return P(*this)%=x;}
    bool operator ==(P x){
        for(int i=0;i<(int)max((*this).size(),x.size());++i){
            if(i>=(int)(*this).size()&&x[i]!=T())return 0;
            if(i>=(int)x.size()&&(*this)[i]!=T())return 0;
            if(i<(int)min((*this).size(),x.size()))if((*this)[i]!=x[i])return 0;
        }
        return 1;
    }
    P &operator +=(T x){
        if(this->size()==0)this->resize(1,T(0));
        (*this)[0]+=x;
        return (*this);
    }
    P &operator -=(T x){
        if(this->size()==0)this->resize(1,T(0));
        (*this)[0]-=x;
        return (*this);
    }
    P &operator *=(T x){
        for(int i=0;i<(int)this->size();++i){
            (*this)[i]*=x;
        }
        return (*this);
    }
    P &operator /=(T x){
        return (*this)*=(T(1)/x);
    }
    P &operator <<=(int x){
        P ret(x,T(0));
        ret.insert(ret.end(),begin(*this),end(*this));
        return (*this)=ret;
    }
    P &operator >>=(int x){
        if((int)(*this).size()<=x)return (*this)=P();
        P ret;
        ret.insert(ret.end(),begin(*this)+x,end(*this));
        return (*this)=ret;
    }
    P &operator +=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        for(int i=0;i<(int)x.size();++i){
            (*this)[i]+=x[i];
        }
        return (*this);
    }
    P &operator -=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        for(int i=0;i<(int)x.size();++i){
            (*this)[i]-=x[i];
        }
        return (*this);
    }
    P &operator *=(const P& x){
        return (*this)=F()(*this,x);
    }
    P &operator /=(P x){
        if(this->size()<x.size()) {
            this->clear();
            return (*this);
        }
        const int n=this->size()-x.size()+1;
        return (*this) = (rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);
    }
    P &operator %=(const P& x){
        return ((*this)-=*this/x*x);
    }
    inline void print(){
        for(int i=0;i<(int)(*this).size();++i)cerr<<(*this)[i]<<" \n"[i==(int)(*this).size()-1];
        if((int)(*this).size()==0)cerr<<endl;
    }
    inline P& shrink(){while((*this).back()==0)(*this).pop_back();return (*this);}
    inline P pre(int sz)const{
        return P(begin(*this),begin(*this)+min((int)this->size(),sz));
    }
    P rev(int deg=-1){
        P ret(*this);
        if(deg!=-1)ret.resize(deg,T(0));
        reverse(begin(ret),end(ret));
        return ret;
    }
    P inv(int deg=-1){
        assert((*this)[0]!=T(0));
        const int n=deg==-1?this->size():deg;
        P ret({T(1)/(*this)[0]});
        for(int i=1;i<n;i<<=1){
            ret*=(-ret*pre(i<<1)+2).pre(i<<1);
        }
        return ret.pre(n);
    }
    inline P dot(const P& x){
        P ret(*this);
        for(int i=0;i<int(min(this->size(),x.size()));++i){
            ret[i]*=x[i];
        }
        return ret;
    }
    P diff(){
        if((int)(*this).size()<=1)return P();
        P ret(*this);
        for(int i=0;i<(int)ret.size();i++){
            ret[i]*=i;
        }
        return ret>>1;
    }
    P integral(){
        P ret(*this);
        for(int i=0;i<(int)ret.size();i++){
            ret[i]/=i+1;
        }
        return ret<<1;
    }
    P log(int deg=-1){
        assert((*this)[0]==T(1));
        const int n=deg==-1?this->size():deg;
        return (diff()*inv(n)).pre(n-1).integral();
    }
    P exp(int deg=-1){
        assert((*this)[0]==T(0));
        const int n=deg==-1?this->size():deg;
        P ret({T(1)});
        for(int i=1;i<n;i<<=1){
            ret=ret*(pre(i<<1)+1-ret.log(i<<1)).pre(i<<1);
        }
        return ret.pre(n);
    }
    P pow(int c,int deg=-1){
        // const int n=deg==-1?this->size():deg;
        // long long i=0;
        // P ret(*this);
        // while(i!=(int)this->size()&&ret[i]==0)i++;
        // if(i==(int)this->size())return P(n,0);
        // if(i*c>=n)return P(n,0);
        // T k=ret[i];
        // return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);
        P x(*this);
        P ret(1,1);
        while(c) {
            if(c&1){
                ret*=x;
                if(~deg)ret=ret.pre(deg);
            }
            x*=x;
            if(~deg)x=x.pre(deg);
            c>>=1;
        }
        return ret;
    }
    P sqrt(int deg=-1){
        const int n=deg==-1?this->size():deg;
        if((*this)[0]==T(0)) {
            for(int i=1;i<(int)this->size();i++) {
                if((*this)[i]!=T(0)) {
                    if(i&1)return{};
                    if(n-i/2<=0)break;
                    auto ret=(*this>>i).sqrt(n-i/2)<<(i/2);
                    if((int)ret.size()<n)ret.resize(n,T(0));
                    return ret;
                }
            }
            return P(n,0);
        }
        P ret({T(1)});
        for(int i=1;i<n;i<<=1){
            ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);
        }
        return ret.pre(n);
    }
    P shift(int c){
        const int n=this->size();
        P f(*this),g(n,0);
        for(int i=0;i<n;++i)f[i]*=F().fact(T(i));
        for(int i=0;i<n;++i)g[i]=F().pow(T(c),i)/F().fact(T(i));
        g=g.rev();
        f*=g;
        f>>=n-1;
        for(int i=0;i<n;++i)f[i]/=F().fact(T(i));
        return f;
    }
    T eval(T x){
        T res=0;
        for(int i=(int)this->size()-1;i>=0;--i){
            res*=x;
            res+=(*this)[i];
        }
        return res;
    }
    vector<T> multipoint_eval(const vector<T>&x){
        const int n=x.size();
        P* v=new P[2*n-1];
        for(int i=0;i<n;i++)v[i+n-1]={T()-x[i],T(1)};
        for(int i=n-2;i>=0;i--){v[i]=v[i*2+1]*v[i*2+2];}
        v[0]=P(*this)%v[0];v[0].shrink();
        for(int i=1;i<n*2-1;i++){
            v[i]=v[(i-1)/2]%v[i];
            v[i].shrink();
        }
        vector<T>res(n);
        for(int i=0;i<n;i++)res[i]=v[i+n-1][0];
        return res;
    }
    P slice(int s,int e,int k){
        P res;
        for(int i=s;i<e;i+=k)res.push_back((*this)[i]);
        return res;
    }
    T nth_term(P q,int64_t x){
        if(x==0)return (*this)[0]/q[0];
        P p(*this);
        P q2=q;
        for(int i=1;i<(int)q2.size();i+=2)q2[i]*=-1;
        q*=q2;
        p*=q2;
        return p.slice(x%2,p.size(),2).nth_term(q.slice(0,q.size(),2),x/2);
    }
    
    //(*this)(t(x))
    P manipulate(P t,int deg){
        P s=P(*this);
        if(deg==0)return P();
        if((int)t.size()==1)return P{s.eval(t[0])};
        int k=min((int)::sqrt(deg/(::log2(deg)+1))+1,(int)t.size());
        int b=deg/k+1;
        P t2=t.pre(k);
        vector<P>table(s.size()/2+1,P{1});
        for(int i=1;i<(int)table.size();i++){
            table[i]=((table[i-1])*t2).pre(deg);
        }
        auto f=[&](auto f,auto l,auto r,int deg)->P{
            if(r-l==1)return P{*l};
            auto m=l+(r-l)/2;
            return f(f,l,m,deg)+(table[m-l]*f(f,m,r,deg)).pre(deg);
        };
        P ans=P();
        P tmp=f(f,s.begin(),s.end(),deg);
        P tmp2=P{1};
        T tmp3=T(1);
        int tmp5=-1;
        P tmp6=t2.diff();
        if(tmp6==P()){
            for(int i=0;i<b;++i){
                if(tmp.size()==0)break;
                ans+=(tmp2*tmp[0]).pre(deg)/tmp3;
                tmp=tmp.diff();
                tmp2=(tmp2*(t-t2)).pre(deg);
                tmp3*=T(i+1);
            }
        }else{
            while(t2[++tmp5]==T());
            P tmp4=(tmp6>>(tmp5-1)).inv(deg);
            for(int i=0;i<b;++i){
                ans+=(tmp*tmp2).pre(deg)/tmp3;
                tmp=((tmp.diff()>>(tmp5-1))*tmp4).pre(deg);
                tmp2=(tmp2*(t-t2)).pre(deg);
                tmp3*=T(i+1);
            }
        }
        return ans;
    }
    //(*this)(t(x))
    P manipulate2(P t,int deg){
        P ans=P();
        P s=(*this).rev();
        for(int i=0;i<(int)s.size();++i){
            ans=(ans*t+s[i]).pre(deg);
        }
        return ans;
    }
    void debug(){
        for(int i=0;i<(int)(*this).size();++i)cerr<<(*this)[i]<<" \n"[i==(int)(*this).size()-1];
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "convolution/FPS_base.hpp"
/**
 * @brief 形式的冪級数(BASE)
 */

template<typename T,typename F>
struct FPS_BASE:std::vector<T>{
    using std::vector<T>::vector;
    using P=FPS_BASE<T,F>;
    F fft;
    FPS_BASE(){}
    inline P operator +(T x)const noexcept{return P(*this)+=x;}
    inline P operator -(T x)const noexcept{return P(*this)-=x;}
    inline P operator *(T x)const noexcept{return P(*this)*=x;}
    inline P operator /(T x)const noexcept{return P(*this)/=x;}
    inline P operator <<(int x)noexcept{return P(*this)<<=x;}
    inline P operator >>(int x)noexcept{return P(*this)>>=x;}
    inline P operator +(const P& x)const noexcept{return P(*this)+=x;}
    inline P operator -(const P& x)const noexcept{return P(*this)-=x;}
    inline P operator -()const noexcept{return P(1,T(0))-=P(*this);}
    inline P operator *(const P& x)const noexcept{return P(*this)*=x;}
    inline P operator /(const P& x)const noexcept{return P(*this)/=x;}
    inline P operator %(const P& x)const noexcept{return P(*this)%=x;}
    bool operator ==(P x){
        for(int i=0;i<(int)max((*this).size(),x.size());++i){
            if(i>=(int)(*this).size()&&x[i]!=T())return 0;
            if(i>=(int)x.size()&&(*this)[i]!=T())return 0;
            if(i<(int)min((*this).size(),x.size()))if((*this)[i]!=x[i])return 0;
        }
        return 1;
    }
    P &operator +=(T x){
        if(this->size()==0)this->resize(1,T(0));
        (*this)[0]+=x;
        return (*this);
    }
    P &operator -=(T x){
        if(this->size()==0)this->resize(1,T(0));
        (*this)[0]-=x;
        return (*this);
    }
    P &operator *=(T x){
        for(int i=0;i<(int)this->size();++i){
            (*this)[i]*=x;
        }
        return (*this);
    }
    P &operator /=(T x){
        return (*this)*=(T(1)/x);
    }
    P &operator <<=(int x){
        P ret(x,T(0));
        ret.insert(ret.end(),begin(*this),end(*this));
        return (*this)=ret;
    }
    P &operator >>=(int x){
        if((int)(*this).size()<=x)return (*this)=P();
        P ret;
        ret.insert(ret.end(),begin(*this)+x,end(*this));
        return (*this)=ret;
    }
    P &operator +=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        for(int i=0;i<(int)x.size();++i){
            (*this)[i]+=x[i];
        }
        return (*this);
    }
    P &operator -=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        for(int i=0;i<(int)x.size();++i){
            (*this)[i]-=x[i];
        }
        return (*this);
    }
    P &operator *=(const P& x){
        return (*this)=F()(*this,x);
    }
    P &operator /=(P x){
        if(this->size()<x.size()) {
            this->clear();
            return (*this);
        }
        const int n=this->size()-x.size()+1;
        return (*this) = (rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);
    }
    P &operator %=(const P& x){
        return ((*this)-=*this/x*x);
    }
    inline void print(){
        for(int i=0;i<(int)(*this).size();++i)cerr<<(*this)[i]<<" \n"[i==(int)(*this).size()-1];
        if((int)(*this).size()==0)cerr<<endl;
    }
    inline P& shrink(){while((*this).back()==0)(*this).pop_back();return (*this);}
    inline P pre(int sz)const{
        return P(begin(*this),begin(*this)+min((int)this->size(),sz));
    }
    P rev(int deg=-1){
        P ret(*this);
        if(deg!=-1)ret.resize(deg,T(0));
        reverse(begin(ret),end(ret));
        return ret;
    }
    P inv(int deg=-1){
        assert((*this)[0]!=T(0));
        const int n=deg==-1?this->size():deg;
        P ret({T(1)/(*this)[0]});
        for(int i=1;i<n;i<<=1){
            ret*=(-ret*pre(i<<1)+2).pre(i<<1);
        }
        return ret.pre(n);
    }
    inline P dot(const P& x){
        P ret(*this);
        for(int i=0;i<int(min(this->size(),x.size()));++i){
            ret[i]*=x[i];
        }
        return ret;
    }
    P diff(){
        if((int)(*this).size()<=1)return P();
        P ret(*this);
        for(int i=0;i<(int)ret.size();i++){
            ret[i]*=i;
        }
        return ret>>1;
    }
    P integral(){
        P ret(*this);
        for(int i=0;i<(int)ret.size();i++){
            ret[i]/=i+1;
        }
        return ret<<1;
    }
    P log(int deg=-1){
        assert((*this)[0]==T(1));
        const int n=deg==-1?this->size():deg;
        return (diff()*inv(n)).pre(n-1).integral();
    }
    P exp(int deg=-1){
        assert((*this)[0]==T(0));
        const int n=deg==-1?this->size():deg;
        P ret({T(1)});
        for(int i=1;i<n;i<<=1){
            ret=ret*(pre(i<<1)+1-ret.log(i<<1)).pre(i<<1);
        }
        return ret.pre(n);
    }
    P pow(int c,int deg=-1){
        // const int n=deg==-1?this->size():deg;
        // long long i=0;
        // P ret(*this);
        // while(i!=(int)this->size()&&ret[i]==0)i++;
        // if(i==(int)this->size())return P(n,0);
        // if(i*c>=n)return P(n,0);
        // T k=ret[i];
        // return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);
        P x(*this);
        P ret(1,1);
        while(c) {
            if(c&1){
                ret*=x;
                if(~deg)ret=ret.pre(deg);
            }
            x*=x;
            if(~deg)x=x.pre(deg);
            c>>=1;
        }
        return ret;
    }
    P sqrt(int deg=-1){
        const int n=deg==-1?this->size():deg;
        if((*this)[0]==T(0)) {
            for(int i=1;i<(int)this->size();i++) {
                if((*this)[i]!=T(0)) {
                    if(i&1)return{};
                    if(n-i/2<=0)break;
                    auto ret=(*this>>i).sqrt(n-i/2)<<(i/2);
                    if((int)ret.size()<n)ret.resize(n,T(0));
                    return ret;
                }
            }
            return P(n,0);
        }
        P ret({T(1)});
        for(int i=1;i<n;i<<=1){
            ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);
        }
        return ret.pre(n);
    }
    P shift(int c){
        const int n=this->size();
        P f(*this),g(n,0);
        for(int i=0;i<n;++i)f[i]*=F().fact(T(i));
        for(int i=0;i<n;++i)g[i]=F().pow(T(c),i)/F().fact(T(i));
        g=g.rev();
        f*=g;
        f>>=n-1;
        for(int i=0;i<n;++i)f[i]/=F().fact(T(i));
        return f;
    }
    T eval(T x){
        T res=0;
        for(int i=(int)this->size()-1;i>=0;--i){
            res*=x;
            res+=(*this)[i];
        }
        return res;
    }
    vector<T> multipoint_eval(const vector<T>&x){
        const int n=x.size();
        P* v=new P[2*n-1];
        for(int i=0;i<n;i++)v[i+n-1]={T()-x[i],T(1)};
        for(int i=n-2;i>=0;i--){v[i]=v[i*2+1]*v[i*2+2];}
        v[0]=P(*this)%v[0];v[0].shrink();
        for(int i=1;i<n*2-1;i++){
            v[i]=v[(i-1)/2]%v[i];
            v[i].shrink();
        }
        vector<T>res(n);
        for(int i=0;i<n;i++)res[i]=v[i+n-1][0];
        return res;
    }
    P slice(int s,int e,int k){
        P res;
        for(int i=s;i<e;i+=k)res.push_back((*this)[i]);
        return res;
    }
    T nth_term(P q,int64_t x){
        if(x==0)return (*this)[0]/q[0];
        P p(*this);
        P q2=q;
        for(int i=1;i<(int)q2.size();i+=2)q2[i]*=-1;
        q*=q2;
        p*=q2;
        return p.slice(x%2,p.size(),2).nth_term(q.slice(0,q.size(),2),x/2);
    }
    
    //(*this)(t(x))
    P manipulate(P t,int deg){
        P s=P(*this);
        if(deg==0)return P();
        if((int)t.size()==1)return P{s.eval(t[0])};
        int k=min((int)::sqrt(deg/(::log2(deg)+1))+1,(int)t.size());
        int b=deg/k+1;
        P t2=t.pre(k);
        vector<P>table(s.size()/2+1,P{1});
        for(int i=1;i<(int)table.size();i++){
            table[i]=((table[i-1])*t2).pre(deg);
        }
        auto f=[&](auto f,auto l,auto r,int deg)->P{
            if(r-l==1)return P{*l};
            auto m=l+(r-l)/2;
            return f(f,l,m,deg)+(table[m-l]*f(f,m,r,deg)).pre(deg);
        };
        P ans=P();
        P tmp=f(f,s.begin(),s.end(),deg);
        P tmp2=P{1};
        T tmp3=T(1);
        int tmp5=-1;
        P tmp6=t2.diff();
        if(tmp6==P()){
            for(int i=0;i<b;++i){
                if(tmp.size()==0)break;
                ans+=(tmp2*tmp[0]).pre(deg)/tmp3;
                tmp=tmp.diff();
                tmp2=(tmp2*(t-t2)).pre(deg);
                tmp3*=T(i+1);
            }
        }else{
            while(t2[++tmp5]==T());
            P tmp4=(tmp6>>(tmp5-1)).inv(deg);
            for(int i=0;i<b;++i){
                ans+=(tmp*tmp2).pre(deg)/tmp3;
                tmp=((tmp.diff()>>(tmp5-1))*tmp4).pre(deg);
                tmp2=(tmp2*(t-t2)).pre(deg);
                tmp3*=T(i+1);
            }
        }
        return ans;
    }
    //(*this)(t(x))
    P manipulate2(P t,int deg){
        P ans=P();
        P s=(*this).rev();
        for(int i=0;i<(int)s.size();++i){
            ans=(ans*t+s[i]).pre(deg);
        }
        return ans;
    }
    void debug(){
        for(int i=0;i<(int)(*this).size();++i)cerr<<(*this)[i]<<" \n"[i==(int)(*this).size()-1];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

