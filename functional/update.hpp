#pragma once

/**
 * @brief 更新
 */

template<typename T>
struct update{
    T operator()(const T& s,const T& t){
        return t;
    }
};