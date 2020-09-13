#pragma once
#include<random>
#include<chrono>

struct RandomNumberGenerator {
    std::mt19937 mt;

    RandomNumberGenerator() : mt(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    int operator()(int a, int b) { // [a, b)
        std::uniform_int_distribution< int > dist(a, b - 1);
        return dist(mt);
    }

    int operator()(int b) { // [0, b)
        return (*this)(0, b);
    }
};