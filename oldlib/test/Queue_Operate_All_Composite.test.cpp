
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include<bits/stdc++.h>
using namespace::std;
using lint=long long;
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)

template<typename T,typename E=T>
class swag{
    stack<pair<T,E>>front,back;
    int sz=0;
    public:
    void push_back(T val){
        if(back.empty()){
            back.emplace(val,f(e,val));
        }else{
            back.emplace(val,f(back.top().second,val));
        }
        sz++;
    }
    void pop_front(){
        if(front.empty()){
            while(!back.empty()){
                const T val=back.top().first;
                back.pop();
                if(front.empty())front.emplace(val,f(val,e));
                else front.emplace(val,f(val,front.top().second));
            }
        }
        front.pop();
        sz--;
    }
    E fold(){
        return f(front.empty()?e:front.top().second,back.empty()?e:back.top().second);
    }
    private:
    E f(const T& s,const T& t){
        return make_pair(t.first*s.first%998244353,(t.first*s.second%998244353+t.second)%998244353);
    }
    E e=make_pair(1,0);
};

int main(){
    swag<pair<lint,lint>>swag;
    lint n;
    cin>>n;
    rep(i,n){
        lint q;
        cin>>q;
        if(q==0){
            lint a,b;
            cin>>a>>b;
            swag.push_back(make_pair(a,b));
        }
        if(q==1){
            swag.pop_front();
        }
        if(q==2){
            lint x;
            cin>>x;
            auto d=swag.fold();
            cout<<(d.first*x%998244353+d.second)%998244353<<endl;
        }
    }
}