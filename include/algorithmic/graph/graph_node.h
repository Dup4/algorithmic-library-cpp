#ifndef ALGORITHMIC_GRAPH_GRAPH_NODE_H
#define ALGORITHMIC_GRAPH_GRAPH_NODE_H

#include <stdint.h>

namespace algorithmic::graph {

class GraphNode {
public:
    GraphNode() = default;
    GraphNode(int32_t V) : V(V) {}

    void SetV(const int32_t& V) {
        this->V = V;
    }

    const int32_t& GetV() const {
        return V;
    }

    int32_t V{0};
};

}  // namespace algorithmic::graph

#endif  // ALGORITHMIC_GRAPH_GRAPH_NODE_H
