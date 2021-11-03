#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../math/FPS_mint.hpp"
#include "../graph_template.hpp"
#include "../centroid_decomposition.hpp"
#include "../../util/template.hpp"
#include "../../math/mod_int.hpp"
#include "../../math/garner.hpp"

template<int MOD>
fps<mod_int<MOD>> solve(int n,const graph&g,const vector<int>&d){
    using fps=fps<mod_int<MOD>>;
    fps ans;
    std::bitset<200000>used;
    rep(i,n){
        fps s{1};
        used[d[i]]=1;
        for(auto e:g[d[i]]){
            fps v{0};
            auto f=[&](auto f,lint n,lint p,lint cnt){
                if(used[n])return;
                if((int)v.size()==cnt)v.resize(v.size()*2);
                if((int)s.size()==cnt)s.resize(s.size()*2);
                v[cnt]++;
                s[cnt]++;
                for(auto e:g[n]){
                    if(p==e)continue;
                    f(f,e,n,cnt+1);
                }
            };
            f(f,e,-1,1);
            ans-=v*v;
        }
        ans+=s*s;
    }
    ans>>=1;
    ans/=2;
    ans.resize(n-1,0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    graph g=load_tree0(n);
    centroid_decomposition cd(g);
    auto d=cd.get_euler_tour();
    auto s=solve<1224736769>(n,g,d);
    auto t=solve<1045430273>(n,g,d);
    vector<lint>ans(n-1);
    for(int i=0;i<n-1;++i){
        ans[i]=garner(vector<long long>{(long long)s[i].value(),(long long)t[i].value()},vector<long long>{1224736769LL,1045430273LL,1LL<<40});
    }
    output(ans);
}