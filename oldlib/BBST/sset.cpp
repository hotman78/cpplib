template<typename T>
class sset{
    struct node{
        T val;
        int cnt=1;
        int dep=0;
        bool removed=0;
        node* ch[2]={nullptr,nullptr};
        node(T val):val(val){}
    };
    using np=node*;
    np root=nullptr;
    int count(np t){return t?t->cnt:0;}
    int depth(np t){return t?t->dep:0;}
    np update(np& t){
        t->cnt=count(t->ch[0])+(!t->removed)+count(t->ch[1]);
        t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
        if(depth(t)>3*log(count(t))+1)rebuild(t);
        return t;
    }

    public:
    void insert(T val){insert(val,root);}
    void erase(T val){erase(val,root);}
    int lower_bound(T val){return lower_bound(val,root);}

    private:
    void insert(T val,np& t){
        if(!t)t=new node(val);
        else if(val==t->val&&t->removed)t->removed=0;
        else if(val<t->val)insert(val,t->ch[0]);
        else if(val>t->val)insert(val,t->ch[1]);
        update(t);
    }
    void erase(T val,np& t){
        if(!t)return;
        else if(val==t->val)t->removed=1;
        else if(val<t->val)erase(val,t->ch[0]);
        else if(val>t->val)erase(val,t->ch[1]);
        update(t);
    }
    int lower_bound(T val,np t){
        if(!t)return 0;
        if(val==t->val)return count(t->ch[0]);
        if(val<t->val)return lower_bound(val,t->ch[0]);
        else return count(t->ch[0])+1+lower_bound(val,t->ch[1]);
    }
    void rebuild(np& t){
		np v[t->cnt];
		auto Y=[&](auto f){return[&](auto... args){return f(f, args...);};};
		int idx=0;
		auto f=Y([&](auto f,np t)->void{
			if(!t)return;
			f(f,t->ch[0]);
			v[idx++]=t;
			f(f,t->ch[1]);
		});
		f(t);
		auto g=Y([&](auto g,int l,int r)->np{
			if(l>=r)return nullptr;
			v[(l+r)/2]->ch[0]=g(g,l,(l+r)/2);
			v[(l+r)/2]->ch[1]=g(g,(l+r)/2+1,r);
			return update(v[(l+r)/2]);
		});
		t=g(0,t->cnt);
    }
};