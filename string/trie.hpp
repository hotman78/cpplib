#pragma once
#include<string>

/**
 * @brief Trie木
 */

struct trie{
    struct node;
    using np=node*;
    struct node{
        int sz=0,sz2=0;
        np ch[10];
        node(){
            for(int i=0;i<10;i++)ch[i]=nullptr;
        }
    };
    np root=new node();
    void add(const std::string& s){
        np t=root;
        t->sz++;
        for(int i=0;i<(int)s.size();++i){
            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new node();
            t=t->ch[s[i]-'0'];
            t->sz++;
        }
        t->sz2=1;
    }
    string count(const std::string& s){
        np t=root;
        int last=0;
        for(int i=0;i<(int)s.size();++i){
            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new node();
            t=t->ch[s[i]-'0'];
            if(t->sz2)last=i;
        }
        return s.substr(0,last+1);
    }
    int count2(const std::string& s){
        np t=root;
        for(int i=0;i<(int)s.size();++i){
            if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new node();
            t=t->ch[s[i]-'0'];
            if(!t->sz)return 0;
        }
        return t->sz2;
    }
    // int count_suffix(const std::string& s){
    //     np t=root;
    //     int res=0;
    //     for(int i=0;i<(int)s.size();++i){
    //         if(!t->ch[s[i]-'0'])t->ch[s[i]-'0']=new node();
    //         t=t->ch[s[i]-'0'];
    //         res+=t->sz2;
    //     }
    //     return res;
    // }
};