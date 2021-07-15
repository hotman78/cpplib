template<typename T>
struct reroot{
    vector<vector<lint>>g;
    vector<lint>p_list;
    vector<T>p_table;
    vector<bool>p_checked;
    vector<map<lint,T>>table;
    vector<T>ans;
    reroot(auto g):g(g),p_list(g.size(),-1),p_checked(g.size(),0),table(g.size()){
        p_table.resize(g.size(),e);
        ans.resize(g.size(),e);
        dfs1(0,-1);
        for(int i=0;i<(int)g.size();++i)ans[i]=dfs2(i,-1);
    }
    T dfs1(lint n,lint p){
        p_list[n]=p;
        T tmp1=e,tmp2=e;
        vector<T>tmp(g[n].size());
        rep(i,g[n].size()){
            lint t=g[n][i];
            if(t==p)continue;
            table[n][t]=tmp1;
            tmp1=f(tmp1,tmp[i]=dfs1(t,n));
        }
        for(lint i=g[n].size()-1;i>=0;--i){
            lint t=g[n][i];
            if(t==p)continue;
            table[n][t]=f(table[n][t],tmp2);
            tmp2=f(tmp[i],tmp2);
        }
        return fix(table[n][p]=tmp1,n,p);
    }
    T dfs2(lint n,lint p){
        if(n==-1)return e;
        if(!p_checked[n]){
            p_checked[n]=1;
            p_table[n]=dfs2(p_list[n],n);
        }
        if(p==-1){
            return f(table[n][p_list[n]],p_table[n]);
        }else{
            if(p_list[n]==-1)return fix(table[n][p],n,p);
            else return fix(f(table[n][p],p_table[n]),n,p);
        }
    }
    vector<T>query(){
        return ans;
    }
    T e=T(1,0);
    T f(T s,T t){
        return s;
    }
    T fix(T s,int n,int p){
        return s;
    }
};