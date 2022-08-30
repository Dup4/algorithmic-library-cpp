#ifndef ALGORITHMIC_DATA_STRUCTURE_LRU_CACHE_H_
#define ALGORITHMIC_DATA_STRUCTURE_LRU_CACHE_H_

#include <cstddef>
#include <memory>
#include <optional>
#include <queue>
#include <unordered_map>
#include <vector>

namespace algorithmic::data_structure {

template <typename K, typename V>
struct DLinkedNode {
    K key;
    V value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : prev(nullptr), next(nullptr) {}
    DLinkedNode(K _key, V _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

template <typename K, typename V, typename Container = std::unordered_map<K, DLinkedNode<K, V>*>>
class LRUCache {
private:
    using DLinkedNode = DLinkedNode<K, V>;

    Container cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    size_t size;
    size_t capacity;

public:
    LRUCache() = delete;

    LRUCache(size_t _capacity) : size(0), capacity(_capacity) {
        init();
    }

    ~LRUCache() {
        clear();
    }

    bool IsExist(const K& key) {
        return cache.count(key) > 0;
    }

    std::optional<V> Get(const K& key) {
        if (!cache.count(key)) {
            return std::nullopt;
        }

        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void Put(const K& key, const V& value) {
        if (!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    size_t Size() const {
        return size;
    }

    void Clear() {
        clear();
        init();
    }

private:
    void init() {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    void clear() {
        for (const auto& [k, v] : cache) {
            if (v != nullptr) {
                delete v;
            }
        }

        cache.clear();

        if (head != nullptr) {
            delete head;
        }

        if (tail != nullptr) {
            delete tail;
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

}  // namespace algorithmic::data_structure

#endif  // ALGORITHMIC_DATA_STRUCTURE_LRU_CACHE_H_
