#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = -1;

struct node {
    int curr_pos, ladders_taken, snakes_taken;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    int p; cin >> p;
    int end = n * n;
    vector<int> ladder(end + 1), snake(end + 1);
    for (int i = 0; i < p; i++) {
    	int a, b; cin >> a >> b;
    	if (a < b) {
    		ladder[a] = b;
    	}
    	else {
    		snake[a] = b;
    	}
    }

    int x, y; cin >> x >> y;

    queue<node> q;
    q.push({x, 0, 0});
    vector<int> steps(end + 1, INF);
    steps[x] = 0;
    while (!q.empty()) {
        auto curr_node = q.front();
        q.pop();

        if (curr_node.curr_pos == y) {
            cout << steps[curr_node.curr_pos] << ' ' << curr_node.ladders_taken << " " << curr_node.snakes_taken << "\n";
            return 0;
        }
        for (int dice_val = 1; dice_val <= m; dice_val++) {
            int next_pos = min(curr_node.curr_pos + dice_val, end);
            int ladders_taken = curr_node.ladders_taken, snakes_taken = curr_node.snakes_taken;
            if (ladder[next_pos]) {
                next_pos = ladder[next_pos];
                ladders_taken += 1;
            }
            else if (snake[next_pos]) {
                next_pos = snake[next_pos];
                snakes_taken += 1;
            }

            if (steps[next_pos] == INF) {
                steps[next_pos] = steps[curr_node.curr_pos] + 1;
                q.push({next_pos, ladders_taken, snakes_taken});
            }
        }
    }

    cout << "-1\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

