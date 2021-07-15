template<typename T>
class sparse_table{
    using F=function<T(T,T)>;
    F f;
    vector<vector<T>>data;
    public:
    sparse_table(vector<T> v,F f):f(f){
        int n=v.size(),log=log2(n)+1;
        data.resize(n,vector<T>(log));
        for(int i=0;i<n;i++)data[i][0]=v[i];
        for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){
            data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);
        }
    }
    T get(int l,int r){
        if(r<l)swap(l,r);
        //assert(0<l||r<=(T)data.size());
        int k=log2(r-l);
        return f(data[l][k],data[r-(1<<k)][k]);
    }
};