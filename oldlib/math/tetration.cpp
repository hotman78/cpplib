lint mod_pow(lint x,lint y,lint mod){
    lint ret=1%mod;
    while(y) {
        if(y%2)ret=ret*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ret;
}

int64_t euler_phi(int64_t n) {
    int64_t ret = n;
    for(int64_t i=2;i*i<=n;i++) {
        if(n%i==0) {
            ret-=ret/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ret-=ret/n;
    return ret;
}

lint tetration(lint a,lint b,lint m){
    vec v;
    lint d=m;
    while(d!=1){
        v.push_back(d);
        d=euler_phi(d);
    }
    v.push_back(1);
    if(a==0)return (b+1)%2%m;
    if(m==1)return 0;
    if(a==1||b==0){
        return 1;
    }
    if(lint(v.size())>=b)v.resize(b-1,1);
    reverse(all(v));
    lint ans=a;
    for(auto e:v){
        lint ad=(ans<=32&&a<e&&pow((double)a,ans)<e?0:e);
        ans=mod_pow(a%e,ans,e)+ad;
    }
    return ans%m;
}