
#include "algorithm.hpp"

#define transmitc auto&
#define transmitv auto
#define transmitvc auto&&

// although it is non-conforming,
// it as a syntactic sugar is very useful
// Maybe

ALWAYS_INLINE auto output(const std::string& str) {
    fputs(str.c_str(), stdout);
}

ALWAYS_INLINE auto output(const char* str) {
    fputs(str, stdout);
}

ALWAYS_INLINE auto output(const char c) {
    putchar(buf, stdout);
}

ALWAYS_INLINE std::string input() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

ALWAYS_INLINE std::string input(const std::string &str) {
    output(str);
    std::string s;
    std::getline(std::cin, s);
    return s;
}

ALWAYS_INLINE std::string input(const char str) {
    output(str);
    std::string s;
    std::getline(std::cin, s);
    return s;
}
