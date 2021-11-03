#pragma once
#include"./graph_template.hpp"
#include"../segment_tree/lazy_segment_tree.hpp"

template<typename T,typename E,typename F,typename G,typename H>
class HLD_lazy{
	int child_size(const  graph& v,int n,int p){
		int cnt=0;
		for(auto t:v[n]){
			if(t!=p)cnt+=child_size(v,t,n);
		}
		return sz[n]=cnt+1;
	}
	void make(const graph& v,int root){
		sz=new int[v.size()];
		vertex=new int[v.size()];
		par=new int[v.size()];
		head=new int[v.size()];
		child_size(v,root,-1);
		stack<tuple<int,int>>stk;
		stk.emplace(root,-1);
		int idx=0;
		par[root]=root;
		head[root]=root;
		while(!stk.empty()){
			int n,p;
			tie(n,p)=stk.top();
			stk.pop();
			vertex[n]=idx++;
			int mx=0,heavy=-1;
			for(auto t:v[n])if(t!=p&&mx<sz[t]){
				mx=sz[t];
				heavy=t;
			}
			for(auto t:v[n]){
				if(t!=heavy&&t!=p){
					par[t]=n;
					head[t]=t;
					stk.emplace(t,n);
				}
			}
			if(heavy!=-1){
				par[heavy]=par[n];
				head[heavy]=head[n];
				stk.emplace(heavy,n);
			}
		}
	}
	int* sz;
	int* vertex;
	int* par;
	int* head;
	F _f;G _g;H _h;
	lazy_segment_tree<T,E,F,G,H>* seg;
	public:
	HLD_lazy(const graph& v,int root=0,F f=F(),G g=G(),H h=H()):_f(f),_g(g),_h(h){
		make(v,root);
		seg=new lazy_segment_tree<T,E,F,G,H>(v.size(),f,g,h);
	}
	// HLD_lazy(const graph& v,const vector<T>& a,int root=0,F f=F(),G g=G(),H h=H()):_f(f),_g(g),_h(h){
	// 	vector<T>tmp(v.size());
	// 	make(v,root);
	// 	for(int i=0;i<(int)v.size();i++){
	// 		tmp[vertex[i]]=a[i];
	// 	}
	// 	seg=new lazy_segment_tree(tmp,f,g,h);
	// }
	int lca(int l,int r){
		while(1){
			if(head[l]==head[r])return sz[l]>sz[r]?l:r;
			else if(sz[head[l]]>sz[head[r]])r=par[r];
			else l=par[l];
		}
	}
	inline void update_vertex(int u,E x){
		seg->update(vertex[u],vertex[u],x);
	}
	inline maybe<T> get_vertex(int u){
		return seg->get(vertex[u],vertex[u]);
	}
	inline void update_subtree(int u,E x){
		seg->update(vertex[u],vertex[u]+sz[u]-1);
	}
	inline maybe<T> get_subtree(int u){
		return seg->get(vertex[u],vertex[u]+sz[u]-1);
	}
	void update_path(int u,int v,E x){
		while(1){
			if(head[u]==head[v]){
				seg->update(vertex[u],vertex[v],x);
				break;
			}
			else if(sz[head[u]]>sz[head[v]]){
				seg->update(vertex[v],vertex[head[v]],x);
				v=par[v];
			}
			else{
				seg->update(vertex[u],vertex[head[u]],x);
				u=par[u];
			}
		}
	}
	T get_path(int u,int v){
		auto f=expand<T,F>(_f);
		maybe<T> res;
		while(1){
			if(head[u]==head[v]){
				return f(res,seg->get(vertex[u],vertex[v]));
			}
			else if(sz[head[u]]>sz[head[v]]){
				res=f(res,seg->get(vertex[v],vertex[head[v]]));
				v=par[v];
			}
			else{
				res=f(res,seg->get(vertex[u],vertex[head[u]]));
				u=par[u];
			}
		}
	}
};