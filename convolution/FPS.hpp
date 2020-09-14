#pragma once
#include"FPS_base.hpp"
#include<atcoder/convolution>

/**
 * @brief 形式的冪級数(ModInt)
 */

template<typename Mint>
struct _FPS{
    template<typename T>
    T operator()(T s,T t){
        vector<Mint> v=atcoder::convolution(static_cast<vector<Mint>>(s),static_cast<vector<Mint>>(t));
        return *static_cast<T*>(&v);
    }
    template<typename T>
    T fact(T s){
        return s.fact();
    }
    template<typename T>
    T pow(T s,int i){
        return s.pow(i);
    }
};
template<typename Mint>using fps=FPS_BASE<Mint,_FPS<Mint>>;