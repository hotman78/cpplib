#pragma once
#include<algorithm>

template<typename T>
struct MIN{
    T operator()(const T& s,const T& t){
        return std::min(s,t);
    }
};