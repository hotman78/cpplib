#pragma once
#include<tuple>

template<typename Node>
struct AVL_base{
    using np=Node*;
    int sz(np t){return t?t->sz:0;}
    int dep(np t){return t?t->dep:0;}
    np update(np t){
        t->sz=sz(t->ch[0])+1+sz(t->ch[1]);
        t->dep=std::max(dep(t->ch[0]),dep(t->ch[1]))+1;
        return t;
    }
    np merge_with_root(np s,np t,np u){
        if(abs(sz(s)-sz(u))<2){
            t->ch[0]=s;t->ch[1]=u;
            return update(t);
        }
        if(sz(s)>sz(u)){
            s->ch[1]=merge_with_root(s->ch[1],t,u);
            return update(s);
        }else{
            u->ch[0]=merge_with_root(s,t,u->ch[0]);
            return update(t);
        }
    }
    np make_root(np& t){
        if(t->ch[1]){
            np res=make_root(t->ch[1]);
            update(t);
            return res;
        }else{
            np res=t;
            t=t->ch[0];
            return res;
        }
    }
    np merge(np s,np t){
        if(!s||!t)return s?s:t;
        np u=make_root(s);
        return merge_with_root(s,u,t);
    }
    std::pair<np,np> split(np t,int i){
        if(!t)return std::make_pair(0,0);
        np s=t->ch[0],u=t->ch[1];
        t->ch[0]=0;t->ch[1]=0;
        if(i==sz(s)){
            return make_pair(s,merge_with_root(0,t,u));
        }
        if(i<sz(s)){
            auto r=split(s,i);
            return make_pair(r.first,merge_with_root(r.second,t,u));
        }else{
            auto r=split(u,i-sz(s)-1);
            return make_pair(merge_with_root(s,t,r.first),r.second);
        }
    }
    //insert erase
    void insert(const np& x,np& t){
        if(!t)t=x;
        else if(*x<=*t)insert(x,t->ch[1]);
        else insert(x,t->ch[0]);
        t=balance(update(t));
    }
    bool erase(const np& x,np& t){
        if(!t)return false;
        else if(*x==*t){
            if(!t->ch[0]||!t->ch[1])t=t->ch[0]?t->ch[0]:t->ch[1];
            else move_down(t->ch[0],t);
            return true;
        }
        bool b;
        if(*x<*t)b=erase(x,t->ch[0]);
        else b=erase(x,t->ch[1]);
        t=balance(update(t));
        return b;
    }
    void move_down(np& t,np& p){
		if(t->ch[1])move_down(t->ch[1],p);
		else p->val=t->val,t=t->ch[0];
		t=balance(update(t));
	}
    np rot(np t){
		int b=dep(t->ch[0])<dep(t->ch[1]);
		if(dep(t->ch[0])==dep(t->ch[1]))return t;
		np s=t->ch[b];
		t->ch[b]=s->ch[1-b];
		s->ch[1-b]=t;
		update(t);update(s);
		return s;
	}
    np balance(np t){
        if(abs(dep(t->ch[0])-dep(t->ch[1]))!=2)return t;
        bool b=dep(t->ch[0])<dep(t->ch[1]);
		if(t->ch[b]&&dep(t->ch[b]->ch[b])<dep(t->ch[b]->ch[1-b])){
			t->ch[b]=rot(t->ch[b]);
		}
		return rot(update(t));
    }
};