class Solution {
public:
    int solve(int row , int col,  vector<vector<int>> &dp){
        if(row==0 && col==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = 0 , left = 0;
        if(row>=1) up = solve(row-1,col,dp);
        if(col>=1) left = solve(row,col-1,dp);
        return dp[row][col]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0 ; i<n ; i++){
            dp[0][i] = 1;
        }
        for(int i=0 ; i<m ; i++){
            dp[i][0] = 1;
        }
        for(int i=1 ; i<m ; i++){
            for(int j = 1; j<n ; j++){
                int up = dp[i-1][j];
                int down = dp[i][j-1];
                dp[i][j] = up + down;
            }
        }
        return dp[m-1][n-1];
    }
};