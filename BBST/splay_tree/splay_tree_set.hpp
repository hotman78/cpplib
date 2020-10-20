#include"./splay_tree_base.hpp"

template<typename T>
struct splay_tree_set_node{
    using np=splay_tree_set_node*;
    np ch[2]={0,0};
    int sz=1;
    T val;
    splay_tree_set_node(T val):val(val){}
    int size(np t){return t?t->sz:0;}
    np push(){}
    np update(){
        sz=size(ch[0])+1+size(ch[1]);
        return this;
    }
};

template<typename T>
struct splay_tree_array:splay_tree_base<splay_tree_set_node<T>>{
    using node=splay_tree_set_node<T>;
    using super=splay_tree_base<node>;
    inline int size(){return super::size(super::root);}
    inline void insert(int idx,T val){return super::insert(idx,new node(val));}
    inline void erase(int idx){return super::erase(idx);}
    inline T& back(){return (*this)[size()-1];}
    inline T& front(){return (*this)[0];}
    T& operator[](int idx){return super::get(idx)->val;}
};