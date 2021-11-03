#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../string/Z_algorizm.cpp"

int main(){
    string s;
    cin>>s;
    auto d=Z_algorizm(s);
    output(d);
}
