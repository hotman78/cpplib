template<typename T,typename E=T>
struct treap{
    using F=function<E(E,E)>;
    vector<F> func;
    struct node{
        unsigned long xor128() {
            static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
            unsigned long t=(x^(x<<11));
            x=y; y=z; z=w;
            return ( w=(w^(w>>19))^(t^(t>>8)) );
        }
        node* ch[2]={nullptr,nullptr};
        T key;
        E val;
        treap<T,E> par;
        vector<E> vals;
        lint pri=xor128(),cnt=1;
        node(T key,E val,treap<T,E>* par):key(key),val(val),par(par){vals.resize(par->func.size());}
        operator E(){return val;}
        node& operator =(const T& v){val=v;return *this;}
    };
    template<typename... F>
    treap(F... f){
        func.insert(func.end(),{f...});
    }
    node *root=nullptr;
    node* insert(T key){
        return emplace(key,key);
    }
    node* emplace(T key,E val){
        node* res;
        auto d=split(root,lower_bound(root,key));
        root=merge(merge(d.first,res=new node(key,val,this)),d.second);
        return res;
    }
    size_t size(){
        return count(root);
    }
    void erase_all(T key){
        auto d=split(root,upper_bound(root,key));
        root=merge(split(d.first,lower_bound(d.first,key)).first,d.second);
    }
    void erase(T key){
        if(get(lower_bound(root,key))!=key)return;
        auto d=split(root,lower_bound(root,key));
        root=merge(d.first,split(d.second,1).second);
    }
    vector<E> operator ()(const int& l,const int& r){
        auto s=split(root,lower_bound(root,l));
        auto t=split(s.second,lower_bound(s.second,r));
        vector<E>res;
        if(t.first)res=t.first->vals;
        root=merge(s.first,merge(t.first,t.second));
        return res;
    }
    node* operator[](const int& key){
        auto d=get(lower_bound(root,key));
        if(d->key==key)return d;
        else {
            return emplace(key,0);
        }
    }
    int lower_bound(T k){return lower_bound(root,k);}
    private:
    node* get(const int& k){
        pair<node*,node*>s,t;
        node* res=(t=split((s=split(root,lower_bound(root,k))).second,1)).first;
        root=merge(s.first,merge(t.first,t.second));
        return res;
    }
    int count(node* t){return !t?0:t->cnt;}
    node* update(node*& t){
        t->cnt=count(t->ch[0])+count(t->ch[1])+1;
        for(int i=0;i<(int)func.size();i++){
            t->vals[i]=t->val;
            if(t->ch[0])t->vals[i]=(func[i])(t->vals[i],t->ch[0]->vals[i]);
            if(t->ch[1])t->vals[i]=(func[i])(t->vals[i],t->ch[1]->vals[i]);
        }
        return t;
    }
    node* merge(node* l,node* r){
        if(!l||!r)return !l?r:l;
        if(l->pri>r->pri){
            l->ch[1]=merge(l->ch[1],r);
            return update(l);
        }else{
            r->ch[0]=merge(l,r->ch[0]);
            return update(r);
        }
    }
    //kより小さい値の数
    size_t lower_bound(node* t,T k){
        if(!t)return 0;
        else if(k<=(t->key))return lower_bound(t->ch[0],k);
        else return count(t->ch[0])+1+lower_bound(t->ch[1],k);
    }
    //k以下の値の数
    size_t upper_bound(node* t,T k){
        if(!t)return 0;
        else if(k<(t->key))return upper_bound(t->ch[0],k);
        else return count(t->ch[0])+1+upper_bound(t->ch[1],k);
    }
    //0-indexedでk番目から右側に
    pair<node*,node*> split(node* t,int k){
        if(!t)return make_pair(nullptr,nullptr);
        if(k<=count(t->ch[0])){
            auto s=split(t->ch[0],k);
            t->ch[0]=s.second;
            return make_pair(s.first,update(t));
        }else{
            auto s=split(t->ch[1],k-count(t->ch[0])-1);
            t->ch[1]=s.first;
            return make_pair(update(t),s.second);
        }
    }
};