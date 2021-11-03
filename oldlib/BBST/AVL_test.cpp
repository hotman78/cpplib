using T=lint;
using np=struct node*;
struct node{
    T val;
    int sz=1,dep=1;
    node* ch[2]={0,0};
    node(T val):val(val){}
    void cpy(np t){val=t->val;}
};
int sz(np t){return t?t->sz:0;}
int dep(np t){return t?t->dep:0;}
np update(np&,bool);
np root=0;
int size(){return root?root->sz:0;}
np rot(np t){
    const bool b=dep(t->ch[0])<dep(t->ch[1]);
    if(dep(t->ch[0])==dep(t->ch[1]))return t;
    np s=t->ch[b];
    t->ch[b]=s->ch[1-b];
    s->ch[1-b]=t;
    update(t,0);update(s,0);
    return s;
}
np update(np& t,bool f=1){
    t->sz=sz(t->ch[0])+1+sz(t->ch[1]);
    t->dep=max(dep(t->ch[0]),dep(t->ch[1]))+1;
    if(f&&abs(dep(t->ch[0])-dep(t->ch[1]))==2){
        bool b=dep(t->ch[0])<dep(t->ch[1]);
        if(t->ch[b]&&dep(t->ch[b]->ch[b])<dep(t->ch[b]->ch[1-b])){
            t->ch[b]=rot(t->ch[b]);
        }
        t=rot(update(t,0));
    }
    return t;
}

void replace(np& t,np s){
    if(!t->ch[0])s->cpy(t),t=0;
    else replace(t->ch[0],s),update(t);
}
void insert(T x,np& t=root){
    if(!t){t=new node(x);return;}
    insert(x,t->ch[x>t->val]);
    update(t);
}
bool erase(T x,np& t=root){
    if(!t)return 0;
    bool res=1;
    if(x==t->val){
        if(t->ch[1])replace(t->ch[1],t);
        else t=new node(*t->ch[0]);
    }
    else res=erase(x,t->ch[x>t->val]);
    update(t);
    return res;
}