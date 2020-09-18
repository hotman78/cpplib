#pragma once
#include<algorithm>
/**
 * @brief 最大値
 */

template<typename T>
struct MAX{
    T operator()(const T& s,const T& t){
        return std::max(s,t);
    }
};