class dynamic_connectivity{
	class union_find{
		vector<int>data;
		stack<pair<int,int>>hist;
		stack<int>hist_size;
		int size;
		public:
		union_find(){}
		union_find(int n){
			resize(n);
		}
		inline void resize(int n){
			data.resize(n,-1);
			size=n;
		}
		inline bool unite(int s,int t){
			s=find(s);t=find(t);
			hist.emplace(s,data[s]);
			hist.emplace(t,data[t]);
			hist_size.push(size);
			if(s==t)return false;
			size--;
			if(data[s]>data[t])swap(s,t);
			data[s]+=data[t];
			data[t]=s;
			return true;
		}
		inline void undo(){
			size=hist_size.top();
			hist_size.pop();
			for(int i=0;i<2;i++){
				auto x=hist.top();
				data[x.first]=x.second;
				hist.pop();
			}
		}
		inline bool same(int s,int t){
			return find(s)==find(t);
		}
		inline int get_size(){
			return size;
		}
		private:
		inline int find(int x){
			while(data[x]>=0)x=data[x];
			return x;
		}
	};
	union_find uf;
	vector<vector<pair<int,int>>>node;
	map<pair<int,int>,int>left;
	vector<vector<pair<int,int>>>que;
	int n,q,sz=1,cnt=0;
	public:
	dynamic_connectivity(int n,int q):n(n),q(q){
		uf.resize(n);
		while(sz<q)sz<<=1;
		que.resize(sz+1);
		node.resize(2*sz-1);
	}
 
	inline void unite(int s,int t){
		if(!left.count(minmax(s,t)))left[minmax(s,t)]=cnt;
		cnt++;
	}
	inline void erase(int s,int t){
		if(left.count(minmax(s,t))){
			add_node(left[minmax(s,t)],cnt,minmax(s,t));
			left.erase(minmax(s,t));
		}
		cnt++;
	}
	inline void query(int s,int t){
		que[cnt].emplace_back(s,t);
	}
	inline void size_query(){
		que[cnt].emplace_back(-1,-1);
	}
	inline vector<int> answer(){
		for(auto d:left){
			add_node(d.second,cnt,d.first);
		}
		vector<int> res;
		for(auto d:que[0]){
			if(d.first==-1&&d.second==-1){
				res.push_back(n);
			}else{
				res.push_back(0);
			}
		}
		__answer(res,0);
		return res;
	}
	private:
	inline void __answer(vector<int>& res,int t){
		for(auto x:node[t]){
			uf.unite(x.first,x.second);
		}
		if(t<sz-1){
			__answer(res,2*t+1);
			__answer(res,2*t+2);
		}else{
			for(auto d:que[t-sz+2]){
				if(d.first==-1&&d.second==-1){
					res.push_back(uf.get_size());
				}else{
					res.push_back(uf.same(d.first,d.second));
				}
			}
		}
		for(int i=0;i<(int)node[t].size();i++)uf.undo();
	}
	inline void add_node(int l,int r,pair<int,int>v){
		l+=sz;
		r+=sz;
		while(l<r){
			if(r&1){
				r-=1;
				node[r-1].push_back(v);
			}
			if(l&1){
				node[l-1].push_back(v);
				l+=1;
			}
			l>>=1;r>>=1;
		}
	}
};