struct uf_min{
    constexpr static int inf=1<<30;
    vector<int>par,mn,mnid;
    uf_min(int v){
        par.resize(v);
        mn.resize(v,inf);
        mnid.resize(v);
        iota(par.begin(),par.end(),0);
        iota(mnid.begin(),mnid.end(),0);
    }
    int find(int v){
        if(par[v]==v)return v;
        int r=find(par[v]);
        if(mn[v]>mn[par[v]]){
            mnid[v]=mnid[par[v]];
            mn[v]=mn[par[v]];
        }
        par[v]=r;
        return r;
    }
    void set(int v,int x){
        mn[v]=x;
    }
    int eval(int v){
        find(v);
        return mnid[v];
    }
    //xをyの親にする
    void link(int x,int y){
        par[y]=x;
    }
};

// rootからvに向かう際に絶対通らないといけない頂点を
// vの祖先とするように木を構築する
vector<int> dominator_tree(vector<vector<int>>g,int s){
	int n=g.size();
	vector<vector<int>> rev_g(n);
	for(int i=0;i<n;++i){
		for(auto e:g[i]){
			rev_g[e].push_back(i);
		}
	}
	stack<int>stk;
    vector<bool>used(n,0);
    vector<int>id(n+1,n);
    vector<int>id2(n+1,n);
    vector<int>sdom(n,n);
    vector<int>idom(n,n);
    vector<vector<int>>ch(n);
    sdom[s]=s;
    int idx=0;
    stk.emplace(s);
    while(!stk.empty()){
        auto v=stk.top();
        stk.pop();
        id2[v]=idx;
        id[idx++]=v;
        for(auto e:g[v]){
            if(!used[e]){
                ch[v].push_back(e);
                stk.emplace(e);
                used[e]=1;
            }
        }
    }
    for(int i=0;i<n;++i){
        int v=id[i];
        if(v==n)continue;
        if(v==s)continue;
        for(auto e:rev_g[v]){
            if(id2[e]<i){
                if(id2[sdom[v]]>id2[e]){
                    sdom[v]=e;
                }
            }
        }
    }
    uf_min uf(n);
    vector<vector<int>>sdom_list(n+1);
    vector<int>u(n,-1);
    for(int i=n-1;i>=0;--i){
        int v=id[i];
        if(v==n)continue;
        for(auto e:sdom_list[v]){
            u[e]=uf.eval(e);
        }
        if(v==s)continue;
        for(auto e:rev_g[v]){
            if(id2[e]<i)continue;
            auto d=uf.eval(e);
            if(id2[sdom[v]]>id2[sdom[d]])sdom[v]=sdom[d];
        }
        sdom_list[sdom[v]].push_back(v);
        uf.set(v,id2[sdom[v]]);
        for(auto e:ch[v]){
            uf.link(v,e);
        }
    }
    for(int i=0;i<n;++i){
        auto v=id[i];
        if(v==n)continue;
        if(v==s){
            idom[v]=v;
            continue;
        }
        if(sdom[v]==sdom[u[v]])idom[v]=sdom[v];
        else idom[v]=idom[u[v]];
    }
    for(int i=0;i<n;++i)if(idom[i]==n)idom[i]=-1;
	return idom;
}