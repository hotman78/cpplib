struct ZDD{
    struct node;
    using np=node*;
    struct node{
        vector<int>mate,rank;
        vector<np> ch;
        int edge_cnt;
        node(const vector<int>&mate,const vector<int>&rank,int edge_cnt):mate(mate),rank(rank),edge_cnt(edge_cnt){}
    };
    int n;
    np root=0;
    vector<pair<int,int>>edge;
    vector<int>rank;
    map<vector<int>,np>list;
    ZDD(int n,vector<pair<int,int>>edge,vector<int>rank):n(n),edge(edge),rank(rank){
        bfs();
    }
    struct BIT{
    vector<lint> bit;
        lint n;
        BIT(lint n):n(n){
            bit.resize(n+1,0);
        }
        //1-indexed [1,x]-sum
        lint sum(lint x){
            lint res=0;
            for(lint i=x;i>0;i-=i&-i)res+=bit[i];
            return res;
        }
        //1-indexed [x,y]-sum
        lint sum(lint x,lint y){
            return sum(y)-sum(x);
        }
        //1-indexed
        void add(lint x,lint val){
            x++;
            if(x>n)return;
            for(lint i=x;i<=n;i+=i&-i)bit[i]+=val;
        }
    };
    lint mx=0;
    bool judge(const vector<int>&v,const vector<int>&rank){
        // int cnt=0;
        // for(int i=1;i<n-1;i++){
        //     //if(rank[i])continue;
        //     if(v[i]!=i)cnt++;
        // }
        // if(mx<cnt)mx=cnt;
        return 1;
    }
    cint hhash(const vector<int>&v){
        vector<int>v2(n);
        BIT b(n);
        for(int i=0;i<n;i++){
            if(v[i]==-1)v2[i]=i+1;
            else{
                v2[i]=b.sum(0,v[i]);
                b.add(v[i],1);
            }
        }
        cint res=0,val=1;
        for(int i=0;i<n;i++){
            res+=val*v2[i];
            val*=i+2;
        }
        return res;
    }
    void bfs(){
        vector<int>v(n);
        iota(v.begin(),v.end(),0);
        root=list[v]=new node(v,rank,0);
        bitset<1000>used;
        random_shuffle(all(edge));
        for(int i=0;i<(int)edge.size();i++){
            cerr<<i<<endl;
            map<vector<int>,np> tmp_list;
            vector<pair<np,np>>tmp_connect;
            int idx=-1;
            for(int j=0;j<1;j++){
                //if(used[j])continue;
                auto list2=list;
                vector<pair<np,np>>connect;
                int s=edge[i].first,t=edge[i].second;
                for(auto [tmp,e]:list){
                    auto mate=e->mate;
                    auto rank=e->rank;
                    int edge_cnt=e->edge_cnt;
                    if(mate[s]==-1||mate[t]==-1)continue;
                    if(mate[s]==t)continue;
                    if(mate[s]==s&&mate[t]==t){
                        mate[s]=t;
                        mate[t]=s;
                        edge_cnt++;
                    }else if(mate[s]==s){
                        mate[mate[t]]=s;
                        mate[s]=mate[t];
                        mate[t]=-1;
                    }else if(mate[t]==t){
                        mate[mate[s]]=t;
                        mate[t]=mate[s];
                        mate[s]=-1;
                    }else{
                        mate[mate[s]]=mate[t];
                        mate[mate[t]]=mate[s];
                        mate[s]=mate[t]=-1;
                        edge_cnt--;
                    }
                    if(v[0]==-1||v[n-1]==-1)continue;
                    //if(!judge(mate,rank))continue;
                    //cint h=hhash(mate);
                    if(!list2.count(mate))list2[mate]=new node(mate,rank,edge_cnt);
                    connect.emplace_back(e,list2[mate]);
                }
                if(tmp_list.size()==0||tmp_list.size()>list2.size()){
                    tmp_connect=connect;
                    tmp_list=list2;
                    idx=j;
                }
            }
            used[idx]=1;
            list=tmp_list;
            for(auto e:tmp_connect){
                e.first->ch.emplace_back(e.second);
            }
        }
    }
    map<np,int64_t>memo;
    int64_t solve(np t){
        if(memo.count(t))return memo[t];
        int64_t res=t->edge_cnt==1&&t->mate[0]==n-1&&t->mate[n-1]==0;
        for(auto e:t->ch){
            res+=solve(e);
        }
        return memo[t]=res;
    }
    int64_t solve(){
        return solve(root);
    }
};