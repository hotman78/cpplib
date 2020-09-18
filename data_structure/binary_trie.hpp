#pragma once
#include<cstdint>

/**
 * @brief BinaryTrie
 */

struct binary_trie{
    constexpr static int B=64;
    using u64=std::uint64_t;
    struct node{
        node* ch[2]={0,0};
        int cnt=0;
    };
    using np=node*;
    np root=new node();
    void insert(u64 x){
        np t=root;
        t->cnt++;
        for(int i=B-1;i>=0;--i){
            if(!t->ch[0])t->ch[0]=new node();
            if(!t->ch[1])t->ch[1]=new node();
            t=t->ch[(x>>i)&1];
            t->cnt++;
        }
    }
    bool erase(u64 x){
        np t=root;
        if(!count(x))return 0;
        t->cnt--;
        for(int i=B-1;i>=0;--i){
            if(!t->ch[0])t->ch[0]=new node();
            if(!t->ch[1])t->ch[1]=new node();
            t=t->ch[(x>>i)&1];
            t->cnt--;
        }
        return 1;
    }
    int count(u64 x){
        np t=root;
        for(int i=B-1;i>=0;--i){
            if(!t->ch[0])t->ch[0]=new node();
            if(!t->ch[1])t->ch[1]=new node();
            t=t->ch[(x>>i)&1];
        }
        return t->cnt;
    }
    u64 min_element(u64 x){
        np t=root;
        u64 res=0;
        for(int i=B-1;i>=0;--i){
            if(!t->ch[0])t->ch[0]=new node();
            if(!t->ch[1])t->ch[1]=new node();
            if(t->ch[(x>>i)&1]->cnt)t=t->ch[(x>>i)&1];
            else{
                t=t->ch[1-((x>>i)&1)];
                res+=1ULL<<i;
            }
        }
        return res;
    }
};