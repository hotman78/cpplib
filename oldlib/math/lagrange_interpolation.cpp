mint lagrange_interpolation(vector<mint>v,lint n){
    lint k=v.size();
    if(n<k)return v[n];
    vector<mint> tmp1(k+1,1),tmp2(k+1,1);
    mint ans=0;
    rep(i,k)tmp1[i]=(i?tmp1[i-1]:1)*(n-i);
    rrep(i,k)tmp2[i]=(i<k-1?tmp2[i+1]:1)*(n-i);
    rep(i,k){
        ans+=v[i]*(i<k-1?tmp2[i+1]:1)*(i?tmp1[i-1]:1)/(mint(k-1-i).fact()*mint(i).fact()*mint((k-1-i)%2?-1:1));
    }
    return ans;
}
