#pragma once
#include<string>

struct trie{
    struct node;
    using np=node*;
    struct node{
        int sz=0,sz2=0;
        np ch[26]={};
    };
    np root=new node();
    void add(std::string s){
        np t=root;
        t->sz++;
        for(int i=0;i<(int)s.size();++i){
            if(!t->ch[s[i]-'a'])t->ch[s[i]-'a']=new node();
            t=t->ch[s[i]-'a'];
            t->sz++;
        }
        t->sz2=1;
    }
};