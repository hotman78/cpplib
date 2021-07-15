#pragma once
#include<vector>
template<typename T>
std::vector<T> gcd_convolution(std::vector<T>s,std::vector<T>t){
	auto zeta=[](std::vector<T>& f){
        const int n=f.size();
        std::vector<bool>sieve(n,1);
        for(int i=2;i<n;++i){
            if(sieve[i]){
                for(int j=(n-1)/i;j>=1;--j){
                    sieve[j*i]=0;
                    f[j]+=f[j*i];
                }
            }
        }
        for (int i=0;i<n;++i){
		    f[0]+=f[i];
	    }
	};
	auto mebius=[](std::vector<T>& f){
        const int n=f.size();
        std::vector<bool>sieve(n,1);
        for (int i=0;i<n;++i){
		    f[i]-=f[0];
	    }
        for(int i=2;i<n;++i){
            if(sieve[i]){
                for(int j=1;j*i<n;++j){
                    sieve[j*i]=0;
                    f[j]-=f[j*i];
                }
            }
        }
	};
    assert(s.size()==t.size());
    const int n=s.size();
	zeta(s);
	zeta(t);
	for(int i=0;i<n;++i)s[i]*=t[i];
	mebius(s);
	return s;
}