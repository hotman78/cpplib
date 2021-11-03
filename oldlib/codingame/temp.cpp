#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC push_options
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
//#include <xmmintrin.h>
//#include <immintrin.h>
using namespace::std;
__attribute__((constructor))void init(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include<ext/pb_ds/tag_and_trait.hpp>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// typedef mp::number<mp::cpp_dec_float<0>> cdouble;
// typedef mp::cpp_int cint;
//template<typename T>using pbds=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
//template<typename T>using pbds_map=__gnu_pbds::tree<T,T,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
//template<typename T,typename E>using hash_map=__gnu_pbds::gp_hash_table<T,E>;
//template<typename T>using pqueue =__gnu_pbds::priority_queue<T, greater<T>,__gnu_pbds::rc_binomial_heap_tag>;
typedef int lint;
#define INF (1LL<<30)
#define IINF (1<<30)
#define EPS (1e-10)
#define endl ('\n')
#define MOD 1000000007LL
//#define MOD 998244353LL
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
#define rep(i,n) for(lint i=0;i<lint(n);++i)
#define repi(i,a,b) for(lint i=lint(a);i<(lint)(b);++i)
#define rrep(i,n) for(lint i=lint(n)-1;i>=0;--i)
#define rrepi(i,a,b) for(lint i=lint(b)-1;i>=lint(a);--i)
#define irep(i) for(lint i=0;;++i)
#define all(n) begin(n),end(n)
#define dist(a,b,c,d) sqrt(pow(a-c,2)+pow(b-d,2))
inline lint gcd(lint A,lint B){return B?gcd(B,A%B):A;}
inline lint lcm(lint A,lint B){return A/gcd(A,B)*B;}
// inline cint cgcd(cint A,cint B){return B?cgcd(B,A%B):A;}
// inline cint clcm(cint A,cint B){return A/cgcd(A,B)*B;}
bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
const vector<lint> dx={1,0,-1,0,1,1,-1,-1};
const vector<lint> dy={0,1,0,-1,-1,1,-1};
#define SUM(v) accumulate(all(v),0LL)
auto call=[](auto f,auto... args){return f(f,args...);};

unsigned long xor128(){ 
    static unsigned long x=123456789,y=362436069,z=521288629,w=88675123; 
    unsigned long t; 
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) ); 
} 

double timer(auto f){
    auto s=chrono::system_clock::now();
    f();
    auto e=chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(e-s).count(); 
}

int main(){
    lint h,w;
    cin>>w>>h;
    cin.ignore();
    vector<string>s(h);
    rep(i,h){
        getline(cin,s[i]);
    }
    lint idx=0;
    vector<vector<lint>> point(h,vector<lint>(w));
    // game loop
    vector<lint>pre(5,0);
    auto f=[&](){
        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();
        vector<pair<lint,lint>> enemy;
        vector<tuple<lint,lint,lint>> player;
        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int _x; // position in the grid
            int _y; // position in the grid
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> _y >> _x >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();
            if(mine){
                player.emplace_back(_x,_y,pacId);
            }else{
                enemy.emplace_back(_x,_y);
            }
        }
        vector<vector<lint>>v(player.size(),vec(4,0));
        for(auto e:enemy){
            rep(i,player.size()){
                lint mx=get<0>(player[i]),my=get<1>(player[i]);
                rep(j,4){
                    lint x=(mx+dx[j]+h)%h,y=(my+dy[j]+w)%w;
                    while(x>=h)x-=h;
                    while(y>=w)y-=w;
                    if((abs(x-e.first)+abs(y-e.second))<=1){
                        v[i][j]--;
                    }
                }
            }
        }
        rep(k,player.size()){
            rep(i,player.size()){
                lint mx=get<0>(player[i]),my=get<1>(player[i]);
                lint ex=get<0>(player[k]),ey=get<1>(player[k]);
                rep(j,4){
                    lint x=(mx+dx[j]+h)%h,y=(my+dy[j]+w)%w;
                    if((abs(x-ex)+abs(y-ey))<=1){
                        v[i][j]--;
                    }
                }
            }
        }
        int pellet; // all pellets in sight
        cin >> pellet; cin.ignore();
        rep(k,pellet){
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> y >> x >> value; cin.ignore();
            rep(i,player.size()){
                lint mx=get<0>(player[i]),my=get<1>(player[i]);
                rep(j,4){
                    lint tx=(mx+dx[j]+h)%h,ty=(my+dy[j]+w)%w;
                    if((abs(tx-x)+abs(ty-y))==0)v[i][j]+=value;
                }
            }
        }
        rep(k,player.size()){
            v[k][(pre[k]+2)&3]--;
            lint mx=get<0>(player[k]),my=get<1>(player[k]);
            tuple<lint,lint,lint> mn=make_tuple(-INF,mx,my);
            rep(i,4){
                lint tx=(mx+dx[i]+h)%h,ty=(my+dy[i]+w)%w;
                if(s[tx][ty]=='#')continue;
                if(get<0>(mn)<=v[k][i]){
                    mn=make_tuple(v[k][i],tx,ty);
                    pre[get<2>(player[k])]=i;
                }
            }
            if(get<0>(mn)<0){
                vector<lint>tmp;
                rep(j,4){
                    lint tx=(mx+dx[j]+h)%h,ty=(my+dy[j]+w)%w;
                    if(s[tx][ty]=='#')continue;
                    if(v[k][j]==0){
                        tmp.push_back(j);
                    }
                }
                if(tmp.size()==0){
                    tmp.push_back(pre[k]);
                }
                lint i=tmp[myScore%tmp.size()];
                mn=make_tuple(v[k][i],(mx+dx[i]+h)%h,(my+dy[i]+w)%w);
                pre[get<2>(player[k])]=i;
                idx=(idx+i)%4;
            }
            //point[get<2>(mn)][get<1>(mn)]+=v[mx][my]*0.3;
            //point[get<2>(mn)][get<1>(mn)]--;
            if(k)cout<<"|";
            cout<<"MOVE "<<get<2>(player[k])<<" "<<get<2>(mn)<<" "<<get<1>(mn);
        }
        cout<<endl;
         // MOVE <pacId> <x> <y>
    };
    while(1){
        cerr<<timer(f)<<endl;
    }
}