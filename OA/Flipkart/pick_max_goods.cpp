/*
    Given a grid where each cell represents count of goods stored in that cell.
    A robot is positioned at top and other positioned at top right.
    In one move robot can move from (i, j) to (i + 1, j) or (i + 1, j - 1) or (i + 1, j + 1) inside th grid only.
    If both the robots are in same cell then only one robot can pick goods
    Once the goods in a cell are picked by robot that cell becomes empty
    Find the maximum number of goods that can be picked by both the robots.
    
    contraints : 
    2 <= n, m <= 50
*/
#include<bits/stdc++.h>
using namespace std;

bool valid(int i, int j, vector<vector<int>>& grid) {
    return i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size();
}

int pick_goods(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, vector<vector<pair<int, int>>>& next) {
    if (!valid(i, j, grid)) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int down = pick_goods(i + 1, j, grid, dp, next);
    int down_left = pick_goods(i + 1, j - 1, grid, dp, next);
    int down_right = pick_goods(i + 1, j + 1, grid, dp, next);

    int mx = max(down, max(down_left, down_right));
    
    if (down == mx) 
        next[i][j] = make_pair(i + 1, j);
    else if (down_left == mx) 
        next[i][j] = make_pair(i + 1, j - 1);
    else 
        next[i][j] = make_pair(i + 1, j + 1);
    
    return dp[i][j] = grid[i][j] + mx;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid) {
        for (auto &cell : row) {
            cin >> cell;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    vector<vector<pair<int, int>>> next(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    int picked = pick_goods(0, 0, grid, dp, next);
    
    // set picked cells to 0
    int i = 0, j = 0;
    while (valid(i, j, grid)) {
        grid[i][j] = 0;
        int ii = next[i][j].first;
        int jj = next[i][j].second;
        i = ii;
        j = jj; 
    }

    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    next = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    picked += pick_goods(0, m - 1, grid, dp, next);
    
    cout << picked << "\n";

    return 0;
}