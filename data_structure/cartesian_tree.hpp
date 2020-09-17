#pragma once
#include<vector>
#include<stack>

template<typename T>
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
    cartesian_tree(std::vector<T>v){
        for(auto e:v)push_back(e);
    }
    void push_back(int val){
        static std::stack<np>stk;
        while(!stk.empty()&&stk.top()->val<=val)stk.pop();
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
};