#ifndef ALGORITHMIC_MATH_BM_MATH_UTILITY_H
#define ALGORITHMIC_MATH_BM_MATH_UTILITY_H

#include <limits>
#include <type_traits>
#include <vector>

namespace algorithmic::math {

class MathUtility {
public:
    template <typename A,
              typename B,
              std::enable_if_t<std::numeric_limits<A>::is_integer && std::numeric_limits<B>::is_integer, bool> = true>
    static A Gcd(A a, B b) {
        return b ? Gcd(b, a % b) : a;
    }

    template <typename T, std::enable_if_t<std::numeric_limits<T>::is_integer, bool> = true>
    static T Gcd(const std::vector<T>& vec) {
        T res = 0;

        for (const auto& num : vec) {
            res = Gcd(res, num);
        }

        return res;
    }

    template <typename A,
              typename B,
              std::enable_if_t<std::numeric_limits<A>::is_integer && std::numeric_limits<B>::is_integer, bool> = true>
    static A Lcm(A a, B b) {
        return a / Gcd(a, b) * b;
    }

    template <typename T, std::enable_if_t<std::numeric_limits<T>::is_integer, bool> = true>
    static T Lcm(const std::vector<T>& vec) {
        T res = 1;

        for (const auto& num : vec) {
            res = Lcm(res, num);
        }

        return res;
    }

    template <typename T, std::enable_if_t<std::numeric_limits<T>::is_integer, bool> = true>
    static T QuickPow(T base, T n) {
        T res = 1;

        while (n) {
            if (n & 1) {
                res = res * base;
            }

            base = base * base;
            n >>= 1;
        }

        return res;
    }

    template <typename T, std::enable_if_t<std::numeric_limits<T>::is_integer, bool> = true>
    static T QuickPow(T base, T n, T mod) {
        T res = 1;
        base = base % mod;

        while (n) {
            if (n & 1) {
                res = res * base % mod;
            }

            base = base * base % mod;
            n >>= 1;
        }

        return res;
    }
};

}  // namespace algorithmic::math

#endif  // ALGORITHMIC_MATH_BM_MATH_UTILITY_H
