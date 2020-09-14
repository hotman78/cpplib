#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../online_Zalgo.hpp"
#include "../../util/template.hpp"

int main(){
    string s;
    cin>>s;
    online_Zalgo z;
    for(auto e:s)z.add(e);
    vec v(s.size());
    rep(i,s.size())v[i]=z[i];
    output(v);
}