template<typename T>
struct Dirichlet{
    using P=Dirichlet<T>;
    static long long N,K,L;
    std::vector<T>a,A;
    Dirichlet():a(K+1),A(L+1){}
    P& operator+=(const P& x){
        for(int i=1;i<=K;++i)a[i]+=x.a[i];
        for(int i=1;i<=L;++i)A[i]+=x.A[i];
    }
    P& operator-=(const P& x){
        for(int i=1;i<=K;++i)a[i]-=x.a[i];
        for(int i=1;i<=L;++i)A[i]-=x.A[i];
    }
    P& operator*=(const P& x){
        P res;
        for(int i=1;i<=K;++i){
            for(int j=1;i*j<=K;++j){
                res.a[i*j]+=a[i]*x.a[j];
            }
        }
        std::vector<T>sum_a=a,sum_b=x.a;
        for(int i=1;i<=K;++i){
            sum_a[i]+=sum_a[i-1];
            sum_b[i]+=sum_b[i-1];
        }
        auto getA=[&](long long n){return (n<=K?sum_a[n]:A[N/n]);};
        auto getB=[&](long long n){return (n<=K?sum_b[n]:x.A[N/n]);};
        for(int i=1;i<=L;++i){
            const long long n=N/i,m=std::floor(std::sqrt(n));
            for(int j=1;j<=m;++j){
                res.A[i]+=a[j]*getB(n/j);
                res.A[i]+=x.a[j]*(getA(n/j)-getA(m));
            }
        }
        return (*this)=res;
    }
    P& operator/=(const P& x){
        assert(x.a[1]!=T());
        //(*this)=x*res;
        P res(*this);
        for(int i=1;i<=K;++i){
            for(int j=2;i*j<=K;++j){
                res.a[i*j]-=res.a[i]*x.a[j];
            }
            res.a[i]/=x.a[1];
        }
        std::vector<T>sum_a=x.a,sum_b=res.a;
        for(int i=1;i<=K;++i){
            sum_a[i]+=sum_a[i-1];
            sum_b[i]+=sum_b[i-1];
        }
        auto getA=[&](long long n){return (n<=K?sum_a[n]:x.A[N/n]);};
        auto getB=[&](long long n){return (n<=K?sum_b[n]:res.A[N/n]);};
        for(int i=L;i>=1;--i){
            const long long n=N/i,m=std::floor(std::sqrt(n));
            for(int j=1;j<=m;++j){
                if(j!=1)res.A[i]-=x.a[j]*getB(n/j);
                res.A[i]-=res.a[j]*(getA(n/j)-getA(m));
            }
            res.A[i]/=x.a[1];
        }
        return (*this)=res;
    }
    P operator*=(const T&x){
        for(int i=1;i<=K;++i){
            a[i]*=x;
        }
        for(int i=1;i<=L;++i){
            A[i]*=x;
        }
        return *this;
    }
    P operator+(const P&x)const{return P(*this)+=x;}
    P operator-(const P&x)const{return P(*this)-=x;}
    P operator*(const P&x)const{return P(*this)*=x;}
    P operator/(const P&x)const{return P(*this)/=x;}
    P inv()const{return ident()/=(*this);}
    T get(){return A[1];}
    P pow(long long x){
        P res=ident();
        P tmp(*this);
        while(x){
            if(x%2)res*=tmp;
            tmp*=tmp;
            x/=2;
        }
        return res;
    }
    void clear(){a.clear();A.clear();}
    template<typename F,typename G>
    static P make(F f,G g){
        P res;
        for(int i=1;i<=K;++i)res.a[i]=f(i);
        for(int i=1;i<=L;++i)res.A[i]=g(N/i);
        return res;
    }
    static P ident(){
        P res;
        res.a[1]=1;
        res.A.assign(L+1,1);
        return res;
    }

    //ζ(s-k)
    static P zeta_shift(int k){
        P res;
        std::vector<T>tmp(k+2),fact(k+2,1),fact_inv(k+2,1);
        for(int i=1;i<=k+1;++i)tmp[i]=tmp[i-1]+T(i).pow(k);
        for(int i=1;i<=k+1;++i)fact[i]=fact[i-1]*i;
        fact_inv[k+1]=T(1)/fact[k+1];
        for(int i=k;i>=0;--i)fact_inv[i]=fact_inv[i+1]*T(i+1);

        for(int i=1;i<=K;++i)res.a[i]=T(i).pow(k);
        auto get=[&](long long n){
            if(n<=k+1)return tmp[n];
            T tmp2=1,res=0;
            for(int i=0;i<=k+1;++i)tmp2*=T(n-i);
            if(tmp2==T()){
                for(int i=0;i<=k+1;++i){
                    T tmp3=1;
                    if(T(n-i)==T()){
                        for(int j=0;j<=k+1;++j){
                            if(i!=j)tmp3*=T(n-i);
                        }
                    }
                    res+=tmp[i]*fact_inv[i]*fact_inv[k+1-i]*tmp3*((k+1-i)%2?T(-1):T(1));
                }
            }else{
                for(int i=0;i<=k+1;++i){
                    res+=tmp[i]*fact_inv[i]*fact_inv[k+1-i]*tmp2/T(n-i)*((k+1-i)%2?T(-1):T(1));
                }
            }
            return res;
        };
        for(int i=1;i<=L;++i){
            res.A[i]=get(N/i);
        }
        return res;
    }
    //ζ(s)
    static P zeta(){
        P res;
        res.a.assign(K+1,1);
        res.a[0]=0;
        for(int i=1;i<=L;++i)res.A[i]=N/i;
        return res;
    }
    //μ(s)=1/ζ(s)
    static P mebius(){return zeta().inv();}
    //σ_k(s)=ζ(s)ζ(s-k)
    static P divisor(int k){
        return zeta()*zeta_shift(k);
    }
    //φ(s)=ζ(s-1)/ζ(s)
    static P euler(){
        return zeta_shift(1)/zeta();
    }
    static void resize(long long n){
        N=n;
        K=std::ceil(std::cbrt(n)*std::cbrt(n));
        L=std::ceil(std::cbrt(n));
    }
    static long long size(){return N;}
};
template<typename T>long long Dirichlet<T>::N=0;
template<typename T>long long Dirichlet<T>::K=0;
template<typename T>long long Dirichlet<T>::L=0;

// template<typename T,typename F,typename G,typename SF,typename SG>
// T Dirichlet_mul(long long n,F f,G g,SF sf,SG sg){
//     T res=0;
//     int m=std::floor(std::sqrt(n));
//     for(int i=1;i<=m;++i){
//         res+=f(i)*sg(n/i%mod);
//         res%=mod;
//         res+=g(i)*(sf(n/i%mod)-sf(m%mod));
//         res%=mod;
//     }
//     return res;
// }