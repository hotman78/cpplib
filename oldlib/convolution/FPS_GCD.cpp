template <class T>
struct fps_gcd:FPS_BASE<T,fps_gcd<T>>{
    using FPS_BASE<T,fps_gcd<T>>::FPS_BASE;
    using P=fps_gcd<T>;
    P mul(P s,P t)override{
        int n=max(s.size(),t.size());
        s.resize(n,T(0));
        t.resize(n,T(0));
        ddt(s);ddt(t);
        auto res=s.dot(t);
        iddt(res);
        return res;
    }
    void ddt(P& a) {
        int n = a.size();
        vector<bool> sieve(n, true);
        for(int p=2;p<n;++p) {
            if(sieve[p]){
                for(int k=2;k*p<n;++k){
                    sieve[k*p]=false;
                }
                for(int k=(n-1)/p;k>0;--k){
                    a[k]+=a[k*p];
                }
            }
        }
    }
    void iddt(P& a) {
        int n = a.size();
        vector<bool>sieve(n,true);
        for(int p=2;p<n;++p) {
            if(sieve[p]){
                for(int k=2;k*p<n;++k){
                    sieve[k*p]=false;
                }
                for(int k=1;k*p<n;++k){
                    a[k]-=a[k*p];
                }
            }
        }
    }
};