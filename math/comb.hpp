template<int mod>
long long comb(long long a, long long b){
    static bool init=1;
    static long long fac[1000001],ifac[1000001];
    if(init){
        init=0;
        fac[0]=1;
        ifac[0]=1;
        auto mod_pow=[&](lint x,lint n){
            lint ans = 1;
            while(n != 0){
                if(n&1)ans=ans*x%mod;
                x=x*x%mod;
                n=n>>1;
            }
            return ans;
        };
        for(int i=0;i<1000000;i++){
            fac[i+1]=fac[i]*(i+1)%mod;
            ifac[i+1]=ifac[i]*mod_pow(i+1, MOD-2)%mod;
        }
    }
    if(a==0&&b==0)return 1;
    if(a<b||a<0)return 0;
    long long tmp=ifac[a-b]*ifac[b]%mod;
    return tmp*fac[a]%mod;
}