#ifndef ALGORITHMIC_STRING_MANACHER_H_
#define ALGORITHMIC_STRING_MANACHER_H_

#include <string.h>
#include <string>
#include <vector>

namespace algorithmic::string {

class Manacher {
public:
    Manacher() {}

    Manacher(const int n) {
        fake_s_.reserve(n << 1);
        u.reserve(n << 1);
    }

    ~Manacher() {}

    // 0-index
    void Build(const char *s, size_t len) {
        this->len = static_cast<int>(len);
        fake_s_.resize((len + 1) << 2);
        u.resize((len + 1) << 2);

        l = 0;

        fake_s_[l++] = '$';
        fake_s_[l++] = '#';
        for (size_t i = 0; i < len; i++) {
            fake_s_[l++] = s[i];
            fake_s_[l++] = '#';
        }
        fake_s_[l] = 0;

        int mx = 0, id = 0;
        for (int i = 0; i < l; i++) {
            u[i] = mx > i ? std::min(u[2 * id - i], mx - i) : 1;

            while (i - u[i] >= 0 && fake_s_[i + u[i]] == fake_s_[i - u[i]]) {
                u[i]++;
            }

            if (i + u[i] > mx) {
                mx = i + u[i];
                id = i;
            }
        }

        fake_s_.resize(l);
        u.resize(l);
    }

    void Build(const char *s) {
        Build(s, strlen(s));
    }

    void Build(const std::string &s) {
        Build(s.c_str(), s.length());
    }

    // check if s[l:r + 1] is a palindrome.
    bool IsPalindrome(int l, int r) const {
        int il = (l + 1) * 2, ir = (r + 1) * 2;
        int mid = (il + ir) / 2;
        int len = (r - l + 2) / 2;
        return (u[mid] / 2) >= len;
    }

    // get the length of the longest palindrome substring
    int GetMaxLengthOfPalindromeSubstring() const {
        int res = 0;

        for (int i = 0; i < l; i++) {
            res = std::max(res, u[i] - 1);
        }

        return res;
    }

    const std::vector<int> &GetU() {
        return u;
    }

private:
    int len, l;
    std::vector<char> fake_s_;
    std::vector<int> u;
};

}  // namespace algorithmic::string

#endif  // ALGORITHMIC_STRING_MANACHER_H_
