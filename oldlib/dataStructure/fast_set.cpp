template<typename T>
struct fast_set{
	constexpr static int B=4;
    constexpr static int S=(1<<B);
	struct node{
		T val=0;
        bool b=0;
		node* ch[1<<B];
        static int node_count;
        void *operator new(std::size_t){
            static node pool[10'000'000];
            return pool + node_count++;
        }
        node(){fill(ch,ch+S,nullptr);}
	};
	using np=node*;
	np root=0,root2=0;
	inline T& operator[](int64_t k){
        return get(abs(k),k>0?root:root2);
    }
    inline bool count(int64_t k){
        return count(abs(k),k>0?root:root2);
    }
    inline vector<pair<int64_t,T>> out(){
        vector<pair<int64_t,T>>v;
        out(v,root2,0,-1,0);
        out(v,root,0,1,0);
        sort(v.begin(),v.end());
        return v;
    }
	T& get(int64_t k,np& t){
		if(!t)t=new node();
		if(!k){
            t->b=1;
            return t->val;
        }
		return get(k>>B,t->ch[k&(S-1)]);
	}
    bool count(int64_t k,np& t){
        if(!t)return 0;
        if(!k)return t->b;
        else return count(k>>B,t->ch[k&(S-1)]);
    }
    void out(vector<pair<int64_t,T>>&v,np& t,int64_t k,int f,int b){
        if(!t)return;
        if(t->b)v.emplace_back(k*f,t->val);
        for(int i=0;i<S;++i){
            out(v,t->ch[i],k+(i<<(B*b)),f,b+1);
        }
    }
};
template<typename T>int fast_set<T>::node::node_count = 0;

template<typename T>
struct fast_set{
	constexpr static int B=4;
	struct node{
		T val=0;
		node** ch=new node*[1<<B]();
	};
	using np=node*;
	np root=0;
	T& operator[](int64_t k){return get(k,root);}
	T& get(int64_t k,np& t){
		if(!t)t=new node();
		if(!k)return t->val;
		return get(k>>B,t->ch[k&((1<<B)-1)]);
	}
};