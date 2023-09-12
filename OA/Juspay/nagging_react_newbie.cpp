#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    map<int, int> node_at_id;
    vector<int> member_id(n);
    for (int i = 0; i < n; i++) {
    	cin >> member_id[i];
    	node_at_id[member_id[i]] = i;
    }

    int m; cin >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
    	int u, v; cin >> u >> v;
    	adj[node_at_id[u]].push_back(node_at_id[v]);
    }


    int id_a, id_b; cin >> id_b >> id_a;
    int a = node_at_id[id_a], b = node_at_id[id_b];
    queue<int> q;
    q.push(b);
    vector<bool> reachable_from_b(n, false);
    while (!q.empty()) {
    	int curr = q.front();
    	q.pop();

    	reachable_from_b[curr] = true;
    	for (int next : adj[curr]) {
    		if (!reachable_from_b[next]) {
    			q.push(next);
    		}
    	}
    }

    vector<int> to_remove;
    for (int i = 0; i < n; i++) {
    	if (i == a or !reachable_from_b[i]) {
    		continue;
    	}

    	for (int neighbour : adj[i]) {
    		if (neighbour == a) {
    			to_remove.push_back(member_id[i]);
    			break;
    		}
    	}
    }

    for (int node : to_remove) {
        cout << node << " ";
    }
    cout << "\n";
    
    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

