template<typename T,typename F>
class UF_data{
    public:
    vector<int> data;
    vector<T>val;
    int sz;
    F merge;
	public:
    UF_data(int sz,F merge=F()):sz(sz),merge(merge){data.resize(sz,-1);val.resize(sz,T());}
    bool unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return 0;
        if(data[x]>data[y])swap(x,y);
		data[x]+=data[y];
		data[y]=x;
        val[x]=merge(move(val[x]),move(val[y]));
		sz--;
        return 1;
    }
    inline void set(int x,const T&v){
        x=root(x);
        val[x]=v;
    }
    template<typename G>
    void apply(int x,G g=G()){
        x=root(x);
        g(val[x]);
    }
    inline T& get(int x){
        return val[root(x)];
    }
    inline int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
    inline bool same(int x, int y){return root(x)==root(y);}
    inline int size(){return sz;}
	inline int size(int x){return -data[root(x)];}
};