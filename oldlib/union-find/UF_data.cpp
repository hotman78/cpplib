template<typename T>
class UF_data{
    public:
    vector<int> data;
    hash_map<int,T>monoid;
    int sz;
	public:
    UF_data(auto sz,vector<T>v):sz(sz){
        data.resize(sz,-1);
        for(int i=0;i<sz;i++){
            monoid[i]=v[i];
        }
    }
    bool unite(auto x,auto y){
        x=root(x);y=root(y);
        if(x==y)return 0;
        if(data[x]>data[y])swap(x,y);
		data[x]+=data[y];
		data[y]=x;
        monoid[x]=f(monoid[x],monoid[y]);
		sz--;
        return 1;
    }
    void update(auto x,T val){
        monoid[root(x)]=f(monoid[root(x)],val);
    }
    T get(auto x){return monoid[x];}
    inline int root(auto x){return data[x]<0?x:data[x]=root(data[x]);}
    inline bool same(auto x, auto y){return root(x)==root(y);}
    inline int size(){return sz;}
	inline int size(auto x){return -data[root(x)];}
    T f(T s,T t){
        return s+t;
    }
};