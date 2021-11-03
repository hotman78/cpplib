template<typename T=lint>
vector<vector<T>> mul(const vector<vector<T>>& s,const vector<vector<T>>& t){
    lint n=s.size();
    vector<vector<T>> res(n,vector<T>(n,0));
    rep(i,n)rep(j,n)rep(k,n){
        res[i][j]+=s[i][k]*t[k][j];
    }
    return res;
}
template<typename T=lint>
vector<vector<T>> mul(const vector<pair<T,T>>& s,const vector<vector<T>>& t){
    lint n=s.size();
    vector<vector<T>> res(n,vector<T>(n,0));
    rep(i,n)rep(j,n)rep(k,n){
        res[i][j]+=s[i][k]*t[k][j];
    }
    return res;
}
template<typename T=lint>
vector<vector<T>> pow(const vector<vector<T>>& s,const lint& n){
    if(n==0){
        lint sz=s.size();
        vector<vector<T>> res(sz,vector<T>(sz,0));
        rep(i,sz)res[i][i]=1;
        return res;
    }
    if(n==1)return s;
    if(n%2==0){
        vector<vector<T>> tmp=pow<T>(s,n/2);
        return mul<T>(tmp,tmp);
    }else{
        return mul<T>(s,pow(s,n-1));
    }
}
template<typename T=lint>
vector<T> conv(vector<T> a,vector<vector<T>> b){
    lint n=a.size();
    vector<T> res(n,0);
    rep(i,n)rep(j,n)res[i]+=a[j]*b[i][j];
    return res;
}