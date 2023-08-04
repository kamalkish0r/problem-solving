// https://cp-algorithms.com/graph/dijkstra.html#implementation
void dijkstra(int s, vector<int>& dist, vector<int>& parent, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    const int INF = INT_MAX;
    dist.assign(n, INF);
    parent.assign(n, -1);

    dist[s] = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] and (u == -1 or dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        visited[u] = true;
        for (auto &edge : adj[u]) {
            auto v = edge.first, weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
}