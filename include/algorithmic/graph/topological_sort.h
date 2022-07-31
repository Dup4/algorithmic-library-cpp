#ifndef ALGORITHMIC_GRAPH_TOPOLOGICAL_SORT_H
#define ALGORITHMIC_GRAPH_TOPOLOGICAL_SORT_H

#include <vector>

#include "./graph_base.h"
#include "./graph_node.h"

namespace algorithmic::graph {

template <typename GraphNode = GraphNode>
class TopologicalSort : public GraphBase<TopologicalSort<GraphNode>, GraphNode> {
    using ThisClass = TopologicalSort<GraphNode>;
    using Base = GraphBase<TopologicalSort<GraphNode>, GraphNode>;

public:
    ThisClass& UpdateTopologicalSort() {
        std::vector<size_t> order;
        std::vector<size_t> unordered;
        auto degree = std::vector<size_t>(Base::GetNumVertices(), 0);

        for (size_t i = 0; i < Base::GetNumVertices(); ++i) {
            for (const auto& v : Base::Visit(i)) {
                ++degree[v.GetV()];
            }
        }

        for (size_t i = 0; i < Base::GetNumVertices(); ++i) {
            if (degree[i] == 0) {
                unordered.push_back(i);
            }
        }

        while (!unordered.empty()) {
            auto u = unordered.back();
            unordered.pop_back();
            order.push_back(u);

            for (const auto& v : Base::Visit(u)) {
                if (--degree[v.GetV()] == 0) {
                    unordered.push_back(v.GetV());
                }
            }
        }

        if (order.size() != Base::GetNumVertices()) {
            has_loop_ = true;
            auto t = std::vector<size_t>();
            topological_order_.swap(t);
            return *this;
        }

        topological_order_.swap(order);

        return *this;
    }

    bool HasLoop() {
        return has_loop_;
    }

    const std::vector<size_t>& GetTopoLogicalOrder() const {
        return topological_order_;
    }

    std::vector<size_t>& GetTopoLogicalOrder() {
        return topological_order_;
    }

private:
    bool has_loop_{false};
    std::vector<size_t> topological_order_{};
};

}  // namespace algorithmic::graph

#endif  // ALGORITHMIC_GRAPH_TOPOLOGICAL_SORT_H
