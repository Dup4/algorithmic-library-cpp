#ifndef ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
#define ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_

// Interval update
// Single query

namespace algorithmic::data_structure::fenwick_tree {

template <typename T, int N>
class FenwickTree {
public:
    void Init(int n) {
        n_ = n;
        memset(arr_, 0, sizeof(arr_[0]) * n);
    }

    void Add(int x, const T& v) {
        for (int i = x; i <= n_; i += lowbit(i)) {
            arr_[i] += v;
        }
    }

    void Add(int l, int r, const T& v) {
        if (l > r) {
            return;
        }

        Add(l, v);
        Add(r + 1, -v);
    }

    T Query(int x) {
        T ret = 0;

        for (int i = x; i > 0; i -= lowbit(i)) {
            ret += arr_[i];
        }

        return ret;
    }

private:
    int lowbit(int x) {
        return x & -x;
    }

    int n_;
    T arr_[N];
};

}  // namespace algorithmic::data_structure::fenwick_tree

#endif  // ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
