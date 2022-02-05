long long double_to_int(string s,long long k){
    if(count(all(s),'.')){
        long long tmp=0;
        for(int i=0;i<(int)s.size();++i)if(s[i]=='.')tmp=s.size()-1-i;
        string t;
        for(auto e:s)if(e!='.')t+=e;
        long long res=stoll(t);
        for(int i=0;i<k-tmp;++i)res*=10;
        return res;
    }else{
        long long res=stoll(s);
        for(int i=0;i<k;++i)res*=10;
        return res;
    }
}