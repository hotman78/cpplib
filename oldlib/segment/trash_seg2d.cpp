template<typename T,typename E>
struct seg2d{
    private:
    struct node{
        T val;
        E lazy;
        node* ch[4]={nullptr,nullptr,nullptr,nullptr};
        node(seg2d* seg):val(seg->et),lazy(seg->ee){}
    };
    using np=node*;
    np root=new node(this);
    T et;
    E ee;
    int64_t n=1;
    public:
    seg2d(int64_t h=1LL<<60,int64_t w=1LL<<60,T et=0,E ee=0):et(et),ee(ee){
        while(n<max(h,w))n<<=2;
    }
    void update(int64_t ax,int64_t ay,int64_t bx,int64_t by,E val){
        update(ax,ay,bx,by,val,0,0,0,n,n,root);
    }
    T get(int64_t ax,int64_t ay,int64_t bx,int64_t by){
        return get(ax,ay,bx,by,0,0,0,n,n,root);
    }
    private:
    //0-indexed [a,b)
    T update(int64_t ax,int64_t ay,int64_t bx,int64_t by,E val,int64_t k,int64_t lx,int64_t ly,int64_t rx,int64_t ry,np t){
        eval(t,k);
        //区間外
        if(rx<=ax||bx<=lx||ry<=ay||by<=ly)return t->val;
        //全部区間内
        if(ax<=lx&&rx<=bx&&ay<=ly&&ry<=by){
            t->lazy=g(t->lazy,val);
            return h(t->val,t->lazy);
        }
        //一部区間内
        rep(i,4)if(!t->ch[i])t->ch[i]=new node(this);
        T res=et;
        res=f(res,update(ax,ay,bx,by,val,4*k+1,lx,ly,(lx+rx)/2,(ly+ry)/2,t->ch[0]));
        res=f(res,update(ax,ay,bx,by,val,4*k+2,(lx+rx)/2,ly,rx,(ly+ry)/2,t->ch[1]));
        res=f(res,update(ax,ay,bx,by,val,4*k+3,lx,(ly+ry)/2,(lx+rx)/2,ry,t->ch[2]));
        res=f(res,update(ax,ay,bx,by,val,4*k+4,(lx+rx)/2,(ly+ry)/2,rx,ry,t->ch[3]));
        return t->val=res;
    }
    //0-indexed [a,b)
    T get(int64_t ax,int64_t ay,int64_t bx,int64_t by,int64_t k,int64_t lx,int64_t ly,int64_t rx,int64_t ry,np t){
        eval(t,k);
        //区間外
        if(rx<=ax||bx<=lx||ry<=ay||by<=ly)return et;
        //全部区間内
        if(ax<=lx&&rx<=bx&&ay<=ly&&ry<=by)return t->val;
        //一部区間内
        rep(i,4)if(!t->ch[i])t->ch[i]=new node(this);
        T res=et;
        res=f(res,get(ax,ay,bx,by,4*k+1,lx,ly,(lx+rx)/2,(ly+ry)/2,t->ch[0]));
        res=f(res,get(ax,ay,bx,by,4*k+2,(lx+rx)/2,ly,rx,(ly+ry)/2,t->ch[1]));
        res=f(res,get(ax,ay,bx,by,4*k+3,lx,(ly+ry)/2,(lx+rx)/2,ry,t->ch[2]));
        res=f(res,get(ax,ay,bx,by,4*k+4,(lx+rx)/2,(ly+ry)/2,rx,ry,t->ch[3]));
        return res;
    }
    inline void eval(np t,int64_t k){
        if(t->lazy==ee)return;
        if((k*4+1)*3<n*4-1){
            rep(i,4)if(!t->ch[i])t->ch[i]=new node(this);
            rep(i,4)t->ch[i]->lazy=g(t->ch[i]->lazy,t->lazy);
        }
        t->val=h(t->val,t->lazy);
        t->lazy=ee;
    }
    T f(T a,T b){
        return a+b;
    }
    T h(T a,E b){
        return a+b;
    }
    E g(E a,E b){
        return a+b;
    }
    auto update(auto a,auto b){return b==ee?a:b;}
};

template<typename T,typename E>
class RBST{
    inline unsigned long rnd() {
        static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
        unsigned long t=(x^(x<<11));
        x=y; y=z; z=w;
        return ( w=(w^(w>>19))^(t^(t>>8)) );
    }
    struct node;
    using np=node*;
    struct node{
        node* ch[2]={nullptr,nullptr};
        T key;E val;E cal;
        int cnt=1;
        node(T key,E val):key(key),val(val){}
    };
    np root=nullptr;
    using F=function<E(E,E)>;
    E e=NULL;
    F func=NULL;
    inline int count(np t){return !t?0:t->cnt;}
    np update(np& t){
        t->cnt=count(t->ch[0])+count(t->ch[1])+1;
        if(func){
            t->cal=e;
            if(t->ch[0])t->cal=func(t->cal,t->ch[0]->cal);
            t->cal=func(t->cal,t->val);
            if(t->ch[1])t->cal=func(t->cal,t->ch[1]->cal);
        }
        return t;
    }
    public:
    RBST(){}
    RBST(E e,F f):e(e),func(f){}
    void insert(T key,E val){insert(root,key,val);}
    void erase(T key){erase(root,key);}
    void erase_all(T key){erase(root,key);}
    int lower_bound(T k){return lower_bound(root,k);}
    int upper_bound(T k){return upper_bound(root,k);}
    T find_key_by_order(T k){return find_key_by_order(root,k);}
    E find_by_order(int idx){return find_by_order(root,idx);}
    E get_sum(T l,T r){return get_sum(root,l,r);}
    E get_sum_by_order(int l,int r){return get_sum_by_order(root,l,r);}
    int size(){return count(root);}
    private:
    void insert(np& t,T key,E val){
        np p=new node(key,val);
        auto d=split(t,lower_bound(t,key));
        t=merge(d.first,merge(update(p),d.second));
    }
    np erase(np& t,T key){
        int idx=lower_bound(t,key);
        auto d=split(t,idx,idx+1);
        t=merge(get<0>(d),get<2>(d));
    }
    np erase_all(np& t,T key){
        auto d=split(t,lower_bound(t,key),upper_bound(t,key));
        t=merge(get<0>(d),get<2>(d));
    }
    E get_sum(np& t,T l,T r){
        np x,y,z;
        tie(x,y,z)=split(t,l,r);
        E res;
        if(y)res=y->cal;
        else res=e;
        t=merge(x,y,z);
        return res;
    }
    E get_sum_by_order(np& t,int l,int r){
        np x,y,z;
        tie(x,y,z)=split_by_order(t,l,r);
        E res;
        if(y)res=y->cal;
        else res=e;
        t=merge(x,y,z);
        return res;
    }
    T find_key_by_order(np& t,const int& k){
        np p,q,r;
        tie(p,q,r)=split(t,k,k+1);
        if(q){
            t=merge(p,q,r);
            return q->key;
        }
    }
    T find_by_order(np& t,const int& k){
        np p,q,r;
        tie(p,q,r)=split(t,k,k+1);
        if(q){
            t=merge(p,q,r);
            return q->val;
        }
        return -1;
    }
    int lower_bound(np& t,T k){
        if(!t)return 0;
        if(k<=(t->key))return lower_bound(t->ch[0],k);
        else return count(t->ch[0])+1+lower_bound(t->ch[1],k);
    }
    int upper_bound(np& t,T k){
        if(!t)return 0;
        if(k<(t->key))return upper_bound(t->ch[0],k);
        else return count(t->ch[0])+1+upper_bound(t->ch[1],k);
    }
    np merge(np& p,np& q,np& r){
        return merge(p,merge(q,r));
    }
    np merge(np l,np r){
        if(!l||!r)return !l?r:l;
        if((unsigned long)count(l)>rnd()%(unsigned long)(count(l)+count(r))){
            l->ch[1]=merge(l->ch[1],r);
            return update(l);
        }else{
            r->ch[0]=merge(l,r->ch[0]);
            return update(r);
        }
    }
    tuple<np,np,np> split(np t,T l,T r){
        auto p=split(t,l);
        auto q=split(p.second,r);
        return make_tuple(p.first,q.first,q.second);
    }
    pair<np,np> split(np t,T k){
        if(!t)return make_pair(nullptr,nullptr);
        bool b=k>t->key;
        auto s=split(t->ch[b],k);
        t->ch[b]=b?s.first:s.second;
        return b?make_pair(update(t),s.second):make_pair(s.first,update(t));
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
};
template<typename Int,typename T>
class segment2d{
    struct node;
    using np=node*;
    using V=RBST<Int,T>*;
    using F=function<T(T,T)>;
    struct node{
        Int x;
        V v;
        np ch[2]={nullptr,nullptr};
        node(T e,F f):v(new RBST<Int,T>(e,f)){}
    };
    Int sz=1,n;
    T e;
    F f;
    np root=nullptr;
    public:
    segment2d(Int n,T e,F f):n(n),e(e),f(f){
        while(sz<n)sz<<=1;
    }
    void insert(Int x,Int y,T val){
        insert(x,y,val,-sz,sz,root);
    }
    T get_sum(Int lx,Int rx,Int ly,Int ry){
        return get_sum(lx,rx,ly,ry,-sz,sz,root);
    }
    private:
    void insert(Int x,Int y,T val,Int l,Int r,np& t){
        if(r<=x||x<l)return;
        if(!t)t=new node(e,f);
        if(l<=x&&x<=r)t->v->insert(y,val);
        if(r-l!=1){
            insert(x,y,val,l,(l+r)/2,t->ch[0]);
            insert(x,y,val,(l+r)/2,r,t->ch[1]);
        }
    }
    T get_sum(Int lx,Int rx,Int ly,Int ry,Int l,Int r,np t){
        if(!t||r<=lx||rx<=l)return e;
        if(lx<=l&&r<=rx)return t->v->get_sum(ly,ry);
        return f(get_sum(lx,rx,ly,ry,l,(l+r)/2,t->ch[0]),get_sum(lx,rx,ly,ry,(l+r)/2,r,t->ch[1]));
    }
};