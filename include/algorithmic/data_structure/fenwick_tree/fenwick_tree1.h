#ifndef ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
#define ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_

// Interval update
// Single query

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
        arr_.assign(n_ + 1, 0);
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

    T Query(int x) const {
        T ret = 0;

        for (int i = x; i > 0; i -= lowbit(i)) {
            ret += arr_[i];
        }

        return ret;
    }

private:
    int lowbit(int x) const {
        return x & -x;
    }

    int n_;
    std::vector<T> arr_;
};

}  // namespace algorithmic::data_structure::fenwick_tree

#endif  // ALGORITHMIC_DATA_STRUCTURE_FENWICK_TREE_H_
