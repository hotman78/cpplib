#pragma once
#include"../alga/maybe.hpp"

template<typename T,typename E,typename F,typename G,typename H>
class lazy_segment_tree{
    using i64=long long;
    i64 n;
    i64 sz;
    struct node;
    using np=node*;
    struct node{
        maybe<T> val=maybe<T>();
        maybe<E> lazy=maybe<E>();
        np lch=nullptr,rch=nullptr;
        node(){}
    };
    np root=new node();
    maybe<T> update(i64 a,i64 b,E x,i64 l,i64 r,np t){
        auto f=expand<T,F>(_f);
        eval(t,l,r);
        //区間外
        if(r<=a||b<=l)return t->val;
        //全部区間内
        if(a<=l&&r<=b){
            t->lazy=x;
            eval(t,l,r);
            return t->val;
        }
        //一部区間内
        return t->val=f(update(a,b,x,l,(l+r)/2,t->lch),update(a,b,x,(l+r)/2,r,t->rch));
    }
    maybe<T> get(i64 a,i64 b,i64 l,i64 r,np t){
        auto f=expand<T,F>(_f);
        eval(t,l,r);
        //区間外
        if(r<=a||b<=l)return maybe<T>();
        //全部区間内
        if(a<=l&&r<=b)return t->val;
        //一部区間内
        return f(get(a,b,l,(l+r)/2,t->lch),get(a,b,(l+r)/2,r,t->rch));
    }
    void eval(np t,i64 l,i64 r){
        auto g=expand<E,G>(_g);
        if(r-l>1){
            if(!t->lch)t->lch=new node();
            if(!t->rch)t->rch=new node();
            t->lch->lazy=g(t->lch->lazy,t->lazy);
            t->rch->lazy=g(t->rch->lazy,t->lazy);
        }
        t->val=h(t->val,t->lazy,l,r);
        t->lazy=maybe<E>();
    }
    F _f;G _g;H _h;
    maybe<T> h(const maybe<T>&s,const maybe<E>&t,i64 l,i64 r){
        if(t.is_none())return s;
        else return maybe<T>(_h(s,t.unwrap(),l,r));
    }
    public:
    lazy_segment_tree(i64 sz,F f=F(),G g=G(),H h=H()):n(1),sz(sz),_f(f),_g(g),_h(h){while(n<sz)n<<=1;}
    //0-indexed [a,b)
    void update(i64 a,i64 b,E x){update(a,b,x,0,n,root);}
    //0-indexed [a,b)
    maybe<T> get(i64 a,i64 b){return get(a,b,0,n,root);}
};