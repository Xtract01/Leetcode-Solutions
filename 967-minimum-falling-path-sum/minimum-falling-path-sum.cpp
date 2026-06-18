class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0);
        for(int j=0 ; j<n ; j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1 ; i<m ; i++){
            vector<int> curr(n,0);
            for(int j=0 ; j<n ; j++){
                int up = matrix[i][j] + prev[j];
                int leftUp = INT_MAX , rightUp = INT_MAX;
                if(j>=1) leftUp = matrix[i][j] + prev[j-1];
                if(j<n-1) rightUp = matrix[i][j] + prev[j+1];

                curr[j] = min({up,leftUp,rightUp});
            }
            prev = curr;
        }
        int ans = prev[0];
        for(int i=1 ; i<n ; i++){
            ans = min(ans,prev[i]);
        }
        return ans;
    }
};