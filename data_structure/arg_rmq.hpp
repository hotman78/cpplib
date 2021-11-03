#pragma once
#include<assert.h>
#include<vector>
#include<stack>
#include<numeric>
#include<cmath>
#include<algorithm>
#include"small_rmq.hpp"
#include"sparse_table.hpp"
#include"../functional/argmin.hpp"

/**
 * @brief RangeArgminQuery &amp;lt;O(N),O(1)&amp;gt;
 * @see https://noshi91.hatenablog.com/entry/2018/08/16/125415
 */

template<typename T>
class arg_rmq{
    constexpr static int b=64;
    std::vector<T>v;
    std::vector<small_rmq<T>*>backet;
    sparse_table<std::pair<int,T>,argmin<int,T>>* st=0;
    public:
    arg_rmq(std::vector<T>v):v(v){
        std::vector<std::pair<int,T>>tmp2;
        for(int i=0;i<(int)v.size();i+=b){
            std::vector<T>tmp;
            T mn=std::numeric_limits<T>::max();
            int idx=-1;
            for(int j=0;i+j<(int)v.size()&&j<b;j++){
                tmp.push_back(v[i+j]);
                if(mn>v[i+j]){
                    mn=v[i+j];
                    idx=i+j;
                }
            }
            tmp2.emplace_back(idx,mn);
            backet.push_back(new small_rmq<T>(tmp));
        }
        st=new sparse_table<std::pair<int,T>,argmin<int,T>>(tmp2);
    }
    maybe<std::pair<int,T>> query(int s,int t){
        if(s==t)return maybe<std::pair<int,T>>();
        if(s/b==t/b){
            int idx=s/b*b+backet[s/b]->query(s%b,t%b);
            return maybe<std::pair<int,T>>(std::make_pair(idx,v[idx]));
        }
        std::pair<int,T> res=std::make_pair(-1,std::numeric_limits<T>::max());

        {
            int idx=s/b*b+backet[s/b]->query(s%b,b);
            res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));
        }

        if(s/b+1!=t/b)res=argmin<int,T>()(res,st->get(s/b+1,t/b).unwrap());

        if(t%b!=0){
            int idx=t/b*b+backet[t/b]->query(0,t%b);
            res=argmin<int,T>()(res,std::make_pair(idx,v[idx]));
        }

        return maybe<std::pair<int,T>>(res);
    }
};