#include<tuple>
#include"mod_pow.hpp"
#include"../util/random_gen.hpp"

/**
 * @brief ModSqrt
 */

long long mod_sqrt(long long a,long long mod){
    if(mod==2||a==0)return a;
    if(mod_pow(a,(mod-1)/2,mod)!=1)return -1;
    if(mod%4==3)return mod_pow(a,(mod+1)/4,mod);
    long long q=(mod-1),s=0;
    while(q%2==0)q/=2,s++;
    long long z=1;
    RandomNumberGenerator rnd;
    while(mod_pow(z=rnd(0,mod),(mod-1)/2,mod)!=mod-1);
    long long c=mod_pow(z,q,mod),t=mod_pow(a,q,mod),r=mod_pow(a,(q+1)/2,mod),m=s;
    while(m>1){
        if(mod_pow(t,1<<(m-2),mod)==1)(c*=c)%=mod,--m;
        else std::tie(c,t,r,m)=std::make_tuple(c*c%mod,c*c%mod*t%mod,c*r%mod,m-1);
    }
    return r%mod;
}