class Solution {
public:
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m;
    void dfs(int row , int col , vector<vector<int>> &vis , vector<vector<char>>& board ){
        vis[row][col] = 1;
        for(vector<int> &dir:directions){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !vis[new_row][new_col] && board[new_row][new_col]=='O'){
                dfs(new_row,new_col,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j = 0 ; j< m; j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }
        for(int i = 0; i< n ; i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};