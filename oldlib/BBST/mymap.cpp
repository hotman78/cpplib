template<typename T,typename E>
class mymap{
    struct node{
        T val,l,r;
        E val2,sum;
        int cnt=1,dep=0;
        static const node* nil;
        node* ch[2]={nullptr,nullptr};
        node(T val,E val2):val(val),l(val),r(val),val2(val2),sum(val2){}
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
        t->sum=f(t->sum,t->val2);
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
    np insert(T val,E val2,np t){
        if(!t)return new node(val,val2);
        bool b=t->val<val;
        t->ch[b]=insert(val,val2,t->ch[b]);
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
        return f(sum(l,r,t->ch[0]),f(b?t->val2:et,sum(l,r,t->ch[1])));
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
    void insert(T val,E val2){root=insert(val,val2,root);}
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