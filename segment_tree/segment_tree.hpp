#pragma once

/**
 * @brief セグメント木
 * @see https://en.wikipedia.org/wiki/Segment_tree
 */

namespace hotman{
    #include<bits/stdc++.h>
    using namespace std;

    template<typename T,typename F>
    class segment_tree{
        using i64=long long;
        using u8=unsigned char;
        struct node;
        using np=node*;
        struct node{
            optional<T>val;
            np ch[2]={nullptr,nullptr};
            node(optional<T> val=nullopt):val(val){}
        };
        np root=new node();
        i64 n=1;
        i64 sz;
        F op;
        public:
        segment_tree(){}
        segment_tree(i64 sz,F op=F()):sz(sz),op(op){
            while(n<=sz)n<<=1;
        }
        segment_tree(std::vector<T> v,F op=F()):sz(v.size()),op(op){
            while(n<=sz)n<<=1;
            for(int i=0;i<sz;++i)change(i,v[i]);
        }
        optional<T> get(i64 a,i64 b){
            return get(a,b,0,n,root);
        }
        void apply(i64 x,T val){
            apply(x,val,0,n,root);
        }
        void apply_left(i64 x,T val){
            apply_left(x,val,0,n,root);
        }
        void change(i64 x,T val){
            change(x,val,0,n,root);
        }
        optional<T> get(i64 a,i64 b,i64 l,i64 r,np t){
            if(!t)return nullopt;
            if(r<=a||b<=l)return nullopt;
            if(a<=l&&r<=b){
                return t->val;
            }
            const i64 m=(l+r)/2;
            return __op(get(a,b,l,m,t->ch[0]),get(a,b,m,r,t->ch[1]));
        }
        optional<T> apply(i64 x,T val,i64 l,i64 r,np t){
            const i64 m=(l+r)/2;
            if(r-l>1){
                if(l<=x&&x<m){
                    if(!t->ch[0])t->ch[0]=new node();
                    apply(x,val,l,m,t->ch[0]);
                }
                if(m<=x&&x<r){
                    if(!t->ch[1])t->ch[1]=new node();
                    apply(x,val,m,r,t->ch[1]);
                }
                return t->val=__op(t->ch[0]?t->ch[0]->val:nullopt,t->ch[1]?t->ch[1]->val:nullopt);
            }else{
                return t->val=__op(t->val,val);
            }
        }
        optional<T> apply_left(i64 x,T val,i64 l,i64 r,np t){
            const i64 m=(l+r)/2;
            if(r-l>1){
                if(l<=x&&x<m){
                    if(!t->ch[0])t->ch[0]=new node();
                    apply_left(x,val,l,m,t->ch[0]);
                }
                if(m<=x&&x<r){
                    if(!t->ch[1])t->ch[1]=new node();
                    apply_left(x,val,m,r,t->ch[1]);
                }
                return t->val=__op(t->ch[0]?t->ch[0]->val:nullopt,t->ch[1]?t->ch[1]->val:nullopt);
            }else{
                return t->val=__op(val,t->val);
            }
        }
        optional<T> change(i64 x,const T& val,i64 l,i64 r,np t){
            const i64 m=(l+r)/2;
            if(r-l>1){
                if(l<=x&&x<m){
                    if(!t->ch[0])t->ch[0]=new node();
                    change(x,val,l,m,t->ch[0]);
                }
                if(m<=x&&x<r){
                    if(!t->ch[1])t->ch[1]=new node();
                    change(x,val,m,r,t->ch[1]);
                }
                return t->val=__op(t->ch[0]?t->ch[0]->val:nullopt,t->ch[1]?t->ch[1]->val:nullopt);
            }else{
                return t->val=val;
            }
        }
        optional<T> __op(const optional<T>& s,const optional<T>& t){
            if(!s.has_value())return t;
            if(!t.has_value())return s;
            return op(s.value(),t.value());
        }
    };

    template<typename T>
    struct MAX_F{
        T operator()(const T& s,const T& t){
            return max(s,t);
        }
    };
    template<typename T>using max_seg=segment_tree<T,MAX_F<T>>;

    template<typename T>
    struct MIN_F{
        T operator()(const T& s,const T& t){
            return min(s,t);
        }
    };
    template<typename T>using min_seg=segment_tree<T,MIN_F<T>>;
    
    template<typename T>
    struct COMPOSITE_F{
        pair<T,T> operator()(const pair<T,T>& s,const pair<T,T>& t){
            return make_pair(s.first*t.first,s.second*t.first+t.second);
        }
    };
    template<typename T>using composite_seg=segment_tree<pair<T,T>,COMPOSITE_F<T>>;
}