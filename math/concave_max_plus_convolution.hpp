#include"../DP/monotone_minima.hpp"
vector<lint> concave_max_plus_convolution(const vector<lint>& a,const vec& b){
    auto f=[&](lint i,lint j){
        if(i-j<0||(int)a.size()<=j||(int)b.size()<=i-j)return INF;
        else return -(a[j]+b[i-j]);
    };
    auto v=monotone_minima(a.size()+b.size()-1,b.size(),INF,f);
    output(v);
    vec res((int)a.size()+(int)b.size()-1);
    rep(i,a.size()+b.size()-1){
        res[i]=-f(i,v[i]);
    }
    return res;
};