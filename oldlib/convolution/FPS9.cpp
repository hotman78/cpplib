template<typename Mint>
struct _FPS9{
    auto operator()(auto s,auto t)->decltype(s){
        if(s==decltype(s)())return decltype(s)();
        if(t==decltype(t)())return decltype(t)();
        auto ntt=[](auto v,const bool& inv){
            const int n=v.size();
            assert(Mint::get_mod()>=3&&Mint::get_mod()%2==1);
            decltype(v) tmp(n,Mint());
            Mint root=inv?Mint(Mint::root()).inv():Mint::root();
            for(int b=n>>1;b>=1;b>>=1,v.swap(tmp)){
                Mint w=root.pow((Mint::get_mod()-1)/(n/b)),p=1;
                for(int i=0;i<n;i+=b*2,p*=w)for(int j=0;j<b;++j){
                    v[i+j+b]*=p;
                    tmp[i/2+j]=v[i+j]+v[i+b+j];
                    tmp[n/2+i/2+j]=v[i+j]-v[i+b+j];
                }
            }
            if(inv)v/=n;
            return v;
        };
        const int n=s.size()+t.size()-1;
        int h=1;
        while((1<<h)<n)h++;
        s.resize((1<<h),Mint(0));
        t.resize((1<<h),Mint(0));
        return ntt(ntt(s,0).dot(ntt(t,0)),1).pre(n);
    }
};
template<typename Mint>using fps=FPS_BASE<Mint,_FPS9<Mint>>;