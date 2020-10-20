#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include"../../util/template.hpp"
#include"../hash_map.hpp"
#include"../../util/fastIO.hpp"

int main(){
    hash_map<lint,lint>m;
    lint q;
    fin>>q;
    while(q--){
        lint c;
        fin>>c;
        if(c==0){
            lint k,v;
            fin>>k>>v;
            m[k]=v;
        }else{
            lint k;
            fin>>k;
            fout<<m[k]<<endl;
        }
    }
}