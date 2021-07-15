template<typename T>
class dual_segment{
	struct node;
	using np=node*;
	using lint=long long;
	struct node{
		T val;
		np ch[2]={nullptr,nullptr};
		node(T val):val(val){}
	};
	np root=nullptr;
	lint n=1,sz;
	public:
	dual_segment(lint sz):sz(sz){while(n<sz)n<<=1;}
	inline void set(lint l,lint r,T x){set(l,r,x,0,n,root);}
	inline T get(lint x){return get(x,0,n,root);}
	private:
	void eval(np& t){
		if(t->val==e)return;
		if(!t->ch[0])t->ch[0]=new node(e);
		if(!t->ch[1])t->ch[1]=new node(e);
		t->ch[0]->val=f(t->ch[0]->val,t->val);
		t->ch[1]->val=f(t->ch[1]->val,t->val);
		t->val=e;
	}
	void set(lint a,lint b,T x,lint l,lint r,np& t){
        if(!t)t=new node(e);
		if(r-l>1)eval(t);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b)t->val=f(t->val,x);
	    else if(r-l>1){
			set(a,b,x,l,(l+r)/2,t->ch[0]);
			set(a,b,x,(l+r)/2,r,t->ch[1]);
		}
	}
	T get(lint x,lint l,lint r,np& t){
        if(!t)t=new node(e);
		if(r-l>1)eval(t);
		if(x<l||r<=x)return e;
        else if(r-l==1){
            return t->val;
        }
		else return f(get(x,l,(l+r)/2,t->ch[0]),get(x,(l+r)/2,r,t->ch[1]));
	}
    T e=0;
    T f(T s,T t){
        return s+t;
    }
};

// template<typename T>
// class dual_segment{
// 	struct node;
// 	using np=node*;
// 	using lint=long long;
// 	struct node{
// 		T val;
// 		np ch[2]={nullptr,nullptr};
// 		node(T val):val(val){}
// 	};
// 	np root=nullptr;
// 	lint n=1,sz;
// 	T e;
// 	function<T(T,T)>f;
// 	public:
// 	dual_segment(lint sz,T e,function<T(T,T)>f):sz(sz),e(e),f(f){while(n<sz)n<<=1;}
// 	inline void set(lint l,lint r,T x){set(l,r,x,-n,n,root);}
// 	inline T get(lint x){return get(x,-n,n,root);}
// 	private:
// 	void eval(np& t){
// 		if(t->val==e)return;
// 		if(!t->ch[0])t->ch[0]=new node(e);
// 		if(!t->ch[1])t->ch[1]=new node(e);
// 		t->ch[0]->val=f(t->ch[0]->val,t->val);
// 		t->ch[1]->val=f(t->ch[1]->val,t->val);
// 		t->val=e;
// 	}
// 	void set(lint a,lint b,T x,lint l,lint r,np& t){
//         if(!t)t=new node(e);
// 		if(r-l>1)eval(t);
// 		if(r<=a||b<=l)return;
// 		else if(a<=l&&r<=b)t->val=f(t->val,x);
// 	    else if(r-l>1){
// 			set(a,b,x,l,(l+r)/2,t->ch[0]);
// 			set(a,b,x,(l+r)/2,r,t->ch[1]);
// 		}
// 	}
// 	T get(lint x,lint l,lint r,np& t){
//         if(!t)t=new node(e);
// 		if(r-l>1)eval(t);
// 		if(x<l||r<=x)return e;
//         else if(r-l==1){
//             return t->val;
//         }
// 		else return f(get(x,l,(l+r)/2,t->ch[0]),get(x,(l+r)/2,r,t->ch[1]));
// 	}
// };