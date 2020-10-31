#include"./splay_tree_base.hpp"

template<typename T,typename E,typename F>
struct splay_tree_map_ushi_node{
    using np=splay_tree_map_ushi_node*;
    np ch[2]={0,0};
    int sz=1;
    T key;E val;E sum;F op;
    splay_tree_map_ushi_node(T key,E val,F op):key(key),val(val),sum(val),op(op){}
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

template<typename T,typename E,typename F>
struct splay_tree_map_ushi:splay_tree_base<splay_tree_map_ushi_node<T,E,F>>{
    using node=splay_tree_map_ushi_node<T,E,F>;
    using super=splay_tree_base<node>;
    using np=node*;
    F op;
    splay_tree_map_ushi(F op=F()):op(op){}
    inline int size(){return super::size(super::root);}
    int get_idx(T key){return super::lower_bound([&](np t){return t->key<key;});}
    inline void insert(T key,E val){
        return super::insert(get_idx(key),new node(key,val,op));
    }
    inline E back(){return (*this)[size()-1];}
    inline E front(){return (*this)[0];}
    bool contains(T key){
        int idx=get_idx(key);
        return idx<size()&&super::get(idx)->key==key;
    }
    E operator[](T key){return super::get(get_idx(key))->val;}
    E fold_idx(int l,int r){
        auto [p,q]=super::split(super::root,l);
        auto [s,t]=super::split(q,r-l);
        T res=s?s->sum:E();
        super::root=super::merge(p,super::merge(s,t));
        return res;
    }
    E fold(T l,T r){
        int ll=get_idx(l);
        int rr=get_idx(r);
        auto [p,q]=super::split(super::root,ll);
        auto [s,t]=super::split(q,rr-ll);
        E res=s?s->sum:E();
        super::root=super::merge(p,super::merge(s,t));
        return res;
    }
    template<typename G>
    void update(T key,G g){
        int idx=super::lower_bound([&](np t){return t->key<key;});
        np t=super::get(idx);
        g(t->val);
        t->update();
    }
};