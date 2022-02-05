#include<vector>
#include<tuple>
#include<assert.h>

template<typename Node>
struct splay_tree_base{
    using np=Node*;
    np root=0;
    inline int size(np t){return t?t->sz:0;}
    int size(){return size(root);}
    np rot(np t,bool b){
        np s=t->ch[1-b];
        assert(s);
        np u=s->ch[b];
        t->ch[1-b]=u;
        s->ch[b]=t;
        t->update();s->update();
        return s;
    }
    void erase(int idx){
        auto [p,q]=split(root,idx);
        auto [s,t]=split(q,1);
        delete s;
        root=merge(p,t);
    }
    void insert(int idx,np val){
        if(size(root)==idx){
            root=merge(root,val);
        }else{
            auto [p,q]=split(root,idx);
            root=merge(merge(p,val),q);
        }
    }
    np merge(np s,np t){
        if(!s||!t)return s?s:t;
        s=splay(s,size(s)-1);
        s->ch[1]=t;
        return s->update();
    }
    std::pair<np,np> split(np t,int idx){
        if(size(t)==idx)return std::make_pair(t,nullptr);
        t=splay(t,idx);
        np s=t->ch[0];
        t->ch[0]=nullptr;
        return std::make_pair(s,t->update());
    }
    np splay(np t,int idx){
        if(idx==size(t->ch[0]))return t;

        bool b1=size(t->ch[0])<idx;
        if(b1)idx-=size(t->ch[0])+1;

        if(idx==size(t->ch[b1]->ch[0]))return rot(t,1-b1);
        bool b2=size(t->ch[b1]->ch[0])<idx;
        if(b2)idx-=size(t->ch[b1]->ch[0])+1;

        t->ch[b1]->ch[b2]=splay(t->ch[b1]->ch[b2],idx);
        if(b1==b2)t=rot(t,1-b2);
        else t->ch[b1]=rot(t->ch[b1],1-b2);

        return rot(t,1-b1);
    }
    std::vector<np> output(){
        std::vector<np>res;
        auto dfs=[&](auto dfs,np t)->void{
            if(!t)return;
            dfs(dfs,t->ch[0]);
            res.push_back(t);
            dfs(dfs,t->ch[1]);
        };
        dfs(dfs,root);
        return res;
    }
    np get_root(){return root;}
    np get(int i){root=splay(root,i);return root;}
    
    template<typename C>
    int lower_bound(C less){
        int res=__lower_bound(root,less);
        if(res<size())root=splay(root,res);
        return res;
    }
    template<typename C>
    int __lower_bound(np t,C less){
        if(!t)return 0;
        bool b=less(t);
        if(b)return size(t->ch[0])+1+__lower_bound(t->ch[1],less);
        else return __lower_bound(t->ch[0],less);
    }
};