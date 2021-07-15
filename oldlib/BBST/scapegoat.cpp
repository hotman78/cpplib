template<typename T,typename E>
class scapegoat_tree{
    struct node{
        T key;E val,cal;
        int cnt=1;
        int dep=0;
        bool removed=0;
        node* ch[2]={nullptr,nullptr};
        node(T key,E val):key(key),val(val){}
    };
    using np=node*;
    np root=nullptr;
    inline int count(np t){return t?t->cnt:0;}
    inline int depth(np t){return t?t->dep:0;}
    np update_node(np& t){
        t->cnt=count(t->ch[0])+(!t->removed)+count(t->ch[1]);
        t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;
        if(depth(t)>2*(log2(count(t))+1)){
            rebuild(t,get(t));
        }
        return t;
    }

    public:
    void update(T key,E val){update(key,val,root);}
    void erase(T key){erase(key,root);}
    int lower_bound(T key){return lower_bound(key,root);}
    T get_key_by_order(int idx){return get_node_by_order(idx,root)->key;}
    E get_by_order(int idx){return get_node_by_order(idx,root)->val;}
    T get(T key){auto t=get_node_by_key();return t?t->val:T();}

    int count(T key){return get_key_by_order(lower_bound(key))==key;}

    private:
    inline void update(T key,E val,np& t){
        if(!t)t=new node(key,val);
        else if(key==t->key&&t->removed){
            t->removed=0;
            t=new node(key,val);
        }
        else if(key==t->key){
            t->val=upd(t->val,val);
        }
        else if(key<t->key)update(key,val,t->ch[0]);
        else if(key>t->key)update(key,val,t->ch[1]);
        update_node(t);
    }
    void erase(T key,np& t){
        if(!t)return;
        else if(key==t->key)t->removed=1;
        else if(key<t->key)erase(key,t->ch[0]);
        else if(key>t->key)erase(key,t->ch[1]);
        update_node(t);
    }
    int lower_bound(T key,np t){
        if(!t)return 0;
        if(key==t->key)return count(t->ch[0]);
        if(key<t->key)return lower_bound(key,t->ch[0]);
        else return count(t->ch[0])+1+lower_bound(key,t->ch[1]);
    }
    np get_node_by_key(T key,np t){
        if(!t)return nullptr;
        if(key==t->key)return t;
        if(key<t->key)return get_node_by_key(key,t->ch[0]);
        else return count(t->ch[0])+1+get_node_by_key(key,t->ch[1]);
    }
    np get_node_by_order(int idx,np t){
        assert(0<=idx&&idx<count(t));
        if(idx==count(t->ch[0]))return t;
        else if(idx<count(t->ch[0]))return get_node_by_order(idx,t->ch[0]);
        else return get_node_by_order(idx-count(t->ch[0])-1,t->ch[1]);
    }
    void rebuild(np& t,vector<pair<T,E>> v){
        if(v.size()==0){t=nullptr;return;}
        int n=v.size();
        int mid=n/2;
        t=new node(v[mid].first,v[mid].second);
        vector<pair<T,E>> v1(mid),v2(n-mid-1);
        for(int i=0;i<mid;i++)v1[i]=v[i];
        for(int i=mid+1;i<n;i++)v2[i-mid-1]=v[i];
        rebuild(t->ch[0],v1);
        rebuild(t->ch[1],v2);
        update_node(t);
    }
    vector<pair<T,E>> get(np t){
        vector<pair<T,E>>v(count(t));
        int i=0;
        get(t,v,i);
        return v;
    }
    void get(np t,vector<pair<T,E>>& v,int& i){
        if(!t)return;
        get(t->ch[0],v,i);
        if(!t->removed)v[i++]=make_pair(t->key,t->val);
        get(t->ch[1],v,i);
    }
    inline E upd(const E& s,const E& t){
        return s+t;
    }
};