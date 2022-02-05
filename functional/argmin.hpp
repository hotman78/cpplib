#pragma once
#include<tuple>

/**
 * @brief 最小値とその位置
 */

template<typename T,typename E>
struct argmin{
    std::pair<T,E> operator()(const std::pair<T,E>& s,const std::pair<T,E>& t){
        return s.second<=t.second?s:t;
    }
};