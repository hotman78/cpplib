#pragma once
#include<tuple>

/**
 * @brief 最大値とその位置
 */

template<typename T,typename E>
struct argmax{
    std::pair<T,E> operator()(const std::pair<T,E>& s,const std::pair<T,E>& t){
        return s.second>=t.second?s:t;
    }
};