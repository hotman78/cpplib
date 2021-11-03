template<typename T>
struct heap{
    struct node{
        node* ch[2]={0,0};
        int s;
        T val;
        node(T val):s(1),val(val){}
    };
    using np=node*;
    np root=0;
    heap(np t=0):root(t){}
    np meld(np a,np b){
        if(!b)return a?new node(*a):0;
        if(!a)return b?new node(*b):0;
        a=new node(*a);b=new node(*b);
        if(a->val>b->val)swap(a,b);
        a->ch[1]=meld(a->ch[1],b);
        if(!a->ch[0]||a->ch[0]->s<a->ch[1]->s)swap(a->ch[0],a->ch[1]);
        a->s=(a->ch[1]?a->ch[1]->s:0)+1;
        return a;
    }
    heap meld(heap b){
        return heap(meld(root,b.root));
    }
    heap insert(T x){
        return heap(meld(root,new node(x)));
    }
    heap pop(){
        return heap(meld(root->ch[0],root->ch[1]));
    }
    T top(){
        return root?root->val:T();
    }
};