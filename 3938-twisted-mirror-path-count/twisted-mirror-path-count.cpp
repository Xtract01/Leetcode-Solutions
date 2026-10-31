class Solution {
public:
    int LEFT = 0;
    int UP = 1;
    int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j][cameFrom] != -1) return dp[i][j][cameFrom];
        int totalPathCount = 0;
        if (grid[i][j] == 1) {
            if (cameFrom == LEFT)
                return dp[i][j][cameFrom] = solve(grid, i + 1, j, UP);
            else
                return dp[i][j][cameFrom] = solve(grid, i, j + 1, LEFT);
        }
        totalPathCount = (totalPathCount +solve(grid, i, j + 1, LEFT)) % MOD;
        totalPathCount = (totalPathCount +solve(grid, i + 1, j, UP)) % MOD;
        return dp[i][j][cameFrom] = totalPathCount;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(grid, 0, 0, LEFT);
    }
};