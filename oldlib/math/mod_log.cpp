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

lint mod_log(lint x,lint y,lint m){
    if(1==y||(x==0&&y==0&&m==1))return 0;
    if(x==0){
        if(y==1)return 0;
        if(y==0)return 1;
        else return -1;
    }
    lint _x=x,_y=y;
    lint g=m;
    lint cnt=0;
    while(gcd(x,m)!=1)m/=gcd(x,m),cnt++;
    g/=m;
    x%=m;
    y%=m;
    map<lint,lint>b;
    lint B=sqrt(m*g)+1;
    lint phi=euler_phi(m);
    lint a=mod_pow(x,B-1,m);
    lint inv_x=mod_pow(x,phi-1,m);
    rrepi(i,cnt,B){
        b[a]=i;
        a=a*inv_x%m;
    }
    lint A=mod_pow(x,B*(phi-1),m);
    lint A2=y;
    rep(i,B){
        rep(j,cnt)if(mod_pow(_x,i*B+j,m*g)==_y)return i*B+j;
        if(b.count(A2)){
            if(mod_pow(_x,i*B+b[A2],m*g)==_y)return i*B+b[A2];
        }
        A2=A2*A%m;
    }
    return -1;
}