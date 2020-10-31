
/**
 * @brief 形式的冪級数
 * 
 * verified with    :https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
 * submission       :https://judge.yosupo.jp/submission/28303
 * 
 */
template<typename T,typename F>
struct fps_base:vector<T>{
    using std::vector<T>::vector;
    using P=fps_base<T,F>;
    F op;
    fps_base(F op=F()):op(op){}
    P operator +(T x)const{return P(*this)+=x;}
    P operator -(T x)const{return P(*this)-=x;}
    P operator *(T x)const{return P(*this)*=x;}
    P operator /(T x)const{return P(*this)/=x;}
    P operator <<(int x){return P(*this)<<=x;}
    P operator >>(int x){return P(*this)>>=x;}
    P operator +(const P& x)const{return P(*this)+=x;}
    P operator -(const P& x)const{return P(*this)-=x;}
    P operator -()const{return P(1,T(0))-=P(*this);}
    P operator *(const P& x)const{return P(*this)*=x;}
    P operator /(const P& x)const{return P(*this)/=x;}
    P operator %(const P& x)const{return P(*this)%=x;}
    bool operator ==(P x){
        return shrink()==x.shrink();
    }
    P &operator +=(T x){
        if(this->size()==0)return *this=P{x};
        (*this)[0]+=x;
        return *this;
    }
    P &operator -=(T x){
        if(this->size()==0)return *this=P{-x};
        (*this)[0]+=x;
        return *this;
    }
    P &operator *=(T x){
        rep(i,0,this->size())(*this)[i]*=x;
        return *this;
    }
    P &operator /=(T x){
        return *this*=T(1)/x;
    }
    P &operator <<=(int x){
        P ret(x,T(0));
        ret.insert(ret.end(),this->begin(),this->end());
        return *this=ret;
    }
    P &operator >>=(int x){
        if((int)this->size()<=x)return *this=P();
        P ret;
        ret.insert(ret.end(),this->begin()+x,this->end());
        return (*this)=ret;
    }
    P &operator +=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        rep(i,0,x.size())(*this)[i]+=x[i];
        return *this;
    }
    P &operator -=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        rep(i,0,x.size())(*this)[i]-=x[i];
        return *this;
    }
    P &operator *=(const P& x){
        return *this=op(*this,x);
    }
    P &operator /=(P x){
        if(this->size()<x.size()){this->clear();return *this;}
        int n=this->size()-x.size()+1;
        return *this=(rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);
    }
    P &operator %=(const P& x){
        return (*this)-=(*this)/x*x;
    }
    P& shrink(){while(this->size()&&this->back()==T(0))this->pop_back();return *this;}
    P pre(int sz)const{
        return P(this->begin(),this->begin()+min<int>(this->size(),sz));
    }
    P rev(int deg=-1){
        P ret(*this);
        if(deg!=-1)ret.resize(deg,T(0));
        reverse(all(ret));
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
    P diff(){
        if((int)this->size()<=1)return P();
        P ret(*this);
        rep(i,0,ret.size())ret[i]*=i;
        return ret>>1;
    }
    P integral(){
        P ret(*this);
        rep(i,0,ret.size())ret[i]/=i+1;
        return ret<<1;
    }
    P log(int deg=-1){
        assert((*this)[0]==T(1));
        int n=deg==-1?this->size():deg;
        return (diff()*inv(n)).pre(n-1).integral();
    }
    P exp(int deg=-1){
        assert((*this)[0]==T(0));
        int n=deg==-1?this->size():deg;
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
		return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);
    }
    template<typename G>
    P sqrt(int deg=-1,G sq=G()){
        const int n=deg==-1?this->size():deg;
        int tmp=0;
        while((*this)[tmp]==T(0))tmp++;
        if(tmp&1)return {};
        if(n-tmp/2<=0)return P(n,0);
        if(tmp){
            return ((*this>>tmp).sqrt(n-tmp/2)<<(tmp/2)).resize(n,T(0));
        }else{
            P ret({T(1)});
            for(int i=1;i<n;i<<=1){
                ret=(ret+pre(i<<1)*ret.inv(i<<1)).pre(i<<1)/T(2);
            }
            return ret.pre(n);
        }
    }
};
struct __F__{template<typename T>T operator()(T s,T t){auto tmp=mul(s,t);return *static_cast<T*>(&tmp);}};
template<typename T>
using fps=fps_base<T,__F__>;