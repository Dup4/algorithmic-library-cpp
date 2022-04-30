#ifndef ALGORITHMIC_MISC_DEBUG_H
#define ALGORITHMIC_MISC_DEBUG_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

inline const char* COLOR_GREEN = "\033[0;32m";
inline const char* COLOR_RED = "\033[0;31m";
inline const char* COLOR_YELLOW = "\033[0;33m";
inline const char* COLOR_END = "\033[0m";

void ptt(const std::string& s) {
    std::cout << s;
}

template <typename A, typename B>
void ptt(const std::map<A, B>& m) {
    std::cout << "{";
    int first = 1;
    for (const auto& [k, v] : m) {
        if (first) {
            first ^= 1;
        } else {
            std::cout << ", ";
        }

        std::cout << k << ":" << v;
    }
    std::cout << "}";
}

template <typename T>
void ptt(const T& arg) {
    std::cout << arg;
}

template <template <typename...> typename T, typename t>
void ptt(const T<t>& arg) {
    int first = 1;
    for (const auto& a : arg) {
        if (first) {
            first ^= 1;
        } else {
            std::cout << ' ';
        }

        std::cout << a;
    }
}

void pt_endl() {}

template <typename T, typename... A>
void pt_endl(const T& arg, const A&... args) {
    ptt(arg);
    std::cout << std::endl;
    pt_endl(args...);
}

void pt_space() {
    std::cout << std::endl;
}

template <typename T, typename... A>
void pt_space(const T& arg, const A&... args) {
    ptt(arg);
    std::cout << std::endl;
    pt_space(args...);
}

#define pt(...) pt_endl(__VA_ARGS__)

#define DBG_PRINT_0()

#define DBG_PRINT_1(x)                       \
    {                                        \
        std::cout << COLOR_YELLOW;           \
        std::cout << #x << " -> ";           \
        ptt(x);                              \
        std::cout << COLOR_END << std::endl; \
    }

#define DBG_PRINT_2(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_1(__VA_ARGS__); \
    }

#define DBG_PRINT_3(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_2(__VA_ARGS__); \
    }

#define DBG_PRINT_4(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_3(__VA_ARGS__); \
    }

#define DBG_PRINT_5(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_4(__VA_ARGS__); \
    }

#define DBG_PRINT_6(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_5(__VA_ARGS__); \
    }

#define DBG_PRINT_7(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_6(__VA_ARGS__); \
    }

#define DBG_PRINT_8(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_7(__VA_ARGS__); \
    }

#define DBG_PRINT_9(x, ...)       \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_8(__VA_ARGS__); \
    }

#define DBG_PRINT_10(x, ...)      \
    {                             \
        DBG_PRINT_1(x);           \
        DBG_PRINT_9(__VA_ARGS__); \
    }

#define DBG_PRINT_11(x, ...)       \
    {                              \
        DBG_PRINT_1(x);            \
        DBG_PRINT_10(__VA_ARGS__); \
    }

#define DBG_PRINT_12(x, ...)       \
    {                              \
        DBG_PRINT_1(x);            \
        DBG_PRINT_11(__VA_ARGS__); \
    }

#define DBG_PRINT_13(x, ...)       \
    {                              \
        DBG_PRINT_1(x);            \
        DBG_PRINT_12(__VA_ARGS__); \
    }

#define DBG_PRINT_14(x, ...)       \
    {                              \
        DBG_PRINT_1(x);            \
        DBG_PRINT_13(__VA_ARGS__); \
    }

#define DBG_PRINT_15(x, ...)       \
    {                              \
        DBG_PRINT_1(x);            \
        DBG_PRINT_14(__VA_ARGS__); \
    }

#define DBG_PRINT_16(x, ...)       \
    {                              \
        DBG_PRINT_1(x);            \
        DBG_PRINT_15(__VA_ARGS__); \
    }

#define _DBG_NARG_(...) _DBG_NARG__(__VA_ARGS__, _DBG_RSET_N_())
#define _DBG_NARG__(...) _DBG_ARG_N_(__VA_ARGS__)
#define _DBG_ARG_N_(__1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, N, ...) N
#define _DBG_RSET_N_() 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define _DBG_PRINT_(NARG, ...) _DBG_PRINT__(NARG, __VA_ARGS__)
#define _DBG_PRINT__(NARG, ...) DBG_PRINT_##NARG(__VA_ARGS__)

#define dbg(...) _DBG_PRINT_(_DBG_NARG_(__VA_ARGS__), __VA_ARGS__)

template <typename T>
void assert_eq(const T& current, const T& expected) {
    dbg(current, expected);

    if (current == expected) {
        std::cout << COLOR_GREEN;
        pt("correct!");
    }

    if (current != expected) {
        std::cout << COLOR_RED;
        pt("wrong answer.");
    }

    std::cout << COLOR_END;
}

#endif  // ALGORITHMIC_MISC_DEBUG_H
