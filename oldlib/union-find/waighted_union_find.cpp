struct WUF{
    public:
    vector<int> par;
    vector<int> rank;
    vector<int> _w;
    lint _s;
    WUF(auto size){
        _s=size;
        par.resize(size);
        rep(i,size)par[i]=i;
        rank.resize(size,0);
        _w.resize(size,0);
    }
    bool unite(auto x,auto y,auto w){
        w+=weight(x);
        w-=weight(y);
        x=root(x);y=root(y);
        if(x==y)return false;
        if(rank[x]<rank[y]){swap(x,y);w=-w;}
        if(rank[x]==rank[y])rank[x]++;
        par[y]=x;
        _s--;
        _w[y] = w;
        return true;
    }
    int root(auto x){
        if(par[x] == x) {
            return x;
        }else {
            auto r = root(par[x]);
            _w[x] += _w[par[x]];
            return par[x] = r;
        }
    }
    bool same(auto x, auto y) {
        return root(x) == root(y);
    }
    int size(){
        return _s;
    }
    int weight(auto x){
        root(x);
        return _w[x];
    }
    int diff(auto x,auto y){
        return weight(y)-weight(x);
    }
};
