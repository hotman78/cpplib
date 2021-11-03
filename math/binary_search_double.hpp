#pragma once
#include<functional>
/**
 * @brief 二分探索(double)
 */

template<typename F>
long double bs(long double mn,long double mx,F func) {
    long double left = mn;
    long double right =mx;
    for(int i=0;i<100;i++){
        long double mid=(right+left)*0.5;
        if (!func(mid)) right = mid;
        else left = mid;
    }
    return left;
}