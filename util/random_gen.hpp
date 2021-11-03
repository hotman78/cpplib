#pragma once
#include<random>
#include<chrono>

template<typename T>
struct RandomNumberGenerator {
    std::mt19937 mt;
    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    T operator()(T a, T b) { // [a, b)
        std::uniform_int_distribution< T > dist(a, b - 1);
        return dist(mt);
    }

    T operator()(T b) { // [0, b)
        return (*this)(0, b);
    }
};