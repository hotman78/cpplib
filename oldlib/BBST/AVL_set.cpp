template<typename T>
class AVL_set{
	struct node;
	using np=node*;
    struct node{
        T val;
        int cnt=1;
        int dep=0;
        np ch[2]={nullptr,nullptr};
        node(T val):val(val){}
    };
    np root=nullptr;
    inline int count(np t){return t?t->cnt:0;}
    inline int depth(np t){return t?t->dep:0;}
    inline np update(np& t,bool f=1){
		if(!t)return t;
        t->cnt=count(t->ch[0])+1+count(t->ch[1]);
        t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
        if(f&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
			rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
		}
        return t;
    }
    public:
	AVL_set(){}
    inline void insert(T val){insert(val,root);}
    inline void erase(T val){erase(val,root);}
    inline int lower_bound(T val){return lower_bound(val,root);}
	inline int upper_bound(T val){return upper_bound(val,root);}
    inline int count(T val){return upper_bound(val,root)-lower_bound(val,root);}
	inline int size(){return count(root);}
	inline T find_by_order(int idx){assert(0<=idx&&idx<size());return find_by_order(idx,root);}
	inline T operator[](int idx){return find_by_order(idx);}
    private:
    void insert(T val,np& t){
        if(!t)t=new node(val);
        else if(val<=t->val)insert(val,t->ch[0]);
        else if(val>t->val)insert(val,t->ch[1]);
        update(t);
    }
    void erase(T val,np& t){
        if(!t)return;
        else if(val==t->val){
			if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];
			else move_down(t->ch[0],t);
		}
        else if(val<t->val)erase(val,t->ch[0]);
        else if(val>t->val)erase(val,t->ch[1]);
		update(t);
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
	T find_by_order(int idx,np t){
		if(idx==count(t->ch[0]))return t->val;
		else if(idx<count(t->ch[0]))return find_by_order(idx,t->ch[0]);
		else return find_by_order(idx-count(t->ch[0])-1,t->ch[1]);
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
};