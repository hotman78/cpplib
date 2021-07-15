// template<typename T>struct SEG{
//     public:
//         lint n=1;
//         vector<T> node;
//         T init;T(*_proc)(T,T)
//         T (*proc)(T,T);
//         SEG(vector<T>v,T _init,T(*_proc)(T,T)){
//             init=_init;
//             proc=_proc;
//             while(n<(lint)v.size())n*=2;
//             node.resize(n*2-1,init);
//             rep(i,v.size())node[i+n-1] = v[i];
//             rrep(i,n-1)node[i]=(*proc)(node[2*i+1],node[2*i+2]);
//         }
//         void update(lint x,T val){
//             x+=(n-1);
//             node[x]=val;
//             while(x>0){
//                 x=(x-1)/2;
//                 node[x]=(*proc)(node[x*2+1],node[x*2+2]);
//             }
//         }
//         T get(lint a,lint b){
//             return query(a,b,0,0,n);
//         }
//         T query(lint a,lint b,lint k,lint l,lint r){
//             if(r<=a||b<=l)return init;
//             if(a<=l&&r<=b)return node[k];
//             else{
//                 lint vl=query(a,b,k*2+1,l,(l+r)/2);
//                 lint vr=query(a,b,k*2+2,(l+r)/2,r);
//                 return (*proc)(vl,vr);
//             }
//         }
// };

// template<typename T>struct SEG{
//     lint n=1;
//     vector<T> node;
//     T init;
//     SEG(vector<T>v,T _init){
//         init=_init;
//         while(n<(lint)v.size())n*=2;
//         node.resize(n*2-1,init);
//         rep(i,v.size())node[i+n-1] = v[i];
//         rrep(i,n-1)node[i]=func(node[2*i+1],node[2*i+2]);
//     }
//     SEG(lint size,T _init){
//         init=_init;
//         while(n<size)n*=2;
//         node.resize(n*2-1,init);
//     }
//     void update(lint x,T val){
//         x+=(n-1);
//         node[x]=val;
//         while(x>0){
//             x=(x-1)/2;
//             node[x]=func(node[x*2+1],node[x*2+2]);
//         }
//     }
//     void add(lint x,T val){
//         x+=(n-1);
//         node[x]+=val;
//         while(x>0){
//             x=(x-1)/2;
//             node[x]=func(node[x*2+1],node[x*2+2]);
//         }
//     }
//     T get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
//         if(r<0)r=n;
//         if(r<=a||b<=l)return init;
//         if(a<=l&&r<=b)return node[k];
//         else{
//             T vl=get(a,b,k*2+1,l,(l+r)/2);
//             T vr=get(a,b,k*2+2,(l+r)/2,r);
//             return func(vl,vr);
//         }
//     }
//     T func(T s,T t){
//         return make_pair(s.first+t.first,s.second+t.second);
//     }
// };

template<typename T>struct SEG{
    lint n=1;
    vector<T> node;
    T init;
    SEG(lint size,T _init){
        init=_init;
        while(n<size)n*=2;
        node.resize(n*2-1,init);
    }
    void update(lint x,T val){
        x+=(n-1);
        node[x]=func(node[x],val);
        while(x>0){
            x=(x-1)/2;
            node[x]=func(node[x*2+1],node[x*2+2]);
        }
    }
    T get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
        if(r<0)r=n;
        if(r<=a||b<=l)return init;
        if(a<=l&&r<=b)return node[k];
        else{
            T vl=get(a,b,k*2+1,l,(l+r)/2);
            T vr=get(a,b,k*2+2,(l+r)/2,r);
            return func(vl,vr);
        }
    }
    T func(T s,T t){
        return s+t;
    }
};

template<typename T,typename E>class LSEG{
    lint n=1;
    vector<T> node;
    vector<E> lazy;
    T et;
    E ee;
    public:
    LSEG(int size,T et,E ee):et(et),ee(ee){
        while(n<size)n<<=1;
        node.resize(2*n-1,et);
        lazy.resize(2*n-1,ee);
    }
    inline void update(int a,int b,const E& x){
        update(a,b,x,0,0,n);
    }
    inline T get(int a,int& b){
        return get(a,b,0,0,n);
    }
    private:
    inline void eval(const int& k,const int& len){
        if(lazy[k]==ee) return;
        if(k*2+1<n*2-1){
            lazy[k*2+1]=g(lazy[k*2+1],lazy[k]);
            lazy[k*2+2]=g(lazy[k*2+2],lazy[k]);
        }
        node[k]=h(node[k],lazy[k],len);
        lazy[k]=ee;
    }
    //0-indexed [a,b)
    T update(const int& a,const int& b,const E& x,const int& k,const int& l,const int& r){
        eval(k,r-l);
        //区間外
        if(r<=a||b<=l)return node[k];
        //全部区間内
        if(a<=l&&r<=b){
            lazy[k]=g(lazy[k],x);
            return h(node[k],lazy[k],r-l);
        }
        //一部区間内
        return node[k]=f(update(a,b,x,2*k+1,l,(l+r)/2),update(a,b,x,2*k+2,(l+r)/2,r));
    }
    //0-indexed [a,b)
    T get(const int& a,const int& b,const int& k,const int& l,const int& r){
        eval(k,r-l);
        //区間外
        if(r<=a||b<=l)return et;
        //全部区間内
        if(a<=l&&r<=b)return node[k];
        //一部区間内
        return f(get(a,b,2*k+1,l,(l+r)/2),get(a,b,2*k+2,(l+r)/2,r));
    }
    inline T f(const T& a,const T& b){
        return make_pair(max(a.first,b.first),min(a.second,b.second));
    }
    inline T h(const T& a,const E& b,const int& len){
        return make_pair(a.first+b,a.second+b);
    }
    inline E g(const E& a,const E& b){
        return b+a;
    }
    auto update(auto a,auto b){return b==ee?a:b;}
};

// struct LSEG{
//     lint n=1;
//     vec node,lazy;
//     LSEG(lint size){
//         while(n<size)n<<=1;
//         node.resize(2*n-1,0);
//         lazy.resize(2*n-1,0);
//     }
//     //0-indexed [a,b)
//     void add(lint a,lint b,lint x,lint k=0,lint l=0,lint r=-1){
//         if(r<0)r=n;
//         if(a<=l&&r<=b){
//             node[k]+=(r-l)*x;
//             if(k<n-1){
//                 lazy[2*k+1]+=x;
//                 lazy[2*k+2]+=x;
//             }
//         }else if(min(b,r)>max(a,l)){
//             node[k]+=(min(b,r)-max(a,l))*x;
//             add(a,b,x,2*k+1,l,(l+r)/2);
//             add(a,b,x,2*k+2,(l+r)/2,r);
//         }
//     }
//     //0-indexed [a,b)
//     lint get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
//         if(r<0)r=n;
//         if (b<=l||r<=a)return 0LL;
//         if(a<=l&&r<=b)return lazy[k]*(r-l)+node[k];
//         node[k]+=(r-l)*lazy[k];
//         if(k<n-1){
//             lazy[2*k+1]+=lazy[k];
//             lazy[2*k+2]+=lazy[k];
//         }
//         lazy[k]=0;
//         return get(a,b,2*k+1,l,(l+r)/2)+get(a,b,2*k+2,(l+r)/2,r);
//     }
// };

// template<typename T,typename E>struct LSEG{
//     lint n=1;
//     vector<T> node;
//     vector<E> lazy;
//     T et;
//     E ee;
//     LSEG(lint size,T et,E ee):et(et),ee(ee){
//         while(n<size)n<<=1;
//         node.resize(2*n-1,et);
//         lazy.resize(2*n-1,ee);
//     }
//     inline void eval(lint k,lint len){
//         if(lazy[k]==ee) return;
//         if(k*2+1<n*2-1){
//             lazy[k*2+1]=g(lazy[k*2+1],lazy[k]);
//             lazy[k*2+2]=g(lazy[k*2+2],lazy[k]);
//         }
//         node[k]=h(node[k],lazy[k],len);
//         lazy[k]=ee;
//     }

//     //0-indexed [a,b)
//     T update(lint a,lint b,E x,lint k=0,lint l=0,lint r=-1){
//         if(r<0)r=n;
//         eval(k,r-l);
//         //区間外
//         if(r<=a||b<=l)return node[k];
//         //全部区間内
//         if(a<=l&&r<=b){
//             lazy[k]=g(lazy[k],x);
//             return h(node[k],lazy[k],r-l);
//         }
//         //一部区間内
//         return node[k]=f(update(a,b,x,2*k+1,l,(l+r)/2),update(a,b,x,2*k+2,(l+r)/2,r));
//     }
//     //0-indexed [a,b)
//     T get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
//         if(r<0)r=n;
//         eval(k,r-l);
//         //区間外
//         if(r<=a||b<=l)return et;
//         //全部区間内
//         if(a<=l&&r<=b)return node[k];
//         //一部区間内
//         return f(get(a,b,2*k+1,l,(l+r)/2),get(a,b,2*k+2,(l+r)/2,r));
//     }
//     T f(T a,T b){
//         return min(a,b);
//     }
//     T h(T a,E b,lint len){
//         if(b==-1)return a;
//         else return b;
//     }
//     E g(E a,E b){
//         return b;
//     }
// };