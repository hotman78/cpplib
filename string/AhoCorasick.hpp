#pragma once
#include<string>
#include<queue>

/**
 * @brief Aho-Corasick法
 */

class AhoCorasick{
    struct node;
    using np=node*;
    constexpr static int num=26;
    constexpr static char base='A';
    struct node{
        np ch[num];
        np link=nullptr;
        int val=0;
        node(){
            for(int i=0;i<num;++i)ch[i]=nullptr;
        }
    };
    np root=new node();
    np root_par=new node();
    public:
    AhoCorasick(){
        root->link=root_par;
        for(int i=0;i<num;++i)root_par->ch[i]=root;
    }
    void insert(std::string v){
        np t=root;
        int idx=0;
        while(idx<(int)v.size()){
            if(!t->ch[v[idx]-base])t->ch[v[idx]-base]=new node();
            t=t->ch[v[idx]-base];
            idx++;
        }
        t->val++;
    }
    void build(){
        built=1;
        std::queue<np>que;
        que.push(root);
        while(!que.empty()){
            np t=que.front();
            que.pop();
            for(int i=0;i<num;++i){
                if(!t->ch[i])continue;
                if(t==root){
                    t->ch[i]->link=t;
                }else{
                    np s=t->link;
                    while(!s->ch[i]){
                        s=s->link;
                    }
                    t->ch[i]->link=s->ch[i];
                }
                que.push(t->ch[i]);
            }
        }
    }
    bool built=0;
    int count(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    idx++;
                    if(idx==(int)v.size())return res;
                }else{
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            auto s=t;
            while(s!=root){
                res+=s->val;
                s=s->link;
            }
        }
        return res;
    }
    int find_first(std::string v){
        if(!built){build();built=1;}
        np t=root;
        int idx=0;
        int res=0;
        while(idx<(int)v.size()){
            while(!t->ch[v[idx]-base]){
                if(t==root){
                    res++;
                    idx++;
                    if(idx==(int)v.size())return -1;
                }else{
                    res++;
                    t=t->link;
                }
            }
            t=t->ch[v[idx++]-base];
            if(t->val>0)return res;
        }
        return -1;
    }
};
