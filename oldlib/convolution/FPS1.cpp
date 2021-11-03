template<typename Mint>
struct _FPS1{
    using u64=uint64_t;
    using lint=int64_t;
    u64 mod_pow(u64 x,u64 y,u64 mod){
        u64 ret=1;
        while(y>0) {
            if(y&1)(ret*=x)%=mod;
            (x*=x)%=mod;
            y>>=1;
        }
        return ret;
    }
    auto ntt(vector<u64> v,const int& h,const bool& inv,u64 mod,u64 _root){
        const int n=v.size();
        assert(mod>=3&&mod%2==1);
        vector<u64> tmp(n,0);
        u64 root=inv?mod_pow(_root,mod-2,mod):_root;
        for(int b=n>>1;b>=1;b>>=1,v.swap(tmp)){
            u64 w=mod_pow(root,(mod-1)/(n/b),mod),p=1;
            for(int i=0;i<n;i+=b*2,(p*=w)%=mod)for(int j=0;j<b;++j){
                (v[i+j+b]*=p)%=mod;
                tmp[i/2+j]=(v[i+j]+v[i+b+j])%mod;
                tmp[n/2+i/2+j]=(v[i+j]-v[i+b+j]+mod)%mod;
            }
        }
        u64 inv_n=mod_pow(n,mod-2,mod);
        if(inv){
            for(int i=0;i<n;++i)(v[i]*=inv_n)%=mod;
        }
        return v;
    }
    vector<u64> mods={1224736769,1045430273,1007681537};
    vector<u64> root={3,3,3};
    auto operator()(auto s,auto t)->decltype(s){
        const int n=s.size()+t.size()-1;
        int h=1;
        while((1<<h)<n)h++;
        vector<vector<u64>>a(3,vector<u64>(1<<h,0)),b(3,vector<u64>(1<<h,0));
        for(int j=0;j<3;j++)for(int i=0;i<(int)s.size();++i)a[j][i]=s[i].a;
        for(int j=0;j<3;j++)for(int i=0;i<(int)t.size();++i)b[j][i]=t[i].a;
        for(int i=0;i<3;i++){
            a[i]=ntt(a[i],h,0,mods[i],root[i]);
            b[i]=ntt(b[i],h,0,mods[i],root[i]);
            for(int j=0;j<(1<<h);++j)a[i][j]*=b[i][j];
            a[i]=ntt(a[i],h,1,mods[i],root[i]);
        }
        decltype(s) v(n);
        mods.push_back(Mint::get_mod());
        for(int i=0;i<n;++i){
            vector<int64_t>tmp(3);
            for(int j=0;j<3;j++){
                tmp[j]=a[j][i];
            }
            v[i]=garner(tmp);
        }
        return v;
    }
    constexpr u64 garner(vector<int64_t>a){
        const int sz=3;
        int64_t coeffs[sz+1]={1,1,1,1};
        int64_t constants[sz+1]={};
        for(int i=0;i<sz;i++){
            int64_t v=(mods[i]+int64_t(a[i])-constants[i])%mods[i]*mod_pow(coeffs[i],mods[i]-2,mods[i])%mods[i];
            for(int j=i+1;j<sz+1;j++) {
                constants[j]=(constants[j]+coeffs[j]*v)%mods[j];
                coeffs[j]=(coeffs[j]*mods[i])%mods[j];
            }
        }
        return u64(constants[3]);
    }
};
template<typename Mint>using fps=FPS_BASE<Mint,_FPS1<Mint>>;