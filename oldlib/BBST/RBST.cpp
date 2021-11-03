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
        auto d=split(t,key);
        t=merge(d.first,merge(update(p),d.second));
    }
    np erase(np& t,T key){
        int idx=lower_bound(t,key);
        auto d=split(t,idx,idx+1);
        t=merge(get<0>(d),get<2>(d));
    }
    np erase_all(np& t,T key){
        auto d=split_by_order(t,lower_bound(t,key),upper_bound(t,key));
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
        tie(p,q,r)=split_by_order(t,k,k+1);
        if(q){
            t=merge(p,q,r);
            return q->key;
        }
    }
    T find_by_order(np& t,const int& k){
        np p,q,r;
        tie(p,q,r)=split_by_order(t,k,k+1);
        assert(q);
        auto d=q->val;
        t=merge(p,q,r);
        return d;
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


// template<typename T,typename E>
// struct RBST{
//     using F=function<E(E,E)>;
//     vector<F> func;
//     inline unsigned long rnd() {
//         static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
//         unsigned long t=(x^(x<<11));
//         x=y; y=z; z=w;
//         return ( w=(w^(w>>19))^(t^(t>>8)) );
//     }
//     struct node{
//         node* ch[2]={nullptr,nullptr};
//         T key;
//         E val;
//         RBST<T,E>* par;
//         vector<E> vals;
//         int cnt=1;
//         node(T key,E val,RBST<T,E>* par):key(key),val(val),par(par){
//             vals.resize(par->func.size());
//             par->update(this);
//         }
//         operator E(){return val;}
//         node& operator =(const T& v){val=v;return *this;}
//     };
//     using np=node*;
//     np stk=nullptr;
//     np root=nullptr;
//     RBST(){}
//     RBST(F f...){
//         func.insert(func.end(),{f});
//     }
//     np emplace(T key,E val){
//         reload();
//         np res=new node(key,val,this);
//         insert(res);
//         return res;
//     }
//     size_t size(){
//         reload();
//         return count(root);
//     }
//     void erase_all(T key){
//         reload();
//         auto d=split(root,upper_bound(root,key));
//         root=merge(split(d.first,lower_bound(d.first,key)).first,d.second);
//     }
//     np erase(T key){
//         reload();
//         auto tmp=get(key);
//         if(!tmp)return nullptr;
//         auto s=split(root,lower_bound(root,key));
//         auto t=split(s.second,1);
//         root=merge(s.first,t.second);
//         return t.first;
//     }
//     vector<E> operator ()(const int& l,const int& r){
//         reload();
//         auto s=split(root,lower_bound(root,l));
//         auto t=split(s.second,lower_bound(s.second,r));
//         vector<E>res;
//         if(t.first)res=t.first->vals;
//         else res.resize(func.size(),E());
//         root=merge(s.first,merge(t.first,t.second));
//         return res;
//     }
//     E& operator[](const int& key){
//         reload();
//         auto d=get(key);
//         if(d){
//             stk=erase(d->key);
//             return stk->val;
//         }else {
//             stk=new node(key,E(),this);
//             return stk->val;
//         }
//     }
//     int lower_bound(T k){reload();return lower_bound(root,k);}
//     int upper_bound(T k){reload();return upper_bound(root,k);}
//     bool binary_search(T k){reload();return get(k);}
//     private:
//     inline void insert(np n){
//         if(!n)return;
//         auto d=split(root,lower_bound(root,n->key));
//         root=merge(d.first,merge(update(n),d.second));
//     }
//     inline np get(const int& k){
//         pair<np,np>s,t;
//         np res=(t=split((s=split(root,lower_bound(root,k))).second,1)).first;
//         root=merge(s.first,merge(t.first,t.second));
//         if(res&&res->key==k)return res;
//         return nullptr;
//     }
//     inline int count(np t){return !t?0:t->cnt;}
//     inline np update(np t){
//         t->cnt=count(t->ch[0])+count(t->ch[1])+1;
//         for(int i=0;i<(int)func.size();i++){
//             t->vals[i]=t->val;
//             if(t->ch[0])t->vals[i]=(func[i])(t->vals[i],t->ch[0]->vals[i]);
//             if(t->ch[1])t->vals[i]=(func[i])(t->vals[i],t->ch[1]->vals[i]);
//         }
//         return t;
//     }
//     inline np merge(np l,np r){
//         if(!l||!r)return !l?r:l;
//         if((unsigned long)count(l)>rnd()%(unsigned long)(count(l)+count(r))){
//             l->ch[1]=merge(l->ch[1],r);
//             return update(l);
//         }else{
//             r->ch[0]=merge(l,r->ch[0]);
//             return update(r);
//         }
//     }
//     //kより小さい値の数
//     inline int lower_bound(np t,T k){
//         if(!t)return 0;
//         if(k<=(t->key))return lower_bound(t->ch[0],k);
//         else return count(t->ch[0])+1+lower_bound(t->ch[1],k);
//     }
//     //k以下の値の数
//     inline int upper_bound(np t,T k){
//         if(!t)return 0;
//         if(k<(t->key))return upper_bound(t->ch[0],k);
//         else return count(t->ch[0])+1+upper_bound(t->ch[1],k);
//     }
//     //0-indexedでk番目から右側に
//     inline pair<np,np> split(np t,int k){
//         if(!t)return make_pair(nullptr,nullptr);
//         if(k<=count(t->ch[0])){
//             auto s=split(t->ch[0],k);
//             t->ch[0]=s.second;
//             return make_pair(s.first,update(t));
//         }else{
//             auto s=split(t->ch[1],k-count(t->ch[0])-1);
//             t->ch[1]=s.first;
//             return make_pair(update(t),s.second);
//         }
//     }
//     inline void reload(){
//         if(stk){insert(stk);}
//         stk=nullptr;
//     }
// };
 