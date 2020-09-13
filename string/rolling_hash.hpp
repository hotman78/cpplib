#pragma once
#include<string>
#include<vector>
#include<set>
#include<tuple>

struct rolling_hash{
    using u64=std::uint64_t;
    constexpr static u64 mod=(1ULL<<61)-1;
    constexpr static u64 base=10007;
    int sz;
    u64 hash;
    constexpr rolling_hash():sz(0),hash(0){}
    constexpr rolling_hash(char c):sz(1),hash(c){}
    rolling_hash(std::string s):sz(0),hash(0){
        for(auto c:s)(*this)+=c;
    }
    constexpr u64 pow(u64 s,int t){
        u64 ret=1;
        while(t){
            if(t&1)ret=mul(ret,s);
            s=mul(s,s);
            t/=2;
        }
        return ret;
    }
    constexpr u64 add(u64 s,u64 t)noexcept{
        s+=t;
        return s>=mod?s-mod:s;
    }
    constexpr u64 sub(u64 s,u64 t)noexcept{
        if(s<t)s+=mod;
        return s-t;
    }
    constexpr u64 mul(u64 a,u64 b)noexcept{
        u64 au=a>>31,ad=a&((1ULL<<31)-1);
        u64 bu=b>>31,bd=b&((1ULL<<31)-1);
        u64 mid=au*bd+ad*bu;
        u64 ret=(au*bu*2+ad*bd+(mid>>30)+((mid&((1ULL<<30)-1))<<31));
        ret=(ret>>61)+(ret&mod);
        return ret>=mod?ret-mod:ret;
    }
    constexpr rolling_hash operator+(rolling_hash s)const noexcept{return rolling_hash(*this)+=s;}
    constexpr bool operator==(rolling_hash s)noexcept{return hash==s.hash&&sz==s.sz;}
    constexpr bool operator<(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<std::make_pair(s.hash,s.sz);}
    constexpr bool operator>(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>std::make_pair(s.hash,s.sz);}
    constexpr bool operator<=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)<=std::make_pair(s.hash,s.sz);}
    constexpr bool operator>=(rolling_hash s)const noexcept{return std::make_pair(hash,sz)>=std::make_pair(s.hash,s.sz);}
    constexpr rolling_hash operator+=(rolling_hash s)noexcept{
        (*this).hash=add((*this).hash*pow(base,s.sz),s.hash);
        (*this).sz+=s.sz;
        return *this;
    }
    constexpr int size(){return sz;}
};