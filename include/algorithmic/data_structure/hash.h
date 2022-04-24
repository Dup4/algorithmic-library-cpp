#ifndef ALGORITHMIC_DATA_STRUCTURE_HASH_H_
#define ALGORITHMIC_DATA_STRUCTURE_HASH_H_

#include <vector>

namespace algorithmic::data_structure {

template <typename T>
class Hash {
public:
    Hash() = default;
    ~Hash() {}

    // You need to make sure the `x` passed in is valid,
    // otherwise it will cause a runtime error.
    T& operator[](int x) const {
        return vec_[x - 1];
    }

    void Init() {
        vec_.clear();
    }

    void Init(int n) {
        Init();
        vec_.reserve(n);
    }

    int Size() const {
        return vec_.size();
    }

    void Add(const T& x) {
        vec_.push_back(x);
    }

    T Get(const T& x) const {
        return lower_bound(vec_.begin(), vec_.end(), x) - vec_.begin() + 1;
    }

    const std::vector<T>& GetVec() const {
        return vec_;
    }

    // After you have added all the <T> that need to be discretized,
    // don't forget to call this function to deduplicate.
    void Gao() {
        sort(vec_.begin(), vec_.end());
        vec_.erase(unique(vec_.begin(), vec_.end()), vec_.end());
    }

private:
    std::vector<T> vec_;
};

}  // namespace algorithmic::data_structure

#endif  // ALGORITHMIC_DATA_STRUCTURE_HASH_H_
