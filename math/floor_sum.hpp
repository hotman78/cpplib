#pragma once
// \sum_{i=0}^{n-1}\floor(a*i+b/c)
long long floor_sum(long long a,long long b,long long c,long long n){
    long long tmp=b/c*n+a/c*n*(n-1)/2;
    if(a%c==0){
        return tmp;
    }
    long long next=(c-b%c+a%c-1)/(a%c);
    if(next>=n){
        return tmp;
    }
    a%=c;
    b=b%c+a*next;
    n-=next;
    return tmp+floor_sum(c,n*a-((b+a*(n-1))/c*c-b),a,(b+a*(n-1))/c);
}