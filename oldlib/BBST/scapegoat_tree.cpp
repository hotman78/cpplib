template<typename T>
class scapegoat_tree{
    struct node;
    using np=node*;
    struct node{
        T val;
        int sz=1,sz2=1,sz3=1;
        int cnt=1;
        np ch[2]={0,0};
        node(T val):val(val){}
    };
    np root=0;
    double alpha=0.7;
    int sz(np t){return t?t->sz:0;};
    int sz2(np t){return t?t->sz2:0;};
    int sz3(np t){return t?t->sz3:0;};
    np update(np t){
        t->sz=sz(t->ch[0])+t->cnt+sz(t->ch[1]);
        t->sz2=sz2(t->ch[0])+1+sz2(t->ch[1]);
        t->sz3=sz3(t->ch[0])+(!!t->cnt)+sz3(t->ch[1]);
        if(max(sz2(t->ch[0]),sz2(t->ch[1]))>alpha*t->sz2){
            np* v=new np[t->sz3];
            int idx=0;
            auto dfs=[&](auto f,np t){
                if(!t)return;
                f(f,t->ch[0]);
                if(t->cnt)v[idx++]=t;
                f(f,t->ch[1]);
            };
            dfs(dfs,t);
            return make_tree(v,v+t->sz3);
        }
        return t;
    }
    np make_tree(np* l,np* r){
        np* m=l+(r-l)/2;
        if(l==r)return 0;
        np res=*m;
        res->ch[0]=make_tree(l,m);
        res->ch[1]=make_tree(m+1,r);
        return update(res);
    }
    np insert(np t,T x){
        if(!t)return new node(x);
        if(t->val==x){
            if(t->cnt)++t->cnt;
        }else{
            bool b=t->val<x;
            t->ch[b]=insert(t->ch[b],x);
        }
        return update(t);
    }
    np erase(np t,T x){
        if(!t)return 0;
        if(t->val==x){
            if(t->cnt)--t->cnt;
        }else{
            bool b=t->val<=x;
            t->ch[b]=erase(t->ch[b],x);
        }
        return update(t);
    }
    public:
    void insert(T x){root=insert(root,x);}
    void erase(T x){root=erase(root,x);}
    int size(){return sz(root);}
};
