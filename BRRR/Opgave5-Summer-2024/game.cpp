#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

// Constants for directions
enum Direction { UP, DOWN, LEFT, RIGHT };

// Structure for a Node
struct Node {
    int x, y;           // Position on the grid
    int cost;           // Cost to reach this node
    Node* prev;         // Pointer to the previous node for path reconstruction
    char type;          // 'E' = empty, 'B' = boulder, 'D' = diamond, 'W' = wall
    bool visited;       // To check if the node is already processed

    Node(int x, int y, char type)
        : x(x), y(y), cost(numeric_limits<int>::max()), prev(nullptr), type(type), visited(false) {
    }
};

// Edge structure to represent weighted edges between nodes
struct Edge {
    Node* from;
    Node* to;
    int weight;
    Edge(Node* from, Node* to, int weight) : from(from), to(to), weight(weight) {}
};

// Graph class
class Graph {
private:
    vector<vector<Node*>> grid;     // 2D grid of nodes
    int rows, cols;                 // Dimensions of the grid

public:
    Graph(int rows, int cols, vector<vector<char>> map) : rows(rows), cols(cols) {
        // Initialize the grid with nodes
        for (int i = 0; i < rows; ++i) {
            vector<Node*> row;
            for (int j = 0; j < cols; ++j) {
                row.push_back(new Node(i, j, map[i][j]));
            }
            grid.push_back(row);
        }
    }

    // Get neighbors of a node
    vector<Edge> getNeighbors(Node* node) {
        vector<Edge> neighbors;
        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // UP, DOWN, LEFT, RIGHT

        for (const auto& direction : directions) {
            int dx = direction.first;
            int dy = direction.second;
            int nx = node->x + dx;
            int ny = node->y + dy;

            // Check bounds
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                Node* neighbor = grid[nx][ny];

                // Validate move based on rules
                if (isMoveValid(node, neighbor)) {
                    neighbors.push_back(Edge(node, neighbor, 1)); // Weight is 1 for all valid moves
                }
            }
        }

        return neighbors;
    }

    // Check if a move is valid based on the rules
    bool isMoveValid(Node* current, Node* neighbor) {
        if (neighbor->type == 'W') return false;   // Cannot move into walls
        if (neighbor->type == 'B' && current->y == neighbor->y) return false; // Cannot walk into boulders
        if (neighbor->type == 'E' && current->type == 'B' && neighbor->x > current->x) return false; // Falling boulder rule
        return true;
    }

    Node* getNode(int x, int y) {
        if (x < 0 || y < 0 || x >= rows || y >= cols) return nullptr;
        return grid[x][y];
    }
};

struct CompareCost {
    bool operator()(Node* a, Node* b) {
        return a->cost > b->cost;
    }
};

void FindPathDijkstra(Graph& graph, Node* start, Node* target) {
    priority_queue<Node*, vector<Node*>, CompareCost> frontier;

    // Initialize the start node
    start->cost = 0;
    frontier.push(start);

    while (!frontier.empty()) {
        Node* current = frontier.top();
        frontier.pop();

        // If the target is reached
        if (current == target) {
            break;
        }

        // Mark as visited
        if (current->visited) continue;
        current->visited = true;

        // Process neighbors
        for (Edge edge : graph.getNeighbors(current)) {
            Node* neighbor = edge.to;
            int newCost = current->cost + edge.weight;

            if (newCost < neighbor->cost) {
                neighbor->cost = newCost;
                neighbor->prev = current;
                frontier.push(neighbor);
            }
        }
    }
}

// Helper to reconstruct the path
vector<Node*> reconstructPath(Node* target) {
    vector<Node*> path;
    for (Node* node = target; node != nullptr; node = node->prev) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Sample map
    vector<vector<char>> map = {
        {'E', 'E', 'E', 'W', 'E'},
        {'E', 'B', 'E', 'W', 'D'},
        {'E', 'E', 'B', 'E', 'E'},
        {'W', 'E', 'E', 'E', 'E'}
    };

    // Create the graph
    Graph graph(4, 5, map);

    // Define start and target nodes
    Node* start = graph.getNode(0, 0);
    Node* target = graph.getNode(1, 4);

    // Run Dijkstra's algorithm
    FindPathDijkstra(graph, start, target);

    // Reconstruct and print the path
    vector<Node*> path = reconstructPath(target);
    for (Node* node : path) {
        cout << "(" << node->x << ", " << node->y << ") ";
    }
    cout << endl;

    return 0;
}
