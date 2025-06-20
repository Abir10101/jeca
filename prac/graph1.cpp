#include <iostream>
#include <unordered_map>
// #include <unordered_set>
// #include <vector>
#include <string>

// Example vertex and edge data structures
struct VertexData {
    double value;
    std::string label;
};

struct EdgeData {
    double cost;
};

class Graph {
public:
    // Add a vertex with custom data
    void add_vertex(int id, const VertexData& data) {
        vertices[id] = data;
    }

    // Add an edge with custom data
    void add_edge(int from, int to, const EdgeData& data) {
        edges[from][to] = data;
        // For undirected graphs, also add the reverse edge:
        // edges[to][from] = data;
    }

    // Remove a vertex and all its edges
    void remove_vertex(int id) {
        vertices.erase(id);
        edges.erase(id);
        for (auto& [from, targets] : edges) {
            targets.erase(id);
        }
    }

    // Remove an edge
    void remove_edge(int from, int to) {
        if (edges.count(from)) {
            edges[from].erase(to);
        }
    }

    // Print the graph
    void print() const {
        for (const auto& [from, targets] : edges) {
            for (const auto& [to, edge_data] : targets) {
                std::cout << "Edge from " << from << " to " << to
                          << " (cost: " << edge_data.cost << ")\n";
            }
        }
    }

private:
    std::unordered_map<int, VertexData> vertices;
    std::unordered_map<int, std::unordered_map<int, EdgeData>> edges;
};

int main() {
    Graph g;
    g.add_vertex(1, {0.1, "A"});
    g.add_vertex(2, {0.2, "B"});
    g.add_vertex(3, {0.3, "C"});
    g.add_edge(4, 2, {1.5});
    g.add_edge(2, 3, {2.5});
    g.add_edge(3, 1, {3.5});
    g.print();
    // g.remove_edge(1, 2);
    // g.print();
    return 0;
}
