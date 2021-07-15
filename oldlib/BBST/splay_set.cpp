template<typename T>
class splay_set{
	struct node;
	using np=node*;
	struct node{
		T val;
		int cnt=1;
		np ch[2]={nullptr,nullptr};
		np par=nullptr;
		node(T val):val(val){}
	};
	np root=nullptr;
	np nil=nullptr;
	inline int count(np t){return !t?0:t->cnt;}
	np update(np& t){
		if(!t)return t;
		t->cnt=count(t->ch[0])+count(t->ch[1])+1;
		return t;
	}
	public:
	splay_set(){}
	inline void insert(T val){root=insert(val,root);root=expose(root);}
	inline int size(){return count(root);}
	private:
	np merge(np s,np t){
		while(s->ch[1])s=s->ch[1];
		expose(s);
		s->ch[1]=t;
		return s;
	}
	pair<np,np> split(np t){
		expose(t);
		auto s=t->ch[0];
		set_child(t,nil,0);
		return {s,t};
	}
	tuple<np,np,np> split(np s,np t){
		expose(s);
		expose(t);
		if(t->ch[0]==s){
			auto u=s->ch[0];
			set_child(s,nil,0);
			return {u,s,t};
		}else{
			auto u=s->ch[0];
			set_child(s,nil,0);
			return {s,u,t};
		}
	}
	np insert(T val,np t){
		while(t->ch[val>t->val])t=t->ch[val>t->val];
		set_child(t,new node(val),val>t->val);
		np s=t->ch[val>t->val];
		while(t->par){
			t=t->par;
			update(t);
		}
		return s=expose(s);
	}
	np expose(np t){
		if(!t)return t;
		while(t->par){
			if((t->par&&t->par->par)&&((t->par->par->ch[0]&&t->par->par->ch[0]->ch[0])||(t->par->par->ch[1]&&t->par->par->ch[1]->ch[1]))){
				rot(t->par);
			}
			rot(t);
		}
		return t;
	}
	void rot(np& t){
		np s=t->par;
		if(!s)return;
		bool b=t==s->ch[1];
		set_child(s,t->ch[1-b],b);
		set_child(t,s,1-b);
	}
	inline void set_child(np& p,np& ch,bool b){
		if(p&&p->ch[b])p->ch[b]->par=nullptr;
		if(p)p->ch[b]=ch;
		if(ch)ch->par=p;
		update(p);
	}
};