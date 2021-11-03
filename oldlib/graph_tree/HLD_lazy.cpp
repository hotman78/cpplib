template<typename T,typename E>
class HLD_lazy{
	class lazy_segment_tree{
		int n=1,sz;
		T* node;
		E* lazy;
		int ids[64];
		int idx;
		void eval(const auto& t){
			if(lazy[t]==ee)return;
			node[t]=h(node[t],lazy[t],n>>(int)(log2(t+1)));
			if(t<n-1){
				lazy[(t<<1)+1]=g(lazy[(t<<1)+1],lazy[t]);
				lazy[(t<<1)+2]=g(lazy[(t<<1)+2],lazy[t]);
			}
			lazy[t]=ee;
		}
		void get_eval(auto l,auto r){
			l+=n;r+=n;
			const int lm=(l/(l&-l))>>1;
			const int rm=(r/(r&-r))>>1;
			idx=0;
			while(r>l){
				if(r<=rm&&r)ids[idx++]=r-1;
				if(l<=lm&&l)ids[idx++]=l-1;
				l>>=1;r>>=1;
			}
			while(l){
				ids[idx++]=l-1;
				l>>=1;
			}
		}
		public:
		lazy_segment_tree(const vector<T>& v):sz(v.size()){
			while(n<(int)v.size())n<<=1;
			node=new T[(n<<1)-1];
			lazy=new E[(n<<1)-1];
			for(int i=(int)v.size()+n-1;i<(n<<1)-1;i++)node[i]=et;
			for(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;
			for(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];
			for(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);
		}
		lazy_segment_tree(const auto& sz):sz(sz){
			while(n<(int)sz)n<<=1;
			node=new T[(n<<1)-1];
			lazy=new E[(n<<1)-1];
			for(int i=0;i<(n<<1)-1;i++)node[i]=et;
			for(int i=0;i<(n<<1)-1;i++)lazy[i]=ee;
		}
		void update(auto l,auto r,E val){
			if(l>r)swap(l,r);
			r++;
			get_eval(l,r);
			for(int i=idx-1;i>=0;i--)eval(ids[i]);
			l+=n;r+=n;
			while(l<r){
				if(l&1){lazy[l-1]=g(lazy[l-1],val);eval(l-1);++l;}
				if(r&1){--r;lazy[r-1]=g(lazy[r-1],val);eval(r-1);}
				l>>=1;r>>=1;
			}
			for(int i=0;i<idx;i++){
				eval((ids[i]<<1)+1);
				eval((ids[i]<<1)+2);
				node[ids[i]]=f(node[(ids[i]<<1)+1],node[(ids[i]<<1)+2]);
			}
		}
		T get(auto l,auto r){
			if(l>r)swap(l,r);
			r++;
			get_eval(l,r);
			for(int i=idx-1;i>=0;i--)eval(ids[i]);
			l+=n;r+=n;
			T res=et;
			while(l<r){
				if(l&1){eval(l-1);res=f(res,node[l-1]);l++;}
				if(r&1){--r;eval(r-1);res=f(res,node[r-1]);}
				l>>=1;r>>=1;
			}
			return res;
		}
	};
	int child_size(const auto& v,int n,int p){
		int cnt=0;
		for(auto t:v[n]){
			if(t!=p)cnt+=child_size(v,t,n);
		}
		return sz[n]=cnt+1;
	}
	void make(const auto& v,int root){
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
	lazy_segment_tree* seg;
	public:
	HLD_lazy(const graph& v,int root=0){
		make(v,root);
		seg=new lazy_segment_tree(v.size());
	}
	HLD_lazy(const graph& v,const auto& a,int root=0){
		vector<T>tmp(v.size());
		make(v,root);
		for(int i=0;i<(int)v.size();i++){
			tmp[vertex[i]]=a[i];
		}
		seg=new lazy_segment_tree(tmp);
	}
	int lca(auto l,auto r){
		while(1){
			if(head[l]==head[r])return sz[l]>sz[r]?l:r;
			else if(sz[head[l]]>sz[head[r]])r=par[r];
			else l=par[l];
		}
	}
	inline void update_vertex(auto u,E x){
		seg->update(vertex[u],vertex[u],x);
	}
	inline T get_vertex(auto u){
		return seg->get(vertex[u],vertex[u]);
	}
	inline void update_subtree(auto u,E x){
		seg->update(vertex[u],vertex[u]+sz[u]-1);
	}
	inline T get_subtree(auto u){
		return seg->get(vertex[u],vertex[u]+sz[u]-1);
	}
	void update_path(auto u,auto v,E x){
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
	T get_path(auto u,auto v){
		T res=et;
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
	protected:
	constexpr static T et=0;
	constexpr static E ee=0;
	constexpr static
	T f(const T& a,const T& b){
		return a+b;
	}
	constexpr static
	T h(const T& a,const E& b,const auto& sz){
		return a+b*sz;
	}
	constexpr static
	E g(const E& a,const E& b){
		return a+b;
	}
	constexpr static
	auto update(auto a,auto b){return b==ee?a:b;}
};