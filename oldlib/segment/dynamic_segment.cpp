template<typename T,typename E,typename R,typename F,typename G>
struct dynamic_segment{
    struct node;
    using np=node*;
    struct node{
        np ch[2]={0,0};
        T val;
        node(T e):val(e){}
    };
    np root=0;
    void update(int64_t l,int64_t r,int64_t x,E val,T e,F f){
        root=update(l,r,x,val,e,f,root);
    }
    R get(int64_t l,int64_t r,int64_t a,int64_t b,R e,F f,G g){
        return get(l,r,a,b,e,f,g,root);
    }
    np update(int64_t l,int64_t r,int64_t x,E val,T e,F f,np t){
        if(x<l||r<=x)return t;
        if(!t)t=new node(e);
        f(t->val,val);
        if(r-l!=1){
            int64_t m=(l+r)/2;
            t->ch[0]=update(l,m,x,val,e,f,t->ch[0]);
            t->ch[1]=update(m,r,x,val,e,f,t->ch[1]);
        }
        return t;
    }
    R get(int64_t l,int64_t r,int64_t a,int64_t b,R e,F f,G g,np t){
        if(!t)return e;
        if(b<=l||r<=a)return e;
        if(a<=l&&r<=b)return g(t->val);
        int64_t m=(l+r)/2;
        return f(get(l,m,a,b,e,f,g,t->ch[0]),get(m,r,a,b,e,f,g,t->ch[1]));
    }
};