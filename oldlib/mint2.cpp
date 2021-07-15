template <uint_fast64_t Modulus> class mint {
    using u64 = uint_fast64_t;
    public:
    u64 a;
    constexpr mint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr mint operator+(const mint rhs) const noexcept {
        return mint(*this) += rhs;
    }
    constexpr mint operator-(const mint rhs) const noexcept {
        return mint(*this) -= rhs;
    }
    constexpr mint operator*(const mint rhs) const noexcept {
        return mint(*this) *= rhs;
    }
    constexpr mint operator/(const mint rhs) const noexcept {
        return mint(*this) /= rhs;
    }
    constexpr mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr mint &operator*=(const mint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr mint operator++(int n) const noexcept {
        return mint(*this) +=1;
    }
    constexpr mint operator--(int n) const noexcept {
        return mint(*this) -=1;
    }
};
template <uint_fast64_t Modulus>ostream& operator<<(ostream& lhs, const mint<Modulus>& rhs) noexcept {
    lhs << rhs.a;
    return lhs;
}
template <uint_fast64_t Modulus>istream& operator>>(istream& lhs, const mint<Modulus>& rhs) noexcept {
    lhs >> rhs.a;
    return lhs;
}