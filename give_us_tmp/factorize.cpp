/**
 * @brief 素因数分解(高速)
 * 
 * verified with    :https://judge.yosupo.jp/problem/factorize
 * submission       :https://judge.yosupo.jp/submission/28308
 */

void __factorize(ll n,ll& c,V<ll>& v){
    if(n==1)return;
    if(n%2==0){
        v.emplace_back(2);
        __factorize(n/2,c,v);
        return;
    }
    if(is_prime(n)){
        v.emplace_back(n);
        return;
    }
    while(1){
        long long x=2,y=2,d=1;
        while(d==1){
            x=((__int128_t)x*x+c)%n;
            y=((__int128_t)y*y%n+c)%n;
            y=((__int128_t)y*y%n+c)%n;
            d=std::gcd(std::abs(x-y),n);
        }
        if(d==n){
            c++;
            continue;
        }
        __factorize(d,c,v);
        __factorize(n/d,c,v);
        return;
    }
}

map<ll,ll> factorize(ll n){
    V<ll>v;
    ll c=1;
    __factorize(n,c,v);
    map<ll,ll>m;
    for(auto e:v){
        m[e]++;
    }
    return m;
}