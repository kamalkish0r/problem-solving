#include <bits/stdc++.h>
using namespace std;

#define int long long

class LCA {
public:
    int LOG;
    vector<vector<int>> up, children;
    vector<int> depth;
    LCA(int n, vector<vector<int>>& children, vector<int>& root_nodes) {
        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }
 
        up.resize(n, vector<int>(LOG + 1, -1));
        depth.resize(n, 0);
        this->children = children;
        for (int root_node : root_nodes) {
        	dfs(root_node);
        }
    }
 
    void dfs(int curr) {
        for (int next : children[curr]) {
            depth[next] = depth[curr] + 1;
            up[next][0] = curr;
            for (int i = 1; i < LOG; i++) {
            	if (up[next][i - 1] != -1)
                	up[next][i] = up[up[next][i - 1]][i - 1];
            }
            dfs(next);
        }
    }
 
    int kth_ancestor(int node, int k) {
        for (int i = LOG - 1; i >= 0; i--) {
            if (k & (1 << i)) {
                node = up[node][i];
            }

            if (node == -1) {
            	return node;
            }
        }
 
        return node;
    }
 
    int get_lca(int a, int b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
 
        int k = depth[a] - depth[b];
        a = kth_ancestor(a, k);
        if (a == -1) {
        	return -1;
        }
        assert(depth[b] == depth[a]);
        if (a == b) {
            return a;
        }
 
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];

                if (a == -1 or b == -1) {
                	return -1;
                }
            }
        }
 
        return up[a][0];
    }
};


void solve() {
	int n; cin >> n;
	vector<int> parent(n), root_nodes;
	vector<vector<int>> children(n);
	for (int i = 0; i < n; i++) {
		cin >> parent[i];

		if (parent[i] != -1) {
			children[parent[i]].push_back(i);
		}
		else {
			root_nodes.push_back(i);
		}
	}

	int u, v; cin >> u >> v;

	LCA tree(n, children, root_nodes);
	cout << tree.get_lca(u, v) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) 
        solve();
        
    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/
		