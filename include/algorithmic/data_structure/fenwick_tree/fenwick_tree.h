#ifndef ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
#define ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_

// Single update
// Interval query
// Find Kth

namespace algorithmic::data_structure::fenwick_tree {

template <typename T, int N>
class FenwickTree {
public:
    void Init(int n) {
        n_ = n;
        high_bit_n_ = highBit(n);
        memset(arr_, 0, sizeof(arr_[0]) * n);
    }

    void Add(int x, const T& v) {
        for (int i = x; i <= n_; i += lowbit(i)) {
            arr_[i] += v;
        }
    }

    T Query(int x) {
        T ret = 0;

        for (int i = x; i > 0; i -= lowbit(i)) {
            ret += arr_[i];
        }

        return ret;
    }

    T Query(int l, int r) {
        if (l > r) {
            return 0;
        }

        return Query(r) - Query(l - 1);
    }

    int Kth(const T& k) {
        int p = 0;

        for (int lim = 1 << (high_bit_n_); lim; lim >>= 1) {
            if (p + lim < N && arr_[p + lim] < k) {
                p += lim;
                k -= arr_[p];
            }
        }

        return p + 1;
    }

private:
    int lowbit(int x) {
        return x & -x;
    }

    int highBit(int x) {
        int res = 0;

        while (x) {
            ++res;
            x >>= 1;
        }

        return res;
    }

    int n_, high_bit_n_;
    T arr_[N];
};

}  // namespace algorithmic::data_structure::fenwick_tree

#endif  // ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
