template<typename T,typename E>
class segment2d{
    class segment_y{
        E* node;
        int n=1;
        public:
        segment_y(auto sz){
            while(n<=(int)sz)n<<=1;
            node=new E[(n<<1)-1];
            rep(i,(n<<1)-1)node[i]=e;
        }
        T get(auto l,auto r){
            l+=n;r+=n;
            E s=e;
            while(l<r){
                if(l&1)s=f(s,node[l++-1]);
                if(r&1)s=f(s,node[--r-1]);
                l/=2;r/=2;
            }
            return s;
        }
        void update(auto t,E val){
            t+=n-1;
            while(t){
                node[t]=f(node[t],val);
                t=(t-1)>>1;
            }
            node[0]=f(node[0],val);
        }
    };
    vector<vector<pair<T,E>>>node;
    vector<vector<T>>y_list;
    segment_y** seg;
    int n=1,sz;
    vector<pair<T,T>>v;
    vector<T>x_list;
    bool built=0;
    public:
    segment2d(){}
    void add_point(T x,T y){
        x_list.push_back(x);
        v.emplace_back(x,y);
    }
    void update(T x,T y,E val){
        if(!built){
            build();
            built=1;
        }
        x=lower_bound(all(x_list),x)-x_list.begin();
        x+=n-1;
        while(x){
            seg[x]->update(lower_bound(all(y_list[x]),y)-y_list[x].begin(),val);
            x=(x-1)/2;
        }
        seg[0]->update(lower_bound(all(y_list[0]),y)-y_list[0].begin(),val);
    }
    T get(T lx,T rx,T ly,T ry){
        if(!built){
            build();
            built=1;
        }
        lx=lower_bound(all(x_list),lx)-x_list.begin();
        rx=lower_bound(all(x_list),rx)-x_list.begin();
        lx+=n;rx+=n;
        T s=e;
        while(lx<rx){
            if((lx&1)&&y_list[lx-1].size()){
                auto p=lower_bound(all(y_list[lx-1]),ly)-y_list[lx-1].begin();
                auto q=lower_bound(all(y_list[lx-1]),ry)-y_list[lx-1].begin();
                s=f(s,seg[lx-1]->get(p,q));
                ++lx;
            }
            if((rx&1)&&y_list[rx-2].size()){
                rx--;
                auto p=lower_bound(all(y_list[rx-1]),ly)-y_list[rx-1].begin();
                auto q=lower_bound(all(y_list[rx-1]),ry)-y_list[rx-1].begin();
                s=f(s,seg[rx-1]->get(p,q));
            }
            lx/=2;rx/=2;
        }
        return s;
    }
    void build(){
        sort(all(x_list));
        x_list.erase(unique(all(x_list)),x_list.end());
        sz=x_list.size();
        while(n<=sz)n<<=1;
        node.resize((n<<1)-1);
        y_list.resize((n<<1)-1);
        seg=new segment_y*[(n<<1)-1];
        for(auto d:v){
            T x,y;
            tie(x,y)=d;
            _update(lower_bound(all(x_list),x)-x_list.begin(),y);
        }
        rep(i,(n<<1)-1){
            sort(all(y_list[i]));
            y_list[i].erase(unique(all(y_list[i])),y_list[i].end());
            seg[i]=new segment_y(y_list[i].size());
        }
    }
    private:
    void _update(int x,T y){
        x+=n-1;
        while(x){
            y_list[x].emplace_back(y);
            x=(x-1)>>1;
        }
        y_list[0].emplace_back(y);
    }
    constexpr static E e=0;
    constexpr static
    E f(E s,E t){
        return s+t;
    }
};

template<typename T,typename E>
class segment2d{
    class AVL_tree{
        struct node;
        using np=node*;
        struct node{
            node* ch[2]={nullptr,nullptr};
            T key;E val;E cal;
            int l,r;
            int cnt=1,dep=0;
            node(T key,E val):key(key),val(val),l(key),r(key){}
        };
        np root=nullptr;
        inline int count(np t){return !t?0:t->cnt;}
        inline int depth(np t){return t?t->dep:0;}
        np update(np& t,bool b=1){
            t->l=t->ch[0]?t->ch[0]->l:t->l;
            t->r=t->ch[1]?t->ch[1]->r:t->r;
            t->cnt=count(t->ch[0])+count(t->ch[1])+1;
            t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
            t->cal=e;
            if(t->ch[0])t->cal=f(t->cal,t->ch[0]->cal);
            t->cal=f(t->cal,t->val);
            if(t->ch[1])t->cal=f(t->cal,t->ch[1]->cal);
            if(b&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
                rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
            }
            return t;
        }
        public:
        AVL_tree(){}
        inline void insert(T key,E val){insert(key,val,root);}
        inline void erase(T key){erase(key,root);}
        inline int size(){return count(root);}
        E get_sum(T l,T r){return get_sum(l,r,root);}
        private:
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
            else p->val=t->val,t=t->ch[0];
            update(t);
        }
        E get_sum(T l,T r,np& t){
            if(!t)return e;
            if(t->r<l||r<=t->l)return e;
            if(l<=t->l&&t->r<r)return t->cal;
            bool b=l<=t->key&&t->key<r;
            return f(get_sum(l,r,t->ch[0]),f(b?t->val:e,get_sum(l,r,t->ch[1])));
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
    struct node;
    using np=node*;
    using V=AVL_tree*;
    struct node{
        T x;
        V v;
        np ch[2]={nullptr,nullptr};
        node():v(new AVL_tree()){}
    };
    T sz=1,n;
    np root=nullptr;
    public:
    segment2d(T n):n(n){
        while(sz<n)sz<<=1;
    }
    segment2d():sz(1LL<<32),n(1LL<<32){}
    inline void insert(T x,T y,E val){
        insert(x,y,val,0,sz,root);
    }
    inline T get_sum(T lx,T rx,T ly,T ry){
        return get_sum(lx,rx,ly,ry,0,sz,root);
    }
    private:
    void insert(T x,T y,E val,T l,T r,np& t){
        if(r<=x||x<l)return;
        if(!t)t=new node();
        if(l<=x&&x<=r)t->v->insert(y,val);
        if(r-l!=1){
            insert(x,y,val,l,(l+r)/2,t->ch[0]);
            insert(x,y,val,(l+r)/2,r,t->ch[1]);
        }
    }
    T get_sum(T lx,T rx,T ly,T ry,T l,T r,np t){
        if(!t||r<=lx||rx<=l)return e;
        if(lx<=l&&r<=rx)return t->v->get_sum(ly,ry);
        return f(get_sum(lx,rx,ly,ry,l,(l+r)/2,t->ch[0]),get_sum(lx,rx,ly,ry,(l+r)/2,r,t->ch[1]));
    }
    constexpr static T e=0;
    constexpr static
    E f(const E& s,const E& t){
        return s+t;
    };
};

// template<typename T,typename E>
// class segment2d{
//     class segment_y{
//         E* node;
//         int n=1;
//         public:
//         segment_y(auto sz){
//             while(n<=(int)sz)n<<=1;
//             node=new E[(n<<1)-1];
//             for(int i=0;i<(n<<1)-1;i++)node[i]=e;
//         }
//         T get(auto l,auto r){
//             l+=n;r+=n;
//             E s=e;
//             while(l<r){
//                 if(l&1)s=f(s,node[l++-1]);
//                 if(r&1)s=f(s,node[--r-1]);
//                 l>>=1;r>>=1;
//             }
//             return s;
//         }
//         void update(auto t,E val){
//             t+=n-1;
//             while(t){
//                 node[t]=f(node[t],val);
//                 t=(t-1)>>1;
//             }
//             node[0]=f(node[0],val);
//         }
//     };
// 	vector<vector<pair<T,E>>>node;
//     vector<vector<T>> y_list;
//     segment_y** seg;
// 	int n=1,sz;
//     vector<tuple<T,T,E>>v;
//     vector<T>x_list;
//     bool built=0;
// 	public:
// 	segment2d(){}
//     void update(T x,T y,E val){
//         v.emplace_back(x,y,val);
//         x_list.push_back(x);
//     }
//     T get(T lx,T rx,T ly,T ry){
//         if(!built){
//             build();
//             built=1;
//         }
//         lx=lower_bound(x_list.begin(),x_list.end(),lx)-x_list.begin();
//         rx=lower_bound(x_list.begin(),x_list.end(),rx)-x_list.begin();
// 		lx+=n;rx+=n;
// 		T s=e;
// 		while(lx<rx){
// 			if((lx&1)&&y_list[lx-1].size()){
//                 s=f(s,seg[lx-1]->get(lower_bound(y_list[lx-1].begin(),y_list[lx-1].end(),ly)-y_list[lx-1].begin(),lower_bound(y_list[lx-1].begin(),y_list[lx-1].end(),ry)-y_list[lx-1].begin()));
//                 ++lx;
//             }
// 			if((rx&1)&&y_list[--rx-1].size()){
//                 s=f(s,seg[rx-1]->get(lower_bound(y_list[rx-1].begin(),y_list[rx-1].end(),ly)-y_list[rx-1].begin(),lower_bound(y_list[rx-1].begin(),y_list[rx-1].end(),ry)-y_list[rx-1].begin()));
//             }
// 			lx>>=1;rx>>=1;
// 		}
// 		return s;
// 	}
//     void build(){
//         sort(x_list.begin(),x_list.end());
//         x_list.erase(unique(x_list.begin(),x_list.end()),x_list.end());
//         sz=x_list.size();
//         while(n<=sz)n<<=1;
// 		node.resize((n<<1)-1);
//         y_list.resize((n<<1)-1,vector<T>());
//         seg=new segment_y*[(n<<1)-1];
//         for(auto d:v){
//             T x,y;E val;
//             tie(x,y,val)=d;
//             _update(lower_bound(x_list.begin(),x_list.end(),x)-x_list.begin(),y,val);
//         }
//         for(int i=0;i<(n<<1)-1;i++){
//             sort(y_list[i].begin(),y_list[i].end());
//             y_list[i].erase(unique(y_list[i].begin(),y_list[i].end()),y_list[i].end());
//             if(y_list[i].size()==0){
//                 seg[i]=nullptr;
//                 continue;
//             }
//             seg[i]=new segment_y(y_list[i].size());
//             for(auto d:node[i]){
//                 T y;E val;
//                 tie(y,val)=d;
//                 seg[i]->update(lower_bound(y_list[i].begin(),y_list[i].end(),y)-y_list[i].begin(),val);
//             }
//         }
//     }
//     private:
// 	void _update(int x,T y,E val){
// 		x+=n-1;
// 		while(x){
// 			node[x].emplace_back(y,val);
//             y_list[x].emplace_back(y);
// 			x=(x-1)>>1;
// 		}
//         node[0].emplace_back(y,val);
//         y_list[0].emplace_back(y);
// 	}
// 	constexpr static E e=0;
// 	constexpr static
// 	E f(const E& s,const E& t){
// 		return s+t;
// 	}
// };


// template<typename T,typename E>
// class segment2d{
//     class AVL_tree{
//         struct node;
//         using np=node*;
//         struct node{
//             node* ch[2]={nullptr,nullptr};
//             T key;E val;E cal;
//             int cnt=1,dep=0;
//             node(T key,E val):key(key),val(val){}
//         };
//         np root=nullptr;
//         inline int count(np t){return !t?0:t->cnt;}
//         inline int depth(np t){return t?t->dep:0;}
//         np update(np& t,bool b=1){
//             t->cnt=count(t->ch[0])+count(t->ch[1])+1;
//             t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
//             t->cal=e;
//             if(t->ch[0])t->cal=f(t->cal,t->ch[0]->cal);
//             t->cal=f(t->cal,t->val);
//             if(t->ch[1])t->cal=f(t->cal,t->ch[1]->cal);
//             if(b&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
//                 rebuild(t,depth(t->ch[0])<depth(t->ch[1]));
//             }
//             return t;
//         }
//         public:
//         AVL_tree(){}
//         inline void insert(T key,E val){insert(root,key,val);}
//         inline E get_sum(T l,T r){return get_sum(root,l,r);}
//         inline int size(){return count(root);}
//         private:
//         void insert(np& t,T key,E val){
//             np p=new node(key,val);
//             auto d=split(t,key);
//             t=merge(d.first,merge(update(p),d.second));
//         }
//         np erase(np& t,T key){
//             int idx=lower_bound(t,key);
//             auto d=split(t,idx,idx+1);
//             t=merge(get<0>(d),get<2>(d));
//         }
//         E get_sum(np& t,T l,T r){
//             np x,y,z;
//             tie(x,y,z)=split(t,l,r);
//             E res;
//             if(y)res=y->cal;
//             else res=e;
//             t=merge(x,y,z);
//             return res;
//         }
//         inline np merge(np& p,np& q,np& r){
//             return merge(p,merge(q,r));
//         }
//         np merge(np l,np r){
//             if(!l||!r)return !l?r:l;
//             if(depth(l)>depth(r)){
//                 l->ch[1]=merge(l->ch[1],r);
//                 return update(l);
//             }else{
//                 r->ch[0]=merge(l,r->ch[0]);
//                 return update(r);
//             }
//         }
//         tuple<np,np,np> split(np t,T l,T r){
//             auto p=split(t,l);
//             auto q=split(p.second,r);
//             return make_tuple(p.first,q.first,q.second);
//         }
//         pair<np,np> split(np t,T k){
//             if(!t)return make_pair(nullptr,nullptr);
//             bool b=k>t->key;
//             auto s=split(t->ch[b],k);
//             t->ch[b]=b?s.first:s.second;
//             return b?make_pair(update(t),s.second):make_pair(s.first,update(t));
//         }
//         np rot(np t){
// 		    int b=depth(t->ch[0])<depth(t->ch[1]);
// 		    if(depth(t->ch[0])==depth(t->ch[1]))return t;
//             np s=t->ch[b];
//             t->ch[b]=s->ch[1-b];
//             s->ch[1-b]=t;
//             update(t,0);update(s,0);
//             return s;
//         }
//         void rebuild(np& t,int b){
//             if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){
//                 t->ch[b]=rot(t->ch[b]);
//             }
//             t=rot(update(t,0));
//         }
//     };
//     struct node;
//     using np=node*;
//     using V=AVL_tree*;
//     struct node{
//         T x;
//         V v;
//         np ch[2]={nullptr,nullptr};
//         node():v(new AVL_tree()){}
//     };
//     T sz=1,n;
//     np root=nullptr;
//     public:
//     segment2d(T n):n(n){
//         while(sz<n)sz<<=1;
//     }
//     segment2d():sz(1LL<<32),n(1LL<<32){}
//     inline void insert(T x,T y,E val){
//         insert(x,y,val,-sz,sz,root);
//     }
//     inline T get_sum(T lx,T rx,T ly,T ry){
//         return get_sum(lx,rx,ly,ry,-sz,sz,root);
//     }
//     private:
//     void insert(T x,T y,E val,T l,T r,np& t){
//         if(r<=x||x<l)return;
//         if(!t)t=new node();
//         if(l<=x&&x<=r)t->v->insert(y,val);
//         if(r-l!=1){
//             insert(x,y,val,l,(l+r)/2,t->ch[0]);
//             insert(x,y,val,(l+r)/2,r,t->ch[1]);
//         }
//     }
//     T get_sum(T lx,T rx,T ly,T ry,T l,T r,np t){
//         if(!t||r<=lx||rx<=l)return e;
//         if(lx<=l&&r<=rx)return t->v->get_sum(ly,ry);
//         return f(get_sum(lx,rx,ly,ry,l,(l+r)/2,t->ch[0]),get_sum(lx,rx,ly,ry,(l+r)/2,r,t->ch[1]));
//     }
//     constexpr static T e=0;
//     constexpr static
//     E f(const E& s,const E& t){
//         return s+t;
//     };
// };

// template<typename T,typename E>
// class RBST{
//     inline unsigned long rnd() {
//         static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
//         unsigned long t=(x^(x<<11));
//         x=y; y=z; z=w;
//         return ( w=(w^(w>>19))^(t^(t>>8)) );
//     }
//     struct node;
//     using np=node*;
//     struct node{
//         node* ch[2]={nullptr,nullptr};
//         T key;E val;E cal;
//         int cnt=1;
//         node(T key,E val):key(key),val(val){}
//     };
//     np root=nullptr;
//     using F=function<E(E,E)>;
//     E e=NULL;
//     F func=NULL;
//     inline int count(np t){return !t?0:t->cnt;}
//     np update(np& t){
//         t->cnt=count(t->ch[0])+count(t->ch[1])+1;
//         if(func){
//             t->cal=e;
//             if(t->ch[0])t->cal=func(t->cal,t->ch[0]->cal);
//             t->cal=func(t->cal,t->val);
//             if(t->ch[1])t->cal=func(t->cal,t->ch[1]->cal);
//         }
//         return t;
//     }
//     public:
//     RBST(){}
//     RBST(E e,F f):e(e),func(f){}
//     inline void insert(T key,E val){insert(root,key,val);}
//     inline void erase(T key){erase(root,key);}
//     inline void erase_all(T key){erase(root,key);}
//     inline int lower_bound(T k){return lower_bound(root,k);}
//     inline int upper_bound(T k){return upper_bound(root,k);}
//     inline T find_key_by_order(T k){return find_key_by_order(root,k);}
//     inline E find_by_order(int idx){return find_by_order(root,idx);}
//     inline E get_sum(T l,T r){return get_sum(root,l,r);}
//     inline E get_sum_by_order(int l,int r){return get_sum_by_order(root,l,r);}
//     inline int size(){return count(root);}
//     private:
//     void insert(np& t,T key,E val){
//         np p=new node(key,val);
//         auto d=split(t,key);
//         t=merge(d.first,merge(update(p),d.second));
//     }
//     np erase(np& t,T key){
//         int idx=lower_bound(t,key);
//         auto d=split(t,idx,idx+1);
//         t=merge(get<0>(d),get<2>(d));
//     }
//     np erase_all(np& t,T key){
//         auto d=split_by_order(t,lower_bound(t,key),upper_bound(t,key));
//         t=merge(get<0>(d),get<2>(d));
//     }
//     E get_sum(np& t,T l,T r){
//         np x,y,z;
//         tie(x,y,z)=split(t,l,r);
//         E res;
//         if(y)res=y->cal;
//         else res=e;
//         t=merge(x,y,z);
//         return res;
//     }
//     E get_sum_by_order(np& t,int l,int r){
//         np x,y,z;
//         tie(x,y,z)=split_by_order(t,l,r);
//         E res;
//         if(y)res=y->cal;
//         else res=e;
//         t=merge(x,y,z);
//         return res;
//     }
//     T find_key_by_order(np& t,const int& k){
//         np p,q,r;
//         tie(p,q,r)=split_by_order(t,k,k+1);
//         if(q){
//             t=merge(p,q,r);
//             return q->key;
//         }
//     }
//     T find_by_order(np& t,const int& k){
//         np p,q,r;
//         tie(p,q,r)=split_by_order(t,k,k+1);
//         assert(q);
//         auto d=q->val;
//         t=merge(p,q,r);
//         return d;
//     }
//     int lower_bound(np& t,T k){
//         if(!t)return 0;
//         if(k<=(t->key))return lower_bound(t->ch[0],k);
//         else return count(t->ch[0])+1+lower_bound(t->ch[1],k);
//     }
//     int upper_bound(np& t,T k){
//         if(!t)return 0;
//         if(k<(t->key))return upper_bound(t->ch[0],k);
//         else return count(t->ch[0])+1+upper_bound(t->ch[1],k);
//     }
//     inline np merge(np& p,np& q,np& r){
//         return merge(p,merge(q,r));
//     }
//     np merge(np l,np r){
//         if(!l||!r)return !l?r:l;
//         if((unsigned long)count(l)>rnd()%(unsigned long)(count(l)+count(r))){
//             l->ch[1]=merge(l->ch[1],r);
//             return update(l);
//         }else{
//             r->ch[0]=merge(l,r->ch[0]);
//             return update(r);
//         }
//     }
//     tuple<np,np,np> split(np t,T l,T r){
//         auto p=split(t,l);
//         auto q=split(p.second,r);
//         return make_tuple(p.first,q.first,q.second);
//     }
//     pair<np,np> split(np t,T k){
//         if(!t)return make_pair(nullptr,nullptr);
//         bool b=k>t->key;
//         auto s=split(t->ch[b],k);
//         t->ch[b]=b?s.first:s.second;
//         return b?make_pair(update(t),s.second):make_pair(s.first,update(t));
//     }
//     //0-indexed [-INF,l),[l,r),[r,INF)
//     tuple<np,np,np> split_by_order(np t,int l,int r){
//         auto p=split_by_order(t,l);
//         auto q=split_by_order(p.second,r-l);
//         return make_tuple(p.first,q.first,q.second);
//     }
//     //0-indexed [-INF,k),[k,INF)
//     inline pair<np,np> split_by_order(np t,int k){
//         if(!t)return make_pair(nullptr,nullptr);
//         bool b=k>count(t->ch[0]);
//         auto s=split_by_order(t->ch[b],k-(b?(count(t->ch[0])+1):0));
//         t->ch[b]=b?s.first:s.second;
//         return b?make_pair(update(t),s.second):make_pair(s.first,update(t));
//     }
// };

// template<typename Int,typename T>
// class segment2d{
//     struct node;
//     using np=node*;
//     using V=RBST<Int,T>*;
//     using F=function<T(T,T)>;
//     struct node{
//         Int x;
//         V v;
//         np ch[2]={nullptr,nullptr};
//         node(T e,F f):v(new RBST<Int,T>(e,f)){}
//     };
//     Int sz=1,n;
//     T e;
//     F f;
//     np root=nullptr;
//     public:
//     segment2d(Int n,T e,F f):n(n),e(e),f(f){
//         while(sz<n)sz<<=1;
//     }
//     inline void insert(Int x,Int y,T val){
//         insert(x,y,val,-sz,sz,root);
//     }
//     inline  T get_sum(Int lx,Int rx,Int ly,Int ry){
//         return get_sum(lx,rx,ly,ry,-sz,sz,root);
//     }
//     private:
//     void insert(Int x,Int y,T val,Int l,Int r,np& t){
//         if(r<=x||x<l)return;
//         if(!t)t=new node(e,f);
//         if(l<=x&&x<=r)t->v->insert(y,val);
//         if(r-l!=1){
//             insert(x,y,val,l,(l+r)/2,t->ch[0]);
//             insert(x,y,val,(l+r)/2,r,t->ch[1]);
//         }
//     }
//     T get_sum(Int lx,Int rx,Int ly,Int ry,Int l,Int r,np t){
//         if(!t||r<=lx||rx<=l)return e;
//         if(lx<=l&&r<=rx)return t->v->get_sum(ly,ry);
//         return f(get_sum(lx,rx,ly,ry,l,(l+r)/2,t->ch[0]),get_sum(lx,rx,ly,ry,(l+r)/2,r,t->ch[1]));
//     }
// };