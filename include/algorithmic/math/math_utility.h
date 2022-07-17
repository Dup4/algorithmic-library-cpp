#ifndef ALGORITHMIC_MATH_BM_MATH_UTILITY_H
#define ALGORITHMIC_MATH_BM_MATH_UTILITY_H

#include <limits>
#include <type_traits>

namespace algorithmic::math {

class MathUtility {
public:
    template <typename A,
              typename B,
              std::enable_if_t<std::numeric_limits<A>::is_integer && std::numeric_limits<B>::is_integer, bool> = true>
    static A Gcd(A a, B b) {
        return b ? Gcd(b, a % b) : a;
    }
};

}  // namespace algorithmic::math

#endif  // ALGORITHMIC_MATH_BM_MATH_UTILITY_H
