#ifndef ALGORITHMIC_MISC_DETECT_H
#define ALGORITHMIC_MISC_DETECT_H

#include <string>

namespace algorithmic::misc {

class Detect {
public:
    static std::string Compiler() {
        std::string res = "";

        res += "Compiler Version: " + detect_compiler();

        return res;
    }

private:
    static std::string detect_compiler() {
        constexpr auto compiler = []() -> std::string {
#ifdef __clang__
            return "clang++";
#else
            return "g++";
#endif
        };

        constexpr auto version = []() -> std::string {
#ifdef __clang__
            return std::to_string(__clang_major__) + "." + std::to_string(__clang_minor__) + "." +
                   std::to_string(__clang_patchlevel__);
#else
            return std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "." +
                   std::to_string(__GNUC_PATCHLEVEL__);
#endif
        };

        return compiler() + " " + version();
    }
};

}  // namespace algorithmic::misc

#endif  // ALGORITHMIC_MISC_DETECT_H
