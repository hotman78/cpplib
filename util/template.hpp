#pragma once
#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
#include"ioutil.hpp"
struct __INIT__{__INIT__(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}}__INIT__;
typedef long long lint;
constexpr long long INF=1LL<<60;
constexpr int IINF=1<<30;
constexpr double EPS=1e-10;
#ifndef REACTIVE
    #define endl '\n';
#endif
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
template<typename T>using V=vector<T>;
template<typename T>using VV=V<V<T>>;
#define output(t) {bool f=0;for(auto val:(t)){cout<<(f?" ":"")<<val;f=1;}cout<<endl;}
#define output2(t) {for(auto i:t)output(i);}
#define debug(t) {bool f=0;for(auto i:t){cerr<<(f?" ":"")<<i;f=1;}cerr<<endl;}
#define debug2(t) {for(auto i:t)debug(i);}
#define loop(n) for(long long _=0;_<(long long)(n);++_)
#define _overload4(_1,_2,_3,_4,name,...) name
#define __rep(i,a) repi(i,0,a,1)
#define _rep(i,a,b) repi(i,a,b,1)
#define repi(i,a,b,c) for(long long i=(long long)(a);i<(long long)(b);i+=c)
#define rep(...) _overload4(__VA_ARGS__,repi,_rep,__rep)(__VA_ARGS__)
#define _overload3_rev(_1,_2,_3,name,...) name
#define _rep_rev(i,a) repi_rev(i,0,a)
#define repi_rev(i,a,b) for(long long i=(long long)(b)-1;i>=(long long)(a);--i)
#define rrep(...) _overload3_rev(__VA_ARGS__,repi_rev,_rep_rev)(__VA_ARGS__)

#define all(n) begin(n),end(n)
template<typename T,typename E>bool chmin(T& s,const E& t){bool res=s>t;s=min<T>(s,t);return res;}
template<typename T,typename E>bool chmax(T& s,const E& t){bool res=s<t;s=max<T>(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
#if __cplusplus>=201703L
    template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
#endif
#define bit(n,a) ((n>>a)&1)
#define extrep(v,...) for(auto v:make_mat_impl({__VA_ARGS__}))
vector<vector<long long>> make_mat_impl(vector<long long> v){if(v.empty())return vector<vector<long long>>(1,vector<long long>());long long n=v.back();v.pop_back();vector<vector<long long>> ret;vector<vector<long long>> tmp=make_mat_impl(v);for(auto e:tmp)for(long long i=0;i<n;++i){ret.push_back(e);ret.back().push_back(i);}return ret;}
using graph=vector<vector<int>>;
template<typename T>using graph_w=vector<vector<pair<int,T>>>;

#if __cplusplus>=201703L
    constexpr inline long long powll(long long a,long long b){long long res=1;while(b--)res*=a;return res;}
#endif

template<typename T,typename E>pair<T,E>& operator+=(pair<T,E>&s,const pair<T,E>&t){s.first+=t.first;s.second+=t.second;return s;}
template<typename T,typename E>pair<T,E>& operator-=(pair<T,E>&s,const pair<T,E>&t){s.first-=t.first;s.second-=t.second;return s;}
template<typename T,typename E>pair<T,E> operator+(const pair<T,E>&s,const pair<T,E>&t){auto res=s;return res+=t;}
template<typename T,typename E>pair<T,E> operator-(const pair<T,E>&s,const pair<T,E>&t){auto res=s;return res-=t;}
#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);
int floor_pow(int n){return n?31-__builtin_clz(n):0;}
