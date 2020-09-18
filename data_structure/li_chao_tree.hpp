#pragma once

/**
 * @brief LiChaoTree
 */

template<typename T>
class LHT{
    using lint = long long;
    struct node;
    using np = node*;
    struct node{
        T a,b;
        np ch[2]={nullptr,nullptr};
        node(T a,T b):a(a),b(b){}
    };
    np root=nullptr;
    T sign(T x){return (x>0)-(x<0);}
    np update(T a,T b,lint p,lint q,lint l,lint r,np t){
        if(!t)t=new node(0,numeric_limits<T>::max());
        //区間外
        if(r<=p||q<=l)return t;
        //全て区間内
        if(p<=l&&r<=q){
            lint m=(l+r)/2;
            if(a*m+b<=(t->a)*m+(t->b)){
                swap(a,t->a);
                swap(b,t->b);
            }
            if(r-l==1||a==t->a)return t;
            if(sign((a-t->a)*l+(b-t->b))*sign((a-t->a)*m+(b-t->b))<=0)t->ch[0]=update(a,b,p,q,l,m,t->ch[0]);
            if(sign((a-t->a)*m+(b-t->b))*sign((a-t->a)*r+(b-t->b))<=0)t->ch[1]=update(a,b,p,q,m,r,t->ch[1]);
            return t;
        }
        //一部区間内
        t->ch[0]=update(a,b,p,q,l,(l+r)/2,t->ch[0]);
        t->ch[1]=update(a,b,p,q,(l+r)/2,r,t->ch[1]);
        return t;
    }
    T get(lint x,lint l,lint r,np t){
        if(!t)return numeric_limits<T>::max();
        if(r-l==1)return t->a*x+t->b;
        lint m=(l+r)/2;
        if(l<=x&&x<m)return min(t->a*x+t->b,get(x,l,m,t->ch[0]));
        else return min(t->a*x+t->b,get(x,m,r,t->ch[1]));
    }
    lint mn=-1LL<<32;
    lint mx=1LL<<32;
    public:
    T get(lint x){
        return get(x,mn,mx,root);
    }
    void add_line(T a,T b){
        root=update(a,b,mn,mx,mn,mx,root);
    }
    void add_segment(lint l,lint r,T a,T b){
        root=update(a,b,l,r,mn,mx,root);
    }
};