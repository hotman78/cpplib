int64_t mod_sqrt(int64_t a,int64_t mod){
    auto mod_pow=[](int64_t a,int64_t b,int64_t mod){
        int64_t res=1;
        while(b){
            if(b%2)(res*=a)%=mod;
            (a*=a)%=mod;
            b/=2;
        }
        return res;
    };
    if(mod==2||a==0)return a;
    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;
    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);
    int64_t q=(mod-1),s=0;
    while(q%2==0)q/=2,s++;
    int64_t z=1;
    random_device rnd;
    while(mod_pow(z=rnd()%mod,(mod-1)/2,mod)!=mod-1);
    int64_t c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;
    while(m>1){
        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;
        else tie(c,t,r,m)=make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);
    }
    return r%mod;
}

int64_t kth_root(int64_t a,int64_t n,int64_t p){
    random_device rnd;
    auto mod_pow=[](int64_t a,int64_t b,int64_t mod){
        a%=mod;
        b%=mod-1;
        int64_t res=1;
        while(b){
            if(b%2)(res*=a)%=mod;
            (a*=a)%=mod;
            b/=2;
        }
        return res;
    };
    auto int_pow=[](int64_t a,int64_t b){
        int64_t res=1;
        while(b){
            if(b%2)res*=a;
            a*=a;
            b/=2;
        }
        return res;
    };
    auto mod_inv=[](int64_t a, int64_t mod){
        int64_t b=mod,s=1,u=0;
        while (b) {
            int64_t q=a/b;
            swap(b,a%=b);
            swap(s-=q*u,u);
        }
        if(a!=1) assert(0);
        return s<0?s+mod:s;
    };
    //aのp乗根
    auto pth_root=[&](int64_t a,int64_t p,int64_t mod)->int64_t{
        int64_t q=mod-1,s=0;
        while(q%p==0)q/=p,s++;
        if(s<=1)return 1;
        int64_t z;
        while(mod_pow(z=rnd()%mod,(mod-1)/p,mod)==1);
        int64_t m=s;
        int64_t c=mod_pow(z,q,mod);
        int64_t r=mod_pow(a,(q+1)/2,mod);
        int64_t t=mod_pow(r,p,mod)*mod_inv(a,mod)%mod;
        while(m>1){
            while(mod_pow(t,int_pow(p,m-2),mod)!=1){
                t=t*mod_pow(c,p,mod)%mod;
                r=r*c%mod;
            }
            c=mod_pow(c,p,mod);
            m--;
        };
        cerr<<"   "<<mod_pow(t,int_pow(p,m-2),mod)<<endl;
        assert(mod_pow(r,p,mod)==a*t%mod);
        return r;
    };
    a%=p;n%=p-1;
    if(a<=1)return a;
    int64_t g=gcd(p-1,n);
    if(mod_pow(a,(p-1)/g,p)!=1)return -1;
    a=mod_pow(a,mod_inv(n/g,(p-1)/g),p);
    for(int i=2;i*i<=n;++i){
        while(n%i==0)n/=i,a=pth_root(a,i,p);
    }
    a=pth_root(a,n,p);
    return a;
}
