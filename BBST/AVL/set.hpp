#pragma once
#include"base.hpp"

template<typename T>
struct Node{
    T val,sum;
    int sz=1,dep=1;
    Node* ch[2]={0,0};
    Node(T val):val(val),sum(val){}
    void cpy(Node* t){val=t->val;}
    bool operator <(const Node& x)const{
        return val<x.val;
    }
    bool operator >(const Node& x)const{return (x)<(*this);}
    bool operator <=(const Node& x)const{return !((x)>(*this));}
    bool operator >=(const Node& x)const{return !((x)<(*this));}
    bool operator ==(const Node& x)const{return (x)<=(*this)&&(*this)<=(x);}
    void update(Node* t){
        
    }
};

template<typename T>
struct avl_set:public AVL_base<Node<T>>{
    using AVL_base<Node<T>>::AVL_base;
    using np=Node<T>*;
    np root=0;
    int lower_bound(np t,np x){
        if(*x<*t)return lower_bound(t->ch[0],x);
        else return AVL_base<Node<T>>::sz(t->ch[0])+1+lower_bound(t->ch[1],x);
    }
    int upper_bound(np t,np x){
        if(*x<=*t)return upper_bound(t->ch[0],x);
        else return AVL_base<Node<T>>::sz(t->ch[0])+1+upper_bound(t->ch[1],x);
    }
    int count(T x){
        np t=new Node<T>(x);
        return upper_bound(root,t)-lower_bound(root,t);
    }
    void insert(T x){
        np s=new Node<T>(x);
        AVL_base<Node<T>>::insert(s,root);
    }
    void erase(T x){
        np s=new Node<T>(x);
        AVL_base<Node<T>>::erase(s,root);
    }
};