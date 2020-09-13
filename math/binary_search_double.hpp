#pragma once
#include<functional>
/**
 * @brief 二分探索(double)
 */

template<typename F>
double bs(double mn,double mx,F func) {
    double left = mn;
    double right =mx;
    for(int i=0;i<100;i++){
        double mid=(right+left)*0.5;
        if (!func(mid)) right = mid;
        else left = mid;
    }
    return left;
}