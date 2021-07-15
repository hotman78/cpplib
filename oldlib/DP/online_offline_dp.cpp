//monotone_minimaを要求
//dp[j]=min(dp[i]+f(i,j))をO(N(logN)^2)で解く
template<typename T>
vector<T> online_offline_dp(int r,T inf,T zero,auto f){
    vector<T>ret(r,inf);
    ret[0]=zero;
    auto h=[&](auto h,int l,int r,T inf,auto f)->void{
        if(l==r-1)return;
        int m=(l+r)/2;
        h(h,l,m,inf,f);
        auto g=[&](int j,int i){
            return ret[i+l]+f(i+l,j+m);
        };
        vector<int>d=monotone_minima(r-m,m-l,inf,g);
        for(int i=m;i<r;++i){
            if(ret[i]>g(i-m,d[i-m]))ret[i]=g(i-m,d[i-m]);
        }
        h(h,m,r,inf,f);
    };
    h(h,0,r,inf,f);
    return ret;
}