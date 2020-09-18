#pragma once
#include<algorithm>

/**
 * @brief 最小値
 */

template<typename T>
struct MIN{
    T operator()(const T& s,const T& t){
        return std::min(s,t);
    }
};