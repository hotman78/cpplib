/**
 * @brief Union Find
 * @docs docs/union_find.md
 * @see https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0
 */

class UF{
    public:
    vector<int> data;
    int sz;
	public:
    UF(int sz):sz(sz){data.resize(sz,-1);}
    bool unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return 0;
        if(data[x]>data[y])swap(x,y);
		data[x]+=data[y];
		data[y]=x;
		sz--;
        return 1;
    }
    inline int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
    inline bool same(int x, int y){return root(x)==root(y);}
    inline int size(){return sz;}
	inline int size(int x){return -data[root(x)];}
};