#include <cassert>
#include <charconv>
#include <cstdlib>
#include <cstring>
#include <string>

template <typename T> T env(const std::string& s, T def = T()) {
    char* p = getenv(s.c_str());
    if (p == nullptr) return def;
    T res;
    std::from_chars(p, p + strlen(p), res);
    return res;
}
