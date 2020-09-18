#pragma once
#include<algorithm>

template<typename T>
struct MAX{
    T operator()(const T& s,const T& t){
        return std::max(s,t);
    }
};