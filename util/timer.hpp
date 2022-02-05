#pragma once
#include<chrono>

struct timer{
    std::chrono::system_clock::time_point  start;
    timer(){
        start=std::chrono::system_clock::now();
    }
    double operator()(){
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
    }
};