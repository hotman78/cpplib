#pragma once

/**
 * @brief マージ可能ヒープ(LeftistHeap)
 */

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
        if(!a||!b)return a?a:b;
        if(a->val>b->val)swap(a,b);
        a->ch[1]=meld(a->ch[1],b);
        if(!a->ch[0]||a->ch[0]->s<a->ch[1]->s)swap(a->ch[0],a->ch[1]);
        a->s=(a->ch[1]?a->ch[1]->s:0)+1;
        return a;
    }
    void meld(heap b){
        root=meld(root,b.root);
    }
    void insert(T x){
        root=meld(root,new node(x));
    }
    void pop(){
        root=meld(root->ch[0],root->ch[1]);
    }
    T top(){
        return root?root->val:T();
    }
};