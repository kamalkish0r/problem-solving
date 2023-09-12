#include <bits/stdc++.h>
using namespace std;

#define int long long

class SegmentTree {
	vector<int> tree;
	int n, NEUTRAL_ELEMENT;
public:
	SegmentTree(int N) {
		n = 1;
		while (n <= N) {
			n *= 2;
		}
		NEUTRAL_ELEMENT = 0;
		tree.resize(2 * n, NEUTRAL_ELEMENT);
	}

	int operation(int a, int b) {
		return a + b;
	}

	void update_query(int idx, int val, int node, int l, int r) {
		cout << idx << " " << node << " " << l << " " << r << "\n";
		if (l == r) {
			tree[node] = val;
			return;
		}

		int mid = (l + r) >> 1;
		if (idx >= l and idx <= mid) {
			update_query(idx, val, 2 * node, l, mid);
		}
		else {
			update_query(idx, val, 2 * node + 1, mid + 1, r);
		}

		tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
	}

	void update_query(int idx, int val) {
		update_query(idx, val, 1, 1, n);
		// for (int i = 1; i <= n; i++) {
		// 	cout << tree[i] << " ";
		// }
		// cout << "\n";
	}

	int get_query(int lx, int rx, int node, int l, int r) {
		if (lx > r or rx < l) {
			return NEUTRAL_ELEMENT;
		}

		if (l >= lx and r <= rx) {
			return tree[node];
		}

		int mid = (l + r) >> 1;
		int left = get_query(lx, rx, 2 * node, l, mid);
		int right = get_query(lx, rx, 2 * node, mid + 1, r);
		cout << lx << " " << rx << " " << node << " " << l << " " << r << " : " << left << " " << right << "\n";
		return operation(left, right);
	}

	int get_query(int lx, int rx) {
		for (int i = 1; i <= n; i++) {
			cout << tree[i] << " ";
		}
		cout << "\n";
		return get_query(lx, rx, 1, 1, n);
	}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) 
    	cin >> a[i];

    SegmentTree st(n);
    vector<int> res;
    for (int i = 1; i <= n; i++) {
    	int index; cin >> index;
    	int shift = st.get_query(1, index);
    	cout << index << " ::: " << shift << "\n";
    	res.push_back(a[index + shift]);
    	st.update_query(index + shift, 1);
    }

    for (int i : res) 
    	cout << i << " ";
    cout << "\n";
    
    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

