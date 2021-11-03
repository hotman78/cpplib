template<typename T,typename E>
class euler_tour_tree{
	public:
    struct node;
    using np=node*;
	using lint=long long;
    struct node{
        np ch[2]={nullptr,nullptr};
        np p=nullptr;
        int l,r,sz=1,sz2=0;
		T val=et,sum=et;
        E lazy=ee;
        node(){}
        node(int l,int r,int sz2):l(l),r(r),sz2(sz2){}
        bool is_root() {
            return !p;
        }
    };
	vector<hash_map<int,np>>ptr;
	np get_node(int l,int r){
        if(ptr[l].find(r)==ptr[l].end())ptr[l][r]=new node(l,r,l==r);
        return ptr[l][r];
    }
	np root(np t){
		if(!t)return t;
        while(t->p)t=t->p;
        return t;
    }
	bool same(np s,np t){
		return root(s)==root(t);
	}
	bool same(int s,int t){
		return root(get_node(s,s))==root(get_node(t,t));
	}
	np reroot(np t){
        auto s=split(t);
        return merge(s.second,s.first);
    }
	pair<np,np> split(np s){
		splay(s);
		np t=s->ch[0];
		if(t)t->p=nullptr;
		s->ch[0]=nullptr;
		return {t,update(s)};
	}
	pair<np,np> split2(np s){
		splay(s);
		np t=s->ch[0];
		np u=s->ch[1];
		if(t)t->p=nullptr;
		s->ch[0]=nullptr;
		if(u)u->p=nullptr;
		s->ch[1]=nullptr;
		return {t,u};
	}
	tuple<np,np,np> split(np s,np t){
		auto u=split2(s);
		if(same(u.first,t)){
			auto r=split2(t);
			return {r.first,r.second,u.second};
		}else{
			auto r=split2(t);
			return {u.first,r.first,r.second};
		}
	}
	template<typename First, typename... Rest>
	np merge(First s,Rest... t){
		return merge(s,merge(t...));
	}
	np merge(np s,np t){
		while(s->ch[1])s=s->ch[1];
		splay(s);
		s->ch[1]=t;
		if(t)t->p=s;
		return update(s);
	}
    int size(np t){return t?t->sz:0;}
    int size2(np t){return t?t->sz2:0;}
    np update(np t){
        t->sz=size(t->ch[0])+1+size(t->ch[1]);
        t->sz2=size2(t->ch[0])+(t->l==t->r)+size2(t->ch[1]);
		t->sum=et;
		if(t->ch[0])t->sum=fn(t->sum,t->ch[0]->sum);
		if(t->l==t->r)t->sum=fn(t->sum,t->val);
		if(t->ch[1])t->sum=fn(t->sum,t->ch[1]->sum);
		return t;
    }
	void push(np t){
        if(t->lazy!=ee){
            if(t->ch[0])propagate(t->ch[0],t->lazy);
            if(t->ch[1])propagate(t->ch[1],t->lazy);
            t->lazy=ee;
        }
    }
    void propagate(np t,E x){
        t->lazy=g(t->lazy,x);
        t->val=h(t->val,x,1);
        t->sum=h(t->sum,x,t->sz2);
    }
    void set_propagate(np t,E x){
        splay(t);
        propagate(t,x);
        push(t);
    }
    void rot(np t,bool b){
        np x=t->p,y=x->p;
        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;
        t->ch[b]=x,x->p=t;
        update(x);update(t);
        if((t->p=y)){
            if(y->ch[0]==x)y->ch[0]=t;
            if(y->ch[1]==x)y->ch[1]=t;
            update(y);
        }
    }
    void splay(np t){
        push(t);
        while(!t->is_root()){
            np q=t->p;
            if(q->is_root()){
                push(q),push(t);
                rot(t,q->ch[0]==t);
            }else{
                np r=q->p;
                push(r), push(q), push(t);
                bool b=r->ch[0]==q;
                if(q->ch[1-b]==t)rot(q,b),rot(t,b);
                else rot(t,1-b),rot(t,b);
            }
        }
    }
	void debug(np t){
		if(!t)return;
		debug(t->ch[0]);
		cerr<<t->l<<"-"<<t->r<<" ";
		debug(t->ch[1]);
	}
	constexpr static T et=0;
    constexpr static T ee=0;
	constexpr static T fn(T s,T t){
		return s+t;
	}
    constexpr static E g(E s,E t){
		return s+t;
	}
    constexpr static T h(T s,E t,int sz){
		return s+t*sz;
	}
	public:
    void reroot(int s){
        reroot(get_node(s,s));
    }
	void update(int s,T x){
		np t=get_node(s,s);
		splay(t);
		t->val=fn(t->val,x);
		update(t);
	}
    void update_subtree(int p,int v,E x){
        cut(p,v);
		np t=get_node(v,v);
		set_propagate(t,x);
		link(p,v);
    }
	euler_tour_tree(int sz){
		ptr.resize(sz);
		for(int i=0;i<sz;i++)ptr[i][i]=new node(i,i,1);
	}
	bool link(int l,int r){
        if(same(l,r))return 0;
        merge(reroot(get_node(l,l)),get_node(l,r),reroot(get_node(r,r)),get_node(r,l));
        return 1;
    }
	bool cut(int l,int r){
        if(ptr[l].find(r)==ptr[l].end())return 0;
        np s,t,u;
        tie(s,t,u)=split(get_node(l,r),get_node(r,l));
        merge(s,u);
        ptr[l].erase(r);
        ptr[r].erase(l);
        return 1;
    }
	T get_sum(int p,int v){
		cut(p,v);
		np t=get_node(v,v);
		splay(t);
		T res=t->sum;
		link(p,v);
		return res;
	}
};