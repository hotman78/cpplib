#pragma once
#include<fstream>
#include<vector>

std::ostream& operator<<(std::ostream& lhs, const mint& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}
std::istream& operator>>(std::istream& lhs,mint& rhs) noexcept {
    long long x;
    lhs >> x;
    rhs=x;
    return lhs;
}

int MOD_NOW=-1;
int sz=0;
std::vector<mint>fact_table,fact_inv_table;

void update(int x){
    if(MOD_NOW!=mint::mod()||sz==0){
        fact_table.assign(1,1);
        fact_inv_table.assign(1,1);
        sz=1;
        MOD_NOW=mint::mod();
    }
    while(sz<=x){
        fact_table.resize(sz*2);
        fact_inv_table.resize(sz*2);
        for(int i=sz;i<sz*2;++i){
            fact_table[i]=fact_table[i-1]*i;
        }
        fact_inv_table[sz*2-1]=fact_table[sz*2-1].inv();
        for(int i=sz*2-2;i>=sz;--i){
            fact_inv_table[i]=fact_inv_table[i+1]*(i+1);
        }
        sz*=2;
    }
}

inline mint fact(int x){
    assert(x>=0);
    update(x);
    return fact_table[x];
}
inline mint fact_inv(int x){
    assert(x>=0);
    update(x);
    return fact_inv_table[x];
}
inline mint comb(int x,int y){
    if(x<0||x<y||y<0)return 0;
    return fact(x)*fact_inv(y)*fact_inv(x-y);
}
inline mint perm(int x,int y){
    return fact(x)*fact_inv(y);
}
inline mint multi_comb(int x,int y){
    return comb(x+y-1,y);
}