#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#include "../dataStructure/swag.cpp"

int main(){
    swag<lint>swag;
    lint n,l;
    cin>>n>>l;
    vector<lint> a(n);
    rep(i,n)cin>>a[i];
    rep(i,l){
        swag.push(a[i]);
    }
    rep(i,n-l){
        cout<<swag.fold()<<" ";
        swag.push(a[i+l]);
        swag.pop();
    }
    cout<<swag.fold()<<endl;
}