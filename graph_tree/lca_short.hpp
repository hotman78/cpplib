#pragma once
#include<vector>
#include"graph_template.hpp"

/**
 * @brief LCA(HL分解)&amp;lt;O(N),O(logN)&amp;gt;
 */

struct lca{
    graph g;
    std::vector<int>sz,in,out,nxt,par,par2;
    lca(const graph& g,int s):g(g){
        int n=g.size();
        sz.resize(n,0);
        in.resize(n,0);
        out.resize(n,0);
        nxt.resize(n,s);
        par.resize(n,s);
        par2.resize(n,s);
        dfs_sz(s,-1);
        dfs_hld(s,-1);
    }
    void dfs_sz(int v,int p) {
        sz[v] = 1;
        for(auto &u: g[v]) {
            if(p==u)continue;
            dfs_sz(u,v);
            sz[v]+=sz[u];
            if(sz[u]>sz[g[v][0]])std::swap(u,g[v][0]);
        }
    }
    void dfs_hld(int v,int p) {
        static int t=0;
        in[v]=t++;
        for(auto u: g[v]){
            if(p==u)continue;
            nxt[u]=(u==g[v][0]?nxt[v]:u);
            par[u]=(u==g[v][0]?par[v]:v);
            par2[u]=v;
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
		return res+std::abs(in[s]-in[t]);
	}
    std::vector<int>path(int s,int t){
        int l=query(s,t);
        std::vector<int>p,q;
        while(s!=l){
            p.push_back(s);
            s=par2[s];
        }
        while(t!=l){
            q.push_back(t);
            t=par2[t];
        }
        p.push_back(l);
        p.insert(p.end(),q.rbegin(),q.rend());
        return p;
    }
};