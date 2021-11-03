#include<vector>
#include"lca.hpp"

struct la{
    graph g;
    std::vector<std::vector<int>>table;
    la(graph g,int st=0):g(g){
        int n=g.size();
        table.resize(30,std::vector<int>(n,st));
        dfs(st,-1);
        for(int i=1;i<30;++i){
            for(int j=0;j<n;++j){
                table[i][j]=table[i-1][table[i-1][j]];
            }
        }
    }
    void dfs(int now,int p){
        for(auto e:g[now]){
            if(e==p)continue;
            table[0][e]=now;
            dfs(e,now);
        }
    }
    int up(int s,int k){
        for(int i=0;i<30;++i){
            if(k>>i&1){
                s=table[i][s];
            }
        }
        return s;
    }
};