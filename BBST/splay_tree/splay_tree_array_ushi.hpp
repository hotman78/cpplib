#include"./splay_tree_base.hpp"

template<typename T,typename F>
struct splay_tree_array_ushi_node{
    using np=splay_tree_array_ushi_node*;
    np ch[2]={0,0};
    int sz=1;
    T val,sum;
    F op;
    splay_tree_array_ushi_node(T val,F op):val(val),op(op){}
    int size(np t){return t?t->sz:0;}
    np push(){}
    np update(){
        sz=size(ch[0])+1+size(ch[1]);
        sum=val;
        if(ch[0])sum=op(ch[0]->sum,sum);
        if(ch[1])sum=op(sum,ch[1]->sum);
        return this;
    }
};

template<typename T,typename F>
struct splay_tree_array_ushi:splay_tree_base<splay_tree_array_ushi_node<T,F>>{
    using node=splay_tree_array_ushi_node<T,F>;
    using super=splay_tree_base<node>;
    using np=node*;
    F op;
    splay_tree_array_ushi(F op=F()):op(op){}
    inline int size(){return super::size(super::root);}
    inline void insert(int idx,T val){return super::insert(idx,new node(val,op));}
    inline void erase(int idx){return super::erase(idx);}
    inline void push_back(T val){insert(size(),val);}
    inline void pop_back(T val){erase(size()-1,val);}
    inline T back(){return (*this)[size()-1];}
    inline T front(){return (*this)[0];}
    T operator[](int idx){return super::get(idx)->val;}
    void update(int idx,T val){
        np t=super::get(idx);
        t->val=val;
        t->update();
    }
    T fold(int l,int r){
        auto [p,q]=super::split(super::root,l);
        auto [s,t]=super::split(q,r-l);
        T res=s->sum;
        super::root=super::merge(p,super::merge(s,t));
        return res;
    }
};