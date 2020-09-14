#pragma once
#include<atcoder/modint>
#include<iostream>
using namespace atcoder;

template<int MOD>
std::ostream& operator<<(std::ostream& lhs, const atcoder::static_modint<MOD>& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}

template<int MOD>
std::istream& operator>>(std::istream& lhs,atcoder::static_modint<MOD>& rhs) noexcept {
    unsigned int x;
    lhs >> x;
    rhs=x;
    return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const atcoder::modint& rhs) noexcept {
    lhs << rhs.val();
    return lhs;
}

std::istream& operator>>(std::istream& lhs,atcoder::modint& rhs) noexcept {
    unsigned int x;
    lhs >> x;
    rhs=x;
    return lhs;
}