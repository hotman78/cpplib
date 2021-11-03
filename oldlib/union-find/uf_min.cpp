//rootとのpathの値のminを取れるUF
struct uf_min{
    constexpr static int inf=1<<30;
    vector<int>par,mn,mnid;
    uf_min(int v){
        par.resize(v);
        mn.resize(v,inf);
        mnid.resize(v);
        iota(par.begin(),par.end(),0);
        iota(mnid.begin(),mnid.end(),0);
    }
    int find(int v){
        if(par[v]==v)return v;
        int r=find(par[v]);
        if(mn[v]>mn[par[v]]){
            mnid[v]=mnid[par[v]];
            mn[v]=mn[par[v]];
        }
        par[v]=r;
        return r;
    }
    void set(int v,int x){
        mn[v]=x;
    }
    int eval(int v){
        find(v);
        return mnid[v];
    }
    //xをyの親にする
    void link(int x,int y){
        par[y]=x;
    }
};
