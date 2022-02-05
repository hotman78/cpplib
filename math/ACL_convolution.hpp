#include<atcoder/modint.hpp>
#include<atcoder/convolution.hpp>

#include"garner.hpp"
#include"../math/ceil_pow2.hpp"

#include<vector>

template<typename Mint>
std::vector<Mint> convolution(const std::vector<Mint>& _s,const std::vector<Mint>& _t){
    using T=std::vector<Mint>;
    if(_s.size()==0||_t.size()==0)return T();
    const size_t sz=_s.size()+_t.size()-1;
    std::vector<atcoder::static_modint<1224736769>>s1(_s.size()),t1(_t.size());
    std::vector<atcoder::static_modint<1045430273>>s2(_s.size()),t2(_t.size());
    std::vector<atcoder::static_modint<1007681537>>s3(_s.size()),t3(_t.size());
    for(size_t i=0;i<_s.size();++i){
        s1[i]=_s[i].val();
        s2[i]=_s[i].val();
        s3[i]=_s[i].val();
    }
    for(size_t i=0;i<_t.size();++i){
        t1[i]=_t[i].val();
        t2[i]=_t[i].val();
        t3[i]=_t[i].val();
    }
    auto v1=atcoder::convolution(s1,t1);
    auto v2=atcoder::convolution(s2,t2);
    auto v3=atcoder::convolution(s3,t3);
    T v(sz);
    for(size_t i=0;i<sz;++i){
        v[i]=garner(std::vector<long long>{v1[i].val(),v2[i].val(),v3[i].val()},std::vector<long long>{1224736769,1045430273,1007681537,(long long)Mint::mod()});
    }
    return v;
}