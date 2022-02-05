#pragma once
#include<vector>
#include"../alga/maybe.hpp"

/**
 * @brief セグメント木
 * @see https://en.wikipedia.org/wiki/Segment_tree
 */

template<typename T,typename F>
class segment_tree{
    using i64=long long;
    struct node;
    using np=node*;
    struct node{
        maybe<T>val;
        np ch[2]={nullptr,nullptr};
        node(maybe<T> val=maybe<T>()):val(val){}
    };
    np root=new node();
    i64 n=1;
    i64 sz;
    F op;
	public:
    segment_tree(){}
	segment_tree(i64 sz,F op=F()):sz(sz),op(op){
		while(n<=sz)n<<=1;
	}
    maybe<T> get(i64 a,i64 b){
        return get(a,b,0,n,root);
    }
    void apply(i64 x,T val){
        apply(x,val,0,n,root);
    }
    void apply_left(i64 x,T val){
        apply_left(x,val,0,n,root);
    }
    void change(i64 x,T val){
        change(x,val,0,n,root);
    }
    maybe<T> get(i64 a,i64 b,i64 l,i64 r,np t){
        if(!t)return maybe<T>();
        auto f=expand<T,F>(op);
        if(r<=a||b<=l)return maybe<T>();
        if(a<=l&&r<=b){
            return t->val;
        }
        const i64 m=(l+r)/2;
        return f(get(a,b,l,m,t->ch[0]),get(a,b,m,r,t->ch[1]));
    }
    void apply(i64 x,T val,i64 l,i64 r,np t){
        auto f=expand<T,F>(op);
        if(!t->ch[0])t->ch[0]=new node();
        if(!t->ch[1])t->ch[1]=new node();
        if(l<=x&&x<r){
            t->val=f(t->val,val);
            const i64 m=(l+r)/2;
            if(r-l>1){
                apply(x,val,l,m,t->ch[0]);
                apply(x,val,m,r,t->ch[1]);
            }
        }
    }
    void apply_left(i64 x,T val,i64 l,i64 r,np t){
        if(!t->ch[0])t->ch[0]=new node();
        if(!t->ch[1])t->ch[1]=new node();
        auto f=expand<T,F>(op);
        if(l<=x&&x<r){
            t->val=f(val,t->val);
            i64 m=(l+r)/2;
            if(r-l>1){
                apply_left(x,val,l,m,t->ch[0]);
                apply_left(x,val,m,r,t->ch[1]);
            }
        }
    }
    maybe<T> change(i64 x,const T& val,i64 l,i64 r,np t){
        if(!t->ch[0])t->ch[0]=new node();
        if(!t->ch[1])t->ch[1]=new node();
        auto f=expand<T,F>(op);
        if(l<=x&&x<r){
            if(r-l>1){
                const i64 m=(l+r)/2;
                auto p=change(x,val,l,m,t->ch[0]);
                auto q=change(x,val,m,r,t->ch[1]);
                return t->val=f(p,q);
            }else{
                return t->val=val;
            }
        }
        return t->val;
    }
};

template<typename T>
struct MAX_F{
    T operator()(const T& s,const T& t){
        return max(s,t);
    }
};
template<typename T>using max_seg=segment_tree<T,MAX_F<T>>;