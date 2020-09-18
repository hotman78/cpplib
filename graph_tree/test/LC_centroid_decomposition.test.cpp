#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../math/FPS_long.hpp"
#include "../graph_template.hpp"
#include "../centroid_decomposition.hpp"
#include "../../util/template.hpp"

int main(){
    lint n;
    cin>>n;
    graph g=load_tree0(n);
    centroid_decomposition cd(g);
    auto d=cd.get_euler_tour();
    fps ans;
    bitset<200000>used;
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
    output(ans);
}