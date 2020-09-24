#pragma once
#include"../alga/maybe.hpp"

/**
 * @brief 双対セグメント木
 */

template<typename T,typename F>
class dual_segment_tree{
	struct node;
	using np=node*;
	using i64=long long;
	struct node{
		maybe<T> val;
		np ch[2]={nullptr,nullptr};
		node(maybe<T> val=maybe<T>()):val(val){}
	};
	np root=nullptr;
	i64 n=1,sz;
    F op;
	public:
	dual_segment_tree(i64 sz,F op=F()):sz(sz),op(op){while(n<sz)n<<=1;}
	inline void update(i64 l,i64 r,T x){update(l,r,x,0,n,root);}
	inline maybe<T> get(i64 x){return get(x,0,n,root);}
	private:
	void eval(np& t){
        auto f=expand<T,F>(op);
		if(t->val.is_none())return;
		if(!t->ch[0])t->ch[0]=new node();
		if(!t->ch[1])t->ch[1]=new node();
		t->ch[0]->val=f(t->ch[0]->val,t->val);
		t->ch[1]->val=f(t->ch[1]->val,t->val);
		t->val=maybe<T>();
	}
	void update(i64 a,i64 b,T x,i64 l,i64 r,np& t){
        auto f=expand<T,F>(op);
        if(!t)t=new node();
		if(r-l>1)eval(t);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b)t->val=f(t->val,x);
	    else if(r-l>1){
			update(a,b,x,l,(l+r)/2,t->ch[0]);
			update(a,b,x,(l+r)/2,r,t->ch[1]);
		}
	}
	maybe<T> get(i64 x,i64 l,i64 r,np& t){
        auto f=expand<T,F>(op);
        if(!t)t=new node();
		if(r-l>1)eval(t);
		if(x<l||r<=x)return maybe<T>();
        else if(r-l==1){
            return t->val;
        }
		else return f(get(x,l,(l+r)/2,t->ch[0]),get(x,(l+r)/2,r,t->ch[1]));
	}
};