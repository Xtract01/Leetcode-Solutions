class Solution {
public:
    int n, m;
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1) {
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(vector<int> &dir : directions){
                int new_row = row + dir[0];
                int new_col = col + dir[1];
                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !vis[new_row][new_col] && grid[new_row][new_col]==1){
                    q.push({new_row,new_col});
                    vis[new_row][new_col] = 1;
                }
            }
        }
        int count = 0;
        for(int i = 0 ;i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};