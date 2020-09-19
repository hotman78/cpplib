#pragma once
#include"../alga/maybe.hpp"

template<typename T,typename F>
class dual_segment_tree{
	struct node;
	using np=node*;
	struct node{
		maybe<T> val;
		np ch[2]={nullptr,nullptr};
		node(maybe<T> val=maybe<T>()):val(val){}
	};
	np root=nullptr;
	int n=1,sz;
    F op;
	public:
	dual_segment_tree(int sz,F op=F()):sz(sz),op(op){while(n<sz)n<<=1;}
	inline void set(int l,int r,T x){set(l,r,x,0,n,root);}
	inline maybe<T> get(int x){return get(x,0,n,root);}
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
	void set(int a,int b,T x,int l,int r,np& t){
        auto f=expand<T,F>(op);
        if(!t)t=new node();
		if(r-l>1)eval(t);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b)t->val=f(t->val,x);
	    else if(r-l>1){
			set(a,b,x,l,(l+r)/2,t->ch[0]);
			set(a,b,x,(l+r)/2,r,t->ch[1]);
		}
	}
	maybe<T> get(int x,int l,int r,np& t){
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