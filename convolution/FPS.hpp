#pragma once
#include"FPS_base.hpp"
#include"../util/ACL.hpp"
/**
 * @brief 形式的冪級数(ModInt)
 */

template<typename Mint>
struct _FPS{
    template<typename T>
    T operator()(const T& _s,const T& _t){
        vector<atcoder::static_modint<Mint::get_mod()>>s(_s.size()),t(_t.size());
        for(size_t i=0;i<_s.size();++i)s[i]=_s[i].value();
        for(size_t i=0;i<_t.size();++i)t[i]=_t[i].value();
        vector<atcoder::static_modint<Mint::get_mod()>> _v=atcoder::convolution(s,t);
        T v(_v.size());
        for (size_t i=0;i<_v.size();++i)v[i]=_v[i].val();
        return v;
    }
    template<typename T>
    T fact(const T& s){
        return s.fact();
    }
    template<typename T>
    T pow(const T& s,int i){
        return s.pow(i);
    }
};
template<typename Mint>using fps=FPS_BASE<Mint,_FPS<Mint>>;