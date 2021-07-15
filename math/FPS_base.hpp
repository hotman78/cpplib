#pragma once
#include<vector>
#include<tuple>
#include<iostream>
#include<cmath>
#include<type_traits>
#include<cassert>

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
        if(std::is_same<T,long long>::value){
            for(int i=0;i<(int)this->size();++i){
                (*this)[i]/=x;
            }
            return (*this);
        }
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
        return ((*this)-=(*this)/x*x);
    }
    inline void print(){
        for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<" \n"[i==(int)(*this).size()-1];
        if((int)(*this).size()==0)std::cerr<<'\n';
    }
    inline P& shrink(){while((*this).back()==0)(*this).pop_back();return (*this);}
    inline P pre(int sz)const{
        return P(begin(*this),begin(*this)+std::min((int)this->size(),sz));
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
        const int n=deg==-1?this->size():deg;
		long long i=0;
		P ret(*static_cast<P*>(this));
		while(i!=(int)this->size()&&ret[i]==0)i++;
		if(i==(int)this->size())return P(n,0);
		if(i*c>=n)return P(n,0);
		T k=ret[i];
		return ((((ret>>i)/k).log(n)*c).exp(n)*(k.pow(c))<<(i*c)).pre(n);
        // const int n=deg==-1?this->size():deg;
        // long long i=0;
        // P ret(*this);
        // while(i!=(int)this->size()&&ret[i]==0)i++;
        // if(i==(int)this->size())return P(n,0);
        // if(i*c>=n)return P(n,0);
        // T k=ret[i];
        // return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);
        // P x(*this);
        // P ret(1,1);
        // while(c) {
        //     if(c&1){
        //         ret*=x;
        //         if(~deg)ret=ret.pre(deg);
        //     }
        //     x*=x;
        //     if(~deg)x=x.pre(deg);
        //     c>>=1;
        // }
        // return ret;
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
    P mul(const std::vector<std::pair<int,T>>& x){
        int mx=0;
        for(auto [s,t]:x){
            if(mx<s)mx=s;
        }
        P res((int)this->size()+mx);
        for(int i=0;i<(int)this->size();++i){
            for(auto [s,t]:x){
                res[i+s]+=(*this)[i]*t;
            }
        }
        return res;
    }
    P div(const std::vector<std::pair<int,T>>& x){
        P res(*this);
        T cnt=0;
        for(auto [s,t]:x){
            if(s==0)cnt+=t;
        }
        cnt=cnt.inv();
        for(int i=0;i<(int)this->size();++i){
            for(auto [s,t]:x){
                if(s==0)continue;
                if(i>=s)res[i]-=res[i-s]*t*cnt;
            }
        }
        res*=cnt;
        return res;
    }
    static P interpolation(const std::vector<T>&x,const std::vector<T>& y){
        const int n=x.size();
        std::vector<std::pair<P,P>>a(n*2-1);
        std::vector<P> b(n*2-1);
        for(int i=0;i<n;++i)a[i+n-1]=std::make_pair(P{1},P{T()-x[i],1});
        for(int i=n-2;i>=0;--i)a[i]={a[2*i+1].first*a[2*i+2].second+a[2*i+2].first*a[2*i+1].second,a[2*i+1].second*a[2*i+2].second};
        auto d=(a[0].first).multipoint_eval(x);
        for(int i=0;i<n;++i)b[i+n-1]=P{T(y[i]/d[i])};
        for(int i=n-2;i>=0;--i)b[i]=b[2*i+1]*a[2*i+2].second+b[2*i+2]*a[2*i+1].second;
        return b[0];
    }
    static P interpolation(const std::vector<T>& y){
        const int n=y.size();
        std::vector<std::pair<P,P>>a(n*2-1);
        std::vector<P>b(n*2-1);
        for(int i=0;i<n;++i)a[i+n-1]=std::make_pair(P{1},P{T()-i,1});
        for(int i=n-2;i>=0;--i)a[i]={a[2*i+1].first*a[2*i+2].second+a[2*i+2].first*a[2*i+1].second,a[2*i+1].second*a[2*i+2].second};
        for(int i=0;i<n;++i){
            T tmp=F().fact(T(i))*F().pow(T(-1),i)*F().fact(T(n-1-i));
            b[i+n-1]=P{T(y[i]/tmp)};
        }
        for(int i=n-2;i>=0;--i)b[i]=b[2*i+1]*a[2*i+2].second+b[2*i+2]*a[2*i+1].second;
        return b[0];
    }
    std::vector<T> multipoint_eval(const std::vector<T>&x){
        const int n=x.size();
        P* v=new P[2*n-1];
        for(int i=0;i<n;i++)v[i+n-1]={T()-x[i],T(1)};
        for(int i=n-2;i>=0;i--){v[i]=v[i*2+1]*v[i*2+2];}
        v[0]=P(*this)%v[0];v[0].shrink();
        for(int i=1;i<n*2-1;i++){
            v[i]=v[(i-1)/2]%v[i];
            v[i].shrink();
        }
        std::vector<T>res(n);
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
    T guess(int64_t x){
        auto p=find_linear_recurrence();
        auto q=p*P(*this);
        q.resize(this->size());
        return q.nth_term(p,x);
    }
    P gcd(P q){
        return *this==P()?q:(q%(*this).shrink()).gcd(*this);
    }
    //(*this)(t(x))
    P manipulate(P t,int deg){
        P s=P(*this);
        if(deg==0)return P();
        if((int)t.size()==1)return P{s.eval(t[0])};
        int k=std::min((int)::sqrt(deg/(::log2(deg)+1))+1,(int)t.size());
        int b=deg/k+1;
        P t2=t.pre(k);
        std::vector<P>table(s.size()/2+1,P{1});
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
    P find_linear_recurrence()const{
        const int n=this->size();
        P b={T(-1)},c={T(-1)};
        T y=T(1);
        for(int i=1;i<=n;++i){
            int l=c.size(),m=b.size();
            T x=0;
            for(int j=0;j<l;++j)x+=c[j]*(*this)[i-l+j];
            b.emplace_back(0);
            m++;
            if(x==T(0))continue;
            T freq=x/y;
            if(l<m){
                auto tmp=c;
                c<<=m-l;
                c-=b*freq;
                b=tmp;
                y=x;
            }else{
                c-=(b*freq)<<(l-m);
            }
        }
        return c.rev().shrink().rev();
    }
    static P stirling_second(int n){
        P a(n+1,0),b(n+1,0);
        for(int i=0;i<=n;++i){
            a[i]=F().pow(T(i),n)/F().fact(T(i));
            b[i]=(i%2?T(-1):T(1))/F().fact(T(i));
        }
        return (a*b).pre(n+1);
    }
    static pair<P,P> sum_of_fractional(const vector<pair<P,P>>&v){
        auto f=[&](const auto& s,const auto& t){
            return s.second>t.second;
        };
        priority_queue<pair<P,P>,vector<pair<P,P>>,decltype(f)>que(f);
        for(auto& e:v){
            que.emplace(e);
        }
        while(que.size()>=2){
            auto [s,t]=move(que.top());
            que.pop();
            auto [u,r]=move(que.top());
            que.pop();
            que.emplace(s*r+t*u,t*r);
        }
        return que.top();
    }
    static P sum_of_exp(const vector<T>&v){
        vector<pair<P,P>>tmp(v.size());
        for(int i=0;i<(int)v.size();++i){
            tmp[i]=make_pair(P{T(1)},P{T(1),T(v[i])*(-1)});
        }
        auto [s,t]=sum_of_fractional(tmp);
        auto res=s*t.inv();
        res.ord_to_exp();
        return res;
    }
    void ord_to_exp(){
        for(int i=0;i<this->size();++i){
            (*this)[i]/=F().fact(T(i));
        }
    }
    void exp_to_ord(){
        for(int i=0;i<this->size();++i){
            (*this)[i]*=F().fact(T(i));
        }
    }
    void debug(){
        for(int i=0;i<(int)(*this).size();++i)std::cerr<<(*this)[i]<<" \n"[i==(int)(*this).size()-1];
    }
};