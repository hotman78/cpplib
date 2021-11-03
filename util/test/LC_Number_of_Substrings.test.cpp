#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include"../ACL.hpp"
#include "../template.hpp"

int main(){
    using namespace atcoder;
    string s;
    cin>>s;
    int n=s.size();
    auto sa=suffix_array(s);
    auto lcp=lcp_array(s,sa);
    lint ans=n-sa[0];
    for(int i=0;i<n-1;++i){
        ans+=(n-sa[i+1])-lcp[i];
    }
    cout<<ans<<endl;
}