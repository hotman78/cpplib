#pragma once
#include"maybe.hpp"

template<typename T,typename F>
struct monoid{
    using M=monoid<T,F>;
    maybe<T> val;
    F op;
    monoid(F op):val(maybe<T>()),op(op){}
    monoid(T val,F op):val(maybe<T>(val)),op(op){}
    maybe<T> get(){return val;}
    void set(T x){return val=maybe<T>(x);}
    M operator+(const M& rhs){
        if(val.is_none())return rhs;
        if(rhs.val.is_none())return *this;
        return monoid(op(get().unwrap(),rhs.get().unwrap()),op);
    }
};