#ifndef ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
#define ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_

// Single update
// Interval query
// Find Kth

#include <vector>
namespace algorithmic::data_structure::fenwick_tree {

template <typename T>
class FenwickTree {
public:
    FenwickTree() = default;

    FenwickTree(const size_t n) {
        arr_.reserve(n);
    }

    void Init(int n) {
        n_ = n;
        high_bit_n_ = highBit(n_);
        arr_.assign(n_ + 1, 0);
    }

    void Add(int x, const T& v) {
        for (int i = x; i <= n_; i += lowbit(i)) {
            arr_[i] += v;
        }
    }

    // query prefix sum
    T Query(int x) const {
        T ret = 0;

        for (int i = x; i > 0; i -= lowbit(i)) {
            ret += arr_[i];
        }

        return ret;
    }

    T Query(int l, int r) const {
        if (l > r) {
            return 0;
        }

        return Query(r) - Query(l - 1);
    }

    T QueryKth(int k) {
        T p = 0;

        for (int lim = 1 << (high_bit_n_); lim; lim >>= 1) {
            if (p + lim <= n_ && arr_[p + lim] < k) {
                p += lim;
                k -= arr_[p];
            }
        }

        return p + 1;
    }

private:
    int lowbit(int x) const {
        return x & -x;
    }

    int highBit(int x) const {
        int res = 0;

        while (x) {
            ++res;
            x >>= 1;
        }

        return res;
    }

    int n_, high_bit_n_;
    std::vector<T> arr_;
};

}  // namespace algorithmic::data_structure::fenwick_tree

#endif  // ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
