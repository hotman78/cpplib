vector<vector<int>>g;
vector<int>used;
vector<int>v;
vector<vector<int>>ch;
int s;
int dfs(int n,int p,int sz,int root){
    if(used[n])return 0;
    bool b=1;
    int res=1;
    for(auto e:g[n]){
        if(p==e)continue;
        auto t=dfs(e,n,sz,root);
        res+=t;
        if(t>sz/2)b=0;
    }
    if(!b||sz-res>sz/2)return res;
    if(root!=-1)ch[root].push_back(n);
    else s=n;
    v.push_back(n);
    used[n]=1;
    for(auto e:g[n]){
        dfs(e,n,dfs(e,n,g.size()*2,n),n);
    }
    return g.size()*2;
}