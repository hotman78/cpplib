/*
最終的にn個の"["とk個の"]"でカッコ列を作る
但し、途中で"["の数が"]"の数よりm個以上大きくなる事を許さない
*/
template<typename T>
T catalans_trapezoids(long long n,long long k,long long m=1){
    if(m<=0)return T();
    else if(0<=k&&k<m)return T(n+k).comb(k);
    else if(m<=k&&k<n+m)return T(n+k).comb(k)-T(n+k).comb(k-m);
    else return T(0);
}