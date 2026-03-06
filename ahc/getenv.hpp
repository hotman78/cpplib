#include <string>

template <typename T> T env(const std::string &name, T def) {
  char *val = getenv(name.c_str());
  if (val == nullptr)
    return def;
  return static_cast<T>(atoll(val));
}