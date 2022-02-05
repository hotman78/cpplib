/**
 * @brief TopTree(WIP)
 */

template<typename T,typename E>
class top_tree{
	struct node;
	using np=node*;
	struct cluster{
		bool is_compress,is_edge,guarded;
		int l,r;
		T key=et;
		np ch[3]={nullptr,nullptr,nullptr};
		np p=nullptr;
		cluster(){}
		cluster(int l,int r,bool is_compress,bool is_edge):l(l),r(r),is_compress(is_compress),is_edge(is_edge){}
        bool is_root(){
            return !p||p->guarded||(p->ch[0]!=this&&p->ch[1]!=this);
        }
	};
	np root=nullptr;
	void join(np p,np t,int i){
		if(t)t->p=p;
		if(p)p->ch[i]=t,update(p);
	}
	//左右の子を入れ替える
	void swap(np t){
		swap(t->l,t->r);
		swap(t->ch[0],t->ch[1]);
		toggle(t->ch[0]);toggle(t->ch[1]);
	}
    void update(np t){

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
                push(r),push(q),push(t);
                bool b=r->ch[0]==q;
                if(q->ch[1-b]==t)rot(q,b),rot(t,b);
                else rot(t,1-b),rot(t,b);
            }
        }
    }
	void push(np t){
		
    }
	void toggle(np t){

	}
	void splice(np s,np t,bool b){
		if(!b){
			join(s->p,t,(s->p->ch[1]==s)+2*(s->p->ch[2]==s));
			join(t->p,s,(t->p->ch[1]==t)+2*(t->p->ch[2]==t));
		}else{
			toggle(s);toggle(t);
			join(s->p,t,(s->p->ch[1]==s)+2*(s->p->ch[2]==s));
			join(t->p,s,(t->p->ch[1]==t)+2*(t->p->ch[2]==t));
		}
	}
	void expose(np t){
		while(1){
			splay(t);
			if(!t->p)return;
			np n;
			if(t->p->is_compress){
				n=t->p;
			}else{
				np s=t->p;
				splay(s);
				n=s->p;
			}
			bool b=n->p&&n->p->guarded;
			splice(t,n->ch[b],b);
			if(t->is_edge)t=n;
		}
	}
	void soft_expose(np s,np t){
		expose(s);
		if(s!=t){
			guard(s,1);
			expose(t);
			guard(s,0);
		}
		if(s->ch[0]=t){
			swap(s);
		}
	}
	np handle(int s){

	}
	void link(int s,int t){
		np v=handle(s),w=handle(t);
		if(w){
			expose(w);
			if(v->l!=t&&v->r!=t){
				np rp=new node(-1,-1,0,0);
				np q=new node(s,t,0,1);
				join(rp,v->ch[2],0);
				join(rp,v->ch[0],1);
				join(v,q,0);
				join(v,rp,2);
			}else{
				if(v->r==t)swap(v);
				np p=new node(s,v->r,1,0);
				np q=new node(s,t,0,1);
				join(p,q,0);
				join(p,v,1);
				v=p;
			}
		}else{
			v=new node(s,t,0,1);
		}
		
	}
	void cut(){

	}
};
