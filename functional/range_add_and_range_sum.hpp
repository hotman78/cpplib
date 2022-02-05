#pragma once
#include"../alga/maybe.hpp"

/**
 * @brief 区間加算
 */

template<typename T,typename E>
struct range_add_and_range_sum{
    T operator()(const maybe<T>& s,const E& t,int l,int r){
        return s.unwrap_or(T())+t*(r-l);
    }
};