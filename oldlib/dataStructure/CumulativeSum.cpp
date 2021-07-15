template<typename T>struct CumulativeSum{
    lint n;
    vector<T> v;
    CumulativeSum(lint n):n(n){
        v.resize(n+1,0);
    }
    //0-indexed
    void update(lint x,T val){
        v[x+1]=v[x]+val;
    }
    //0-indexed [a,b) sum
    T get(lint a,lint b){
        return v[b]-v[a];
    }
    T get(lint x){
        return v[x+1]-v[x];
    }
    vector<T> vals(){
        vector<T> res(n);
        rep(i,n)res[i]=v[i+1]-v[i];
        return res;
    }
};

template<typename T=lint>struct cumsum2D{
    vector<vector<T>> s;
    lint h,w;
    cumsum2D(vector<vector<T>> v){
        h=v.size();
        w=v[0].size();
        s.resize(h+1,vector<T>(w+1,0));
        rep(i,h)rep(j,w){
            s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+v[i][j];
        }
    }
    T get(lint lx,lint rx,lint ly,lint ry){
        return s[rx][ry]-s[rx][ly]-s[lx][ry]+s[lx][ly];
    }
    T get(lint rx,lint ry){
        return s[rx][ry];
    }
};

template<typename T=int64_t>
class csum{
    vector<T>v,s;
    public:
    csum(int n){v.resize(n,e);}
    csum(int n,int k){v.resize(n,k);}
    void push_back(T val){
        v.push_back(val);
    }
    T& operator[](int i){return v[i];}
    void build(){
        s.resize(v.size()+1,e);
        for(size_t i=0;i<v.size();i++)s[i+1]=f(s[i],v[i]);
    }
    T operator()(int l,int r){return rev(s[r],s[l]);}
    int size(){return v.size();}
    private:
    T e=0;
    T f(T a,T b){
        return a+b;
    }
    T rev(T a,T b){
        return a-b;
    }
};