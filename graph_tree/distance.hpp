std::vector<int> distance(const graph& G,int start){
    std::vector<int>memo(G.size());
    auto f=[&](auto f,int v,int p,int i)->void{
        for(auto t:G[v]){
            if(t==p)continue;
            f(f,t,v,i+1);
        }
        memo[v]=i;
    };
    f(f,start,-1,0);
    return memo;
}