/**
 * @brief 素数判定(高速)
 * 
 * verified with    :https://judge.yosupo.jp/problem/factorize
 * submission       :https://judge.yosupo.jp/submission/28308
 */
bool is_prime(ll n){
    if(n<=1)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    ll s=0,d=n-1;
    while(d%2)d/=2,s++;
    auto mod_pow=[](__int128_t a,__int128_t b,__int128_t n){
        ll res=1;
        while(b){
            if(b%2)res=res*a%n;
            a=a*a%n;
            b/=2;
        }
        return (ll)(res);
    };
    for(ll e:{2,3,5,7,11,13,17,19,23,29,31,37}){
        if(n<=e)break;
        if(mod_pow(e,d,n)==1)continue;
        bool b=1;
        for(int i=0;i<s;i++){
            if(mod_pow(e,d<<i,n)==n-1)b=0;
        }
        if(b)return 0;
    }
    return 1;
}