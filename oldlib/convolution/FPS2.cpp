template<typename Mint>
struct fps2:FPS_BASE<Mint,fps2<Mint>>{
    using real=long double;
    struct complex_t{
        using C=complex_t;
        real re,im;
        C operator+(C x){return C(*this)+=x;}
        C operator*(C x){return C(*this)*=x;}
        C operator/(C x){return C(*this)/=x;}
        C operator-(C x){return C(*this)-=x;}
        C operator+=(C x){
            re+=x.re;im+=x.im;
            return *this;
        }
        C operator-=(C x){
            re-=x.re;im-=x.im;
            return *this;
        }
        C operator*=(C x){
            return *this=C{re*x.re-im*x.im,re*x.im+im*x.re};
        }
        C inv(){
            return C{re/(re*re+im*im),-im/(re*re+im*im)};
        }
        C conj(){
            return C{re,-im};
        }
        C operator/=(C x){
            return *this*=x.inv();
        }
        C mod(){
            return C{fmodl(re,Mint::get_mod()),fmodl(im,Mint::get_mod())};
        }
    };
    using C=complex_t;
    using FPS_BASE<Mint,fps2<Mint>>::FPS_BASE;
    using P=fps2<Mint>;
    P mul(P s,P t)override{
        lint n=s.size()+t.size()-1;
        P res(n);
        lint h=1;
        while((1<<h)<n)h++;
        vector<C>a(1<<h,C{0,0}),b(1<<h);
        for(int i=0;i<(int)s.size();i++)a[i].re=s[i].value();
        for(int i=0;i<(int)t.size();i++)a[i].im=t[i].value();
        fft(a,h,0);
        for(int i=0;i<1<<h;i++){
            int j=i==0?0:(1<<h)-i;
            b[i]=((a[i].mod()+a[j].mod().conj())*(a[i].mod()-a[j].mod().conj())*C{0,-.25}).mod();
        }
        fft(b,h,1);
        for(int i=0;i<n;i++){
            res[i]=fmodl(roundl(b[i].re),real(Mint::get_mod()));
        }
        return res;
    }
    void fft(vector<C>& v,const int& h,const bool& inv){
		int n=v.size(),mask=n-1;
		assert((n&(n-1))==0);
		vector<C> tmp(n);
        C* table=new C[n];
        table[0]=C{1,0};
        real theta =2*M_PI*(inv?-1:1)/n;
        for(int i=0;i<n;++i)table[i]=C{cos(i*theta),sin(i*theta)};
        for(int j=n>>1,t=h-1;j>=1;j>>=1,--t){
            for(int k=0;k<n;++k){
                int s=k&(j-1); // T は 下 t 桁
                int i=k>>t; // i は 上 h - t 桁
                tmp[k]=(v[((i<<(t+1))|s)&mask]+table[i*j]*v[((i<<(t+1))|j|s)&mask]).mod();
                // ζ_(2^(h - t))^i
            }
            swap(v,tmp);
        }
        if(inv)for(int i=0;i<n;++i)v[i].re/=n;
	}
};