#pragma once
#include"../../alga/maybe.hpp"
/**
 * @brief Segment Tree
 * @docs docs/segment_tree.md
 * @see https://en.wikipedia.org/wiki/Segment_tree
 */
template<typename T,typename F>
class segment_tree{
	maybe<T>* node;
    F op;
	int n=1;
	public:
    segment_tree(){}
	segment_tree(int sz,F op):op(op){
		while(n<=sz)n<<=1;
		node=new maybe<T>[n*2];
		for(int i=0;i<n*2;i++)node[i]=maybe<T>();
	}
    segment_tree(const vector<T>&v,F op):op(op){
        auto f=expand<T,F>(op);
        const int sz=v.size();
		while(n<=sz)n<<=1;
		node=new maybe<T>[n*2]();
        for(int i=0;i<sz;i++)node[i+n]=maybe<T>(v[i]);
        for(int i=n-1;i>=1;i--)node[i]=f(node[i*2],node[i*2+1]);
	}
    maybe<T> get(int l,int r){
        auto f=expand<T,F>(op);
        l+=n;r+=n;
        maybe<T> s,t;
        while(l<r){
            if(l&1)s=f(s,node[l++]);
            if(r&1)t=f(node[--r],t);
            l>>=1;r>>=1;
        }
        return f(s,t);
    }
    void apply(int t,T _val){
        auto f=expand<T,F>(op);
        t+=n;
        maybe<T> val=maybe<T>(_val);
        while(t){
            node[t]=f(node[t],val);
            t=t>>1;
        }
    }
    void apply_left(int t,T _val){
        auto f=expand<T,F>(op);
        t+=n;
        maybe<T> val=maybe<T>(_val);
        while(t){
            node[t]=f(val,node[t]);
            t=t>>1;
        }
    }
    void change(int t,T val){
        auto f=expand<T,F>(op);
        t+=n;
        node[t]=maybe<T>(val);
        while(t>1){
            t=t>>1;
            node[t]=f(node[t*2],node[t*2+1]);
        }
    }
};

template<typename T,typename F>
segment_tree<T,F> make_segment_tree(vector<T> v,F op){
    return segment_tree<T,F>(v,op);
}
template<typename T,typename F>
segment_tree<T,F> make_segment_tree(int size,T goast,F op){
    return segment_tree<T,F>(size,op);
}