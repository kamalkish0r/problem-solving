// dijkstra on sparse graphs where m <<< n ^ 2
void dijkstra(int s, vector<int>& dist, vector<int>& parent, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    const int INF = INT_MAX;
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto curr = pq.top();
        auto u = curr.second, d_u = curr.first;
        pq.pop();

        if (dist[u] != d_u) {
            continue;
        }

        for (auto &edge : adj[u]) {
            auto v = edge.first, weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        if (v == -1) { // no path exists
            path.clear();
            return path;
        }

        path.push_back(v);
    }
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}