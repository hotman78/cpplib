vector<vector<mint>>NTT2d(const vector<vector<mint>>&s,const vector<vector<mint>>&t){
    int sh=s.size()+t.size()-1;
    int sw=s[0].size()+t[0].size()-1;
    int h=1,w=1;
    while(h<sh)h*=2;
    while(w<sw)w*=2;
    fps<mint>f(h*w),g(h*w);
    vector<vector<mint>>res(sh,vector<mint>(sw));
    rep(i,s.size())rep(j,s[0].size()){
        f[i*w+j]=s[i][j];
    }
    rep(i,t.size())rep(j,t[0].size()){
        g[i*w+j]=t[i][j];
    }
    f*=g;
    rep(i,sh)rep(j,sw){
        res[i][j]=f[i*w+j];
    }
    return res;
}