#pragma once
#include <random>
#include <chrono>

template <typename T> struct RandomNumberGenerator {
    std::mt19937 mt;
    RandomNumberGenerator()
        : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}

    T operator()(T a, T b) {                               // [a, b)
        if constexpr (std::is_floating_point<T>::value) {  // 浮動小数点数の場合
            std::uniform_real_distribution<T> dist(a, b);
            return dist(mt);
        } else {
            std::uniform_int_distribution<T> dist(a, b - 1);
            return dist(mt);
        }
    }

    T operator()(T b) {  // [0, b)
        return (*this)(0, b);
    }
};

// 重み付き確率分布
template <typename T> int PMF(const std::vector<T>& v) {
    RandomNumberGenerator<double> rnd;
    T sm = 0;
    for (int i = 0; i < v.size(); i++) {
        sm += v[i];
    }
    T p = rnd(0, sm);
    int idx = 0;
    while (p > 0) {
        p -= v[idx];
        idx++;
    }
    return idx - 1;
}