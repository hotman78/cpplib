template<int n=10'000'000>
vector<int64_t> primeList() {
    bitset<n+1> p;
    p.set();
    p[0]=0;
    for(int i=2;i<sqrt(n)+10;++i){
        if(!p[i])continue;
        for(int j=2*i;j<n;j+=i)p[j]=0;
    }
    vector<int64_t>list;
    for(int i=2;i<=n;++i)if(p[i])list.push_back(i);
    return list;
}

inline vector<lint> primeList(lint n) {
    vector<bool> p(n+1);
    vector<lint> list;
    repi(i,1, n+1)p[i] = true;
    repi(i,2,sqrt(n)+1) {
        if (p[i]) {
            repi(j,2,n/i+1) {
                p[i*j] = false;
            }
        }
    }
    repi(i, 2, n+1)if (p[i])list.push_back(i);
    return list;
}
template<typename T>
inline set<T> primeSet(T n) {
    vector<bool> p(n+1,1);
    set<T> set;
    p[0]=0;
    for(int i=2;i<=sqrt(n);i++) {
        if(p[i])for(int j=2;j<n/i+1;j++)p[i*j]=0;
    }
    for(int i=2;i<=n;i++)if(p[i])set.insert(i);
    return set;
}