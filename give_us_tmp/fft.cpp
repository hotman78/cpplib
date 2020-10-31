/**
 * 
 * @brief 多項式乗算
 * 
 * mul<double>:
 *  verifed with    :https://atcoder.jp/contests/atc001/tasks/fft_c
 *  submittion      :https://atcoder.jp/contests/atc001/submissions/17731754
 * mul<complex<double>>:
 *  verifed with    :https://atcoder.jp/contests/atc001/tasks/fft_c
 *  submittion      :https://atcoder.jp/contests/atc001/submissions/17731806
 * mul<modint<1000000007>>  :
 *  verifed with    :https://judge.yosupo.jp/problem/convolution_mod_1000000007
 *  submittion      :https://judge.yosupo.jp/submission/28246
 */

using D=double;
const D PI=acos(D(-1));
using Pc=complex<D>;

void fft(bool type,V<Pc>& a){
    int n=a.size(),s=0;
    while((1<<s)<n)s++;
    assert((1<<s)==n);
    static V<Pc>ep[30];
    if(!ep[s].size()){
        rep(i,0,n){
            ep[s].push_back(polar<D>(1,i*2*PI/n));
        }
    }
    V<Pc>b(n);
    rep(i,1,s+1){
        int w=1<<(s-i);
        for(int y=0;y<n/2;y+=w){
            Pc now=ep[s][y];
            if(type)now=conj(now);
            rep(x,0,w){
                auto l=a[y<<1|x];
                auto u=now,v=a[y<<1|x|w];
                auto r=u*v;
                b[y|x]=l+r;
                b[y|x|n>>1]=l-r;
            }
        }
        swap(a,b);
    }
}

V<D>mul(const V<D>&a,const V<D>&b){
    int s=a.size(),t=b.size(),lg=0;
    if(!s||!t)return {};
    while((1<<lg)<s+t-1)lg++;
    int n=1<<lg;
    V<Pc>c(n);
    rep(i,0,s)c[i].real(a[i]);
    rep(i,0,t)c[i].imag(b[i]);
    fft(false,c);
    rep(i,0,n/2+1){
        const int j=i?n-i:0;
        c[i]=(c[i]+conj(c[j]))*(c[i]-conj(c[j]))*Pc(0,-.25l);
        if(i!=j)c[j]=conj(c[i]);
    }
    fft(true,c);
    V<D>d(s+t-1);
    rep(i,0,s+t-1){
        d[i]=c[i].real()/D(n);
    }
    return d;
}

V<Pc>mul(const V<Pc>&a,const V<Pc>&b){
    int s=a.size(),t=b.size(),lg=0;
    if(!s||!t)return {};
    while((1<<lg)<s+t-1)lg++;
    int n=1<<lg;
    V<Pc>c(n),d(n);
    rep(i,0,s)c[i]=a[i];
    rep(i,0,t)d[i]=b[i];
    fft(false,c);
    fft(false,d);
    rep(i,0,n){
        c[i]*=d[i];
    }
    fft(true,c);
    V<Pc>e(s+t-1);
    rep(i,0,s+t-1){
        d[i]=c[i]/Pc(n);
    }
    return d;
}

template <class Mint, int K = 3, int SHIFT = 11>
V<Mint> mul(const V<Mint>& a, const V<Mint>& b) {
    int s=a.size(),t=b.size();
    if (!s||!t)return {};
    int lg = 0;
    while ((1<<lg)<s+t-1)lg++;
    int n=1<<lg;
    V<V<Pc>>x(K,V<Pc>(n)),y(K,V<Pc>(n));
    rep(ph,0,K){
        V<Pc>z(n);
        rep(i,0,n){
            D nx=0,ny=0;
            if(i<s)nx=(a[i].a>>(ph*SHIFT))&((1<<SHIFT)-1);
            if(i<t)ny=(b[i].a>>(ph*SHIFT))&((1<<SHIFT)-1);
            z[i]=Pc(nx,ny);
        }
        fft(false,z);
        rep(i,0,n){
            z[i]*=0.5;
        }
        rep(i,0,n){
            int j=i?n-i:0;
            x[ph][i]=Pc(z[i].real()+z[j].real(),z[i].imag()-z[j].imag());
            y[ph][i]=Pc(z[i].imag()+z[j].imag(),-z[i].real()+z[j].real());
        }
    }
    V<V<Pc>>z(K,V<Pc>(n));
    rep(xp,0,K)rep(yp,0,K){
        int zp=(xp+yp)%K;
        rep(i,0,n){
            if(xp+yp<K)z[zp][i]+=x[xp][i]*y[yp][i];
            else z[zp][i]+=x[xp][i]*y[yp][i]*Pc(0,1);
        }
    }
    rep(ph,0,K){
        fft(true,z[ph]);
    }
    V<Mint>c(s+t-1);
    Mint base=1;
    rep(ph,0,2*K-1){
        rep(i,0,s+t-1){
            if(ph<K){
                c[i]+=Mint(ll(round(z[ph][i].real()/n)))*base;
            }else{
                c[i]+=Mint(ll(round(z[ph-K][i].imag()/n)))*base;
            }
        }
        base*=1<<SHIFT;
    }
    return c;
}