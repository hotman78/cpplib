//隣接リストを渡す
pair<vector<lint>,vector<vector<lint>>> scc(vector<vector<lint>>g){
    lint n=g.size();
    vector<vector<lint>>rev(n);
    for(int i=0;i<n;i++)for(auto e:g[i]){
        rev[e].emplace_back(i);
    }
    lint idx=0;
    vector<lint>v(n,-1);
    vector<bool>visited(n,0);
    function<void(lint)>dfs=[&](lint now){
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
    vector<lint>res(n,-1);
    function<void(lint)>rdfs=[&](lint now){
        for(auto e:rev[now]){
            if(res[e]==-1)res[e]=idx,rdfs(e);
        }
    };
    for(int i=n-1;i>=0;--i){
        if(res[v[i]]==-1){
            res[v[i]]=++idx;
            rdfs(v[i]);
        }
    }
    idx++;
    vector<vector<lint>>res2(idx);
    for(int i=0;i<n;i++)for(auto e:g[i]){
        if(res[i]==res[e])continue;
        res2[res[i]].push_back(res[e]);
    }
    for(int i=0;i<idx;i++){
        sort(res2[i].begin(),res2[i].end());
        res2[i].erase(unique(res2[i].begin(),res2[i].end()),res2[i].end());
    }
    return {res,res2};
}

// struct scc{
//     vector<vector<lint>>gg,rg;
//     vector<lint>pos;
//     vector<lint>comp,order;
//     vector<bool>used;
//     lint sz;
//     scc(lint sz):sz(sz){
//         gg.resize(sz);
//         rg.resize(sz);
//     }
//     void add(lint a,lint b){
//         gg[a].push_back(b);
//         rg[b].push_back(a);
//     }
//     void dfs(lint idx){
//         if(used[idx])return;
//         used[idx]=1;
//         for(lint to:gg[idx])dfs(to);
//         order.push_back(idx);
//     }
//     void rdfs(int idx, int cnt) {
//         if(comp[idx]!=-1) return;
//         comp[idx] = cnt;
//         for(int to : rg[idx]) rdfs(to, cnt);
//     }

//     vector<lint> build(){
//         pos.resize(sz);
//         used.resize(sz,0);
//         comp.resize(sz,-1);
//         rep(i,gg.size())dfs(i);
//         reverse(all(order));
//         int ptr=0;
//         for(lint i:order)if(comp[i]==-1){rdfs(i,ptr);ptr++;}
//         return comp;
//     }
// };
