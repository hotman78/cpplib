#pragma once
#include"FPS_mint.hpp"
#include"mod_int_dynamic.hpp"

template<typename mint>
int kth_root(int n,int k){
    if(k==0){
        if(n==1)return 0;
        else return -1;
    }
    fps<mint>f(k+1,0);
    f[k]=1;
    f[0]=-n;
    random_device rnd;
    for(int times=0;times<10;++times){
        if(f.size()<=2){
            f.resize(k+1);
            f[k]=1;
            f[0]=-n;
        }
        fps<mint>g(k,0),h={1};
        for(int i=0;i<k;++i)g[i]=rnd();
        int t=(mint::get_mod()-1)/2;
        while(t){
            if(t%2)h*=g,h%=f,h.shrink();
            g*=g;
            g%=f;
            g.shrink();
            t/=2;
        }
        f=f.gcd(h+1).shrink();
        if(f.size()==2)return (f[0]/f[1]*(-1)).value();
    }
    return -1;
}