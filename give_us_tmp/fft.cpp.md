---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u591A\u9805\u5F0F\u4E57\u7B97"
    links:
    - https://atcoder.jp/contests/atc001/submissions/17731754
    - https://atcoder.jp/contests/atc001/submissions/17731806
    - https://atcoder.jp/contests/atc001/tasks/fft_c
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
    - https://judge.yosupo.jp/submission/28246
  bundledCode: "#line 1 \"give_us_tmp/fft.cpp\"\n/**\n * \n * @brief \u591A\u9805\u5F0F\
    \u4E57\u7B97\n * \n * mul<double>:\n *  verifed with    :https://atcoder.jp/contests/atc001/tasks/fft_c\n\
    \ *  submittion      :https://atcoder.jp/contests/atc001/submissions/17731754\n\
    \ * mul<complex<double>>:\n *  verifed with    :https://atcoder.jp/contests/atc001/tasks/fft_c\n\
    \ *  submittion      :https://atcoder.jp/contests/atc001/submissions/17731806\n\
    \ * mul<modint<1000000007>>  :\n *  verifed with    :https://judge.yosupo.jp/problem/convolution_mod_1000000007\n\
    \ *  submittion      :https://judge.yosupo.jp/submission/28246\n */\n\nusing D=double;\n\
    const D PI=acos(D(-1));\nusing Pc=complex<D>;\n\nvoid fft(bool type,V<Pc>& a){\n\
    \    int n=a.size(),s=0;\n    while((1<<s)<n)s++;\n    assert((1<<s)==n);\n  \
    \  static V<Pc>ep[30];\n    if(!ep[s].size()){\n        rep(i,0,n){\n        \
    \    ep[s].push_back(polar<D>(1,i*2*PI/n));\n        }\n    }\n    V<Pc>b(n);\n\
    \    rep(i,1,s+1){\n        int w=1<<(s-i);\n        for(int y=0;y<n/2;y+=w){\n\
    \            Pc now=ep[s][y];\n            if(type)now=conj(now);\n          \
    \  rep(x,0,w){\n                auto l=a[y<<1|x];\n                auto u=now,v=a[y<<1|x|w];\n\
    \                auto r=u*v;\n                b[y|x]=l+r;\n                b[y|x|n>>1]=l-r;\n\
    \            }\n        }\n        swap(a,b);\n    }\n}\n\nV<D>mul(const V<D>&a,const\
    \ V<D>&b){\n    int s=a.size(),t=b.size(),lg=0;\n    if(!s||!t)return {};\n  \
    \  while((1<<lg)<s+t-1)lg++;\n    int n=1<<lg;\n    V<Pc>c(n);\n    rep(i,0,s)c[i].real(a[i]);\n\
    \    rep(i,0,t)c[i].imag(b[i]);\n    fft(false,c);\n    rep(i,0,n/2+1){\n    \
    \    const int j=i?n-i:0;\n        c[i]=(c[i]+conj(c[j]))*(c[i]-conj(c[j]))*Pc(0,-.25l);\n\
    \        if(i!=j)c[j]=conj(c[i]);\n    }\n    fft(true,c);\n    V<D>d(s+t-1);\n\
    \    rep(i,0,s+t-1){\n        d[i]=c[i].real()/D(n);\n    }\n    return d;\n}\n\
    \nV<Pc>mul(const V<Pc>&a,const V<Pc>&b){\n    int s=a.size(),t=b.size(),lg=0;\n\
    \    if(!s||!t)return {};\n    while((1<<lg)<s+t-1)lg++;\n    int n=1<<lg;\n \
    \   V<Pc>c(n),d(n);\n    rep(i,0,s)c[i]=a[i];\n    rep(i,0,t)d[i]=b[i];\n    fft(false,c);\n\
    \    fft(false,d);\n    rep(i,0,n){\n        c[i]*=d[i];\n    }\n    fft(true,c);\n\
    \    V<Pc>e(s+t-1);\n    rep(i,0,s+t-1){\n        d[i]=c[i]/Pc(n);\n    }\n  \
    \  return d;\n}\n\ntemplate <class Mint, int K = 3, int SHIFT = 11>\nV<Mint> mul(const\
    \ V<Mint>& a, const V<Mint>& b) {\n    int s=a.size(),t=b.size();\n    if (!s||!t)return\
    \ {};\n    int lg = 0;\n    while ((1<<lg)<s+t-1)lg++;\n    int n=1<<lg;\n   \
    \ V<V<Pc>>x(K,V<Pc>(n)),y(K,V<Pc>(n));\n    rep(ph,0,K){\n        V<Pc>z(n);\n\
    \        rep(i,0,n){\n            D nx=0,ny=0;\n            if(i<s)nx=(a[i].a>>(ph*SHIFT))&((1<<SHIFT)-1);\n\
    \            if(i<t)ny=(b[i].a>>(ph*SHIFT))&((1<<SHIFT)-1);\n            z[i]=Pc(nx,ny);\n\
    \        }\n        fft(false,z);\n        rep(i,0,n){\n            z[i]*=0.5;\n\
    \        }\n        rep(i,0,n){\n            int j=i?n-i:0;\n            x[ph][i]=Pc(z[i].real()+z[j].real(),z[i].imag()-z[j].imag());\n\
    \            y[ph][i]=Pc(z[i].imag()+z[j].imag(),-z[i].real()+z[j].real());\n\
    \        }\n    }\n    V<V<Pc>>z(K,V<Pc>(n));\n    rep(xp,0,K)rep(yp,0,K){\n \
    \       int zp=(xp+yp)%K;\n        rep(i,0,n){\n            if(xp+yp<K)z[zp][i]+=x[xp][i]*y[yp][i];\n\
    \            else z[zp][i]+=x[xp][i]*y[yp][i]*Pc(0,1);\n        }\n    }\n   \
    \ rep(ph,0,K){\n        fft(true,z[ph]);\n    }\n    V<Mint>c(s+t-1);\n    Mint\
    \ base=1;\n    rep(ph,0,2*K-1){\n        rep(i,0,s+t-1){\n            if(ph<K){\n\
    \                c[i]+=Mint(ll(round(z[ph][i].real()/n)))*base;\n            }else{\n\
    \                c[i]+=Mint(ll(round(z[ph-K][i].imag()/n)))*base;\n          \
    \  }\n        }\n        base*=1<<SHIFT;\n    }\n    return c;\n}\n"
  code: "/**\n * \n * @brief \u591A\u9805\u5F0F\u4E57\u7B97\n * \n * mul<double>:\n\
    \ *  verifed with    :https://atcoder.jp/contests/atc001/tasks/fft_c\n *  submittion\
    \      :https://atcoder.jp/contests/atc001/submissions/17731754\n * mul<complex<double>>:\n\
    \ *  verifed with    :https://atcoder.jp/contests/atc001/tasks/fft_c\n *  submittion\
    \      :https://atcoder.jp/contests/atc001/submissions/17731806\n * mul<modint<1000000007>>\
    \  :\n *  verifed with    :https://judge.yosupo.jp/problem/convolution_mod_1000000007\n\
    \ *  submittion      :https://judge.yosupo.jp/submission/28246\n */\n\nusing D=double;\n\
    const D PI=acos(D(-1));\nusing Pc=complex<D>;\n\nvoid fft(bool type,V<Pc>& a){\n\
    \    int n=a.size(),s=0;\n    while((1<<s)<n)s++;\n    assert((1<<s)==n);\n  \
    \  static V<Pc>ep[30];\n    if(!ep[s].size()){\n        rep(i,0,n){\n        \
    \    ep[s].push_back(polar<D>(1,i*2*PI/n));\n        }\n    }\n    V<Pc>b(n);\n\
    \    rep(i,1,s+1){\n        int w=1<<(s-i);\n        for(int y=0;y<n/2;y+=w){\n\
    \            Pc now=ep[s][y];\n            if(type)now=conj(now);\n          \
    \  rep(x,0,w){\n                auto l=a[y<<1|x];\n                auto u=now,v=a[y<<1|x|w];\n\
    \                auto r=u*v;\n                b[y|x]=l+r;\n                b[y|x|n>>1]=l-r;\n\
    \            }\n        }\n        swap(a,b);\n    }\n}\n\nV<D>mul(const V<D>&a,const\
    \ V<D>&b){\n    int s=a.size(),t=b.size(),lg=0;\n    if(!s||!t)return {};\n  \
    \  while((1<<lg)<s+t-1)lg++;\n    int n=1<<lg;\n    V<Pc>c(n);\n    rep(i,0,s)c[i].real(a[i]);\n\
    \    rep(i,0,t)c[i].imag(b[i]);\n    fft(false,c);\n    rep(i,0,n/2+1){\n    \
    \    const int j=i?n-i:0;\n        c[i]=(c[i]+conj(c[j]))*(c[i]-conj(c[j]))*Pc(0,-.25l);\n\
    \        if(i!=j)c[j]=conj(c[i]);\n    }\n    fft(true,c);\n    V<D>d(s+t-1);\n\
    \    rep(i,0,s+t-1){\n        d[i]=c[i].real()/D(n);\n    }\n    return d;\n}\n\
    \nV<Pc>mul(const V<Pc>&a,const V<Pc>&b){\n    int s=a.size(),t=b.size(),lg=0;\n\
    \    if(!s||!t)return {};\n    while((1<<lg)<s+t-1)lg++;\n    int n=1<<lg;\n \
    \   V<Pc>c(n),d(n);\n    rep(i,0,s)c[i]=a[i];\n    rep(i,0,t)d[i]=b[i];\n    fft(false,c);\n\
    \    fft(false,d);\n    rep(i,0,n){\n        c[i]*=d[i];\n    }\n    fft(true,c);\n\
    \    V<Pc>e(s+t-1);\n    rep(i,0,s+t-1){\n        d[i]=c[i]/Pc(n);\n    }\n  \
    \  return d;\n}\n\ntemplate <class Mint, int K = 3, int SHIFT = 11>\nV<Mint> mul(const\
    \ V<Mint>& a, const V<Mint>& b) {\n    int s=a.size(),t=b.size();\n    if (!s||!t)return\
    \ {};\n    int lg = 0;\n    while ((1<<lg)<s+t-1)lg++;\n    int n=1<<lg;\n   \
    \ V<V<Pc>>x(K,V<Pc>(n)),y(K,V<Pc>(n));\n    rep(ph,0,K){\n        V<Pc>z(n);\n\
    \        rep(i,0,n){\n            D nx=0,ny=0;\n            if(i<s)nx=(a[i].a>>(ph*SHIFT))&((1<<SHIFT)-1);\n\
    \            if(i<t)ny=(b[i].a>>(ph*SHIFT))&((1<<SHIFT)-1);\n            z[i]=Pc(nx,ny);\n\
    \        }\n        fft(false,z);\n        rep(i,0,n){\n            z[i]*=0.5;\n\
    \        }\n        rep(i,0,n){\n            int j=i?n-i:0;\n            x[ph][i]=Pc(z[i].real()+z[j].real(),z[i].imag()-z[j].imag());\n\
    \            y[ph][i]=Pc(z[i].imag()+z[j].imag(),-z[i].real()+z[j].real());\n\
    \        }\n    }\n    V<V<Pc>>z(K,V<Pc>(n));\n    rep(xp,0,K)rep(yp,0,K){\n \
    \       int zp=(xp+yp)%K;\n        rep(i,0,n){\n            if(xp+yp<K)z[zp][i]+=x[xp][i]*y[yp][i];\n\
    \            else z[zp][i]+=x[xp][i]*y[yp][i]*Pc(0,1);\n        }\n    }\n   \
    \ rep(ph,0,K){\n        fft(true,z[ph]);\n    }\n    V<Mint>c(s+t-1);\n    Mint\
    \ base=1;\n    rep(ph,0,2*K-1){\n        rep(i,0,s+t-1){\n            if(ph<K){\n\
    \                c[i]+=Mint(ll(round(z[ph][i].real()/n)))*base;\n            }else{\n\
    \                c[i]+=Mint(ll(round(z[ph-K][i].imag()/n)))*base;\n          \
    \  }\n        }\n        base*=1<<SHIFT;\n    }\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: give_us_tmp/fft.cpp
  requiredBy: []
  timestamp: '2020-10-31 15:42:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: give_us_tmp/fft.cpp
layout: document
redirect_from:
- /library/give_us_tmp/fft.cpp
- /library/give_us_tmp/fft.cpp.html
title: "\u591A\u9805\u5F0F\u4E57\u7B97"
---
