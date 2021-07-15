template<typename T,typename E>
class dynamic_lazy_segment{
    using lint=long long;
    lint n;
    lint sz;
    struct node;
    using np=node*;
    struct node{
        T val=et;
        E lazy=ee;
        np lch=nullptr,rch=nullptr;
        node(){}
    };
    np root=new node();
    T update(lint a,lint b,E x,lint l,lint r,np t){
        eval(t,l,r);
        //区間外
        if(r<=a||b<=l)return t->val;
        //全部区間内
        if(a<=l&&r<=b){
            t->lazy=x;
            eval(t,l,r);
            return t->val;
        }
        //一部区間内
        return t->val=f(update(a,b,x,l,(l+r)/2,t->lch),update(a,b,x,(l+r)/2,r,t->rch));
    }
    T get(lint a,lint b,lint l,lint r,np t){
        eval(t,l,r);
        //区間外
        if(r<=a||b<=l)return et;
        //全部区間内
        if(a<=l&&r<=b)return t->val;
        //一部区間内
        return f(get(a,b,l,(l+r)/2,t->lch),get(a,b,(l+r)/2,r,t->rch));
    }
    void eval(np t,lint l,lint r){
        if(r-l>1){
            if(!t->lch)t->lch=new node();
            if(!t->rch)t->rch=new node();
            t->lch->lazy=g(t->lch->lazy,t->lazy);
            t->rch->lazy=g(t->rch->lazy,t->lazy);
        }
        t->val=h(t->val,t->lazy,r-l);
        t->lazy=ee;
    }
    static T et;
    static E ee;
    T f(T a,T b){
        return a+b;
    }
    T h(T a,E b,lint len){
        return a*b.first+b.second*len;
    }
    E g(E a,E b){
        return {a.first*b.first,b.second+b.first*a.second};
    }
    //auto update(auto a,auto b){return b==ee?a:b;}
    public:
    dynamic_lazy_segment(lint sz):n(1),sz(sz){while(n<sz)n<<=1;}
    dynamic_lazy_segment():n(1LL<<60),sz(1LL<<60){}
    //0-indexed [a,b)
    void update(lint a,lint b,E x){update(a,b,x,0,n,root);}
    //0-indexed [a,b)
    T get(lint a,lint b){return get(a,b,0,n,root);}
};
template<typename T,typename E>T dynamic_lazy_segment<T,E>::et=0;
template<typename T,typename E>E dynamic_lazy_segment<T,E>::ee={1,0};