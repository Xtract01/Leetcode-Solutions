class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int row = cur[1];
            int col = cur[2];

            if (vis[row][col]) continue;
            vis[row][col] = 1;

            if (row == n-1 && col == n-1)
                return time;

            for (auto &d : dir) {
                int nr = row + d[0];
                int nc = col + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};