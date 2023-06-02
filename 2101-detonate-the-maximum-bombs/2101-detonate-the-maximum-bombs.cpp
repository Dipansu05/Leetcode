class Solution {
public:
   
void dfs(std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_set<int>& visited, int bombIndex) {
    visited.insert(bombIndex);

    if (graph.find(bombIndex) != graph.end()) {
        for (int neighbor : graph[bombIndex]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(graph, visited, neighbor);
            }
        }
    }
}

int maximumDetonation(std::vector<std::vector<int>>& bombs) {
    int maxDetonations = 0;
    int n = bombs.size();
    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            long long dx = bombs[i][0] - bombs[j][0];
            long long dy = bombs[i][1] - bombs[j][1];
            long long distanceSquared = dx * dx + dy * dy;

            if (distanceSquared <= static_cast<long long>(bombs[i][2]) * bombs[i][2]) {
                graph[i].insert(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::unordered_set<int> visited;
        dfs(graph, visited, i);
        maxDetonations = std::max(maxDetonations, static_cast<int>(visited.size()));
    }

    return maxDetonations;
}
};