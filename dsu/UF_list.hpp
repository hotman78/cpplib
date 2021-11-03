class UF{
    public:
    vector<int> data;
    int sz;
	public:
    UF(int sz):sz(sz){
        for(int i=0;i<sz;++i)data[i]=i;
    }
    bool unite(int x,int y){
        data.swap(x,y);
        return 1;
    }
};