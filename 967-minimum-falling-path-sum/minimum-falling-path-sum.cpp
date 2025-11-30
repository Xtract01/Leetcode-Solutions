class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0),curr(m,0);

        for(int j=0 ; j< m; j++) prev[j] = matrix[0][j];
        for(int i= 1 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j] + (j-1>=0 ? prev[j-1] : 1e8);
                int rd = matrix[i][j] +(j+1<m ? prev[j+1] : 1e8);
                curr[j]= min({u,ld,rd});
            }
            prev = curr;
        }
        int mini = 1e8;
        for(int j = 0 ; j<m ; j++){
            mini = min(mini,prev[j]);
        }
        return mini;
    }
};