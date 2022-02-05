#pragma once
#include<tuple>

/**
 * @brief 一次関数の合成
 */

template<typename T>
struct composite{
    //t(s(x))
    std::pair<T,T> operator()(const std::pair<T,T>& s,const std::pair<T,T>& t){
        return std::make_pair(s.first*t.first,s.second*t.first+t.second);
    }
};
