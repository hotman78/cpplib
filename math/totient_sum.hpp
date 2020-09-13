#pragma once
#include<map>

/**
 * @brief トーシェント関数の和
 */

template<typename T>
T totient_sum(long long n){
    static std::map<long long,T> m2;
    static bool init=1;
    static long long* m=new long long[10000000]();
    if(init){
        init=0;
        long long k=1e7;
        for(long long i=1;i<=k;i++)m[i]=i;
        for(long long i=1;i<=k;i++)for(long long j=i*2;j<=k;j+=i)m[j]-=m[i];
        for(long long i=1;i<k;i++)m[i+1]+=m[i];
    }
    if(n<1e7)return m[n];
    else if(m2.count(n))return m2[n];
    T ans=T(n)*(n+1)/2;
    long long mx=0;
    for(long long i=1;i*i<n;i++){
        ans-=T(n/i-n/(i+1))*totient_sum<T>(i);
        mx=n/(i+1)+1;
    }
    for(long long i=2;i<mx;i++){
        ans-=totient_sum<T>(n/i);
    }
    return m2[n]=ans;
}