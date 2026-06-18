class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0 ; j<n ; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftUp = INT_MAX , rightUp = INT_MAX;
                if(j>=1) leftUp = matrix[i][j] + dp[i-1][j-1];
                if(j<n-1) rightUp = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min({up,leftUp,rightUp});
            }
        }
        int ans = dp[m-1][0];
        for(int i=1 ; i<n ; i++){
            ans = min(ans,dp[m-1][i]);
        }
        return ans;
    }
};