struct two_sat{
    int n;
    vector<vector<int>>v;
    vector<int>list;
    vector<vector<int>>g;
    two_sat(int n):n(n){
        v.resize(n*2);
        list.resize(n*2,-1);
    }
    //add s==p&&t==q
    void add_edge(int s,int t,bool p,bool q){
        v[s+p*n].push_back(t+(1-q)*n);
        v[t+q*n].push_back(s+(1-p)*n);
    }
    bool solve(){
        static int scced=0;
        static bool ans=1;
        if(!scced){
            scced=1;
            scc(v);
            for(int i=0;i<n;i++){
                if(list[i]==list[i+n])ans=0;
            }
        }
        return ans;
    }
    bool operator[](int i){
        return list[i]>list[i+n];
    }
    void scc(vector<vector<int>>g){
        int n=2*this->n;
        vector<vector<int>>rev(n);
        for(int i=0;i<n;i++)for(auto e:g[i]){
            rev[e].emplace_back(i);
        }
        lint idx=0;
        vector<int>v(n,-1);
        vector<bool>visited(n,0);
        function<void(int)>dfs=[&](int now){
            visited[now]=1;
            for(auto e:g[now]){
                if(!visited[e])dfs(e);
            }
            v[idx++]=now;
        };
        for(int i=0;i<n;i++){
            if(!visited[i])dfs(i);
        }
        idx=-1;
        function<void(int)>rdfs=[&](int now){
            for(auto e:rev[now]){
                if(list[e]==-1)list[e]=idx,rdfs(e);
            }
        };
        for(int i=n-1;i>=0;--i){
            if(list[v[i]]==-1){
                list[v[i]]=++idx;
                rdfs(v[i]);
            }
        }
        idx++;
        for(int i=0;i<n;i++)for(auto e:g[i]){
            if(list[i]==list[e])continue;
            g[list[i]].push_back(list[e]);
        }
        for(int i=0;i<idx;i++){
            sort(g[i].begin(),g[i].end());
            g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
        }
    }
};