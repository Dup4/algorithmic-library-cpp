#ifndef ALGORITHMIC_STRING_KMP_H_
#define ALGORITHMIC_STRING_KMP_H_

#include <string.h>
#include <string>
#include <vector>

namespace algorithmic::string {

class ExKMP {
public:
    ExKMP() = default;

    ExKMP(const size_t n, const size_t m) {
        init(n, m);
    }

    ExKMP(const size_t n) {
        init(n, n);
    }

    // `next_[i]` represents the LCP length of `s[i:]` and `s`
    void GenNext(const char *s, const int len_s) {
        next_.resize(len_s);
        int p = 0, pos;
        next_[0] = len_s;

        while (p + 1 < len_s && s[p] == s[p + 1]) {
            ++p;
        }

        next_[pos = 1] = p;

        for (int i = 2; i < len_s; ++i) {
            int len = next_[i - pos];

            if (len + i < p + 1) {
                next_[i] = len;
            } else {
                // find the last position of
                // the positions that
                // have been matched for the substring
                int j = std::max(p - i + 1, 0);

                // brute force match
                while (i + j < len_s && s[j + 1] == s[i + j]) {
                    ++j;
                }

                p = i + (next_[pos = i] = j) - 1;
            }
        }
    }

    void GenNext(const std::string &s) {
        GenNext(s.c_str(), s.length());
    }

    const std::vector<int> &GetNext() const {
        return next_;
    }

    // `extend_[i]` represents the LCP length of `t[i:]` and `s`.
    void GenExtend(const char *s, int len_s, const char *t, int len_t) {
        GenNext(s, len_s);
        extend_.resize(len_t);
        int p = 0, pos;

        while (p < len_t && s[p] == t[p]) {
            ++p;
        }

        p = extend_[pos = 0] = p;

        for (int i = 1; i < len_s; ++i) {
            int len = next_[i - pos];

            if (len + i < p + 1) {
                extend_[i] = len;
            } else {
                int j = std::max(p - i + 1, 0);

                while (i + j < len_s && j < len_t && t[j + 1] == s[i + j]) {
                    ++j;
                }

                p = i + (extend_[pos = i] = j) - 1;
            }
        }
    }

    void GenExtend(const std::string &s, const std::string &t) {
        GenExtend(s.c_str(), s.length(), t.c_str(), t.length());
    }

    const std::vector<int> &GetExtend() const {
        return extend_;
    }

private:
    void init(const size_t n, const size_t m) {
        next_.reserve(n);
        extend_.reserve(m);
    }

    std::vector<int> next_;
    std::vector<int> extend_;
};

}  // namespace algorithmic::string

#endif  // ALGORITHMIC_STRING_KMP_H_
