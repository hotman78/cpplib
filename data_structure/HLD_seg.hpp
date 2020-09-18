template<typename T>
class HLD_seg{
	class segment{
		T* node;
		int n=1;
		public:
		segment(int sz){
			while(n<sz)n<<=1;
			node=new T[(n<<1)-1];
			for(int i=0;i<(n<<1)-1;i++)node[i]=e;
		}
		segment(const vector<T>& v){
			while(n<(int)v.size())n<<=1;
			node=new T[(n<<1)-1];
			for(int i=0;i<(int)v.size();i++)node[i+n-1]=v[i];
        	for(int i=n-2;i>=0;i--)node[i]=f(node[(i<<1)+1],node[(i<<1)+2]);
		}
		T get(auto l,auto r){
			if(l>r)swap(l,r);
			l+=n;r+=n+1;
			T s=e;
			while(l<r){
				if(l&1)s=f(s,node[l++-1]);
				if(r&1)s=f(s,node[--r-1]);
				l>>=1;r>>=1;
			}
			return s;
		}
		void update(auto t,T val){
			t+=n-1;
			while(1){
				node[t]=f(node[t],val);
				t=(t-1)>>1;
				if(!t)break;
			}
		}
	};
	int child_size(const auto& v,int n,int p){
		int cnt=0;
		for(auto t:v[n]){
			if(t!=p)cnt+=child_size(v,t,n);
		}
		return sz[n]=cnt+1;
	}
	void make_hld(const auto&v,int n,int p){
		static int idx=0;
		vertex[n]=idx++;
		int mx=0,heavy=-1;
		for(auto t:v[n])if(t!=p&&mx<sz[t]){
			mx=sz[t];
			heavy=t;
		}
		if(heavy!=-1){
			par[heavy]=par[n];
			head[heavy]=head[n];
			make_hld(v,heavy,n);
		}
		for(auto t:v[n]){
			if(t!=heavy&&t!=p){
				par[t]=n;
				head[t]=t;
				make_hld(v,t,n);
			}
		}
	}
	int* sz;
	int* vertex;
	int* par;
	int* head;
	segment* seg;
	public:
	HLD_seg(const auto& v,int root=0){
		make(v,root);
		seg=new segment(v.size());
	}
	HLD_seg(const auto& v,const auto& a,int root=0){
		make(v,root);
		vector<T>tmp(v.size());
		for(int i=0;i<(int)v.size();i++){
			tmp[vertex[i]]=a[i];
		}
		seg=new segment(tmp);
	}
	void make(const auto& v,int root){
		sz=new int[v.size()];
		vertex=new int[v.size()];
		par=new int[v.size()];
		head=new int[v.size()];
		child_size(v,root,-1);
		par[root]=root;
		head[root]=root;
		make_hld(v,root,-1);
	}
	int lca(auto l,auto r){
		while(head[l]!=head[r]){
			if(sz[head[l]]>sz[head[r]])r=par[r];
			else l=par[l];
		}
		return sz[l]>sz[r]?l:r;
	}
	inline void update(auto t,T x){
		seg->update(vertex[t],x);
	}
	T get(auto u,auto v){
		T res=e;
		while(head[u]!=head[v]){
			if(sz[head[u]]>sz[head[v]]){
				res=f(res,seg->get(vertex[v],vertex[head[v]]));
				v=par[v];
			}
			else{
				res=f(res,seg->get(vertex[u],vertex[head[u]]));
				u=par[u];
			}
		}
		return f(res,seg->get(vertex[u],vertex[v]));
	}
	inline T get_subtree(auto u){
		return seg->get(vertex[u],vertex[u]+sz[u]-1);
	}
	protected:
	constexpr static T e=0;
	constexpr static
	T f(const T& s,const T& t){
		return s+t;
	}
};