vector<int> suffix_array(string s){
    int n=s.size();
    vector<int> v1(n,-1),v2(n,-1);
    vector<int> rank(n,-1);
    iota(v1.begin(),v1.end(),0);
    iota(v2.begin(),v2.end(),0);
    sort(v1.begin(),v1.end(),[&](auto p,auto q){return s[p]<s[q];});
    int idx=0;
    for(int i=0;i<n;++i){
        rank[v1[i]]=idx;
        if(i<n-1&&s[v1[i]]!=s[v1[i+1]])idx++;
    }
    for(int i=0;i<(int)log2(n)+2;++i){
        const int h=1<<i;
        sort(v2.begin(),v2.end(),[&](auto p,auto q){
            return make_pair(rank[p],p+h<n?rank[p+h]:-1)<make_pair(rank[q],q+h<n?rank[q+h]:-1);
        });
        swap(v1,v2);
        idx=0;
        vector<int> tmp(n,-1);
        for(int j=0;j<n;++j){
            tmp[v1[j]]=idx;
            if(j<n-1&&make_pair(rank[v1[j]],v1[j]+h<n?rank[v1[j]+h]:-1)<make_pair(rank[v1[j+1]],v1[j+1]+h<n?rank[v1[j+1]+h]:-1))idx++;
        }
        swap(rank,tmp);
    }
    return v1;
}