#pragma once
#include<vector>
#include"FPS_base.hpp"
#include"../util/ACL.hpp"
#include"../math/ceil_pow2.hpp"
#include"../math/garner.hpp"

/**
 * @brief 形式的冪級数(Integer)
 */

struct _FPS{
    template<typename T>
    T operator()(const T& _s,const T& _t){
        std::vector<long long>v=atcoder::convolution_ll(static_cast<std::vector<long long>>(_s),static_cast<std::vector<long long>>(_t));
        return *static_cast<T*>(&v);
    }
    template<typename T>
    T fact(const T& s){
        T t=1;
        for(int i=1;i<=s;++i){
            t*=i;
        }
        return t;
    }
    template<typename T>
    T pow(T s,int i){
        T t=1;
        while(i){
            if(i%2)t*=s;
            s*=s;
            i/=2;
        }
        return t;
    }
};
using fps=FPS_BASE<long long,_FPS>;