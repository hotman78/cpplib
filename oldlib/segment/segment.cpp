template<typename T>
class segment{
	T* node;
	int n=1;
	public:
	segment(int sz){
		while(n<=sz)n<<=1;
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
		l+=n;r+=n;
		T s=e,t=e;
		while(l<r){
			if(l&1)s=f(s,node[l++-1]);
			if(r&1)t=f(node[--r-1],t);
			l>>=1;r>>=1;
		}
		return f(s,t);
	}
    void change(auto t,T val){
		t+=n-1;
        node[t]=val;
		while(t){
			t=(t-1)>>1;
            node[t]=f(node[t*2+1],node[t*2+2]);
		}
	}
	void update(auto t,T val){
		t+=n-1;
        node[t]=f(node[t],val);
		while(t){
			t=(t-1)>>1;
            node[t]=f(node[t*2+1],node[t*2+2]);
		}
	}
	T e={1,0};
	T f(const T& s,const T& t){
		return {s.first*t.first,s.second*t.first+t.second};
	}
};
