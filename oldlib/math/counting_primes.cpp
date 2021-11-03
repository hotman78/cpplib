#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC push_options
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
#include <xmmintrin.h>
#include <immintrin.h>
using namespace::std;
__attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<0>> cdouble;
// typedef mp::cpp_int cint;
template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;
typedef long long lint;
#define INF (1LL<<60)
#define IINF (1<<30)
#define LINF (9223372036854775807LL)
#define EPS (1e-10)
#define endl ('\n')
#define MOD 1000000007LL
//#define MOD 998244353LL
//#define MOD 18446744069414584321ULL
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
template<typename T>inline void numout(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i<INF/2?i:"INF";f=1;}cout<<endl;}
template<typename T>inline void numout2(T t){for(auto i:t)numout(i);}
template<typename T>inline void output(T t){bool f=0;for(auto i:t){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}
template<typename T>inline void output2(T t){for(auto i:t)output(i);}
template<typename T>inline void _output(T t){bool f=0;for(lint i=0;i<t.size();i++){cout<<f?"":" "<<t[i];f=1;}cout<<endl;}
template<typename T>inline void _output2(T t){for(lint i=0;i<t.size();i++)output(t[i]);}
#define rep(i,...) for(auto i:range(__VA_ARGS__)) 
#define rrep(i,...) for(auto i:reversed(range(__VA_ARGS__)))
#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
#define irep(i) for(lint i=0;;++i)
inline vector<int64_t> range(int64_t n){vector<int64_t>v(n);iota(v.begin(),v.end(),0LL);return v;}
inline vector<int64_t> range(int64_t a,int64_t b){vector<int64_t>v(b-a);iota(v.begin(),v.end(),a);return v;}
inline vector<int64_t> range(int64_t a,int64_t b,int64_t c){vector<int64_t>v((b-a+c-1)/c);for(int i=0;i<(int)v.size();++i)v[i]=i?v[i-1]+c:a;return v;}
inline auto reversed(auto v){reverse(v.begin(),v.end());return v;}
#define all(n) begin(n),end(n)
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
//inline lint gcd(lint A,lint B){return B?gcd(B,A%B):A;}
//inline lint lcm(lint A,lint B){return A/gcd(A,B)*B;}
// inline cint cgcd(cint A,cint B){return B?cgcd(B,A%B):A;}
// inline cint clcm(cint A,cint B){return A/cgcd(A,B)*B;}
bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
auto call=[](auto f,auto... args){return f(f,args...);};
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}

int main(){
	mat v(10'000'001);
	lint t;
	cin>>t;
	assert(1<=t&&t<=100'000);
	while(t--){
		lint x,y;
		cin>>x>>y;
		lint ans=0;
		assert(1<=x&&x<=10'000'000);
		assert(1<=y&&y<=10'000'000);
        if(x==1&&y==2){
            cout<<0<<endl;
            continue;
        }
		if(x>y-x)x=y-x;
		{
			for(lint i=1;i*i<=y;i++){
				if(y%i)continue;
				{
					__int128_t a=i;
					if(a%2){
						lint b=(a*a-1)*y/(2*a*x);
						if((a*a-1)*y%(2*a*x)==0&&1<=b&&b<=100'000'000&&a<b){
							ans++;
						}
					}
				}
				if(y==i*i)continue;
				{
					__int128_t a=y/i;
					if(a%2){
						lint b=(a*a-1)*y/(2*a*x);
						if((a*a-1)*y%(2*a*x)==0&&1<=b&&b<=100'000'000&&a<b){
							ans++;
						}
					}
				}
			}
			ans+=100'000'000/y;
		}
		cout<<ans<<endl;
	}
}