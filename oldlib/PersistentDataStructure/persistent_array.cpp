
template<typename T>
struct pvector{
    struct node;
    using np=node*;
    struct node{
        T data=0;
        np ch[16];
        node(){
            for(int i=0;i<16;i++)ch[i]=nullptr;
        }
    };
    np root=nullptr;
    np set(lint idx,T val,np t){
        np res=t?new node(*t):new node();
        if(idx==0)res->data=val;
        else res->ch[idx&15]=set(idx>>4,val,res->ch[idx&15]);        
        return res;
    }
    T get(lint idx,np t){
        if(!t)return T();
        return idx?get(idx>>4,t->ch[idx&15]):t->data;
    }
    public:
    pvector(){}
    pvector(np t):root(t){}
    T get(lint idx){
        return get(idx,root);
    }
    pvector set(lint idx,T val){
        return pvector(set(idx,val,root));
    }
};