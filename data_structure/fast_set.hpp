#pragma once
#include<cstdint>
#include<vector>
#include<tuple>
#include<algorithm>
#include <cassert>
#include<iostream>

/**
 * @brief FastSet(遅い)
 */

template<typename T>
struct fast_set{
	constexpr static int B=4;
    constexpr static int S=(1<<B);
	struct node{
		T val=0;
        bool b=0;
		node* ch[S]={};
        static int node_count;
        void* operator new(std::size_t){
            static node* pool=(node*)malloc(4096*sizeof(node));
            if(node_count==4096){
                node_count=0;
                pool=(node*)malloc(4096*sizeof(node));
            }
            return pool + node_count++;
        }
        node(){}
	};
	using np=node*;
	np root=new node(),root2=new node();
	inline T& operator[](int64_t k){
        return get(std::abs(k),k>0?root:root2);
    }
    inline bool count(int64_t k){
        return count(std::abs(k),k>0?root:root2);
    }
    inline std::vector<std::pair<int64_t,T>> out(){
        std::vector<std::pair<int64_t,T>>v;
        out(v,root2,0,-1,0);
        out(v,root,0,1,0);
        std::sort(v.begin(),v.end());
        return v;
    }
	T& get(int64_t k,np t){
        while(k){
            if(!t->ch[k&(S-1)])t->ch[k&(S-1)]=new node();
            t=t->ch[k&(S-1)];
            k>>=B;
        }
        t->b=1;
        return t->val;
	}
    bool count(int64_t k,np& t){
        if(!t)return 0;
        if(!k)return t->b;
        else return count(k>>B,t->ch[k&(S-1)]);
    }
    void out(std::vector<std::pair<int64_t,T>>&v,np& t,int64_t k,int f,int b){
        if(!t)return;
        if(t->b)v.emplace_back(k*f,t->val);
        for(int i=0;i<S;++i){
            out(v,t->ch[i],k+(i<<(B*b)),f,b+1);
        }
    }
};
template<typename T>int fast_set<T>::node::node_count = 0;