#pragma once
#include<assert.h>
#include<vector>
#include<stack>
#include<numeric>
#include<cmath>
#include<algorithm>
#include"small_rmq.hpp"
#include"sparse_table.hpp"
#include"../functional/MIN.hpp"
#include"../alga/maybe.hpp"
/**
 * @brief RMQ&amp;lt;O(N),O(1)&amp;gt;
 * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415
 */

template<typename T>
class RMQ{
    constexpr static int b=64;
    std::vector<T>v;
    std::vector<small_rmq<T>*>backet;
    sparse_table<T,MIN<T>>* st=0;
    public:
    RMQ(std::vector<T>v):v(v){
        std::vector<T>tmp2;
        for(int i=0;i<(int)v.size();i+=b){
            std::vector<T>tmp;
            T mn=std::numeric_limits<T>::max();
            for(int j=0;i+j<(int)v.size()&&j<b;j++){
                tmp.push_back(v[i+j]);
                if(mn>v[i+j])mn=v[i+j];
            }
            tmp2.push_back(mn);
            backet.push_back(new small_rmq<T>(tmp));
        }
        st=new sparse_table<T,MIN<T>>(tmp2);
    }
    T query(int s,int t){
        if(s/b==t/b)return v[s/b*b+backet[s/b]->query(s%b,t%b)];
        T res=std::numeric_limits<T>::max();

        res=std::min(res,v[s/b*b+backet[s/b]->query(s%b,b)]);
        res=std::min(res,st->get(s/b+1,t/b).unwrap_or(std::numeric_limits<T>::max()));
        if(t%b!=0)res=std::min(res,v[t/b*b+backet[t/b]->query(0,t%b)]);

        return res;
    }
};