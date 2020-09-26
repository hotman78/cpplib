#pragma once
#include<tuple>
/**
 * @brief HashMap(WIP)
 */

template<typename T,typename E,typename F=std::hash<T>>
struct hash_map{
    struct node{
        T key;E val;
        unsigned long b;
        node():key(T()),val(E()),b(0){}
        node(T key,E val):key(key),val(val),b(0){}
        static node* alc;
        static size_t cnt;
        static size_t alc_sz;
        void* operator new(size_t){
            if(alc_sz==cnt){
                alc_sz*=2;
                alc=(node*)malloc(alc_sz*sizeof(node));
                cnt=0;
            }
            return alc+cnt++;
        }
    };
    size_t sz;
    node* point;
    constexpr static size_t mod_list[24]={37,67,131,257,521,1031,2053,4099,8209,16411,32771,65537,131101,262147,524309,1048583,2097169,4194319,8388617,16777259,33554467,67108879,134217757,268435459};
    node** table;
    F op;
    hash_map(F op=F()):sz(15),op(op){
        table=new node*[mod_list[sz]]();
    }
    node** _realloc(){
        const size_t old_sz=sz;
        while(1){
            sz++;
            bool fail=0;
            node** tmp=new node*[mod_list[sz]]();
            for(node** itr=table;itr<table+mod_list[old_sz];++itr){
                if(*itr==0)continue;
                const size_t ha=op((*itr)->key)%mod_list[sz];
                (*itr)->b=0;
                if(insert(tmp,*itr,ha).first==0){fail=1;break;}
            }
            if(fail){
                delete[] tmp;
            }
            else {
                delete[] table;
                table=tmp;
                break;
            }
        }
        return table;
    }
    std::pair<bool,node*> insert(node** table,node* t,size_t tmp){
        if(!table[tmp])return {true,table[tmp]=t};
        size_t k=0;
        unsigned long tt=~table[tmp]->b;
        const size_t pre=tmp;
        unsigned long x=1;
        while(tt){
            tmp+=(k=__builtin_ctzl(tt)+1);
            x<<=k;
            tt>>=k;
            tmp%=mod_list[sz];
            if(!table[tmp]){
                table[tmp]=t;
                table[pre]->b|=x>>1;
                return {true,table[tmp]};
            }
        }
        return {false,nullptr};
    }
    std::pair<bool,node*> search(T key,size_t tmp){
        int k=0;
        if(!table[tmp])return {false,nullptr};
        if(table[tmp]->key==key)return {true,table[tmp]};

        unsigned long t=table[tmp]->b;
        while(t){
            tmp+=(k=__builtin_ctzl(t)+1);
            tmp%=mod_list[sz];
            t>>=k;
            if(table[tmp]->key==key)return {true,table[tmp]};
        }
        return {false,nullptr};
    }
    E& operator[](T key){
        size_t ha=op(key)%mod_list[sz];
        auto res=search(key,ha);
        if(res.first)return res.second->val;
        else {
            while(1){
                auto res=insert(table,new node(key,E()),ha);
                if(res.first)return res.second->val;
                _realloc();
                ha=op(key)%mod_list[sz];
            }
        }
    }
};
template<typename T,typename E,typename F=std::hash<T>>typename hash_map<T,E,F>::node* hash_map<T,E,F>::node::alc=(node*)malloc(sizeof(node));
template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::cnt=0;
template<typename T,typename E,typename F=std::hash<T>>size_t hash_map<T,E,F>::node::alc_sz=1;
