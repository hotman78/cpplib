struct symplex{
    public:
    lint valSize,formula_size=-1;
    symplex(lint valSize):valSize(valSize){}
    vector<vector<double>> list;
    vector<int> defaultList;
    set<int> defaultSet;
    void add_formula(vector<double>coefficient,int def){
        // vector<double>coefficient(valSize,0.);
        // rep(i,x.size())coefficient[x[i]]=a[i];
        list.push_back(coefficient);
        defaultList.push_back(def);
        defaultSet.insert(def);
        formula_size++;
    }
    double solve(){
        while(1){
            rep(i,formula_size)normalize(i,defaultList[i]);
            rep(i,formula_size)rep(j,formula_size+1){
                if(i==j)continue;
                _add(i,j,-list[j][defaultList[i]]);
            }
            double mn=0;
            int change=0;
            rep(i,valSize)if(chmin(mn,list[formula_size][i]))change=i;
            if(mn==0)break;
            double limit=0;
            int changed=0;
            rep(i,formula_size){
                if(chmax(limit,-list[i][valSize]/list[formula_size][change])){
                    changed=defaultList[i];
                }
            }
            defaultSet.erase(changed);
            defaultSet.insert(change);
            defaultList[changed]=change;
        }
        output2(list);
        return list[formula_size][valSize];
    }
    private:
    //i行目をj列目の数でnormalizeする
    void normalize(int i,int j){
        double tmp=list[i][j];
        if(tmp==0)return;
        rep(k,valSize+1)list[i][k]/=tmp;
    }
    //i行目のk倍をj行目に足す
    void _add(int i,int j,double k){
        rep(l,valSize+1)list[j][l]+=k*list[i][l];
    }
};