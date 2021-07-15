lint* m=new lint[10000000]();
map<lint,mint> m2;
mint totient_sum(lint n){
    static bool init=1;
    if(init){
        init=0;
        lint k=1e7;
        for(lint i=1;i<=k;i++)m[i]=i;
        for(lint i=1;i<=k;i++)for(lint j=i*2;j<=k;j+=i)m[j]-=m[i];
        for(lint i=1;i<k;i++)m[i+1]+=m[i];
    }
    if(n<1e7)return m[n];
    else if(m2.count(n))return m2[n];
    mint ans=mint(n)*(n+1)/2;
    lint mx=0;
    for(lint i=1;i*i<n;i++){
        ans-=mint(n/i-n/(i+1))*totient_sum(i);
        mx=n/(i+1)+1;
    }
    for(lint i=2;i<mx;i++){
        ans-=totient_sum(n/i);
    }
    return m2[n]=ans;
}