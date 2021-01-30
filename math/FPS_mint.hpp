#pragma once
#include"FPS_base.hpp"
//#include"../util/ACL.hpp"
#include<atcoder/convolution.hpp>
#include"../math/ceil_pow2.hpp"
#include"../math/garner.hpp"
/**
 * @brief 形式的冪級数(ModInt)
 */

template<typename Mint>
struct _FPS{
    template<typename T>
    T operator()(const T& _s,const T& _t){
        if(_s.size()==0||_t.size()==0)return T();
        const size_t sz=_s.size()+_t.size()-1;
        if constexpr(Mint::is_static&&(Mint::get_mod()&((1<<ceil_pow2(sz))-1))==1){
            std::vector<atcoder::static_modint<Mint::get_mod()>>s(_s.size()),t(_t.size());
            for(size_t i=0;i<_s.size();++i)s[i]=_s[i].value();
            for(size_t i=0;i<_t.size();++i)t[i]=_t[i].value();
            std::vector<atcoder::static_modint<Mint::get_mod()>> _v=atcoder::convolution(s,t);
            T v(_v.size());
            for (size_t i=0;i<_v.size();++i)v[i]=_v[i].val();
            return v;
        }else{
            std::vector<atcoder::static_modint<1224736769>>s1(_s.size()),t1(_t.size());
            std::vector<atcoder::static_modint<1045430273>>s2(_s.size()),t2(_t.size());
            std::vector<atcoder::static_modint<1007681537>>s3(_s.size()),t3(_t.size());
            for(size_t i=0;i<_s.size();++i){
                s1[i]=_s[i].value();
                s2[i]=_s[i].value();
                s3[i]=_s[i].value();
            }
            for(size_t i=0;i<_t.size();++i){
                t1[i]=_t[i].value();
                t2[i]=_t[i].value();
                t3[i]=_t[i].value();
            }
            auto v1=atcoder::convolution(s1,t1);
            auto v2=atcoder::convolution(s2,t2);
            auto v3=atcoder::convolution(s3,t3);
            T v(sz);
            for(size_t i=0;i<sz;++i){
                v[i]=garner(std::vector<long long>{v1[i].val(),v2[i].val(),v3[i].val()},std::vector<long long>{1224736769,1045430273,1007681537,(long long)Mint::get_mod()});
            }
            return v;
        }
    }
    template<typename T>
    T fact(const T& s){
        return s.fact();
    }
    template<typename T>
    T pow(const T& s,long long i){
        return s.pow(i);
    }
};
template<typename Mint>using fps=FPS_BASE<Mint,_FPS<Mint>>;