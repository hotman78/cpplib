template<typename T,typename E>
class AVL_map{
	struct node;
	using np=node*;
    struct node{
        T key;E val;E cal;
        int cnt=1;
        int dep=0;
        np ch[2]={nullptr,nullptr};
        node(T key,E val):key(key),val(val){}
    };
    bool is_multi=true;
    np root=nullptr;
    inline int count(np t){return t?t->cnt:0;}
    inline int depth(np t){return t?t->dep:0;}
    inline E calc(np t){return t?t->cal:e;}
    inline np update(np& t,bool f=1){
		if(!t)return t;
        t->cnt=count(t->ch[0])+1+count(t->ch[1]);
        t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
        t->cal=e;
        if(t->ch[0])t->cal=func(t->cal,t->ch[0]->val);
        t->cal=func(t->cal,t->val);
        if(t->ch[1])t->cal=func(t->cal,t->ch[1]->val);
        if(f&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
			rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
		}
        return t;
    }
    E e=0;
    E func(E s,E t){
        return s+t;
    }
    public:
	AVL_map(){}
    AVL_map(bool f){is_multi=f;}
    inline void insert(T key,E val){insert(key,val,root);}
    inline void erase(T key){erase(key,root);}
    inline int lower_bound(T key){return lower_bound(key,root);}
	inline int upper_bound(T key){return upper_bound(key,root);}
    inline int count(T key){return upper_bound(key,root)-lower_bound(key,root);}
	inline int size(){return count(root);}
	inline T find_by_order(int idx){assert(0<=idx&&idx<size());return find_by_order(idx,root);}
	inline T operator[](int idx){return find_by_order(idx);}
    inline void allow_multi(bool f){is_multi=f;}
    inline E get_sum_by_order(int l,int r){return get_sum_by_order(l,r,-1,root);}
    inline E get_sum(lint l,lint r){return get_sum(l,r,-1,root);}
    private:
    E get_sum(T l,T r,int p,np t){
        if(!t)return e;
        bool f=l<=t->key&&t->key<r;
        if(r<=t->key)return get_sum(l,r,-1,t->ch[0]);
        if(l>t->key)return get_sum(l,r,-1,t->ch[1]);
        E l_val=(f&&p==1)?calc(t->ch[0]):get_sum(l,r,0,t->ch[0]);
        E r_val=(f&&p==0)?calc(t->ch[1]):get_sum(l,r,1,t->ch[1]);
        return func(func(l_val,f?t->val:e),r_val);
    }
    E get_sum_by_order(int l,int r,int p,np t){
        if(!t)return e;
        int idx=count(t->ch[0]);
        bool f=l<=idx&&idx<r;
        if(r<=idx)return get_sum_by_order(l,r,-1,t->ch[0]);
        if(l>idx)return get_sum_by_order(l-idx-1,r-idx-1,-1,t->ch[1]);
        E l_val=(f&&p==1)?calc(t->ch[0]):get_sum_by_order(l,r,0,t->ch[0]);
        E r_val=(f&&p==0)?calc(t->ch[1]):get_sum_by_order(l-idx-1,r-idx-1,1,t->ch[1]);
        return func(func(l_val,f?t->val:e),r_val);
    }
    void insert(T key,E val,np& t){
        if(!t)t=new node(key,val);
        else if(key<=t->key)insert(key,val,t->ch[0]);
        else if(key>t->key)insert(key,val,t->ch[1]);
        update(t);
    }
    void erase(T key,np& t){
        if(!t)return;
        else if(key==t->key){
			if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];
			else move_down(t->ch[0],t);
		}
        else if(key<t->key)erase(key,t->ch[0]);
        else if(key>t->key)erase(key,t->ch[1]);
		update(t);
    }
	void move_down(np& t,np& p){
		if(t->ch[1])move_down(t->ch[1],p);
		else p->key=t->key,t=t->ch[0];
		update(t);
	}
    int lower_bound(T key,np t){
        if(!t)return 0;
        if(key<=t->key)return lower_bound(key,t->ch[0]);
        else return count(t->ch[0])+1+lower_bound(key,t->ch[1]);
    }
	int upper_bound(T key,np t){
        if(!t)return 0;
        if(key<t->key)return upper_bound(key,t->ch[0]);
        else return count(t->ch[0])+1+upper_bound(key,t->ch[1]);
    }
	E find_by_order(int idx,np t){
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


// template<typename T,typename E>
// class AVL_map{
// 	struct node;
// 	using np=node*;
//     struct node{
//         T key;E val;E cal;
//         int cnt=1;
//         int dep=0;
//         np ch[2]={nullptr,nullptr};
//         node(T key,E val):key(key),val(val){}
//     };
//     bool is_multi=true;
//     np root=nullptr;
//     inline int count(np t){return t?t->cnt:0;}
//     inline int depth(np t){return t?t->dep:0;}
//     inline E calc(np t){return t?t->cal:e;}
//     inline np update(np& t,bool f=1){
// 		if(!t)return t;
//         t->cnt=count(t->ch[0])+1+count(t->ch[1]);
//         t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
//         if(func){
//             t->cal=e;
//             if(t->ch[0])t->cal=func(t->cal,t->ch[0]->val);
//             t->cal=func(t->cal,t->val);
//             if(t->ch[1])t->cal=func(t->cal,t->ch[1]->val);
//         }
//         if(f&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
// 			rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
// 		}
//         return t;
//     }
//     using F=function<E(E,E)>;
//     F func;E e;
//     public:
// 	AVL_map(){}
//     AVL_map(bool f){is_multi=f;}
//     AVL_map(F f,E e):func(f),e(e){}
//     inline void insert(T key,E val){insert(key,val,root);}
//     inline void erase(T key){erase(key,root);}
//     inline int lower_bound(T key){return lower_bound(key,root);}
// 	inline int upper_bound(T key){return upper_bound(key,root);}
//     inline int count(T key){return upper_bound(key,root)-lower_bound(key,root);}
// 	inline int size(){return count(root);}
// 	inline T find_by_order(int idx){assert(0<=idx&&idx<size());return find_by_order(idx,root);}
// 	inline T operator[](int idx){return find_by_order(idx);}
//     inline void allow_multi(bool f){is_multi=f;}
//     inline E get_sum_by_order(int l,int r){return get_sum_by_order(l,r,-1,root);}
//     inline E get_sum(int l,int r){return get_sum(l,r,-1,root);}
//     private:
//     E get_sum(T l,T r,int p,np t){
//         if(!t)return e;
//         bool f=l<=t->key&&t->key<r;
//         if(r<=t->key)return get_sum(l,r,-1,t->ch[0]);
//         if(l>t->key)return get_sum(l,r,-1,t->ch[1]);
//         E l_val=(f&&p==1)?calc(t->ch[0]):get_sum(l,r,0,t->ch[0]);
//         E r_val=(f&&p==0)?calc(t->ch[1]):get_sum(l,r,1,t->ch[1]);
//         return func(func(l_val,f?t->val:e),r_val);
//     }
//     E get_sum_by_order(int l,int r,int p,np t){
//         if(!t)return e;
//         int idx=count(t->ch[0]);
//         bool f=l<=idx&&idx<r;
//         if(r<=idx)return get_sum_by_order(l,r,-1,t->ch[0]);
//         if(l>idx)return get_sum_by_order(l-idx-1,r-idx-1,-1,t->ch[1]);
//         E l_val=(f&&p==1)?calc(t->ch[0]):get_sum_by_order(l,r,0,t->ch[0]);
//         E r_val=(f&&p==0)?calc(t->ch[1]):get_sum_by_order(l-idx-1,r-idx-1,1,t->ch[1]);
//         return func(func(l_val,f?t->val:e),r_val);
//     }
//     void insert(T key,E val,np& t){
//         if(!t)t=new node(key,val);
//         else if(!is_multi&&key==t->key)return;
//         else if(key<=t->key)insert(key,val,t->ch[0]);
//         else if(key>t->key)insert(key,val,t->ch[1]);
//         update(t);
//     }
//     void erase(T key,np& t){
//         if(!t)return;
//         else if(key==t->key){
// 			if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];
// 			else move_down(t->ch[0],t);
// 		}
//         else if(key<t->key)erase(key,t->ch[0]);
//         else if(key>t->key)erase(key,t->ch[1]);
// 		update(t);
//     }
// 	void move_down(np& t,np& p){
// 		if(t->ch[1])move_down(t->ch[1],p);
// 		else p->key=t->key,t=t->ch[0];
// 		update(t);
// 	}
//     int lower_bound(T key,np t){
//         if(!t)return 0;
//         if(key<=t->key)return lower_bound(key,t->ch[0]);
//         else return count(t->ch[0])+1+lower_bound(key,t->ch[1]);
//     }
// 	int upper_bound(T key,np t){
//         if(!t)return 0;
//         if(key<t->key)return upper_bound(key,t->ch[0]);
//         else return count(t->ch[0])+1+upper_bound(key,t->ch[1]);
//     }
// 	E find_by_order(int idx,np t){
// 		if(idx==count(t->ch[0]))return t->val;
// 		else if(idx<count(t->ch[0]))return find_by_order(idx,t->ch[0]);
// 		else return find_by_order(idx-count(t->ch[0])-1,t->ch[1]);
// 	}
// 	np rot(np t){
// 		int b=depth(t->ch[0])<depth(t->ch[1]);
// 		if(depth(t->ch[0])==depth(t->ch[1]))return t;
// 		np s=t->ch[b];
// 		t->ch[b]=s->ch[1-b];
// 		s->ch[1-b]=t;
// 		update(t,0);update(s,0);
// 		return s;
// 	}
//     void rebuild(np& t,int b){
// 		if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){
// 			t->ch[b]=rot(t->ch[b]);
// 		}
// 		t=rot(update(t,0));
//     }
// };
