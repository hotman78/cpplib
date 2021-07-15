template<typename T>
struct segment_tree_beats{
    struct node;
    using np=node*;
    using lint=long long;
    struct node{
        const T mx=1e18;
        const T mn=-1e18;
        T lazy_add=T(),lazy_update=mx;
        T max_v=T(),smax_v=mn;
        lint max_c;
        T min_v=T(),smin_v=mx;
        lint min_c;
        T sum=T();
        np ch[2]={nullptr,nullptr};
        node(T sz):max_c(sz),min_c(sz){}
    };
    np root=nullptr;
    const T mx=1e18;
    const T mn=-1e18;
    void update_node_max(np t,T x){
        t->sum+=(x-t->max_v)*t->max_c;
        if(t->max_v==t->min_v){
            t->max_v=t->min_v=x;
        }else if(t->max_v==t->smin_v){
            t->max_v=t->smin_v=x;
        }else{
            t->max_v=x;
        }
        if(t->lazy_update !=mx && x < t->lazy_update ) {
            t->lazy_update = x;
        }
    }
    void update_node_min(np t,T x){
        t->sum+=(x-t->min_v)*t->min_c;
        if(t->min_v==t->max_v){
            t->min_v=t->max_v=x;
        }else if(t->min_v==t->smax_v){
            t->min_v=t->smax_v=x;
        }else{
            t->min_v=x;
        }
        if(t->lazy_update !=mx && t->lazy_update < x ) {
            t->lazy_update = x;
        }
    }
    np __update_min(T x,lint a,lint b,lint l,lint r,np t){
        if(!t)t=new node(r-l);
        if(b<=l||r<=a||t->max_v<=x){
            return t;
        }
        if(a<=l&&r<=b&&t->smax_v<x){
            update_node_max(t,x);
            return t;
        }
        push(t,l,r);
        t->ch[0]=__update_min(x,a,b,l,(l+r)/2,t->ch[0]);
        t->ch[1]=__update_min(x,a,b,(l+r)/2,r,t->ch[1]);
        update(t,l,r);
        return t;
    }
    np __update_max(T x,lint a,lint b,lint l,lint r,np t){
        if(!t)t=new node(r-l);
        if(b<=l||r<=a||x<=t->min_v){
            return t;
        }
        if(a<=l&&r<=b&&x<t->smin_v){
            update_node_min(t,x);
            return t;
        }
        push(t,l,r);
        t->ch[0]=__update_max(x,a,b,l,(l+r)/2,t->ch[0]);
        t->ch[1]=__update_max(x,a,b,(l+r)/2,r,t->ch[1]);
        update(t,l,r);
        return t;
    }
    np __update_add(T x,lint a,lint b,lint l,lint r,np t){
        if(!t)t=new node(r-l);
        if(b<=l||r<=a){
            return t;
        }
        if(a<=l&&r<=b){
            addall(t,l,r,x);
            return t;
        }
        push(t,l,r);
        t->ch[0]=__update_add(x,a,b,l,(l+r)/2,t->ch[0]);
        t->ch[1]=__update_add(x,a,b,(l+r)/2,r,t->ch[1]);
        update(t,l,r);
        return t;
    }
    np __update_update(T x,lint a,lint b,lint l,lint r,np t){
        if(!t)t=new node(r-l);
        if(b<=l||r<=a){
            return t;
        }
        if(a<=l&&r<=b){
            updateall(t,l,r,x);
            return t;
        }
        push(t,l,r);
        t->ch[0]=__update_update(x,a,b,l,(l+r)/2,t->ch[0]);
        t->ch[1]=__update_update(x,a,b,(l+r)/2,r,t->ch[1]);
        update(t,l,r);
        return t;
    }
    T __get_sum(lint a,lint b,lint l,lint r,np t){
        if(!t)return T();
        //区間外
        if(b<=l||r<=a)return T();
        //全部区間内
        if(a<=l&&r<=b){
            return t->sum;
        }
        //一部区間内
        push(t,l,r);
        return __get_sum(a,b,l,(l+r)/2,t->ch[0])+__get_sum(a,b,(l+r)/2,r,t->ch[1]);
    }
    void updateall(np t,lint l,lint r,T x){
        t->max_v=x; t->smax_v=mn;
        t->min_v=x; t->smin_v=mx;
        t->max_c=t->min_c=r-l;
        t->sum=x*(r-l);
        t->lazy_update = x;
        t->lazy_add=T();
    }

    void addall(np t,lint l,lint r,T x){
        t->max_v+=x;
        if(t->smax_v!=mn)t->smax_v+=x;
        t->min_v+=x;
        if(t->smin_v!=mx)t->smin_v+=x;
        t->sum+=x*(r-l);
        if(t->lazy_update != mx) {
            t->lazy_update+= x;
        } else {
            t->lazy_add+=x;
        }
    }
    void push(np t,lint l,lint r){
        if(r-l==1)return;
        if(!t->ch[0])t->ch[0]=new node((r-l)/2);
        if(!t->ch[1])t->ch[1]=new node((r-l)/2);
        if(t->lazy_update != mx) {
            updateall(t->ch[0],l,(l+r)/2,t->lazy_update);
            updateall(t->ch[1],(l+r)/2,r,t->lazy_update);
            t->lazy_update = mx;
            return;
        }
        if(t->lazy_add != T()) {
            addall(t->ch[0],l,(l+r)/2,t->lazy_add);
            addall(t->ch[1],(l+r)/2,r,t->lazy_add);
            t->lazy_add = T();
        }
        if(t->max_v<t->ch[0]->max_v){
            update_node_max(t->ch[0],t->max_v);
        }
        if(t->min_v>t->ch[0]->min_v){
            update_node_min(t->ch[0],t->min_v);
        }
        if(t->max_v<t->ch[1]->max_v){
            update_node_max(t->ch[1],t->max_v);
        }
        if(t->min_v>t->ch[1]->min_v){
            update_node_min(t->ch[1],t->min_v);
        }
    }
    void update(np t,lint l,lint r){
        if(r-l==1)return;
        if(!t->ch[0])t->ch[0]=new node((r-l)/2);
        if(!t->ch[1])t->ch[1]=new node((r-l)/2);
        t->sum=t->ch[0]->sum+t->ch[1]->sum;
        if(t->ch[0]->max_v < t->ch[1]->max_v){
            t->max_v=t->ch[1]->max_v;
            t->max_c=t->ch[1]->max_c;
            t->smax_v=max(t->ch[0]->max_v,t->ch[1]->smax_v);
        }else if(t->ch[1]->max_v < t->ch[0]->max_v){
            t->max_v=t->ch[0]->max_v;
            t->max_c=t->ch[0]->max_c;
            t->smax_v=max(t->ch[1]->max_v,t->ch[0]->smax_v);
        }else{
            t->max_v=t->ch[0]->max_v;
            t->max_c=t->ch[0]->max_c+t->ch[1]->max_c;
            t->smax_v=max(t->ch[0]->smax_v,t->ch[1]->smax_v);
        }
        if(t->ch[0]->min_v > t->ch[1]->min_v){
            t->min_v=t->ch[1]->min_v;
            t->min_c=t->ch[1]->min_c;
            t->smin_v=min(t->ch[0]->min_v,t->ch[1]->smin_v);
        }else if(t->ch[1]->min_v > t->ch[0]->min_v){
            t->min_v=t->ch[0]->min_v;
            t->min_c=t->ch[0]->min_c;
            t->smin_v=min(t->ch[1]->min_v,t->ch[0]->smin_v);
        }else{
            t->min_v=t->ch[0]->min_v;
            t->min_c=t->ch[0]->min_c+t->ch[1]->min_c;
            t->smin_v=min(t->ch[0]->smin_v,t->ch[1]->smin_v);
        }
    }
    lint sz,n=1;
    public:
    segment_tree_beats(lint sz):sz(sz){
        while(n<sz)n<<=1;
    }
    segment_tree_beats():sz(1LL<<60),n(1LL<<60){}
    void chmax(lint l,lint r,T x){
        root=__update_max(x,l,r,0,n,root);
    }
    void chmin(lint l,lint r,T x){
        root=__update_min(x,l,r,0,n,root);
    }
    void add(lint l,lint r,T x){
        root=__update_add(x,l,r,0,n,root);
    }
    void update(lint l,lint r,T x){
        root=__update_update(x,l,r,0,n,root);
    }
    T get_sum(lint l,lint r){
        return __get_sum(l,r,0,n,root);
    }
};