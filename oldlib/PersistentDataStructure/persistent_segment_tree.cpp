template<typename T>
class persistent_segment_tree{
	struct node;
	using np=node*;
	using lint=long long;
	struct node{
		lint val;int cnt=0;
		np ch[2]={nullptr,nullptr};
		node(){}
		node(T val):val(val){}
		node(np n):val(n->val),cnt(n->cnt){ch[0]=n->ch[0];ch[1]=n->ch[1];}
	};
	vector<np>root{nullptr};
	lint sz=1,n;
	int count(np t){return t?t->cnt:0;}
	public:
	persistent_segment_tree(lint n):n(n){
		while(sz<n)sz<<=1;
	}
	void push_back(lint pos,T val){
		root.push_back(push_back(pos,val,root[root.size()-1],-sz,sz));
	}
	T get(lint lx,lint rx,lint ly,lint ry){
		return g(get(ly,ry,root[rx],-sz,sz),get(ly,ry,root[lx],-sz,sz));
	}
	lint get_count(lint lx,lint rx,lint ly,lint ry){
		return get_count(ly,ry,root[rx],-sz,sz)-get_count(ly,ry,root[lx],-sz,sz);
	}
	lint kth_element(lint lx,lint rx,lint k){
		return kth_element(root[rx],root[lx],k,-sz,sz);
	}
	private:
	np push_back(lint pos,T val,np t,lint l,lint r){
		if(l<=pos&&pos<r){
			np res=t?new node(t):new node(e);
			res->val=f(res->val,val);
			res->cnt++;
			if(r-l>1){
				res->ch[0]=push_back(pos,val,res->ch[0],l,(l+r)/2);
				res->ch[1]=push_back(pos,val,res->ch[1],(l+r)/2,r);
			}
			return res;
		}else{
			return t;
		}
	}
	lint get_count(lint a,lint b,np t,lint l,lint r){
		if(!t||r<=a||b<=l)return 0;
        if(a<=l&&r<=b){return t->cnt;}
        return f(get_count(a,b,t->ch[0],l,(l+r)/2),get_count(a,b,t->ch[1],(l+r)/2,r));
	}
	T get(lint a,lint b,np t,lint l,lint r){
        if(!t||r<=a||b<=l)return e;
        if(a<=l&&r<=b){return t->val;}
        return f(get(a,b,t->ch[0],l,(l+r)/2),get(a,b,t->ch[1],(l+r)/2,r));
    }
	lint kth_element(np s,np t,lint k,lint l,lint r){
		if(r-l==1)return l;
		if(!s)s=new node(e);
		if(!t)t=new node(e);
		lint cnt=count(s->ch[0])-count(t->ch[0]);
		if(cnt>k)return kth_element(s->ch[0],t->ch[0],k,l,(l+r)/2);
		else return kth_element(s->ch[1],t->ch[1],k-cnt,(l+r)/2,r);
	}
	T e=0;
	T f(T s,T t){
		return s+t;
	}
	T g(T s,T t){
		return s-t;
	}
};