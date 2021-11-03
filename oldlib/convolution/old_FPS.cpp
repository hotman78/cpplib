template<typename T,typename P>
struct FPS_BASE:vector<T>{
    using vector<T>::vector;
    inline P operator +(T x)noexcept{return P(*static_cast<P*>(this))+=x;}
    inline P operator -(T x)noexcept{return P(*static_cast<P*>(this))-=x;}
    inline P operator *(T x)noexcept{return P(*static_cast<P*>(this))*=x;}
    inline P operator /(T x)noexcept{return P(*static_cast<P*>(this))/=x;}
    inline P operator <<(int x)noexcept{return P(*static_cast<P*>(this))<<=x;}
    inline P operator >>(int x)noexcept{return P(*static_cast<P*>(this))>>=x;}
    inline P operator +(const P& x)noexcept{return P(*static_cast<P*>(this))+=x;}
    inline P operator -(const P& x)noexcept{return P(*static_cast<P*>(this))-=x;}
    inline P operator -()noexcept{return P(1,T(0))-=P(*static_cast<P*>(this));}
    inline P operator *(const P& x)noexcept{return P(*static_cast<P*>(this))*=x;}
    inline P operator /(const P& x)noexcept{return P(*static_cast<P*>(this))/=x;}
    inline P operator %(const P& x)noexcept{return P(*static_cast<P*>(this))%=x;}
    inline P &operator +=(T x){
        if(this->size()==0)this->resize(1,T(0));
        (*static_cast<P*>(this))[0]+=x;
        return (*static_cast<P*>(this));
    }
    inline P &operator -=(T x){
        if(this->size()==0)this->resize(1,T(0));
        (*static_cast<P*>(this))[0]-=x;
        return (*static_cast<P*>(this));
    }
    inline P &operator *=(T x){
        for(int i=0;i<(int)this->size();++i){
            (*static_cast<P*>(this))[i]*=x;
        }
        return (*static_cast<P*>(this));
    }
    inline P &operator /=(T x){
        return (*static_cast<P*>(this))*=(T(1)/x);
    }
    inline P &operator <<=(int x){
        P ret(x,T(0));
        ret.insert(ret.end(),begin(*static_cast<P*>(this)),end(*static_cast<P*>(this)));
        return (*static_cast<P*>(this))=ret;
    }
    inline P &operator >>=(int x){
        P ret;
        ret.insert(ret.end(),begin(*static_cast<P*>(this))+x,end(*static_cast<P*>(this)));
        return (*static_cast<P*>(this))=ret;
    }
    inline P &operator +=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        for(int i=0;i<(int)x.size();++i){
            (*this)[i]+=x[i];
        }
        return (*static_cast<P*>(this));
    }
    inline P &operator -=(const P& x){
        if(this->size()<x.size())this->resize(x.size(),T(0));
        for(int i=0;i<(int)x.size();++i){
            (*static_cast<P*>(this))[i]-=x[i];
        }
        return (*static_cast<P*>(this));
    }
    inline P &operator *=(const P& x){
        return (*static_cast<P*>(this))=mul((*static_cast<P*>(this)),x);
    }
    inline P &operator /=(P x){
        if(this->size()<x.size()) {
            this->clear();
            return (*static_cast<P*>(this));
        }
        const int n=this->size()-x.size()+1;
        return (*static_cast<P*>(this)) = (rev().pre(n)*x.rev().inv(n)).pre(n).rev(n);
    }
    inline P &operator %=(const P& x){
        return ((*static_cast<P*>(this))-=*static_cast<P*>(this)/x*x);
    }
    inline P& shrink(){while((*static_cast<P*>(this)).back()==0)(*static_cast<P*>(this)).pop_back();return (*static_cast<P*>(this));}
    inline P pre(int sz)const{
        return P(begin(*this),begin(*this)+min((int)this->size(),sz));
    }
    inline P rev(int deg=-1){
        P ret(*static_cast<P*>(this));
        if(deg!=-1)ret.resize(deg,T(0));
        reverse(begin(ret),end(ret));
        return ret;
    }
    P inv(int deg=-1){
        assert((*static_cast<P*>(this))[0]!=T(0));
        const int n=deg==-1?this->size():deg;
        P ret({T(1)/(*this)[0]});
        for(int i=1;i<n;i<<=1){
            ret=(ret*T(2)-ret*ret*pre(i<<1)).pre(i<<1);
        }
        return ret.pre(n);
    }
    inline P dot(const P& x){
        P ret(*static_cast<P*>(this));
        for(int i=0;i<int(min(this->size(),x.size()));++i){
            ret[i]*=x[i];
        }
        return ret;
    }
    P diff(){
        P ret(*static_cast<P*>(this));
        for(int i=0;i<(int)ret.size();i++){
            ret[i]*=i;
        }
        return ret>>1;
    }
    P integral(){
        P ret(*static_cast<P*>(this));
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
		return ((((ret>>i)/k).log()*c).exp()*(k.pow(c))<<(i*c)).pre(n);
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
		P f(*static_cast<P*>(this)),g(n,0);
		for(int i=0;i<n;++i)f[i]*=T(i).fact();
		for(int i=0;i<n;++i)g[i]=T(c).pow(i)/T(i).fact();
		g=g.rev();
		f*=g;
		f>>=n-1;
		for(int i=0;i<n;++i)f[i]/=T(i).fact();
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
        v[0]=P(*static_cast<P*>(this))%v[0];v[0].shrink();
        for(int i=1;i<n*2-1;i++){
            v[i]=v[(i-1)/2]%v[i];
            v[i].shrink();
        }
        vector<T>res(n);
        for(int i=0;i<n;i++)res[i]=v[i+n-1][0];
        return res;
    }
    virtual P mul(P s,P t)=0;
};