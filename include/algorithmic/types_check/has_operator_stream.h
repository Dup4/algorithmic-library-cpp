#ifndef ALGORITHMIC_TYPES_CHECK_HAS_OPERATOR_STREAM_H
#define ALGORITHMIC_TYPES_CHECK_HAS_OPERATOR_STREAM_H

#include <iostream>
#include <utility>

namespace algorithmic::types_check {

template <typename T>
class has_operator_stream {
private:
    template <typename U>
    static auto check(int) -> decltype(operator<<(std::cout, std::declval<U>()), std::true_type());

    template <typename U>
    static std::false_type check(...);

public:
    enum { value = std::is_same<decltype(check<T>(0)), std::true_type>::value };
};

template <typename T>
inline constexpr bool has_operator_stream_v = has_operator_stream<T>::value;

}  // namespace algorithmic::types_check

#endif  // ALGORITHMIC_TYPES_CHECK_HAS_OPERATOR_STREAM_H
