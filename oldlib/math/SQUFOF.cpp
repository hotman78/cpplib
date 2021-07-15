lint __prime_factor(__int128_t N,__int128_t m){
    N*=m;
    __int128_t q0=sqrt(N);
    __int128_t P=q0;
    __int128_t pQ=1;
    __int128_t Q=N-q0*q0;
    if(Q==0)return P;
    while(1){
        __int128_t tmp2=P,tmp3=Q,q=(q0+P)/Q;
        P=q*Q-P;
        Q=pQ+q*(tmp2-P);
        pQ=tmp3;
        if(P==tmp2)return pQ/__gcd(pQ,2*m);
    }
}
void prime_factor(__int128_t N,map<lint,lint>& m){
    vector<int>v={3,5,7,11};
    while(is_prime(N)){
        for(int i=0;i<16;i++){
            lint tmp=1;
            for(int j=0;j<4;j++){
                if(i&1<<j)tmp*=v[j];
            }
            auto d=__prime_factor(N,tmp);
            if(d!=1){
                prime_factor(d,m);
                prime_factor(N/d,m);
                return;
            }
        }
    }
    m[N]++;
}