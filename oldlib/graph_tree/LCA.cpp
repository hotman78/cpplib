class LCA{
    using lint=long long;
    template<typename T>
    class sparse_table{
        using F=function<T(T,T)>;
        F f;
        vector<vector<T>>data;
        public:
        sparse_table(vector<T> v,F f):f(f){
            int n=v.size(),log=log2(n)+1;
            data.resize(n,vector<T>(log));
            for(int i=0;i<n;i++)data[i][0]=v[i];
            for(int j=1;j<log;j++)for(int i=0;i+(1<<(j-1))<n;i++){
                data[i][j]=f(data[i][j-1],data[i+(1<<(j-1))][j-1]);
            }
        }
        T get(int l,int r){
            if(r<l)swap(l,r);
            int k=log2(r-l);
            return f(data[l][k],data[r-(1<<k)][k]);
        }
    };
    vector<pair<lint,lint>>data;
    vector<lint>start;
    sparse_table<pair<lint,lint>>*st;
    vector<lint>dep;
    vector<lint> __dist;
    public:
    LCA(){}
    LCA(vector<vector<lint>>v,lint s){
        data.resize(v.size()*2-1);
        start.resize(v.size());
        lint i=0;
        dep=depth(s,v);
        __dist=__distance(s,v);
        function<void(lint,lint)>f=[&](lint n,lint p){
            start[n]=i;
            data[i++]=make_pair(dep[n],n);
            for(lint t:v[n]){
                if(t==p)continue;
                f(t,n);
                data[i++]=make_pair(dep[n],n);
            }
        };
        f(s,-1);
        st=new sparse_table<pair<lint,lint>>(data,[](auto s,auto t){return s.first>t.first?s:t;});
    }
    lint lca(lint p,lint q){
        return st->get(min(start[p],start[q]),max(start[p],start[q])+1).second;
    }
    lint distance(lint p,lint q){
        return __dist[p]+__dist[q]-2*__dist[lca(p,q)];
    }
    vector<lint> __distance(lint start,vector<vector<lint>>G){
		vector<lint>memo(G.size());
		function<lint(lint,lint,lint)> f=[&](lint v,lint p,lint i){
			for(auto t:G[v]){
				if(t==p)continue;
				f(t,v,i+1);
			}
			return memo[v]=i;
		};
		f(start,-1,0);
		return memo;
    }
    vector<lint> depth(lint start,vector<vector<lint>>G){
        vector<lint>memo(G.size());
        function<lint(lint,lint)>f=[&](lint v,lint p){
            lint mx=0;
            for(lint t:G[v]){
                if(t==p)continue;
                mx=max(mx,f(t,v));
            }
            return memo[v]=mx+1;
        };
        f(start,-1);
        return memo;
    }
};

struct lca{
    using lint=long long;
    vector<vector<lint>>g;
    vector<int>sz,in,out,nxt,par;
    lca(vector<vector<lint>>g,int s):g(g),sz(g.size(),0),in(g.size(),0),out(g.size(),0),nxt(g.size(),s),par(g.size(),s){
        dfs_sz(s,-1);
        dfs_hld(s,-1);
    }
    void dfs_sz(int v,int p) {
        sz[v] = 1;
        for(auto &u: g[v]) {
            if(p==u)continue;
            dfs_sz(u,v);
            sz[v]+=sz[u];
            if(sz[u]>sz[g[v][0]])swap(u,g[v][0]);
        }
    }
    void dfs_hld(int v,int p) {
        static int t=0;
        in[v]=t++;
        for(auto u: g[v]){
            if(p==u)continue;
            nxt[u]=(u==g[v][0]?nxt[v]:u);
            par[u]=(u==g[v][0]?par[v]:v);
            dfs_hld(u,v);
        }
        out[v] = t;
    }
    int query(int s,int t){
        while(nxt[s]!=nxt[t]){
			if(sz[nxt[s]]>sz[nxt[t]])t=par[t];
			else s=par[s];
		}
        return sz[s]>sz[t]?s:t;
    }
    int distance(int s,int t){
		int res=0;
		while(nxt[s]!=nxt[t]){
			if(sz[nxt[s]]>sz[nxt[t]]){
				res+=in[t]-in[nxt[t]]+1;
				t=par[t];
			}
			else {
				res+=in[s]-in[nxt[s]]+1;
				s=par[s];
			}
		}
		return res+abs(in[s]-in[t]);
	}
};