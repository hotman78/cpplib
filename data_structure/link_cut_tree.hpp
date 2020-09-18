template<typename T,typename E>
class link_cut{
    class myset{
        struct node{
            T val,l,r,sum;
            int cnt=1,dep=0;
            static const node* nil;
            node* ch[2]={nullptr,nullptr};
            node(T val):val(val),l(val),r(val),sum(val){}
        };
        using np=node*;
        np root=nullptr;
        inline int count(np t){return t?t->cnt:0;}
        inline int depth(np t){return t?t->dep:0;}
        np update(np t,bool flag=1){
            if(!t)return t;
            t->cnt=count(t->ch[0])+1+count(t->ch[1]);
            t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
            if(t->ch[0])t->l=t->ch[0]->l;
            if(t->ch[1])t->r=t->ch[1]->r;

            t->sum=et;
            if(t->ch[0])t->sum=f(t->sum,t->ch[0]->sum);
            t->sum=f(t->sum,t->val);
            if(t->ch[1])t->sum=f(t->sum,t->ch[1]->sum);

            if(flag&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){
                bool b=depth(t->ch[0])<depth(t->ch[1]);
                if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){
                    t->ch[b]=rot(t->ch[b]);
                }
                t=rot(update(t,0));
            }
            return t;
        }
        np rot(np t){
            T b=depth(t->ch[0])<depth(t->ch[1]);
            np s=t->ch[b];
            t->ch[b]=s->ch[1-b];
            s->ch[1-b]=t;
            update(t,0);
            return update(s,0);
        }
        np insert(T val,np t){
            if(!t)return new node(val);
            bool b=t->val<val;
            t->ch[b]=insert(val,t->ch[b]);
            return update(t);
        }
        np erase(T val,np t){
            if(!t)return t;
            if(t->val==val){
                return move_down(t->ch[0],t->ch[1]);
            }else{
                bool b=t->val<val;
                t->ch[b]=erase(val,t->ch[b]);
            }
            return update(t);
        }
        np move_down(np t,np rhs) {
            if(!t)return rhs;
            t->ch[1]=move_down(t->ch[1],rhs);
            return update(t);
        }
        E sum(T l,T r,np t){
            if(!t)return et;
            if(t->r<l||r<=t->l)return et;
            if(l<=t->l&&t->r<r)return t->sum;
            bool b=l<=t->val&&t->val<r;
            return f(sum(l,r,t->ch[0]),f(b?t->val:et,sum(l,r,t->ch[1])));
        }
        int lower_bound(T val,np t){
            if(!t)return 0;
            bool b=val>t->val;
            return(b?count(t->ch[0])+1:0)+lower_bound(val,t->ch[b]);
        }
        int upper_bound(T val,np t){
            if(!t)return 0;
            bool b=val>=t->val;
            return(b?count(t->ch[0])+1:0)+upper_bound(val,t->ch[b]);
        }
        T find_by_order(T idx,np t){
            if(idx==count(t->ch[0]))return t->val;
            bool b=idx>count(t->ch[0]);
            return find_by_order(idx-(b?count(t->ch[0])+1:0),t->ch[b]);
        }
        public:
        void insert(T val){root=insert(val,root);}
        void erase(T val){root=erase(val,root);}
        inline int size(){return count(root);}
        inline int count(T val){return upper_bound(val,root)-lower_bound(val,root);}
        inline int count(T l,T r){return lower_bound(r,root)-lower_bound(l,root);}
        inline E sum(T l,T r){return sum(l,r,root);}
        inline E all_sum(){return root?root->sum:et;}
        //0-indexでidx番目
        inline T operator[](T idx){return find_by_order(idx,root);}
        //x未満の個数/s[lower_bound(x)]はx以上最小の値
        inline int lower_bound(T x){return lower_bound(x,root);}
        //x以下の個数/s[upper_bound(x)]はxより大きい最小の値
        inline int upper_bound(T x){return upper_bound(x,root);}
    };
    public:
    struct node;
    using np=node*;
    struct node{
        np ch[2]={nullptr,nullptr};
        np p=nullptr;
        int idx;
        T key,sum,sum2,csum;
        myset light;
        bool rev=0;
        E lazy=ee;
        int sz;
        node(){}
        node(int idx,T key):idx(idx),key(key),sum(key),sum2(et),csum(et),sz(1){}
        bool is_root() {
            return !p||(p->ch[0]!=this&&p->ch[1]!=this);
        }
    };
    int size(np t){return t?t->sz:0;}
    void update(np t){
        t->sz=size(t->ch[0])+1+size(t->ch[1]);
        t->sum=et;
        if(t->ch[0])t->sum=f(t->sum,t->ch[0]->sum);
        t->sum=f(t->sum,t->key);
        if(t->ch[1])t->sum=f(t->sum,t->ch[1]->sum);
        t->csum=f(f(t->key,t->light.all_sum()),t->ch[1]?t->ch[1]->sum2:et);
        t->sum2=f(f(f(t->ch[0]?t->ch[0]->sum2:et,t->key),t->ch[1]?t->ch[1]->sum2:et),t->light.all_sum());
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
                push(q), push(t);
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
    void propagate(np t,E x){
        t->lazy=h(t->lazy,x);
        t->key=g(t->key,x,1);
        t->sum=g(t->sum,x,t->sz);
    }
    void set_propagate(np t,E x){
        expose(t);
        propagate(t,x);
        push(t);
    }
    void push(np t){
        if(t->lazy!=ee){
            if(t->ch[0])propagate(t->ch[0],t->lazy);
            if(t->ch[1])propagate(t->ch[1],t->lazy);
            t->lazy=ee;
        }
        if(t->rev){
            if(t->ch[0])toggle(t->ch[0]);
            if(t->ch[1])toggle(t->ch[1]);
            t->rev=0;
        }
    }
    np expose(np t){
        np rp=nullptr;
        for(np cur=t;cur;cur=cur->p){
            splay(cur);
            if(cur->ch[1]){
                cur->light.insert(cur->ch[1]->sum2);
            }
            cur->ch[1]=rp;
            if(cur->ch[1]){
                cur->light.erase(cur->ch[1]->sum2);
            }
            update(cur);
            rp=cur;
        }
        splay(t);
        return rp;
    }
    vector<int>get_path(np x){
        vector<int>vs;
        function<void(np)>dfs=[&](np cur){
            if(!cur)return;
            push(cur);
            dfs(cur->ch[1]);
            vs.push_back(cur->idx);
            dfs(cur->ch[0]);
        };
        expose(x);
        dfs(x);
        return vs;
    }
    void link(np ch,np par){
        expose(ch);
        expose(par);
        ch->p=par;
        par->ch[1]=ch;
        update(par);
    }
    void cut(np ch){
        expose(ch);
        np par=ch->ch[0];
        ch->ch[0]=nullptr;
        par->p=nullptr;
        update(ch);
    }
    void toggle(np t){
        assert(t);
        swap(t->ch[0],t->ch[1]);
        t->sum=s(t->sum);
        t->rev^=1;
    }
    void evert(np t){
        expose(t);
        toggle(t);
        push(t);
    }
    np get_root(np x){
        expose(x);
        while(x->ch[0]){
            push(x);
            x=x->ch[0];
        }
        return x;
    }
    vector<np>p;
    static T et;
    static E ee;
    constexpr static
    T s(T s){
        return s;
    }
    constexpr static
    T f(T s,T t){
        return s+t;
    }
    constexpr static
    T g(T s,E t,int len){
        return s+t*len;
    }
    constexpr static
    E h(E s,E t){
        return s+t;
    }
    public:
    link_cut(int sz){
        p.resize(sz,nullptr);
        for(int i=0;i<sz;i++)p[i]=new node(i,et);
    }
    link_cut(){}
    void set_key(int t,T key) {
        expose(p[t]);
        p[t]->key=key;
        update(p[t]);
    }
    T get_key(int t) {
        return p[t]->key;
    }
    vector<int> get_path(int s,int t){
        evert(p[s]);
        return get_path(p[t]);
    }
    void path_add(int s,int t,E x){
        evert(p[s]);
        set_propagate(p[t],x);
    }
    T get_path_sum(int s,int t){
        evert(p[s]);
        expose(p[t]);
        return p[t]->sum;
    }
    //tを根としたsの部分木の和を得る
    T get_subtree_sum(int s,int t){
        evert(p[t]);
        expose(p[s]);
        return p[s]->csum;
    }
    void make_node(T x){
        p.emplace_back(new node(p.size(),x));
    }
    void evert(int t){
        evert(p[t]);
    }
    void link(int s,int t){
        evert(p[s]);
        link(p[s],p[t]);
    }
    void cut(int s,int t){
        evert(p[s]);
        cut(p[t]);
    }
    bool same(int s,int t){
        return get_root(p[s])==get_root(p[t]);
    }
    np lca(int s,int t){
        if(get_root(p[s])!=get_root(p[t]))return nullptr;
        expose(p[s]);
        return expose(p[t]);
    }
};
template<typename T,typename E>T link_cut<T,E>::et=0;
template<typename T,typename E>E link_cut<T,E>::ee=0;
