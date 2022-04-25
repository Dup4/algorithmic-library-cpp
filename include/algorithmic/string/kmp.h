#ifndef ALGORITHMIC_STRING_KMP_H_
#define ALGORITHMIC_STRING_KMP_H_

#include <string.h>
#include <string>
#include <vector>

namespace algorithmic::string {

class KMP {
public:
    KMP() = default;

    KMP(const size_t n) {
        next_.reserve(n + 1);
    }

    // `next_[i]` represents the length of the longest
    // common prefix and suffix of the first i characters
    void GenNext(const char *s, const size_t len) {
        next_.resize(len + 1);

        int j;
        size_t i;

        j = next_[0] = -1;
        i = 0;

        while (i < len) {
            while (-1 != j && s[i] != s[j]) {
                j = next_[j];
            }

            next_[++i] = ++j;
        }
    }

    void GenNext(const std::string &s) {
        GenNext(s.c_str(), s.length());
    }

    const std::vector<int> &GetNext() const {
        return next_;
    }

    // `s` is the match string
    // `t` is the pattern string
    // returns the subscript where `t` appers in `s`
    std::vector<int> MatchString(const char *s, const int len_s, const char *t, const int len_t) {
        GenNext(t, len_t);

        int i = 0, j = 0;
        auto res = std::vector<int>();

        while (i < len_s) {
            while (-1 != j && s[i] != t[j]) {
                j = next_[j];
            }

            ++i, ++j;

            if (j >= len_t) {
                res.push_back(i - len_t);
                j = next_[j];
            }
        }

        return res;
    }

    std::vector<int> MatchString(const std::string &s, const std::string &t) {
        return MatchString(s.c_str(), s.length(), t.c_str(), t.length());
    }

private:
    std::vector<int> next_;
};

}  // namespace algorithmic::string

#endif  // ALGORITHMIC_STRING_KMP_H_
