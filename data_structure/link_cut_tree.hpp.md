---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/link_cut_tree.hpp\"\ntemplate<typename T,typename\
    \ E>\nclass link_cut{\n    class myset{\n        struct node{\n            T val,l,r,sum;\n\
    \            int cnt=1,dep=0;\n            static const node* nil;\n         \
    \   node* ch[2]={nullptr,nullptr};\n            node(T val):val(val),l(val),r(val),sum(val){}\n\
    \        };\n        using np=node*;\n        np root=nullptr;\n        inline\
    \ int count(np t){return t?t->cnt:0;}\n        inline int depth(np t){return t?t->dep:0;}\n\
    \        np update(np t,bool flag=1){\n            if(!t)return t;\n         \
    \   t->cnt=count(t->ch[0])+1+count(t->ch[1]);\n            t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;\n\
    \            if(t->ch[0])t->l=t->ch[0]->l;\n            if(t->ch[1])t->r=t->ch[1]->r;\n\
    \n            t->sum=et;\n            if(t->ch[0])t->sum=f(t->sum,t->ch[0]->sum);\n\
    \            t->sum=f(t->sum,t->val);\n            if(t->ch[1])t->sum=f(t->sum,t->ch[1]->sum);\n\
    \n            if(flag&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){\n           \
    \     bool b=depth(t->ch[0])<depth(t->ch[1]);\n                if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){\n\
    \                    t->ch[b]=rot(t->ch[b]);\n                }\n            \
    \    t=rot(update(t,0));\n            }\n            return t;\n        }\n  \
    \      np rot(np t){\n            T b=depth(t->ch[0])<depth(t->ch[1]);\n     \
    \       np s=t->ch[b];\n            t->ch[b]=s->ch[1-b];\n            s->ch[1-b]=t;\n\
    \            update(t,0);\n            return update(s,0);\n        }\n      \
    \  np insert(T val,np t){\n            if(!t)return new node(val);\n         \
    \   bool b=t->val<val;\n            t->ch[b]=insert(val,t->ch[b]);\n         \
    \   return update(t);\n        }\n        np erase(T val,np t){\n            if(!t)return\
    \ t;\n            if(t->val==val){\n                return move_down(t->ch[0],t->ch[1]);\n\
    \            }else{\n                bool b=t->val<val;\n                t->ch[b]=erase(val,t->ch[b]);\n\
    \            }\n            return update(t);\n        }\n        np move_down(np\
    \ t,np rhs) {\n            if(!t)return rhs;\n            t->ch[1]=move_down(t->ch[1],rhs);\n\
    \            return update(t);\n        }\n        E sum(T l,T r,np t){\n    \
    \        if(!t)return et;\n            if(t->r<l||r<=t->l)return et;\n       \
    \     if(l<=t->l&&t->r<r)return t->sum;\n            bool b=l<=t->val&&t->val<r;\n\
    \            return f(sum(l,r,t->ch[0]),f(b?t->val:et,sum(l,r,t->ch[1])));\n \
    \       }\n        int lower_bound(T val,np t){\n            if(!t)return 0;\n\
    \            bool b=val>t->val;\n            return(b?count(t->ch[0])+1:0)+lower_bound(val,t->ch[b]);\n\
    \        }\n        int upper_bound(T val,np t){\n            if(!t)return 0;\n\
    \            bool b=val>=t->val;\n            return(b?count(t->ch[0])+1:0)+upper_bound(val,t->ch[b]);\n\
    \        }\n        T find_by_order(T idx,np t){\n            if(idx==count(t->ch[0]))return\
    \ t->val;\n            bool b=idx>count(t->ch[0]);\n            return find_by_order(idx-(b?count(t->ch[0])+1:0),t->ch[b]);\n\
    \        }\n        public:\n        void insert(T val){root=insert(val,root);}\n\
    \        void erase(T val){root=erase(val,root);}\n        inline int size(){return\
    \ count(root);}\n        inline int count(T val){return upper_bound(val,root)-lower_bound(val,root);}\n\
    \        inline int count(T l,T r){return lower_bound(r,root)-lower_bound(l,root);}\n\
    \        inline E sum(T l,T r){return sum(l,r,root);}\n        inline E all_sum(){return\
    \ root?root->sum:et;}\n        //0-index\u3067idx\u756A\u76EE\n        inline\
    \ T operator[](T idx){return find_by_order(idx,root);}\n        //x\u672A\u6E80\
    \u306E\u500B\u6570/s[lower_bound(x)]\u306Fx\u4EE5\u4E0A\u6700\u5C0F\u306E\u5024\
    \n        inline int lower_bound(T x){return lower_bound(x,root);}\n        //x\u4EE5\
    \u4E0B\u306E\u500B\u6570/s[upper_bound(x)]\u306Fx\u3088\u308A\u5927\u304D\u3044\
    \u6700\u5C0F\u306E\u5024\n        inline int upper_bound(T x){return upper_bound(x,root);}\n\
    \    };\n    public:\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        np ch[2]={nullptr,nullptr};\n        np p=nullptr;\n        int idx;\n\
    \        T key,sum,sum2,csum;\n        myset light;\n        bool rev=0;\n   \
    \     E lazy=ee;\n        int sz;\n        node(){}\n        node(int idx,T key):idx(idx),key(key),sum(key),sum2(et),csum(et),sz(1){}\n\
    \        bool is_root() {\n            return !p||(p->ch[0]!=this&&p->ch[1]!=this);\n\
    \        }\n    };\n    int size(np t){return t?t->sz:0;}\n    void update(np\
    \ t){\n        t->sz=size(t->ch[0])+1+size(t->ch[1]);\n        t->sum=et;\n  \
    \      if(t->ch[0])t->sum=f(t->sum,t->ch[0]->sum);\n        t->sum=f(t->sum,t->key);\n\
    \        if(t->ch[1])t->sum=f(t->sum,t->ch[1]->sum);\n        t->csum=f(f(t->key,t->light.all_sum()),t->ch[1]?t->ch[1]->sum2:et);\n\
    \        t->sum2=f(f(f(t->ch[0]?t->ch[0]->sum2:et,t->key),t->ch[1]?t->ch[1]->sum2:et),t->light.all_sum());\n\
    \    }\n    void rot(np t,bool b){\n        np x=t->p,y=x->p;\n        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;\n\
    \        t->ch[b]=x,x->p=t;\n        update(x);update(t);\n        if((t->p=y)){\n\
    \            if(y->ch[0]==x)y->ch[0]=t;\n            if(y->ch[1]==x)y->ch[1]=t;\n\
    \            update(y);\n        }\n    }\n    void splay(np t){\n        push(t);\n\
    \        while(!t->is_root()){\n            np q=t->p;\n            if(q->is_root()){\n\
    \                push(q), push(t);\n                rot(t,q->ch[0]==t);\n    \
    \        }else{\n                np r=q->p;\n                push(r), push(q),\
    \ push(t);\n                bool b=r->ch[0]==q;\n                if(q->ch[1-b]==t)rot(q,b),rot(t,b);\n\
    \                else rot(t,1-b),rot(t,b);\n            }\n        }\n    }\n\
    \    void propagate(np t,E x){\n        t->lazy=h(t->lazy,x);\n        t->key=g(t->key,x,1);\n\
    \        t->sum=g(t->sum,x,t->sz);\n    }\n    void set_propagate(np t,E x){\n\
    \        expose(t);\n        propagate(t,x);\n        push(t);\n    }\n    void\
    \ push(np t){\n        if(t->lazy!=ee){\n            if(t->ch[0])propagate(t->ch[0],t->lazy);\n\
    \            if(t->ch[1])propagate(t->ch[1],t->lazy);\n            t->lazy=ee;\n\
    \        }\n        if(t->rev){\n            if(t->ch[0])toggle(t->ch[0]);\n \
    \           if(t->ch[1])toggle(t->ch[1]);\n            t->rev=0;\n        }\n\
    \    }\n    np expose(np t){\n        np rp=nullptr;\n        for(np cur=t;cur;cur=cur->p){\n\
    \            splay(cur);\n            if(cur->ch[1]){\n                cur->light.insert(cur->ch[1]->sum2);\n\
    \            }\n            cur->ch[1]=rp;\n            if(cur->ch[1]){\n    \
    \            cur->light.erase(cur->ch[1]->sum2);\n            }\n            update(cur);\n\
    \            rp=cur;\n        }\n        splay(t);\n        return rp;\n    }\n\
    \    vector<int>get_path(np x){\n        vector<int>vs;\n        function<void(np)>dfs=[&](np\
    \ cur){\n            if(!cur)return;\n            push(cur);\n            dfs(cur->ch[1]);\n\
    \            vs.push_back(cur->idx);\n            dfs(cur->ch[0]);\n        };\n\
    \        expose(x);\n        dfs(x);\n        return vs;\n    }\n    void link(np\
    \ ch,np par){\n        expose(ch);\n        expose(par);\n        ch->p=par;\n\
    \        par->ch[1]=ch;\n        update(par);\n    }\n    void cut(np ch){\n \
    \       expose(ch);\n        np par=ch->ch[0];\n        ch->ch[0]=nullptr;\n \
    \       par->p=nullptr;\n        update(ch);\n    }\n    void toggle(np t){\n\
    \        assert(t);\n        swap(t->ch[0],t->ch[1]);\n        t->sum=s(t->sum);\n\
    \        t->rev^=1;\n    }\n    void evert(np t){\n        expose(t);\n      \
    \  toggle(t);\n        push(t);\n    }\n    np get_root(np x){\n        expose(x);\n\
    \        while(x->ch[0]){\n            push(x);\n            x=x->ch[0];\n   \
    \     }\n        return x;\n    }\n    vector<np>p;\n    static T et;\n    static\
    \ E ee;\n    constexpr static\n    T s(T s){\n        return s;\n    }\n    constexpr\
    \ static\n    T f(T s,T t){\n        return s+t;\n    }\n    constexpr static\n\
    \    T g(T s,E t,int len){\n        return s+t*len;\n    }\n    constexpr static\n\
    \    E h(E s,E t){\n        return s+t;\n    }\n    public:\n    link_cut(int\
    \ sz){\n        p.resize(sz,nullptr);\n        for(int i=0;i<sz;i++)p[i]=new node(i,et);\n\
    \    }\n    link_cut(){}\n    void set_key(int t,T key) {\n        expose(p[t]);\n\
    \        p[t]->key=key;\n        update(p[t]);\n    }\n    T get_key(int t) {\n\
    \        return p[t]->key;\n    }\n    vector<int> get_path(int s,int t){\n  \
    \      evert(p[s]);\n        return get_path(p[t]);\n    }\n    void path_add(int\
    \ s,int t,E x){\n        evert(p[s]);\n        set_propagate(p[t],x);\n    }\n\
    \    T get_path_sum(int s,int t){\n        evert(p[s]);\n        expose(p[t]);\n\
    \        return p[t]->sum;\n    }\n    //t\u3092\u6839\u3068\u3057\u305Fs\u306E\
    \u90E8\u5206\u6728\u306E\u548C\u3092\u5F97\u308B\n    T get_subtree_sum(int s,int\
    \ t){\n        evert(p[t]);\n        expose(p[s]);\n        return p[s]->csum;\n\
    \    }\n    void make_node(T x){\n        p.emplace_back(new node(p.size(),x));\n\
    \    }\n    void evert(int t){\n        evert(p[t]);\n    }\n    void link(int\
    \ s,int t){\n        evert(p[s]);\n        link(p[s],p[t]);\n    }\n    void cut(int\
    \ s,int t){\n        evert(p[s]);\n        cut(p[t]);\n    }\n    bool same(int\
    \ s,int t){\n        return get_root(p[s])==get_root(p[t]);\n    }\n    np lca(int\
    \ s,int t){\n        if(get_root(p[s])!=get_root(p[t]))return nullptr;\n     \
    \   expose(p[s]);\n        return expose(p[t]);\n    }\n};\ntemplate<typename\
    \ T,typename E>T link_cut<T,E>::et=0;\ntemplate<typename T,typename E>E link_cut<T,E>::ee=0;\n"
  code: "template<typename T,typename E>\nclass link_cut{\n    class myset{\n    \
    \    struct node{\n            T val,l,r,sum;\n            int cnt=1,dep=0;\n\
    \            static const node* nil;\n            node* ch[2]={nullptr,nullptr};\n\
    \            node(T val):val(val),l(val),r(val),sum(val){}\n        };\n     \
    \   using np=node*;\n        np root=nullptr;\n        inline int count(np t){return\
    \ t?t->cnt:0;}\n        inline int depth(np t){return t?t->dep:0;}\n        np\
    \ update(np t,bool flag=1){\n            if(!t)return t;\n            t->cnt=count(t->ch[0])+1+count(t->ch[1]);\n\
    \            t->dep=max(depth(t->ch[0]),depth(t->ch[1]))+1;\n            if(t->ch[0])t->l=t->ch[0]->l;\n\
    \            if(t->ch[1])t->r=t->ch[1]->r;\n\n            t->sum=et;\n       \
    \     if(t->ch[0])t->sum=f(t->sum,t->ch[0]->sum);\n            t->sum=f(t->sum,t->val);\n\
    \            if(t->ch[1])t->sum=f(t->sum,t->ch[1]->sum);\n\n            if(flag&&abs(depth(t->ch[0])-depth(t->ch[1]))==2){\n\
    \                bool b=depth(t->ch[0])<depth(t->ch[1]);\n                if(t->ch[b]&&depth(t->ch[b]->ch[b])<depth(t->ch[b]->ch[1-b])){\n\
    \                    t->ch[b]=rot(t->ch[b]);\n                }\n            \
    \    t=rot(update(t,0));\n            }\n            return t;\n        }\n  \
    \      np rot(np t){\n            T b=depth(t->ch[0])<depth(t->ch[1]);\n     \
    \       np s=t->ch[b];\n            t->ch[b]=s->ch[1-b];\n            s->ch[1-b]=t;\n\
    \            update(t,0);\n            return update(s,0);\n        }\n      \
    \  np insert(T val,np t){\n            if(!t)return new node(val);\n         \
    \   bool b=t->val<val;\n            t->ch[b]=insert(val,t->ch[b]);\n         \
    \   return update(t);\n        }\n        np erase(T val,np t){\n            if(!t)return\
    \ t;\n            if(t->val==val){\n                return move_down(t->ch[0],t->ch[1]);\n\
    \            }else{\n                bool b=t->val<val;\n                t->ch[b]=erase(val,t->ch[b]);\n\
    \            }\n            return update(t);\n        }\n        np move_down(np\
    \ t,np rhs) {\n            if(!t)return rhs;\n            t->ch[1]=move_down(t->ch[1],rhs);\n\
    \            return update(t);\n        }\n        E sum(T l,T r,np t){\n    \
    \        if(!t)return et;\n            if(t->r<l||r<=t->l)return et;\n       \
    \     if(l<=t->l&&t->r<r)return t->sum;\n            bool b=l<=t->val&&t->val<r;\n\
    \            return f(sum(l,r,t->ch[0]),f(b?t->val:et,sum(l,r,t->ch[1])));\n \
    \       }\n        int lower_bound(T val,np t){\n            if(!t)return 0;\n\
    \            bool b=val>t->val;\n            return(b?count(t->ch[0])+1:0)+lower_bound(val,t->ch[b]);\n\
    \        }\n        int upper_bound(T val,np t){\n            if(!t)return 0;\n\
    \            bool b=val>=t->val;\n            return(b?count(t->ch[0])+1:0)+upper_bound(val,t->ch[b]);\n\
    \        }\n        T find_by_order(T idx,np t){\n            if(idx==count(t->ch[0]))return\
    \ t->val;\n            bool b=idx>count(t->ch[0]);\n            return find_by_order(idx-(b?count(t->ch[0])+1:0),t->ch[b]);\n\
    \        }\n        public:\n        void insert(T val){root=insert(val,root);}\n\
    \        void erase(T val){root=erase(val,root);}\n        inline int size(){return\
    \ count(root);}\n        inline int count(T val){return upper_bound(val,root)-lower_bound(val,root);}\n\
    \        inline int count(T l,T r){return lower_bound(r,root)-lower_bound(l,root);}\n\
    \        inline E sum(T l,T r){return sum(l,r,root);}\n        inline E all_sum(){return\
    \ root?root->sum:et;}\n        //0-index\u3067idx\u756A\u76EE\n        inline\
    \ T operator[](T idx){return find_by_order(idx,root);}\n        //x\u672A\u6E80\
    \u306E\u500B\u6570/s[lower_bound(x)]\u306Fx\u4EE5\u4E0A\u6700\u5C0F\u306E\u5024\
    \n        inline int lower_bound(T x){return lower_bound(x,root);}\n        //x\u4EE5\
    \u4E0B\u306E\u500B\u6570/s[upper_bound(x)]\u306Fx\u3088\u308A\u5927\u304D\u3044\
    \u6700\u5C0F\u306E\u5024\n        inline int upper_bound(T x){return upper_bound(x,root);}\n\
    \    };\n    public:\n    struct node;\n    using np=node*;\n    struct node{\n\
    \        np ch[2]={nullptr,nullptr};\n        np p=nullptr;\n        int idx;\n\
    \        T key,sum,sum2,csum;\n        myset light;\n        bool rev=0;\n   \
    \     E lazy=ee;\n        int sz;\n        node(){}\n        node(int idx,T key):idx(idx),key(key),sum(key),sum2(et),csum(et),sz(1){}\n\
    \        bool is_root() {\n            return !p||(p->ch[0]!=this&&p->ch[1]!=this);\n\
    \        }\n    };\n    int size(np t){return t?t->sz:0;}\n    void update(np\
    \ t){\n        t->sz=size(t->ch[0])+1+size(t->ch[1]);\n        t->sum=et;\n  \
    \      if(t->ch[0])t->sum=f(t->sum,t->ch[0]->sum);\n        t->sum=f(t->sum,t->key);\n\
    \        if(t->ch[1])t->sum=f(t->sum,t->ch[1]->sum);\n        t->csum=f(f(t->key,t->light.all_sum()),t->ch[1]?t->ch[1]->sum2:et);\n\
    \        t->sum2=f(f(f(t->ch[0]?t->ch[0]->sum2:et,t->key),t->ch[1]?t->ch[1]->sum2:et),t->light.all_sum());\n\
    \    }\n    void rot(np t,bool b){\n        np x=t->p,y=x->p;\n        if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;\n\
    \        t->ch[b]=x,x->p=t;\n        update(x);update(t);\n        if((t->p=y)){\n\
    \            if(y->ch[0]==x)y->ch[0]=t;\n            if(y->ch[1]==x)y->ch[1]=t;\n\
    \            update(y);\n        }\n    }\n    void splay(np t){\n        push(t);\n\
    \        while(!t->is_root()){\n            np q=t->p;\n            if(q->is_root()){\n\
    \                push(q), push(t);\n                rot(t,q->ch[0]==t);\n    \
    \        }else{\n                np r=q->p;\n                push(r), push(q),\
    \ push(t);\n                bool b=r->ch[0]==q;\n                if(q->ch[1-b]==t)rot(q,b),rot(t,b);\n\
    \                else rot(t,1-b),rot(t,b);\n            }\n        }\n    }\n\
    \    void propagate(np t,E x){\n        t->lazy=h(t->lazy,x);\n        t->key=g(t->key,x,1);\n\
    \        t->sum=g(t->sum,x,t->sz);\n    }\n    void set_propagate(np t,E x){\n\
    \        expose(t);\n        propagate(t,x);\n        push(t);\n    }\n    void\
    \ push(np t){\n        if(t->lazy!=ee){\n            if(t->ch[0])propagate(t->ch[0],t->lazy);\n\
    \            if(t->ch[1])propagate(t->ch[1],t->lazy);\n            t->lazy=ee;\n\
    \        }\n        if(t->rev){\n            if(t->ch[0])toggle(t->ch[0]);\n \
    \           if(t->ch[1])toggle(t->ch[1]);\n            t->rev=0;\n        }\n\
    \    }\n    np expose(np t){\n        np rp=nullptr;\n        for(np cur=t;cur;cur=cur->p){\n\
    \            splay(cur);\n            if(cur->ch[1]){\n                cur->light.insert(cur->ch[1]->sum2);\n\
    \            }\n            cur->ch[1]=rp;\n            if(cur->ch[1]){\n    \
    \            cur->light.erase(cur->ch[1]->sum2);\n            }\n            update(cur);\n\
    \            rp=cur;\n        }\n        splay(t);\n        return rp;\n    }\n\
    \    vector<int>get_path(np x){\n        vector<int>vs;\n        function<void(np)>dfs=[&](np\
    \ cur){\n            if(!cur)return;\n            push(cur);\n            dfs(cur->ch[1]);\n\
    \            vs.push_back(cur->idx);\n            dfs(cur->ch[0]);\n        };\n\
    \        expose(x);\n        dfs(x);\n        return vs;\n    }\n    void link(np\
    \ ch,np par){\n        expose(ch);\n        expose(par);\n        ch->p=par;\n\
    \        par->ch[1]=ch;\n        update(par);\n    }\n    void cut(np ch){\n \
    \       expose(ch);\n        np par=ch->ch[0];\n        ch->ch[0]=nullptr;\n \
    \       par->p=nullptr;\n        update(ch);\n    }\n    void toggle(np t){\n\
    \        assert(t);\n        swap(t->ch[0],t->ch[1]);\n        t->sum=s(t->sum);\n\
    \        t->rev^=1;\n    }\n    void evert(np t){\n        expose(t);\n      \
    \  toggle(t);\n        push(t);\n    }\n    np get_root(np x){\n        expose(x);\n\
    \        while(x->ch[0]){\n            push(x);\n            x=x->ch[0];\n   \
    \     }\n        return x;\n    }\n    vector<np>p;\n    static T et;\n    static\
    \ E ee;\n    constexpr static\n    T s(T s){\n        return s;\n    }\n    constexpr\
    \ static\n    T f(T s,T t){\n        return s+t;\n    }\n    constexpr static\n\
    \    T g(T s,E t,int len){\n        return s+t*len;\n    }\n    constexpr static\n\
    \    E h(E s,E t){\n        return s+t;\n    }\n    public:\n    link_cut(int\
    \ sz){\n        p.resize(sz,nullptr);\n        for(int i=0;i<sz;i++)p[i]=new node(i,et);\n\
    \    }\n    link_cut(){}\n    void set_key(int t,T key) {\n        expose(p[t]);\n\
    \        p[t]->key=key;\n        update(p[t]);\n    }\n    T get_key(int t) {\n\
    \        return p[t]->key;\n    }\n    vector<int> get_path(int s,int t){\n  \
    \      evert(p[s]);\n        return get_path(p[t]);\n    }\n    void path_add(int\
    \ s,int t,E x){\n        evert(p[s]);\n        set_propagate(p[t],x);\n    }\n\
    \    T get_path_sum(int s,int t){\n        evert(p[s]);\n        expose(p[t]);\n\
    \        return p[t]->sum;\n    }\n    //t\u3092\u6839\u3068\u3057\u305Fs\u306E\
    \u90E8\u5206\u6728\u306E\u548C\u3092\u5F97\u308B\n    T get_subtree_sum(int s,int\
    \ t){\n        evert(p[t]);\n        expose(p[s]);\n        return p[s]->csum;\n\
    \    }\n    void make_node(T x){\n        p.emplace_back(new node(p.size(),x));\n\
    \    }\n    void evert(int t){\n        evert(p[t]);\n    }\n    void link(int\
    \ s,int t){\n        evert(p[s]);\n        link(p[s],p[t]);\n    }\n    void cut(int\
    \ s,int t){\n        evert(p[s]);\n        cut(p[t]);\n    }\n    bool same(int\
    \ s,int t){\n        return get_root(p[s])==get_root(p[t]);\n    }\n    np lca(int\
    \ s,int t){\n        if(get_root(p[s])!=get_root(p[t]))return nullptr;\n     \
    \   expose(p[s]);\n        return expose(p[t]);\n    }\n};\ntemplate<typename\
    \ T,typename E>T link_cut<T,E>::et=0;\ntemplate<typename T,typename E>E link_cut<T,E>::ee=0;\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/link_cut_tree.hpp
  requiredBy: []
  timestamp: '2020-09-18 16:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/link_cut_tree.hpp
layout: document
redirect_from:
- /library/data_structure/link_cut_tree.hpp
- /library/data_structure/link_cut_tree.hpp.html
title: data_structure/link_cut_tree.hpp
---
