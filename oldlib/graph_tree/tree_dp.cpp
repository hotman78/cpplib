auto tree_dp(const auto& g,const auto& f,const auto& res_e,int now=0,int par=-1){
    auto res=res_e;
    for(auto e:g[now]){
        res=f(res,tree_dp(g,f,res_e,e,now));
    }
    return res;
}
