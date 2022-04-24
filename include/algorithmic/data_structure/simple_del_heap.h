#ifndef ALGORITHMIC_DATA_STRUCTURE_HASH_H_
#define ALGORITHMIC_DATA_STRUCTURE_HASH_H_

#include <queue>
#include <vector>

namespace algorithmic::data_structure {

template <typename T>
class Heap {
public:
    void Clear() {
        while (!q.empty()) {
            q.pop();
        }

        while (!d.empty()) {
            d.pop();
        }
    }

    void Push(const T& x) {
        q.push(x);
    }

    void Del(const T& x) {
        d.push(x);
    }

    const T& Top() {
        while (!d.empty() && d.top() == q.top()) {
            d.pop(), q.pop();
        }

        return q.top();
    }

    T Pop() {
        while (!d.empty() && d.top() == q.top()) {
            d.pop(), q.pop();
        }

        T x = std::move(q.top());
        q.pop();

        return x;
    }

    size_t Size() {
        return q.size() - d.size();
    }

private:
    std::priority_queue<T> q, d;
};

}  // namespace algorithmic::data_structure

#endif  // ALGORITHMIC_DATA_STRUCTURE_HASH_H_
