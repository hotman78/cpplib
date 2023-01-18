#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../../cpplib/util/template.hpp"
#include "../../../cpplib/graph_tree/centroid_decomposition.hpp"
#include "atcoder/convolution.hpp"

vector<long long> solve(int n,const graph&g,const vector<int>&d){
    using poly=vector<long long>;
    poly ans(n);
    std::bitset<200000>used;
    rep(i,n){
        poly s{1};
        used[d[i]]=1;
        for(auto e:g[d[i]]){
            poly v{0};
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
            auto res=atcoder::convolution_ll(v,v);
            for(int j=0;j<res.size();++j){
                ans[j]-=res[j];
            }
        }
        auto res=atcoder::convolution_ll(s,s);
        for(int j=0;j<res.size();++j){
            ans[j]+=res[j];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    graph g=load_tree0(n);
    centroid_decomposition cd(g);
    auto d=cd.get_euler_tour();
    auto ans=solve(n,g,d);
    vector<long long>ans2(n-1);
    for(int i=0;i<n-1;++i){
        ans2[i]=ans[i+1]/2;
    }
    output(ans2);
}