class Solution {
public:
    int n,m;
    int t[201][201];
    bool isSafe(int i,int j){
        return (i<m && j<n && i>=0 && j>=0);
    }
    int dfs(int i, int j ,vector<vector<int>>& matrix ){
        if(t[i][j]!=-1) return t[i][j];
        int ans = 1;
        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(auto &d:dir){
            int i_ = d[0]+i;
            int j_ = d[1]+j;
            if(isSafe(i_,j_) && matrix[i][j]>matrix[i_][j_]){
                ans = max(ans,1+dfs(i_,j_,matrix));
            }
        }
        return t[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(t,-1,sizeof t);
        int res = INT_MIN;
        for(int i=0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                res = max(res,dfs(i,j,matrix));
            }
        }
        return res;
    }
};