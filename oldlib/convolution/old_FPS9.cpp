template<typename Mint>
struct fps9:FPS_BASE<Mint,fps9<Mint>>{
    using FPS_BASE<Mint,fps9<Mint>>::FPS_BASE;
    using P=fps9<Mint>;
    P mul(P s,P t)override{
        const int n=s.size()+t.size()-1;
        int h=1;
        while((1<<h)<n)h++;
        s.resize((1<<h),Mint(0));
        t.resize((1<<h),Mint(0));
        return ntt(ntt(s,h,0).dot(ntt(t,h,0)),h,1).pre(n);
    }
    P ntt(P v,const int& h,const bool& inv){
		const int n=v.size();
        assert(Mint::get_mod()>=3&&Mint::get_mod()%2==1);
		P tmp(n,Mint());
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
	}
};
