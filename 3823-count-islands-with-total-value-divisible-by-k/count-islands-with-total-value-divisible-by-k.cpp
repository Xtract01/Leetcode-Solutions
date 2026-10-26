class Solution {
public:
    int m ,n;
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        long long sum = grid[r][c];
        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i][0];
            int new_c = c + dir[i][1];

            if (new_r >= 0 && new_r < m &&
                new_c >= 0 && new_c < n &&
                grid[new_r][new_c] != 0) {
                sum += dfs(grid, new_r, new_c);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i=0 ;i<m ; i++){
            for(int j=0 ; j<n ;j++){
                if(grid[i][j]!=0){
                    long long sum = dfs(grid,i,j);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};