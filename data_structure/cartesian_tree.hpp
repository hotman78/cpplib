#pragma once
#include<vector>
#include<stack>
#include<cstdint>
#include<functional>

/**
 * @brief cartesian_tree
 */

template<typename T,typename F=std::less<T>>
struct cartesian_tree{
    struct node;
    using np=node*;
    struct node{
        np ch[2]={0,0};
        T val;
        int pos;
        int sz=0;
        node(T val,int pos):val(val),pos(pos){}
    };
    int size(np t){return t?t->sz:0;}
    np update(np t){}
    np root=0;
    int sz=0;
    F comp;
    cartesian_tree(std::vector<T>v,F comp):comp(comp){
        for(auto e:v)push_back(e);
    }
    cartesian_tree(std::vector<T>v):comp(F()){
        for(auto e:v)push_back(e);
    }
    cartesian_tree(F comp):comp(comp){}
    cartesian_tree():comp(F()){}

    void push_back(int val){
        static std::stack<np>stk;
        while(!stk.empty()&&comp(val,stk.top()->val))stk.pop();
        np t=new node(val,sz);
        if(stk.empty()){
            t->ch[0]=root;
            root=t;
        }else{
            t->ch[0]=stk.top()->ch[1];
            stk.top()->ch[1]=t;
        }
        stk.emplace(t);
        sz++;
    }
    std::int64_t update_size(np t){
        if(!t)return 0;
        return t->sz=update_size(t->ch[0])+1+update_size(t->ch[1]);
    }
    std::vector<T>get(){
		std::vector<T>v(sz);
		auto f=[&](auto f,np t){
			if(!t)return;
			f(f,t->ch[0]);
			if(t->ch[0])v[t->ch[0]->pos]=t->pos;
			if(t->ch[1])v[t->ch[1]->pos]=t->pos;
			f(f,t->ch[1]);
		};
		v[root->pos]=root->pos;
		f(f,root);
		return v;
	}
};