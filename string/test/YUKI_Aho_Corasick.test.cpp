#define PROBLEM "https://yukicoder.me/problems/no/430"
#include"../AhoCorasick.hpp"
#include "../../util/template.hpp"

int main(){
    string s;
    cin>>s;
    lint q;
    cin>>q;
    AhoCorasick aho;
    while(q--){
        string t;
        cin>>t;
        aho.insert(t);
    }
    cout<<aho.count(s)<<endl;
}