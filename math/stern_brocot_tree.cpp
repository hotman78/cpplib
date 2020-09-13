#include<iostream>

//分母がm以下のk番目の数
long long m;
void bs(long long a,long long b,long long c,long long d,long long& k){
    if(b+d>m)return;
    bs(a,b,a+c,b+d,k);
    k--;
    if(k==0){
        std::cout<<a+c<<" "<<b+d<<std::endl;
        exit(0);
    }
    bs(a+c,b+d,c,d,k); 
}