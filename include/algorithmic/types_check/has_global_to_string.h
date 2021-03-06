#ifndef ALGORITHMIC_TYPES_CHECK_HAS_GLOBAL_TO_STRING_H
#define ALGORITHMIC_TYPES_CHECK_HAS_GLOBAL_TO_STRING_H

#include <type_traits>

namespace algorithmic::types_check {

template <typename T>
class has_global_to_string {
private:
    template <typename U>
    static auto check(int) -> decltype(ToString(std::declval<U>()), std::true_type());

    template <typename U>
    static std::false_type check(...);

public:
    enum { value = std::is_same<decltype(check<T>(0)), std::true_type>::value };
};

template <typename T>
inline constexpr bool has_global_to_string_v = has_global_to_string<T>::value;

}  // namespace algorithmic::types_check

#endif  // ALGORITHMIC_TYPES_CHECK_HAS_GLOBAL_TO_STRING_H
