struct online_Zalgo{
    vector<int>z;
    set<int>memo;
    vector<vector<int>>hist;
    string s="";
    int sz=0;
    void add(char c){
        s+=c;
        memo.emplace(sz);
        z.push_back(-1);
        hist.push_back(vector<int>());
        sz++;
        int mx=-1;
        for(auto itr=next(memo.begin(),1);itr!=memo.end();){
            auto idx=*itr;
            if(s[sz-idx-1]!=s.back()){
                itr=memo.erase(itr);
                z[idx]=sz-idx-1;
                hist.back().push_back(idx);
            }else{
                mx=idx;
                break;
            }
        }
        if(mx==-1)return;
        for(auto e:hist[sz-1-mx]){
            memo.erase(mx+e);
            z[mx+e]=sz-(mx+e)-1;
            hist.back().push_back(mx+e);
        }
    }
    int operator[](int idx){
        if(memo.count(idx))return sz-idx;
        else return z[idx];
    }
};