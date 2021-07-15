class persistent_union_find{
    template<typename T>
    struct persistent_array{
        struct node;
        using np=node*;
        struct node{
            T data;
            np ch[20];
        };
        np root=nullptr;
        persistent_array(){}
        np get_root(){
            return root;
        }
        void destructive_set(int idx,T val,np& t){
            if(!t)t=new node();
            if(idx==0){
                t->data=val;
            }else{
                destructive_set(idx/20,val,t->ch[idx%20]);
            }
        }
        np set(int idx,T val,const np& t){
            np res=new node();
            if(t){
                memcpy(res->ch,t->ch,sizeof(t->ch));
                res->data=t->data;
            }
            if(idx==0){
                res->data=val;
            }else{
                res->ch[idx%20]=set(idx/20,val,res->ch[idx%20]);
            }
            return res;
        }
        T get(int idx,np t){
            if(!t)return 0;
            if(idx==0){
                return t->data;
            }else{
                return get(idx/20,t->ch[idx%20]);
            }
        }
    };
    using lint=long long;
    using PA=persistent_array<lint>;
    PA data;
    public:
    using np=PA::np;
    persistent_union_find(){}
    np init(lint n){
        np res=data.get_root();
        for(lint i=0;i<n;i++)data.destructive_set(i,-1,res);
        return res;
    }
    pair<bool,np> unite(lint x,lint y,np t){
        x=root(x,t);y=root(y,t);
        if(x==y)return {0,t};
        if(data.get(x,t)>data.get(y,t))swap(x,y);
        np res=data.set(y,x,data.set(x,data.get(x,t)+data.get(y,t),t));
        return {1,res};
    }
    lint root(lint x,np t){
        if(data.get(x,t)<0)return x;
        else {
            lint res=root(data.get(x,t),t);
            return res;
        }
    }
    inline bool same(lint x, lint y,np t){return root(x,t)==root(y,t);}
	inline lint size(lint x,np t){return -data.get(root(x,t),t);}
};
using PUF=persistent_union_find;
using np=PUF::np;