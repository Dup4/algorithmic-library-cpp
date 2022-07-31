#ifndef ALGORITHMIC_GRAPH_GRAPH_BASE_H
#define ALGORITHMIC_GRAPH_GRAPH_BASE_H

#include <vector>

#include "./graph_node.h"

namespace algorithmic::graph {

template <typename T, typename GraphNode = GraphNode>
class GraphBase {
public:
    GraphBase() = default;
    virtual ~GraphBase() = default;

    T& SetNumVertices(const size_t& num_vertices) {
        num_vertices_ = num_vertices;
        graph_.resize(num_vertices + 5);

        return derived();
    }

    size_t GetNumVertices() const {
        return num_vertices_;
    }

    T& UpdateGraph(const std::vector<std::vector<GraphNode>>& g) {
        graph_ = g;
        return derived();
    }

    T& AddEdge(size_t u, GraphNode&& v) {
        graph_[u].push_back(std::forward<GraphNode>(v));
        return derived();
    }

    std::vector<GraphNode>& Visit(size_t u) {
        return graph_[u];
    }

    const std::vector<GraphNode>& Visit(size_t u) const {
        return graph_[u];
    }

private:
    T& derived() {
        return static_cast<T&>(*this);
    }

protected:
    size_t num_vertices_{0};
    std::vector<std::vector<GraphNode>> graph_{};
};

}  // namespace algorithmic::graph

#endif  // ALGORITHMIC_GRAPH_GRAPH_BASE_H
