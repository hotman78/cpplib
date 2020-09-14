#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include"../ACL.hpp"
#include "../template.hpp"

int main(){
    string s;
    cin>>s;
    auto v=atcoder::suffix_array(s);
    output(v);
}