template<typename T>
class AVL_array{
	struct node;
	using np=node*;
    struct node{
        T val;T fold;
        int cnt=1;
        int dep=0;
        np ch[2]={nullptr,nullptr};
        node(T val):val(val){}
    };
    template<typename Getter>
    class iterator{
        int i;
        Getter getter;
        public:
        iterator(const int& i,const Getter& getter):i(i),getter(getter){}
        inline constexpr auto operator*()noexcept{return getter(i);}
        inline constexpr iterator operator++()noexcept{++i;return *this;}
        inline constexpr iterator operator--()noexcept{--i;return *this;}
        inline constexpr iterator operator++(int n)noexcept{++i;return *this;}
        inline constexpr iterator operator--(int n)noexcept{--i;return *this;}
        inline constexpr iterator operator+=(const int& rhs)noexcept{i+=rhs;return *this;}
        inline constexpr iterator operator-=(const int& rhs)noexcept{i-=rhs;return *this;}
        inline constexpr iterator operator+(const int& rhs)const noexcept{return iterator(*this)+=rhs;}
        inline constexpr iterator operator-(const int& rhs)const noexcept{return iterator(*this)-=rhs;}
        inline constexpr bool operator!=(const iterator& rhs)const noexcept{return i!=rhs.i;}
        inline constexpr bool operator==(const iterator& rhs)const noexcept{return i==rhs.i;}
    };
    inline auto make_iterator(const int& i)noexcept{
        static auto getter=[this](int i){return find_by_order(i);};
        return iterator<decltype(getter)>(i,getter);
    }
    np root=nullptr;
    inline int count(np t){return t?t->cnt:0;}
    inline int depth(np t){return t?t->dep:0;}
    inline T get_fold(np t){return t?t->fold:e;}
    inline np update(np& t,bool b=1){
		if(!t)return t;
        t->cnt=count(t->ch[0])+1+count(t->ch[1]);
        t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
        t->fold=f(f(get_fold(t->ch[0]),t->val),get_fold(t->ch[1]));
        if(b&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
			rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
		}
        return t;
    }
    public:
	AVL_array(){}
    AVL_array(auto n){
        for(int i=0;i<n;i++)insert(i,T());
    }
    AVL_array(auto n,T e){
        for(int i=0;i<n;i++)insert(i,e);
    }
    inline void push_back(T val){insert(size(),val,root);}
    inline void insert(auto pos,T val){assert(0<=pos&&pos<=size());insert(pos,val,root);}
    inline void erase(auto pos){assert(0<=pos&&pos<=size());erase(pos,root);}
    inline T get_fold(auto l,auto r){assert(0<=l&&l<=r&&r<=size());return get_fold(root,l,r);}
	inline int size(){return count(root);}
	inline T& find_by_order(int idx){assert(0<=idx&&idx<size());return find_by_order(idx,root);}
	inline T& operator[](int idx){return find_by_order(idx);}
    inline auto begin()noexcept{return make_iterator(0);}
    inline auto end()noexcept{return make_iterator(size());}
    private:
    void insert(auto pos,T val,np& t){
        if(!t)t=new node(val);
        else if(pos<count(t->ch[0])+1)insert(pos,val,t->ch[0]);
        else insert(pos-count(t->ch[0])-1,val,t->ch[1]);
        update(t);
    }
    void erase(auto pos,np& t){
        if(!t)return;
        else if(pos==count(t->ch[0])+1){
			if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];
			else move_down(t->ch[0],t);
		}
        else if(pos<count(t->ch[0])+1)erase(pos,t->ch[0]);
        else erase(pos-count(t->ch[0])-1,t->ch[1]);
		update(t);
    }
    T get_fold(np& t,auto l,auto r){
        np x,y,z;
        tie(x,y,z)=split_by_order(t,l,r);
        T res;
        if(y)res=y->fold;
        else res=e;
        t=merge(x,y,z);
        return res;
    }
	void move_down(np& t,np& p){
		if(t->ch[1])move_down(t->ch[1],p);
		else p->val=t->val,t=t->ch[0];
		update(t);
	}
    int lower_bound(T val,np t){
        if(!t)return 0;
        if(val<=t->val)return lower_bound(val,t->ch[0]);
        else return count(t->ch[0])+1+lower_bound(val,t->ch[1]);
    }
	int upper_bound(T val,np t){
        if(!t)return 0;
        if(val<t->val)return upper_bound(val,t->ch[0]);
        else return count(t->ch[0])+1+upper_bound(val,t->ch[1]);
    }
	T& find_by_order(int idx,np t){
		if(idx==count(t->ch[0]))return t->val;
		else if(idx<count(t->ch[0]))return find_by_order(idx,t->ch[0]);
		else return find_by_order(idx-count(t->ch[0])-1,t->ch[1]);
	}
    inline np merge(np& p,np& q,np& r){
        return merge(p,merge(q,r));
    }
    np merge(np l,np r){
        if(!l||!r)return !l?r:l;
        if(depth(l)>depth(r)){
            l->ch[1]=merge(l->ch[1],r);
            return update(l);
        }else{
            r->ch[0]=merge(l,r->ch[0]);
            return update(r);
        }
    }
    //0-indexed [-INF,l),[l,r),[r,INF)
    tuple<np,np,np> split_by_order(np t,int l,int r){
        auto p=split_by_order(t,l);
        auto q=split_by_order(p.second,r-l);
        return make_tuple(p.first,q.first,q.second);
    }
    //0-indexed [-INF,k),[k,INF)
    inline pair<np,np> split_by_order(np t,int k){
        if(!t)return make_pair(nullptr,nullptr);
        bool b=k>count(t->ch[0]);
        auto s=split_by_order(t->ch[b],k-(b?(count(t->ch[0])+1):0));
        t->ch[b]=b?s.first:s.second;
        return b?make_pair(update(t),s.second):make_pair(s.first,update(t));
    }
	np rot(np t){
		int b=depth(t->ch[0])<depth(t->ch[1]);
		if(depth(t->ch[0])==depth(t->ch[1]))return t;
		np s=t->ch[b];
		t->ch[b]=s->ch[1-b];
		s->ch[1-b]=t;
		update(t,0);update(s,0);
		return s;
	}
    void rebuild(np& t,int b){
		if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){
			t->ch[b]=rot(t->ch[b]);
		}
		t=rot(update(t,0));
    }
    const T e=0;
    T f(const T& s,const T& t){
        return s+t;
    }
};

//機能縮小版
template<typename T,typename F>
class avl_array{
	struct node;
	using np=node*;
    struct node{
        T val,sum;
        int cnt=1;
        int dep=0;
        np ch[2]={nullptr,nullptr};
        node(T val):val(val),sum(val){}
    };
    T e;
    F fn;
    np root=nullptr;
    inline int count(np t){return t?t->cnt:0;}
    inline int depth(np t){return t?t->dep:0;}
    inline T sum(np t){return t?t->sum:e;}
    np update(np t,bool f=1){
		if(!t)return t;
        t->cnt=count(t->ch[0])+1+count(t->ch[1]);
        t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
        t->sum=fn(fn(sum(t->ch[0]),t->val),sum(t->ch[1]));
        if(f&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
			t=rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
		}
        return t;
    }
    np rebuild(np t,int b){
		if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){
			t->ch[b]=rot(t->ch[b]);
		}
		return rot(t);
    }
    np rot(np t){
        if(depth(t->ch[0])==depth(t->ch[1]))return t;
        bool b=depth(t->ch[0])>depth(t->ch[1]);
        tie(t->ch[1-b]->ch[b],t->ch[1-b],t) = make_tuple(t,t->ch[1-b]->ch[b],t->ch[1-b]);
        if(t->ch[b])update(t->ch[b],0);
        return update(t,0);
    }
    np insert(int idx,T val,np t){
        if(!t)return new node(val);
        bool b=idx>count(t->ch[0]);
        t->ch[b]=insert(b?idx-count(t->ch[0])-1:idx,val,t->ch[b]);
        return update(t);
    }
    np erase(int idx,np t){
        if(idx==count(t->ch[0])){
            if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];
			else t->ch[0]=move_down(t->ch[0],t);
        }else{
            bool b=idx>count(t->ch[0]);
            t->ch[b]=erase(b?idx-count(t->ch[0])-1:idx,t->ch[b]);
        }
        return update(t);
    }
    np move_down(np t,np p){
		if(t->ch[1])t->ch[1]=move_down(t->ch[1],p);
		else p->val=t->val,t=t->ch[0];
		return update(t);
	}
    int lower_bound(T val,T l,np t){
        if(!t)return 0;
        T tmp=fn(fn(l,sum(t->ch[0])),t->val);
        bool b=tmp<val;
        if(b) return count(t->ch[0])+1+lower_bound(val,tmp,t->ch[1]);
        else return lower_bound(val,l,t->ch[0]);
    }
    public:
    avl_array(T e,F fn):e(e),fn(fn){}
    void insert(int idx,T val){root=insert(idx,val,root);}
    void erase(int idx){root=erase(idx,root);}
    int lower_bound(T val){return lower_bound(val,e,root);}
    int size(){return count(root);}
};